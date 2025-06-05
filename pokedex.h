/*
 * Proyecto Batalla clase Pokedex
 * Diego Méndez Morales
 * A01713173
 * 03/06/2025
 * Esta clase define objeto de tipo Pokedex, el cual sirve como un centro de 
 * recopilación de datos de tanto Enytrenadores como Pokemon que haya visto el
 * jugador, en el caso de la historia, que haya entrado al hall de la fama.
 */

#ifndef POKEDEX.H
#define POKEDEX.H

#include <iostream>
#include <string>

#include "pokemon.h"
#include "entrenador.h"

// Declaración de la clase Pokedex
class Pokedex{

    // Atributos propios
    private:
        std::string nombre;
        Personaje* guia[1000];
        int max_p;

    // Métodos propios
    public:
        Pokedex();
        Pokedex(std::string);
        std::string get_nombre();
        void crea_objetos();
        void imprime_objetos();
};

//"========================================"
/*
 * Creación de constructores para Pokedex
*/

// Default
Pokedex::Pokedex(){
    nombre = "";
    max_p = 0;
}

/*
 * Constructor de objeto Pokedex
 * 
 * @param: string nombre
 * @return: Objeto Pokedex
 */

Pokedex::Pokedex(std::string nom){
    nombre = nom;
    max_p = 0;
}

//"========================================"
/*
 * Creación de métodos de acceso
 *
 * Los getters apoyan a obtener un atributo privado de nuestro objeto
 * 
 * @param
 * @return: string nombre;
*/

std::string Pokedex::get_nombre(){
    return nombre;
}

//"========================================"
/*
 * Creación de método para tener objetos guardados
 * 
 * Como en la historia ya habran pasado estos entrenadores, los datos que ya 
 * estan guardados en la pokedex ya deben de estar guardados al momento de la 
 * creación.
 * 
 * @param
 * @return
 */

void Pokedex::crea_objetos(){

    Personaje* scyther = new Pokemon("Scyther", "Ruta 15", 50, "Tracey");
    guia[max_p] = scyther;
    max_p++;
    Personaje* mrmime = new Pokemon("Mr.Mime", "Ruta 14", 50, "Delia");
    guia[max_p] = mrmime;
    max_p++;
    Personaje* jynx = new Pokemon("Jynx", "Islas Espuma", 50, "Jessie");
    guia[max_p] = jynx;
    max_p++;
    Personaje* pinsir = new Pokemon("Pinsir", "Ruta 14", 50, "Steven");
    guia[max_p] = pinsir;
    max_p++;
    Personaje* tauros = new Pokemon("Tauros", "Zona Zafari", 50, "Ash");
    guia[max_p] = tauros;
    max_p++;
    Personaje* electabuzz = new Pokemon("Electabuzz", "Central Electrica", 50,
    "Cassy");
    guia[max_p] = electabuzz;
    max_p++;
    Personaje* magmar = new Pokemon("Magmar", "Mansion Pokemon", 50, "Blaine");
    guia[max_p] = magmar;
    max_p++;

    Personaje* brock = new Entrenador("Brock", "Ciudad Plateada", "tipo Roca",
    1995);
    guia[max_p] = brock;
    max_p++;
    Personaje* misty = new Entrenador("Misty", "Cuidad Celeste", "tipo Agua",
    1995);
    guia[max_p] = misty;
    max_p++;
    Personaje* gardenia = new Entrenador("Gardenia", "Ciudad Vetusta",
    "tipo planta", 2006);
    guia[max_p] = gardenia;
    max_p++;
    Personaje* maximo = new Entrenador("Maximo", "Ciudad Algaria", 
    "tipo Acero", 2002);
    guia[max_p] = maximo;
    max_p++;
}

//"========================================"
/*
 * Método de visualización del objeto
 * 
 * Método con polimorfismo para visualizar los datos guardados en el objeto
 * creado
 * 
 * @param
 * @return
 */

void Pokedex::imprime_objetos(){
    for(int i=0; i<max_p; i++){
        guia[i] -> mostrar();
        std::cout << "==============================" << std::endl;
    }
}

#endif