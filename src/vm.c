#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "vm.h"
#include "instr.h"


int ip = 0;
int sp = -1;

int *stack;
bool running = true;

void log_instr(char *instr, int value) {
    printf("instr: %s, value: %i\n", instr, value);
}

void eval() {

}

void initialize_vm(int stack_size) {
    stack = malloc(stack_size * sizeof(int));
    printf("initialize vm with stack size of %i bytes\n", stack_size);
}

int run_vm(char *filename) {
    FILE *fp;
    fp = fopen(filename, "rb");
    fseek(fp, 0, SEEK_SET);

    unsigned char instr;
    int value;

    struct file_header header;
    fread(&header, sizeof(struct file_header), 1, fp);

    printf("\nrunning program '%s'\n", filename);

    if (strcmp(header.magic, HEADER_MAGIC) != 0) {
        printf("error: magic not found\n");
        return -1;
    } else {
        printf(" -> magic found in header\n");
    }

    switch (header.version) {
        case VERSION_1:
            printf(" -> binary version 1\n");
            break;
        default:
            printf("error: invalid version %x found\n", header.version);
            return -1;
    }

    printf("\nexecuting...\n");

    while (fread(&instr, INSTRUCTION_SIZE, INSTRUCTION_SIZE, fp) == 1 && running) {
        switch (instr) {
            case PUSH:
                fread(&value, sizeof(char), VALUE_SIZE, fp);
                sp++;
                stack[sp] = value;
                printf("instr: 0x%x - push ; pushed value: %i\n", instr, value);
                break;
            case POP: {
                int val_popped = stack[sp--];
                printf("instr: 0x%x - pop  ; popped value: %i\n", instr, val_popped);
                break;
            }
            case HLT:
                printf("instr: 0x%x - hlt\n", instr);
                running = false;
                break;
            case NOP:
                printf("instr: 0x%x - nop\n", instr);
                break;
            case MOV:
                printf("instr: 0x%x - mov\n", instr);
                break;
            case UFF:
                printf("caught debug instruction 0x%x\n", instr);
                break;
            default:
                printf("unknown instr: 0x%x\n", instr);
                return 255;
                break;
        }

        ip++;
    }

    return 0;
}