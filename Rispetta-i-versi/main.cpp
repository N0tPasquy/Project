#include "header.hpp"
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

    //nel main devo controllare quante caselle ci sono per ogni rigo


    /*Risolutore r;
    r.Risolvi();*/

    return 0;
}
