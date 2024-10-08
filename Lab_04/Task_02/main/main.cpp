#include <iostream>
#include <algorithm> // for sorting array
#include "../libraries/Queue.h"

using namespace std;
int main()
{
    //Taking inputs
    int size, number;
    cout << "Enter the size of the queue : ";
    cin >> size;
    cout << "Enter the number : ";
    cin >> number;
    Queue<int> queue(size);
    int input;
    cout << "Enter the numbers : " << endl;
    for(int i = 0; i < size; i++)
    {
        cin >> input;
        queue.insert(input);
    }

    // Inserting item into the array
    int array[size];
    for (int i = 0; i < size; i++)
    {
        array[i] = queue.remove();
    }

    // Reversing the array
    int array2[number];
    for (int i = 0; i < number; i++)
    {
        array2[i] = array[i];
    }
    reverse(array2, array2 + number);
    for (int i = 0; i < number; i++)
    {
        array[i] = array2[i];
    }

    // Inserting the reversed array back into the queue	
    for (int i = 0; i < size; i++)
    {
        queue.insert(array[i]);
    }
    cout << "Queue after reversing : ";
    while (!queue.isEmpty())
    {
        cout << queue.remove() << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}

