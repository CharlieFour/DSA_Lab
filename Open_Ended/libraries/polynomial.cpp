#include "polynomial.h"
#include "list.h"
#include <iostream>
#include <sstream>
#include <string>
#include <cctype>
#include <cmath>

Polynomial::Polynomial(){
}

Polynomial::Polynomial(int d){
}

List Polynomial::readPolynomial(std::string fileName)
{
    List list;
    std::ifstream file(fileName);
    int x = 0, y = 0;  // x is the coefficient, y is the exponent
    std::string line;
    if (getline(file, line)) {
        int i = 0;
        while (i < line.size()) {
            if (isdigit(line[i]) || (line[i] == '-' && isdigit(line[i + 1]))) {
                // Read the coefficient (may be multi-digit or negative)
                std::string coeffStr;
                if (line[i] == '-') {
                    coeffStr += '-';
                    i++;
                }
                while (isdigit(line[i])) {
                    coeffStr += line[i++];
                }
                x = std::stoi(coeffStr);

                // Check if exponent follows
                if (line[i] == 'x') {
                    i++;  // Skip 'x'
                    if (i < line.size() && line[i] == '^') {
                        i++;  // Skip '^'
                        std::string expStr;
                        while (isdigit(line[i])) {
                            expStr += line[i++];
                        }
                        y = std::stoi(expStr);
                    } else {
                        y = 1;  // Implicit exponent 1 for terms like '2x'
                    }
                } else {
                    y = 0;  // Constant term
                }

                // Add the term to the list
                list.iAE(x, y);
            }
            i++;
        }
    }
    file.close();
    return list;
}

List Polynomial::addPolynomial(List p1, List p2)
{
    Nodeptr current1 = p1.list;
    Nodeptr current2 = p2.list;
    List result;
    while(current1 != nullptr)
    {
        while(current2 != nullptr)
        {
            if(current1->exponent == current2->exponent)
            {
                result.iAE(current1->number + current2->number, current1->exponent);  
            }
            current2 = current2->prev;
        }
        current1 = current1->prev;
    }
    return result;
}

List Polynomial::multiplyPolynomial(List p1, List p2)
{
    Nodeptr current1 = p1.list;
    Nodeptr current2 = p2.list;
    List result;
    while(current1 != nullptr)
    {
        while(current2 != nullptr)
        {
            result.iAE(current1->number * current2->number, current1->exponent + current2->exponent);   
            current2 = current2->prev;
        }
        current1 = current1->prev;
    }
    return result;
}

void Polynomial::evaluatePolynomial(int x, List p)
{
    Nodeptr current = p.list;
    int result = 0;
    while(current != nullptr)
    {
        result = result + pow((current->number * x), current->exponent);
    }
    std::cout << "The value of the polynomial at x = " << x << " is: " << result << std::endl;
}