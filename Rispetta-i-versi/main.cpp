#include "header.hpp"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    fstream P, S;
    S.open("Soluzione.txt", ios::in);
    P.open("Problema.txt", ios::in);

    if(!S || !P){   //Controllo se uno dei due file non è stato aperto correttamente
        cerr << "Impossibile aprire il file"
             << endl;     //Con questo if controllo se il file è stato aperto correttamente, se così non fosse notifico a video ed esco dal programma
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
        cout<<"Il file soluzione non e' compatibile con il problema"<<endl;
        return 0;
    }

    int dim = nRigheSol, i = 0;
    rigo A[dim];

    P.clear();
    S.clear();
    P.seekg(ios::beg);
    S.seekg(ios::beg);

    while(nRigheSol > 0){
        cout<<"Rigo "<<i+1<<endl;
        //codice che va ripetuto per ogni istanza
        string rigoSol, rigoProb, simboli;

        getline(S, rigoSol);
        getline(P, rigoProb);

        simboli = A[i].scomponiSimboli(rigoSol);

        if(A[i].confrontaSimboli(&rigoProb, &simboli)){
            cout<<"I simboli non combaciano, scrivi su file Sbagliata"<<endl; //invece di questo cout deve esserci il modo per scrivere sul file Esito.txt "Sbagliata"
        }else{
            cout<<"I simboli combaciano, continua"<<endl;
            if(A[i].controllaDuplicati(rigoSol)){

                if(A[i].verificaNumeri(&rigoProb,rigoSol)) {
                    cout << "I numeri vanno bene, continua" << endl;

                    if(A[i].verificaUguaglianze(rigoProb, rigoSol)){
                        cout<<"Scrivi su file Corretta"<<endl;
                    }else{
                        cout<<"Le uguaglianze non sono verificate, scrivi su file Sbagliata"<<endl;
                    }

                }else
                    cout<<"I numeri non vanno bene, scrivi su file Sbagliata"<<endl;    //Invece di questo cout deve esserci il modo per scrivere sul file Esito.txt "Sbagliata"

            }else{
                cout<<"Ci sono numeri duplicati, scrivi su file Sbagliata"<<endl;
            }
        }

        nRigheSol--;
        i++;
    }

    S.close();  //alla fine di tutto chiudo entrambi i file
    P.close();

    return 0;
}
