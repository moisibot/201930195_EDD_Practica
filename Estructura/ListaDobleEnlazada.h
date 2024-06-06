#ifndef CONTROLAEROPUERTO_LISTADOBLEENLAZADA_H
#define CONTROLAEROPUERTO_LISTADOBLEENLAZADA_H
#include "Nodo.h"
#include <stdexcept>

template <typename T>
class ListaDobleEnlazada {
private:
    Nodo<T>* cabeza;
    Nodo<T>* cola;
    int tamaño;

public:
    ListaDobleEnlazada() : cabeza(nullptr), cola(nullptr), tamaño(0) {}
    ~ListaDobleEnlazada();

    void insertar(T dato);
    void insertarOrdenado(T dato, bool (*compararPor)(T, T));
    bool eliminar(T dato);
    T* buscar(T dato);
    void mostrar() const;
    int getTamaño() const { return tamaño; }
    bool estaVacia() const { return tamaño == 0; }
    void ordenarPorVueloYAsiento();

    //virtual ~ListaDobleEnlazada();
    typedef Nodo<T>* Iterador;

    Iterador begin() const {
        return cabeza;
    }

    Iterador end() const {
        return nullptr;
    }
};

template <typename T>
void ListaDobleEnlazada<T>::insertar(T dato) {
    Nodo<T>* nuevoNodo = new Nodo<T>(dato);
    if (estaVacia()) {
        cabeza = cola = nuevoNodo;
    } else {
        nuevoNodo->anterior = cola;
        cola->siguiente = nuevoNodo;
        cola = nuevoNodo;
    }
    tamaño++;
}

template<typename Pasajero>
ListaDobleEnlazada<Pasajero>::~ListaDobleEnlazada() {
}


#endif //CONTROLAEROPUERTO_LISTADOBLEENLAZADA_H
