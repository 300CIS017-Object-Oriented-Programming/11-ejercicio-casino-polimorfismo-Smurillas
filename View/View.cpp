#include "View.h"
#include <iostream>
#include <limits>

using std::cin;
using std::cout;
using std::endl;

int View::mostrarMenu() {
    int opcion;
    cout << "===== MENU =====\n";
    cout << "1. Agregar jugador\n";
    cout << "2. Jugar\n";
    cout << "3. Consultar jugador\n";
    cout << "4. Recargar gonzos\n";
    cout << "5. Retirar jugador\n";
    cout << "0. Salir\n";
    cout << "Digita el numero: ";
    cin >> opcion;
    return opcion;
}

void View::agregarJugador() {
    try {
        casino.agregarJugador();
    } catch (const std::exception& ex) {
        cout << "ERROR: " << ex.what() << endl;
    }
}

void View::jugarView() {
    try {
        long idJugador;
        cout << "Ingrese id del jugador para jugar: ";
        cin >> idJugador;

        float cantGonzos;
        cout << "Cuántos gonzos desea apostar: ";
        cin >> cantGonzos;

        cout << "Elija el juego:\n";
        cout << "1. Mayor a 13.\n";
        cout << "2. Dos colores.\n";
        cout << "3. Slots\n";
        cout << "4. Par o Impar\n";
        cout << "Opción: ";
        int idJuego;
        cin >> idJuego;

        float resultado = casino.jugar(idJuego, idJugador, cantGonzos);
        if (resultado > 0) {
            cout << "¡Has ganado!: ";
        } else {
            cout << "Has perdido :(!: ";
        }
        cout << resultado << " Gonzos" << endl;
    } catch (const std::exception& ex) {
        cout << "ERROR: " << ex.what() << endl;
    }
}

void View::mostrarJugador() {
    try {
        long idJugador;
        cout << "Ingrese el id del jugador: ";
        cin >> idJugador;
        casino.verInfoJugador(idJugador);
    } catch (const std::exception& ex) {
        cout << "ERROR: " << ex.what() << endl;
    }
}

void View::recargarGonzos() {
    try {
        long idJugador;
        cout << "Ingrese el id del jugador: ";
        cin >> idJugador;
        casino.recargarGonzos(idJugador);
        cout << "Recarga realizada con éxito." << endl;
    } catch (const std::exception& ex) {
        cout << "ERROR: " << ex.what() << endl;
    }
}

void View::retirarJugador() {
    try {
        long idJugador;
        cout << "Ingrese el id del jugador: ";
        cin >> idJugador;
        casino.retirarJugador(idJugador);
        cout << "Jugador retirado con éxito." << endl;
    } catch (const std::exception& ex) {
        cout << "ERROR: " << ex.what() << endl;
    }
}

void View::verPrincipal() {
    int opcion;
    do {
        opcion = mostrarMenu();
        switch (opcion) {
            case 1: agregarJugador(); break;
            case 2: jugarView();      break;
            case 3: mostrarJugador(); break;
            case 4: recargarGonzos(); break;
            case 5: retirarJugador(); break;
            case 0: cout << "¡Hasta pronto!\n"; break;
            default: cout << "Opción inválida\n"; break;
        }
    } while (opcion != 0);
}
