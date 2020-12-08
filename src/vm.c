#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "vm.h"
#include "instr.h"

int ip = 0;
int sp = -1;

int *stack;
signed int applied_stack_size;

// global arrays/variables are always set to 0
int registers[NUM_REGS];

bool running = true;

void log_instr(char *instr, int value) {
    printf("instr: %s, value: %i\n", instr, value);
}

void print_stack_dump() {
    printf("\neax: 0x%08x\tebx: 0x%08x\n", registers[EAX], registers[EBX]);
    printf("ecx: 0x%08x\tedx: 0x%08x\n", registers[ECX], registers[EDX]);
    printf("eex: 0x%08x\tefx: 0x%08x\n", registers[EEX], registers[EFX]);
    printf("egx: 0x%08x\tehx: 0x%08x\n", registers[EGX], registers[EHX]);

    printf("\nip:  0x%08x\tsp:  0x%08x\n", ip, sp);

    printf("\nstack_size: \t0x%08x\n", applied_stack_size);
}

void eval() {

}

void initialize_vm(int stack_size) {
    stack = malloc(stack_size * sizeof(int));
    applied_stack_size = stack_size;

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
                fread(&value, sizeof(int), 1, fp);
                sp++;
                stack[sp] = value;
                break;
            case POP: {
                int val_popped = stack[sp--];
                break;
            }
            case HLT:
                running = false;
                break;
            case NOP:
                break;
            case MOV:
                break;
            case MOVA:
                fread(&value, sizeof(int), 1, fp);
                registers[EAX] = value;
                break;
            case UFF:
                printf("caught debug instruction 0x%x\n", instr);
                break;
            default:
                printf("unknown instr: 0x%x\n", instr);
                return 255;
        }

        ip++;
    }

    return 0;
}

void halt_vm() {
    running = false;
    free(stack);
}
