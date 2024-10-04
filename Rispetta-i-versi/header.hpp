//
// Created by Pasquale on 03/10/2024.
//
//! WARNING -- Clion looks for input files and writes output files to the Debug folder.
//! If you put your input files in there it will see them. --
//
// L’istruzione ofstream sta per output file stream e crea un riferimento a un file su cui scrivere
//
// L’ istruzione ifstream sta per input file stream e crea un riferimento a un file da cui leggere
//
// La classe fstream si utilizza come riferimento generico a un file la cui natura deve essere
//      specificata in fase di apertura
//

#ifndef RISPETTA_I_VERSI_HEADER_HPP
#define RISPETTA_I_VERSI_HEADER_HPP

#include <iostream>
#include <string>   //questa libreria invece lavora sulle stringhe trattandole come classi, quindi in modo più dinamico e in stile C++.

#include <vector>   //libreria per poter usare i vector con le loro function, come .push_back()

#include <fstream>  //libreria importata per poter utilizzare gli oggetti di tipo fstream, ifstream e ofstream. Serve per leggere/scrivere su file
using namespace std;

class Risolutore {
private:
    string Problema = "Problema.txt";
    string Soluzione = "Soluzione.txt";
public:

    void Risolvi() {
        fstream F;                            //ifstream classe che ho importato da <fstream>, F è un oggetto della classe ifstream
        //F.open("Soluzione.txt");             //F è un oggetto di ifstream, quindi apre in input il file "Soluzione.txt"
        F.open(Soluzione, ios::in);

        if (!F) {
            cerr << "Impossibile aprire il file"
                 << endl;     //con questo if controllo se il file è stato aperto correttamente, se così non fosse lo notifico a video ed esco
            exit(0);
        }

        string Rigo;            //dichiaro la stringa in stile C++, la stringa in stile array di char (stile C) e le variabili che ci serviranno
        F.seekg(ios::beg);                  //imposto il puntatore del file all'inizio del file, nel caso l'ultima apertura non lo avesse reimpostato

        while (!F.eof()) {
            vector <string> ch, Numeri, Simboli;

            //--> Procedo a salvare un rigo del file letto in input in una stringa classe stile C++ <--
            getline(F, Rigo);   //con getline() mi salvo la riga del file nella variabile Rigo, nella prima iterazione contiene: 1<4>2<3<5

            //--> controllo carattere per carattere il Rigo, quando trovo un simbolo < o > lo salvo nel vector Simboli,
            // quando invece non è così lo salvo nel vector Numeri <--
            for(int i = 0; i < Rigo.length(); i++){
                if(Rigo[i] == '<' || Rigo[i] == '>'){
                    Simboli.push_back(string(1, Rigo[i]));
                }else /*if(Rigo[i] >= '1' && Rigo[i] <= '9')*/{
                    Numeri.push_back(string(1, Rigo[i]));
                }
            }

            for (int i = 0; i < Numeri.size(); i++) {
                cout<<Numeri[i];
            }
            cout<<endl;
            for (int i = 0; i < Simboli.size(); ++i) {
                cout<<Simboli[i];
            }
            cout<<endl;

            //!-- DA FINIRE --
            //!-- AIUTO NON SO COSA FARE ODIO LE STRINGHE E I VECTOR VAFFANCULO --
            //!-- NON SO NEMMENO SE STAVO ANDANDO BENE, SPERO DI SI --
            //!-- NEL NOME DEL PADRE, DEL FIGLIO E DELLO SPIRITO SANTO --
            //!-- da capire in modo più chiaro cosa bisgona fare in questo ciclo
            //!-- dovrei leggere da file UNA SOLA RIGA ALLA VOLTA, salvare i numeri e
            //! i caratteri nelle rispettive stringhe create apposta, confrontare la stringa
            //! caratteri appena creata con UNA RIGA ALLA VOLTA le righe del file "Problema.txt"
        }

        F.close();  //dopo tutte le operazioni chiudo il file

    }

};
#endif //RISPETTA_I_VERSI_HEADER_HPP
