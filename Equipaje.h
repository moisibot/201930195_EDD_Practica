
#ifndef CONTROLAEROPUERTO_EQUIPAJE_H
#define CONTROLAEROPUERTO_EQUIPAJE_H

#include <string>
#include "Pasajero.h"
using namespace std;

class Equipaje {
private:
    string idEquipaje;
    int peso;
    Pasajero* propietario;

public:
    Equipaje(string id, int p, Pasajero* prop);

    // Getters
    string getIdEquipaje() const;
    int getPeso() const;
    Pasajero* getPropietario() const;

    // Setters
    void setIdEquipaje(string id);
    void setPeso(int p);
    void setPropietario(Pasajero* prop);

    // Otros métodos
    void mostrarInfo() const;
    string getInfoPropietario() const;
};

#endif //CONTROLAEROPUERTO_EQUIPAJE_H
