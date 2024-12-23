//
// Created by Pasquale & Nazzaro il patatone on 05/10/2024.
//

#ifndef RISPETTA_I_VERSI_HEADER_HPP
#define RISPETTA_I_VERSI_HEADER_HPP

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class rigo{
private:
    string soluzione, problema, simboli;   //variabili dove salvo il contenuto di ogni rigo che viene passato in input
    vector <int> numeri;
public:
    rigo(): soluzione(" "), problema(" "){};

    void setSoluzione(string sol){
        soluzione = sol;
    }

    void setProblema(string prob){
        problema = prob;
    }

    //!OK
    bool confrontaSimboli(){                          //!confronta i simboli estratti dalla soluzione con quelli nel problema. Se c'è una
        if(problema.length() != simboli.length())      //!differenza, restituisce false (non è una soluzione); altrimenti, true (è una possibile soluzione).
            return false;
        for(int i = 0; i <= problema.length(); i++){
            if(problema[i] != simboli[i]){
                return false;
            }
        }
        return true;
    }

    //!OK
    bool controllaDuplicati(){                        //!Verifica se ci sono numeri duplicati nella soluzione utilizzando un array di booleani per
        bool Char[256] = {false};                    //!tracciare i caratteri visti. Restituisce true se non ci sono duplicati, false altrimenti.
        for(int i = 0; i < numeri.size(); i++){
            int ch = numeri[i];
            if(Char[ch]){
                return false;
            }
            Char[ch] = true;
        }
        return true;
    }

    //!OK
    bool verificaNumeri(){                               //!Controlla che i numeri nella soluzione non superino un certo limite (pari al numero di
        for (int i = 0; i < simboli.length()+1; i++) {      //!simboli + 1). Restituisce true se valido, false altrimenti.
            if(numeri[i] > simboli.length()+1){
                return false;
            }
        }
        return true;
    }

    //!OK
    bool verificaUguaglianze(){                            //!Verifica che i numeri nella soluzione rispettino le disuguaglianze rappresentate dai simboli
        for(int i = 0; i < simboli.length(); i++){             //!< e >. Restituisce true se tutte le condizioni sono rispettate, false altrimenti.
            if(simboli[i] == '<'){
                if(numeri[i] > numeri[i+1]){
                    return false;
                }
            }else{
                if(numeri[i] < numeri[i+1]){
                    return false;
                }
            }
        }
        return true;
    }

    //!OK
    void solToInt(){        //! Dalla stringa soluzione questo metodo divide i numeri in un vector <int> e i simboli in una stringa
        string tmp;

        for(int i = 0; i < soluzione.length(); i++){
            char c = soluzione[i];
            if(c >= '0' && c <= '9'){   //controllo che il carattere analizzato sia un numero
                tmp += c;   //nel caso sia un numero lo salvo in tmp
            }else if(!tmp.empty()){
                simboli += c;   // Crea la stringa simboli
                numeri.push_back(stoi(tmp));    // Crea il vector <int> numeri
                tmp = "";   //resetto tmp per i successivi numeri
            }
        }
        if(!tmp.empty())
            numeri.push_back(stoi(tmp));    // Controlla l' ultimo elemento del rigo
    }
};

#endif //RISPETTA_I_VERSI_HEADER_HPP
