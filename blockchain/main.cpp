#include "header.hpp"

int main() {
    blockChain blockChain;
    blocco blocco1;
    blocco blocco2;
    blocco blocco3;

    transazione t1("Alice", "Bob", 50);
    transazione t2("Bob", "Charlie", 20);
    transazione t3("Charlie", "Alice", 30);
    transazione t4("Bob", "Alice", 35);
    transazione t5("Alice", "Charlie", 5);
    transazione t6("Alice", "Bob", 2);

    blocco1.aggiungiTransazione(t1);
    blocco1.aggiungiTransazione(t2);
    blocco1.aggiungiTransazione(t3);
    blockChain.aggiungiBlocco(blocco1);

    blocco2.aggiungiTransazione(t4);
    blocco2.aggiungiTransazione(t5);
    blockChain.aggiungiBlocco(blocco2);

    blocco3.aggiungiTransazione(t6);
    blockChain.aggiungiBlocco(blocco3);

    if(blockChain.exist("Alice"))
        blockChain.stampaTransizioni("Alice");
    else
        cout<<"Non esiste nessuno con quell' indirizzo!"<<endl;

    return 0;
}
