#include "Pila.h"
#include <iostream>

Pila::Pila() : cima(nullptr) {}

Pila::~Pila() {
    while (cima) {
        Equipaje* temp = cima;
        cima = cima->siguiente;
        delete temp;
    }
}

void Pila::apilar(int cantidad) {
    Equipaje* nuevo = new Equipaje(cantidad);
    nuevo->siguiente = this->cima;
    this->cima = nuevo;
}

int Pila::desapilar() {
    if (!cima) return 0;
    Equipaje* temp = cima;
    cima = cima->siguiente;
    int cantidad = temp->cantidad;
    delete temp;
    return cantidad;
}

bool Pila::estaVacia() {
    return cima == nullptr;
}

Equipaje *Pila::getCima() const {
    return cima;
}

void Pila::setCima(Equipaje *cima) {
    Pila::cima = cima;
}
