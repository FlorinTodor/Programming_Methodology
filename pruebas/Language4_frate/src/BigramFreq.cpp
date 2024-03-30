
/*
 * Metodología de la Programación: Language1
 * Curso 2022/2023
 */

#include "BigramFreq.h"
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

BigramFreq::BigramFreq() {
    _bigram = "__";
    _frequency = 0;
}

Bigram BigramFreq::getBigram() const{
    return _bigram;
}

int BigramFreq::getFrequency() const {
    return _frequency;
}

void BigramFreq::setBigram(Bigram bigram) {
    _bigram = bigram;
}

void BigramFreq::setFrequency(int frequency) {
    if(frequency < 0) {
        throw out_of_range("Frequency se encuentra fuera del rango\n");
    }
    else {
        _frequency = frequency;
    }
}

std::string BigramFreq::toString() const{
    string bigrama = _bigram.toString() + ' ' + to_string(_frequency);
    return bigrama;
}