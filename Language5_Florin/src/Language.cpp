//
// Created by flo on 03/05/23.
//

#include "../include/Language.h"
#include "../include/BigramFreq.h"
#include <iostream>
#include <fstream>

using namespace std;
const std::string Language::MAGIC_STRING_T = "MP-LANGUAGE-T-1.0";
const std::string Language::MAGIC_STRING_B="MP-LANGUAGE-B-1.0";

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
    this->identicador = other.identicador;
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
        this->identicador = MAGIC_STRING_T;
        _size = 0;
        _vectorBigramFreq = nullptr;
        _languageId = "unknown";

    } else {
        this->identicador = MAGIC_STRING_T;
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

void Language::setLanguageId(std::string &id) {
    this->_languageId = id;
}
int Language::getSize() const {
    return _size;
}

void Language::setSize(int i) {
    _size = i;
}

void Language::set_Identificador(std::string &id) {
    this->identicador = id;
}

BigramFreq &Language::at( const int index) {
    if (index > _size or index < 0) {
        throw out_of_range("Se encuentra fuera del rango");
    } else {
        return _vectorBigramFreq[index];
    }

}

const BigramFreq &Language::at(const int index) const {
    if (index > _size or index < 0) {
        throw out_of_range("Se encuentra fuera del rango");
    } else {
        return _vectorBigramFreq[index];
    }
}

int Language::findBigram(Bigram bigram) const {
    for (int i = 0; i <= _size - 1; ++i) {
        if (_vectorBigramFreq[i].getBigram().toString() == bigram.toString()) {
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
            if (_vectorBigramFreq[j] < _vectorBigramFreq[j + 1]) {
                //En el caso de que la frecuencia de la posici�n siguiente es mayor, se intercambian en el array
                swapElementsArrayBigramFreq(j, j + 1);
                intercambio = true;
            } else if (_vectorBigramFreq[j] == _vectorBigramFreq[j+1]){
                //En el caso de que las frecuencias sean iguales, comparamos los bigramas alfab�ticamente
                if (_vectorBigramFreq[j].getBigram().toString() > _vectorBigramFreq[j+1].getBigram().toString()) {
                    swapElementsArrayBigramFreq(j, j + 1);
                    intercambio = true;
                }
            }
        }
        if (!intercambio) {
            //Si intercambio es false se para el segundo bucle for y se sigue con el primero
            //ES decir, ser� false en el caso de que las frecuencia sean iguales y que los textos sean lo mismo.
            //El intercambio ser� false siempre que no ocurra ning�n caso de los if del for anidado
            break;
        }
    }
}

void Language::append(BigramFreq bigramFreq) {
    int posicion = findBigram(bigramFreq.getBigram());
    if (posicion != -1) { //Significa que se encuentra en el vector de bigram
        this->_vectorBigramFreq[posicion].setFrequency(
                this->_vectorBigramFreq[posicion].getFrequency() + bigramFreq.getFrequency());
    } else {
        
        //Nuevo por el tema de memoria din�mica
        BigramFreq *aux;
        aux = reservarmemoria(_size);
        for (int i = 0; i < _size ; ++i) {
            //aux[i] = _vectorBigramFreq[i];
            aux[i].setFrequency(_vectorBigramFreq[i].getFrequency());
            aux[i].setBigram(_vectorBigramFreq[i].getBigram());
        }
        deallocate();
        _vectorBigramFreq = aux;
        _vectorBigramFreq[_size].setBigram(bigramFreq.getBigram());
        _vectorBigramFreq[_size].setFrequency(bigramFreq.getFrequency());
        _size++;
    }
}

/*  //SE DEJA DE USAR POR LA IMPLEMENTACI�N DE LA SOBRECARGA DEL OPERADOR +=
void Language::join(Language language) {
    if (language.getLanguageId() == _languageId) {
        for (int i = 0; i < language._size; ++i) {
            this->append(language.at(i));
        }
    } else {
        throw std::ios_base::failure(string("Error de identificador de idioma"));
    }
}*/

void Language::load(char *fileName) {
    ifstream fentrada;
    fentrada.open(fileName);
    string identificador;

    if (fentrada) {
        fentrada>> identificador;
        if (identificador == MAGIC_STRING_T) {
            this->set_Identificador(identificador);
            fentrada >> *this;
        }
        else if( identificador == MAGIC_STRING_B){
            this->set_Identificador(identificador);
            fentrada >> *this;
        }
        else{
            throw std::ios_base::failure(string("Error de identificador de archivo"));
        }

    } else {
        throw std::ios_base::failure(string("Error de apertura del fichero"));
    }
    fentrada.close();

}

void Language::save(char *fileName) const {
    ofstream fsalida;
    fsalida.open(fileName);
    if (fsalida) {
        fsalida << *this;
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

BigramFreq const &Language::operator[](const int index) const  {
    this->at(index);
}

Language &Language::operator+=(Language &language) {
    if (language.getLanguageId() == _languageId) {
        for (int i = 0; i < language._size; ++i) {
            this->append(language.at(i));
        }
    } else {
        throw std::ios_base::failure(string("Error de identificador de idioma"));
    }
    return *this;
}

std::ostream &operator<<(ostream &os,  const Language &language) {
    if(language._languageId == "unknown"){
        os << language.identicador<<endl;
        os << language._languageId<<endl;
        os <<language.toString()<<endl;
    }
    else{
        os << language.identicador<<endl;
        os << language.getLanguageId() << endl;

        if(language.identicador == language.MAGIC_STRING_T){
            os << language.toString();
        }

        if(language.identicador == language.MAGIC_STRING_B){
            os<<language._size;
            for (int i=0; i< language.getSize() ;++i){
                language[i].serialize(os);
            }

       }
    }


    return os;
}

std::istream &operator>>(istream &is, Language &language) {
    string idioma;
    int parejas;
    string bigrama;
    int frecuencia;


    is >> idioma;
    language.setLanguageId(idioma);
    is >> parejas;
    if(parejas < 0){
        throw std::out_of_range("El n�mero de bigramas le�dos desde el archivo es negativo");
    }

    language.setSize(parejas);
    BigramFreq *vectorBigram = reservarmemoria(parejas);
    if( language.identicador == language.MAGIC_STRING_T){
        for (int i = 0; i < parejas; ++i) {
            is >> bigrama;
            is >> frecuencia;
            vectorBigram[i].setBigram(bigrama);
            vectorBigram[i].setFrequency(frecuencia);
        }
    }

    if( language.identicador == language.MAGIC_STRING_B){
        for (int i = 0; i < parejas; ++i) {
            vectorBigram[i].deserialize(is);
        }
    }

    if (language._vectorBigramFreq !=nullptr) { language.deallocate(); } //En el caso en el que se sobrecargue los datos
    // de un objeto language y se cargue otro nuevo, si no est� vaci� se libera memoria
    language._vectorBigramFreq = vectorBigram;
    return is;
}



