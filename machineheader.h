#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;
class memory
{
public:
    memory(int v=0);
    void set(int v);
    int get()const;
    string binaryValue()const;
    string hexaValue()const;
    int twosComplementValue() const;

    // ~memory();
protected :
    int value=0;
};
class Register:public memory
{

public:
    bool operator==(const memory &rhs) const;
    bool operator!=(const memory &rhs) const;
    Register& operator=(const memory &rhs);
    
};
class ArthmeticUnit
{
public:
    
    int add_int(int val1, int val2);
    
};
class machine
{
private:
    ArthmeticUnit *AU;
    memory *mem;
    Register *reg;
    int progCount,regCount,memSize;
    bool halt;
    string screen;
    bool valid_value(string ins);
    void one(string ins);
    void two(string ins);
    void three(string ins);
    void four(string ins);
    void five(string ins);
    void seven(string ins);

public:
    machine(int mem_size,int reg_count);
    int regisCount();
    int memorySize();
    bool runOneCycle();
    string sceenContent();
    memory &memIndex(int index);
    Register &registerIndex(int index);
    void reset();
    bool halted();
    // ~machine();
};


string decemalToBase(int val,int base);
int baseToDecemal(string val,int base);
int baseToDecemal(char x);



