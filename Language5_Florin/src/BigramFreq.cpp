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

std::ostream & operator<<(std::ostream &os, BigramFreq &bigramFreq){
    os << bigramFreq.toString();
    return os;
}

std::istream &operator>>(std::istream &is, BigramFreq &bigramFreq){
    string aux;
    Bigram bigrama;
    int n;
    is >> bigrama;

    is >> n;

    if(n>0){
        bigramFreq.setBigram(bigrama);
        bigramFreq.setFrequency(n);
    }
    else{
        throw out_of_range("La frecuencia del bigrama debe de ser extrictamente mayor que 0");
    }

    return is;
}

bool operator>(BigramFreq &bigramFreq1, BigramFreq &bigramFreq2){
    if (bigramFreq1.getFrequency() > bigramFreq2.getFrequency()){ //Comprueba las frecuencias true si bigram1 es mayor
        return true;
    }
    else if(bigramFreq1.getFrequency() == bigramFreq2.getFrequency()){ //EN el caso de que tengan la misma frecuencia
        if(bigramFreq1.getBigram().toString().compare(bigramFreq2.getBigram().toString()) > 0){ //Si el string del bigram1 es mayor que el bigram2
            return true;
        }
        else{  //Si el string de bigram2 es mayor que el bigram2
            return false;
        }
    }
    else{//Comprueba las frecuencias false si bigram2 es menor
        return false;
    }

}

bool operator<(BigramFreq &bigramFreq1, BigramFreq &bigramFreq2){
    if (bigramFreq1.getFrequency() < bigramFreq2.getFrequency()){ //Comprueba las frecuencias true si bigram2 es mayor
        return true;
    }
    else if(bigramFreq1.getFrequency() == bigramFreq2.getFrequency()){ //EN el caso de que tengan la misma frecuencia
        if(bigramFreq1.getBigram().toString().compare(bigramFreq2.getBigram().toString()) < 0){ //Si el string del bigram1 es menor que el bigram2
            return true;
        }
        else{  //Si el string de bigram1 es mayor que el bigram2
            return false;
        }
    }
    else{//Comprueba las frecuencias false si bigram2 es menor
        return false;
    }
}

bool operator==(BigramFreq &bigramFreq1, BigramFreq &bigramFreq2){
    if(bigramFreq1.getFrequency() == bigramFreq2.getFrequency()){
        if(bigramFreq1.getBigram().toString().compare(bigramFreq2.getBigram().toString()) == 0){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}

bool operator!=(BigramFreq &bigramFreq1, BigramFreq &bigramFreq2){
    if(! (bigramFreq1==bigramFreq2)){
        return true;
    }
    else{
        return false;
    }
}

bool operator<=(BigramFreq &bigramFreq1, BigramFreq &bigramFreq2){
    if( bigramFreq1 < bigramFreq2 or bigramFreq1 == bigramFreq2){
        return true;
    }
    else{
        return false;
    }
}

bool operator>=(BigramFreq &bigramFreq1, BigramFreq &bigramFreq2){
    if( bigramFreq1 > bigramFreq2 or bigramFreq1 == bigramFreq2){
        return true;
    }
    else{
        return false;
    }
}

void BigramFreq::serialize(std::ostream& outputStream) const {
    _bigram.serialize(outputStream);
    outputStream.write(reinterpret_cast<const char*>(&_frequency), sizeof(_frequency));
}

void BigramFreq::deserialize(std::istream& inputStream) {
    _bigram.deserialize(inputStream);
    inputStream.read(reinterpret_cast<char*>(&_frequency), sizeof(_frequency));
}


