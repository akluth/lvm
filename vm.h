#ifndef TINIVM_VM_H
#define TINIVM_VM_H

#define STACK_SIZE 256

typedef enum {
    MOV,
    SET,
    PUSH,
    POP,
    HLT
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
