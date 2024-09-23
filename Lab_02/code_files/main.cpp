#include <iostream>
#include "../header_files/Stack.h"

using namespace std;

int main()
{
    Stack<int> intStack;
    Stack<string> stringStack;
    Stack<float> floatStack;
    Stack<bool> boolStack;

    intStack.push(100);
    intStack.push(40);
    intStack.push(5);
    stringStack.push("hello");
    stringStack.push("hillo");
    floatStack.push(3.14);
    floatStack.push(3.54);

    /*int intVal;
    intStack.pop(intVal);
    cout << "This value is poped from int Stack: " << intVal << endl;

    string strVal;
    stringStack.pop(strVal);
    cout << "This value is popped from string Stack: " << strVal << endl;

    float floatVal;
    floatStack.pop(floatVal);
    cout << "This value is popped from float Stack: " << floatVal << endl;*/

    cout << "Maximum value in int Stack: " << intStack.max() << endl;
    cout << "Minimum value in int Stack: " << intStack.min() << endl;

    cout << "Maximum value in string Stack: " << stringStack.min() << endl;

    cout << "Maximum value in float Stack: " << floatStack.max() << endl;
    
    boolStack.push(true);
    cout << "Maximum value in bool Stack: " << boolStack.max() << endl;
    system("pause");
}