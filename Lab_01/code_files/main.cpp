#include <string>
#include "house.h"
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;
vector<House> available;

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

        available.push_back(house);

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
    while(check == true );

}
void displayHouse()
{
    House house;
        cout << left << setw(25) << "Owner" 
            << setw(30) << "Address" 
            << setw(12) << "Bedrooms" 
            << setw(10) << "Price" << endl;

        cout << string(77, '-') << endl;

        for (const auto& item : available)
        {
            cout << left << setw(25) << item.getOwnerName()
                << setw(30) << item.getAddress()
                << setw(12) << item.getBedrooms()
                << setw(10) << item.getPrice() << endl;
        }
}
int main()
{
    House house;
    house.loadFile(available);
    house.saveFile(available);
    system("pause");
}