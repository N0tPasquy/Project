/*
 * Progettare ed implementare un programma che utilizzando una Map, conti il
 * numero di occorrenze di ogni parola contenuta in un file
 */

#include <iostream>
#include <fstream>  //libreria per i file
#include <map>  //libreria per usare le map
using namespace std;

int main() {
    string line;    //stringa di appoggio

    map<string, int> occorrenze;    //map occorrenze

    ifstream input("Input1.txt");   //scegliere il file "Input.txt" per fare la verifica su un testo più grande

    if(!input){
        cerr<<"File non aperto correttamente"<<endl;
        return 0;
    }

    //Il programma è case sensitive
    map<string ,int>::iterator it;
    while (input >> line){   //copio ogni parola divisa da uno spazio all' interno di line
        if (line.back() == ',' || line.back() == '.')     //controlla che alla fine di ogni parola non ci sia un punto o una virgola
            line.pop_back();    //se c'è, esegue pop_back() rimuove l' ultimo elemento in coda, nel nostro caso la virgola o il punto
        it = occorrenze.find(line);     //.find() restituisce l' iteratore
        if(it == occorrenze.end()){
            occorrenze.insert(pair<string, int>(line, 1));
        }else{
            it->second++;   //accedo alla seconda sezione di mappa alla posizione it e incremento quel valore
        }
    }

    input.close();  //chiudo il file aperto in precedenza

    for(auto& a: occorrenze){    //ciclo ranged-for, ripete il ciclo per tutta la dimensione di occorrenze, auto trova in automatico il tipo di variabile da associare ad "a", nel nostro caso sarà di tipo pair
        cout<<a.first<<": "<<a.second<<endl;  //stampa a video sia key (la parola del testo) che il numero di occorrenze
    }   //a.first ritorna il valore key della map, a.second ritorna il numero int salvato in map
        //Viene utilizzato il tipo pair siccome la mappa necessita proprio di due elementi e salviamo ogni record di "map<string, int> occorrenze" in "pair<string, int> a"
        //Per ogni iterazione di ciclo il pair punterà al successivo di map partendo dal primo elemento in ordine alfabetico, perché la key è una stringa e viene gestita con l'ordine lessico-grafico

    return 0;
}
