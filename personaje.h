/*
 * Proyecto Batalla clase Personaje
 * Diego Méndez Morales
 * A01713173
 * 03/06/2025
 * Esta clase define objeto de tipo Personaje que apoya a las clases heredadas
 * Entrenador y Pokemon
 */

#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <string>
#include <iostream>

// Creación de la clase abstracta Personaje
class Personaje{
    
    // Declaración de variables heredables
    protected:
        std::string nombre;
        std::string lugar;
        int nivel;
        int exp;

    // Declaración de métodos heredables
    public:
        Personaje();
        Personaje(std::string nom ,std::string city ,int lv ,int xp);

        std::string get_nombre();
        std::string get_lugar();
        int get_nivel();
        int get_exp();

        void set_nombre(std::string nom);
        void set_lugar(std::string city);
        void set_nivel(int lv);
        void set_exp(int xp);

        void aumento_xp(int xp);
        void aumento_lv(int lv);
        virtual void mostrar() = 0;
};

//"========================================"
/*
 * Creacion de constructores
 * 
 * Para la creación del objeto por parámetros:
 * 
 * @param: string nombre, string lugar de origen, int nivel, int cantidad de 
 * experiencia
 * @return 
 */

Personaje::Personaje(){
    nombre = "";
    lugar = "";
    nivel = 0;
    exp = 0;
}
Personaje::Personaje(std::string nom, std::string city, int lv, int xp){
    nombre = nom;
    lugar = city;
    nivel = lv;
    exp = xp;
}

//"========================================"
/*
 * Creación de métodos de acceso
 *
 * Los getters apoyan a obtener un atributo privado de nuestro objeto
 * 
 * @param
 * @return (Dependiendo el caso): string nombre, string lugar de origen, int
 * nivel, int cantidad de experiencia
*/

std::string Personaje::get_nombre(){
    return nombre;
}
std::string Personaje::get_lugar(){
    return lugar;
}
int Personaje::get_nivel(){
    return nivel;
}
int Personaje::get_exp(){
    return exp;
}

//"========================================"
/*
 * Creación de métodos de acceso
 *
 * Setters cambiando valores originales por otros deseados
 *
 * @param (Dependiendo el caso): string nombre, string lugar de origen, int
 * nivel, int cantidad de experiencia
 * @return 
 */

void Personaje::set_nombre(std::string nom){
    nombre = nom;
}
void Personaje::set_lugar(std::string city){
    lugar = city;
}
void Personaje::set_nivel(int lv){
    nivel = lv;
}
void Personaje::set_exp(int xp){
    exp = xp;
}

//"========================================"
/*
 * Método de subida de experiencia
 *
 * Después de una batalla, cada personaje gana cierta experiencia que le ayuda
 * a subir de nivel
 *
 * @param int experiencia ganada
 * @return 
 */

void Personaje::aumento_xp(int xp){
    exp = exp + xp;
}

//"========================================"
/*
 * Método para subir de nivel
 *
 * Con cierto nivel de experiencia, el personaje puede subir de nivel
 *
 * @param int experiencia
 * @return 
 */

void Personaje::aumento_lv(int exp){
    if (exp == 100){
        nivel++;
    }
    else{
        nivel = nivel;
    }
}

//"========================================"
/*
 * Método de observación de personaje
 *
 * Método que tendra sobreescritura que apoya a visualizar atributos del 
 * personaje
 *
 * @param 
 * @return 
 */

void Personaje::mostrar(){
    std::cout << "Nombre: " << nombre << std::endl;
    std::cout << "Lugar: " << lugar << std::endl;
    std::cout << "Nivel:" << nivel << std::endl;
}

#endif