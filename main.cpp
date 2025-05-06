#include "View/View.h"
#include <iostream>
#include "ParImpar.h"
// …
juegos.push_back(std::make_unique<ParImpar>());
listaJuegos.push_back("Par o Impar");


using std::cin;
using std::cout;
using std::endl;


int main() {
    // Objeto de tipo View para enlazar con la vista
    View vistaPPAL;
    vistaPPAL.verPrincipal();
    return 0;
}