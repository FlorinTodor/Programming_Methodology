/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nomina.cpp
 * Author: gabrielfp
 * 
 * Created on 11 de mayo de 2023, 8:48
 */

#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include "Nomina.h"
#include <iostream>

using namespace std;

Nomina::Nomina() {
    sueldo_bruto = 0;
    sueldo_neto = 0;
    empleado.setNombre("");
    empleado.setApellidos("");
}

Nomina::Nomina(Empleados emp, double sb, double sn){
    sueldo_bruto = sb;
    sueldo_neto = sn;
    empleado.setNombre(emp.getNombre());
    empleado.setApellidos(emp.getApellidos());
}

double Nomina::getSalarioBruto(){
    return sueldo_bruto;
}

double Nomina::getSalarioNeto(){
    return sueldo_neto;
}

Empleados Nomina::getEmpleados(){
    return empleado;
}

void Nomina::setSalarioBruto(double sb) {
    sueldo_bruto = sb;
}

void Nomina::setSalarioNeto(double sn){
    sueldo_neto = sn;
}

void Nomina::setEmpleadoNomina(Empleados emp){
    empleado.setNombre(emp.getNombre());
    empleado.setApellidos(emp.getApellidos());
}

void Nomina::toString(){
    cout << toUpper(empleado.getNombre()) << " " << toUpper(empleado.getApellidos()) << "\nSalario Bruto -> " <<
            sueldo_bruto << "\nSalario Neto -> " << sueldo_neto << endl;
};

void sort(Nomina nom [], int n_util) {
    for(int i=0; i<n_util; ++i){
        for(int j=0; j<n_util-i-1; ++j){
            if(nom[j].getEmpleados().getNombre() > nom[j+1].getEmpleados().getNombre()){
                swad(nom[j], nom[j+1]);
            }
            
            else if(nom[j].getEmpleados().getNombre() == nom[j+1].getEmpleados().getNombre()){
                if(nom[j].getEmpleados().getApellidos() > nom[j+1].getEmpleados().getApellidos()){
                    swad(nom[j], nom[j+1]);
                }
            }
        }
    }
}

void swad(Nomina &n1, Nomina &n2){
    Nomina auxiliar;
    auxiliar = n1;
    n1 = n2;
    n2 = auxiliar;
}

string toUpper(string cadena) {
    for(int i=0; i<15; ++i){
        if(cadena[i] >= 'a' && cadena[i] <= 'z')
            cadena[i] = toupper(cadena[i]);
    }
    
    return cadena;
}







