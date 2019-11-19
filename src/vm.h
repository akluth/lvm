#ifndef TINIVM_VM_H
#define TINIVM_VM_H

#define STACK_SIZE 256

typedef enum {
    NOP     = 0x00,
    MOV     = 0x01,
    SET     = 0x02,
    PUSH    = 0x03,
    POP     = 0x04,
    HLT     = 0x05,
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
void run_vm();

#endif //TINIVM_VM_H
