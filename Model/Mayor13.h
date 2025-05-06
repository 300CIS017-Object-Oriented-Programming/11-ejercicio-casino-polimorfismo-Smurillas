//
// Created by lufe0 on 7/05/2021.
//

#ifndef CASINO_MAYOR13_H
#define CASINO_MAYOR13_H


#include "Juego.h"
#include<cstdlib>
#include<ctime>

class Mayor13 : public Juego {

protected:
    float calcularResultado(float gonzosApostar) override;

    void mostrarReglas() const;

public:
    ~Mayor13() override = default; // Los destructores deben ser sobreescritos y deben ser virtual en la clase papa. Si no tiene nada especial se puede marcar como default
    float jugar(float gonzosApostar) override;

};


#endif //CASINO_MAYOR13_H
