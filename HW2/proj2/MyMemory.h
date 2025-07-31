#include <iostream>
#include "List.hpp"
#include "MyMemoryBlock.h"

using namespace std;

class MyMemory{
    public:
        MyMemory(int num=0, int len=0);
        void resize(int num=100, int len=100);
        int req_mem(int len);
        bool release_mem(int ind, int len);
        void merge_mem();
        void dump();
        ~MyMemory(); // destructor
    
    private:
        List<MyMemoryBlock> mlist;
        int max_index;
        int block_size;
};