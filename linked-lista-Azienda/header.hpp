//
// Created by Pasquale on 12/10/2024.
//

#ifndef LINKED_LISTA_AZIENDA_HEADER_HPP
#define LINKED_LISTA_AZIENDA_HEADER_HPP

#include <string>

using namespace std;


class impiegato{
private:
    string nome;
    float salario;
public:
    impiegato(){
        nome = "";
        salario = 0;
    }

    void setNome(string n){
        nome = n;
    }

    void setSalario(float s){
        salario = s;
    }

    string getNome(){
        return nome;
    }

    float getSalario(){
        return salario;
    }
};

class manager : public impiegato{
private:
    float bonus;
public:
    manager() : impiegato(){
        bonus = 0;
    }

    void setBonus(float b){
        bonus = b;
    }

    float getBonus(){
        return bonus;
    }
};

class azienda{
private:
    //! Creare una lista di impiegati e stamparla a video sfruttando il principio del polimorfismo
    //! Implementare l' overload dell'operatore + in modo da sommare i salari di tutti gli impiegati.
    impiegato a;
    azienda* next{};
public:
    azienda(){

        next = nullptr;
    };
};

#endif //LINKED_LISTA_AZIENDA_HEADER_HPP
