#include <iostream>
#include "List.hpp"
#include "MyMemory.h"

using namespace std;

MyMemory::MyMemory(int num, int len): max_index(num-1), block_size(len)
        /* constructor which creates memory blocks in order of increasing index till parameter and allocates length from parameter */ 
        {
            for(int i = 0; i < num; i++)
            {
                mlist.push_back(MyMemoryBlock(i,len));
            }
        }
void MyMemory::resize(int num, int len)
    {
        mlist.clear();
        MyMemory(num,len); // resizes list based on parameters
    }
int MyMemory::req_mem(int len)
    {
        for(auto i = mlist.begin(); i != mlist.end(); ++i)
        {   
            if(i->get_length() >= len) // if a MMB in the list has required memory, allocate it. if the MMB gets used up, delete it from the list
            {
                i->allocate_mem(len);
                if(i->get_length() == 0)
                    mlist.erase(i);
                return i->get_index();
            }
        }
        return -1; // else return -1
}
bool MyMemory::release_mem(int ind, int len)
{
    bool indexExists = false;
    if(ind > max_index || len > block_size || len < 0 || ind < 0) // if parameters are not within bounds return false
        return false;
    else // else if index is found, free memory. if index doesn't exist yet, insert a MMB by the order of indexes
    {
        auto i = mlist.begin();
        while(i->get_index() <= ind && i != mlist.end())
        {
            if(i->get_index() == ind)
            {
                i->free_mem(len);
                indexExists = true;
            }
            ++i;
        }
        if(!indexExists)
            mlist.insert(i, MyMemoryBlock(ind,len));
        return true;
    }
}
void MyMemory::merge_mem()
{
    for(auto i = mlist.begin(); i != mlist.end(); ++i)
    {
        auto j = i; // iterator for the next index in list
        ++j;
        while(i->get_length() + j->get_length() <= block_size && j != mlist.end())
        {
            i->free_mem(j->get_length()); // merges memory with the smaller index and deletes the next index while iterating it
            j = mlist.erase(j);
        }
    }
}
void MyMemory::dump()
{
    // based on output in proj2.x
    cout<<"Number of blocks: "<<mlist.size()<<"\n";
    for(auto i = mlist.begin(); i != mlist.end(); ++i)
    {
        cout<<"Block(index = "<<i->get_index()<<"): "<<i->get_length()<<"\n";
    }
}
MyMemory::~MyMemory() // destructor
{
    mlist.clear();
}