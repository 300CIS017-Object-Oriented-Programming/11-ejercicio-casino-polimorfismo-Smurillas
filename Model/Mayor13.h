#ifndef CASINO_MAYOR13_H
#define CASINO_MAYOR13_H

#include "Juego.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

class Mayor13 : public Juego {
protected:
    bool decidioRetirarse;
    float calcularResultado(float gonzosApostar) override;

public:
    Mayor13() : decidioRetirarse(false) {}
    ~Mayor13() override = default;

    float jugar(float gonzosApostar) override;
    void mostrarReglas() const override;
};

#endif // CASINO_MAYOR13_H
