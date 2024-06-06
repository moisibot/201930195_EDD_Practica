#ifndef CONTROLAEROPUERTO_PILA_H
#define CONTROLAEROPUERTO_PILA_H
#include "Nodo.h"
#include <stdexcept>

template <typename T>
class Pila {
private:
    Nodo<T>* tope;
    int tamaño;

public:
    Pila() : tope(nullptr), tamaño(0) {}
    ~Pila();

    void push(T dato);
    T pop();
    T peek() const;
    bool estaVacia() const { return tamaño == 0; }
    int getTamaño() const { return tamaño; }

   // virtual ~Pila();
};

template <typename T>
void Pila<T>::push(T dato) {
    Nodo<T>* nuevoNodo = new Nodo<T>(dato);
    nuevoNodo->siguiente = tope;
    tope = nuevoNodo;
    tamaño++;
}

template <typename T>
T Pila<T>::pop() {
    if (estaVacia()) throw std::out_of_range("La pila está vacía");
    T dato = tope->dato;
    Nodo<T>* temp = tope;
    tope = tope->siguiente;
    delete temp;
    tamaño--;
    return dato;
}

template<typename Equipaje>
Pila<Equipaje>::~Pila() {
}
#endif //CONTROLAEROPUERTO_PILA_H
