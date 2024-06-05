#include "Equipaje.h"
#include <iostream>

Equipaje::Equipaje(string id, int p, Pasajero* prop)
        : idEquipaje(id), peso(p), propietario(prop) {}

// Getters
string Equipaje::getIdEquipaje() const { return idEquipaje; }
int Equipaje::getPeso() const { return peso; }
Pasajero* Equipaje::getPropietario() const { return propietario; }

// Setters
void Equipaje::setIdEquipaje(string id) { idEquipaje = id; }
void Equipaje::setPeso(int p) { peso = p; }
void Equipaje::setPropietario(Pasajero* prop) { propietario = prop; }

// Otros métodos
void Equipaje::mostrarInfo() const {
    cout << "Equipaje ID: " << idEquipaje << " (Peso: " << peso << " kg)" << endl
         << "  Propietario: " << getInfoPropietario() << endl;
}

string Equipaje::getInfoPropietario() const {
    return propietario ? propietario->getNombreCompleto() + " - Vuelo: " + propietario->getNumeroVuelo()
                       : "Desconocido";
}