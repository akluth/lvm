#ifndef TINIVM_VM_H
#define TINIVM_VM_H

#define STACK_SIZE 256
#define HEADER_LEN 7
#define HEADER_MAGIC "bupi"

struct __attribute__((__packed__)) file_header {
    char magic[4];
    unsigned char null_byte;
    unsigned char version;
    unsigned char padding;
};

typedef enum {
    VERSION_1 = 0xc1
} Version;

typedef enum {
    NOP     = 0x00,
    SET     = 0x02,
    PUSH    = 0x03,
    POP     = 0x04,
    HLT     = 0x05,
    MOV     = 0x06,
    UFF     = 0xff
} InstructionSet;

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

void initialize_vm(int);
int run_vm();

#endif //TINIVM_VM_H
