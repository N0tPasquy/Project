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

#include <string>
#include <vector>
using namespace std;

class esito{
private:
    string soluzione;
    string problema;
    int numCaselle;
public:
    esito(string* sol, string* prob, int num): soluzione(*sol), problema(*prob), numCaselle(num){};

    string scomponiSimboli(){
        string simboli;
        for (int i = 0; i < soluzione.length(); i++) {
            if(soluzione[i] == '<' || soluzione[i] == '>'){
                simboli += soluzione[i];
                numCaselle++;
            }
        }
        return simboli;
    }

    string scomponiNumeri(){
        string numeri;
        stoi(soluzione);
        for (int i = 0; i < soluzione.length(); i++) {
            if(soluzione[i] >= 1 && soluzione[i] <= numCaselle){
                numeri += soluzione[i];
            }
        }
        return numeri;
    }

};

#endif //RISPETTA_I_VERSI_HEADER1_HPP
