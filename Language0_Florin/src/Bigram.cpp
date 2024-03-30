//
// Created by flo on 4/03/23.
//

#include "../include/Bigram.h"
#include <string>
#include <assert.h>
#include <iostream>
#include <stdexcept>
using namespace  std;

Bigram::Bigram(char first, char second) {
    if(!_text.empty()){ _text.clear();}

        _text.push_back(first);
        _text.push_back(second);
}

Bigram::Bigram(const std::string &text) {

   if (text.size() == 2){
       _text = text;
   }
   else{
       _text="__";
   }
}

std::string Bigram::getText() const {
   return _text;
}

std::string Bigram::toString() const {
   return _text;
}

char &Bigram::at(int index) {
    if ( index == 0 or index == 1){
        return _text[index];
    }
    else{
        throw out_of_range("Se encuentra fuera del rango");
    }
}

const char &Bigram::at(int index) const {
    if (index == 0 or index == 1) {
        return _text[index];
    } else {
        throw out_of_range("Se encuentra fuera del rango");
    }
}



bool isValidCharacter(char character, const std::string& validCharacters){

    assert(!validCharacters.empty());
    bool validacion= false;
    size_t a = validCharacters.find(character);
    a != validCharacters.npos ? validacion = true : validacion = false;
    //Si es distinto que npos significa que se encuentra en validCharacters

    return validacion;

}


void toUpper(Bigram &bigram){
    string text = bigram.toString(); // obtener el string del objeto Bigram
    for(int c = 0; c <= text.size(); c++){
        if (islower(text[c])) { // si el carácter es una letra minúscula
            text[c] = toupper(text[c]); // convertir el carácter a mayúscula
        }
    }
    bigram=text;

}

