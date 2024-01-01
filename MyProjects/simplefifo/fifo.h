#ifndef _H_FIFO_DYNAMMIC_
#define _H_FIFO_DYNAMMIC_

class fifo
{
private :
    unsigned int fifoSize;
    char * p_fifo;
    char * p_read;
    char * p_write;
    unsigned char count;
    bool fifo_empty;
    bool fifo_full;
    
    public:
    fifo(unsigned int fifo_size = 16) ;   // overloaded constructor
    fifo(const fifo &source) ;       // cpy constructor
    ~fifo();
    
    char fifo_push(const char charIn);
    char fifo_get(char * p_ch) ;
    void fifo_print() const;
    bool isFifofull() const;
    bool isFifoempty() const;
    unsigned char get_fifo_count() const;

};

#endif // _H_FIFO_DYNAMMIC_
