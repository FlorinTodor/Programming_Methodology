/*
 * Metodología de la Programación: Language2
 * Curso 2022/2023
 */

/**
 * @file Language.h
 * @author Silvia Acid Carrillo <acid@decsai.ugr.es>
 * @author Andrés Cano Utrera <acu@decsai.ugr.es>
 * @author Luis Castillo Vidal <L.Castillo@decsai.ugr.es>
 *
 * Created on 29 January 2023, 11:00
 */

#ifndef LANGUAGE_H
#define LANGUAGE_H


#include <iostream>
#include "../include/BigramFreq.h"
#include "../include/Bigram.h"

/**
 * @class Language
 * @brief It defines a model for a given language. It contains a vector of
 * pairs Bigram-frequency (objects of the class BigramFreq) and an identifier
 * (string) of the language.
 */

/**
 * @author Florin Emanuel Todor
 */

class Language {
public:

    /**
     * @brief Base constructor. It builds a Language object with "unknown" as
     * identifier, and an empty vector of pairs Bigram-frequency.
     */
    Language();

    /**
     * @brief It builds a Language object with "unknow" as
     * identifier, and a vector of @p numberBigrams pairs Bigram-frequency.
     * Each pair will be initialized as "__" for the Bigram and 0 for the
     * frequency.
     * @throw std::out_of_range Throws a std::out_of_range exception if
     * @p numberBigrams > @p DIM_VECTOR_BIGRAM_FREQ or numberBigrams<0
     * @param numberBigrams The number of bigrams to use in this Language.
     * Input parameter
     */
    Language(int numberBigrams);

    /**
     *@brief Constructor de copia
     * @param other objeto del cual se copian sus datos
     */
    Language(const Language &other);

    /**
     *@brief Destructor
     */
    ~Language();

    /**
     * @brief Returns the identifier of this language object.
     * Query method.
     * @return A const reference to the identifier of this language object.
     */
    std::string getLanguageId() const;

    /**
     * @brief Sets a new identifier for this language object.
     * Modifier method.
     * @param id The new identifier. Input parameter
     */
    void setLanguageId(std::string &id);

    /**
     * @brief Sets a new identifier for this language object.
     *
     * @param id
     */
    void set_Identificador(std::string &id);

    /**
     * @brief Gets a const reference to the BigramFreq at the given position
     * of the vector in this object.
     * Query method
     * @param index the position to consider. Input parameter
     * @throw std::out_of_range Throws an std::out_of_range exception if the
     * given index is not valid
     * @return A const reference to the BigramFreq at the given position
     */
    const BigramFreq &at(int index) const;

    /**
     * @brief Gets a reference to the BigramFreq at the given position of the
     * vector in this object.
     * Query and modifier method
     * @param index the position to consider. Input parameter
     * @throw std::out_of_range Throws an std::out_of_range exception if the
     * given index is not valid
     * @return A reference to the BigramFreq at the given position
     */
    BigramFreq &at(int index);

    /**
     * @brief Gets the number of BigramFreq objects.
     * Query method
     * @return The number of BigramFreq objects
     */
    int getSize() const;

    /**
     * @brief Searchs the given bigram in the list of bigrams in this
     * Language. If found, it returns the position where it was found. If not,
     * it returns -1. We consider that position 0 is the one of the first
     * bigram in the list of bigrams and this->getSize()-1 the one of the last
     * bigram.
     * Query method
     * @param bigram A bigram. Input parameter
     * @pre The list of bigrams should be ordered in decreasing order of
     * frequency. This is not checked in this method.
     * @return If found, it returns the position where the bigram
     * was found. If not, it returns -1
     */
    int findBigram(Bigram bigram) const;

    /**
     * @brief Obtains a string with the following content:
     * - In the first line, the number of bigrams in this Language
     * - In the following lines, each one of the pairs bigram-frequency
     * (separated by a whitespace).
     * Query method
     * @return A string with the number of bigrams and the list of pairs of
     * bigram-frequency in the object
     */
    std::string toString() const;

    /**
     * @brief Sort the vector of BigramFreq in decreasing order of frequency.
     * If two BigramFreq objects have the same frequency, then the alphabetical
     * order of the bigrams of those objects will be considered (the object
     * with a bigram that comes first alphabetically will appear first)
     * Modifier method
     */
    void sort();

    /**
     * @brief Saves this Language object in the given file.
     * Query method
     * @param fileName A c-string with the name of the file where this Language
     * object will be saved. Input parameter
     * @throw std::ios_base::failure Throws a std::ios_base::failure exception
     * if the given file cannot be opened or if an error occurs while writing
     * to the file
     */
    void save(char fileName[]) const;

    /**
     * @brief Loads into this object the Language object stored in the given
     * file
     * Modifier method
     * @param fileName A c-string with the name of the file where the Language
     * will be stored. Input parameter
     * @throw std::out_of_range Throws a std::out_of_range exception if the
     * number of bigrams in the given file, cannot be allocated in this Language
     * because it exceeds the maximum capacity
     * @throw std::ios_base::failure Throws a std::ios_base::failure exception
     * if the given file cannot be opened or if an error occurs while reading
     * from the file
     * @throw throw std::invalid_argument Throws a std::invalid_argument if
     * an invalid magic string is found in the given file
     */
    void load(char fileName[]);

    /**
     * @brief Appends a copy of the given BigramFreq to this Language object.
     * If the bigram is found in this object, then its frequency is increased
     * with the one of the given BigramFreq object. If not, a copy of the
     * given BigramFreq object is appended to the end of the list of
     * BigramFreq objects in this Language.
     * Modifier method
     * @param bigramFreq The BigramFreq to append to this object. Input parameter
     */
    void append(BigramFreq bigramFreq);

    /**
     * @brief Appends to this Language object, the list of pairs
     * bigram-frequency contained in @p language.
     * Modifier method
     * @param language A Language object. Input parameter
     */
    void join(Language language);

    /**
     * @brief Gets the distance between this Language object (\f$L_1\f$) and
     * the given one @p otherLanguage (\f$L_2\f$).
     * The distance between two Languages \f$L_1\f$ and \f$L_2\f$ is
     * calculated in the following way:
     * \f$d = \frac{ \sum_{bigram_i(L_1)} | rank_{bigram_i(L_1)}^{L_1} -
     * rank_{bigram_i(L_1)}^{L_2} | }{size(L_1) * size(L_1)}\f$,
     * where \f$bigram_i(L_j)\f$ is the bigram \f$i\f$ of the Language \f$L_j,
     * j \in \{1, 2\}\f$ and \f$rank_{bigram_i(L_j)}^{L_k}\f$ is the ranking
     * of the bigram \f$i\f$ of the Language \f$L_j, j \in \{1, 2\}\f$ in the
     * Language \f$L_k\f$.
     * The rank of a bigram is the position in which it
     * appears in the list of BigramFreq. We consider 0 as the
     * first position (rank equals to 0). When calculating
     * \f$rank_{bigram_i(L_1)}^{L_2}\f$, if the bigram \f$bigram_i(L_1)\f$
     * does not appears in the Language \f$L_2\f$ we consider that the rank
     * is equals to the size of Language \f$L_1\f$.
     * @param otherLanguage A Language object
     * @pre The list of bigrams of this and otherLanguage should be ordered in
     * decreasing order of frequency. This is not checked in this method.
     * @throw Throws a std::invalid_argument exception if the implicit object
     * (*this) is empty, that is, it does not have any bigram.
     * @return The distance between this Language object and the given
     * one @p otherLanguage.
     */
    double getDistance(const Language &otherLanguage) const;


    /**
     * @brief Swaps the elements at positions @p first and @p second in the given
     * array of BigramFreq
     * @param first the position of the first element to be swaped. Input parameter
     * @param second the position of the second element to be swaped. Input parameter
     * @throw Throws a std::out_of_range exception if first or second are positions
     * out of the range of the given array
    */
    void swapElementsArrayBigramFreq(int first, int second);
    /**
     * @brief Realiza la copia de un objeto Language al actual
     * @param other objeto del cual se copia sus datos
     * @return referencia al nuevo objeto
     */

    /**
     * @brief Sobrecarga del operadorr de asignacion
     * @param other objeto del cual se les copia sus datos
     * @return Referencia del objeto con los datos copiados de other
     */
    Language &operator=(const Language &other);


    /**
     * @brief Overloading of the [] operator for Language class
     * @param index index of the element. Input parameter
     * @return A reference to the BigramFreq object at position @p index
     */
    BigramFreq const  &operator[](int index) const ;



    /**
     * @brief Overloading of the += operator with a Language parameter.
     * For each bigram in the given Language @p language, if that bigram is
     * found in this object, then its frequency is increased with the one in
     * @p language. If not, a copy of the bigram-pair is appended to the end
     * of the list of BigramFreq objects in this Language.
     * @param language A Language object. Input parameter
     * @return A reference to this object.
     */
    Language & operator+=(Language &language);

    /**
 * @brief Set a size for this language object
 * Modifier method
 * @param i The new size. Input parameter
 */
    void setSize(int i);
//DECLARADO AMBOS OPERADORES DENTRO DE LA CLASE Y FRIEND PARA PODER USAR LAS VARIABLES PRIVADAS DE LA CLASE LANGUAGE, PARA SU USO EN MEMORIA DINAMICA
    /**
 * @brief Overloading of the stream insertion operator for Language class
 * @param os The output stream to be used
 * @param language the Language object. Input parameter
 * @return @p os A reference to the output stream
 */
 friend std::ostream &operator<<(std::ostream &os, const Language &language);

/**
 * @brief Overloading of the stream extraction operator for Language class
 * throw std::out_of_range Throws a std::out_of_range if the number of bigrams
 * read from the file is negative.
 * @param is The input stream to be used
 * @param language the Language object. Output parameter
 * @return @p is A reference to the input stream
 */
   friend  std::istream &operator>>(std::istream &is, Language &language);



private:
    std::string identicador; //CREADO PARA SABER EN QUE FORMATO VAMOS A GUARDAR LOS ARCHIVOS, PARA COLOCAR SU CABECERA
    std::string _languageId; ///< language identifier
    BigramFreq *_vectorBigramFreq; ///< array of BigramFreq
    int _size; ///< Number of elements in _vectorBigramFreq
    static const std::string MAGIC_STRING_T; ///< A const string with the magic string for text files
    static const std::string MAGIC_STRING_B; ///< A const string with the magic string for binary files


    /**
     * @brief allocate function
     * @param i size for this language object
     *
     */
    void allocate(int i = 0);

    /**
     * @brief deallocate fuction, se basa en liberar memoria dinamica
     */
    void deallocate();

    /**
     * @brief Reserva memoria dinámica
     * @param i Tamaño para memoria dinámica
     * @return devuelve la dirección de memoria de donde comienza
     */
    friend BigramFreq *reservarmemoria(int i);

    /**
     * @brief Funcion que se basa en copiar los datos de other, dicha función se llama en el operador de asignacion
     * @param other objeto Language del que se va a copiar sus datos
     * @return devuelve la dirección de memoria de donde comienza
     */
    Language &copy(const Language &other);



};



#endif /* LANGUAGE_H */