#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <cstdlib>
#include <ctime>

#include "personaje.h"
#include "entrenador.h"
#include "pokemon.h"
#include "ataque.h"
#include "tipo.h"

//"========================================"
//Validacion de entrada de numeros

int valida_num(int vmin,int vmax){
    std::string dec;
    bool entrada = false;

    while(entrada == false){
        std::cout << "Introduce tu entrada: " << std::endl;
        std::cin >> dec;

        if(dec.size() == 1 && std::isdigit(dec[0])){
            int num = std::stoi(dec);
            if(num >= vmin && num <= vmax){
                entrada = true;
                return num;
            }
            else{
                std::cout << "Entrada invalida" << std::endl;
            }
            }
        else{
            std::cout << "Entrada invalida" << std::endl;
        }
    }
}

//"========================================"

float calcula_dano(Pokemon atacante, Pokemon defensor, Ataque ataq){
    std::string clase = ataq.get_clase();
    float atq = 0.0;
    float def = 0.0;
    
    if (clase == "Fisico"){
        atq = atacante.get_ataque();
        def = defensor.get_defensa();
    }
    else{
        atq = atacante.get_ataque_esp();
        def = defensor.get_defensa_esp();
    }

    std::string tipo1_a = atacante.get_tipo_prim().get_nombre();
    std::string tipo2_a = atacante.get_tipo_sec().get_nombre();

    std::string tipo1_d = defensor.get_tipo_prim().get_nombre();
    std::string tipo2_d = defensor.get_tipo_sec().get_nombre();

    Tipo ataque = ataq.get_tipo();
    std::string tip_ataq = ataq.get_tipo().get_nombre();

    float comp1 = ataque.eficiencia(tipo1_d);
    float comp2 = ataque.eficiencia(tipo2_d);

    float compatibilidad = comp1 * comp2;

    float dano;

    float random = ((std::rand() % 16) * 0.01) + .85;

    dano = (((2.0/5.0) * atacante.get_nivel()) + 2) * (atq / def) * 
    (ataq.get_potencia() / 50) + 2;

    float stab;

    if(tip_ataq == tipo1_a || tip_ataq == tipo2_a){
        stab = 1.5;
    }
    else{
        stab = 1.0;
    }

    float dano_final = dano * compatibilidad * random * stab;

    if(compatibilidad == 4.0){
        std::cout << "Es super eficaz!!!!" << std::endl;
    }
    if(compatibilidad == 2.0){
        std::cout << "Es eficaz" << std::endl;
    }
    if(compatibilidad == 0.5){
        std::cout << "Es poco eficaz" << std::endl;
    }
    if(compatibilidad == 0.0){
        std::cout << "No ha hecho efecto este ataque" << std::endl;
    }

    if(random == 1.00){
        std::cout << "Ha sido un GOLPE CRITICO!!" << std::endl;
    }

    return dano_final;
}

//"========================================"
int pelea(Pokemon pok, Pokemon bot){
    float vel = pok.get_velocidad();
    float vel_bot = bot.get_velocidad();
    int res = 0;

    while(pok.get_vida() > 0 && bot.get_vida() > 0){

        std::cout << "Que quieres hacer...??" << std::endl;
        std::cout << "0.- Ver Info" << std::endl;
        std::cout << "1.- Atacar" << std::endl;
        std::cout << "2.- Huir" << std::endl;

        int dec = valida_num(0,2);

        if(dec == 0){
            std::cout << "0.- Info del oponente" << std::endl;
            std::cout << "1.- Info personal" << std::endl;
            std::cout << "2.- Regresar" << std::endl;

            int num = valida_num(0,2);

            if(num == 0){
                bot.mostrar_en_batalla();
            }
            if(num == 1){
                pok.mostrar();
            }
        }
        if(dec == 2){
            std::cout << "Estas seguro de querer abandonar..?" << std::endl;
            std::cout << "No habra experiencia ganada" << std::endl;
            std::cout << "0.- Aceptar" << std::endl;
            std::cout << "1.- Cancelar" << std::endl;

            int numero = valida_num(0,1);

            if(numero == 0){
                std::cout << "Lo lamento, pero no puedes huir de una batalla"
                " contra otro entrenador" << std::endl;
            }
        }
        if(dec == 1){
            std::cout << "Que ataque quires usar...?" << std::endl;
            for(int i=0; i<4; i++){
                std::cout << i << ".-" << pok.get_atq(i).get_nombre() 
                << std::endl;
            }
            
            int atc = valida_num(0,3);
            int alet = std::rand() % 4;
            
            Ataque ataque_bat = pok.get_atq(atc);
            Ataque ataque_bot = bot.get_atq(alet);

            if(vel > vel_bot){
                std::cout << pok.get_nombre() << " ha utilizado " 
                << ataque_bat.get_nombre() << std::endl; 
                
                float dano = calcula_dano(pok,bot,ataque_bat);
                bot.recibe_dano(dano);

                if(bot.get_vida() <= 0){
                    std::cout << bot.get_nombre() << " se ha debilitado" 
                    << std::endl;
                    res = 1;
                    break;
                }
                
                std::cout << "Vida de " << bot.get_nombre() << " = " 
                << bot.get_vida() << std::endl;
                
                std::cout << bot.get_nombre() << " ha utilizado " 
                << ataque_bot.get_nombre() << std::endl;
                
                float dano2 = calcula_dano(bot,pok,ataque_bot);
                pok.recibe_dano(dano2);

                if(pok.get_vida() <= 0){
                    std::cout << pok.get_nombre() << " se ha debilitado" 
                    << std::endl;
                    res = 0;
                    break;
                }
                
                std::cout << "Vida de " << pok.get_nombre() << " = " 
                << pok.get_vida() << std::endl;

            }
            if(vel_bot > vel){
                std::cout << bot.get_nombre() << " ha utilizado " 
                << ataque_bot.get_nombre() << std::endl;
                
                float dano = calcula_dano(bot,pok,ataque_bot);
                pok.recibe_dano(dano);

                if(pok.get_vida() <= 0){
                    std::cout << pok.get_nombre() << " se ha debilitado" 
                    << std::endl;
                    res = 0;
                    break;
                }
                
                std::cout << "Vida de " << pok.get_nombre() << " = " 
                << pok.get_vida() << std::endl;

                std::cout << pok.get_nombre() << " ha utilizado " 
                << ataque_bat.get_nombre() << std::endl; 
                
                float dano2 = calcula_dano(pok,bot,ataque_bat);
                bot.recibe_dano(dano2);

                if(bot.get_vida() <= 0){
                    std::cout << bot.get_nombre() << " se ha debilitado" 
                    << std::endl;
                    res = 1;
                    break;
                }
                
                std::cout << "Vida de " << bot.get_nombre() << " = " 
                << bot.get_vida() << std::endl;
            }

            if(vel == vel_bot){
                int priority = std::rand() % 2;

                if(priority == 1){

                    std::cout << pok.get_nombre() << " ha utilizado " 
                    << ataque_bat.get_nombre() << std::endl; 
                
                    float dano = calcula_dano(pok,bot,ataque_bat);
                    bot.recibe_dano(dano);

                    if(bot.get_vida() <= 0){
                        std::cout << bot.get_nombre() << " se ha debilitado" 
                        << std::endl;
                        res = 1;
                        break;
                    }
                
                    std::cout << "Vida de " << bot.get_nombre() << " = " 
                    << bot.get_vida() << std::endl;

                    std::cout << bot.get_nombre() << " ha utilizado " 
                    << ataque_bot.get_nombre() << std::endl;
                
                    float dano2 = calcula_dano(bot,pok,ataque_bot);
                    pok.recibe_dano(dano2);

                    if(pok.get_vida() <= 0){
                        std::cout << pok.get_nombre() << " se ha debilitado" 
                        << std::endl;
                        res = 0;
                        break;
                    }
                
                    std::cout << "Vida de " << pok.get_nombre() << " = " 
                    << pok.get_vida() << std::endl;

                }
                if(priority == 0){

                    std::cout << bot.get_nombre() << " ha utilizado " 
                    << ataque_bot.get_nombre() << std::endl;
                
                    float dano = calcula_dano(bot,pok,ataque_bot);
                    pok.recibe_dano(dano);

                    if(pok.get_vida() <= 0){
                        std::cout << pok.get_nombre() << " se ha debilitado" 
                        << std::endl;
                        res = 0;
                        break;
                    }
                
                    std::cout << "Vida de " << pok.get_nombre() << " = " 
                    << pok.get_vida() << std::endl;

                    std::cout << pok.get_nombre() << " ha utilizado " 
                    << ataque_bat.get_nombre() << std::endl; 
                
                    float dano2 = calcula_dano(pok,bot,ataque_bat);
                    bot.recibe_dano(dano2);

                    if(bot.get_vida() <= 0){
                        std::cout << bot.get_nombre() << " se ha debilitado" 
                        << std::endl;
                        res = 0;
                        break;
                    }
                    
                    std::cout << "Vida de " << bot.get_nombre() << " = " 
                    << bot.get_vida() << std::endl;
                }
            }
        }

    }
    return res;
}

//"========================================"
//Validacion de entrada de nombres

Pokemon valida_entrada(std::vector<Pokemon> pokedex){
    std::string nom;
    bool entrada = false;
    Pokemon poksec;

    while(entrada == false){
        
        std::cout << "Introduce el nombre de un Pokemon: ";
        std::cin >> nom;

        //Vuelvo minuculas a las entradas
        for(int i=0; i<nom.size(); i++){
            nom[i] = std::tolower(nom[i]);
        }

        //Busco el nombre de cada Pokemon y lo comparo con la entrada
        for(int i=0; i<pokedex.size(); i++){
            std::string nombre = pokedex[i].get_nombre();
        
            nombre[0] = std::tolower(nombre[0]);

            if(nom == nombre){
                nom[0] = std::toupper(nom[0]);
                entrada = true;
                poksec = pokedex[i];
                return poksec;
            }
        }

        std::cout << "Ese Pokemon no se ha identificado, intentalo de nuevo"
        << std::endl;
    }
}

//"========================================"
//Historia principal de la pelea

int historia(Entrenador player, Entrenador bot){
    int win = 0;
    int res = 0;

    std::cout << "Arbitro: " << std::endl;
    std::cout << "Entrandores!!!, saquen a su primer Pokemon" << std::endl;
    player.mostrar_equipo();

    int dec1 = valida_num(0,2);
    Pokemon pok1 = player.get_poke(dec1);
    player.quitar_poke(dec1);

    int ale1 = rand() % 3;
    Pokemon pok1_bot = bot.get_poke(ale1);
    bot.quitar_poke(ale1);

    std::cout << "Arbitro: " << std::endl;
    std::cout << "Perfecto, por un lado tenemos a " << player.get_nombre() <<
    " con su " << pok1.get_nombre() << std::endl;
    std::cout << "Y en la otra esquina tenemos a " << bot.get_nombre() <<
    " con su " << pok1_bot.get_nombre() << std::endl;
    std::cout << "Todos listos...." << std::endl;
    std::cout << "3!" << std::endl;
    std::cout << "2!!" << std::endl;
    std::cout << "1!!!" << std::endl;
    std::cout << "Que comience la batalla!!!!" << std::endl;

    int battle = pelea(pok1,pok1_bot);

    std::cout << "Arbitro: " << std::endl;
    
    if(battle == 1){
        std::cout << pok1_bot.get_nombre() << " no puede seguir luchando" 
        << std::endl;
        win = win + 1;
    }
    else{
        std::cout << pok1.get_nombre() << " no puede seguir luchando" 
        << std::endl;
    }

    std::cout << "Entrnadores!!!, saquen a su segundo Pokemon" << std::endl;
    std::cout << "Elige alguno de tus Pokemon restantes: " << std::endl;

    player.mostrar_equipo();

    int dec2 = valida_num(0,1);
    Pokemon pok2 = player.get_poke(dec2);
    player.quitar_poke(dec2);

    int ale2 = rand() % 2;
    Pokemon pok2_bot = bot.get_poke(ale2);
    bot.quitar_poke(ale2);

    std::cout << "Arbitro: " << std::endl;
    std::cout << "Ahora en cancha tenemos a " << player.get_nombre() <<
    " con su " << pok2.get_nombre() << std::endl;
    std::cout << "Y en la otra esquina tenemos a " << bot.get_nombre()
    << " con " << pok2_bot.get_nombre() << std::endl;
    std::cout << "Todo listo?" << std::endl;
    std::cout << "Empezamos en 3!" << std::endl;
    std::cout << "2!!" << std::endl;
    std::cout << "1!!!" << std::endl;
    std::cout << "Que inicie la batalla!!!" << std::endl;

    int battle2 = pelea(pok2,pok2_bot);

    std::cout << "Arbitro: " << std::endl;
    
    if(battle2 == 1){
        std::cout << pok2_bot.get_nombre() << " no puede seguir luchando" 
        << std::endl;
        win = win + 1;
    }
    else{
        std::cout << pok2.get_nombre() << " no puede seguir luchando" 
        << std::endl;
    }

    std::cout << "Estamos a punto de acabar de acabar nuestra la batalla"
    << std::endl;
    std::cout << "Entrenadores!!!, saquen a su ultimo Pokemon.." << std::endl;

    Pokemon pok3 = player.get_poke(0);
    player.quitar_poke(0);

    Pokemon pok3_bot = bot.get_poke(0);
    bot.quitar_poke(0);

    std::cout << "Lucharan!!!!" << std::endl;
    std::cout << "El " << pok3.get_nombre() << " de " << player.get_nombre() 
    << std::endl;
    std::cout << "contra el " << pok3_bot.get_nombre() << " de " 
    << bot.get_nombre() << std::endl;

    std::cout << "Todo listo!!! La batalla comienza en..." << std::endl;
    std::cout << "3!" << std::endl;
    std::cout << "2!!" << std::endl;
    std::cout << "1!!!" << std::endl;

    int battle3 = pelea(pok3,pok3_bot);

    std::cout << "Arbitro: " << std::endl;
    if(battle3 == 1){
        std::cout << pok3_bot.get_nombre() << " no puede seguir luchando" 
        << std::endl;
        win = win + 1;
    }
    else{
        std::cout << pok3.get_nombre() << " no puede seguir luchando" 
        << std::endl;
    }

    std::cout << "El ganador de esta pelea es..." << std::endl;

    if(win >= 2){
        std::cout << player.get_nombre() << " !!!!!" << std::endl;
        res = 1;
    }
    else{
        std::cout << bot.get_nombre() << " !!!!!" << std::endl;
        res = 0;
    }

    return res;
}

//"========================================"

int main(){
    
    srand(time(0));

//"========================================"
// Creacion de tipos
 
    Tipo normal("Normal");
    Tipo lucha("Lucha");
    Tipo volador("Volador");
    Tipo veneno("Veneno");
    Tipo tierra("Tierra");
    Tipo roca("Roca");
    Tipo bicho("Bicho");
    Tipo fantasma("Fantasma");
    Tipo acero("Acero");
    Tipo fuego("Fuego");
    Tipo agua("Agua");
    Tipo planta("Planta");
    Tipo electrico("Electrico");
    Tipo psiquico("Psiquico");
    Tipo hielo("Hielo");
    Tipo dragon("Dragon");
    Tipo siniestro("Siniestro");
    Tipo hada("Hada");

    Tipo nulo("Nulo");

//"========================================"
//Efectividades del tipo Normal

    normal.agregar_resistencia("Roca");
    normal.agregar_resistencia("Acero");

    normal.agregar_inmunidad("Fantasma");

//"========================================"
//Efectividades del tipo Lucha

    lucha.agregar_ventaja("Normal");
    lucha.agregar_ventaja("Roca");
    lucha.agregar_ventaja("Acero");
    lucha.agregar_ventaja("Hielo");
    lucha.agregar_ventaja("Siniestro");

    lucha.agregar_resistencia("Volador");
    lucha.agregar_resistencia("Veneno");
    lucha.agregar_resistencia("Bicho");
    lucha.agregar_resistencia("Psiquico");
    lucha.agregar_resistencia("Hada");

    lucha.agregar_inmunidad("Fantasma");

//"========================================"
//Efectividades del tipo Volador

    volador.agregar_ventaja("Lucha");
    volador.agregar_ventaja("Bicho");
    volador.agregar_ventaja("Planta");

    volador.agregar_resistencia("Roca");
    volador.agregar_resistencia("Acero");
    volador.agregar_resistencia("Electrico");

//"========================================"
//Efectividades del tipo Veneno

    veneno.agregar_ventaja("Planta");
    veneno.agregar_ventaja("Hada");

    veneno.agregar_resistencia("Veneno");
    veneno.agregar_resistencia("Tierra");
    veneno.agregar_resistencia("Roca");
    veneno.agregar_resistencia("Fantasma");

    veneno.agregar_inmunidad("Acero");

//"========================================"
//Efectividades del tipo Tierra

    tierra.agregar_ventaja("Veneno");
    tierra.agregar_ventaja("Roca");
    tierra.agregar_ventaja("Acero");
    tierra.agregar_ventaja("Fuego");
    tierra.agregar_ventaja("Electrico");

    tierra.agregar_resistencia("Bicho");
    tierra.agregar_resistencia("Planta");

    tierra.agregar_inmunidad("Volador");

//"========================================"
//Efectividades del tipo Roca

    roca.agregar_ventaja("Volador");
    roca.agregar_ventaja("Bicho");
    roca.agregar_ventaja("Fuego");
    roca.agregar_ventaja("Hielo");

    roca.agregar_resistencia("Lucha");
    roca.agregar_resistencia("Tierra");
    roca.agregar_resistencia("Acero");

//"========================================"
//Efectividades del tipo Bicho

    bicho.agregar_ventaja("Planta");
    bicho.agregar_ventaja("Psiquico");
    bicho.agregar_ventaja("Siniestro");

    bicho.agregar_resistencia("Lucha");
    bicho.agregar_resistencia("Volador");
    bicho.agregar_resistencia("Veneno");
    bicho.agregar_resistencia("Fantasma");
    bicho.agregar_resistencia("Acero");
    bicho.agregar_resistencia("Fuego");
    bicho.agregar_resistencia("Hada");

//"========================================"
//Efectividades del tipo Fantasma

    fantasma.agregar_ventaja("Fantasma");
    fantasma.agregar_ventaja("Psiquico");

    fantasma.agregar_inmunidad("Normal");
    fantasma.agregar_inmunidad("Siniestro");

//"========================================"
//Efectividades del tipo Acero

    acero.agregar_ventaja("Roca");
    acero.agregar_ventaja("Hielo");
    acero.agregar_ventaja("Hada");

    acero.agregar_resistencia("Acero");
    acero.agregar_resistencia("Fuego");
    acero.agregar_resistencia("Agua");
    acero.agregar_resistencia("Electrico");

//"========================================"
//Efectividades del tipo Fuego

    fuego.agregar_ventaja("Bicho");
    fuego.agregar_ventaja("Acero");
    fuego.agregar_ventaja("Planta");
    fuego.agregar_ventaja("Hielo");

    fuego.agregar_resistencia("Roca");
    fuego.agregar_resistencia("Fuego");
    fuego.agregar_resistencia("Agua");
    fuego.agregar_resistencia("Dragon");

//"========================================"
//Efectividades del tipo Agua

    agua.agregar_ventaja("Tierra");
    agua.agregar_ventaja("Roca");
    agua.agregar_ventaja("Fuego");

    agua.agregar_resistencia("Agua");
    agua.agregar_resistencia("Planta");
    agua.agregar_resistencia("Dragon");

//"========================================"
//Efectividades del tipo Planta

    planta.agregar_ventaja("Tierra");
    planta.agregar_ventaja("Roca");
    planta.agregar_ventaja("Agua");

    planta.agregar_resistencia("Volador");
    planta.agregar_resistencia("Veneno");
    planta.agregar_resistencia("Bicho");
    planta.agregar_resistencia("Acero");
    planta.agregar_resistencia("Fuego");
    planta.agregar_resistencia("Planta");
    planta.agregar_resistencia("Dragon");

//"========================================"
//Efectividades del tipo Electrico

    electrico.agregar_ventaja("Volador");
    electrico.agregar_ventaja("Agua");

    electrico.agregar_resistencia("Planta");
    electrico.agregar_resistencia("Electrico");
    electrico.agregar_resistencia("Dragon");

    electrico.agregar_inmunidad("Tierra");

//"========================================"
//Efectividades del tipo Psiquico

    psiquico.agregar_ventaja("Lucha");
    psiquico.agregar_ventaja("Veneno");

    psiquico.agregar_resistencia("Acero");
    psiquico.agregar_resistencia("Psiquico");

    psiquico.agregar_inmunidad("Siniestro");

//"========================================"
//Efectividades del tipo Hielo

    hielo.agregar_ventaja("Volador");
    hielo.agregar_ventaja("Tierra");
    hielo.agregar_ventaja("Planta");
    hielo.agregar_ventaja("Dragon");

    hielo.agregar_resistencia("Acero");
    hielo.agregar_resistencia("Fuego");
    hielo.agregar_resistencia("Agua");
    hielo.agregar_resistencia("Hielo");

//"========================================"
//Efectividades del tipo Dragon

    dragon.agregar_ventaja("Dragon");

    dragon.agregar_resistencia("Acero");

    dragon.agregar_inmunidad("Hada");

//"========================================"
//Efectividades del tipo Siniestro

    siniestro.agregar_ventaja("Fantasma");
    siniestro.agregar_ventaja("Psiquico");

    siniestro.agregar_resistencia("Lucha");
    siniestro.agregar_resistencia("Siniestro");
    siniestro.agregar_resistencia("Hada");

//"========================================"
//Efectividades del tipo Hada

    hada.agregar_ventaja("Lucha");
    hada.agregar_ventaja("Dragon");
    hada.agregar_ventaja("Siniestro");

    hada.agregar_resistencia("Veneno");
    hada.agregar_resistencia("Acero");
    hada.agregar_resistencia("Fuego");

//"========================================"
//Creacion de Ataques de tipo Normal

    Ataque atq1_n("Golpe Cuerpo", "Fisico", normal, 85.0, 100.0, 15);
    Ataque atq2_n("Fuerza", "Fisico", normal, 80.0, 100.0, 15);
    Ataque atq3_n("Triataque", "Especial", normal, 80.0, 100.0, 10);
    Ataque atq4_n("Pisoton", "Fisico", normal, 65.0, 100.0, 20);

//"========================================"
//Creacion de Ataques de tipo Lucha

    Ataque atq1_l("Fuerza Bruta", "Fisco", lucha, 100.0, 100.0, 5);
    Ataque atq2_l("Puno Drenaje", "Fisco", lucha, 75.0, 100.0, 10);
    Ataque atq3_l("Demolicion", "Fisco", lucha, 75.0, 100.0, 15);
    Ataque atq4_l("Plancha Corporal", "Fisico", lucha, 80.0, 100.0, 10);

//"========================================"
//Creacion de Ataques de tipo Volador

    Ataque atq1_vo("Vuelo", "Fisico", volador, 90.0, 95.0, 15);
    Ataque atq2_vo("Golpe Aereo", "Fisico", volador, 60.0, 90.0, 20);
    Ataque atq3_vo("Tajo Aereo", "Especial", volador, 75.0, 95.0, 15);

//"========================================"
//Creacion de Ataques de tipo Veneno

    Ataque atq1_ve("Bomba Acida", "Especial", veneno, 40.0, 100.0, 20);
    Ataque atq2_ve("Onda Toxica", "Especial", veneno, 95.0, 100.0, 10);
    Ataque atq3_ve("Puya Nociva", "Fisico", veneno, 80.0, 100.0, 20);
    Ataque atq4_ve("Carga Toxica", "Especial", veneno, 65.0, 100.0, 10);

//"========================================"
//Creacion de Ataques de tipo Tierra

    Ataque atq1_ti("Terratemblor", "Fisico", tierra, 60.0, 100.0, 20);
    Ataque atq2_ti("Tierra Viva", "Especial", tierra, 90.0, 100.0, 10);

//"========================================"
//Creacion de Ataques de tipo Roca

    Ataque atq1_r("Tumba Rocas", "Fisico", roca, 60.0, 95.0, 15);
    Ataque atq2_r("Roca Afilada", "Fisico", roca, 100.0, 80.0, 5);

//"========================================"
//Creacion de Ataques de tipo Bicho

    Ataque atq1_b("Megacuerno", "Fisico", bicho, 120.0, 85.0, 10);
    Ataque atq2_b("Tijera X", "Fisico", bicho, 80.0, 100.0, 15);

//"========================================"
//Creacion de Ataques de tipo Fantasma

    Ataque atq1_fa("Garra Umbria", "Fisico", fantasma, 70.0, 100.0, 15);
    Ataque atq2_fa("Bola Sombra", "Especial", fantasma, 80.0, 100.0, 15);

//"========================================"
//Creacion de Ataques de tipo Acero

    Ataque atq1_ac("Foco resplandor", "Especial", acero, 80.0, 100.0, 10);
    Ataque atq2_ac("Cola Ferrea", "Fisico", acero, 100.0, 75.0, 15);
    Ataque atq3_ac("Ala de Acero", "Fisico", acero, 70.0, 90.0, 25);
    Ataque atq4_ac("Cabeza de Hierro", "Fisico", acero, 80.0, 100.0, 15);
    Ataque atq5_ac("Giro Bola", "Fisico", acero, 70.0, 100.0, 5);

//"========================================"
//Creacion de Ataques de tipo Fuego

    Ataque atq1_fu("Nitrocarga", "Fisico", fuego, 50.0, 100.0, 20);
    Ataque atq2_fu("Lanzallamas", "Especial", fuego, 90.0, 100.0, 15);

//"========================================"
//Creacion de Ataques de tipo Agua

    Ataque atq1_ag("Hidrobomba", "Especial", agua, 110.0, 80.0, 5);

//"========================================"
//Creacion de Ataques de tipo Planta

    Ataque atq1_p("Hoja Afilada", "Fisico", planta, 55.0, 95.0, 25);
    Ataque atq2_p("Energibola", "Especial", planta, 90.0, 100.0, 10);

//"========================================"
//Creacion de Ataques de tipo Electrico

    Ataque atq1_e("Rayo", "Especial", electrico, 90.0, 100.0, 15);

//"========================================"
//Creacion de Ataques de tipo Psiquico

    Ataque atq1_ps("Cabezazo Zen", "Fisico", psiquico, 80.0, 90.0, 15);
    Ataque atq2_ps("Psiquico", "Especial", psiquico, 90.0, 100.0, 10);

//"========================================"
//Creacion de Ataques de tipo Hielo

    Ataque atq1_hi("Rayo Hielo", "Especial", hielo, 90.0, 100.0, 10);

//"========================================"
//Creacion de Ataques de tipo Dragon

    Ataque atq1_d("Garra Dragon", "Fisico", dragon, 80.0, 100.0, 15);
    Ataque atq2_d("Pulso Dragon", "Especial", dragon, 85.0, 100.0, 10);
    Ataque atq3_d("Cola Dragon", "Fisico", dragon, 60.0, 90.0, 10);

//"========================================"
//Creacion de Ataques de tipo Siniestro

    Ataque atq1_s("Mordisco", "Fisico", siniestro, 60.0, 100.0, 25);
    Ataque atq2_s("Buena Baza", "Fisico", siniestro, 60.0, 100.0, 10);
    Ataque atq3_s("Ladron", "Fisico", siniestro, 60.0, 100.0, 25);
    Ataque atq4_s("Vendetta", "Fisico", siniestro, 50.0, 100.0, 10);
    Ataque atq5_s("Juego Sucio", "Fisico", siniestro, 95.0, 100.0, 15);

//"========================================"
//Creacion de Ataques de tipo Hada

    Ataque atq1_ha("Carantona", "Fisico", hada, 90.0, 90.0, 10);
    Ataque atq2_ha("Fuerza Lunar", "Especial", hada, 95.0, 100.0, 15);
    Ataque atq3_ha("Brillo Magico", "Especial", hada, 85.0, 100.0, 10);
    Ataque atq4_ha("Voz Cautivadora", "Especial", hada, 50.0, 100.0, 15);

//"========================================"
//Creacion de Pokemon

    Pokemon venusaur("Venusaur", "Lab. Pokemon", 50, 0, 82.0, 83.0, 100.0, 
    100.0, 80.0, 80.0, planta, veneno, "Normal");
    venusaur.agregar_ataq(atq1_p);
    venusaur.agregar_ataq(atq1_ve);
    venusaur.agregar_ataq(atq1_ti);
    venusaur.agregar_ataq(atq1_n);

//"========================================"

    Pokemon charizard("Charizard", "Lab. Pokemon", 50, 0, 84.0, 78.0, 109.0, 
    85.0, 78.0, 100.0, fuego, volador, "Normal");
    charizard.agregar_ataq(atq1_d);
    charizard.agregar_ataq(atq2_fu);
    charizard.agregar_ataq(atq1_vo);
    charizard.agregar_ataq(atq1_fu);

//"========================================"

    Pokemon blastoise("Blastoise", "Lab. Pokemon", 50, 0, 83.0, 100.0, 85.0, 
    105.0, 79.0, 78.0, agua, nulo, "Normal");
    blastoise.agregar_ataq(atq1_ac);
    blastoise.agregar_ataq(atq1_ag);
    blastoise.agregar_ataq(atq1_s);
    blastoise.agregar_ataq(atq1_hi);

//"========================================"

    Pokemon raichu("Raichu", "Central de Energia", 50, 0, 90.0, 55.0, 90.0, 
    80.0, 60.0, 110.0, electrico, nulo, "Normal");
    raichu.agregar_ataq(atq1_e);
    raichu.agregar_ataq(atq2_ac);
    raichu.agregar_ataq(atq1_n);
    raichu.agregar_ataq(atq1_ha);

//"========================================"

    Pokemon nidoking("Nidoking", "Ruta 22", 50, 0, 102.0, 77.0, 85.0, 75.0, 
    81.0, 85.0, veneno, tierra, "Normal");
    nidoking.agregar_ataq(atq1_b);
    nidoking.agregar_ataq(atq2_ve);
    nidoking.agregar_ataq(atq2_ti);
    nidoking.agregar_ataq(atq1_r);

//"========================================"

    Pokemon nidoqueen("Nidoqueen", "Ruta 22", 50, 0, 92.0, 87.0, 75.0, 85.0, 
    90.0, 76.0, veneno, tierra, "Normal");
    nidoqueen.agregar_ataq(atq1_l);
    nidoqueen.agregar_ataq(atq2_ve);
    nidoqueen.agregar_ataq(atq2_ti);
    nidoqueen.agregar_ataq(atq1_fa);

//"========================================"

    Pokemon beedrill("Beedrill", "Bosque Verde", 50, 0, 80.0, 40.0, 45.0, 
    80.0, 65.0, 75.0, bicho, veneno, "Normal");
    beedrill.agregar_ataq(atq3_ve);
    beedrill.agregar_ataq(atq2_vo);
    beedrill.agregar_ataq(atq2_b);
    beedrill.agregar_ataq(atq2_s);

//"========================================"

    Pokemon pidgeot("Pidgeot", "Ruta 2", 50, 0, 80.0, 75.0, 70.0, 70.0, 83.0, 
    101.0, normal, volador, "Normal");
    pidgeot.agregar_ataq(atq1_vo);
    pidgeot.agregar_ataq(atq3_ac);
    pidgeot.agregar_ataq(atq3_s);
    pidgeot.agregar_ataq(atq3_vo);

//"========================================"

    Pokemon clefable("Clefable", "Monte Lunar", 50, 0, 70.0, 73.0, 95.0, 90.0,
    95.0, 60.0, hada, nulo, "Normal");
    clefable.agregar_ataq(atq2_ha);
    clefable.agregar_ataq(atq1_ps);
    clefable.agregar_ataq(atq3_ha);
    clefable.agregar_ataq(atq2_fa);

//"========================================"

    Pokemon alakazam("Alakazam", "Ruta 24", 50, 0, 50.0, 45.0, 135.0, 95.0, 
    55.0, 120.0, psiquico, nulo, "Normal");
    alakazam.agregar_ataq(atq2_l);
    alakazam.agregar_ataq(atq2_ps);
    alakazam.agregar_ataq(atq3_ha);
    alakazam.agregar_ataq(atq2_p);

//"========================================"

    Pokemon machamp("Machamp", "Ruta 10", 50, 0, 130.0, 80.0, 65.0, 85.0, 90.0,
    55.0, lucha, nulo, "Normal");
    machamp.agregar_ataq(atq2_r);
    machamp.agregar_ataq(atq2_l);
    machamp.agregar_ataq(atq4_s);
    machamp.agregar_ataq(atq2_n);

//"========================================"

    Pokemon gengar("Gengar", "Torre Pokemon", 50, 0, 65.0, 60.0, 130.0, 75.0, 
    60.0, 110.0, fantasma, veneno, "Normal");
    gengar.agregar_ataq(atq2_fa);
    gengar.agregar_ataq(atq4_ve);
    gengar.agregar_ataq(atq5_s);
    gengar.agregar_ataq(atq2_ps);

//"========================================"

    Pokemon golem("Golem", "Cueva Roca", 50, 0, 120.0, 130.0, 55.0, 65.0, 
    80.0, 45.0, roca, tierra, "Normal");
    golem.agregar_ataq(atq2_r);
    golem.agregar_ataq(atq1_ti);
    golem.agregar_ataq(atq3_l);
    golem.agregar_ataq(atq4_ac);

//"========================================"

    Pokemon magneton("Magneton", "Central de Energia", 50, 0, 60.0, 95.0, 
    120.0, 70.0, 50.0, 70.0, electrico, acero, "Normal");
    magneton.agregar_ataq(atq3_n);
    magneton.agregar_ataq(atq1_ac);
    magneton.agregar_ataq(atq1_e);
    magneton.agregar_ataq(atq5_ac);

//"========================================"

    Pokemon lapras("Lapras", "Pueblo Auriga", 50, 0, 85.0, 80.0, 85.0, 95.0, 
    130.0, 60.0, agua, hielo, "Normal");
    lapras.agregar_ataq(atq1_ag);
    lapras.agregar_ataq(atq1_hi);
    lapras.agregar_ataq(atq4_ha);
    lapras.agregar_ataq(atq2_d);

//"========================================"

    Pokemon kangaskhan("Kangaskhan", "Zona Zafari", 50, 0, 95.0, 80.0, 40.0, 
    80.0, 105.0, 90.0, normal, nulo, "Normal");
    kangaskhan.agregar_ataq(atq1_ti);
    kangaskhan.agregar_ataq(atq2_ac);
    kangaskhan.agregar_ataq(atq1_r);
    kangaskhan.agregar_ataq(atq4_n);

//"========================================"

    Pokemon dragonite("Dragonite", "Cueva Celeste", 50, 0, 134.0, 95.0, 100.0, 
    100.0, 91.0, 80.0, dragon, volador, "Normal");
    dragonite.agregar_ataq(atq3_d);
    dragonite.agregar_ataq(atq1_vo);
    dragonite.agregar_ataq(atq4_l);
    dragonite.agregar_ataq(atq2_fu);

//"========================================"
//Creacion de Entrenadores

    Entrenador rojo("Rojo", "Meseta Anil", 7, 1500);
        rojo.agregar_poke(charizard);
        rojo.agregar_poke(raichu);
        rojo.agregar_poke(nidoking);

    Entrenador azul("Azul", "Pueblo Paleta", 7, 1500);
        azul.agregar_poke(blastoise);
        azul.agregar_poke(golem);
        azul.agregar_poke(pidgeot);

    Entrenador verde("Verde", "Cueva Celeste", 7, 1500);
        verde.agregar_poke(venusaur);
        verde.agregar_poke(clefable);
        verde.agregar_poke(lapras);

    Entrenador player("Player", "Pueblo Paleta", 0, 0);

//"========================================"
//Vector donde esten guardados todos los pokemon

    std::vector<Pokemon> pokedex = {venusaur,blastoise,charizard,raichu,
    beedrill,pidgeot,magneton,nidoking,nidoqueen,gengar,machamp,golem,
    alakazam,clefable,lapras,kangaskhan,dragonite};

//"========================================"
//Vector donde esten guardados todos los entrenadores

    std::vector<Entrenador> trainers = {rojo,azul,verde};

//"========================================"
//Inicio del juego

    std::cout << "Bienvenido a la region de Aran, " << std::endl;
    std::cout << "donde humanos y pokemon conviven en armonia." << std::endl;
    std::cout << "Perdona el atrevimiento, pero me podrias recordar tu nombre?" 
    << std::endl;

    std::string nom;
    std::cin >> nom;
    player.set_nombre(nom);

    std::cout << "Claro!! " << player.get_nombre() << "," << std::endl;
    std::cout << "como pude olvidar tu nombre" << std::endl;

    std::cout << "Como tu sabes, un buen entrenador necesita un equipo fuerte" 
    << std::endl; 
    std::cout << "para alzarce con la victoria." << std::endl;
    std::cout << "Dime " << player.get_nombre() << std::endl;
    std::cout << "Quienes forman parte de tu equipo?" << std::endl;

    std::cout << "Escoje tres Pokemon que quieras que te ayuden:" << std::endl;

    for(int i=0; i<17; i++){
        std::cout << i << ".- " << pokedex[i].get_nombre() << std::endl;
    }

    for(int i=0; i<3; i++){
        Pokemon pok = valida_entrada(pokedex);
        player.agregar_poke(pok);
    }

    player.mostrar_equipo();

    Pokemon pok1 = player.get_poke(0);
    Pokemon pok2 = player.get_poke(1);
    Pokemon pok3 = player.get_poke(2);

    std::cout << "Ahora que estas preparado, empecemos con lo bueno" 
    << std::endl;

    std::cout << "Has sido seleccionado para participar en el torneo de" 
    " los maestros, donde se enfrentan los mejores entrenadores de todas" 
    " las regiones" << std::endl;

    std::cout << "Aceptas el reto?" << std::endl;
    std::cout << "0.- Si, estoy seguro" << std::endl;
    std::cout << "1.- Ehhhh, nop" << std::endl;

    int dec = valida_num(0,1);

    if(dec == 0){
        std::cout << "Perfecto, sabia que podia confiar en ti, continuemos"
        << std::endl;
    }
    if(dec == 1){
        std::cout << "Lo lamento pero ya te inscribi, empecemos" << std::endl;
    }

    std::cout << "Te enfrentaras en tres rondas, cada una con un entrenador"
    " diferente, tendras la oportunidad de abandonar hasta que acaba tu"
    " batalla o te quedes sin pokemon, veremos que pasa." << std::endl;

    std::cout << "Veremos a quien te enfrentaras: " << std::endl;

    int random = rand() % trainers.size();
    Entrenador prim_bot = trainers[random];
    trainers.erase(trainers.begin() + random);

    std::cout << "Tu contrincante sera: " << std::endl;

    prim_bot.mostrar();

    int hist1 = historia(player,prim_bot);

    if(hist1 == 1){
        std::cout << "Felicidades, sabia que lo podias lograr," 
        " quieres seguir participando?" << std::endl;

        std::cout << "0.- Sii, que venga el que sigue" << std::endl;
        std::cout << "1.- Asi mejor la dejamos" << std::endl;

        int seguir = valida_num(0,1);

        if(seguir == 0){
            std::cout << "Excelente, en un momento inicia tu siguiente batalla" 
            << std::endl;
        }
        else{
            std::cout << "Ok entiendo, muchas gracias por participar" 
            << std::endl;
            return 0;
        }
    }
    else{
        std::cout << "Lo lamento, pero ya has sido descalificado, intentalo"
        " a la proxima" << std::endl;
        return 0;
    }

    int random2 = std::rand() % trainers.size();
    Entrenador sec_bot = trainers[random2];
    trainers.erase(trainers.begin() + random2);

    std::cout << "Ahora entra como retador...." << std::endl;
    sec_bot.mostrar();

    int hist2 = historia(player,sec_bot);

    if(hist2 == 1){
        std::cout << "Felicidades, sabia que lo podias lograr," 
        " quieres seguir participando?" << std::endl;

        std::cout << "0.- Sii, que venga el que sigue" << std::endl;
        std::cout << "1.- Asi mejor la dejamos" << std::endl;

        int seguir = valida_num(0,1);

        if(seguir == 0){
            std::cout << "Excelente, en un momento inicia tu siguiente batalla" 
            << std::endl;
        }
        else{
            std::cout << "Ok entiendo, muchas gracias por participar" 
            << std::endl;
            return 0;
        }
    }
    else{
        std::cout << "Lo lamento, pero ya has sido descalificado, intentalo"
        " a la proxima" << std::endl;
        return 0;
    }

    Entrenador ter_bot = trainers[0];

    std::cout << "Ahora como ultimo participante de este torneo tenemos a..." 
    << std::endl;

    ter_bot.mostrar();

    int hist3 = historia(player,ter_bot);

    if(hist3 == 1){
        std::cout << "FELICIDADES, te has convertido en nuestro campeon" 
        " absoluto, debes estar orgulloso, nos vemos en la proxima" 
        << std::endl;
    }
    else{
        std::cout << "Estivuste muy cerca, puedes volver a intentarlo" 
        "cuando quieras, gracias y hasta la proxima" << std::endl;
    }

    return 0;
}