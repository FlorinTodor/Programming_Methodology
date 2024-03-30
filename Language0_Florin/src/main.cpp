
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


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/**
 * @author Florin Emanuel Todor
 * @date   06/03/2023
 */
#include <string>
#include "../include/Bigram.h"
#include <iostream>

using namespace std;


int main(int argc, char* argv[]) {
   ////////////////////////////////////////////DECLARACIÓN DE VARIABLES///////////////////////////////////////
    const string validCharacters = "abcdefghijklmnopqrstuvwxyz\xE0\xE1\xE2\xE3\xE4\xE5\xE6\xE7\xE8\xE9\xEA\xEB\xEC\xED\xEE\xEF\xF0\xF1\xF2\xF3\xF4\xF5\xF6\xF8\xF9\xFA\xFB\xFC\xFD\xFE\xFF";

   // string cadena1 = argv[1]; uso con argv
   // string cadena2 = argv[2]; uso con argv
   string cadena1, cadena2;
    Bigram palabras[60]; //Tamaño fijo de array de Bigram
    int n=0; //nº de parejas de bigram
    int  contador=0;
    string aux;

    //Leer el texto
    cout<<"Introduzca el text"<<endl;
    cin >> cadena1;

    //Leer la pareja de Bigram para buscar en cadena1
    cout<<"Introduzca la pareja de Bigram"<<endl;
    cin>> cadena2;


    ////////////////////////////////////////COMIENZO DEL CÓDIGO //////////////////////////////////////////////
    for(int i = 0 ; i< cadena1.size(); ++i){
        cadena1[i] = tolower(cadena1[i]);
    }
    for(int i=0; i< cadena1.size(); ++i){

        if(isValidCharacter(cadena1[i],validCharacters)){ // En el caso de que sea valido el caracter
            contador++;

            if (contador==1){ //Primera vez que se introduce un caracter
                aux.push_back(cadena1[i]);
            }
            if (contador == 2){ //Segundo caracter, para poder formar la pareja de Bigram
                aux.push_back(cadena1[i]);
                char e = aux[1];
                palabras[n]=aux;
                contador=1; //Para guardar el segundo caracter
                n++; //Aumentar el número de parejas de bigram
                aux.clear();
                aux.push_back(e);

            }
        }
        else{ // En el caso de que no sea válido el caracter
            aux.clear();
            contador=0;
        }
    }

    ///////////////////////////////////////////ALGORITMO TERMINADO //////////////////////////////

    //////////////////////////////////////////MUESTRA DEL CÓDIGO REALIZADO PARA LA PRÁCTICA /////////////////////////
    cout<<n<<endl; //Mostrar el número de parejas de Bigram

    //Mostras las parejas de bigram
    for(int i=0; i< n; ++i){
        cout<<palabras[i].toString()<<endl;
    }

    /////////////////////////////////////////VAMOS A MOSTRAR LAS PAREJAS DE BIGRAM QUE CUMPLAN LA CONDICIÓN ///////////////////////////
    cout<<endl; //Salto de línea
    cout<<n<<endl; //Mostrar el número de parejas de Bigram

    for(int i=0; i< n; ++i){
        if(palabras[i].toString() == cadena2){
            toUpper(palabras[i]);
            cout<<palabras[i].toString()<<endl;
        }
        else{
            cout<<palabras[i].toString()<<endl;
        }
    }

}


