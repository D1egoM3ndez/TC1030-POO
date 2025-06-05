/*
 * Proyecto Batalla clase Ataque
 * Diego Méndez Morales
 * A01713173
 * 03/06/2025
 * Esta clase define objeto de tipo Ataque que apoya a la Pokemon para combatir
 */

#ifndef ATAQUE_H
#define ATAQUE_H

#include <iostream>
#include <string>

#include "tipo.h"

// Declaración de la clase Ataque
class Ataque{

    // Atributos propios
    private:
        std::string nombre;
        std::string clase;
        Tipo tipo;
        float potencia;
        float presicion;
        int pp; // número de veces que puede usar el movimiento
    
    // Métodos propios
    public:
        Ataque();
        Ataque(std::string nom, std::string cl, Tipo type, float pot, 
        float pre, int move);

        std::string get_nombre();
        std::string get_clase();
        Tipo get_tipo();
        float get_potencia();
        float get_presicion();
        int get_pp();

        void set_nombre(std::string nom);
        void set_clase(std::string cl);
        void set_potencia(float pot);
        void set_presicion(float pre);
        void set_pp(int move);

        void mostrar();
};

//"========================================"
/*
 * Creación de constructores
*/

// Default
Ataque::Ataque(){
    nombre = "";
    clase = "";
    potencia = 0.0;
    presicion = 0.0;
    pp = 0;
}

/*
 * Constructor de objeto Ataque que ayuda en el momento de la batalla
 * 
 * @param: string nombre, string clase, Tipo tipo, float potencia, 
 * float presicion, int intentos del movimeinto
 * @return: Objeto Ataque
 */

Ataque::Ataque(std::string nom, std::string cl, Tipo type, float pot, 
float pre, int move){
    nombre = nom;
    clase = cl;
    tipo = type;
    potencia = pot;
    presicion = pre;
    pp = move;
}

//"========================================"
/*
 * Creación de métodos de acceso
 *
 * Los getters apoyan a obtener un atributo privado de nuestro objeto
 * 
 * @param
 * @return (Dependiendo el caso): string nombre, string clase, Tipo tipo, 
 * float potencia, float presicion, int pp
*/

std::string Ataque::get_nombre(){
    return nombre;
}
std::string Ataque::get_clase(){
    return clase;
}
Tipo Ataque::get_tipo(){
    return tipo;
}
float Ataque::get_potencia(){
    return potencia;
}
float Ataque::get_presicion(){
    return presicion;
}
int Ataque::get_pp(){
    return pp;
}

//"========================================"
/*
 * Creación de métodos de acceso
 *
 * Los setters apoyan a modificar algún atributo en acciones posteriores
 * 
 * @param: string nombre, string clase, float potencia, float presicion, 
 * int pp
 * @return 
*/

void Ataque::set_nombre(std::string nom){
    nombre = nom;
}
void Ataque::set_clase(std::string cl){
    clase = cl;
}
void Ataque::set_potencia(float pot){
    potencia = pot;
}
void Ataque::set_presicion(float pre){
    presicion = pre;
}
void Ataque::set_pp(int move){
    pp = move;
}

//"========================================"
/*
 * Método de visualización del objeto de tipo Ataque
 *
 * Método para poder visualizar los atributos del objeto Ataque 
 * 
 * @param
 * @return 
*/

void Ataque::mostrar(){
    std::cout << "Nombre: " << nombre << std::endl;
    std::cout << "Tipo: " << tipo.get_nombre() << std::endl;
    std::cout << "Clase: " << clase << std::endl;
    std::cout << "Potencia: " << potencia << std::endl;
    std::cout << "Presicion: " << presicion << std::endl;
    std::cout << "PP: " << pp << std::endl;
}

#endif