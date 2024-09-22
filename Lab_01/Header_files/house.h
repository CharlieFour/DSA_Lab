#pragma once

#include <string>
class House
{
    private:
        std::string ownerName;
        std::string address;
        int bedrooms;
        int price;

    public:
        House(){}

        //getters
        std::string getOwnerName() const;
        std::string getAddress() const;
        int getBedrooms() const;
        int getPrice() const;
        //setters
        void setOwnerName(std::string);
        void setAddress(std::string);
        void setBedrooms(int);
        void setPrice(int);
        //file handling
        void loadFile(std::vector<House> &houses);
        void saveFile(std::vector<House> &houses);
};