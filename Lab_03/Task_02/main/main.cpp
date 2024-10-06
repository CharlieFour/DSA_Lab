#include <iostream>

using namespace std;

int computeBio(int n, int k);
main()
{
    int n ,k;
    cout << "Enter the k : ";
    cin >> k;
    cout << "Enter the n : ";
    cin >> n;
    int b = computeBio(n, k);
    cout << "The Binomial is : " << b << endl;
    system("pause");
    return 0; 
}

int computeBio(int n, int k)
{
    if(k == 0 || k == n)
    {
        return 1;
    }
    else if (!(k > 0 && k < n || n > 1))
    {
        return 0;
    }
    else
    {
        return computeBio(n - 1, k - 1) + computeBio(n - 1, k);
    }
}