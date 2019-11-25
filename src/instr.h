#ifndef TINIVM_INSTR_H
#define TINIVM_INSTR_H

#define INSTRUCTION_SIZE 1
#define VALUE_SIZE 16

typedef enum {
    NOP     = 0x00,
    SET     = 0x02,
    PUSH    = 0x03,
    POP     = 0x04,
    HLT     = 0x05,
    MOV     = 0x06,
    MOVA    = 0x6a,
    UFF     = 0xff
} InstructionSet;

#endif //TINIVM_INSTR_H
