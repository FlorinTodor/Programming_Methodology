//
// Created by flo on 25/03/23.
//

#include "../include/BigramFreq.h"
#include "../include/Bigram.h"
#include <string>
using namespace std;

/**
 * @author Florin Emanuel Todor
 */

BigramFreq::BigramFreq() {
    Bigram aux="__";
    _bigram = aux;
    _frequency = 0;
}
 const Bigram & BigramFreq::getBigram()const {
   return _bigram;
}

 int BigramFreq::getFrequency()const {
    return _frequency;
}

void BigramFreq::setBigram(Bigram bigram) {
    _bigram = bigram;
}

void BigramFreq::setFrequency(int frequency) {
    _frequency = frequency;
}

std::string BigramFreq::toString() const {
    string aux;
    aux.push_back(_bigram.toString()[0]);
    aux.push_back(_bigram.toString()[1]);
    aux.push_back(' ');
    string numero = to_string(_frequency);
    aux+=numero;
    return aux;

}