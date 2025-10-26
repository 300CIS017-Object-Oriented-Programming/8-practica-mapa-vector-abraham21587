//
// Created by Usuario on 25/10/2025.
//
#include "torneo.h"
#include "videojuegos.h"
#include "jugador.h"
#include <iostream>
#include <limits>
using namespace std;


torneo::torneo() {}

torneo::~torneo() {
    // Liberar memoria de los videojuegos
    for (auto &p : videoj_disponibles) {
        delete p.second;
    }
    videoj_disponibles.clear();

    // Liberar memoria de los jugadores
    for (auto &p : jugador_registrados) {
        delete p.second;
    }
    jugador_registrados.clear();

    cout << "Memoria del torneo liberada correctamente.\n";
}


void torneo::registrarVideojuego() {
    string codigo;
    cout << "Ingresa el codigo del videojuego(sin espacios): ";
    cin >> codigo;

    if (videoj_disponibles.count(codigo)) {
        cout << "Ya existe un juego con este codigo.\n";
        return;
    }

    string nombre;
    cout << "Ingresa el nombre(sin espacios): ";
    cin >> nombre;

    string genero;
    cout << "Ingresa el genero del videojuego(sin espacios): ";
    cin >> genero;

    int niveldificultad;
    while (true) {
        cout << "Ingresa la dificultad (1 a 5): ";
        if (!(cin >> niveldificultad)) {
            cout << "Entrada invalida. Ingrese un numero entre 1 y 5.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        if (niveldificultad < 1 || niveldificultad > 5) {
            cout << "Dificultad fuera de rango. Intente nuevamente.\n";
            continue;
        }
        break;
    }

    videojuegos* nuevo = new videojuegos(codigo, nombre, genero, niveldificultad);
    videoj_disponibles[codigo] = nuevo;
    cout << "El videojuego se ha agregado correctamente.\n";
}


void torneo::registrarJugador() {
    string nickname;
    cout << "Ingresa el nickname:(sin espacios) ";
    cin >> nickname;

    if (jugador_registrados.count(nickname)) {
        cout << "Ya existe un jugador con ese nickname.\n";
        return;
    }

    int nivelranking;
    while (true) {
        cout << "Ingresa el nivel de ranking (1 a 100): ";
        if (!(cin >> nivelranking)) {
            cout << "⚠Entrada invalida. Ingrese un numero entre 1 y 100.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        if (nivelranking < 1 || nivelranking > 100) {
            cout << "Nivel fuera de rango. Intente nuevamente.\n";
            continue;
        }
        break;
    }

    jugador* nuevo = new jugador(nickname, nivelranking);
    jugador_registrados[nickname] = nuevo;
    cout << "El jugador se ha registrado correctamente.\n";
}

// Inscribir un jugador a un videojuego existente
void torneo::inscribirJugadorEnVideojuego() {
    string nickname;
    cout << "Ingresa el nickname del jugador(sin espacios): ";
    cin >> nickname;

    if (!jugador_registrados.count(nickname)) {
        cout << " Jugador no encontrado. Registrelo primero.\n";
        return;
    }

    string codigo;
    cout << "Ingresa el codigo del videojuego(sin espacios): ";
    cin >> codigo;

    if (!videoj_disponibles.count(codigo)) {
        cout << " Videojuego no encontrado en el catalogo.\n";
        return;
    }

    jugador* jug = jugador_registrados[nickname];
    videojuegos* juego = videoj_disponibles[codigo];
    jug->incribirvideoj(juego);
}

// Mostrar los videojuegos en los que participa un jugador
void torneo::mostrarVideojuegosJugador() {
    string nickname;
    cout << "Ingresa el nickname del jugador a consultar(sin espacios): ";
    cin >> nickname;

    if (!jugador_registrados.count(nickname)) {
        cout << " Jugador no encontrado en el catalogo.\n";
        return;
    }

    jugador* jug = jugador_registrados[nickname];
    jug->mostrarvideojuego();

    float prom = jug->promediodificultad();
    if (prom == 0.0f ) {
        cout << "Promedio de dificultad: N/A (no tiene juegos inscritos)\n";
    } else {
        cout << "Promedio de dificultad: " << prom << endl;
    }
}

// ⚙Inicializar videojuegos para pruebas
void torneo::inicializarVideojuegos() {
    videoj_disponibles["COD001"] = new videojuegos("COD001", "Call of Duty", "FPS", 4);
    videoj_disponibles["LOL002"] = new videojuegos("LOL002", "League of Legends", "MOBA", 3);
    videoj_disponibles["APEX03"] = new videojuegos("APEX03", "Apex Legends", "Battle Royale", 4);
    videoj_disponibles["SMB04"] = new videojuegos("SMB04", "Smash Bros", "Fighting", 2);
    cout << "Videojuegos inicializados para pruebas.\n";
}

// Inicializar jugadores de prueba
void torneo::inicializarJugadores() {
    jugador* j1 = new jugador("Juanito", 80);
    jugador* j2 = new jugador("Pepito", 45);
    jugador_registrados[j1->getnickname()] = j1;
    jugador_registrados[j2->getnickname()] = j2;

    // Inscribir en juegos si existen
    if (videoj_disponibles.count("LOL002")) {
        j1->incribirvideoj(videoj_disponibles["LOL002"]);
        j2->incribirvideoj(videoj_disponibles["LOL002"]);
    }
    if (videoj_disponibles.count("COD001")) {
        j1->incribirvideoj(videoj_disponibles["COD001"]);
    }

    cout << "Jugadores inicializados para pruebas.\n";
}






