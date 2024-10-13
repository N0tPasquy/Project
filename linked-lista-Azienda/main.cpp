#include "header.hpp"
using namespace std;

int main() {
    cout<<"Lista dei dipendenti: "<<endl;

    lista Azienda;
    //!PROBLEMA - l' impiegato B dovrebbe essere visualizzato come manager, invece viene elaborato come impegato semplice.
    //! RISOLVERE
    impiegato* A = new impiegato("Mario Rossi", 1300);
    impiegato* B = new manager("Michelangelo Naslyednikov", 1600, 100);

    Azienda.insert(A);
    Azienda.insert(B);

    Azienda.stampa();

    float totaleSalari = +Azienda;
    cout<<"Somma di tutti gli stipendi dell' azienda pari a: "<<totaleSalari<<endl;

    return 0;
}
