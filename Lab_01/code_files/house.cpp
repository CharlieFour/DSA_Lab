#include <string>
#include <iostream>
#include <fstream>
#include "../Header_files/house.h"
#include <vector>
#include <sstream>


std::string House::getOwnerName() const
{
    return ownerName;
}

std::string House::getAddress() const
{
    return address;
}

int House::getBedrooms() const
{
    return bedrooms;
}

int House::getPrice() const
{
    return price;
}

void House::setOwnerName(std::string name)
{
    ownerName = name.length() > 20 ? name.substr(0 , 20) : name;
}

void House::setAddress(std::string addr)
{
    address = addr.length() > 20 ? addr.substr(0 , 20) : addr;
}

void House::setBedrooms(int bed)
{
    bedrooms = bed;
}

void House::setPrice(int pri)
{
    price = pri;
}

void loadFile(std::vector<House> &houses)
{
    std::ifstream inFile("../Data/house_data.csv");
    if (inFile.is_open())
    {
        //declear the variables
        House house;
        std::string ownerName, city;
        int price, bedrooms;
        std::string line; // to store a row
        std::getline(inFile, line); //to store the  row

        while(getline(inFile, line))
        {
            std::stringstream ss(line);
            
            // Extract the values separated by commas
            std::getline(ss, ownerName, ',');
            ss >> price;
            ss.ignore();  // Ignore the comma after price
            ss >> bedrooms;
            ss.ignore();  // Ignore the comma after bedrooms
            std::getline(ss, city, ',');
            house.setOwnerName(ownerName);
            house.setPrice(price);
            house.setAddress(city);
            house.setBedrooms(bedrooms);

            houses.push_back(house);
        }
    }
    else
    {
        std::cout << "File not found at the specified location." << std::endl;
    }
}

void saveFile(const std::vector<House> &houses)
{
    std::ofstream outFile("../Data/house_data.csv");

    //Header
    outFile << "Owner name,Price,Bedrooms,City\n";
    //data
    for (const auto&house : houses)
    {
        outFile << house.getOwnerName() << ","
                << house.getPrice() << ","
                << house.getBedrooms() << ","
                << house.getAddress() << "\n";
    }
    outFile.close();
    std::cout << "File saved successfully." << std::endl;
}