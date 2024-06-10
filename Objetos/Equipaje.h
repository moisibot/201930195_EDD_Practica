#ifndef CONTROLAEROPUERTO_EQUIPAJE_H
#define CONTROLAEROPUERTO_EQUIPAJE_H
#include <string>
#include "Pasajero.h"
using namespace std;
class Equipaje {
public:
    int cantidad;
    Equipaje* siguiente;

    int getCantidad() const;

    void setCantidad(int cantidad);

    Equipaje *getSiguiente() const;

    void setSiguiente(Equipaje *siguiente);

    Equipaje(int cantidad);
};
#endif //CONTROLAEROPUERTO_EQUIPAJE_H
