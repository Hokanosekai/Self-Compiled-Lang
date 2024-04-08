#ifndef _STACK_H
#define _STACK_H

#include <stdio.h>
#include <stdlib.h>

struct node;
struct stack;

typedef struct node {
  int data;
  struct node *next;
} node;

typedef struct stack {
  node *top;
} stack;

node *init_node(int data);
stack *init_stack();

void free_node(node *n);
void free_stack(stack *s);

int count_node(node *n);

int stack_push(stack *s, int data);
int stack_pop(stack *s);
int stack_peek(stack *s);

int is_empty(stack *s);

int debug_stack(stack *s);
int print_stack(stack *s);

#endif // _STACK_H