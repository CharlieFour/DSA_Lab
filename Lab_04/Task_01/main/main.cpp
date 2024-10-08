#include <iostream>
#include "../libraries/Queue.h"

using namespace std;

int main()
{
    Queue<int> queue;
    int number = 1;
    while (number < 10)
    {
        queue.insert(number);
        number++;
    }
    while (!queue.isEmpty())
    {
        cout << queue.remove() << " ";
    }
    system("pause");
    return 0;
}