#include "header.hpp"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream P("Problema.txt"), S("Soluzione.txt");
    ofstream E("Esito.txt");

    if(!E){
        ofstream E("Esito.txt");
        if(!E){
            cerr << "Impossibile aprire ii file 'Problema.txt'"<< endl;     //Con questo if controllo se il file è stato aperto correttamente, se così non fosse notifico a video ed esco dal programma
            return 0;
        }
    }

    if(!S){   //Controllo se uno dei due file non è stato aperto correttamente
        cerr << "Impossibile aprire ii file 'Soluzione.txt'"<< endl;     //Con questo if controllo se il file è stato aperto correttamente, se così non fosse notifico a video ed esco dal programma
        return 0;
    }

    if(!P){
        cerr << "Impossibile aprire ii file 'Problema.txt'"<< endl;     //Con questo if controllo se il file è stato aperto correttamente, se così non fosse notifico a video ed esco dal programma
        return 0;
    }

    int nRigheSol = 0, nRigheProb = 0;
    string tmp;


    while(getline(S, tmp)){
        nRigheSol++;
    }

    while(getline(P, tmp)){
        nRigheProb++;
    }

    if(nRigheProb != nRigheSol){
        E<<"Il file soluzione non e' compatibile con il problema"<<endl;
        return 0;
    }

    int dim = nRigheSol, i = 0;
    rigo A[dim];

    P.clear();
    S.clear();
    E.clear();
    P.seekg(ios::beg);
    S.seekg(ios::beg);
    E.seekp(ios::beg);

    //! -- UNICA COSA DA FARE IMPORTANTE --
    //! Dovremmo fare in modo che questi algoritmi lavorino sugli attributi di classe rigo,
    //! evitando di lavorare sulle variabili utilizzate nel while

    while(dim > 0){
        //codice che va ripetuto per ogni rigo
        string rigoSol, rigoProb, simboli;

        getline(S, rigoSol);
        getline(P, rigoProb);

        simboli = A[i].scomponiSimboli(rigoSol);

        // Ritorna vero se i simboli sono diversi
        if(A[i].confrontaSimboli(rigoProb, simboli)){
            E<<"Sbagliata"<<endl;
        }else{

            if(A[i].controllaDuplicati(rigoSol)){

                if(A[i].verificaNumeri(&rigoProb,rigoSol)) {

                    if(A[i].verificaUguaglianze(rigoProb, rigoSol)){
                        E<<"Corretta"<<endl;
                    }else{
                        E<<"Sbagliata"<<endl;
                    }
                }else {
                    E << "Sbagliata" << endl;
                }
            }else{
                E<<"Sbagliata"<<endl;
            }
        }

        dim--;
        i++;
    }

    S.close();  //alla fine di tutto chiudo tutti i file
    P.close();
    E.close();

    return 0;
}
