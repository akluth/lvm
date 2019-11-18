#ifndef TINIVM_INSTR_H
#define TINIVM_INSTR_H

unsigned int instructions[4] = {
        0x01,   // mov  - move a value (hardcoded, variable or register)
        0x02,   // set  - set register to a value (only hardcoded values)
        0x03,   // push - push value to stack
        0x04,   // pop  - pop value from stack
        0x05    // hlt  - halt system
};

#endif //TINIVM_INSTR_H
