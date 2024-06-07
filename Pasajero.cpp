#include "Pasajero.h"
#include <iostream>
Pasajero::Pasajero(string pasaporte, string nom, string ape, string vuelo, string asiento, int pesoEq)
        : numeroPasaporte(pasaporte), nombre(nom), apellido(ape), numeroVuelo(vuelo),
          numeroAsiento(asiento), pesoEquipaje(pesoEq) {}
// get
string Pasajero::getNumeroPasaporte() const { return numeroPasaporte; }
string Pasajero::getNombre() const { return nombre; }
string Pasajero::getApellido() const { return apellido; }
string Pasajero::getNombreCompleto() const { return nombre + " " + apellido; }
string Pasajero::getNumeroVuelo() const { return numeroVuelo; }
string Pasajero::getNumeroAsiento() const { return numeroAsiento; }
int Pasajero::getPesoEquipaje() const { return pesoEquipaje; }
// set
void Pasajero::setNumeroPasaporte(string pasaporte) { numeroPasaporte = pasaporte; }
void Pasajero::setNombre(string nom) { nombre = nom; }
void Pasajero::setApellido(string ape) { apellido = ape; }
void Pasajero::setNumeroVuelo(string vuelo) { numeroVuelo = vuelo; }
void Pasajero::setNumeroAsiento(string asiento) { numeroAsiento = asiento; }
void Pasajero::setPesoEquipaje(int peso) { pesoEquipaje = peso; }
// varios métodos
void Pasajero::mostrarInfo() const {
    cout << "Pasajero: " << getNombreCompleto() << " (Pasaporte: " << numeroPasaporte << ")" << endl
         << "  Vuelo: " << numeroVuelo << ", Asiento: " << numeroAsiento << endl
         << "  Equipaje: " << (tieneEquipaje() ? to_string(pesoEquipaje) + " kg" : "No") << endl;
}
bool Pasajero::tieneEquipaje() const { return pesoEquipaje > 0; }