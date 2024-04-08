#include "instruction.h"
#include <string.h>

#define DEBUG 1

struct program;

typedef struct program {
  instruction *top;
  stack *stack;
} program;

int init_program(struct program *program);

int add_instruction(struct program *program, instruction instr);

int run_program(struct program *program);

int init_program(struct program *program) {
  stack *new_stack = init_stack();
  if (new_stack == NULL) {
    return -1;
  }

  program->stack = new_stack;
  program->top = NULL;
  return 0;
}

int add_instruction(struct program *program, instruction instr) {
  instruction *new_instr = (instruction *)malloc(sizeof(instruction));
  if (new_instr == NULL) {
    return -1;
  }

  memcpy(new_instr, &instr, sizeof(instruction));
  new_instr->next = NULL;

  if (program->top == NULL) {
    program->top = new_instr;
    return 0;
  }

  instruction *last = get_last_instruction(program->top);
  last->next = new_instr;
  return 0;
}

int run_program(struct program *program) {
  instruction *current = program->top;
  while (current != NULL) {

    #ifdef DEBUG
    printf("\n\nRunning instruction %p\n", (void *) current);

    debug_stack(program->stack);

    #endif

    if (current->fn.with_args) {
      current->fn.with_args(program->stack, current->arg);
    } else {
      current->fn.no_args(program->stack);
    }

    current = current->next;
  }

  return 0;
}

int main() {
  struct program program;
  init_program(&program);

  instruction push_1 = {
    .arg = 1,
    .fn = {
      .with_args = push
    }
  };
  add_instruction(&program, push_1);

  instruction push_2 = {
    .arg = 2,
    .fn = {
      .with_args = push,
    }
  };
  add_instruction(&program, push_2);

  instruction sum_ = {
    .arg = 0,
    .fn = {
      .no_args = sum,
    }
  };
  add_instruction(&program, sum_);

  instruction print_ = {
    .arg = 0,
    .fn = {
      .no_args = print,
    }
  };
  add_instruction(&program, print_);


  run_program(&program);

  return 0;
}