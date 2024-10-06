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
    rigo a(rigoSol, rigoProb);
    simboli = a.scomponiSimboli(rigoSol);
    cout<<simboli<<endl;
    cout<<rigoSol<<endl;

    //prima di mettere nel while bisogna controllare che i due file abbiano lo stesso numero di righe
    //tutto questo deve essere messo all' interno di un ciclo while che scorre tutte le righe fin quando non finisce, while(S.eof())
    if(a.confrontaSimboli(&rigoProb, &simboli)){
        cout<<"I simboli non combaciano, scrivi su file Sbagliata"<<endl; //invece di questo cout deve esserci il modo per scrivere sul file Esito.txt "Sbagliata"
    }else{
        cout<<"I simboli combaciano, continua"<<endl;
        if(a.controllaDuplicati(rigoSol)){

            if(a.verificaNumeri(&rigoProb,rigoSol)) {
                cout << "I numeri vanno bene, continua" << endl;

                if(a.verificaUguaglianze(rigoProb, rigoSol)){
                    cout<<"Scrivi su file Corretta"<<endl;
                }else{
                    cout<<"Scrivi su file Sbagliata"<<endl;
                }

            }else
                cout<<"I numeri non vanno bene, scrivi su file Sbagliata"<<endl;    //Invece di questo cout deve esserci il modo per scrivere sul file Esito.txt "Sbagliata"

        }else{
            cout<<"Ci sono numeri duplicati, scrivi su file Sbagliata"<<endl;
        }
    }



    /*Risolutore r;
    r.Risolvi();*/

    return 0;
}
