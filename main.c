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

    while ((opt = getopt(argc, argv, "s:i:")) != -1) {
        switch (opt) {
            case 's':
                stack_size = atoi(optarg);
                break;
            case 'i':
                filename = optarg;
                break;
        }
    }

    initialize_vm(stack_size);
    run_vm(filename);

    return 0;
}