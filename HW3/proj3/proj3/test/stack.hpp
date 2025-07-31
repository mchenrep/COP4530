#ifndef STACK_HPP
#define STACK_HPP
#include <iostream>
#include <vector>
#include "stack.h"

using namespace cop4530;

// constructor/destructors
template <typename T>
Stack<T>::Stack() : container() {}

template <typename T>
Stack<T>::~Stack()
{
    clear();
} 

template <typename T>
Stack<T>::Stack (const Stack<T>& s)
{
    container = s.container;
}
template <typename T>
Stack<T>::Stack(Stack<T> && s) 
{
    container(move(s.container));
}

// accessor/mutators

template <typename T>
Stack<T>& Stack<T>::operator= (const Stack <T>& s)
{
    container = s.container;
    return *this;
}

template <typename T>
Stack<T> & Stack<T>::operator=(Stack<T> && s)
{
    container = move(s.container);
    return *this;
}

template <typename T>
bool Stack<T>::empty() const 
{ 
    return container.empty();
}

template <typename T>
void Stack<T>::clear()
{
    container.clear();
}

template <typename T>
void Stack<T>::push(const T & x)
{
    container.push_back(x);
}
template <typename T>
void Stack<T>::push(T && x)
{
    container.push_back(x);
}

template <typename T>
void Stack<T>::pop() 
{ 
    if(!empty())
        container.pop_back();
}

template <typename T>
T& Stack<T>::top()
{
    return container.back();
}

template <typename T>
const T& Stack<T>::top() const 
{ 
    return container.back();
}

template <typename T>
int Stack<T>::size() const 
{ 
    return container.size();
}

template <typename T>
void Stack<T>::print(std::ostream& os, char ofc) const
{
    for(auto i : container)
    {
        std::cout<<i<<ofc;
    }
}

// non-member functions

template <typename T>
std::ostream& operator<< (std::ostream& os, const Stack<T>& a)
{
    a.print(os);
    return os;
}

template <typename T>
bool operator== (const Stack<T>& a, const Stack <T>& b)
{
    if(a.size() != b.size())
        return false;
    for(int i = 0; i < a.size(); i++)
    {
        if(a.container[i] != b.container[i])
            return false;
    }
    return true;
}

template <typename T>
bool operator!= (const Stack<T>& a, const Stack <T>& b)
{
    return !(a == b);
}

template <typename T>
bool operator<=(const Stack<T>& a, const Stack <T>& b)
{
    return (a.container <= b.container);
}




#endif
