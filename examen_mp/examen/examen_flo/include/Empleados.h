#include <string>
#ifndef EMPLEADOS_H
#define EMPLEADOS_H

using namespace std;

class Empleados{
    private:
       string nombre;
       string apellidos;
        
    public:
        /**
         * Constructor por defecto.
         */
        Empleados();
        
        /**
         * Constructor por argumentos.
         * @param name
         * @param surname
         */
        Empleados(string name, string surname);
        
        /**
         * devuelve el nombre del objeto.
         * @return 
         */
        string  getNombre();
        
        /**
         * devuelve los apellidos del objeto.
         * @return 
         */
        string getApellidos();
        
        /**
         * modifica el nombre del objeto.
         * @param name
         */
        void setNombre(const string name);
        
        /**
         * modifca los apellidos del objeto.
         * @param surname
         */
        
        void setApellidos(const string surname);
        
        
};

#endif /* EMPLEADOS_H */
