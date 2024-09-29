#include <iostream>
#include "../libraries/Stack.h"
#include <string>
#include <ctime>

int main()
{
    Stack<int> myStack2(10);

    std::srand(std::time(0));

    for(int i = 0; i < 10; i++)
    {
        myStack2.push(std::rand() % 100 + 1);
    }

    std::cout << "\nMaximum number: " << myStack2.max() << std::endl;
    std::cout << "Minimum number: " << myStack2.min() << std::endl;

    while(!myStack2.isEmpty())
    {
        std::cout << myStack2.pop() << std::endl;
    }

    Stack<bool> boolStack(5);
    boolStack.push(true);
    boolStack.push(false);

    boolStack.max();

    return 0;
}