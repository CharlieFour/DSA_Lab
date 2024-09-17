#include <string>
#include "house.h"
#include <iostream>
#include <iomanip>

using namespace std;
House available[100];
int count = 0;

void addHouse()
{
    string ownerName;
    string address;
    int bedrooms;
    int price;
    bool check;
    House house;
    cout << "-----Enter the House details-----" << endl;


    do
    {
        cout << "-----------------------------------------------------" << endl;
        cout << "Owner : ";
        getline(cin, ownerName);
        house.setOwnerName(ownerName);
        cout << "Address : ";
        getline(cin, address);
        house.setAddress(address);
        cout << "Bedrooms : ";
        cin >> bedrooms;
        house.setBedrooms(bedrooms);
        cout << "Price : ";
        cin >> price;
        house.setPrice(price);

        available[count] = house;
        count++;

        cout << "-----------------------------------------------------" << endl;
        cin.ignore();
        char c;
        cout << "Do you want to add another house? (Y for yes, N for no) : ";
        cin >> c;
        if(c == 'Y' || c == 'y')	
        {
            check = true;
        }
        else if (c == 'N' || c == 'n')
        {
            check = false;
        }
    }
    while(count < 100 && check == true );

}
void displayHouse()
{
        cout << left << setw(25) << "Owner" 
            << setw(30) << "Address" 
            << setw(12) << "Bedrooms" 
            << setw(10) << "Price" << endl;

        cout << string(77, '-') << endl;

        for (int i = 0; i < count; i++)
        {
            cout << left << setw(25) << available[i].getOwnerName()
                << setw(30) << available[i].getAddress()
                << setw(12) << available[i].getBedrooms()
                << setw(10) << available[i].getPrice() << endl;
        }
}
int main()
{
    addHouse();
    displayHouse();
    system("pause");
}