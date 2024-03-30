#ifndef NOMINA_H
#define NOMINA_H
#include "Empleados.h"

using namespace std;

class Nomina{
    private:
        double sueldo_bruto;
        double sueldo_neto;
        Empleados empleado;
       
    public:
        /**
         * Constructor por defecto.
         */
        Nomina();
        
        /**
         * Constructor por argumentos
         * @param emp
         * @param sb
         * @param sn
         */
        Nomina(Empleados emp, double sb, double sn);
        
        /**
         * Devuelve el salario bruto
         * @return 
         */
        double getSalarioBruto();
        
        /**
         * Devuelve el salario neto
         * @return 
         */
        double getSalarioNeto();
        
        /**
         * Devuelve el objeto empleado relacionado con el objeto nómina
         * @return 
         */
        Empleados getEmpleados();
        
        /**
         * Modifica el salario bruto
         * @param sb
         */
        void setSalarioBruto(double sb);
        
        /**
         * Modifica el salario neto
         * @param sn
         */

        void setSalarioNeto(double sn);
        
        /**
         * Modifica el objeto empleado realcionado con el objeto nómina.
         * @param emp
         */
        
        void setEmpleadoNomina(Empleados emp);
        
        /**
         * Método que pinta por pantalla todos los datos del objeto nómina.
         */
        void toString();

};

/**
 * Método de ordenación: Debemos de ordenar alfabéticamente por nombre y en caso de ser igual por apellidos.
 * @param nom
 * @param n_util
 */
void sort(Nomina nom [], int n_util);
/**
 * Método de intercambio que nos servirá de ayuda para el métodod e ordenación.
 * @param n1
 * @param n2
 */
void swad(Nomina &n1, Nomina &n2);


/**
 * Método que transforma una cadena string en mayúsculas
 * @param cadena
 * @return 
 */

string toUpper(string cadena);

#endif /* NOMINA_H */


