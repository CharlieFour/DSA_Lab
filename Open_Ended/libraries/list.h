#pragma once
typedef struct Node* Nodeptr;

struct Node{
    int exponent;
    int number;
    Nodeptr next;
    Nodeptr prev;
};

class List
{    
    public:
        Nodeptr list;
        int length;
        List();
        void iAE(int x, int y);
        void clear();
};