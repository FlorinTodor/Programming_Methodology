//
// Created by flo on 30/04/23.
//

#include "../include/Language.h"
#include "../include/BigramFreq.h"
#include <iostream>
#include <fstream>

using namespace std;
const string Language::MAGIC_STRING_T = "MP-LANGUAGE-T-1.0";

/**
 * @author Florin Emanuel Todor
 */


Language::Language() {
    allocate();
}

Language::Language(int numberBigrams) {
    allocate(numberBigrams);
}

BigramFreq *reservarmemoria(int i) {
    BigramFreq *aux;
    aux = new BigramFreq[i];
    return aux;

}

Language &Language::copy(const Language &other) {
    this->_languageId = other._languageId;
    this->_size = other._size;
    this->_vectorBigramFreq = reservarmemoria(_size);
    for (int i = 0; i < _size; ++i) {
        this->_vectorBigramFreq[i] = other._vectorBigramFreq[i];
    }
    return *this;
}

Language &Language::operator=(const Language &other) {
    if (this == &other) { return *this; }
    else {
        delete [] this->_vectorBigramFreq;
        return copy(other);
    }
}

Language::Language(const Language &other) {
    *this = other;
}

void Language::deallocate() {
    delete[] this->_vectorBigramFreq;
    _vectorBigramFreq = nullptr;
}

Language::~Language() {
    this->_size = 0;
    this->_languageId = "unknown";
    deallocate();
}


void Language::allocate(int i) {

    if (i == 0) {
        _size = 0;
        _vectorBigramFreq = nullptr;
        _languageId = "unknown";

    } else {
        Bigram aux = "__";
        _languageId = "unknown";
        _size = i;
        _vectorBigramFreq = nullptr;
        if (i < 0 or i > _size) {
            throw out_of_range("Se encuentra fuera del rango");
        } else {
            BigramFreq *vectorBigram = reservarmemoria(_size); //M�todo friend para reservar memoria para el _vectorBigramFreq
            for (int i = 0; i < _size; ++i) {
                vectorBigram[i].setFrequency(0);
                vectorBigram[i].setBigram(aux);
            }
            this->_vectorBigramFreq = vectorBigram; //Se le asigna al puntero de this, la direcci�n de memoria de vectorBigram
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
    if (index > _size or index < 0) {
        throw out_of_range("Se encuentra fuera del rango");
    } else {
        return _vectorBigramFreq[index];
    }

}

const BigramFreq &Language::at(int index) const {
    if (index > _size or index < 0) {
        throw out_of_range("Se encuentra fuera del rango");
    } else {
        return _vectorBigramFreq[index];
    }
}

int Language::findBigram(Bigram bigram) const {
    for (int i = 0; i <= _size - 1; ++i) {
        if (_vectorBigramFreq[i].getBigram().getText() == bigram.getText()) {
            return i;
        }
    }
    return -1;
}

std::string Language::toString() const {
    string aux = "";
    aux += to_string(_size);
    aux.push_back('\n');
    for (int i = 0; i <= _size - 1; ++i) {
        aux += _vectorBigramFreq[i].toString();
        aux.push_back('\n');
    }
    return aux;
}

void Language::swapElementsArrayBigramFreq(int first, int second) {
    BigramFreq aux;
    if (first < 0 || second < 0) {
        throw out_of_range("Se encuentra fuera del rango");
    } else if (first < _size && second < _size) {
        aux = _vectorBigramFreq[first];
        _vectorBigramFreq[first] = _vectorBigramFreq[second];
        _vectorBigramFreq[second] = aux;
    } else {
        throw out_of_range("Se encuentra fuera del rango");
    }
}

void Language::sort() {
    // Algoritmo de ordenaci�n burbuja para ordenar los objetos BigramFreq, teniendo en cuenta frecuencias y alfabeticamente
    for (int i = 0; i < _size - 1; ++i) {
        bool intercambio = false;
        for (int j = 0; j < _size - i - 1; ++j) {
            if (_vectorBigramFreq[j].getFrequency() < _vectorBigramFreq[j + 1].getFrequency()) {
                //En el caso de que la frecuencia de la posici�n siguiente es mayor, se intercambian en el array
                swapElementsArrayBigramFreq(j, j + 1);
                intercambio = true;
            } else if (_vectorBigramFreq[j].getFrequency() == _vectorBigramFreq[j + 1].getFrequency() &&
                       _vectorBigramFreq[j].getBigram().toString() > _vectorBigramFreq[j + 1].getBigram().toString()) {
                //En el caso de que las frecuencias sean iguales, comparamos los bigramas a trav�s de la funci�n toString.
                swapElementsArrayBigramFreq(j, j + 1);
                intercambio = true;
            }
        }
        if (!intercambio) {
            //Si intercambio es false se para el segundo bucle for y se sigue con el primero
            //ES decir, ser� false en el caso de que las frecuencia  sean iguales y que los textos sean lo mismo.
            //El intercambio ser� false siempre que no ocurra ning�n caso de los if del for anidado
            break;
        }
    }
}

void Language::append(const BigramFreq &bigramFreq) {
    int posicion = findBigram(bigramFreq.getBigram());
    if (posicion != -1) { //Significa que se encuentra en el vector de bigram
        this->_vectorBigramFreq[posicion].setFrequency(
                this->_vectorBigramFreq[posicion].getFrequency() + bigramFreq.getFrequency());
    } else {
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
    } else {
        throw std::ios_base::failure(string("Error de identificador de idioma"));
    }
}

void Language::load(char *fileName) {
    ifstream fentrada;
    fentrada.open(fileName);
    string identificador;
    string idioma;
    string bigrama;
    int frecuencia = 0;
    int parejas = 0;

    if (fentrada) {
        fentrada >> identificador;
        if (identificador != MAGIC_STRING_T) {
            throw std::ios_base::failure(string("Error de identificador de archivo"));
        }

        fentrada >> idioma;
        setLanguageId(idioma); //Realmente no har�a falta valdr�a con haber hecho fentrada >> _LanguageId
        fentrada >> parejas;
        setSize(parejas); //Realmente no har�a falta valdr�a con haber hecho fentrada >> _size

        BigramFreq *vectorBigram = reservarmemoria(parejas);
        for (int i = 0; i < parejas; ++i) {
            fentrada >> bigrama;
            fentrada >> frecuencia;
            vectorBigram[i].setBigram(bigrama);
            vectorBigram[i].setFrequency(frecuencia);
        }
        if(_vectorBigramFreq != nullptr){deallocate();} //En el caso en el que se sobrecargue los datos de un objeto language y se cargue otro nuevo, si no est� vaci� se libera memoria
        _vectorBigramFreq = vectorBigram;


    } else {
        throw std::ios_base::failure(string("Error de apertura del fichero"));
    }
    fentrada.close();

}

void Language::save(char *fileName) const {
    ofstream fsalida;
    fsalida.open(fileName);
    if (fsalida) {
        fsalida << MAGIC_STRING_T << endl;
        fsalida << _languageId << endl;
        fsalida << this->toString();
    } else {
        throw std::ios_base::failure(string("Error de apertura del fichero"));
    }

    fsalida.close();
}

double Language::getDistance(const Language &otherLanguage) const {
    double sum = 0; //Sumatoria para calcular la distancia
    int rank2; //Posici�n en L2

    if (this->_size == 0) {
        throw std::invalid_argument("Bigrama vacio");
    }

    for (int i = 0; i < _size; i++) {//S�lo tenemos que comprobar los elementos de l1, por eso solo hasta _size de l1
        Bigram aux;
        aux = (_vectorBigramFreq[i].getBigram());
        int comprobar = otherLanguage.findBigram(aux);
        if (comprobar != -1) { //Significa que se encuentra en el otro language
            rank2 = comprobar;
            sum += abs(i - rank2); //valor absoluto
        } else { //En el caso de que no se encuentre en el otro language
            rank2 = _size;
            sum += ::abs(i - rank2); //valor absoluto
        }

    }
    sum /= (_size * _size);
    return sum;

}


