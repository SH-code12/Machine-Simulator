#include "machineheader.h"
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
