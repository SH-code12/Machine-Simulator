#include "machineheader.h"
#define all(v) v.begin(), v.end()
#define each auto &
// #include <iostream>
// #include <cmath>
// #include <algorithm>
// #include <string>


using namespace std;

string decemalToBase(int val,int base){
    string baseValue;
    while (val)
    {
        int reminder =val%base;
        val/=base;
        char d = ((reminder<10)?reminder+'0':'A'+(reminder-10));
        baseValue +=d;
    }
    if(baseValue.empty()){
        baseValue.push_back('0');
        
    }
    reverse(baseValue.begin(),baseValue.end());
    return baseValue;
    
}
int baseToDecemal(string val, int base){
    reverse(val.begin(),val.end());
    int pos=0, num=0;
    for (size_t i = 0; i < val.size(); i++) {
        char &x = val[i];
        int d = (isalpha(x) ? x - 'A' + 10 : x - '0');
        num += d * pos;
        pos *= base;
    
    }
    return num;

}
int baseToDecemal(char x){
    int d = (isalpha(x) ? x - 'A' + 10 : x - '0');
    return d;
}

memory::memory(int v){
    value=v;
}
void memory:: set(int v){
    value=v;
}
int memory::get()const{
    return value;
}
string memory::binaryValue()const{
    string biValue= decemalToBase(value,2);
    while (biValue.size()<8){
        biValue='0'+biValue;
    }
    return biValue;
    
}
string memory::hexaValue()const{
    string hexValue= decemalToBase(value,16);
    while (hexValue.size()<2){
        hexValue='0'+hexValue;
    }
    return hexValue;
}
int memory::twosComplementValue() const{
    string biValue=binaryValue();
    int num;
    bool rev=0;
    if (biValue[0]=='1'){
        int size=biValue.size();
        for (int i = size-1; i >=0; i--)
        {
            if (rev) {
            // If we are in the process of taking two's complement, invert the bit
            biValue[i] = !(biValue[i] - '0') + '0';

            // If the current bit is '1', set rev to true
            if (biValue[i] - '0') {
                rev = true;
            }
        }
    }
    }

    // Convert the inverted binary string to decimal and multiply by -1
    return baseToDecemal(biValue, 2) * -1;
        
    }
    int ArthmeticUnit::add_int(int val1, int val2)
    {
    int sum = val1 + val2;
    string binary_sum = decemalToBase(sum, 2);
    if (binary_sum.size() > 8) binary_sum = binary_sum.substr(binary_sum.size() - 8, 8);
    return baseToDecemal(binary_sum, 2);
    }

    bool machine::valid_value(string ins)
    {
    for (each c: ins)
    {
        if (c < '0' || c > 'F')
        {
            return false;
        }
    }
        return true;
    }
    // copy from memory to register
void machine::one(string ins)
{
    int register_index = baseToDecemal(ins[1]), memory_cell_idx = baseToDecemal(ins.substr(2, 2), 16);
    reg[register_index] = mem[memory_cell_idx];
}

// assign value to register
void machine::two(string ins)
{
    int register_index = baseToDecemal(ins[1]), value = baseToDecemal(ins.substr(2, 2), 16);
    reg[register_index] = value;
}

// copy from register to memory
void machine::three(string ins)
{
    int register_index = baseToDecemal(ins[1]), memory_index = baseToDecemal(ins.substr(2, 2), 16);
    mem[memory_index] = reg[register_index];
    if (memory_index == 0) screen.push_back(mem[memory_index].get());
}

// copy from register to register
void machine::four(string ins)
{
    int register_index_1 = baseToDecemal(ins[2]), register_index_2 = baseToDecemal(ins[3]);
    reg[register_index_2] = reg[register_index_1];
}

// add (2's complement)
void machine::five(string ins)
{
    int r[3];
    for (int i{}; i < 3; i++) r[i] = baseToDecemal(ins[i + 1]);
    reg[r[0]] = AU->add_int(reg[r[1]].get(), reg[r[2]].get());
}
// jump
void machine::seven(string ins)
{
    int register_index = baseToDecemal(ins[1]), memory_index = baseToDecemal(ins.substr(2, 2), 16);
    if (reg[register_index] == reg[0]) progCount = memory_index;
}

// machine::machine(int mem_size, int reg_count) : memSize(mem_size), regCount(reg_count)
// {
//     mem = new memory[mem_size];
//     reg = new Register[reg_count];
//     progCount = 0;
//     halt = false;
// }
// int machine::regisCount()
// {
//     return regCount;
// }

// int machine::memorySize()
// {
//     return memSize;
// }
machine::machine(int mem_size, int reg_count) : memSize(mem_size), regCount(reg_count)
{
    mem = new memory[mem_size];
    reg = new Register[reg_count];
    progCount = 0;
    halt = false;
}
int machine::regisCount()
{
    return regCount;
}

int machine::memorySize()
{
    return memSize;
}

bool machine::runOneCycle()
{
    if (progCount > 254)
    {
        halt = true;
        return false;
    }
    string ins = mem[progCount].hexaValue() + mem[progCount + 1].hexaValue();
    progCount += 2;

    switch (ins[0]) {
        case '1': {
            one(ins);
            return true;
        }
        case '2': {
            two(ins);
            return true;
        }
        case '3': {
            three(ins);
            return true;
        }
        case '4': {
            four(ins);
            return true;
        }
        case '5': {
            five(ins);
            return true;
        }
        case 'B':{
            seven(ins);
            return true;
        }
    }
    if (ins == "COOO")
    {
        halt = true;
        return true;
    }
    return false;
}

string machine::sceenContent()
{
    return screen;
}

memory &machine::memIndex(int index)
{
    return mem[index];
}

Register &machine::registerIndex(int index)
{
    return reg[index];
}

bool machine::halted()
{
    return halt;
}
void machine::reset(){
    for (int i = 0; i < regCount; i++)
    {
        reg[i]=0;
    }
    for (int i = 0; i < memSize; i++)
    {
        mem[i]=0;
    }
    progCount=0;
    halt =0;
    screen="";
    
}

bool Register::operator==(const memory &rhs) const
{
    return value == rhs.get();
}
bool Register::operator!=(const memory &rhs) const
{
    return value != rhs.get();
}
Register& Register::operator=(const memory &rhs)
{
    value = rhs.get();
    return *this;
}

    
    // int main(){
    // return 0;
    // }
    
