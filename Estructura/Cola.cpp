#include "Cola.h"

Cola::Cola() : frente(nullptr), final(nullptr) {}

Cola::~Cola() {
    while (frente) {
        Pasajero* temp = frente;
        frente = frente->siguiente;
        delete temp;
    }
}

void Cola::encolar(Pasajero* pasajero) {
    if (final) {
        final->siguiente = pasajero;
    } else {
        frente = pasajero;
    }
    final = pasajero;
    pasajero->siguiente = nullptr;
}

Pasajero* Cola::desencolar() {
    if (!this->frente) return nullptr;
    Pasajero* temp = this->frente;
    this->frente = this->frente->siguiente;
    if (!this->frente) final = nullptr;
    return temp;
}

bool Cola::estaVacia() {
    return frente == nullptr;
}

Pasajero *Cola::getFrente() const {
    return frente;
}

void Cola::setFrente(Pasajero *frente) {
    Cola::frente = frente;
}

Pasajero *Cola::getFinal() const {
    return final;
}

void Cola::setFinal(Pasajero *final) {
    Cola::final = final;
}
