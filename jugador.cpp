//
// Created by Usuario on 25/10/2025.
//

#include "jugador.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

jugador::jugador(string nick, int nivel):
nickname(nick),
nivelRaking(nivel){}

string jugador::getnickname() const {
    return nickname;
}

int jugador::getnivelRaking() const {
    return nivelRaking;
}

void jugador::incribirvideoj(videojuegos* juego) {

    for (auto v : videojuegosIncritos) {
        if (v->getCodigo() == juego->getCodigo()) {
            cout << "ya esta inscrito este video juego.\n";
            return;
        }
    }
    videojuegosIncritos.push_back(juego);
    cout << "incripcion exitosa en el juego: " << juego->getCodigo() << endl;
}

void jugador::mostrarvideojuego() const {

    cout << "lista de video juegos de " << nickname <<  endl;
    for (auto v : videojuegosIncritos) {
        v-> mostrarinfo();
    }
}

float jugador::promediodificultad() const {
    if (videojuegosIncritos.empty()) return 0;
    float suma = 0;
    for (auto v : videojuegosIncritos) {
        suma += v->getniveldificultad();
    }
    return suma / videojuegosIncritos.size();
}






