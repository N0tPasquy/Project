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
#include <string>
#include <fstream>
using namespace std;

class Risolutore {
private:
    string Problema = "Problema.txt";
    string Soluzione = "Soluzione.txt";
public:

    void Risolvi() {
        fstream F;                            //ifstream classe che ho importato da <fstream>, F è un oggetto della classe ifstream
        F.open("Soluzione.txt");             //F è un oggetto di ifstream, quindi apre in input il file "Soluzione.txt"
        //F.open(Soluzione.c_str(), ios::in);             // .c_str() estrae la stringa di caratteri in stile C

        if (!F) {
            cerr << "Impossibile aprire il file"
                 << endl;     //con questo if controllo se il file è stato aperto correttamente, se così non fosse lo notifico a video ed esco
            exit(0);
        }

        F.seekg(ios::beg);                  //imposto il puntatore del file all'inizio del file, nel caso l'ultima apertura non lo avesse reimpostato

        string Numeri, Simboli, Rigo;       //dichiaro le stringhe e le variabili di appoggio
        getline(F, Rigo);
        //F.seekg(ios::beg);

        while (!F.eof()) {
            int Lunghezza = Rigo.size()+1;
            char ch[Lunghezza];
            F.get(ch, Lunghezza);

            cout<<ch<<endl;

            getline(F, Rigo);

            //!-- DA FINIRE --
            //!-- AIUTO NON SO COSA FARE ODIO LE STRINGHE VAFFANCULO --
            //!-- NON SO NEMMENO SE STAVO ANDANDO BENE, SPERO DI SI --coglione
            //!-- NEL NOME DEL PADRE, DEL FIGLIO E DELLO SPIRITO SANTO --
            //!-- da capire in modo più chiaro cosa bisgona fare in questo ciclo
            //!-- dovrei leggere da file UNA SOLA RIGA ALLA VOLTA, salvare i numeri e i caratteri nelle rispettive stringhe create apposta, confrontare la stringa caratteri appena creata con UNA RIGA ALLA VOLTA le righe del file "Problema.txt"
            //cout << Rigo << endl;
            //quando il codice viene eseguito, riusciamo a leggere da file, ora bisogna capire come fare per separare i caratteri '<' e '>'
            //dai numeri per ogni riga. Qui mi arrendo per ora
        }

        F.close();                             //dopo tutte le operazioni chido il file

    }

};
#endif //RISPETTA_I_VERSI_HEADER_HPP
