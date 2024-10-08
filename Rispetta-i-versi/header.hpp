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

    //! Provare a rendere questo metodo void e farlo lavorare con attributi della classe rigo
    void scomponiSimboli(){    //metodo per dividere i numeri dai simboli < e >
        for (int i = 0; i < soluzione.length(); i++) {    //ciclo for per scorrere tutto il rigo attuale di soluzione
            if(soluzione[i] == '<' || soluzione[i] == '>'){ //controllo l' i-esimo carattere di soluzione
                simboli += soluzione[i];      //se in posizione [i] di "sol" trovo uno tra i simboli < e > lo salvo nella stringa "simboli"
                soluzione.erase(i, 1);    //una volta salvato il simbolo, lo elimino dalla stringa di partenza
            }                              //così facendo alla fine del ciclo nella stringa "sol" (che sarebbe il rigo di Soluzione.txt)
        }                                  //troveremo solamente numeri
    }                   // mentre peri numeri lavoro direttamente sulla stringa originale tramite riferimento

    bool confrontaSimboli(){   //metodo dove vengono confrontati i simboli trovati in precedenza con i simboli di "Problema.txt", prendo in input i puntatori alle stringhe
        if(problema.length() != simboli.length())     //verifico che entrambi i righi abbiano la stessa lunghezza
            return true;   // se così non fosse significa che non è soluzione, quindi ritorno vero

        for(int i = 0; i <= problema.length(); i++){    //ciclo che scorre il rigo di problema
            if(problema[i] != simboli[i]){  //se l' i-esimo simbolo di "prob" e l' i-esimo simbolo di "simboli" sono
                return true;           //diversi significa che non è soluzione, quindi ritorno vero
            }
        }
        return false; //nel caso sia tutto uguale ritorno false
    }

    bool controllaDuplicati(){
        bool Char[256] = {false};   // Crea un array di booleani di dimensione 256 per tenere traccia dei caratteri

        for(int i = 0; i < soluzione.length(); i++){  //ciclo che mi scorre tutto il rigo
            char ch = soluzione[i];   //salvo l' i-esimo carattere di num in una variabile di appoggio
            if(Char[ch]){   //se nell' array di bool in posizione ch c'è un valore diverso da false, significa che il numero che stiamo verificando già è stato trovato in precedenza
                return false;   //quindi ritorno false
            }
            Char[ch] = true;    //se non è già stato trovato cambio da false a true, così facendo nei successivi controlli nel caso di un duplicato la condizione sopra sarà vera, quindi c'è un duplicato
        }
        return true;    //se non ci sono duplicati ritorno vero
    }

    bool verificaNumeri(){  //metodo per controllare che in ogni rigo ci siano N numeri quante sono le "caselle" di Soluzione.txt
        for (int i = 0; i < simboli.length()+1; i++) { //le caselle sono sempre il numero dei simboli + 1, quindi itero il ciclo tante volte quante sono le caselle
            if((soluzione[i] - '0') > simboli.length()+1){   //Con num[i] - '0' viene eseguita la sottrazione ASCII tra l' i-esimo num e 0, questo permette la conversione da string a int,
                return false;                       // dopo la conversione verifico se il numero appena trovato è piu grande del numero massimo consentito
            }                                       // se così fosse significa che non è soluzione, quindi ritorno falso
        }
        return true;    //nel caso in cui tutti i numeri non superano N (dove N è il numero di caselle) ritorno vero
    }

    bool verificaUguaglianze(){
        for(int i = 0; i < simboli.length(); i++){     //ciclo che scorre lungo tutto il rigo
            if(simboli[i] == '<'){ //siccome < e > all' interno della stringa sono char all' i-esima iterazione del ciclo ho bisogno di verificare quale dei dure utilizzare per fare il confronto
                if((soluzione[i] - '0') > (soluzione[i+1] - '0')){  //se mi trovo nel caso num[1] < num[i+1] devo verificare che sia vero, per questione di comodità, controllo invece l'operazione inversa.
                    return false;   //controllando l' inverso ritorno falso alla prima occasione buona, senza dover continuare a fare altri confronti inutili
                }
            }else{  //si il simbolo non è '<' sarà per forza '>'
                if((soluzione[i] - '0') < (soluzione[i+1] - '0')){  //stesso discorso per quest' altro caso
                    return false;
                }
            }
        }
        return true;    //se tutte le uguaglianze sono verificare ritorno vero
    }

};

#endif //RISPETTA_I_VERSI_HEADER_HPP
