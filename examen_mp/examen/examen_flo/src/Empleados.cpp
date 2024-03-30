/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Empleados.cpp
 * Author: Florin Emanuel Todor
 * 
 * Created on 11 de mayo de 2023, 8:48
 */

#include "Empleados.h"
#include <string.h>

Empleados::Empleados(){
    this->nombre="";
    this->apellidos="";
}
Empleados::Empleados( string name, string surname){
    this->nombre=name;
    this->apellidos=surname;
}

string Empleados::getNombre(){
    return this->nombre;
}
string Empleados::getApellidos(){
    return this->apellidos;
}

void Empleados::setNombre(const string name){
    this->nombre=name;
}
void Empleados::setApellidos(const string surname){
    this->apellidos=surname;
}