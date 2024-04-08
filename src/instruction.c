#include "instruction.h"

instruction *get_last_instruction(instruction *instr) {
  instruction *current = instr;
  while (current->next != NULL) {
    current = current->next;
  }

  return current;
}

int push(stack *stack, int value) {
  stack_push(stack, value);
  return 0;
}

int pop(stack *stack) {
  return stack_pop(stack);
}

int print(stack *stack) {
  int value = stack_peek(stack);
  printf("Top of stack: %d\n", value);
  return 0;
}

int sum(stack *stack) {
  int a = pop(stack);
  int b = pop(stack);
  push(stack, a + b);
  return 0;
}

int sub(stack *stack) {
  int a = pop(stack);
  int b = pop(stack);
  push(stack, a - b);
  return 0;
}

int mul(stack *stack) {
  int a = pop(stack);
  int b = pop(stack);
  push(stack, a * b);
  return 0;
}

int divide(stack *stack) {
  int a = pop(stack);
  int b = pop(stack);
  push(stack, a / b);
  return 0;
}
