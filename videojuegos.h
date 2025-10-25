//
// Created by Usuario on 25/10/2025.
//
#ifndef INC_8_PRACTICA_MAPA_VECTOR_ABRAHAM21587_VIDEOJUEGOS_H
#define INC_8_PRACTICA_MAPA_VECTOR_ABRAHAM21587_VIDEOJUEGOS_H


#include <string>
using namespace std;

class videojuegos {
private:
    string codigo;
    string nombre;
    string genero;
    int niveldificultad;

public:

    videojuegos(string c, string n, string g, int d);
    string getCodigo();
    string getnombre();
    int getniveldificultad();
    void mostrarinfo();

};



#endif //INC_8_PRACTICA_MAPA_VECTOR_ABRAHAM21587_VIDEOJUEGOS_H