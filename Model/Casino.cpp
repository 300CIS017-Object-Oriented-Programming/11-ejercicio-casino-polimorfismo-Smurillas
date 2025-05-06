#include "Casino.h"

Casino::Casino() {
    juegosDisponibles.push_back(std::make_shared<Mayor13>());
    juegosDisponibles.push_back(std::make_shared<DosColores>());
    juegosDisponibles.push_back(std::make_shared<Slots>());
    juegosDisponibles.push_back(std::make_shared<ParImpar>());  // 👉 Nuevo juego
}

Casino::~Casino() = default;

float Casino::convertirPesosAGonzos(float dinero) {
    // 10 000 pesos = 100 gonzos ⇒ 1 gonzo = 100 pesos
    return dinero / 100.0f;
}

bool Casino::verExisteJugador(long id) {
    return jugadoresMap.find(id) != jugadoresMap.end();
}

bool Casino::verPuedeContinuar(long idJugador, float gonzosApostar) {
    if (!verExisteJugador(idJugador)) return false;
    return jugadoresMap[idJugador].getCantGonzos() >= gonzosApostar;
}

void Casino::agregarJugador() {
    long id;
    string nombre;
    float dineroPesos;

    cout << "Ingrese id de jugador: ";
    cin >> id;
    if (verExisteJugador(id)) {
        throw std::invalid_argument("El jugador ya existe");
    }

    cout << "Ingrese nombre de jugador: ";
    cin >> nombre;
    cout << "Ingrese dinero en pesos: ";
    cin >> dineroPesos;
    if (dineroPesos <= 0) {
        throw std::invalid_argument("El dinero debe ser mayor a 0");
    }

    float gonzos = convertirPesosAGonzos(dineroPesos);
    jugadoresMap.emplace(id, Jugador(id, nombre, gonzos));
}

void Casino::retirarJugador(long id) {
    if (!verExisteJugador(id)) {
        throw std::domain_error("El jugador no existe");
    }
    jugadoresMap.erase(id);
}

void Casino::verInfoJugador(long idJugador) {
    if (!verExisteJugador(idJugador)) {
        throw std::domain_error("El jugador no existe");
    }
    jugadoresMap[idJugador].mostrarInfo();
}

void Casino::recargarGonzos(long idJugador) {
    if (!verExisteJugador(idJugador)) {
        throw std::domain_error("El jugador no existe");
    }

    float dineroPesos;
    cout << "Ingrese dinero en pesos para recargar: ";
    cin >> dineroPesos;
    if (dineroPesos <= 0) {
        throw std::invalid_argument("El dinero debe ser mayor a 0");
    }

    float gonzos = convertirPesosAGonzos(dineroPesos);
    jugadoresMap[idJugador].actualizarGonzos(gonzos);
}

float Casino::jugar(int idJuego, long idJugador, float gonzosApostar) {
    if (!verExisteJugador(idJugador)) {
        throw std::domain_error("El jugador no existe");
    }
    if (idJuego < 1 || idJuego > static_cast<int>(juegosDisponibles.size())) {
        throw std::domain_error("El juego no existe");
    }
    if (!verPuedeContinuar(idJugador, gonzosApostar)) {
        throw std::domain_error("Saldo insuficiente");
    }

    auto juego = juegosDisponibles[idJuego - 1];
    juego->mostrarReglas();
    float resultado = juego->jugar(gonzosApostar);
    jugadoresMap[idJugador].aumentarJuegos();
    jugadoresMap[idJugador].actualizarGonzos(resultado);
    return resultado;
}
