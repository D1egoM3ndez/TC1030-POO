/*
 * Proyecto Batalla clase Entrenador
 * Diego Méndez Morales
 * A01713173
 * 03/06/2025
 * Esta clase define objeto de tipo Entrenador, heredado de Personaje, donde 
 * cada uno tiene un equipo  de objetos de tipo Pokemon para jugar
 */

#ifndef ENTRENADOR_H
#define ENTRENADOR_H

#include <iostream>
#include <string>
#include <vector>

#include "personaje.h"
#include "pokemon.h"

// Declaración de la clase Entrenador heredada de clase Personaje
class Entrenador: public Personaje{
    
    // Atributos propios de la clase
    private:
        std::vector <Pokemon> equipo; // Equipo jugable dentro de la batalla
        std::string especialidad;
        int year;

    // Métodos propios de la clase
    public:
        Entrenador();
        Entrenador(std::string nom, std::string city, int lv, int xp);
        Entrenador(std::string nom, std::string city, std::string esp, 
        int num);

        std::string get_especialidad();
        Pokemon get_poke(int num);

        void set_especialidad(std::string esp);

        void mostrar_equipo();

        void quitar_poke(int num);
        void agregar_poke(Pokemon p);
        void mostrar_completo();
        void mostrar();
};

//"========================================"
/*
 * Creación de constructores para objetos de tipo Entrenador
*/

// Default
Entrenador::Entrenador(){
    nombre = "";
    lugar = "";
    nivel = 0;
    exp = 0;
}

/*
 * Constructor de objeto Entrenador cuya función será el de participante 
 * en la historia del juego
 * 
 * @param: string nombre, string lugar, int nivel, int experiencia
 * @return: Objeto Entrenador
 */

Entrenador::Entrenador(std::string nom, std::string city, int lv, int xp){
    nombre = nom;
    lugar = city;
    nivel = lv;
    exp = xp;
}

/*
 * Constructor de objeto Entrenador cuya función será el visualizar anteriores
 * campeones de la historia del juego
 * 
 * @param: string nombre, string lugar, string especialidad, 
 * int año de competencia 
 * @return: Objeto Entrenador
 */

Entrenador::Entrenador(std::string nom, std::string city, std::string esp, 
int num){
    nombre = nom;
    lugar = city;
    especialidad = esp;
    year = num;
}

//"========================================"
/*
 * Método de consulta de algún Pokemon del equipo del Entrenador
 *
 * Ayuda para escoger un Pokemon del vector equipo del entrenador
 * 
 * @param: int número
 * @return: Objeto Pokemon
 */

Pokemon Entrenador::get_poke(int num){
    if (num >= 0 && num < equipo.size()){
        return equipo[num];
    }
    return Pokemon();
}

//"========================================"
/*
 * Método de consulta del equipo del Entrenador
 *
 * Visualización completa de los Pokemon que forman parte del equipo de un 
 * Entrenador
 * 
 * @param
 * @return
 */

void Entrenador::mostrar_equipo(){
    std::cout << "El equipo esta conformado por: " << std::endl;
    for(int i=0; i<equipo.size(); i++){
        std::cout << i << ".- " << equipo[i].get_nombre() << std::endl;
    }
}

//"========================================"
/*
 * Método de agregación de un objeto Pokemon
 *
 * Método que mediante la agregación de un objeto de tipo Pokemon añade uno de 
 * estos al equipo del Entrenador
 * 
 * @param: Pokemon poke
 * @return
 */

void Entrenador::agregar_poke(Pokemon poke){
    equipo.push_back(poke);
}

//"========================================"
/*
 * Método de eliminación de un miembro del equipo de un Entrenador
 *
 * Método que nos ayuda a remover un objeto Pokemon no deseado del equipo del
 * Entrenador
 * 
 * @param: int número
 * @return
 */

void Entrenador::quitar_poke(int num){
    if(num == 2){
        equipo.pop_back();
    }
    else{
        equipo.erase(equipo.begin() + num);
    }
}

//"========================================"
/*
 * Método de visualización del objeto Entrenador
 *
 * Visualización completa del objeto Entrenador
 * 
 * @param
 * @return
 */

void Entrenador::mostrar_completo(){
    std::cout << "Nombre: " << nombre << std::endl;
    std::cout << "Lugar de origen: " << lugar << std::endl;
    std::cout << "Nivel: " << nivel << std::endl;

    std::cout << "Equipo Pokemon: " << std::endl;

    for (int i=0; i<3; i++){
        std::cout << equipo[i].get_nombre() << std::endl;
    }
}

//"========================================"
/*
 * Método de visualización del objeto Entrenador
 *
 * Visualización completa del objeto Entrenador en el hall de la fama de la
 * historia del juego
 * 
 * @param
 * @return
 */

void Entrenador::mostrar(){
    std::cout << "Nombre: " << nombre << std::endl;
    std::cout << "Lugar de origen: " << lugar << std::endl;
    std::cout << "Especialista en: " << especialidad << std::endl;
    std::cout << "Torneo de: " << year << std::endl;
}

#endif