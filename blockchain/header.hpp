//
// Created by Pasquale on 17/10/2024.
//

#ifndef BLOCKCHAIN_HEADER_HPP
#define BLOCKCHAIN_HEADER_HPP

#include <iostream>
#include <string>
using namespace std;

//La classe transazione contiene tutte le informazioni riguardanti un movimento di denaro
class transazione{
private:
    string from;
    string to;
    int qt;
public:
    transazione() : from(), to(), qt() {};  //Costruttore di default

    transazione(string f, string t , int q){    //Costruttore parametrizzato
        from = f;
        to = t;
        qt = q;
    }

    string getFrom(){   //Metodi get degli attributi della classe
        return from;
    }

    string getTo(){
        return to;
    }

    int getQt(){
        return qt;
    }

    void stampa(){  //Metodo che stampa a video il movimento salvato nell' istanza della classe
        cout<<"Transizione da: "<<from<<endl<<"a: "<<to<<endl<<"quantita' di denaro trasferita: "<<qt<<endl;
        cout<<"---"<<endl;
    }
};

//La classe template nodo contiene un dato di tipo T (una volta sarà un oggetto di transazione, un altra volta sarà una lista) e un puntatore al nodo successivo
template <class T>
class nodo{
private:
    T dato;
    nodo* next;
public:
    nodo(T d) : next(nullptr){  //Costruttore parametrizzato dove viene passato un oggetto di tipo classe transazione oppure una lista
        dato = d;
    }

    void setNext(nodo* n){
        next = n;
    }

    nodo* getNext(){
        return next;
    }

    T getDato(){    //Ritorna il tipo di dato contenuto all' interno del nodo
        return dato;
    }
};

//La classe template lista gestisce i nodi, una volta gestisce nodi con oggetti transazioni e un altra volta nodi con oggetti di tipo lista
template <class T>
class lista{
private:
    nodo<T>* head;
    nodo<T>* tail;
public:
    lista() : head(nullptr), tail(nullptr){};   //Costruttore di default

    nodo<T>* getHead(){
        return head;
    }

    void insertAtTail(T d){ //Metodo per inserire un nuovo nodo alla fine della lista
        nodo<T>* newNodo = new nodo<T>(d);
        if (head == nullptr){   //Gestisce il caso in vogliamo inserire un nodo in una lista vuota
            head = tail = newNodo;
        }else{
            tail->setNext(newNodo); //Inserimento "in fondo" alla lista
            tail = newNodo;
        }
    }

    void removeHead(){  //Rimuove il nodo alla testa della lista
        if(head == nullptr)
            cout<<"Lista già vuota"<<endl;
        else{
            nodo<T>* tmp = head;
            head = head->getNext();
            delete tmp;
        }
    }

    ~lista(){   //Il distruttore di lista invoca il metodo removeHead() fin quando la lista non contiene più nessun nodo
        while (head != nullptr){
            removeHead();
        }
    }

    int stampa(string key){ //Quando invocato su una lista di transazioni, scorre all' interno di tutta la lista e quando trova lo stesso nome
        int saldo = 0;      // della key che gli viene passata in input, aggiunge o sottrae la quantità qt di denaro
        nodo<T>* current = head;
        while(current != nullptr){
            if(current->getDato().getFrom() == key){
                current->getDato().stampa();
                saldo -= current->getDato().getQt();
            }else if(current->getDato().getTo() == key){
                current->getDato().stampa();
                saldo += current->getDato().getQt();
            }
            current = current->getNext();
        }
        return saldo;   //Alla fine del ciclo while ritorno il saldo "temporaneo" dell indirizzo key.
    }                   // Temporaneo perché questo metodo fa la scansione sulla lista di transazioni, poi ritorna il risultato che verrà
};                      // sommato/sottratto al saldoFinale

//Classe blocco implementa una lista di transazioni e gestisce l' inserimento di una nuova transazione in fonda alla lista di transazioni
class blocco{
private:
    lista<transazione> listaTransazioni;
public:
    blocco(){};

    void aggiungiTransazione(transazione t){
        listaTransazioni.insertAtTail(t);
    }

    lista<transazione> getListaTransazioni(){
        return listaTransazioni;
    }

    int stampaTransazione(string key){  //Metodo che invoca stampa() della classe lista con oggetti di transazioni
        return listaTransazioni.stampa(key);    // e ritorna al chiamante il saldo "temporaneo" calcolato all' interno del blocco
    }

};

//La classe blockChain implementa una lista di blocchi, gestisce l' inserimenti di nuovi blocchi all' interno della lista
class blockChain{
private:
    lista<blocco> listaBlockChain;
public:
    blockChain(){};

    void aggiungiBlocco(blocco b){  //In input gli passiamo un oggetto di tipo blocco, che non è altro che un contenitore di una lista di transazioni
        listaBlockChain.insertAtTail(b);
    }

    void stampaTransizioni(string key){ //Richiama il metodo stampaTransazione() della classe blocco, su ogni blocco presente all' interno della lista blockChain
        nodo<blocco>* current = listaBlockChain.getHead();  // e a ogni occorrenza somma al saldo finale il saldo "temporaneo" calcolato all' interno di ogni blocco
        int saldoFinale = 0;
        while (current != nullptr){
            saldoFinale += current->getDato().stampaTransazione(key);
            current = current->getNext();
        }
        cout<<"Saldo finale di "<<key<<" pari a " <<saldoFinale<<endl;  //alla fine stampa il saldo dell' indirizzo che stavamo cercando
    }

    bool exist(string key){ //Metodo che controlla se un indirizzo esiste all' interno della blockChain
        nodo<blocco>* current = listaBlockChain.getHead();
        while (current != nullptr){
            if(current->getDato().getListaTransazioni().getHead()->getDato().getFrom() == key || current->getDato().getListaTransazioni().getHead()->getDato().getTo() == key){
                return true;    //Ritorna vero se esiste almeno una volta
            }
            current = current->getNext();
        }
        return false; //Altrimenti ritorna falso
    }
};

#endif //BLOCKCHAIN_HEADER_HPP
