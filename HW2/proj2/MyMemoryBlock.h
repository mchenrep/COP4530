#ifndef MY_MEMORY_BLOCK_H  // Check if MY_MEMORY_BLOCK_H is not defined
#define MY_MEMORY_BLOCK_H  // Define MY_MEMORY_BLOCK_H
#include <iostream>
#include "List.hpp"

class MyMemoryBlock{
    public:
        MyMemoryBlock(int ind = 0, int len = 0);

    //accessors
        int get_length();
        int get_index();

    //mutators
        int allocate_mem(int len);
        void free_mem(int len);
    
    private:
        int index;
        int length;
};

#endif