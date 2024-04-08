#ifndef _INSTRUCTION_H
#define _INSTRUCTION_H

#include "stack.h"

typedef int (*fn_with_args)(stack *stack, int);
typedef int (*fn_no_args)(stack *stack);

struct instruction;

typedef struct instruction {
  union {
    fn_with_args with_args;
    fn_no_args no_args;
  } fn;
  int arg;
  struct instruction *next;
} instruction;

int execute_instruction(stack *stack, instruction *instr);

instruction* get_last_instruction(instruction *instr);

int push(stack *stack, int value);
int pop(stack *stack);

int sum(stack *stack);
int sub(stack *stack);
int mul(stack *stack);
int divide(stack *stack);

int print(stack *stack);

#endif