#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "vm.h"
#include "instr.h"

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
    printf("initialize vm with stack size of %i bytes\n", stack_size);
}

void run_vm(char *filename) {
    FILE *fp;

    fp = fopen(filename, "rb");
    fseek(fp, 0, SEEK_SET);

    int instr;
    int value;

    while (fread(&instr, INSTRUCTION_SIZE, INSTRUCTION_SIZE, fp) == 1 && running) {
        switch (instr) {
            case PUSH:
                fread(&value, sizeof(char), VALUE_SIZE, fp);
                printf("instr: 0x%x - push | value: %i\n", instr, value);
                break;
            case POP:
                printf("instr: 0x%x - pop\n", instr);
                break;
            case HLT:
                printf("instr: 0x%x - hlt\n", instr);
                running = false;
                break;
            case NOP:
                printf("instr: 0x%x - nop\n", instr);
                break;
            default:
                printf("unknown instr: 0x%x\n", instr);
                break;
        }
    }
//    while (running) {
//        eval(fetch());
//        ip++;
//    }
}