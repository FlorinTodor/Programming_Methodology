//
// Created by flo on 29/03/23.
//

#include "../include/Language.h"
#include "../include/BigramFreq.h"
#include <iostream>
#include <fstream>
using namespace std;
const string Language::MAGIC_STRING_T="MP-LANGUAGE-T-1.0";

/**
 * @author Florin Emanuel Todor
 */

Language::Language() {
    _languageId="unknown";
    _size=0;
}

Language::Language(int numberBigrams) {
    Bigram aux = "__";
    if( numberBigrams < 0 or numberBigrams > DIM_VECTOR_BIGRAM_FREQ){
        throw out_of_range("Se encuentra fuera del rango");
    }
    else{
        _languageId="unknown";
        _size = numberBigrams;
        for(int i=0; i< _size; ++i){
            _vectorBigramFreq[i].setFrequency(0);
            _vectorBigramFreq[i].setBigram(aux);
        }
    }
}

 std::string Language::getLanguageId() const {
    return _languageId;
}

 int Language::getSize() const {
    return _size;
}

void Language::setSize(int i) {
    _size = i;
}

void Language::setLanguageId(std::string id) {
    _languageId = id;
}

BigramFreq &Language::at(int index) {
    if (index > DIM_VECTOR_BIGRAM_FREQ or index < 0 ){
        throw out_of_range("Se encuentra fuera del rango");
    }
    else{
        return _vectorBigramFreq[index];
    }

}

const BigramFreq &Language::at(int index) const {
    if (index > DIM_VECTOR_BIGRAM_FREQ or index < 0 ){
        throw out_of_range("Se encuentra fuera del rango");
    }
    else{
        return _vectorBigramFreq[index];
    }
}

int Language::findBigram(Bigram bigram) const {
    for(int i=0; i<= _size-1; ++i){
        if (_vectorBigramFreq[i].getBigram().getText() == bigram.getText()){
            return i;
        }
    }
    return -1;
}

std::string Language::toString() const{
    string aux="";
    aux+=to_string(_size);
    aux.push_back('\n');
    for(int i=0; i<=_size-1; ++i){
        aux+=_vectorBigramFreq[i].toString();
        aux.push_back('\n');
    }
    return aux;
}

void Language::swapElementsArrayBigramFreq( int first, int second){
    BigramFreq aux;
    if (first < 0 || second < 0){
        throw out_of_range("Se encuentra fuera del rango");
    }
    else if (first < _size && second < _size) {
        aux = _vectorBigramFreq[first];
        _vectorBigramFreq[first] = _vectorBigramFreq[second];
        _vectorBigramFreq[second] = aux;
    }
    else{
        throw out_of_range("Se encuentra fuera del rango");
    }
}

void Language::sort() {
    // Algoritmo de ordenación burbuja para ordenar los objetos BigramFreq, teniendo en cuenta frecuencias y alfabeticamente
    for (int i = 0; i < _size-1; ++i){
        bool intercambio = false;
        for (int j = 0; j < _size-i-1; ++j){
            if (_vectorBigramFreq[j].getFrequency() < _vectorBigramFreq[j+1].getFrequency()){
                //En el caso de que la frecuencia de la posición siguiente es mayor, se intercambian en el array
                swapElementsArrayBigramFreq(j, j+1);
                intercambio = true;
            }
            else if (_vectorBigramFreq[j].getFrequency() == _vectorBigramFreq[j+1].getFrequency() && _vectorBigramFreq[j].getBigram().toString() > _vectorBigramFreq[j+1].getBigram().toString()){
                //En el caso de que las frecuencias sean iguales, comparamos los bigramas a través de la función toString.
                swapElementsArrayBigramFreq(j, j+1);
                intercambio = true;
            }
        }
        if (!intercambio){
            //Si intercambio es false se para el segundo bucle for y se sigue con el primero
            //ES decir, será false en el caso de que las frecuencia  sean iguales y que los textos sean lo mismo.
            //El intercambio será false siempre que no ocurra ningún caso de los if del for anidado
            break;
        }
    }
}

void Language::append(BigramFreq bigramFreq) {
    int posicion = findBigram(bigramFreq.getBigram());
    if (posicion != -1) { //Significa que se encuentra en el vector de bigram
        this->_vectorBigramFreq[posicion].setFrequency(this->_vectorBigramFreq[posicion].getFrequency() + bigramFreq.getFrequency());
    }
    else {
        _size++;
        _vectorBigramFreq[_size - 1].setBigram(bigramFreq.getBigram());
        _vectorBigramFreq[_size - 1].setFrequency(bigramFreq.getFrequency());
    }
}

void Language::join(Language language) {
    if (language.getLanguageId() == _languageId) {
        for (int i = 0; i < language._size; ++i) {
            this->append(language.at(i));
        }
    }
    else {
        throw std::ios_base::failure(string("Error de identificador de idioma"));
    }
}

void Language::load(char *fileName) {
    ifstream fentrada;
    fentrada.open(fileName);
    string identificador;
    string idioma;
    string bigrama;
    int frecuencia;
    int parejas=0;

    if(fentrada){
        fentrada >> identificador;
        
        if( identificador != MAGIC_STRING_T){
            throw std::ios_base::failure( string("Error de identificador de archivo"));
        }

        fentrada >> idioma;
        setLanguageId(idioma); //Realmente no haría falta valdría con haber hecho fentrada >> _LanguageId
        fentrada >> parejas;
        setSize(parejas); //Realmente no haría falta valdría con haber hecho fentrada >> _size
	
	if( _size > DIM_VECTOR_BIGRAM_FREQ){
		throw std::out_of_range("El tamaño de biagrams supera al tamaño del array");
	}
	
       for(int i=0; i < _size; ++i){ 
            fentrada>> bigrama;
            fentrada>> frecuencia;
            this->_vectorBigramFreq[i].setBigram(bigrama);
            this->_vectorBigramFreq[i].setFrequency(frecuencia);
        }
        
        

    }
    else{
        throw std::ios_base::failure( string("Error de apertura del fichero"));
    }
    fentrada.close();

}

void Language::save(char *fileName) const {
    ofstream fsalida;
    fsalida.open(fileName);
    if(fsalida){
        fsalida << MAGIC_STRING_T <<endl;
        fsalida << _languageId <<endl;
        fsalida<< this->toString();
    }
    else{
        throw std::ios_base::failure( string("Error de apertura del fichero"));
    }

    fsalida.close();
}
