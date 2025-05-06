//
// Created by lufe0 on 7/05/2021.
//

#include "Casino.h"

// Constructor que inicializa las ganancias y perdidas en cero
Casino::Casino() {
    cout << "Inicialice casino";
    // Inicia un jugador en el mapa para comenzar
    jugadoresMap.insert({1, new Jugador(1, "Pedro rodriguez", 500)});

    // Inicia  los juegos disponibles y los agrega al mapa de juegos
    // Se puede usar auto pq el tipo de objeto que voy a crear es igual a la variable que estoy inicializando ejm Mayor13
    auto *juego1 = new Mayor13();
    juegosDisponibles.push_back(juego1);
    auto *juego2 = new DosColores();
    juegosDisponibles.push_back(juego2);
    auto *slots = new Slots();
    juegosDisponibles.push_back(slots);
}

void Casino::agregarJugador() {
    string nombreJugador;
    float dineroPesos;
    long idJugador;
    cout << "Ingrese el nombre del jugador \n";
    cin.ignore(100, '\n');
    getline(cin, nombreJugador);
    // Id del jugador
    bool errores = false;

    // Se agrega jugador solo si no existe con anticipacion
    do {
        cout << "Ingrese el id del jugador \n";
        cin >> idJugador;
        if (verExisteJugador(idJugador)) {
            cout << "El jugador con la identificacion recibida ya existe\n";
            errores = true;
        }else{
            errores = false;
        }
    } while (errores);

    // Validacion del dinero
    do {
        cout << "Ingrese el dinero en pesos \n";
        cin >> dineroPesos;
    } while (dineroPesos <= 0);

    // Se convierte el dinero a Gonzos
    float cantGonzos = convertirPesosAGonzos(dineroPesos);

    // Se agrega el jugador
    auto *pJugador = new Jugador(idJugador, nombreJugador, cantGonzos);
    // Se agrega el jugador al mapa de jugadores del casino
    jugadoresMap.insert({pJugador->getId(), pJugador});

    cout << "Jugador agregado exitosamente  \n";
}

/* Este metodo de ejemplo delega los mensajes de error en la intaracción con la consola unicamente a la vista */
// Ejemplo dentro de Casino::jugar()
    std::cout << "Has elegido: " << listaJuegos[indice] << "\n";
    juegos[indice]->mostrarReglas();    // <-- aquí
    bool resultado = juegos[indice]->jugar(apuesta);
float Casino::jugar(int idJuego, long idJugador, float gonzosApostar) {
    if (gonzosApostar < 1) {
        throw std::domain_error("Debe apostar al menos 1 gonzo\n");
    }

    if (!verExisteJugador(idJugador)) {
        throw std::domain_error("El jugador con la identificacion recibida NO existe, no es posible jugar\n");
    }
    if (idJuego > juegosDisponibles.size()) {
        throw std::domain_error("NO existe el juego que desea jugar\n");
    }
    if (!verPuedeContinuar(idJugador, gonzosApostar)) {
        throw std::domain_error("No tienes saldo suficiente para jugar\n");
    }
    // Si no hay errores se inicia el juego
    Juego *pJuegoAJugar = juegosDisponibles.at(idJuego - 1);

    // Consulta al jugador, consulta los gonzos iniciales, juega y obtiene el resultado
    Jugador *pJugador = jugadoresMap[idJugador];
    float gonzosGanados = pJuegoAJugar->jugar(gonzosApostar) - gonzosApostar;

    // Actualiza el saldo del jugador con el resultado
    pJugador->actualizarGonzos(gonzosGanados);

    // Actualiza la cantidad de juegos jugados
    pJugador->aumentarJuegos();

    // Retorna los gonzos ganados o perdidos
    return gonzosGanados;
}

void Casino::verInfoJugador(long idJugador) {
    // En teoría esta excepción no debería salir nunca pero se pone como táctica de programación segura.
    if (!verExisteJugador(idJugador)) {
        throw std::domain_error("El jugador con la identificacion recibida NO existe\n");
    }
    Jugador *pJugador = jugadoresMap[idJugador];
    pJugador->mostrarInfo();
}

bool Casino::verPuedeContinuar(int idJugador, float gonzosApostar) {
    // En teoría esta excepción no debería salir nunca pero se pone como táctica de programación segura.
    if (!verExisteJugador(idJugador)) {
        throw std::domain_error("El jugador con la identificacion recibida NO existe");
    }
    Jugador *pJugador = jugadoresMap[idJugador];
    if (pJugador->getCantGonzos() < gonzosApostar) {
        return false;
    }
    return true;
}

void Casino::retirarJugador(long idJugador) {
    if (verExisteJugador(idJugador)) {
        // Se obtiene el jugador
        Jugador *pJugador = jugadoresMap[idJugador];
        // limpia la memoria
        delete pJugador;
        // borra el apuntador del mapa
        jugadoresMap.erase(idJugador);
    } else {
        throw std::invalid_argument("El jugador con la identificacion recibida NO existe\n");
    }
}

void Casino::recargarGonzos(long idJugador) {
    if (!verExisteJugador(idJugador)) {
        throw std::domain_error("El jugador con la identificacion recibida NO existe\n");
    }
    float dinero;
    Jugador *pJugador = jugadoresMap[idJugador];
    do {
        cout << "Ingrese la cantidad de dinero  a recargar: ";
        cin >> dinero;
    } while (dinero < 0);
    // Se convierte el dinero a gonzos
    float gonzos = convertirPesosAGonzos(dinero);

    pJugador->actualizarGonzos(gonzos);
}


bool Casino::verExisteJugador(long id) {

    // Si el jugador se encuentra en el mapa retorna true, de lo contrario retorna false
    // Este es un tipo de condicional de una linea para guardar la variable del resultado
    bool result = (jugadoresMap.find(id) != jugadoresMap.end());
    return result;
}

/* OJO este metodo podria ser estatico
 * "A method can be static if it does not reference any of its class' non-static methods and non-static fields and is not overridden in a subclass".*/
float Casino::convertirPesosAGonzos(float dinero) {
    return (dinero / 100);
}


Casino::~Casino() {
    // Se libera la memoria del jugadores y de juegos
    // Simplifica iteracion en el mapa for(map<long, Jugador*>::iterator it = jugadoresMap.begin();
    for (auto &it : jugadoresMap) {
        Jugador *jugadorTemp = jugadoresMap[it.first];
        delete jugadorTemp;
    }

    // Simplificación del for
    // for(int i=0; i< juegosDisponibles.size(); i++)
    for (auto juegoTemp : juegosDisponibles) {
        delete juegoTemp;
    }
    cout << "Termine de llamar destructor de casino \n";
}
