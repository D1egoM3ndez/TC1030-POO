/*
 * Proyecto Batalla clase Tipo
 * Diego Méndez Morales
 * A01713173
 * 03/06/2025
 * Esta clase define objeto de tipo Tipo que ayuda al sistema RPG del juego
 */

#ifndef TIPO_H
#define TIPO_H

#include <iostream>
#include <string>

// Declaración de la clase Tipo
class Tipo{
    
    // Atributos de la clase
    private:
        std::string nombre;
        std::string ventajas[8];
        std::string resistencias[8];
        std::string inmunidades[8];
        int max_v;
        int max_r;
        int max_i;

    // Métodos de la clase
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
/*
 * Creación de constructores
*/

// Default
Tipo::Tipo(){
    nombre = "";
    max_v = 0;
    max_r = 0;
    max_i = 0;
}

/*
 * Constructor de objeto Tipo con un nombre identificador
 * 
 * @param: string nombre, string clase, Tipo tipo, float potencia, 
 * float presicion, int intentos del movimeinto
 * @return: Objeto Tipo
 */

Tipo::Tipo(std::string nom){
    nombre = nom;
    max_v = 0;
    max_r = 0;
    max_i = 0;
}

//"========================================"
/*
 * Creación de métodos de acceso
 *
 * Los getters apoyan a obtener un atributo privado de nuestro objeto
 * 
 * @param
 * @return: string nombre
*/

std::string Tipo::get_nombre(){
    return nombre;
}

//"========================================"
/*
 * Creación de métodos de acceso
 *
 * Los setters apoyan a modificar algún atributo en acciones posteriores
 * 
 * @param: string nombre
 * @return 
*/

void Tipo::set_nombre(std::string nom){
    nombre = nom;
}

//"========================================"
/*
 * Método de asignación de fortalezas del tipo
 *
 * Método que ayuda a fijar aquellas ventajas que tiene un tipo sobre otros a
 * la hora de combatir
 * 
 * @param: string type
 * @return 
*/

void Tipo::agregar_ventaja(std::string type){
    if (max_v >= 0 && max_v < 8){
        ventajas[max_v] = type;
        max_v++;
    }
}

//"========================================"
/*
 * Método de asignación de fortalezas del tipo
 *
 * Método que ayuda a fijar aquellos tipos resistentes que tiene un tipo 
 * sobre otros a la hora de combatir
 * 
 * @param: string type
 * @return 
*/

void Tipo::agregar_resistencia(std::string type){
    if (max_r >= 0 && max_r < 8){
        resistencias[max_r] = type;
        max_r++;
    }
}

//"========================================"
/*
 * Método de asignación de fortalezas del tipo
 *
 * Método que ayuda a fijar aquellos tipos imnunes sobre otros a la hora de 
 * combatir
 * 
 * @param: string type
 * @return 
*/

void Tipo::agregar_inmunidad(std::string type){
    if (max_i >= 0 && max_i < 8){
        inmunidades[max_i] = type;
        max_i++;
    }
}

//"========================================"
/*
 * Método de asignación de eficiencia de un tipo sobre otro
 *
 * Método que busca en los arreglos del tipo para pdoer determinar su
 * eficiencia sobre el tipo contrincante
 * 
 * @param: string type
 * @return: float daño
*/

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
/*
 * Método de visualización completa del objeto Tipo
 *
 * Método que ayuda a visualizar los atributos completos del objeto
 * 
 * @param
 * @return
*/

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