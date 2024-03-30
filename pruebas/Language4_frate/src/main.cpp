/*
 * Metodología de la Programación: Language3
 * Curso 2022/2023
 */

#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include "../include/Language.h"

using namespace std;

/**
 * Shows help about the use of this program in the given output stream
 * @param outputStream The output stream where the help will be shown (for example,
 * cout, cerr, etc)
 */
void showEnglishHelp(ostream& outputStream) {
    outputStream << "Error, run with the following parameters:" << endl;
    outputStream << "language4 [-t min|max] <file1.bgr> <file2.bgr> [ ... <filen.bgr>]" << endl;
}

bool esArchivo(const string& fileName, const string& extension) {
    if (fileName.length() >= extension.length()) {
        return (0 == fileName.compare(fileName.length() - extension.length(), extension.length(), extension));
    } else {
        return false;
    }
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

const int TAM = 100;

int main(int argc, char* argv[]) {

    const int DIM_VECTOR_BIGRAM_FREQ = 2000;
int i; int n= DIM_VECTOR_BIGRAM_FREQ;  
Language lang; 
BigramFreq bf;  
bf.setFrequency(10);
for ( i = 0; i < n; i++) { 
    Bigram b1(char((i/100)+'A'),char((i % 100)+'A'));
    bf.setBigram(b1);
    lang.append(bf); 
    
}
Bigram b2(char((i/100)+'A'),char((i MOD100)+'A'));
bf.setBigram(b2); 

lang.append(bf);

// Tienes que controlar una excepción out_of_range, estudialo.
}