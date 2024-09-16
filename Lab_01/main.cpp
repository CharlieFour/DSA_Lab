#include <string>
#include "house.h"
#include <iostream>

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

    do
    {
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
    for (int i = 0; i < count; i++)
    {
        cout << "Owner : " << available[i].getOwnerName() << endl;
        cout << "Address : " << available[i].getAddress() << endl;
        cout << "Bedrooms : " << available[i].getBedrooms() << endl;
        cout << "Price : " << available[i].getPrice() << endl;
    }
}
int main()
{
    addHouse();
    displayHouse();
}