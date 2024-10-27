#include "list.h"
#include <iostream>
#include <fstream>

List::List(){
    list = nullptr;
    length = 0;
}

void List::iAE(int x, int y){
    if(list == nullptr){
        Nodeptr p = new Node;
        p->number = x;
        p->exponent = y;
        p->prev = list;
        p->next = nullptr;
        list = p;

        length++;
        return;
    }
    Nodeptr p = list;
    while(p->prev != nullptr){
        p = p->prev;
    }
    Nodeptr q = new Node;
    p->number = x;
    p->exponent = y;
    q->prev = nullptr;
    q->next = p;
    p->prev = q;

    length++;
}

void List::clear(){
    Nodeptr p = list->prev;
    while(p->prev != nullptr){
        Nodeptr q = p->next;
        delete p;
        p = q;
    }
}