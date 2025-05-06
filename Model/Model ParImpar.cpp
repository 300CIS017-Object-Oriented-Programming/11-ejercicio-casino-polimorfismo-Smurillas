#include "ParImpar.h"
#include <iostream>
#include <cstdlib>

void ParImpar::mostrarReglas() const {
    std::cout << "Reglas de ‘Par o Impar’:\n"
              << "- Apuesta cierta cantidad de Gonzos.\n"
              << "- Elige par (0) o impar (1).\n"
              << "- Si coincide con el tiro (0=par,1=impar), ganas tu apuesta; si no, la pierdes.\n";
}

bool ParImpar::jugar(int apuesta) {
    int tiro = std::rand() % 2;
    int eleccion;
    std::cout << "Elige Par(0) o Impar(1): ";
    std::cin >> eleccion;
    if (eleccion == tiro) {
        std::cout << "¡Acertaste! Ganas " << apuesta << " Gonzos.\n";
        return true;
    }
    std::cout << "Fallaste. Pierdes " << apuesta << " Gonzos.\n";
    return false;
}
//
// Created by Santiago Murillas on 5/6/25.
//
