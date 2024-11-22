# Machine Simulator

This repository contains the implementation of a **Vole Machine Simulator** that simulates the operations of the Vole machine using Object-Oriented Programming principles. The simulator fetches and executes instructions step by step and displays the status of the machine’s components (Registers, PC, IR, Memory, etc.).

---

## Features

- **Menu of Choices**: Users can choose from a set of options to interact with the simulator.
- **Load Program from File**: Load machine instructions from a file formatted with space-separated hexadecimal values.
- **Step-by-Step Instruction Execution**: The simulator fetches, validates, and executes each instruction one step at a time.
- **Display Machine Status**: After the execution of each step or after completing the program, the simulator displays the status of:
  - Registers
  - Program Counter (PC)
  - Instruction Register (IR)
  - Memory
  - Screen
- **Instruction Set**: The simulator supports a basic set of machine instructions for the Vole machine, processed from hexadecimal input.


## How to Run the Simulator

### Prerequisites:
- C++ Compiler (e.g., g++)
- A valid Vole program file with space-separated hex instructions.

### Compilation:
To compile the simulator, navigate to the project directory and run:

```bash
g++ main.cpp -o vole_simulator
