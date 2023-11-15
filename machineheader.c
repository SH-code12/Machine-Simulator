
class memory
{
public:
    memory(int v=0);
    void set(int v);
    int get()const;
    string binaryValue()const;
    string hexaValue()const;
    int twosComplementValue() const;

    ~memory();
protected :
    int value=0;
};
class register:public memory
{

public:
    bool operator==(const memory &rhs) const;
    bool operator!=(const memory &rhs) const;
    Register operator=(const memory &rhs);
    
};
class machine
{
private:
    memory *mem;
    register *reg;
    int progCount,regCount,memSize;
    bool halt;
    string screen;
    bool valid_value(string ins);
    void one(string ins);
    void two(string ins);
    void three(string ins);
    void four(string ins);
    void five(string ins);
    void six(string ins);
    void seven(string ins);

public:
    machine(int memSize=256,int regC=16);
    int regisCount();
    int memorySize();
    bool runOneCycle();
    string sceenContent();
    Memory &memIndex(int index);
    Register &registerIndex(int index);
    void reset();
    bool halted();
    ~machine();
};

string decemalToBase(int val,int base);
int baseToDecemal(string value, int base);
int baseToDecemal(char c);




