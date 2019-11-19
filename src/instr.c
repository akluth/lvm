#include "instr.h"

unsigned int instructions[7] = {
        0x00,   // nop  - do nothing
        0x02,   // set  - set register to a value (only hardcoded values)
        0x03,   // push - push value to stack
        0x04,   // pop  - pop value from stack
        0x05,   // hlt  - halt system
        0x06,   // mov  - move a value (hardcoded, variable or register)
        0xff    // uff  - debug instruction
};
