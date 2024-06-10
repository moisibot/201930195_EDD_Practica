#include "ListaDoblementeEnlazada.h"
#include <iostream>

ListaDoblementeEnlazada::ListaDoblementeEnlazada() : cabeza(nullptr), cola(nullptr) {}

ListaDoblementeEnlazada::~ListaDoblementeEnlazada() {
    Nodo* actual = cabeza;
    while (actual) {
        Nodo* temp = actual;
        actual = actual->siguiente;
        delete temp->pasajero;
        delete temp;
    }
}

void ListaDoblementeEnlazada::insertarPasajero(Pasajero* pasajero) {
    Nodo* nuevo = new Nodo(pasajero);
    if (!cabeza) {
        cabeza = cola = nuevo;
    } else {
        cola->siguiente = nuevo;
        nuevo->anterior = cola;
        cola = nuevo;
    }
}

void ListaDoblementeEnlazada::eliminarPasajero(const std::string& numero_de_pasaporte) {
    Nodo* actual = cabeza;
    while (actual) {
        if (actual->pasajero->numero_de_pasaporte == numero_de_pasaporte) {
            if (actual == cabeza) {
                cabeza = cabeza->siguiente;
                if (cabeza) cabeza->anterior = nullptr;
            } else if (actual == cola) {
                cola = cola->anterior;
                if (cola) cola->siguiente = nullptr;
            } else {
                actual->anterior->siguiente = actual->siguiente;
                actual->siguiente->anterior = actual->anterior;
            }
            delete actual->pasajero;
            delete actual;
            return;
        }
        actual = actual->siguiente;
    }
}

Pasajero* ListaDoblementeEnlazada::buscarPasajero(const std::string& numero_de_pasaporte) {
    Nodo* actual = cabeza;
    while (actual) {
        if (actual->pasajero->numero_de_pasaporte == numero_de_pasaporte) {
            return actual->pasajero;
        }
        actual = actual->siguiente;
    }
    return nullptr;
}

void ListaDoblementeEnlazada::imprimirLista() {
    Nodo* actual = cabeza;
    while (actual) {
        std::cout << "Nombre: " << actual->pasajero->nombre << ", Pasaporte: " << actual->pasajero->numero_de_pasaporte << std::endl;
        actual = actual->siguiente;
    }
}

Nodo *ListaDoblementeEnlazada::getCabeza() const {
    return cabeza;
}

void ListaDoblementeEnlazada::setCabeza(Nodo *cabeza) {
    ListaDoblementeEnlazada::cabeza = cabeza;
}

Nodo *ListaDoblementeEnlazada::getCola() const {
    return cola;
}

void ListaDoblementeEnlazada::setCola(Nodo *cola) {
    ListaDoblementeEnlazada::cola = cola;
}
