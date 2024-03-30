/*
 * Metodología de la Programación: Language0
 * Curso 2022/2023
 */

/* 
 * File:   main.cpp
 * @author Silvia Acid Carrillo <acid@decsai.ugr.es>
 * @author Andrés Cano Utrera <acu@decsai.ugr.es>
 * @author Luis Castillo Vidal <L.Castillo@decsai.ugr.es>
 *
 * Created on 2 de febrero de 2023, 12:23
 */



/**
 * This program reads a text (without spaces) with a undefined number of 
 * characters and a text with two characters (bigram). It finds the bigrams 
 * contained in the first text, storing them in an array of Bigram. 
 * After that, the bigrams of the array are shown in the standard output. 
 * Then it converts to uppercase the bigrams in the array that are equals to the 
 * bigram of the second text. Finally the bigrams of the array are shown again 
 * in the standard output. 
 * Running example:
 * > language0 < data/SimpleText.txt
 */

/**
 * @author Florin Emanuel Todor
 * @date   03/03/2023
 */
#include <string>
#include "Bigram.h"
using namespace std;


int main(int argc, char* argv[]) {
    // This string contains the list of characters that are considered as
    // valid within a word. The rest of characters are considered as
    // separators
    const string validCharacters = "abcdefghijklmnopqrstuvwxyz\xE0\xE1\xE2\xE3\xE4\xE5\xE6\xE7\xE8\xE9\xEA\xEB\xEC\xED\xEE\xEF\xF0\xF1\xF2\xF3\xF4\xF5\xF6\xF8\xF9\xFA\xFB\xFC\xFD\xFE\xFF";

    string cadena1 = argv[0];
    string cadena2 = argv[1];
    Bigram palabras;
    int n=0;

    // Read a text
    // Convertir todos los elementos en minuscula
    for(int i = 0 ; i< cadena1.size(); ++i){
        cadena1[i] = tolower(cadena1[i]);
    }
    int contador=0;
    char letra1, letra2;
    for(int i=0 ; i< cadena1.size(); ++i){
        if (isValidCharacter(cadena1[i],validCharacters)){
            contador++;
            if ( contador == 1){ letra1 = cadena1[i];}
            if ( contador == 2){ letra2 = cadena1[i]; Bigram aux(letra1,letra2); palabras = aux; n++; letra1 = letra2; contador = 1;} //Supuestamente funciona

            //QUeda pensar como seguir teniendo la letra anterior, ya que son consecutivos. Supuestamente ya estaría hecho con el tema de contador = 1

        }
        else{
            contador=0;
        }

    }
    /*
    for(int i = 0; i < 50; ++i){
        cout<< palabras[i].toString()<<endl;
    } */


    //Tras tener todos los bigramas hechos, tenemos que buscar en ese array si hay alguna pareja que tenga cadena2, si lo tiene se pone en mayúscula.



    // Read a bigram (tex with two characters)
    
    // Find the bigrams in text and put them in an array of Bigrams
    
    // Show the bigrams stored in the array
    
    // Convert to uppercase the bigrams in the array that are equals to input bigram
    
    // Show again the bigrams stored in the array
}

