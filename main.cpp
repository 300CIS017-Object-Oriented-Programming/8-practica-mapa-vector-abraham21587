#include <iostream>
#include "torneo.h"
using namespace std;

int main() {
    torneo torneo; // 👈 Se crea el objeto principal del sistema

    int opcion;

    do {
        cout << "\n🏆 BATTLE ARENA - SISTEMA DE TORNEO eSPORTS 🕹️\n";
        cout << "---------------------------------------------\n";
        cout << "1. Registrar videojuego\n";
        cout << "2. Registrar jugador\n";
        cout << "3. Inscribir jugador a videojuego\n";
        cout << "4. Mostrar videojuegos de un jugador\n";
        cout << "5. Inicializar videojuegos (datos de prueba)\n";
        cout << "6. Inicializar jugadores (datos de prueba)\n";
        cout << "0. Salir\n";
        cout << "---------------------------------------------\n";
        cout << "Elige una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                torneo.registrarVideojuego();
                break;

            case 2:
                torneo.registrarJugador();
                break;

            case 3:
                torneo.inscribirJugadorEnVideojuego();
                break;

            case 4:
                torneo.mostrarVideojuegosJugador();
                break;

            case 5:
                torneo.inicializarVideojuegos();
                break;

            case 6:
                torneo.inicializarJugadores();
                break;

            case 0:
                cout << "\n👋 Saliendo del torneo...\n";
                break;

            default:
                cout << "❌ Opción no válida. Intenta de nuevo.\n";
        }

    } while (opcion != 0);

    // 👇 Al terminar, el destructor de Torneo se ejecuta automáticamente
    return 0;
}

