#include "header.hpp"

int main() {
    cout<<"Lista dei dipendenti: "<<endl;

    lista Azienda;

    impiegato* A = new impiegato("Mario Rossi", 1300);
    impiegato* B = new manager("Michelangelo Naslyednikov", 1600, 100);

    Azienda.insert(A);
    Azienda.insert(B);

    Azienda.stampa();

    float totaleSalari = +Azienda;
    cout<<"Somma di tutti gli stipendi dell' azienda pari a: "<<totaleSalari<<endl;

    return 0;
}
