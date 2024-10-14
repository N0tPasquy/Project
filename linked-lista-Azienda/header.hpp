//
// Created by Pasquale on 12/10/2024.
//
//Progettare e implementare una lista (linked list) di
//impiegati di un'azienda. Un impiegato ha un nome e un
//salario. Un manager è un impiegato cui viene corrisposto
//un bonus oltre al salario.

#ifndef LINKED_LISTA_AZIENDA_HEADER_HPP
#define LINKED_LISTA_AZIENDA_HEADER_HPP

#include <iostream>
#include <string>

using namespace std;

class impiegato{
protected:
    string nome;
    float salario;
public:
    impiegato(string n, float s){
        nome = n;
        salario = s;
    }

    virtual string getNome(){
        return nome;
    }

    virtual float getSalario(){
        return salario;
    }

    virtual void stampa(){
        cout<<"Impiegato "<<nome<<" con salario pari a "<<salario<<endl;
    }
};

class manager : public impiegato{
private:
    float bonus;
public:
    manager(string n, float s, float b) : impiegato(n, s){
        bonus = b;
    }

    float getSalario() override{
        return salario + bonus;
    }

    void stampa() override{
        cout<<"Manager "<<nome<<" con salario pari a "<<salario<<", con bonus pari a "<<bonus<<endl;
    }
};

class nodo{
private:
    impiegato* dati;
    nodo* next;
public:
    nodo(impiegato* tmp){
        dati = tmp;
        next = nullptr;
    }

    impiegato* getDati(){
        return dati;
    }

    void setNext(nodo* n){
        next = n;
    }

    nodo* getNext(){
        return next;
    }
};

class lista{
private:
    nodo* head;
    nodo* last;
public:
    lista() : head(nullptr), last(nullptr){};

    void insert(impiegato* tmp){
        nodo* newNodo = new nodo(tmp);
        if(head == nullptr){
            last = head = newNodo;
        }else{
            last->setNext(newNodo);
            last = newNodo;
        }
    }

    void stampa(){
        nodo* tmp = head;
        if(tmp == nullptr){
            cout<<"Lista vuota!"<<endl;
            return;
        }
        while (tmp != nullptr){
            tmp->getDati()->stampa();
            tmp = tmp->getNext();
        }
    }

    float operator+ (){
        float sommaSalari = 0;
        nodo* tmp = head;
        while (tmp != nullptr){
            sommaSalari += tmp->getDati()->getSalario();
            tmp = tmp->getNext();
        }
        return sommaSalari;
    }

    void remove(){
        if(head == nullptr){
            cout<<"Lista vuota"<<endl;
            return;
        }
        nodo* tmp = head;
        delete head;
        head = tmp->getNext();
    }

    ~lista(){
        while (head != nullptr){
            remove();
        }
    }
};

#endif //LINKED_LISTA_AZIENDA_HEADER_HPP
