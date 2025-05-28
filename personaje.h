#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <string>
#include <iostream>

class Personaje{
    
    protected:
        std::string nombre;
        std::string lugar;
        int nivel;
        int exp;

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
        virtual void mostrar();
};

//"========================================"

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

void Personaje::aumento_xp(int xp){
    exp = exp + xp;
}
void Personaje::aumento_lv(int exp){
    if (exp == 100){
        nivel++;
    }
    else{
        nivel = nivel;
    }
}
void Personaje::mostrar(){
    std::cout << "Nombre: " << nombre << std::endl;
    std::cout << "Lugar: " << lugar << std::endl;
    std::cout << "Nivel:" << nivel << std::endl;
}

#endif