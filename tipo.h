#ifndef TIPO_H
#define TIPO_H

#include <iostream>
#include <string>

class Tipo{
    
    private:
        std::string nombre;
        std::string ventajas[8];
        std::string resistencias[8];
        std::string inmunidades[8];
        int max_v;
        int max_r;
        int max_i;

    public:
        Tipo();
        Tipo(std::string nom);

        std::string get_nombre();
        void set_nombre(std::string nom);

        void agregar_ventaja(std::string nom);
        void agregar_resistencia(std::string nom);
        void agregar_inmunidad(std::string nom);

        float eficiencia(std::string t1);

        void mostrar_eficiencias();
};

//"========================================"

Tipo::Tipo(){
    nombre = "";
    max_v = 0;
    max_r = 0;
    max_i = 0;
}
Tipo::Tipo(std::string nom){
    nombre = nom;
    max_v = 0;
    max_r = 0;
    max_i = 0;
}

//"========================================"

std::string Tipo::get_nombre(){
    return nombre;
}

//"========================================"

void Tipo::set_nombre(std::string nom){
    nombre = nom;
}

//"========================================"

void Tipo::agregar_ventaja(std::string type){
    if (max_v >= 0 && max_v < 8){
        ventajas[max_v] = type;
        max_v++;
    }
}
void Tipo::agregar_resistencia(std::string type){
    if (max_r >= 0 && max_r < 8){
        resistencias[max_r] = type;
        max_r++;
    }
}
void Tipo::agregar_inmunidad(std::string type){
    if (max_i >= 0 && max_i < 8){
        inmunidades[max_i] = type;
        max_i++;
    }
}

//"========================================"

float Tipo::eficiencia(std::string type){
    for (int i=0; i<8; i++){
        if (ventajas[i] == type){
            return 2.0;
        }
        if (resistencias[i] == type){
            return 0.5;
        }
        if (inmunidades[i] == type){
            return 0.0;
        }
    }
    return 1.0;
}

//"========================================"

void Tipo::mostrar_eficiencias(){
    std::cout << "Las tipos que pierden contra este tipo son: " << std::endl;
    if (max_v > 0){
        for (int i=0; i<8; i++){
            if (ventajas[i] == ""){
                break;
            }
            std::cout << i << ".- " << ventajas[i] << std::endl;
        }
    }
    else{
        std::cout << "Este tipo no tiene ventaja elemental" << std::endl;
    }
    std::cout << "Los tipos que lo resisten son: " << std::endl;
    if (max_r > 0){
        for (int i=0; i<8; i++){
            if (resistencias[i] == ""){
                break;
            }
            std::cout << i << ".- " << resistencias[i] << std::endl;
        }
    }
    else{
        std::cout << "Ningun tipo lo resiste" << std::endl;
    }
    std::cout << "Los tipos que son inmunes son: " << std::endl;
    if (max_i > 0){
        for (int i=0; i<8; i++){
            if (inmunidades[i] == ""){
                break;
            }
            std::cout << i << ".-" << inmunidades[i] << std::endl;
        }
    }
    else{
        std::cout << "Ningun tipo es inmune a este tipo" << std::endl;
    }
}

#endif