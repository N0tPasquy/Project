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

                    //con questa libreria possiamo lavorare sulle stringhe come se fossero array di char, come si fa in C,
#include <cstring>  //si utilizza per le sue funzioni più importanti come: strcpy(), strcmp(). La prima fa la copia di una stringa in un altra,
                    //la seconda confronta due stringhe

#include <fstream>  //libreria importata per poter utilizzare gli oggetti di tipo fstream, ifstream e ofstream. Serve per leggere/scrivere su file
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

        //TUTTA QUESTA PARTE, FINO ALLA RIGA 50, NON È NECESSARIA. VIENE USATA SOLO PER FARE DELLE PROVE DI DEBUG
        string Rigo;            //dichiaro la stringa in stile C++ e le variabili che ci serviranno
        getline(F, Rigo);
        F.seekg(ios::beg);                  //imposto il puntatore del file all'inizio del file, nel caso l'ultima apertura non lo avesse reimpostato
        int Lunghezza = Rigo.size()+1;
        char ch[Lunghezza];

        while (!F.eof()) {
            //--> Procedo a salvare un rigo del file letto in input in una stringa classe stile C++
            getline(F, Rigo);   //con getline() mi salvo la riga del file nella variabile Rigo, nella prima iterazione contiene: 1<4>2<3<5

            //--> adesso bisogna convertire string Rigo in un array di caratteri
            strcpy(ch, Rigo.c_str());   //bisogna includere la libreria <cstring> per usare questa function. Non fa altro che copiare una stringa dentro un altra stringa.
                                                    // In input accetta solo array di char, per questo la stringa "Rigo" utilizzo il metodo .c_str(), non fa altro che convertire
                                                    // da tipo classe a tipo array di char

            //--> Una volta copiata la stringa C++ Rigo nell' array di char C ch, possiamo procedere a separare i numeri dai simboli '<' e '>'

            /*Lunghezza = Rigo.size()+1;
            for (int i = 0; i < Lunghezza; i++) {
                    cout<<ch[i];
            }
            cout<<endl;*/

            //!-- DA FINIRE --
            //!-- AIUTO NON SO COSA FARE ODIO LE STRINGHE VAFFANCULO --
            //!-- NON SO NEMMENO SE STAVO ANDANDO BENE, SPERO DI SI --
            //!-- NEL NOME DEL PADRE, DEL FIGLIO E DELLO SPIRITO SANTO --
            //!-- da capire in modo più chiaro cosa bisgona fare in questo ciclo
            //!-- dovrei leggere da file UNA SOLA RIGA ALLA VOLTA, salvare i numeri e
            //! i caratteri nelle rispettive stringhe create apposta, confrontare la stringa
            //! caratteri appena creata con UNA RIGA ALLA VOLTA le righe del file "Problema.txt"
        }

        F.close();                             //dopo tutte le operazioni chido il file

    }

};
#endif //RISPETTA_I_VERSI_HEADER_HPP
