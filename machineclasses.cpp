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
    int pos=0, num;
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
