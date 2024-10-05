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

#include <fstream>  //Libreria importata per poter utilizzare gli oggetti di tipo fstream, ifstream e ofstream. Serve per leggere/scrivere su file
using namespace std;

class Risolutore {
private:
    string Problema = "Problema.txt";
    string Soluzione = "Soluzione.txt";
public:

    //!-- NUOVO HEADER CREATO, SPIEGAZIONE LÌ

    void Risolvi() {
        fstream S;                            //ifstream classe che ho importato da <fstream>, F è un oggetto della classe ifstream
        fstream P;
        //S.open("Soluzione.txt");             //F è un oggetto di ifstream, quindi apre in input il file "Soluzione.txt"
        S.open(Soluzione, ios::in);
        P.open(Problema, ios::in);

        if (!S) {
            cerr << "Impossibile aprire il file"
                 << endl;     //con questo if controllo se il file è stato aperto correttamente, se così non fosse notifico a video ed esco dal programma
            exit(0);
        }

        if(!P){
            cerr << "Impossibile aprire il file"
                 << endl;     //Stessa cosa per il file "Problema"
            exit(0);
        }

        string RigoSol, RigoProb;            //dichiaro la stringa in stile C++ e le variabili che ci serviranno
        S.seekg(ios::beg);      //imposto il puntatore del file all'inizio del file, nel caso l'ultima apertura non lo avesse reimpostato
        P.seekg(ios::beg);

        //!-- NUOVO HEADER CREATO, SPIEGAZIONE LÌ

        while (!S.eof()) {
            vector <string> Soluz, Simboli;
            vector <int> Numeri;
            int N = 0;

            //--> Procedo a salvare un rigo del file letto in input in una stringa classe stile C++ <--
            getline(S, RigoSol);   //con getline() mi salvo la riga del file nella variabile Rigo, nella prima iterazione contiene: 1<4>2<3<5

            //--> controllo carattere per carattere il Rigo, quando trovo un simbolo < o > lo salvo nel vector Simboli,
            // quando invece non è così lo salvo nel vector Numeri <--
            for(int i = 0; i < RigoSol.length(); i++){     //Ciclo che scorre tutto il rigo soluzione
                if(RigoSol[i] == '<' || RigoSol[i] == '>'){   //If che controlla l' i-esimo carattere del Rigo
                    Simboli.push_back(string(1, RigoSol[i]));  //Se siamo il carattere controllato è un '<' o '>' lo inserisce nel vector dei Simboli
                    N++;    //Contatore per verificare da quante caselle è formato il RigoSol che stiamo scorrendo
                }/*else if(RigoSol[i] >= '0' && RigoSol[i] <= '9'){
                    Numeri.push_back(RigoSol[i]);   //Altrimenti lo inserisce nel vector "Numeri" contenente solamente int
                }*/
            }

            //!-- NUOVO HEADER CREATO, SPIEGAZIONE LÌ

            getline(P, RigoProb); //Questo getline() salva l' i-esimo rigo del file "Problema" nella stringa rSoluz

            for(int i = 0; i < RigoProb.length(); i++){   //ciclo che scorre tutto il rigo del problema
                Soluz.push_back(string(1, RigoProb[i]));
                if(Soluz[i] != Simboli[i]){

                }
            }
            if(Soluz == Simboli){      //prima di fare questo devo trasformare rSoluz in un vector per poter fare il confronto

            }

            //Dopo questo ciclo ho due vector popolati, uno con solo numeri e un altro con solo simboli.
            //Dobbiamo confrontare se i simboli di vector Simboli corrispondono ai simboli dell' i-esimo rigo del file


            //!-- DA FINIRE --
            //!-- AIUTO NON SO COSA FARE ODIO LE STRINGHE E I VECTOR VAFFANCULO --
            //!-- NON SO NEMMENO SE STAVO ANDANDO BENE, SPERO DI SI --
            //!-- NEL NOME DEL PADRE, DEL FIGLIO E DELLO SPIRITO SANTO --
            //!-- Bravo Pasquà! continua così 
            //!-- da capire in modo più chiaro cosa bisogna fare in questo ciclo
            //!-- dovrei leggere da file UNA SOLA RIGA ALLA VOLTA, salvare i numeri e
            //!-- i caratteri nelle rispettive stringhe create apposta, confrontare la stringa
            //!-- caratteri appena creata con UNA RIGA ALLA VOLTA le righe del file "Problema.txt"
        }

        //!-- NUOVO HEADER CREATO, SPIEGAZIONE LÌ

        S.close();  //dopo tutte le operazioni chiudo il file

    }

};
#endif //RISPETTA_I_VERSI_HEADER_HPP
