#include <string>
#include "../Header_files/house.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <conio.h>

using namespace std;
vector<House> available;

void addHouse();
void displayHouse();
void filterHouse();
void menu();
int main()
{
    House house;
    house.loadFile(available);
    menu();
    house.saveFile(available);
    system("pause");
}

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
        system("CLS");
        cin.ignore();
        cout << string(55, '-') << endl;
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
        house.setRatio(price / bedrooms);

        available.push_back(house);

        cout << string(55, '-') << endl;
        char c;
        cout << "Do you want to add another house? Press Y for yes, N for no : ";
        c = _getch();
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
    system("pause");
}

void filterHouse()
{
    string address;
    int bedrooms;
    int price;
    float ratio;
    int choice;
    int counter = 0;
    cout << "Note: The developers are working on the AI filter system, that the system predict the price acordingly, so the house by location is not available at the moment." << endl;
    cout << string(77, '-') << endl;
    cout << "1. Filter by price" << endl;
    cout << "2. Filter by bedrooms" << endl;
    cout << "3. Filter by both price/size ratio" << endl;
    cout << string(77, '-') << endl;
    cout << "Enter your choice : ";
    cin >> choice;
    switch (choice)
    {
        case 1 :
            counter = 0;
            cout << "Enter the price max price : ";
            cin >> price;

            cout << left << setw(25) << "Owner" 
                 << setw(30) << "Address" 
                 << setw(12) << "Bedrooms" 
                 << setw(10) << "Price" << endl;
            cout << string(77, '-') << endl;

            for (auto& item : available)
            {   
                if (item.getPrice() <= price)
                {
                    counter++;
                    cout << left << setw(25) << item.getOwnerName()
                        << setw(30) << item.getAddress()
                        << setw(12) << item.getBedrooms()
                        << setw(10) << item.getPrice() << endl;
                }
            }
            if (counter == 0)
            {
                cout << "No house found with the given price." << endl;
            }
            system("pause");
            system("cls");
            break;
        case 2 :
            cout << "1. Specified number of rooms" << endl;
            cout << "2. Largest house" << endl;
            cout << "Enter your choice : ";
            cin >> choice;
            switch (choice)
            {
                case 1 :
                    counter = 0;
                    cout << "Enter the number of bedrooms : ";
                    cin >> bedrooms;
                    cout << left << setw(25) << "Owner" 
                                 << setw(30) << "Address" 
                                 << setw(12) << "Bedrooms" 
                                 << setw(10) << "Price" << endl;
                    cout << string(77, '-') << endl;
                    for (auto& item : available)
                    {
                        if (item.getBedrooms() == bedrooms)
                        {
                            counter++;

                            cout << left << setw(25) << item.getOwnerName()
                                << setw(30) << item.getAddress()
                                << setw(12) << item.getBedrooms()
                                << setw(10) << item.getPrice() << endl;
                        }
                    }
                    if (counter == 0)
                    {
                        cout << "No house found with the given number of bedrooms." << endl;
                    }
                    system("pause");
                    system("cls");
                    break;
                case 2 :
                    int max = 0;
                    counter = 0;
                    for (auto& item : available)
                    {
                        if (item.getBedrooms() > max)
                        {
                            max = item.getBedrooms();
                        }
                    }
                    cout << left << setw(25) << "Owner" 
                                << setw(30) << "Address" 
                                << setw(12) << "Bedrooms" 
                                << setw(10) << "Price" << endl;

                    cout << string(77, '-') << endl;
                    for (auto& item : available)
                    {
                        if (item.getBedrooms() == max)
                        {
                            counter++;
                            cout << left << setw(25) << item.getOwnerName()
                                << setw(30) << item.getAddress()
                                << setw(12) << item.getBedrooms()
                                << setw(10) << item.getPrice() << endl;
                        }
                    }
                    if (counter == 0)
                    {
                        cout << "No house found with the largest number of bedrooms." << endl;
                    }
                    system("pause");
                    system("cls");
                    break;
            }
            break;
        case 3 :
            counter = 0;
            cout << "Enter the price : " ;
            cin >> price;   
            cout << "Enter the number of bedrooms : ";
            cin >> bedrooms; 
            ratio = price / bedrooms;
            cout << left << setw(25) << "Owner" 
                        << setw(30) << "Address" 
                        << setw(12) << "Bedrooms" 
                        << setw(10) << "Price" << endl;

            cout << string(77, '-') << endl;

            for (const auto & item : available)
            {
                if (item.getRatio() <= ratio)
                {
                    counter++;
                    cout << left << setw(25) << item.getOwnerName()
                        << setw(30) << item.getAddress()
                        << setw(12) << item.getBedrooms()
                        << setw(10) << item.getPrice() << endl;
                }
            }
            if (counter == 0)
            {
                cout << "No house found with the given price and number of bedrooms." << endl;
            }
            system("pause");
            system("cls");
            break;
        default :
            cout << "Invalid choice" << endl;
    }
}
void menu()
{
    char choice;
    do
    {
        system("cls");
        cout << "-----------------------------------------------------" << endl;
        cout << "1. Add a new house" << endl;
        cout << "2. Display all houses" << endl;
        cout << "3. Filter all houses" << endl;
        cout << "4. Exit" << endl;
        cout << "-----------------------------------------------------" << endl;
        cout << "Enter your choice : ";
        cin >> choice;
        if (choice == '1')
        {
            addHouse();
        }
        else if (choice == '2')
        {
            cin.ignore();
            displayHouse();
            
        }
        else if (choice == '3')
        {
            system("cls");
            cin.ignore();
            filterHouse();
        }
    }
    while(choice != '4');
}