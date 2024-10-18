#include "header.hpp"

int main() {
    lista<transazione> blockchain;

    blockchain.insertAtTail(transazione("Alice", "Bob", 50));
    blockchain.insertAtTail(transazione("Bob", "Charlie", 20));
    blockchain.insertAtTail(transazione("Charlie", "Alice", 30));

    string indirizzo = "Alice";
    blockchain.stampa(indirizzo);

    return 0;
}
