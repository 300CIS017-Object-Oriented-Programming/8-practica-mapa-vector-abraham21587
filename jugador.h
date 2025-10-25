//
// Created by Usuario on 25/10/2025.
//

#ifndef INC_8_PRACTICA_MAPA_VECTOR_ABRAHAM21587_JUGADOR_H
#define INC_8_PRACTICA_MAPA_VECTOR_ABRAHAM21587_JUGADOR_H


#include <string>
using namespace std;
#include <vector>
#include "videojuegos.h"

class jugador {
private:

    string nickname;
    int nivelRaking;
    vector<videojuegos*> videojuegosIncritos;

public:
    jugador(string nick, int nivel);
    string getnickname() const;
    int getnivelRaking() const;
    void incribirvideoj(videojuegos* juego);
    void mostrarvideojuego() const;
    float promediodificultad() const;

};



#endif //INC_8_PRACTICA_MAPA_VECTOR_ABRAHAM21587_JUGADOR_H