#include "ParImpar.h"

void ParImpar::mostrarReglas() const {
    std::cout << "Reglas de 'Par o Impar':\n"
              << "- Apuesta cierta cantidad de Gonzos.\n"
              << "- Elige par (0) o impar (1).\n"
              << "- Si coincide con el tiro de la casa, ganas tu apuesta; si no, la pierdes.\n";
}

float ParImpar::jugar(float gonzosApostar) {
    numeroCasino = rand() % 2;
    cout << "Elige Par(0) o Impar(1): ";
    cin >> numeroJugador;  // 0 o 1
    cout << "Resultado de la casa: " << numeroCasino << endl;
    return calcularResultado(gonzosApostar);
}

float ParImpar::calcularResultado(float gonzosApostar) {
    if (numeroJugador == numeroCasino) {
        return gonzosApostar;
    } else {
        return -gonzosApostar;
    }
}

//
// Created by Santiago Murillas on 5/6/25.
//
