//
// Created by Pasquale on 17/10/2024.
//
#include "header.hpp"

transizione::transizione(std::string f, std::string t, int q) {
    from = f;
    to = t;
    qt = q;
}

void transizione::setFrom(std::string f) {
    from = f;
}

string transizione::getFrom() {
    return from;
}

void transizione::setTo(std::string t) {
    to = t;
}

string transizione::getTo() {
    return to;
}

void transizione::setQt(int q) {
    qt = q;
}

int transizione::getQt() {
    return qt;
}

blocco::blocco(T* tmp, blocco *next){
    
}