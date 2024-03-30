/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nomina.cpp
 * Author: Florin Emanuel Todor
 * 
 * Created on 11 de mayo de 2023, 8:48
 */

#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include "Nomina.h"
#include <iostream>
#include <functional>

using namespace std;

Nomina::Nomina(){
    this->sueldo_bruto=0;
    this->sueldo_neto=0;
    this->empleado;
}
Nomina::Nomina(Empleados &emp, const double sb, const double sn){
    this->empleado = emp;
    this->sueldo_bruto = sb;
    this->sueldo_neto = sn;
}
double Nomina::getSalarioBruto(){
    return this->sueldo_bruto;
}
double Nomina::getSalarioNeto(){
    return this->sueldo_neto;
}
Empleados & Nomina::getEmpleados(){
    return this->empleado;
}
void Nomina::setSalarioBruto(const double sb){
    this->sueldo_bruto= sb;
}
void Nomina::setSalarioNeto(const double sn){
    this->sueldo_neto= sn;
}
void Nomina::setEmpleadoNomina(const Empleados & emp){
    this->empleado = emp;
}

string toUpper(string cadena){
    for(int i=0; i<cadena.size(); ++i){
        cadena[i] = toupper(cadena[i]);
    }
    return cadena;
}
void Nomina::toString(){
    cout<<toUpper(this->empleado.getNombre()) <<" " <<toUpper(this->empleado.getApellidos())<<endl;
    cout<<"Salario Bruto -> "<<this->sueldo_bruto<<endl;
    cout<<"Salario Neto -> "<<this->sueldo_neto<<endl;
}

void swad(Nomina &n1, Nomina &n2){
    Nomina aux;
    aux = n1;
    n1 = n2;
    n2= aux;
}

void sort(Nomina nom [], int n_util){
    for (int i=0; i< n_util -1 ; ++i){
        for(int j=0 ; j < n_util -i -1 ; ++j){
             if(nom[j].getEmpleados().getNombre() > nom[j+1].getEmpleados().getNombre()){
                 swad(nom[j], nom[j+1]);
             }
             if (nom[j].getEmpleados().getNombre() == nom[j+1].getEmpleados().getNombre()){
                 if(nom[j].getEmpleados().getApellidos() > nom[j+1].getEmpleados().getApellidos()){
                     swad(nom[j],nom[j+1]);
                 }
             }
        }
       
    }
}








