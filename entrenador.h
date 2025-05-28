#ifndef ENTRENADOR_H
#define ENTRENADOR_H

#include <iostream>
#include <string>
#include <vector>

#include "personaje.h"
#include "pokemon.h"

class Entrenador: public Personaje{
    
    private:
        std::vector <Pokemon> equipo;
        std::string especialidad;
        int year;

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

Entrenador::Entrenador(){
    nombre = "";
    lugar = "";
    nivel = 0;
    exp = 0;
}
Entrenador::Entrenador(std::string nom, std::string city, int lv, int xp){
    nombre = nom;
    lugar = city;
    nivel = lv;
    exp = xp;
}
Entrenador::Entrenador(std::string nom, std::string city, std::string esp, 
int num){
    nombre = nom;
    lugar = city;
    especialidad = esp;
    year = num;
}

//"========================================"

Pokemon Entrenador::get_poke(int num){
    if (num >= 0 && num < equipo.size()){
        return equipo[num];
    }
    return Pokemon();
}

//"========================================"

void Entrenador::mostrar_equipo(){
    std::cout << "El equipo esta conformado por: " << std::endl;
    for(int i=0; i<equipo.size(); i++){
        std::cout << i << ".- " << equipo[i].get_nombre() << std::endl;
    }
}

//"========================================"

void Entrenador::agregar_poke(Pokemon poke){
    equipo.push_back(poke);
}
void Entrenador::quitar_poke(int num){
    if(num == 2){
        equipo.pop_back();
    }
    else{
        equipo.erase(equipo.begin() + num);
    }
}
void Entrenador::mostrar_completo(){
    std::cout << "Nombre: " << nombre << std::endl;
    std::cout << "Lugar de origen: " << lugar << std::endl;
    std::cout << "Nivel: " << nivel << std::endl;

    std::cout << "Equipo Pokemon: " << std::endl;

    for (int i=0; i<3; i++){
        std::cout << equipo[i].get_nombre() << std::endl;
    }
}
void Entrenador::mostrar(){
    std::cout << "Nombre: " << nombre << std::endl;
    std::cout << "Lugar de origen: " << lugar << std::endl;
    std::cout << "Especialista en: " << especialidad << std::endl;
    std::cout << "Torneo de: " << year << std::endl;
}

#endif