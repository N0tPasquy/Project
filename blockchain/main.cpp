#include "header.hpp"

//Semplice main dove creo delle transazioni e le inserisco all' interno della lista blocchi
//Aggiungo poi i blocchi all' interno della lista blockChain
//! TO DO - Fare in modo che invece di scrivere a video e leggere in input, il programma legga da file le transazioni e scriva su file i risultati della ricerca
int main() {
    blockChain blockChain;
    blocco blocco1;
    blocco blocco2;
    blocco blocco3;

    transazione t1("Mario", "Bob", 50);
    transazione t2("Bob", "Luigi", 20);
    transazione t3("Luigi", "Mario", 30);
    transazione t4("Bob", "Mario", 35);
    transazione t5("Mario", "Luigi", 5);
    transazione t6("Mario", "Bob", 2);

    blocco1.aggiungiTransazione(t1);
    blocco1.aggiungiTransazione(t2);
    blocco1.aggiungiTransazione(t3);
    blockChain.aggiungiBlocco(blocco1);

    blocco2.aggiungiTransazione(t4);
    blocco2.aggiungiTransazione(t5);
    blockChain.aggiungiBlocco(blocco2);

    blocco3.aggiungiTransazione(t6);
    blockChain.aggiungiBlocco(blocco3);

    //Controllo che l' indirizzo che voglio cercare esista all' interno della blockChain
    if(blockChain.exist("Mario"))
        blockChain.stampaTransizioni("Mario");
    else
        cout<<"Non esiste nessuno con quell' indirizzo!"<<endl;

    return 0;
}
