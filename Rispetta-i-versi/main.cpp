#include "header.hpp"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream P("Problema.txt"), S("Soluzione.txt"); //apro in input i due file da leggere
    ofstream E("Esito.txt");    //apro in output il file su cui bisogna scrivere l' esito

    if(!E){ //controllo che ogni file venga aperto in modo corretto
            cerr << "Impossibile aprire ii file 'Problema.txt'"<< endl;     //Con questo if controllo se il file è stato aperto correttamente, se così non fosse notifico a video ed esco dal programma
            return 0;
    }

    if(!S){
        cerr << "Impossibile aprire ii file 'Soluzione.txt'"<< endl;     //Con questo if controllo se il file è stato aperto correttamente, se così non fosse notifico a video ed esco dal programma
        return 0;
    }

    if(!P){
        cerr << "Impossibile aprire ii file 'Problema.txt'"<< endl;     //Con questo if controllo se il file è stato aperto correttamente, se così non fosse notifico a video ed esco dal programma
        return 0;
    }

    int nRigheSol = 0, nRigheProb = 0;  //variabili di conteggio dei righi di ogni file
    string tmp;


    while(getline(S, tmp)){
        nRigheSol++;    //conto il numero di righi nel file soluzione
    }

    while(getline(P, tmp)){
        nRigheProb++;   //conto il numero di righi nel file problema
    }

    if(nRigheProb != nRigheSol){
        E<<"Il file soluzione non e' compatibile con il problema"<<endl;    //se non dovessero avere lo stesso numero di righi non posso continuare con lo svolgimento
        return 0;
    }

    int dim = nRigheSol, i = 0; //contatori interi per il ciclo while
    rigo A[nRigheSol];  //creo l' array di oggetti di tipo rigo, per ogni posizione dell' array corrisponde un rigo del problema e un rigo della soluzione

    //metodi che reimpostano il puntatore del file all'inizio
    P.clear();
    S.clear();
    E.clear();
    P.seekg(ios::beg);
    S.seekg(ios::beg);
    E.seekp(ios::beg);

    while(dim > 0){ //il ciclo viene ripetuto "dim" volte, dove dim è il numero di righi dei file
        //codice che va ripetuto per ogni rigo
        string rigoSol, rigoProb, simboli;

        getline(S, rigoSol);
        getline(P, rigoProb);

        A[i].setSoluzione(rigoSol);
        A[i].setProblema(rigoProb);
        A[i].scomponiSimboli();

        if(A[i].confrontaSimboli()){    // Ritorna vero se i simboli sono diversi
            E<<"Sbagliata"<<endl;
        }else{

            if(A[i].controllaDuplicati()){  // Ritorna vero se non ci sono duplicati

                if(A[i].verificaNumeri()) { // Ritorna vero se i numeri all' interno di soluzione soddisfano la traccia

                    if(A[i].verificaUguaglianze()){ //Ritorna vero se tutte le uguaglianze di soluzione sono verificate
                        E<<"Corretta"<<endl;
                    }else{
                        E<<"Sbagliata"<<endl;
                    }
                }else {
                    E<<"Sbagliata"<< endl;
                }
            }else{
                E<<"Sbagliata"<<endl;
            }
        }
        dim--;
        i++;
    }

    S.close();  //alla fine del ciclo while chiudo tutti i file aperti in precedenza
    P.close();
    E.close();

    return 0;
}
