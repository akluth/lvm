#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <getopt.h>
#include <stdbool.h>
#include "vm.h"
#include "instr.h"

int main(int argc, char *argv[]) {
    int opt;
    unsigned int stack_size = STACK_SIZE;
    char *filename;

    while ((opt = getopt(argc, argv, "s:")) != -1) {
        switch (opt) {
            case 's':
                stack_size = (unsigned int)optarg;
                break;
        }
    }

    for (int index = optind; index < argc; index++) {
        printf("loading %s\n", argv[index]);
        filename = argv[index];
    }

    FILE *fp;
    int instr;
    int value;

    fp = fopen(filename, "rb");
    fseek(fp, 0, SEEK_SET);

    bool running = true;

    while (fread(&instr, INSTRUCTION_SIZE, INSTRUCTION_SIZE, fp) == 1) {
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

    //initialize_vm(stack_size);
    //run_vm();

    return 0;
}