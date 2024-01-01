#include <iostream>
#include "fifo.h"

using namespace std;
int main(){
    cout << "my own fifo example" << endl;
    char val;
    fifo fifo1(8);
    // fill fifo
    fifo1.fifo_push(0x30);
    fifo1.fifo_push(0x31);
    fifo1.fifo_push(0x32);
    fifo1.fifo_push(0x33);
    fifo1.fifo_push(0x34);
    fifo1.fifo_push(0x35);
    fifo1.fifo_push(0x36);
    fifo1.fifo_push(0x37);
    fifo1.fifo_push(0x38);
    fifo1.fifo_push(0x38);
    fifo1.fifo_print();
    
    // drain fifo
    fifo1.fifo_get(&val);
    fifo1.fifo_get(&val);
    fifo1.fifo_get(&val);
    fifo1.fifo_get(&val);
    fifo1.fifo_get(&val);
    fifo1.fifo_get(&val);
    fifo1.fifo_get(&val);
    fifo1.fifo_get(&val);
    // here empty
    fifo1.fifo_get(&val);

fifo1.fifo_print();

// partially fill fifo
    fifo1.fifo_push(0x30);
    fifo1.fifo_push(0x31);
    fifo1.fifo_push(0x32);
    fifo1.fifo_push(0x33);
    
    fifo1.fifo_get(&val);
    fifo1.fifo_get(&val);
    fifo1.fifo_get(&val);
    fifo1.fifo_get(&val);

fifo1.fifo_print();

// partially fill fifo
    fifo1.fifo_push(0x34);
    fifo1.fifo_push(0x35);
    fifo1.fifo_push(0x36);
    fifo1.fifo_push(0x37);
    // partailly read    
    fifo1.fifo_get(&val);
    fifo1.fifo_get(&val);
    
    
    fifo1.fifo_push(0x44);
    fifo1.fifo_push(0x45);
    fifo1.fifo_push(0x46);
    fifo1.fifo_push(0x47);
    fifo1.fifo_push(0x48);
    fifo1.fifo_push(0x49);
    // full here
    fifo1.fifo_push(0x50);


    fifo1.fifo_get(&val);
    fifo1.fifo_get(&val);
    fifo1.fifo_get(&val);
    fifo1.fifo_get(&val);
    fifo1.fifo_get(&val);
    fifo1.fifo_get(&val);
    fifo1.fifo_get(&val);
    fifo1.fifo_get(&val);
    //here empty
    fifo1.fifo_get(&val);    
    
    fifo1.fifo_print();
    
    cout << fifo1.isFifofull() << endl;
    cout << fifo1.isFifoempty() << endl;;
    
    
    fifo1.fifo_push(0x54);
    fifo1.fifo_push(0x55);
    fifo1.fifo_push(0x56);
    fifo1.fifo_push(0x57);
    fifo1.fifo_push(0x58);
    fifo1.fifo_get(&val);
    fifo1.fifo_get(&val);
    fifo1.fifo_get(&val);
    fifo1.fifo_push(0x64);
    fifo1.fifo_push(0x65);
    fifo1.fifo_push(0x66);
    fifo1.fifo_push(0x67);
    fifo1.fifo_push(0x68);
    fifo1.fifo_get(&val);
    fifo1.fifo_get(&val);
    fifo1.fifo_get(&val);
    fifo1.fifo_push(0x74);
    fifo1.fifo_push(0x75);
    fifo1.fifo_push(0x76);
    fifo1.fifo_push(0x77);
    fifo1.fifo_push(0x78);
    fifo1.fifo_get(&val);
    fifo1.fifo_get(&val);
    fifo1.fifo_get(&val);
    fifo1.fifo_get(&val);
    fifo1.fifo_get(&val);
    fifo1.fifo_get(&val);
    fifo1.fifo_get(&val);
    fifo1.fifo_get(&val);
    fifo1.fifo_get(&val);
    fifo1.fifo_get(&val);
    fifo1.fifo_get(&val);
    fifo1.fifo_get(&val);
    
}