#include "stack.h"

node *init_node(int value) {
  node *new_node = (node *)malloc(sizeof(node));
  new_node->data = value;
  new_node->next = NULL;
  return new_node;
}

int count_node(node *node) {
  if (node == NULL) {
    return 0;
  }

  return 1 + count_node(node->next);
}

stack *init_stack() {
  stack *new_stack = (stack *)malloc(sizeof(stack));
  new_stack->top = NULL;
  return new_stack;
}

int stack_push(stack *stack, int value) {
  node *new_node = init_node(value);
  new_node->next = stack->top;
  stack->top = new_node;
  return 0;
}

int stack_pop(stack *stack) {
  if (stack->top == NULL) {
    printf("Stack is empty\n");
    return -1;
  }

  node *tmp = stack->top;
  stack->top = stack->top->next;
  int value = tmp->data;
  free(tmp);
  return value;
}

int stack_peek(stack *stack) {
  if (stack->top == NULL) {
    printf("Stack is empty\n");
    return -1;
  }

  return stack->top->data;
}

int is_empty(stack *stack) {
  return stack->top == NULL;
}

int debug_stack(stack *stack) {
  int count = count_node(stack->top);

  printf("Stack has %d nodes\n", count);

  // print the stack from top to bottom with index of each node and is address

  int i = 0;

  node *current = stack->top;
  while (current != NULL) {
    printf("%d | %p | %d\n", i++, (void*) current, current->data);
    current = current->next;
  }

  return 0;
}

int print_stack(stack *stack) {
  node *current = stack->top;
  while (current != NULL) {
    printf("%d\n", current->data);
    current = current->next;
  }
  return 0;
}

void free_node(node *node) {
  free(node);
}

void free_stack(stack *stack) {
  node *current = stack->top;
  while (current != NULL) {
    node *tmp = current;
    current = current->next;
    free_node(tmp);
  }
  free(stack);
}
