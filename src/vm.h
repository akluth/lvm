#ifndef TINIVM_VM_H
#define TINIVM_VM_H

#define STACK_SIZE 256
#define HEADER_LEN 7
#define HEADER_MAGIC "laura"

struct __attribute__((__packed__)) file_header {
    char magic[5];
    unsigned char null_byte;
    unsigned char version;
    unsigned char padding;
};

typedef enum {
    VERSION_1 = 0xc1
} Version;

typedef enum {
    EAX,
    EBX,
    ECX,
    EDX,
    EEX,
    EFX,
    EGX,
    EHX,
    NUM_REGS
} Registers;

void print_stack_dump();
void initialize_vm(int);
int run_vm();
void halt_vm();

#endif //TINIVM_VM_H
