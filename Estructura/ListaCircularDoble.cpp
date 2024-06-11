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

void ListaCircularDoble::insertarNodo(NodoAvion* nodoAvion) {
    if (!cabeza) {
        cabeza = nodoAvion;
        nodoAvion->siguiente = nodoAvion;
        nodoAvion->anterior = nodoAvion;
    } else {
        NodoAvion* ultimo = cabeza->anterior;
        ultimo->siguiente = nodoAvion;
        nodoAvion->anterior = ultimo;
        nodoAvion->siguiente = cabeza;
        cabeza->anterior = nodoAvion;
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

NodoAvion* ListaCircularDoble::buscarAvion(const std::string& numeroRegistro) {
    if (!cabeza) return nullptr;
    NodoAvion* actual = cabeza;
    do {
        if (actual->avion->numero_de_registro == numeroRegistro) {
            return actual;
        }
        actual = actual->siguiente;
    } while (actual != cabeza);
    return nullptr;
}

void ListaCircularDoble::moverAvion(const std::string& numeroRegistro, ListaCircularDoble& otraLista) {
    NodoAvion* nodoAvion = buscarAvion(numeroRegistro);
    if (nodoAvion) {
        if (nodoAvion == cabeza) {
            if (cabeza->siguiente == cabeza) {
                cabeza = nullptr;
            } else {
                NodoAvion* ultimo = cabeza->anterior;
                cabeza = cabeza->siguiente;
                cabeza->anterior = ultimo;
                ultimo->siguiente = cabeza;

            }
        } else {
            nodoAvion->anterior->siguiente = nodoAvion->siguiente;
            nodoAvion->siguiente->anterior = nodoAvion->anterior;
        }
        otraLista.insertarNodo(nodoAvion);
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