//
// Created by Usuario on 25/10/2025.
//

#ifndef INC_8_PRACTICA_MAPA_VECTOR_ABRAHAM21587_TORNEO_H
#define INC_8_PRACTICA_MAPA_VECTOR_ABRAHAM21587_TORNEO_H
#include <map>
#include <string>

#include "jugador.h"


class torneo {
private:
    map<string, videojuegos*> videoj_disponibles;
    map<string, jugador*> jugador_registrados;

public:

    void registrarVideojuego();
    void registrarJugador();
    void inscribirJugadorEnVideojuego();
    void mostrarVideojuegosJugador();
    void inicializarVideojuegos();
    void inicializarJugadores();


};


#endif //INC_8_PRACTICA_MAPA_VECTOR_ABRAHAM21587_TORNEO_H