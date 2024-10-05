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

    //!-- Il codice di seguito funziona solamente per il primo rigo, bisogna fare un ciclo while
    //! con condizione "fin quando non si arriva alla fine dei file", cioè while(S.eof() && P.eof())
    //! e all' interno del while ripetere il codice che segue, va bene anche se viene copiato e incollato
    //! dovrebbe andare lo stesso siccome non andiamo mai a modificare il seekg() di entrambi i file,
    //! ma viene aggiornato solamente quando leggiamo le varie righe all' inizio del codice

    string rigoSol, rigoProb, simboli;
    getline(S, rigoSol);
    getline(P, rigoProb);
    esito a(rigoSol, rigoProb);
    simboli = a.scomponiSimboli(rigoSol);
    cout<<simboli<<endl;
    cout<<rigoSol<<endl;
    if(a.confrontaSimboli(&rigoProb, &simboli)){
        cout<<"I simboli non combaciano"<<endl; //invece di questo queto cout deve esserci il modo per scrivere sul file Esito.txt "Sbagliata"
    }else{
        cout<<"I simboli combaciano"<<endl;
        if(a.verificaNumeri(rigoProb,rigoSol))
            cout<<"vero"<<endl; //! Arrivati a questo punto: abbiamo verificato che i simboli combacino,
                                //! abbiamo verificato che i numeri siano giusti, dobbiamo continuare e fare tutti i confronti tra i numeri
                                //! consiglio di fare prima questo metodo e solo una volta finito di continuare con la scrittura sul
                                //! file "Esito.txt", bisogna verificare se esiste già e poi aggiungere in "APPEND" l' esito.
                                //! Se il file "Esito.txt" non esiste nel primo caso, bisogna crearlo
        else
            cout<<"falso"<<endl;    //Invevece di questo cout deve esserci il modo per scrivere sul file Esito.txt "Sbagliata"
    }



    /*Risolutore r;
    r.Risolvi();*/

    return 0;
}
