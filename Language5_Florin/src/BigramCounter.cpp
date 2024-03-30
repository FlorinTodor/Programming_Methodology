/*
 * Metodología de la Programación: Language5
 * Curso 2022/2023
 */

/** 
 * @file BigramCounter.cpp
 * @author Silvia Acid Carrillo <acid@decsai.ugr.es>
 * @author Andrés Cano Utrera <acu@decsai.ugr.es>
 * @author Luis Castillo Vidal <L.Castillo@decsai.ugr.es>
 * 
 * Created on 12 February 2023, 11:00
 */

#include <iostream>
#include "../include/Language.h"
#include "../include/Bigram.h"
#include "../include/BigramCounter.h"
#include "../include/BigramFreq.h"
#include <string>
#include <fstream>
using namespace  std;

/**
 * DEFAULT_VALID_CHARACTERS is a c-string that contains the set of characters
 * that will be considered as part of a word (valid chars). 
 * The characters not in the c-string will be considered as separator of words.
 * The constructor of the class BigramCounter uses this c-string as a 
 * default parameter. It is possible to use a different c-string if that
 * constructor is used with a different c-string
 */
const char* const BigramCounter::DEFAULT_VALID_CHARACTERS="abcdefghijklmnopqrstuvwxyz\xE0\xE1\xE2\xE3\xE4\xE5\xE6\xE7\xE8\xE9\xEA\xEB\xEC\xED\xEE\xEF\xF0\xF1\xF2\xF3\xF4\xF5\xF6\xF8\xF9\xFA\xFB\xFC\xFD\xFE\xFF";

/**
 * @author Florin Emanuel Todor
 */

BigramCounter::BigramCounter(std::string validChars) {
    _validCharacters = validChars;
    int n; //Al tratarse de una matriz cuadrada no hay ningún problema
    n= getSize();
    allocate(n);
    for(int k=0; k < n; ++k){
        for(int l=0; l< n; ++l){
            _frequency[k][l] = 0;
        }
    }

}

int BigramCounter::getSize() const {
    return _validCharacters.size();
}
void BigramCounter::deallocate() {
    for(int i=0; i<this->getSize(); ++i){
        delete[] _frequency[i];
    }
    delete[] _frequency;
    _frequency = nullptr;
}

void BigramCounter::allocate(int i) {
    _frequency = new int *[i];
    for(int j=0; j< i; ++j){
        _frequency[j] = new int [i];
    }
}

BigramCounter &BigramCounter::operator=(const BigramCounter &orig) {
    if( this == &orig){ return *this;}
    else{
        deallocate();
        _validCharacters = orig._validCharacters;
        allocate(_validCharacters.size());
        for(int i=0; i< getSize(); ++i){
            for(int j=0; j< getSize(); ++j){
                _frequency[i][j] = orig(i,j);
            }
        }
    }
}

BigramCounter::BigramCounter(const BigramCounter &orig) {
    *this = orig;
}

BigramCounter::~BigramCounter() {
    this->_validCharacters ="";
    deallocate();
}

int BigramCounter::getNumberActiveBigrams() const {
    int numbers=0;
    int tamanio = getSize();
    for(int i=0; i< tamanio; ++i){
        for(int j=0; j< tamanio; j++){
            if ( _frequency[i][j] > 0){ numbers++;}
        }
    }
    return  numbers;
 }

bool BigramCounter::setFrequency(Bigram &bigram, int frequency) {
    if (bigram.toString().size() != 2){
        throw std::invalid_argument("bigram is not valid");
    }
    string aux = bigram.toString();
    int posicion_1 = isValidCharacter(aux[0],_validCharacters);
    int posicion_2 = isValidCharacter(aux[2],_validCharacters);
    if(posicion_1 != -1 and posicion_2 != -1){
        _frequency[posicion_1][posicion_2] = frequency;
        return true;
    }
    else{
        return false;

    }

}

void BigramCounter::increaseFrequency(Bigram &bigram, int frequency) {
    if (bigram.toString().size() != 2){
        throw std::invalid_argument("bigram is not valid");
    }
    if(frequency == 0){
        string aux = bigram.toString();
        int posicion_1 = isValidCharacter(aux[0],_validCharacters);
        int posicion_2 = isValidCharacter(aux[2],_validCharacters);
        if(posicion_1 != -1 and posicion_2 != -1){
            _frequency[posicion_1][posicion_2] +=  1;
        }
        else{
            throw std::invalid_argument("No se encuentra caracteres válidos");
        }

    }
    else{
        string aux = bigram.toString();
        int posicion_1 = isValidCharacter(aux[0],_validCharacters);
        int posicion_2 = isValidCharacter(aux[2],_validCharacters);
        if(posicion_1 != -1 and posicion_2 != -1){
            _frequency[posicion_1][posicion_2] += frequency;
        }
        else{
            throw std::invalid_argument("No se encuentra caracteres válidos");
        }

    }
}

BigramCounter &BigramCounter::operator+=(const BigramCounter &rhs) {

    if(this->getSize() == rhs.getSize() && this->_validCharacters == rhs._validCharacters){
        for(int i=0; i< rhs.getSize(); ++i){
            for(int j=0; j< rhs.getSize(); ++i){
                _frequency[i][j] += rhs(i,j);
            }
        }
        return *this;
    }
    else{
        throw std::invalid_argument("Ambos objetos deben de tener el mismo tamaño de matriz y los mismos caracteres válidos");
    }

}

void BigramCounter::calculateFrequencies(char *fileName) {
    ifstream file(fileName);
    if (!file.is_open()) {
        throw std::ios_base::failure("exception if the given file cannot be opened");
    }

    char c;
    int lastChar = 0;
    while (file >> noskipws >> c) {
        c = tolower(c);
        int pos = isValidCharacter(c, _validCharacters);
        if (pos != -1) {
            if (lastChar != 0) {
                int lastPos = isValidCharacter(lastChar, _validCharacters);
                if (lastPos != -1) {
                    _frequency[lastPos][pos]++;
                }
            }
            lastChar = c;
        } else {
            lastChar = 0;
        }

    }
}

Language BigramCounter::toLanguage() const {
    Language language;
    for (int i = 0; i < getSize(); ++i) {
        for (int j = 0; j < getSize(); ++j) {
            if (this->_frequency[i][j] > 0) {
                Bigram bigram(_validCharacters[i], _validCharacters[j]);
                BigramFreq bigramFreq;
                bigramFreq.setBigram(bigram);
                bigramFreq.setFrequency(_frequency[i][j]);
                language.append(bigramFreq);
            }
        }
    }
    return language;
}


const int &BigramCounter::operator()(int row, int column) const {
    return  _frequency[row][column];
}

int &BigramCounter::operator()(int row, int column) {
    return  _frequency[row][column];
}
