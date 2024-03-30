/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* *****************************************************************************
 * Ejercicio de prácticas de Metodología de la Programación Doble Grado de  
 * Informática y Administración de Empresas
 * 
 * Rellene sus datos personales.
 * 
 * Alumno: Gabriel Filipov Petkov
 * Correo Electrónico: gabrielfp@correo.ugr.es
 * 
 ******************************************************************************/

#include <cstdlib>
#include <iostream>
#include <fstream>

#include "Nomina.h"

     
     
using namespace std;

const int TAM = 1005;

/*
 * 
 */
int main(int argc, char** argv) {
    
   /**
    * Creación de las variables necesarias 
    * Recuerda  que usamos memoría dinámica
    */
    Nomina *nom = new Nomina[TAM];
    Empleados emp;
    int tam= 0;
    string name;
    string surname;
    double sb;
    double sn;
    
    /**
    * Lectura de los datos leídos desde el fichero
    */
    ifstream ficheroEntrada(argv[1]);
    
    ficheroEntrada >> tam;
    
    for(int i=0; i<tam; ++i){
        //Nombre
        ficheroEntrada >> name;
        emp.setNombre(name);
        
        //Apellidos
        ficheroEntrada >> surname;
        emp.setApellidos(surname);
        
        //Empleado
        nom[i].setEmpleadoNomina(emp);
        
        //Salario bruto
        ficheroEntrada >> sb;
        nom[i].setSalarioBruto(sb);
        
        //Salario neto
        ficheroEntrada >> sn;
        nom[i].setSalarioNeto(sn);
    }
   
    
    /**
      Ordenar los datos utilizando el método correspondiente.
    */
    sort(nom, tam);
    
   
    /**
     Mostrar los datos ordenados    
     */ 
    for(int i=0; i<tam; ++i){
        nom[i].toString();
        cout << endl;
    }
    
    delete [] nom;
       
    return 0;
}
