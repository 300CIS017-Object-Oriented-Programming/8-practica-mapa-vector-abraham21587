//
// Created by Usuario on 25/10/2025.
//

#include "videojuegos.h"
#include <iostream>
#include <string>
using namespace std;


videojuegos::videojuegos(string c, string n, string g, int d):
codigo(c), nombre(n), genero(g), niveldificultad(d) {}

string videojuegos::getCodigo() {
   return codigo;
}

string videojuegos::getnombre() {
   return nombre;
}

string videojuegos::getgenero() {
   return genero;
}


int videojuegos::getniveldificultad() {
   return niveldificultad;
}

void videojuegos::mostrarinfo() {

   cout << " el codigo del juego es : " << codigo
   << ", el nombre del juegos es : " << nombre
   << ", el genero del juego es:  " << genero
   << ", la dificultad es: " <<niveldificultad
   << endl;
}



