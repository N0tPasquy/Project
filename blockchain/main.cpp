#include "header.hpp"

int main() {
    // Creiamo alcune transazioni
    transizione t1("Alice", "Bob", 100);
    transizione t2("Bob", "Charlie", 50);
    transizione t3("Charlie", "Alice", 30);

    // Creiamo una lista di transazioni
    list<transizione> listaTransazioni;

    // Inseriamo le transazioni nella lista
    listaTransazioni.insert(t1);
    listaTransazioni.insert(t2);
    listaTransazioni.insert(t3);

    nodo<transizione>* current = listaTransazioni.getHead(); // Aggiungiamo getHead
    while (current != nullptr) {
        transizione trans = current->getDato();
        cout << "Transazione da: " << trans.getFrom()
             << " a: " << trans.getTo()
             << " per un importo di: " << trans.getQt() << endl;
        current = current->getNext();
    }

    return 0;
}
