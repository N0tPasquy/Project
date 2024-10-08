//
// Created by Pasquale on 05/10/2024.
//

#ifndef RISPETTA_I_VERSI_HEADER_HPP
#define RISPETTA_I_VERSI_HEADER_HPP

#include <string>
#include <cstring>
using namespace std;

class rigo{
private:
    string soluzione;   //variabili dove salvo il contenuto di ogni rigo che viene passato in input
    string problema;
    string simboli;
public:
    rigo(): soluzione(" "), problema(" "){};

    void setSoluzione(string sol){
        soluzione = sol;
    }

    void setProblema(string prob){
        problema = prob;
    }


    void scomponiSimboli(){                                //! Estrae i simboli < e > da una stringa (soluzione) e li salva in un’altra stringa (simboli),
        for (int i = 0; i < soluzione.length(); i++) {      //! eliminandoli dalla stringa originale.
            if(soluzione[i] == '<' || soluzione[i] == '>'){
                simboli += soluzione[i];
                soluzione.erase(i, 1);
            }
        }
    }

    bool confrontaSimboli(){                          //!confronta i simboli estratti dalla soluzione con quelli nel problema. Se c'è una
        if(problema.length() != simboli.length())      //! differenza, restituisce true (non è una soluzione); altrimenti, false (è una soluzione).
            return true;
        for(int i = 0; i <= problema.length(); i++){
            if(problema[i] != simboli[i]){
                return true;
            }
        }
        return false;
    }

    bool controllaDuplicati(){                        //!Verifica se ci sono numeri duplicati nella soluzione utilizzando un array di booleani per
        bool Char[256] = {false};                    //!tracciare i caratteri visti. Restituisce true se non ci sono duplicati, false altrimenti.
        for(int i = 0; i < soluzione.length(); i++){
            char ch = soluzione[i];
            if(Char[ch]){
                return false;
            }
            Char[ch] = true;
        }
        return true;
    }

    bool verificaNumeri(){                               //!Controlla che i numeri nella soluzione non superino un certo limite (pari al numero di
        for (int i = 0; i < simboli.length()+1; i++) {      //!simboli + 1). Restituisce true se valido, false altrimenti.
            if((soluzione[i] - '0') > simboli.length()+1){
                return false;
            }
        }
        return true;
    }

    bool verificaUguaglianze(){                            //!Verifica che i numeri nella soluzione rispettino le disuguaglianze rappresentate dai simboli
        for(int i = 0; i < simboli.length(); i++){             //!< e >. Restituisce true se tutte le condizioni sono rispettate, false altrimenti.
            if(simboli[i] == '<'){
                if((soluzione[i] - '0') > (soluzione[i+1] - '0')){
                    return false;
                }
            }else{
                if((soluzione[i] - '0') < (soluzione[i+1] - '0')){
                    return false;
                }
            }
        }
        return true;
    }

};

#endif //RISPETTA_I_VERSI_HEADER_HPP
