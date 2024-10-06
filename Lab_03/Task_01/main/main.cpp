#include <iostream>

using namespace std;

void printR(int n);
main ()
{
    int a;
    cout << "Enter a number to print from to 0 in reverse: ";
    cin >> a;
    printR(a);
    system("pause");
    return 0;
}

void printR(int n)
{
    if(n == 0)
    {
        return;
    }
    else
    {
        cout << n << endl;
        printR(n - 1);
    }
}