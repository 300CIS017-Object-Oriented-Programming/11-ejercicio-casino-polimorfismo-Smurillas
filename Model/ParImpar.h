#ifndef CASINO_PARIMPAR_H
#define CASINO_PARIMPAR_H

#include "Juego.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

class ParImpar : public Juego {
protected:
    float calcularResultado(float gonzosApostar) override;

public:
    ParImpar() { srand(static_cast<unsigned>(time(nullptr))); }
    ~ParImpar() override = default;

    float jugar(float gonzosApostar) override;
    void mostrarReglas() const override;
};

#endif // CASINO_PARIMPAR_H
