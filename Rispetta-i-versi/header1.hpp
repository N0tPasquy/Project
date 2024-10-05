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
    string soluzione;
    string problema;
public:
    esito(string sol, string prob): soluzione(sol), problema(prob){};

    string scomponiSimboli(string &sol){
        string simboli;
        for (int i = 0; i < sol.length(); i++) {
            if(sol[i] == '<' || sol[i] == '>'){
                simboli += sol[i];
                sol.erase(i, 1);
            }
        }
        return simboli;
    }

    bool confrontaSimboli(string *prob, string *simboli){
        for(int i = 0; i < prob->length(); i++){
            if(prob[i] != simboli[i]){
                return false;
            }
        }
        return true;
    }

    bool verificaNumeri(string simb, string &num){
        cout<<simb.length()+1<<endl;
        for (int i = 0; i < simb.length()+1; i++) {
            if((num[i] - '0') > simb.length()+1){   //Con num[i] - '0' viene eseguita la sottrazione ASCII tra l' i-esimo num e 0,
                return false;                       // questo permette la conversione da string a int
            }
        }
        return true;
    }

};

#endif //RISPETTA_I_VERSI_HEADER1_HPP
