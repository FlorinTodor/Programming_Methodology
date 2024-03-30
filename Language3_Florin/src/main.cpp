/*
 * Metodología de la Programación: Language3
 * Curso 2022/2023
 */

#include <iostream>
#include "../include/Language.h"
#include <string>
using namespace  std;
/*
 * File:   main.cpp
 * @author Silvia Acid Carrillo <acid@decsai.ugr.es>
 * @author Andrés Cano Utrera <acu@decsai.ugr.es>
 * @author Luis Castillo Vidal <L.Castillo@decsai.ugr.es>
 *
 * Created on 7 de febrero de 2023, 14:02
 */

/**
 * @author Florin Emanuel Todor
 */

/**
 * Shows help about the use of this program in the given output stream
 * @param outputStream The output stream where the help will be shown (for example,
 * cout, cerr, etc)
 */
void showEnglishHelp(ostream& outputStream) {
    outputStream << "Error, run with the following parameters:" << endl;
    outputStream << "language3 [-t min|max] <file1.bgr> <file2.bgr> [ ... <filen.bgr>]" << endl;
}

/**
 * This program reads an undefined number of Language objects from the set of
 * files passed as parameters to main(). All the Languages object, except the
 * first one, must be stored in a dynamic array of Language objects. Then,
 * for each Language in the dynamic array, this program prints to the
 * standard output the name of the file of that Language and the distance from
 * the first Language to the current Language.
 * Finally, the program should print in the standard output, the name of
 * the file with the Language with the minimum|maximum distance to the Language
 * of the first file and its language identifier.
 *
 * At least, two Language files are required to run this program.
 * Running example:
 * > language3 [-t min|max] <file1.bgr> <file2.bgr> [  ... <filen.bgr>]
 */

int main(int argc, char* argv[]) {
    if (argc <3){
        showEnglishHelp(cerr);
    }

    //Vamos a tener en cuenta que se le pasa -t
    bool min=false;
    bool max=false;
    if(string(argv[1]) == "-t"){
        //ARGUMENTOS 1 Y 2 SERÍA PARA -T Y MIN/MAX el resto sería para los ficheros bgr
        if(string(argv[2])=="min"){
            min=true;
        }
        else if(string(argv[2])=="max"){
            max=true;
        }
        else if(string(argv[2]).find_first_not_of("MAX""MIN""") == string::npos){
            showEnglishHelp(cerr);
        }
        else {
            showEnglishHelp(cerr);
        }

        int pos=0; //Almacenamos la posición del que tenga el max o min
        string * ficheros= new string[argc-2]; //Creamos un string dinámico para mostrar el nombre de los ficheros
        Language * languages = new Language[argc-2]; //Creamos un vector de languages dinámico
        languages[0].load(argv[3]); //Cargamos el primer language, para calcular la distancia
        ficheros[0]= string(argv[3]); //Almacenamos el nombre del fichero del primer language
        int posicion=4;//Debido a que como se lee -t y la modalidad, se empieza a leer los demás ficheros desde 4 hasta argc

        for(int i=1; i< argc-3; ++i){ //Empieza en 1 porque en 0 está el primero para las distancias, argc-3 para quitar los dos primeros parámetros y el language 0
            languages[i].load(argv[posicion]); //Uso de posición para empezar a leer los demás ficheros del argv
            ficheros[i] = string(argv[posicion]);
            posicion++;
        }

        if(min){
            double minimo=1;
            for(int i=1; i< argc-3; ++i){//Empieza en 1 porque en 0 está el primero para las distancias, argc-3 para quitar los dos primeros parámetros y el language 0
                double distancia = languages[0].getDistance(languages[i]);
                cout<<"Distance to "<<ficheros[i]<<": "<< distancia;
                if(distancia < minimo){ minimo = distancia; pos=i;}
                cout<<endl;
            }

            cout<<"Nearest language file: "<<ficheros[pos]<<endl;
            cout<<"Identifier of the nearest language: "<<languages[pos].getLanguageId()<<endl;

            delete[]languages;
            delete[]ficheros;
        }

        if(max){
            double maximo =-1;
            for(int i=1; i< argc-3; ++i){//Empieza en 1 porque en 0 está el primero para las distancias, argc-3 para quitar los dos primeros parámetros y el language 0
                double distancia = languages[0].getDistance(languages[i]);
                cout<<"Distance to "<<ficheros[i]<<": "<< distancia;
                if(distancia > maximo){ maximo = distancia; pos=i;}
                cout<<endl;
            }

            cout<<"Farthest language file: "<<ficheros[pos]<<endl;
            cout<<"Farthest language identifier:"<<languages[pos].getLanguageId()<<endl;


            delete[]languages;
            delete[]ficheros;
        }


    }
   else if(string(argv[1]).find_first_not_of("-""abcdefghijklmnopqrsuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") == std::string::npos) {
            showEnglishHelp(cerr);
    }

    else{ //En el caso de que no se haya pasado nada, TODOS LOS PARÁMETROS SON FICHEROS BGR

        string * ficheros= new string[argc];
        Language * languages = new Language[argc];
        languages[0].load(argv[1]);//Cargar el primer language
        ficheros[0]= string(argv[1]);//Almacenar el nombre del fichero del primer language
        int posicion=2;//Para almacenar los ficheros de languages
        double minimo=1; //maximo de distancia es 1, ya que se encuentra entre 0 y 1
        int pos=0;//Almacenar la posición del min

        for(int i=1; i< argc-1; ++i){ //Empieza en 1 porque en 0 está el primero para las distancias, argc-3 para quitar los dos primeros parámetros y el language 0
            languages[i].load(argv[posicion]); //Uso de posición para empezar a leer los demás ficheros del argv
            ficheros[i] = string(argv[posicion]);
            posicion++;
        }

        for(int i=1; i< argc-1; ++i){//Empieza en 1 porque en 0 está el primero para las distancias, argc-1 para quitar el language 0
            double distancia = languages[0].getDistance(languages[i]);
            cout<<"Distance to "<<ficheros[i]<<": "<< distancia;
            if(distancia < minimo){ minimo = distancia; pos=i;}
            cout<<endl;
        }

        cout<<"Nearest language file: "<<ficheros[pos]<<endl;
        cout<<"Identifier of the nearest language: "<<languages[pos].getLanguageId()<<endl;
        delete[]languages;
        delete[]ficheros;
    }


}