/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Empleados.cpp
 * 
 * 
 * Created on 11 de mayo de 2023, 8:48
 */

#include "Empleados.h"
#include <string.h>

Empleados::Empleados() {
    nombre = "";
    apellidos = "";
}

Empleados::Empleados(string name, string surname){
    nombre = name;
    apellidos = surname;
}

std::string Empleados::getNombre(){
    return nombre;
}

std::string Empleados::getApellidos(){
    return apellidos;
}

void Empleados::setNombre(string name){
    nombre = name;
}

void Empleados::setApellidos(string surname){
    apellidos = surname;
}
