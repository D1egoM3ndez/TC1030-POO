/*
 * Proyecto Batalla clase Pokemon
 * Diego Méndez Morales
 * A01713173
 * 03/06/2025
 * Esta clase define objeto de tipo Pokemon, heredado de Personaje, donde 
 * estos son aquellos que fungen como personajes principales de la historia, 
 * donde con ayuda de objetos de tipo Ataque ayudan a combatir.
 */

#ifndef POKEMON_H
#define POKEMON_H

#include <iostream>
#include <string>

#include "personaje.h"
#include "ataque.h"
#include "tipo.h"

// Declaración de la clase Pokemon heredada de Personaje
class Pokemon: public Personaje{
    
    // Atributos propios de un Pokemon para la batalla
    private:
        float ataque;
        float defensa;
        float ataque_esp;
        float defensa_esp;
        float vida;
        float velocidad;

        std::string estado;
        std::string entrenador;

        Tipo tipo_prim;
        Tipo tipo_sec;

        Ataque ataques[4];
        int max_a;

    // Métodos propios de la clase Pokemon
    public:
        Pokemon();
        Pokemon(std::string nom, std::string city, int lv, int xp,
        float atq, float def, float atq_e, float def_e, float hp, float vel, 
        Tipo t1, Tipo t2, std::string state);
        Pokemon(std::string nom, std::string city, int lv, std::string train);

        float get_ataque();
        float get_defensa();
        float get_ataque_esp();
        float get_defensa_esp();
        float get_vida();
        float get_velocidad();
        Tipo get_tipo_prim();
        Tipo get_tipo_sec();
        Ataque get_atq(int num);
        std::string get_estado();

        void set_ataque(float atq);
        void set_defensa(float def);
        void set_ataque_esp(float atq);
        void set_defensa_esp(float def);
        void set_vida(float hp);
        void set_velocidad(float vel);
        void set_estado(std::string state);

        void agregar_ataq(Ataque ataq);
        void recibe_dano(float dano);
        void mostrar_historia();
        void mostrar_en_batalla();
        void mostrar();
};

//"========================================"
/*
 * Creación de constructores para un objeto de tipo Pokemon
*/

// Default
Pokemon::Pokemon(){
    nombre = "";
    lugar = "";
    nivel = 0;
    exp = 0;
    ataque = 0.0;
    defensa = 0.0;
    ataque_esp = 0.0;
    defensa_esp = 0.0;
    vida = 0.0;
    velocidad = 0.0;
    max_a = 0.0;
    estado = "";
}

/*
 * Constructor de objeto Pokemon que puede ser escogido para combatir en la
 * historia principal
 * 
 * @param: string nombre, string lugar, int nivel, int experiencia, 
 * float ataque, float defensa, float ataque especial, float defensa especial, 
 * float vida, float velocidad, Tipo tipo primario, Tipo tipo secundario, 
 * string estado
 * @return: Objeto Pokemon
 */

Pokemon::Pokemon(std::string nom, std::string city, int lv, int xp, float atq, 
float def, float atq_e, float def_e, float hp, float vel, Tipo t1, Tipo t2, 
std::string state){
    nombre = nom;
    lugar = city;
    nivel = lv;
    exp = xp;
    ataque = atq;
    defensa = def;
    ataque_esp = atq_e;
    defensa_esp = def_e;
    vida = hp;
    velocidad = vel;
    tipo_prim = t1;
    tipo_sec = t2;
    max_a = 0;
    estado = state;
}

/*
 * Constructor de objeto Pokemon camepón del torneo
 * 
 * @param: string nombre, string lugar, int nivel, Tipo tipo primario, 
 * Tipo tipo secundario
 * @return: Objeto Pokemon
 */

Pokemon::Pokemon(std::string nom, std::string city, int lv, std::string train){
    nombre = nom;
    lugar = city;
    nivel = lv;
    entrenador = train;
}

//"========================================"
/*
 * Creación de métodos de acceso
 *
 * Los getters apoyan a obtener un atributo privado de nuestro objeto
 * 
 * @param (Caso de querer algún ataque en especifico): int número
 * @return (Dependiendo el caso): float ataque, float defensa, 
 * float ataque especial, float defensa especial, float vida, float velocidad, 
 * Tipo tipo primario, Tipo tipo secundario, Ataque ataque, string estado
*/

float Pokemon::get_ataque(){
    return ataque;
}
float Pokemon::get_defensa(){
    return defensa;
}
float Pokemon::get_ataque_esp(){
    return ataque_esp;
}
float Pokemon::get_defensa_esp(){
    return defensa_esp;
}
float Pokemon::get_vida(){
    return vida;
}
float Pokemon::get_velocidad(){
    return velocidad;
}
Tipo Pokemon::get_tipo_prim(){
    return tipo_prim;
}
Tipo Pokemon::get_tipo_sec(){
    return tipo_sec;
}
Ataque Pokemon::get_atq(int num){
    return ataques[num];
}
std::string Pokemon::get_estado(){
    return estado;
}

//"========================================"
/*
 * Creación de métodos de acceso
 *
 * Los setters apoyan a modificar algún atributo en acciones posteriores
 * 
 * @param: float ataque, float defensa, float ataque especial, 
 * float defensa especial, float vida, float velocidad, string estado
 * @return 
*/

void Pokemon::set_ataque(float atq){
    ataque = atq;
}
void Pokemon::set_defensa(float def){
    defensa = def;
}
void Pokemon::set_ataque_esp(float atq_e){
    ataque_esp = atq_e;
}
void Pokemon::set_defensa_esp(float def_e){
    defensa_esp = def_e;
}
void Pokemon::set_vida(float hp){
    vida = hp;
}
void Pokemon::set_velocidad(float vel){
    velocidad = vel;
}
void Pokemon::set_estado(std::string state){
    estado = state;
}

//"========================================"
/*
 * Método de agregación de un objeto Ataque
 *
 * Método que nos apoya para agregar un obejto Ataque a un objeto de tipo 
 * Pokemon para poder combatir
 * 
 * @param: Ataque ataque
 * @return 
*/

void Pokemon::agregar_ataq(Ataque ataq){
    if (max_a < 4){
        ataques[max_a] = ataq;
        max_a++;
    }
}

//"========================================"
/*
 * Método principal en la historia del juego
 *
 * Método que nos apoya a recibir daño a los Pokemon para determinar cuando 
 * alguien gana la batalla
 * 
 * @param: float dano
 * @return 
*/

void Pokemon::recibe_dano(float dano){
    vida = vida - dano;
}

//"========================================"
/*
 * Método para visualizar un objeto Pokemon 
 *
 * Método que apoya al usuario para visualizar los atributos del objeto Pokemon
 * que este usando en ese momento dentro de la batalla
 * 
 * @param
 * @return 
*/

void Pokemon::mostrar_historia(){
    std::cout << "Nombre: " << nombre << std::endl;
    std::cout << "Atrapado en: " << lugar << std::endl;
    std::cout << "Nivel: " << nivel << std::endl;

    std::cout << "Movimientos: " << std::endl;

    for (int i=0; i<4; i++){
        std::cout << ataques[i].get_nombre() << std::endl;
    }
}

//"========================================"
/*
 * Método para visualizar un objeto Pokemon 
 *
 * Método que apoya al usuario para visualizar los atributos del objeto Pokemon
 * contrario que este usando el contrincante en ese momento dentro de la 
 * batalla
 * 
 * @param
 * @return 
*/

void Pokemon::mostrar_en_batalla(){
    std::cout << "Nombre: " << nombre << std::endl;
    std::cout << "Atrapado en: " << lugar << std::endl;
    std::cout << "Nivel: " << nivel << std::endl;
}

//"========================================"
/*
 * Método para visualizar un objeto Pokemon 
 *
 * Método que apoya al usuario para visualizar los atributos del objeto Pokemon
 * que haya pasado al hall de la fama como campeon
 * 
 * @param
 * @return 
*/

void Pokemon::mostrar(){
    std::cout << "Nombre: " << nombre << std::endl;
    std::cout << "Atrapado en: " << lugar << std::endl;
    std::cout << "Nivel: " << nivel << std::endl;
    std::cout << "Entrenador Original: " << entrenador << std::endl;
}

#endif 