#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

class Register {
private:
    int value;

public:
    Register() : value(0) {}

    int getValue() const {
        return value;
    }

    void setValue(int newValue) {
        value = newValue;
    }
};
//------------------------------------------------------------------------------------------------------
class Memory {
private:
    vector<int> cells;

public:
    Memory(int size) : cells(size, 0) {}

    int read(int address) const {
        if (address >= 0 && address < cells.size()) {
            return cells[address];
        } else {
            // Handle out-of-bounds access
            cout << "Error: Memory address does not exist  or out of range " <<endl;
            return 0;
        }
    }

    void write(int address, int value) {
        if (address >= 0 && address < cells.size()) {
            cells[address] = value;
        } else {
            // Handle out-of-bounds access
            cout << "Error: Memory address does not exist  or out of range " << endl;
        }
    }
};
//-----------------------------------------------------------------------------------------------------
class Instruction {
private:
    int opCode;
    int operand1;
    int operand2;

public:
    Instruction(int op, int op1, int op2) : opCode(op), operand1(op1), operand2(op2) {}

    int getOpCode() const {
        return opCode;
    }

    int getOperand1() const {
        return operand1;
    }

    int getOperand2() const {
        return operand2;
    }
};
//-----------------------------------------------------------------------------------------------------
class Machine {
private:
    Register registers[16];  // 16 registers, indexed from 0 to 15
    Memory memory;
    int programCounter;

    int fetchInstruction() {
        return memory.read(programCounter++);
    }

    Instruction decodeInstruction(int instructionWord) {
        int opCode = instructionWord >> 14;  // Use 2 bits for opcode
        int operand1 = (instructionWord >> 8) & 0xF;  // Use 4 bits for operand1
        int operand2 = instructionWord & 0xFF;  // Use 8 bits for operand2

        return Instruction(opCode, operand1, operand2);
    }

    void executeInstruction(const Instruction& instruction) {
        switch (instruction.getOpCode()) {
            case 0:  // LOAD
                loadRegister(instruction.getOperand1(), memory.read(instruction.getOperand2()));
                break;

                // Implement other instructions here

            default:
                // Handle invalid instructions
                break;
        }
    }

    int encodeInstruction(const Instruction& instruction) {
        return (instruction.getOpCode() << 14) | (instruction.getOperand1() << 8) | instruction.getOperand2();
    }

    void loadRegister(int registerIndex, int value) {
        registers[registerIndex].setValue(value);
    }


public:
    Machine() : memory(256), programCounter(0) {}

    void loadProgram(const vector<Instruction>& program) {
        for (size_t i = 0; i < program.size(); ++i) {
            memory.write(i, encodeInstruction(program[i]));
        }
    }

    void execute() {
        while (true) {
            int instructionWord = fetchInstruction();
            Instruction instruction = decodeInstruction(instructionWord);

            if (instruction.getOpCode() == 3) {  // HALT instruction
                break;  // Exit the loop when HALT instruction is encountered
            }

            executeInstruction(instruction);
        }
    }

    // Print the state of registers and memory
    void printState() const {
        cout << "Registers:" << std::endl;
        for (int i = 0; i < 16; ++i) {
            cout << "R" << i << " : " << setw(2) << setfill('0') << registers[i].getValue() << endl;
        }

        cout << "Memory:" << endl;
        for (int i = 0; i < 256; ++i) {
            cout << "M" << i << " : " << setw(2) << setfill('0') << memory.read(i) << endl;
        }
    }
};
//---------------------------------------------------------------------------------------------------------------------------------
int main() {
    vector<Instruction> program = {
            Instruction(0, 0, 10),    // Example: LOAD R0 with the value at memory location 10
            Instruction(3, 0, 0)      // Example: HALT
    };

    Machine machine;
    machine.loadProgram(program);
    machine.execute();

    // Print the state of registers and memory
    machine.printState();

    return 0;
}
