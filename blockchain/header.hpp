//
// Created by Pasquale on 17/10/2024.
//

#ifndef BLOCKCHAIN_HEADER_HPP
#define BLOCKCHAIN_HEADER_HPP

#include <iostream>
#include <string>
using namespace std;

class transazione{
private:
    string from;
    string to;
    int qt;
public:
    transazione() : from(""), to(""), qt(0){};

    transazione(string f, string t , int q){
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

    void stampa(){
        cout<<"Transizione DA "<<from<<" A "<<to<<", quantita' di denaro trasferita: "<<qt<<endl;
    }
};

template <class T>
class nodo{
private:
    T dato;
    nodo* next;
public:
    nodo(T d) : next(nullptr){
        dato = d;
    }

    void setNext(nodo* n){
        next = n;
    }

    nodo* getNext(){
        return next;
    }

    T getDato(){
        return dato;
    }
};

template <class T>
class lista{
private:
    nodo<T>* head;
    nodo<T>* tail;
public:
    lista() : head(nullptr), tail(nullptr){};

    nodo<T>* getHead(){
        return head;
    }

    void insertAtTail(T d){
        nodo<T>* newNodo = new nodo<T>(d);
        if (head == nullptr){
            head = tail = newNodo;
        }else{
            tail->setNext(newNodo);
            tail = newNodo;
        }
    }

    void removeHead(){
        if(head == nullptr)
            cout<<"Lista già vuota"<<endl;
        else{
            nodo<T>* tmp = head;
            head = head->getNext();
            delete tmp;
        }
    }

    ~lista(){
        while (head != nullptr){
            removeHead();
        }
    }

    void stampa(string key){
        int saldoFinale = 0;
        nodo<T>* current = head;
        while (current != nullptr){
            if(current->getDato().getFrom() == key){
                current->getDato().stampa();
                saldoFinale -= current->getDato().getQt();
            }else if( current->getDato().getTo() == key){
                current->getDato().stampa();
                saldoFinale += current->getDato().getQt();
            }
            current = current->getNext();
        }
        cout<<"Saldo finale pari a: "<<saldoFinale;
    }
};

#endif //BLOCKCHAIN_HEADER_HPP
