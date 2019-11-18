#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "vm.h"

const int program[] = {
        PUSH, 1337,
        POP,
        HLT
};

int ip = 0;
int sp = -1;

int *stack;
bool running = true;

void log_instr(char *instr, int value) {
    printf("instr: %s, value: %i\n", instr, value);
}

int fetch() {
    return program[ip];
}

void eval(int instr) {
    switch (instr) {
        case HLT:
            log_instr("HLT", 0);
            running = false;
            break;
        case PUSH: {
            sp++;
            stack[sp] = program[++ip];
            log_instr("PUSH", program[ip]);
            break;
        }
        case POP: {
            int val_popped = stack[sp--];
            log_instr("POP", val_popped);
            break;
        }
    }
}

void initialize_vm(int stack_size) {
    stack = malloc(stack_size * sizeof(int));
}

void run_vm() {
    while (running) {
        eval(fetch());
        ip++;
    }
}