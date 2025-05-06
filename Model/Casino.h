#ifndef CASINO_CASINO_H
#define CASINO_CASINO_H

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <memory>
#include <stdexcept>

#include "Juego.h"
#include "Mayor13.h"
#include "DosColores.h"
#include "Slots.h"
#include "ParImpar.h"
#include "Jugador.h"

using std::cin;
using std::cout;
using std::string;
using std::vector;
using std::unordered_map;
using std::shared_ptr;

class Casino {
private:
    vector<shared_ptr<Juego>> juegosDisponibles;
    unordered_map<long, Jugador> jugadoresMap;

    bool verPuedeContinuar(long idJugador, float gonzosApostar);

public:
    Casino();
    virtual ~Casino();

    static float convertirPesosAGonzos(float dinero);
    bool verExisteJugador(long id);
    void agregarJugador();
    void retirarJugador(long id);
    float jugar(int idJuego, long idJugador, float gonzosApostar);
    void verInfoJugador(long idJugador);
    void recargarGonzos(long idJugador);
};

#endif // CASINO_CASINO_H
