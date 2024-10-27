#include <iostream>
#include "../libraries/polynomial.h"
#include "../libraries/list.h"
#include <limits>

using namespace std;

void menu();
int getInput();

main()
{
    List p1, p2;
    Polynomial poly;
    List result;
    p1 = poly.readPolynomial("ptest1");
    p2 = poly.readPolynomial("ptest2");
    menu();
    int input = getInput();
    while(input != 4)
    {
        switch(input)
        {
            case 1:
                result = poly.addPolynomial(p1, p2);
                while(result.list != nullptr)
                {
                    cout << result.list->number << "x^" << result.list->exponent << " ";
                }
                break;
            case 2:
                result = poly.multiplyPolynomial(p1, p2);
                cout << result.list->number << "x^" << result.list->exponent << " ";
                break;
            case 3:
                int a , b;
                a = getInput();
                poly.evaluatePolynomial(a, p1);
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
        menu();
        input = getInput();
    }
    system("pause");
    return 0;
}

void menu()
{
    cout << "1. Addition" << endl;
    cout << "3. Multiplication" << endl;
    cout << "3. Evaluate" << endl;
    cout << "4. Exit" << endl;
}

int getInput()
{
    int x;
    cout << "Enter the input: ";
    if(cin>>x)
    {
        return x;
    }
    else
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cerr << "Invalid input. Please enter a number." << endl;
        return getInput();
    }
}