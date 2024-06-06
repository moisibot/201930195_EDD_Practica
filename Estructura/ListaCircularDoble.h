#ifndef CONTROLAEROPUERTO_LISTACIRCULARDOBLE_H
#define CONTROLAEROPUERTO_LISTACIRCULARDOBLE_H
#include <string>
#include <stdexcept>
#include "Nodo.h"

template <typename T, typename EstadoType>
class ListaCircularDoble {
private:
    Nodo<T>* cabeza;
    int tamaño;
    struct Iterador {
        Nodo<T>* nodo;

        Iterador(Nodo<T>* n) : nodo(n) {}

        T& operator*() { return nodo->dato; }

        Iterador& operator++() {
            nodo = nodo->siguiente;
            return *this;
        }

        bool operator!=(const Iterador& other) const {
            return nodo != other.nodo;
        }
    };

public:
    ListaCircularDoble() : cabeza(nullptr), tamaño(0) {}
    ~ListaCircularDoble();

    void insertar(T dato);
    bool eliminar(T dato);
    T* buscar(T dato);
    void mostrar() const;
    int getTamaño() const { return tamaño; }
    bool estaVacia() const { return tamaño == 0; }

    T pop();
    T* buscar(const std::string& numeroRegistro);
   // void moverEntreEstados(T& dato, EstadoType nuevoEstado);

    // Específico para Aviones
    void moverEntreEstados(T* dato, EstadoType nuevoEstado);
    Iterador begin() const {
        return Iterador(cabeza);
    }

    Iterador end() const {
        return Iterador(nullptr);
    }

  //  virtual ~ListaCircularDoble();

};

// La implementación iría aquí
template <typename T, typename EstadoType>
void ListaCircularDoble<T, EstadoType>::moverEntreEstados(T* dato, EstadoType nuevoEstado) {
    if (dato) {
        // Aquí llamaría al método setEstado() de la clase T
        dato->setEstado(nuevoEstado);
        insertar(*dato); // Insertar de nuevo en la lista con el nuevo estado
    }
}

template <typename T, typename EstadoType>
T* ListaCircularDoble<T, EstadoType>::buscar(const std::string& numeroRegistro) {
    Nodo<T>* actual = cabeza;
    if (!actual) return nullptr;

    do {
        if (actual->dato.getNumeroRegistro() == numeroRegistro) {
            return &(actual->dato);
        }
        actual = actual->siguiente;
    } while (actual != cabeza);

    return nullptr;
}

template<typename T, typename EstadoType>
ListaCircularDoble<T, EstadoType>::~ListaCircularDoble() {
    Nodo<T>* actual = cabeza;
    if (actual) {
        do {
            Nodo<T>* temp = actual->siguiente;
            delete actual;
            actual = temp;
        } while (actual != cabeza);
    }
}
template<typename T, typename EstadoType>
void ListaCircularDoble<T, EstadoType>::insertar(T dato) {
    Nodo<T>* nuevoNodo = new Nodo<T>(dato);
    if (cabeza == nullptr) {
        cabeza = nuevoNodo;
        nuevoNodo->siguiente = nuevoNodo;
        nuevoNodo->anterior = nuevoNodo;
    } else {
        Nodo<T>* ultimo = cabeza->anterior;
        nuevoNodo->siguiente = cabeza;
        nuevoNodo->anterior = ultimo;
        ultimo->siguiente = nuevoNodo;
        cabeza->anterior = nuevoNodo;
    }
    tamaño++;
}
template <typename T, typename EstadoType>
T ListaCircularDoble<T, EstadoType>::pop() {
    if (cabeza == nullptr) {
        throw std::out_of_range("La lista está vacía");
    }

    Nodo<T>* temp = cabeza;
    T dato = temp->dato;

    if (cabeza == cabeza->siguiente) {
        cabeza = nullptr;
    } else {
        cabeza->anterior->siguiente = cabeza->siguiente;
        cabeza->siguiente->anterior = cabeza->anterior;
        cabeza = cabeza->siguiente;
    }

    delete temp;
    tamaño--;
    return dato;
}

template <typename T, typename EstadoType>
bool ListaCircularDoble<T, EstadoType>::eliminar(T dato) {
    Nodo<T>* actual = cabeza;
    if (!actual) return false;

    do {
        if (actual->dato == dato) {
            if (actual == cabeza) {
                if (cabeza == cabeza->siguiente) {
                    cabeza = nullptr;
                } else {
                    cabeza->anterior->siguiente = cabeza->siguiente;
                    cabeza->siguiente->anterior = cabeza->anterior;
                    cabeza = cabeza->siguiente;
                }
            } else {
                actual->anterior->siguiente = actual->siguiente;
                actual->siguiente->anterior = actual->anterior;
            }

            delete actual;
            tamaño--;
            return true;
        }

        actual = actual->siguiente;
    } while (actual != cabeza);

    return false;
}
#endif //CONTROLAEROPUERTO_LISTACIRCULARDOBLE_H
