

#ifndef CONTROLAEROPUERTO_PASAJERO_H
#define CONTROLAEROPUERTO_PASAJERO_H

#include <string>
using namespace std;

class Pasajero {
private:
    string numeroPasaporte;
    string nombre;
    string apellido;
    string numeroVuelo;
    string numeroAsiento;
    int pesoEquipaje;  // 0 si no tiene equipaje

public:
    Pasajero(string pasaporte, string nom, string ape, string vuelo, string asiento, int pesoEq = 0);

    // Getters
    string getNumeroPasaporte() const;
    string getNombre() const;
    string getApellido() const;
    string getNombreCompleto() const;
    string getNumeroVuelo() const;
    string getNumeroAsiento() const;
    int getPesoEquipaje() const;

    // Setters
    void setNumeroPasaporte(string pasaporte);
    void setNombre(string nom);
    void setApellido(string ape);
    void setNumeroVuelo(string vuelo);
    void setNumeroAsiento(string asiento);
    void setPesoEquipaje(int peso);

    // Otros métodos
    void mostrarInfo() const;
    bool tieneEquipaje() const;
};


#endif //CONTROLAEROPUERTO_PASAJERO_H
