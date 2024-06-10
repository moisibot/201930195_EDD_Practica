#ifndef CONTROLAEROPUERTO_NODO_H
#define CONTROLAEROPUERTO_NODO_H
#include "../Objetos/Pasajero.h"
class Nodo {
public:
    Pasajero* pasajero;
    Nodo* siguiente;
    Nodo* anterior;
    Nodo(Pasajero* pasajero);

    Pasajero *getPasajero() const;

    void setPasajero(Pasajero *pasajero);

    Nodo *getSiguiente() const;

    void setSiguiente(Nodo *siguiente);

    Nodo *getAnterior() const;

    void setAnterior(Nodo *anterior);
};
#endif //CONTROLAEROPUERTO_NODO_H
