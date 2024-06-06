#ifndef CONTROLAEROPUERTO_AVION_H
#define CONTROLAEROPUERTO_AVION_H
#include <string>

using namespace std;

class Avion {
private:
    string numeroRegistro;
    string modelo;
    int capacidad;
    string estado;  // "Disponible" o "Mantenimiento"

public:
    Avion(string reg, string mod, int cap, string est = "Disponible");

    // get
    string getNumeroRegistro() const;
    string getModelo() const;
    int getCapacidad() const;
    string getEstado() const;

    // set
    void setNumeroRegistro(string reg);
    void setModelo(string mod);
    void setCapacidad(int cap);
    void setEstado(string est);

    //  info de los aviones
    void mostrarInfo() const;
    bool estaDisponible() const;
    bool operator==(const Avion& otro) const;
};

#endif //CONTROLAEROPUERTO_AVION_H
