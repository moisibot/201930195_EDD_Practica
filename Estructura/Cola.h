#ifndef CONTROLAEROPUERTO_COLA_H
#define CONTROLAEROPUERTO_COLA_H
#include "Nodo.h"
#include <stdexcept>

template <typename T>
class Cola {
private:
    Nodo<T>* frente;
    Nodo<T>* final;
    int tamaño;
public:
    Cola() : frente(nullptr), final(nullptr), tamaño(0) {}
    ~Cola();
    void encolar(T dato);
    T desencolar();
    T verFrente() const;
    bool estaVacia() const { return tamaño == 0; }
    int getTamaño() const { return tamaño; }
};

template <typename T>
Cola<T>::~Cola() {
    while (!estaVacia()) {
        desencolar();
    }
}

template <typename T>
void Cola<T>::encolar(T dato) {
    Nodo<T>* nuevoNodo = new Nodo<T>(dato);
    if (estaVacia()) {
        frente = final = nuevoNodo;
    } else {
        final->siguiente = nuevoNodo;
        final = nuevoNodo;
    }
    tamaño++;
}

template <typename T>
T Cola<T>::desencolar() {
    if (estaVacia()) throw std::out_of_range("La cola está vacía");
    T dato = frente->dato;
    Nodo<T>* temp = frente;
    frente = frente->siguiente;
    delete temp;
    tamaño--;
    if (tamaño == 0) final = nullptr;
    return dato;
}
/*
template<typename Pasajero>
Cola<Pasajero>::~Cola() {
}*/
#endif //CONTROLAEROPUERTO_COLA_H
