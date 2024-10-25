#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <thread>
#include <mutex>
using namespace std;

void verifica(const vector<int>& corr, mutex& mux, string& nomeFile);

int main() {
    vector<int> corretto = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,0};
    mutex mux;

    string nomeFiles[] = {"input1.txt", "input2.txt"};

    thread th[2];

    for(int i = 0; i < 2; i++){
        th[i] = thread(verifica, ref(corretto), ref(mux), ref(nomeFiles[i]));
    }

    for(int i = 0; i < 2; ++i) {
        th[i].join();
    }

    return 0;
}

void verifica(const vector<int>& corr, mutex& mux, string& nomeFile){
    vector<int> soluzione;
    string line;

    mux.lock();
    ifstream tabella(nomeFile);
    if(!tabella){
        cerr<<"File non aperto correttamente"<<endl;
        exit(0);
    }

    while (getline(tabella, line)){
        istringstream iss(line);
        int num;
        while (iss >> num) {    //ogni numero letto nella stringa lo inserisco nella variabile num
            soluzione.push_back(num);
        }   //dopo 4 iterazioni (nel nostro caso) il while diventa falso perché non ci sono più elementi in iss
    }

    tabella.close();
    mux.unlock();

    mux.lock();
    for(auto& a :soluzione){
        cout<<a<<" ";
    }
    cout<<endl;

    if(soluzione == corr){
        cout<<"corretto"<<endl;
    }else{
        cout<<"sbagliato"<<endl;
    }
    mux.unlock();
}