#include <iostream>
#include "../header_files/Stack.h"

template <class itemType>
Stack<itemType>::Stack()
{
    maxStack = 500;
    top = -1;
    items = new itemType[maxStack];
}
template <class itemType>
Stack<itemType>::Stack(int max)
{
    maxStack = max;
    top = -1;
    items = new itemType[maxStack];
}
template <class itemType>
Stack<itemType>::~Stack()
{
    delete[] items;
}
template <class itemType>
bool Stack<itemType>::isEmpty()
{
    return top == -1;
}

template <class itemType>
bool Stack<itemType>::isFull()
{
    return top == maxStack - 1;
}
template <class itemType>
void Stack<itemType>::push(itemType value)
{
    if (isFull())
    {
        std::cout << "Stack is full" << std::endl;
    }
    else
    {
        top++;
        items[top] = value;
    }
}
template <class itemType>
void Stack<itemType>::pop(itemType &ite)
{
    if (isEmpty())
    {
        std::cout << "Stack is empty" << std::endl;
    }
    else
    {
        ite = items[top--];
    }
}
