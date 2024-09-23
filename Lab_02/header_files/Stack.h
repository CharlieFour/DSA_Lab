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
        void pop(itemType &ite);    
        bool isEmpty();
        bool isFull();
        itemType max();
        itemType min();

};


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

template <class itemType>
itemType Stack<itemType>::max()
{
    if (!std::is_same<itemType, bool>::value)
    {
        if (isEmpty())
        {
            std::cout << "Stack is empty" << std::endl;
            return 0;
        }
        else
        {
            itemType max = items[0];
            for (int i = 1; i <= top; i++)
            {
                if (items[i] > max)
                {
                    max = items[i];
                }
            }
            return max;
        }
    }
    else
    {
        std::cout << "This function is not available for bool type" << std::endl;
        return 0;
    }
}

template <class itemType>
itemType Stack<itemType>::min()
{
    if (!std::is_same<itemType, bool>::value)
    {
        if (isEmpty())
        {
            std::cout << "Stack is empty" << std::endl;
            return 0;
        }
        else
        {
            itemType min = items[0];
            for (int i = 1; i <= top; i++)
            {
                if (items[i] < min)
                {
                    min = items[i];
                }
            }
            return min;
        }
    }
    else
    {
        std::cout << "This function is not available for bool type" << std::endl;
        return 0;
    }
}