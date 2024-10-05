#include "header1.hpp"
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

    string rigoSol, rigoProb, simboli;
    getline(S, rigoSol);
    getline(P, rigoProb);
    esito a(rigoSol, rigoProb);
    simboli = a.scomponiSimboli(rigoSol);
    cout<<simboli<<endl;
    cout<<rigoSol<<endl;
    if(a.confrontaSimboli(&rigoProb, &simboli)){
        cout<<"I simboli non combaciano"<<endl; //invece di questo queto cout deve esserci il modo per scrivere su file
    }else{
        cout<<"I simboli combaciano"<<endl;
        bool prova = a.verificaNumeri(rigoProb,rigoSol);
        if(prova)
            cout<<"vero"<<endl;
        else
            cout<<"falso"<<endl;
    }



    /*Risolutore r;
    r.Risolvi();*/

    return 0;
}
