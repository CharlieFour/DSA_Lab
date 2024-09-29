#pragma once
#include <iostream>
#include <type_traits>

template <class itemType>
class Stack
{
    private:
        int top;
        int maxStack;
        itemType* items;

    public:
        Stack(int max);
        Stack();
        ~Stack();
        void push(itemType newItem);
        itemType pop();    
        bool isEmpty();
        bool isFull();
        itemType max();
        itemType min();

};
#include "Stack.cpp"