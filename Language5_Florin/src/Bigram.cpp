//
// Created by flo on 25/03/23.
//
#include "../include/Bigram.h"
#include <iostream>
#include "string"
#include <stdio.h>
#include <cstring>
#include "assert.h"

/**
 * @author Florin Emanuel Todor
 */
using namespace std;

    Bigram::Bigram(const std::string &text) {

        if( text.size() == 2){
            _text[0] = text[0];
            _text[1] = text[1];
            _text[2] = '\0';

        }

    }

    Bigram::Bigram(char first,  char second) {

        _text[0] = first;
        _text[1] = second;
        _text[2] = '\0';

    }

    Bigram::Bigram(const char *text)  {

            if(strlen(text) != 2){
                _text[0] = '_';
                _text[1] = '_';
                _text[2] = '\0';
            }
            else{
                _text[0] = text[0];
                _text[1] = text[1];
                _text[2] = '\0';
            }
    }

std::string Bigram::getText() const {
    string aux;
    aux = _text;
    return aux;
}

std::string Bigram::toString() const {
    string aux;
    aux = _text;
    return aux;

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

void  Bigram::toUpper() {
    for(int i=0; i< strlen(_text); ++i){
        if (islower(_text[i])) { // si el carácter es una letra minúscula
            _text[i] = toupper(_text[i]); // convertir el carácter a mayúscula
        }
    }
}

int isValidCharacter(char character, const std::string& validCharacters){

    assert(!validCharacters.empty());
    bool validacion= false;
    size_t a = validCharacters.find(character);
    int pos;
    a != validCharacters.npos ? pos = a : pos  = -1;
    //Si es distinto que npos significa que se encuentra en validCharacters

    return pos;

}

Bigram &Bigram::operator[](int index) {
    at(index);
}
std::ostream & operator<<(std::ostream &os, Bigram &bigram){
    os << bigram.toString();
    return os;
}

std::istream &operator>>(std::istream &is, Bigram &bigram){
    string aux;
    is >> aux;

    if(aux.size() == 2){
        bigram= aux;
    }
    else{
        throw out_of_range("No se ha introducido un bigram correcto");
    }
    return is;
}

void Bigram::serialize(std::ostream& outputStream) const {
    outputStream.write(_text, sizeof(_text));
}

void Bigram::deserialize(std::istream& inputStream) {
    inputStream.read(_text, sizeof (_text));
}