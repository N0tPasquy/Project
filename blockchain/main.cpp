#include "header.hpp"

int main() {
    /*lista<transazione> blockchain;

    blockchain.insertAtTail(transazione("Alice", "Bob", 50));
    blockchain.insertAtTail(transazione("Bob", "Charlie", 20));
    blockchain.insertAtTail(transazione("Charlie", "Alice", 30));

    string indirizzo = "Alice";
    blockchain.stampa(indirizzo);*/

    blockChain blockChain;
    blocco blocco1;
    blocco blocco2;
    blocco blocco3;

    blocco1.getListaTransizioni()->insertAtTail(transazione("Alice", "Bob", 50));
    blocco1.getListaTransizioni()->insertAtTail(transazione("Bob", "Charlie", 20));
    blocco1.getListaTransizioni()->insertAtTail(transazione("Charlie", "Alice", 30));

    blocco2.getListaTransizioni()->insertAtTail(transazione("Bob", "Alice", 35));
    blocco2.getListaTransizioni()->insertAtTail(transazione("Alice", "Charlie", 5));

    blocco3.getListaTransizioni()->insertAtTail(transazione("Alice", "Bob", 2));

    blockChain.getListaBlockChain()->insertAtTail(blocco1);
    blockChain.getListaBlockChain()->insertAtTail(blocco2);
    blockChain.getListaBlockChain()->insertAtTail(blocco3);

    //! Da rivedere il metodo per stampare
    blockChain.getListaBlockChain()->stampa("Alice");

    return 0;
}
