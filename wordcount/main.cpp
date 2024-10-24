/*
 * Progettare ed implementare un programma che utilizzando una Map, conti il
 * numero di occorrenze di ogni parola contenuta in un file
 */

//!scrivere commenti e ripetere gli argomenti nuovi

#include <iostream>
#include <string>
#include <fstream>
#include <map>
using namespace std;

int main() {
    string line;

    map<string, int> occorrenze;
    map<string, int>::iterator it;

    ifstream input("Input.txt");
    if(!input){
        cerr<<"File non aperto correttamente"<<endl;
        return 0;
    }

    input.seekg(ios::beg);
    while (!input.eof()){
        getline(input, line, ' ');
        while (!line.empty() && (line.back() == ',' || line.back() == '.'))
            line.pop_back();
        occorrenze[line]++;
    }

    input.close();

    for(auto& pair : occorrenze){
        cout<<pair.first<<": "<<pair.second<<endl;
    }

    return 0;
}
