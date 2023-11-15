#include <iostream>
#include <bits/stdc++.h>
#include "Machineclasses.cpp"
using namespace std;

int main()
{
    machine machine1(256,16);
    int opration;
    cout<<"program starts";
    while(true){
        cout<< "enter the number of the opration";
        
        cout<<"1-load a progrm from a file\n2-display screen\n3-display memory\n4-display registers\n5-run til halt\n6-run one cycle\n0-exit\n";
        cout<<"number of the opration: ";
        cin>>opration;
        if (opration < 0 || opration > 6) continue;
        switch (opration)
        {
        case 0:
            return 0;
        case 1:
        {
            machine1.reset();
            string file_name, hex_value;
            int idx{};
            cout << "Filename: ";
            cin >> file_name;
            ifstream fs(file_name);

            while (fs >> hex_value) {
                // Check if the hex_value starts with "0x"
                if (hex_value.substr(0, 2) == "0x") {
                    // Extract the hexadecimal part and convert it to decimal
                    int value = stoi(hex_value.substr(2), 0, 16);

                    // Set the value in the next memory cell
                    machine1.memIndex(idx).set(value);
                    idx++;
                } else {
                    cerr << "Invalid hex format: " << hex_value << endl;
                    // Handle the error or skip the invalid value as needed
                }
            }

            break;


        }
        case 2:
        {
            cout<<machine1.sceenContent()<<'\n';
            break;
        }
        case 3:
        {
            for (int i = 0; i < machine1.memorySize(); i++)
            {
                cout<<decemalToBase(i,16)<<": "<<machine1.memIndex(i).hexaValue()<<'\n';
            }
            
        }
        case 4:
        {
            for (int i = 0; i < machine1.regisCount(); i++)
            {
                cout<<decemalToBase(i,16)<<": "<<machine1.registerIndex(i).hexaValue()<<'\n';
            }
            
        }
        case 5:
        {
            while (!machine1.halted())
            {
                machine1.runOneCycle();
            }
            break;
        }
        case 6:
        {
            machine1.runOneCycle();
            break;
        }
            
        
        
        default:
            break;
        }

    }
    
    
    
    return 0;
}
