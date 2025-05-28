#ifndef POKEMON_H
#define POKEMON_H

#include <iostream>
#include <string>

#include "personaje.h"
#include "ataque.h"
#include "tipo.h"

class Pokemon: public Personaje{
    
    private:
        float ataque;
        float defensa;
        float ataque_esp;
        float defensa_esp;
        float vida;
        float velocidad;

        std::string estado;

        Tipo tipo_prim;
        Tipo tipo_sec;

        Ataque ataques[4];
        int max_a;

    public:
        Pokemon();
        Pokemon(std::string nom, std::string city, int lv, int xp,
        float atq, float def, float atq_e, float def_e, float hp, float vel, 
        Tipo t1, Tipo t2, std::string state);
        Pokemon(std::string nom, std::string city, int lv, Tipo t1, Tipo t2);

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
Pokemon::Pokemon(std::string nom, std::string city, int lv, Tipo t1, Tipo t2){
    nombre = nom;
    lugar = city;
    nivel = lv;
    tipo_prim = t1;
    tipo_sec = t2;
}

//"========================================"

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

void Pokemon::agregar_ataq(Ataque ataq){
    if (max_a < 4){
        ataques[max_a] = ataq;
        max_a++;
    }
}
void Pokemon::recibe_dano(float dano){
    vida = vida - dano;
}
void Pokemon::mostrar_historia(){
    std::cout << "Nombre: " << nombre << std::endl;
    std::cout << "Atrapado en: " << lugar << std::endl;
    std::cout << "Nivel: " << nivel << std::endl;

    std::cout << "Movimientos: " << std::endl;

    for (int i=0; i<4; i++){
        std::cout << ataques[i].get_nombre() << std::endl;
    }
}
void Pokemon::mostrar_en_batalla(){
    std::cout << "Nombre: " << nombre << std::endl;
    std::cout << "Atrapado en: " << lugar << std::endl;
    std::cout << "Nivel: " << nivel << std::endl;
}
void Pokemon::mostrar(){
    std::cout << "Nombre: " << nombre << std::endl;
    std::cout << "Atrapado en: " << lugar << std::endl;
    std::cout << "Nivel: " << nivel << std::endl;
    std::cout << "Tipo primario: " << tipo_prim.get_nombre() << std::endl;

    std::string tip = tipo_sec.get_nombre();

    if(tip == "Nulo"){
        std::cout << "Tipo secundario: " << "N/A" << std::endl;
    }
    else{
        std::cout << "Tipo secundario: " << tipo_sec.get_nombre() << std::endl;
    }
}

#endif 