//
// Created by Pasquale on 17/10/2024.
//

#ifndef BLOCKCHAIN_HEADER_HPP
#define BLOCKCHAIN_HEADER_HPP

#include <iostream>
#include <string>
using namespace std;

class transizione{
private:
    string from;
    string to;
    int qt;
public:
    transizione(string, string, int);

    void setFrom(string);
    string getFrom();

    void setTo(string);
    string getTo();

    void setQt(int);
    int getQt();
};

template <class T>
class blocco{
private:
    T* contenuto;
    blocco *next;
public:
    blocco(T*, blocco*);

    void setContenuto(T*);
    T* getContenuto();

    void setNext(blocco*);
    blocco* getNext();
};

#endif //BLOCKCHAIN_HEADER_HPP
