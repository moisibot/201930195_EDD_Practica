#include "Equipaje.h"

Equipaje::Equipaje(int cantidad) : cantidad(cantidad), siguiente(nullptr) {}

int Equipaje::getCantidad() const {
    return cantidad;
}

void Equipaje::setCantidad(int cantidad) {
    Equipaje::cantidad = cantidad;
}

Equipaje *Equipaje::getSiguiente() const {
    return siguiente;
}

void Equipaje::setSiguiente(Equipaje *siguiente) {
    Equipaje::siguiente = siguiente;
}
