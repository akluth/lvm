#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <getopt.h>
#include "vm.h"

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
        printf("Non-option argument %s\n", argv[index]);
        filename = argv[index];
    }

    initialize_vm(stack_size);
    run_vm();

    return 0;
}