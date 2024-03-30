#include "Bigram.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

Bigram::Bigram(const std::string &text) {
    if (text.size() == 2) {
        _text[0] = text[0];
        _text[1] = text[1];
    }
    _text[2] = '\0';
}

Bigram::Bigram(char first, char second){
    _text[0] = first;
    _text[1] = second;
    _text[2] = '\0';
}

Bigram::Bigram(char text[]){
    if (strlen(text) == 2) {
        _text[0] = text[0];
        _text[1] = text[1];
    }
    else {
        _text[0] = '_';
        _text[1] = '_';
    }

    _text[2] = '\0';
}

std::string Bigram::getText() const{
    return _text;
}

std::string Bigram::toString() const{
    string copy = _text;
    return copy;
}

const char& Bigram::at(int index) const{
    if(index != 0 && index != 1) {
        throw out_of_range("Index se encuentra fuera del rango\n");
    }
    else return _text[index];
}

char& Bigram::at(int index) {
    if(index != 0 && index != 1) {
        throw out_of_range("Index se encuentra fuera del rango\n");
    }
    else return _text[index];
}

void Bigram::toUpper() {
    for(int i=0; i<2; ++i) {
        if(_text[i] >= 'a' && _text[i] <= 'z' ) {
            _text[i] = toupper(_text[i]);
        }
    }
}

bool isValidCharacter(char character, const std::string& validCharacters) {
    return validCharacters.find(character) != std::string::npos;
}