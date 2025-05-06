#ifndef CASINO_VIEW_H
#define CASINO_VIEW_H

#include "../Model/Casino.h"

class View {
private:
    Casino casino;

    int mostrarMenu();
    void jugarView();
    void agregarJugador();
    void retirarJugador();
    void mostrarJugador();
    void recargarGonzos();

public:
    View() = default;
    void verPrincipal();
};

#endif // CASINO_VIEW_H
