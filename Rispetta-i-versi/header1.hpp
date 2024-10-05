//
// Created by Pasquale on 05/10/2024.
//
//!-- SPIEGAZIONE:
//  Ll problema va risolto in modo tale che ogni rigo di Problema.txt e Soluzione.txt sia una istanza di una classe
//  il file "header.hpp" non l'ho eliminato perché il codice scritto può servire per essere ricopiato nella scrittura
//  dei metodi di questo nuovo header. Avevo sbagliato a capire la traccia fin dall'inizio per questo l'esercizio
//  risultava più difficile del dovuto, riprenderò a risolverlo in giornata
//

#ifndef RISPETTA_I_VERSI_HEADER1_HPP
#define RISPETTA_I_VERSI_HEADER1_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

class esito{
private:
    string soluzione;   //variabili dove salvo il contenuto di ogni rigo che viene passato in input
    string problema;
public:
    esito(string sol, string prob): soluzione(sol), problema(prob){};   //Per ogni istanza di esito, prendo in input l'
                                                                        // i-esimo rigo che viene passato dall main

    string scomponiSimboli(string &sol){    //metodo per dividere i numeri dai simboli < e >
        string simboli;
        for (int i = 0; i < sol.length(); i++) {    //ciclo for per scorrere tutto il rigo attuale di soluzione
            if(sol[i] == '<' || sol[i] == '>'){ //controllo l' i-esimo carattere di soluzione
                simboli += sol[i];      //se in posizione [i] di "sol" trovo uno tra i simboli < e > lo salvo nella stringa "simboli"
                sol.erase(i, 1);    //una volta salvato il simbolo, lo elimino dalla stringa di partenza
            }                              //così facendo alla fine del ciclo nella stringa "sol" (che sarebbe il rigo di Soluzione.txt)
        }                                  //troveremo solamente numeri
        return simboli; //ritorno la nuova stringa contente i simboli < e > del rigo Soluzione.txt,
    }                   // mentre peri numeri lavoro direttamente sulla stringa originale tramite riferimento

    bool confrontaSimboli(string *prob, string *simboli){   //metodo dove vengono confrontati i simboli trovati in precedenza con i simboli di "Problema.txt", prendo in input i puntatori alle stringhe
        if(prob->length() != simboli->length())     //verifico che entrambi i righi abbiano la stessa lunghezza
            return false;   // se così non fosse significa che non è soluzione, quindi ritorno falso

        for(int i = 0; i < prob->length(); i++){    //ciclo che scorre il rigo di problema
            if(prob[i] != simboli[i]){  //se l' i-esimo simbolo di "prob" e l' i-esimo simbolo di "simboli" sono
                return false;           //diversi significa che non è soluzione, quindi ritorno falso
            }
        }
        return true; //nel caso sia tutto uguale ritorno vero
    }

    bool verificaNumeri(string simb, string &num){  //metodo per controllare che in ogni rigo ci siano N numeri quante sono le "caselle" di Soluzione.txt
        for (int i = 0; i < simb.length()+1; i++) { //le caselle sono sempre il numero dei simboli + 1, quindi itero il ciclo tante volte quante sono le caselle
            if((num[i] - '0') > simb.length()+1){   //Con num[i] - '0' viene eseguita la sottrazione ASCII tra l' i-esimo num e 0, questo permette la conversione da string a int,
                return false;                       // dopo la conversione verifico se il numero appena trovato è piu grande del numero massimo consentito
            }                                       // se così fosse significa che non è soluzione, quindi ritorno falso
        }
        return true;    //nel caso in cui tutti i numeri non superano N (dove N è il numero di caselle) ritorno vero
    }

};

#endif //RISPETTA_I_VERSI_HEADER1_HPP
