//
// Created by flo on 25/03/23.
//
/**
 * @author Florin Emanuel Todor
 */
#include "../include/ArrayBigramFreqFunctions.h"
#include "assert.h"
#include <string>
#include <algorithm>
using namespace std;

/**
 * @author Florin Emanuel Todor
 */

void readArrayBigramFreq(BigramFreq array[], const int dim, int nElements){
    assert(nElements >= 0);
    //Si nElements es > dim, se leerá solamente dim. debido a que dim es la capacidad máxima del array
    int tamanio;
    Bigram aux;
    string string1;
    int numero;

   if ( nElements > dim){
       tamanio = dim;
   }
   else if(nElements < dim){
        tamanio = nElements;
   }
   else{
       tamanio = dim;
   }
    cout<< "escriba "<<tamanio<<" parejas de Bigram y su frecuencia"<<endl;
   for(int i=0; i< tamanio; ++i){
        cin>>string1;
        aux = string1;
        array[i].setBigram(aux);
        cin>> numero;
        array[i].setFrequency(numero);
   }
}

void printArrayBigramFreq( BigramFreq array[],  int nElements){
    cout<<nElements<<endl;
    for(int i=0; i<nElements;++i){
        cout<<array[i].toString()<<endl;
    }

}

void swapElementsArrayBigramFreq(BigramFreq array[], int nElements, int first, int second){
    BigramFreq aux;
    if (first < 0 || second < 0){
        throw out_of_range("Se encuentra fuera del rango");
    }
    else if (first < nElements && second < nElements) {
        aux = array[first];
        array[first] = array[second];
        array[second] = aux;
    }
    else{
        throw out_of_range("Se encuentra fuera del rango");
    }
}

void sortArrayBigramFreq(BigramFreq array[], int nElements){
    // Algoritmo de ordenación burbuja para ordenar los objetos BigramFreq, teniendo en cuenta frecuencias y alfabeticamente
    for (int i = 0; i < nElements-1; i++){
        bool intercambio = false;
        for (int j = 0; j < nElements-i-1; j++){
            if (array[j].getFrequency() < array[j+1].getFrequency()){
                //En el caso de que la frecuencia de la posición siguiente es mayor, se intercambian en el array
                swapElementsArrayBigramFreq(array, nElements, j, j+1);
                intercambio = true;
            }
            else if (array[j].getFrequency() == array[j+1].getFrequency() && array[j].getBigram().toString() > array[j+1].getBigram().toString()){
                //En el caso de que las frecuencias sean iguales, comparamos los bigramas a través de la función toString.
                swapElementsArrayBigramFreq(array, nElements, j, j+1);
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

void toUpperArrayBigramFreq(BigramFreq array[], int nElements){
    Bigram aux;
    for(int i=0; i< nElements; ++i){
         aux = array[i].getBigram();
         aux.toUpper();
         array[i].setBigram(aux);

    }
}