//
// Created by flo on 4/03/23.
//
#include "Bigram.h"


#include "string"
#include "assert.h"
using namespace  std;

Bigram::Bigram(char first, char second) {
    _text.push_back(first);
    _text.push_back(second);
}

Bigram::Bigram(const std::string &text) {

    for( int i=0; i< text.size(); ++i){
        _text.push_back(text[i]);
    }
}

std::string Bigram::getText() const {
    string prueba;

    prueba.append(_text,_text.size());

    return prueba;
}

std::string Bigram::toString() const {
    string prueba;

    prueba.append(_text,_text.size());

    return prueba;
}

char &Bigram::at(int index) {

    return _text[index];
}

const char &Bigram::at(int index) const {
    return _text[index];
}


bool isValidCharacter(char character, const std::string& validCharacters){

    assert(!validCharacters.empty());
    bool algo= false;
    size_t a  = validCharacters.find(character);
    if ( a !=0){ algo = true;} else{ algo= false;}
    //a !=0 ? algo = true : algo = false;

    return algo;

}

void toUpper(Bigram &bigram){
    string text = bigram.toString(); // obtener el string del objeto Bigram
    for(int c = 0; c< text.size(); c++){
        if (islower(text[c])) { // si el carácter es una letra minúscula
            text[c] = toupper(text[c]); // convertir el carácter a mayúscula
        }
    }
    bigram=text;

}

