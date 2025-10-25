//
// Created by Usuario on 25/10/2025.
//

#include "torneo.h"
#include "videojuegos.h"
#include "jugador.h"
#include <iostream>
using namespace std;

torneo::torneo() {

}

torneo::~torneo() {
    for (auto &p : videoj_disponibles) {
        delete p.second;
    }
    videoj_disponibles.clear();

    // Liberar memoria de Jugador*
    for (auto &p : jugador_registrados) {
        delete p.second;
    }
    jugador_registrados.clear();
}


void torneo::registrarVideojuego() {

    string codigo;
    cout << "ingresa el Codigo: ";
    cin >> codigo;

    if (videoj_disponibles.count(codigo)) {
        cout << "ya exite un juego con este codigo";
        return;
    }

    string nombre;
    cout << "ingresa el nombre: ";
    cin >> nombre;

    string genero;
    cout << "ingresa el genero del videojuego: ";
    cin >> genero;

    int niveldificultad;
    while (true) {
        cout << "ingrese una la difultad de 1 a 5: ";
        if (!(cin >> niveldificultad)) {
            cout << "ingrese un numero entre 1 y 5: ";
            cin.clear();
            continue;
        }
        if (niveldificultad < 1 || niveldificultad > 5) {
            cout << "ingrese una la difultad de 1 a 5: ";
            continue;

        }
        break;
    }

    videojuegos* nuevo = new videojuegos(codigo, nombre, genero, niveldificultad);
    videoj_disponibles[codigo] = nuevo;
    cout << "el video juego se a agregado" << endl;


}

void torneo::registrarJugador() {

    string nickname;
    cout << "ingresa el nickname: ";
    cin >> nickname;

    int nivelranking;
    while (true) {
        cout << "ingrese una la difultad de 1 a 5: ";
        if (!(cin >> nivelranking)) {
            cout << "ingrese un numero entre 1 y 5: ";
            cin.clear();
            continue;
        }
        if (nivelranking < 1 || nivelranking > 5) {
            cout << "ingrese una la difultad de 1 a 5: ";
            continue;

        }
        break;

    }

    jugador* nuevo = new jugador(nickname, nivelranking);
    jugador_registrados[nickname] = nuevo;
    cout << "el jugador se a agregado" << endl;

}

void torneo::inscribirJugadorEnVideojuego() {

    string nickname;
    cout << "ingresa el nickname del jugador: ";
    cin >> nickname;

    if (!jugador_registrados.count(nickname)) {
        cout << "jugador no encontrado. registrelo primero. \n";
        return;
    }

    string codigo;
    cout << "ingrese el codigo del videojuego: " << endl;
    cin >> codigo;

    if (!videoj_disponibles.count(codigo)) {
        cout << "videojuego no encontrado en el catalogo";
        return;
    }

    jugador* jug = jugador_registrados[nickname];
    videojuegos* juego = videoj_disponibles[codigo];
    jug->incribirvideoj(juego);

}

void torneo::mostrarVideojuegosJugador() {

    string nickname;
    cout << "ingrese el nickname del jugador a consultar: ";
    cin >> nickname;

    if (!jugador_registrados.count(nickname)) {
        cout << "jugador no encontrado en el catalogo";
        return;
    }

    jugador* jug = jugador_registrados[nickname];
    jug->mostrarvideojuego();

    float prom = jug->promediodificultad();
    if (prom == 0.0f && true) {

        cout << "promedio de dificultad: N/A no tiene juegos incritos" << endl;

    }else {
        cout << "promedio de dificultad: " << prom << endl;
    }

}

void torneo::inicializarVideojuegos() {

    videoj_disponibles["COD001"] = new videojuegos("COD001", "Call of Duty", "FPS", 4);
    videoj_disponibles["LOL002"] = new videojuegos("LOL002", "League of Legends", "MOBA", 3);
    videoj_disponibles["APEX03"] = new videojuegos("APEX03", "Apex Legends", "Battle Royale", 4);
    videoj_disponibles["SMB04"] = new videojuegos("SMB04", "Smash Bros", "Fighting", 2);
    cout << "Videojuegos inicializados para pruebas.\n";

}

void torneo::inicializarJugadores() {

    jugador* j1 = new jugador("Juanito", 80);
    jugador* j2 = new jugador("Pepito", 45);
    jugador_registrados[j1->getnickname()] = j1;
    jugador_registrados[j2->getnickname()] = j2;

    // Opcional: inscribir a algunos jugadores en videojuegos de prueba
    if (videoj_disponibles.count("LOL002")) {
        j1->incribirvideoj(videoj_disponibles["LOL002"]);
        j2->incribirvideoj(videoj_disponibles["LOL002"]);
    }
    if (videoj_disponibles.count("COD001")) {
        j1->incribirvideoj(videoj_disponibles["COD001"]);
    }
    cout << "🔧 Jugadores inicializados para pruebas.\n";
}







