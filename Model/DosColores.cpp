#include "DosColores.h"

void DosColores::mostrarReglas() const {
    std::cout << "Reglas de 'Dos Colores':\n"
              << "- Elige un color (Blanco o Negro) y un valor de dado (1–6).\n"
              << "- Si aciertas color y número, ganas 4× tu apuesta.\n"
              << "- Si sólo aciertas número, recibes 1.5×; si sólo color, recuperas tu apuesta; si fallas, pierdes todo.\n";
}

float DosColores::jugar(float gonzosApostar) {
    srand(static_cast<unsigned>(time(nullptr)));
    const int min = 1, max = 6;
    numeroJugador = min + rand() % (max - min + 1);
    numeroCasino  = min + rand() % (max - min + 1);
    colorCasino   = rand() % 2;

    cout << "Tu número aleatorio es: " << numeroJugador << endl;
    cout << "Elige un color:\n1. Blanco\n2. Negro\nOpción: ";
    cin >> colorJugador;
    --colorJugador;  // ajusta de 1-2 a 0-1

    cout << "Número casino: " << numeroCasino << endl;
    cout << "Color casino: "
         << (colorCasino == 0 ? "Blanco" : "Negro")
         << endl;

    return calcularResultado(gonzosApostar);
}

float DosColores::calcularResultado(float gonzosApostar) {
    if (numeroJugador == numeroCasino && colorJugador == colorCasino) {
        return 4 * gonzosApostar;
    } else if (numeroJugador == numeroCasino) {
        return 1.5f * gonzosApostar;
    } else if (colorJugador == colorCasino) {
        return gonzosApostar;
    } else {
        return -gonzosApostar;
    }
}

