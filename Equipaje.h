
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

    // get
    string getIdEquipaje() const;
    int getPeso() const;
    Pasajero* getPropietario() const;

    // set
    void setIdEquipaje(string id);
    void setPeso(int p);
    void setPropietario(Pasajero* prop);

    //  mostrar informacion de los equipajes
    void mostrarInfo() const;
    string getInfoPropietario() const;
};

#endif //CONTROLAEROPUERTO_EQUIPAJE_H
