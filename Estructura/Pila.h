#ifndef CONTROLAEROPUERTO_PILA_H
#define CONTROLAEROPUERTO_PILA_H
#include "../Objetos/Equipaje.h"
class Pila {
private:
    Equipaje* cima;

public:
    Pila();
    ~Pila();
    void apilar(int cantidad);
    int desapilar();
    bool estaVacia();

    Equipaje *getCima() const;

    void setCima(Equipaje *cima);
};
#endif // CONTROLAEROPUERTO_PILA_H
