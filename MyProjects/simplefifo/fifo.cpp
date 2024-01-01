#include "fifo.h"
#include <iostream>
#include <cstring>



fifo::fifo(unsigned int fifo_size): fifoSize {fifo_size}
{
    std::cout << "fifo is created with size " << fifo_size << std::endl;
    this->p_fifo = new char[fifo_size];
    this->p_read = p_fifo;
    this->p_write= p_fifo;
    count = 0;
    fifo_empty = true;
    fifo_full = false;
}

fifo::~fifo()
{
    std::cout << "Fifo is deleted !\n";
    delete [] p_fifo;
}

fifo::fifo(const fifo &source) {       // cpy constructor

this->p_fifo = source.p_fifo;
this->p_read = source.p_read;
this->fifoSize = source.fifoSize;
this->p_write = source.p_write;
std::memcpy(this->p_fifo, source.p_fifo, source.fifoSize); // do a deep copy
}

void fifo::fifo_print() const{
    if (fifo_empty)
        return;
    std::cout << this->fifoSize <<  std::endl;
    char * tp = p_fifo;
    for (size_t i = 0 ; i < fifoSize; i++){
        std::cout << *tp++ << ",";
    }
    char v;
    itoa(this->count,&v, 10);
    std::cout << "\nfifo has " << v << " values" << std::endl;
    std::cout << " is fifo full ? " << this->fifo_full << std::endl;
    std::cout << " is fifo empty ? " << this->fifo_empty << std::endl;
    
}

char fifo::fifo_push(const char charIn){
    if (count==fifoSize){
        fifo_full = true;
        fifo_empty = false;
        std::cout << "fifo is full error !\n";
        return 1;
    }
        
    else{
        if (p_write>=(p_fifo + fifoSize)) p_write = p_fifo;
          std::cout << " fifo push val " << charIn << std::endl;
          *p_write++ = charIn;
           count++;
           fifo_empty = false;
           
        }
        return 0;
        
}
char fifo::fifo_get(char * p_ch) {
    if (count==0){
        std::cout << "Fifo Is empty !!\n";
        fifo_empty = true;
        fifo_full = false;
        return 1;        
    }
    else{
        if (p_read>=(p_fifo + fifoSize)) p_read = p_fifo;
         count--;
         *p_ch = *p_read++ ;
         if (count==0){
             fifo_empty = true;
             fifo_full = false;
         }
         else fifo_empty = false;
         std::cout << " fifo get val " << *p_ch << std::endl;
         return 0;
    }

}

bool fifo::isFifofull() const{
    return fifo_full;
}
bool fifo::isFifoempty() const{
    return fifo_empty;
}

unsigned char fifo::get_fifo_count() const{
    return count;
}