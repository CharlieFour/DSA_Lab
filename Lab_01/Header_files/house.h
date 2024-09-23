#pragma once

#include <string>
#include <vector>
class House
{
    private:
        std::string ownerName;
        std::string address;
        int bedrooms;
        int price;
        float ratio;

    public:
        House(){}

        //getters
        std::string getOwnerName() const;
        std::string getAddress() const;
        int getBedrooms() const;
        int getPrice() const;
        float getRatio() const;
        //setters
        void setOwnerName(std::string);
        void setAddress(std::string);
        void setBedrooms(int);
        void setPrice(int);
        void setRatio(float);
        //file handling
        void loadFile(std::vector<House> &houses);
        void saveFile(const std::vector<House> &houses);
};