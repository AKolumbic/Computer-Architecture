#include "retyped_cpu.h"

// helper functions
unsigned char cpu_ram_read(struct cpu *cpu, unsigned char address)
{   
    return cpu->ram[address];
}

void cpu_ram_write(struct cpu *cpu, unsigned char address, unsigned char value)
{
    return cpu->ram[address] = value;
}

// load the binary bytes from an .ls8 source file into a RAM array
void cpu_load(struct cpu *cpu)
{
    const int DATA_LEN = 6;
    char data[DATA_LEN] = {
        //from print8.ls8
        0b10000010, // LDI R0,8
        0b00000000,
        0b00001000,
        0b01000111, // PRN R0
        0b00000000,
        0b00000001  // HLT
    };

    int address = 0;

    for (int i = 0; i<DATA_LEN; i++)
    {
        cpu->ram[address++] = data[i];
    }
}

void alu(struct cpu *cpu, enum alu_op, unsigned char regA, unsigned char regB)
{
    switch (op)
    {
        case ALU_MUL:
        break;
        //TODO: implement more ALU ops
    }
}

void cpu_run(struct cpu *cpu)
{
    // we create a 'running' variable, and set it to 1, for TRUE
    // it is TRUE until we get an HLT instruction
    int running = 1;

    while (running)
    {
        // 1. Get the value of the current instruction (in address PC).
        // 2. switch() over it to decide on a course of action.
        // 3. Do whatever the instruction should do according to the spec.
        // 4. Move the PC to the next instruction.
    }
}

void cpu_init(struct cpu *cpu)
{
    // Todo: init the PC and other special registers

    //TODO: zero registers and RAM
}