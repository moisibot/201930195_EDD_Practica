#include "ListaCircularDoble.h"
#include <iostream>

NodoAvion::NodoAvion(Avion* avion) : avion(avion), siguiente(nullptr), anterior(nullptr) {}

Avion *NodoAvion::getAvion() const {
    return avion;
}

void NodoAvion::setAvion(Avion *avion) {
    NodoAvion::avion = avion;
}

NodoAvion *NodoAvion::getSiguiente() const {
    return siguiente;
}

void NodoAvion::setSiguiente(NodoAvion *siguiente) {
    NodoAvion::siguiente = siguiente;
}

NodoAvion *NodoAvion::getAnterior() const {
    return anterior;
}

void NodoAvion::setAnterior(NodoAvion *anterior) {
    NodoAvion::anterior = anterior;
}

ListaCircularDoble::ListaCircularDoble() : cabeza(nullptr) {}

ListaCircularDoble::~ListaCircularDoble() {
    if (cabeza) {
        NodoAvion* actual = cabeza;
        do {
            NodoAvion* temp = actual;
            actual = actual->siguiente;
            delete temp->avion;
            delete temp;
        } while (actual != cabeza);
    }
}

void ListaCircularDoble::insertarAvion(Avion* avion) {
    NodoAvion* nuevo = new NodoAvion(avion);
    if (!cabeza) {
        cabeza = nuevo;
        cabeza->siguiente = cabeza;
        cabeza->anterior = cabeza;
    } else {
        NodoAvion* ultimo = cabeza->anterior;
        ultimo->siguiente = nuevo;
        nuevo->anterior = ultimo;
        nuevo->siguiente = cabeza;
        cabeza->anterior = nuevo;
    }
}

void ListaCircularDoble::eliminarAvion(const std::string& numeroRegistro) {
    if (!cabeza) return;
    NodoAvion* actual = cabeza;
    do {
        if (actual->avion->numero_de_registro == numeroRegistro) {
            if (actual->siguiente == actual) {
                delete actual->avion;
                delete actual;
                cabeza = nullptr;
                return;
            } else {
                actual->anterior->siguiente = actual->siguiente;
                actual->siguiente->anterior = actual->anterior;
                if (actual == cabeza) cabeza = actual->siguiente;
                delete actual->avion;
                delete actual;
                return;
            }
        }
        actual = actual->siguiente;
    } while (actual != cabeza);
}

Avion* ListaCircularDoble::buscarAvion(const std::string& numeroRegistro) {
    if (!cabeza) return nullptr;
    NodoAvion* actual = cabeza;
    do {
        if (actual->avion->numero_de_registro == numeroRegistro) {
            return actual->avion;
        }
        actual = actual->siguiente;
    } while (actual != cabeza);
    return nullptr;
}

void ListaCircularDoble::moverAvion(const std::string& numeroRegistro, ListaCircularDoble& otraLista) {
    Avion* avion = buscarAvion(numeroRegistro);
    if (avion) {
        eliminarAvion(numeroRegistro);
        otraLista.insertarAvion(avion);
    }
}

void ListaCircularDoble::imprimirLista() {
    if (!cabeza) return;
    NodoAvion* actual = cabeza;
    do {
        std::cout << "Vuelo: " << actual->avion->vuelo << ", Registro: " << actual->avion->numero_de_registro << std::endl;
        actual = actual->siguiente;
    } while (actual != cabeza);
}

NodoAvion *ListaCircularDoble::getCabeza() const {
    return cabeza;
}

void ListaCircularDoble::setCabeza(NodoAvion *cabeza) {
    ListaCircularDoble::cabeza = cabeza;
}
