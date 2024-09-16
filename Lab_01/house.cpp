#include <string>
#include "house.h"


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