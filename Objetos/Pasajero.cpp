#include "Pasajero.h"

Pasajero::Pasajero(std::string nombre, std::string nacionalidad, std::string numero_de_pasaporte, std::string vuelo,
                   int asiento, std::string destino, std::string origen, int equipaje_facturado)
        : nombre(nombre), nacionalidad(nacionalidad), numero_de_pasaporte(numero_de_pasaporte), vuelo(vuelo),
        asiento(asiento), destino(destino), origen(origen), equipaje_facturado(equipaje_facturado), siguiente(nullptr) {}

const string &Pasajero::getNombre() const {
    return nombre;
}

void Pasajero::setNombre(const string &nombre) {
    Pasajero::nombre = nombre;
}

const string &Pasajero::getNacionalidad() const {
    return nacionalidad;
}

void Pasajero::setNacionalidad(const string &nacionalidad) {
    Pasajero::nacionalidad = nacionalidad;
}

const string &Pasajero::getNumeroDePasaporte() const {
    return numero_de_pasaporte;
}

void Pasajero::setNumeroDePasaporte(const string &numeroDePasaporte) {
    numero_de_pasaporte = numeroDePasaporte;
}

const string &Pasajero::getVuelo() const {
    return vuelo;
}

void Pasajero::setVuelo(const string &vuelo) {
    Pasajero::vuelo = vuelo;
}

int Pasajero::getAsiento() const {
    return asiento;
}

void Pasajero::setAsiento(int asiento) {
    Pasajero::asiento = asiento;
}

const string &Pasajero::getDestino() const {
    return destino;
}

void Pasajero::setDestino(const string &destino) {
    Pasajero::destino = destino;
}

const string &Pasajero::getOrigen() const {
    return origen;
}

void Pasajero::setOrigen(const string &origen) {
    Pasajero::origen = origen;
}

int Pasajero::getEquipajeFacturado() const {
    return equipaje_facturado;
}

void Pasajero::setEquipajeFacturado(int equipajeFacturado) {
    equipaje_facturado = equipajeFacturado;
}

Pasajero *Pasajero::getSiguiente() const {
    return siguiente;
}

void Pasajero::setSiguiente(Pasajero *siguiente) {
    Pasajero::siguiente = siguiente;
}
