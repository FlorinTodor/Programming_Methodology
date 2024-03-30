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

#include <iostream>
#include <fstream>
#include "Nomina.h"

     
     
using namespace std;



int main(int argc, char** argv) {
    
   /**
    * Creación de las variables necesarias 
    * Recuerda  que usamos memoría dinámica
    */
    int empleados=0;
    fstream fichero;
    string nombre;
    string apellidos;
    double sb;
    double sn;
    Nomina * nomina=nullptr;
    Empleados aux;
    
    
    
    
    /**
    * Lectura de los datos leídos desde el fichero
    */
    fichero.open(argv[1]);
    if(fichero){
   
        fichero >>empleados;
        nomina = new Nomina [empleados];
        for(int i=0; i< empleados;++i){
            fichero >> nombre;
            fichero >> apellidos;
            aux.setNombre(nombre);
            aux.setApellidos(apellidos);
            fichero >> sb;
            fichero >> sn;
            nomina[i].setEmpleadoNomina(aux);
            nomina[i].setSalarioBruto(sb);
            nomina[i].setSalarioNeto(sn);
            
        }
        
    }
    else{
        throw ios::failure("Error en la apertura del fichero");
    }
    
    
   
    
    /**
      Ordenar los datos utilizando el método correspondiente.
    */
    sort(nomina,empleados);
    
    
    
   
    /**
     Mostrar los datos ordenados    
     */ 
    for(int i=0; i< empleados; ++i){
        nomina[i].toString();
        cout<<"------------------------------------------------------------------------------------------------------"<<endl;
        cout<<endl;
    }
    
    
    delete[] nomina;
    return 0;
   
}
