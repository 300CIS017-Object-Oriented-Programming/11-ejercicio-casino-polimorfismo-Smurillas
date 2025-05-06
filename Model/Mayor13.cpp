#include "Mayor13.h"

void Mayor13::mostrarReglas() const {
    std::cout << "Reglas de 'El Mayor a 13':\n"
              << "- Se genera un número aleatorio entre 1 y 13 para ti y para el casino.\n"
              << "- Antes de ver el número del casino, puedes retirarte y perder la mitad de tu apuesta.\n"
              << "- Si juegas y tu número > número del casino, ganas 2× tu apuesta; si no, pierdes todo.\n";
}

float Mayor13::jugar(float gonzosApostar) {
    srand(static_cast<unsigned>(time(nullptr)));
    numeroJugador = rand() % 13 + 1;

    cout << "Tu número aleatorio es: " << numeroJugador << endl;
    cout << "¿Deseas retirarte antes de ver el número del casino? (1=Sí, 2=No): ";
    int opcion;
    cin >> opcion;
    if (opcion == 1) {
        decidioRetirarse = true;
        return -0.5f * gonzosApostar;
    }

    numeroCasino = rand() % 13 + 1;
    cout << "Número casino: " << numeroCasino << endl;
    return calcularResultado(gonzosApostar);
}

float Mayor13::calcularResultado(float gonzosApostar) {
    if (decidioRetirarse) {
        return -0.5f * gonzosApostar;
    } else if (numeroJugador > numeroCasino) {
        return 2 * gonzosApostar;
    } else {
        return -gonzosApostar;
    }
}


