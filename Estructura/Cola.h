#ifndef CONTROLAEROPUERTO_COLA_H
#define CONTROLAEROPUERTO_COLA_H
#include "../Objetos/Pasajero.h"
class Cola {
private:
    Pasajero* frente;
    Pasajero* final;

public:
    Cola();
    ~Cola();
    void encolar(Pasajero* pasajero);
    Pasajero* desencolar();
    bool estaVacia();

    Pasajero *getFrente() const;

    void setFrente(Pasajero *frente);

    Pasajero *getFinal() const;

    void setFinal(Pasajero *final);
};
#endif// CONTROLAEROPUERTO_COLA_H
