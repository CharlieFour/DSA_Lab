#include <iostream>

using namespace std;
bool isPrime(int n, int i = 2);

main()
{
    int n;
    char ch;
    do
    {
        cout << "\nEnter a number : ";
        cin >> n;
        if(isPrime(n))
        {
            cout << n << " is a prime number." << endl;
        }
        else
        {
            cout << n << " is not a prime number." << endl;
        }
        cout << "\nDo you want to continue? (y/n) : ";
        cin >> ch;
    }
    while(ch != 'n');
}
bool isPrime(int n, int i)
{
    if(n <= 0)
    {
        return false;
    }
    else
    {
        if(i == n)
        {
            return true;
        }
        else
        {
            if(n % i == 0)
            {
                return false;
            }
            else
            {
                return isPrime(n, i+1);
            }
        }
    }
}