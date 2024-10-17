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
    transizione(){};

    transizione(string f, string t , int q){
        from = f;
        to = t;
        qt = q;
    }

    void setFrom(string f){
        from = f;
    }
    string getFrom(){
        return from;
    }

    void setTo(string t){
        to = t;
    }
    string getTo(){
        return to;
    }

    void setQt(int q){
        qt = q;
    }
    int getQt(){
        return qt;
    }
};

template <class T>
class nodo;

template <class T>
class list{
private:
    nodo<T>* head;
public:
    list() : head(nullptr){};

    void insert(T tmp){
        nodo<T>* newNodo = new nodo<T>(tmp);
        if(head == nullptr){
            head = newNodo;
        }else{
            newNodo->setNext(head);
            head = newNodo;
        }
    }

    nodo<T>* getHead(){
        return head;
    }

};

template <class T>
class nodo{
private:
    T dato;
    nodo* next;
public:
    nodo(T d){
        dato = d;
    }

    void setDato(T d){
        dato = d;
    }
    T getDato(){
        return dato;
    }
    void setNext(nodo* n){
        next = n;
    }
    nodo* getNext(){
        return next;
    }
};

#endif //BLOCKCHAIN_HEADER_HPP
