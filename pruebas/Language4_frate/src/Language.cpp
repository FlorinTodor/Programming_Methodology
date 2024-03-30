/*
 * Metodología de la Programación: Language2
 * Curso 2022/2023
 */

#include "../include/Language.h"
#include <iostream>
#include <fstream>

using namespace std;

const string Language::MAGIC_STRING_T="MP-LANGUAGE-T-1.0";

Language::Language() {
    _languageId = "unkown";
    _size = 0;
    _vectorBigramFreq = nullptr;
}

Language::Language(int numberBigrams) {
    if(numberBigrams < 0){
        throw std::out_of_range("El numero de bigramas se encuentra fuera del rango");
    }

    _languageId = "unkown";
    _size = numberBigrams;
    _vectorBigramFreq = new BigramFreq[_size];

    for(int i=0; i<_size; ++i) {
        _vectorBigramFreq[i].setBigram("__"); //The bigram is initializated as "__"
        _vectorBigramFreq[i].setFrequency(0); //The frequency is initializated as 0
    }
}

Language::Language(const Language &orig) {
    _languageId = orig.getLanguageId();
    _size = orig.getSize();
    _vectorBigramFreq = new BigramFreq[_size];
    for(int i=0; i<_size; ++i){
        _vectorBigramFreq[i] = orig._vectorBigramFreq[i];
    }
}

Language::~Language() {
    delete [] _vectorBigramFreq;
}

Language &Language::operator=(const Language &orig) {
    if(this != &orig) {
        //Liberamos memoria del objeto
        delete [] _vectorBigramFreq;

        //Copiamos el contenido de orig
        _languageId = orig.getLanguageId();
        _size = orig.getSize();
        _vectorBigramFreq = new BigramFreq[_size];
        for(int i=0; i<_size; ++i){
            _vectorBigramFreq[i] = orig._vectorBigramFreq[i];
        }
    }

    return *this;
}

const std::string &Language::getLanguageId() const {
    return _languageId;
}

void Language::setLanguageId(const std::string &id) {
    _languageId = id;
}

const BigramFreq &Language::at(int index) const {
    if(index < 0 || index >= _size){
        throw out_of_range("Index se encuentra fuera del rango\n");
    }
    else return _vectorBigramFreq[index];
}

BigramFreq &Language::at(int index) {
    if(index != 0 || index != 1){
        throw out_of_range("Index it's out of the range\n");
    }
    else return _vectorBigramFreq[index];
}

int Language::getSize() const {
    return _size;
}

double Language::getDistance(const Language &otherLanguage) const {
    if(_size == 0) {
        throw std::invalid_argument("Argumento Invalido...\n");
    }

    //Declaramos la variable distance
    double distance=0;

    for(int i=0; i<_size; ++i){
        int rank1 = i;
        int rank2 = otherLanguage.findBigram(_vectorBigramFreq[i].getBigram());

        if (rank2 == -1) {
            rank2 = _size;
        }

        distance += abs(rank1 - rank2);
    }

    distance /= _size*_size;
    return distance;
}

int Language::findBigram(const Bigram &bigram) const {
    for(int i=0; i<_size; ++i) {
        if(_vectorBigramFreq[i].getBigram().getText() == bigram.getText()) {
            return i;
        }
    }
    return -1;
}

std::string Language::toString() const {
    string language;

    //First line
    language += std::to_string(_size);
    language.push_back('\n');

    //Next lines
    for(int i=0; i<_size; ++i){
        language += _vectorBigramFreq[i].toString();
        language.push_back('\n');
    }

    return language;
}

void Language::swapElementsArrayBigramFreq(int first, int second) {
    BigramFreq aux;

    if(_size > first && first >= 0 && _size > second && second >= 0) {
        aux = _vectorBigramFreq[first];
        _vectorBigramFreq[first] = _vectorBigramFreq[second];
        _vectorBigramFreq[second] = aux;
    }
    else {
        throw out_of_range("First o second se encuentra fuera del rango\n");
    }
}

void Language::sort() {
    //Ordenacion por burbuja
    for(int i=0; i<_size; ++i) {
        for(int j=0; j<_size-i-1; ++j){
            if(_vectorBigramFreq[j].getFrequency() < _vectorBigramFreq[j+1].getFrequency()){
                swapElementsArrayBigramFreq(j, j+1);
            }
            else if(_vectorBigramFreq[j].getFrequency() == _vectorBigramFreq[j+1].getFrequency() && _vectorBigramFreq[j].getBigram().getText() > _vectorBigramFreq[j+1].getBigram().getText()) {
                swapElementsArrayBigramFreq(j, j+1);
            }
        }
    }
}

void Language::save(const char *fileName) const {
    //Asignamos a un fichero el nombre del fichero de salida
    std::ofstream ficheroSalida(fileName);

    if(!ficheroSalida.is_open()){
        throw std::ios_base::failure("Error. No se puede abir el fichero\n");
    }

    //MAGIC STRING
    ficheroSalida << MAGIC_STRING_T << endl;

    //Guardamos en el fichero de salida el ID del language y el tamanio
    ficheroSalida << _languageId << endl;

    //Ahora guardaremos los bigramas con sus respectivas frecuencias
    ficheroSalida << toString();

    //Cerramos el fichero de salida
    ficheroSalida.close();
}

void Language::load(const char *fileName) {

    //Abrimos el archivo
    std::ifstream ficheroEntrada(fileName);

    if(!ficheroEntrada.is_open()) {
        throw std::ios_base::failure("Error al abrir el fichero\n");
    }

    //Obtenemos el magic string
    string magic;
    ficheroEntrada >> magic;

    if(magic != MAGIC_STRING_T){
        throw std::invalid_argument("El magic string del fichero es invalido\n");
    }

    //Obtenemos el identificador del language
    ficheroEntrada >> _languageId;

    //Obtenemos el numero de bigramas
    ficheroEntrada >> _size;

    if(_size < 0){
        throw std::out_of_range("El numero de bigramas esta fuera del rango permitido\n");
    }

    //Obtenemos los bigramas y sus respectivas frecuencias
    string bigram;
    int frequency;
    _vectorBigramFreq = new BigramFreq[_size];

    for(int i=0; i<_size; ++i) {
        ficheroEntrada >> bigram >> frequency;
        _vectorBigramFreq[i].setBigram(bigram);
        _vectorBigramFreq[i].setFrequency(frequency);
    }

    //Cerramos el fichero
    ficheroEntrada.close();
}

void Language::append(const BigramFreq &bigramFreq) {
    //Guardamos en un entero la posicion del bigrama
    int posicion = findBigram(bigramFreq.getBigram());

    //Si se ha encontrado, entoces...
    if(posicion >= 0) {
        _vectorBigramFreq[posicion].setFrequency(_vectorBigramFreq[posicion].getFrequency()+bigramFreq.getFrequency());
    }

    else{
        _vectorBigramFreq[_size] = bigramFreq;
        _size++;
    }
}

void Language::join(const Language &language) {
    for(int i=0; i<language.getSize(); ++i) {
        append(language._vectorBigramFreq[i]);
    }
}