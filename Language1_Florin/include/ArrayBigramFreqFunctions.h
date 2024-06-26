
/*
 * Metodología de la Programación: Language1
 * Curso 2022/2023
 */

/** 
 * @file ArrayBigramFreqFunctions.h
 * @author Silvia Acid Carrillo <acid@decsai.ugr.es>
 * @author Andrés Cano Utrera <acu@decsai.ugr.es>
 * @author Luis Castillo Vidal <L.Castillo@decsai.ugr.es>
 * 
 * Created on 7 February 2023, 19:45
 */
#ifndef ARRAYBIGRAMFREQFUNCTIONS_H
#define ARRAYBIGRAMFREQFUNCTIONS_H

#include"BigramFreq.h"

/**
 * @author Florin Emanuel Todor
 */


/**
 * @brief Reads the number of used elements and the elements of an array of
 * BigramFreq
 * If @p nElements is greater than @p dim, then only @p dim elements are read
 * If @p nElements is negative, then zero elements are read
 * @param array The array where the elements will be stored. Output parameter
 * @param dim The capacity of the array. Input parameter
 * @param nElements The number of elements used by the array. Output parameter
*/
void readArrayBigramFreq(BigramFreq array[], const int dim, int nElements);

/**
 * @brief Prints in the standard output the number of used elements and the 
 * elements of an array of BigramFreq 
 * @param array The array of BigramFreq to be printed. Input parameter
 * @param nElements The number of elements used by the array. Input parameter
*/
void printArrayBigramFreq( BigramFreq array[],  int nElements);

/**
 * @brief Swaps the elements at positions @p first and @p second in the given
 * array of BigramFreq
 * @param array The array of BigramFreq. Input/Output parameter
 * @param nElements The number of elements used by the array. Input parameter
 * @param first the position of the first element to be swaped. Input parameter
 * @param second the position of the second element to be swaped. Input parameter
 * @throw Throws a std::out_of_range exception if first or second are positions 
 * out of the range of the given array
*/
void swapElementsArrayBigramFreq(BigramFreq array[], int nElements, int first, int second);


/**
 * @brief Sorts the given array of BigramFreq in decreasing order of 
 * frequency
 * @param array The array of BigramFreq. Input/Output parameter
 * @param nElements The number of elements used by the array. Input parameter
*/
void sortArrayBigramFreq(BigramFreq array[], int nElements);

/**
 * @brief Converts to uppercase all the bigrams within the given array
 * @param array An array of BigramFreq objects. Input/Output parameter
 * @param nElements The number of elements in the array. Input parameter
 */
void toUpperArrayBigramFreq(BigramFreq array[], int nElements);

#endif /* ARRAYBIGRAMFREQFUNCTIONS_H */

