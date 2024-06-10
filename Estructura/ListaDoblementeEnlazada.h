#ifndef CONTROLAEROPUERTO_LISTADOBLEMENTEENLAZADA_H
#define CONTROLAEROPUERTO_LISTADOBLEMENTEENLAZADA_H
#include "../Objetos/Pasajero.h"
#include "Nodo.h"
class ListaDoblementeEnlazada {
private:
    Nodo* cabeza;
    Nodo* cola;
public:
    ListaDoblementeEnlazada();
    ~ListaDoblementeEnlazada();
    void insertarPasajero(Pasajero* pasajero);
    void eliminarPasajero(const std::string& numero_de_pasaporte);
    Pasajero* buscarPasajero(const std::string& numero_de_pasaporte);
    void imprimirLista();

    Nodo *getCabeza() const;

    void setCabeza(Nodo *cabeza);

    Nodo *getCola() const;

    void setCola(Nodo *cola);
};
#endif // CONTROLAEROPUERTO_LISTADOBLEMENTEENLAZADA_H
