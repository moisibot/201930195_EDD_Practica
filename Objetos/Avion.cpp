#include "Avion.h"

Avion::Avion(std::string vuelo, std::string numero_de_registro, std::string modelo, std::string fabricante, int ano_fabricacion,
             int capacidad, int peso_max_despegue, std::string aerolinea, std::string estado)
        : vuelo(vuelo), numero_de_registro(numero_de_registro), modelo(modelo), fabricante(fabricante), ano_fabricacion(ano_fabricacion),
        capacidad(capacidad), peso_max_despegue(peso_max_despegue), aerolinea(aerolinea), estado(estado), siguiente(nullptr), anterior(nullptr) {}

Avion *Avion::getSiguiente() const {
    return siguiente;
}

Avion *Avion::getAnterior() const {
    return anterior;
}

const string &Avion::getVuelo() const {
    return vuelo;
}

const string &Avion::getNumeroDeRegistro() const {
    return numero_de_registro;
}

const string &Avion::getModelo() const {
    return modelo;
}

const string &Avion::getFabricante() const {
    return fabricante;
}

int Avion::getAnoFabricacion() const {
    return ano_fabricacion;
}

int Avion::getCapacidad() const {
    return capacidad;
}

int Avion::getPesoMaxDespegue() const {
    return peso_max_despegue;
}

const string &Avion::getAerolinea() const {
    return aerolinea;
}

const string &Avion::getEstado() const {
    return estado;
}

void Avion::setVuelo(const string &vuelo) {
    Avion::vuelo = vuelo;
}

void Avion::setNumeroDeRegistro(const string &numeroDeRegistro) {
    numero_de_registro = numeroDeRegistro;
}

void Avion::setModelo(const string &modelo) {
    Avion::modelo = modelo;
}

void Avion::setFabricante(const string &fabricante) {
    Avion::fabricante = fabricante;
}

void Avion::setAnoFabricacion(int anoFabricacion) {
    ano_fabricacion = anoFabricacion;
}

void Avion::setCapacidad(int capacidad) {
    Avion::capacidad = capacidad;
}

void Avion::setPesoMaxDespegue(int pesoMaxDespegue) {
    peso_max_despegue = pesoMaxDespegue;
}

void Avion::setAerolinea(const string &aerolinea) {
    Avion::aerolinea = aerolinea;
}

void Avion::setEstado(const string &estado) {
    Avion::estado = estado;
}

void Avion::setSiguiente(Avion *siguiente) {
    Avion::siguiente = siguiente;
}

void Avion::setAnterior(Avion *anterior) {
    Avion::anterior = anterior;
}
