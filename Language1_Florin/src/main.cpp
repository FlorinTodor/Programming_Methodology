/*
 * Metodología de la Programación: Language1
 * Curso 2022/2023
 */

/*
 * File:   main.cpp
 * @author Silvia Acid Carrillo <acid@decsai.ugr.es>
 * @author Andrés Cano Utrera <acu@decsai.ugr.es>
 * @author Luis Castillo Vidal <L.Castillo@decsai.ugr.es>
 *
 * Created on 7 de febrero de 2023, 14:02
 */


/**
 * This program reads from the stardard input, an integer n (number of elements)
 * and a list of n pairs bigram-frequency. The pairs are stored in an array,
 * and then it is sorted in decreasing order of frequency. After that,
 * all the bigrams are changed to uppercase. The sorted array is finally shown
 * in the stardard output.
 * Running example:
 * > language1 < data/miniquijotebigrams.txt
 */

#include "iostream"
#include "../include/Bigram.h"
#include "../include/BigramFreq.h"
#include "../include/ArrayBigramFreqFunctions.h"
using namespace std;

/**
 * @author Florin Emanuel Todor
 */

int main(int argc, char* argv[]) {
    /////////////////////DECLARACIÓN DE VARIABLES/////////////////////
    int n;
    cout<<"Escriba el número de elementos que contendrá las parejas de BigramFreq"<<endl;
    cin>>n;
    BigramFreq array[n];

    /////////////////////USO DE FUNCIONES PARA EL PROYECTO////////////
    readArrayBigramFreq(array,n,n);
    sortArrayBigramFreq(array,n);
    toUpperArrayBigramFreq(array,n);
    printArrayBigramFreq(array,n);

}
