#include <iostream>
#include "List.hpp"
#include "MyMemoryBlock.h"

using namespace std;

MyMemoryBlock::MyMemoryBlock(int ind, int len): index(ind), length(len){}

    //accessors
int MyMemoryBlock::get_length()
{
    return length;  
}
int MyMemoryBlock::get_index()
{
    return index;
}

    //mutators
int MyMemoryBlock::allocate_mem(int len)
{
    if(len > length)
        return -1;
    else
    {
        length -= len;
        return len;
    }
}
void MyMemoryBlock::free_mem(int len)
{
    length += len;
}