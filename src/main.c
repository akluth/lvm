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
    bool debug = false;
    bool stack_dump = false;

    while ((opt = getopt(argc, argv, "s:i:dx")) != -1) {
        switch (opt) {
            case 's':
                stack_size = atoi(optarg);
                break;
            case 'i':
                filename = optarg;
                break;
            case 'd':
                debug = true;
                break;
            case 'x':
                stack_dump = true;
                break;
        }
    }

    initialize_vm(stack_size);
    int result = run_vm(filename);
    halt_vm();

    if (stack_dump) {
        print_stack_dump();
    }

    return result;
}