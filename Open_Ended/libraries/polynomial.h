#pragma once

#include <iostream>
#include <fstream>
#include "list.h"

class Polynomial
{
    public:
        Polynomial();
        Polynomial(int d);
        List readPolynomial(std::string fileName);
        List addPolynomial(List p1, List p2);
        List multiplyPolynomial(List p1, List p2);
        void evaluatePolynomial(int x, List p);
};