#include "Nodo.h"

Nodo::Nodo(Pasajero* pasajero) : pasajero(pasajero), siguiente(nullptr), anterior(nullptr) {}

Pasajero *Nodo::getPasajero() const {
    return pasajero;
}

void Nodo::setPasajero(Pasajero *pasajero) {
    Nodo::pasajero = pasajero;
}

Nodo *Nodo::getSiguiente() const {
    return siguiente;
}

void Nodo::setSiguiente(Nodo *siguiente) {
    Nodo::siguiente = siguiente;
}

Nodo *Nodo::getAnterior() const {
    return anterior;
}

void Nodo::setAnterior(Nodo *anterior) {
    Nodo::anterior = anterior;
}
