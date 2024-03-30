/*
 * Metodología de la Programación: Language5
 * Curso 2022/2023
 */

/**
 * @file learn.cpp
 * @author Silvia Acid Carrillo <acid@decsai.ugr.es>
 * @author Andr?s Cano Utrera <acu@decsai.ugr.es>
 * @author Luis Castillo Vidal <L.Castillo@decsai.ugr.es>
 *
 * Created on 29 January 2023, 11:00
 */

/**
 * Shows help about the use of this program in the given output stream
 * @param outputStream The output stream where the help will be shown (for example,
 * cout, cerr, etc)
 */
 


#include <iostream>
#include "Language.h"
#include "Bigram.h"
#include "BigramCounter.h"
#include "BigramFreq.h"

using namespace std;
    void showEnglishHelp(ostream &outputStream) {
        outputStream << "Error, run with the following parameters:" << endl;
        outputStream << "learn [-t|-b] [-l languageId] [-o outputFilename] <text1.txt> [<text2.txt> <text3.txt> .... ]"
                     << endl;
        outputStream
                << "           learn the model for the language languageId from the text files <text1.txt> <text2.txt> <text3.txt> ..."
                << endl;
        outputStream << endl;
        outputStream << "Parameters:" << endl;
        outputStream << "-t|-b: text mode or binary mode for the output file (-t by default)" << endl;
        outputStream << "-l languageId: language identifier (unknown by default)" << endl;
        outputStream << "-o outputFilename: name of the output file (output.bgr by default)" << endl;
        outputStream << "<text1.txt> <text2.txt> <text3.txt> ....: names of the input files (at least one is mandatory)"
                     << endl;
    }


/**
 * This program learns a Language model from a set of input tex files (tex1.txt,
 * tex2.txt, ...
 * Running example:
 * > learn [-t|-b] [-l languageId] [-o outputFilename] <text1.txt> [<text2.txt> <text3.txt> ....]
 * @param argc The number of command line parameters
 * @param argv The vector of command line parameters (cstrings)
 * @return 0 If there is no error; a value > 0 if error
 */

/**
 * @author Florin Emanuel Todor
 */
#include "string"
#include "cstring"

int main(int argc, char * argv[]) {
    char * outputFilename = "output.bgr";
    string languageId = "unknown";
    bool binaryMode = false;
    char** ficheros = nullptr;
    int numInputFiles = 0;
    cout<<argc<<endl;

    for (int i = 1; i < argc; ++i) {
       
        string arg = argv[i];
        cout<<arg<<endl;
        if (string(argv[i])== "-t"){
            binaryMode = false;
        } else if (string (argv[i]) == "-b") {
            binaryMode = true;
        } else if (string(argv[i]) == "-l") {
            if (i + 1 < argc) {
                languageId = argv[++i];
            } else {
                showEnglishHelp(cerr);
                return 1;
            }
        } else if (string(argv[i]) == "-o"){
            if (i + 1 < argc) {
                outputFilename = argv[++i];
            } else {
                showEnglishHelp(cerr);
                return 1;
            }
        }
        else {
            if (numInputFiles == 0) {
                ficheros = new char* [argc - i];
            }
            ficheros[numInputFiles++] = argv[i];
        }
    }

    BigramCounter counter;
    Language language;

    for (int i = 0; i < numInputFiles; ++i) {
        counter.calculateFrequencies(ficheros[i]);
    }

    language = counter.toLanguage();
    language.setLanguageId(languageId);
    language.sort();
    language.save(outputFilename);
    cout<<"algo"<<endl;

    delete[] ficheros;
}

