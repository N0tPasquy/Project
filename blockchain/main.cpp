#include "header.hpp"

int main() {
    lista<transazione> blockchain;

    blockchain.insert(transazione("Alice", "Bob", 50));
    blockchain.insert(transazione("Bob", "Charlie", 20));
    blockchain.insert(transazione("Charlie", "Alice", 30));

    string indirizzo = "Alice";
    blockchain.stampa(indirizzo);

    return 0;
}
