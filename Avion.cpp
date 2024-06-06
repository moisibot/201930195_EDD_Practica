#include "Avion.h"
#include <iostream>

Avion::Avion(string reg, string mod, int cap, string est)
        : numeroRegistro(reg), modelo(mod), capacidad(cap), estado(est) {}

// get
string Avion::getNumeroRegistro() const { return numeroRegistro; }
string Avion::getModelo() const { return modelo; }
int Avion::getCapacidad() const { return capacidad; }
string Avion::getEstado() const { return estado; }

// set
void Avion::setNumeroRegistro(string reg) { numeroRegistro = reg; }
void Avion::setModelo(string mod) { modelo = mod; }
void Avion::setCapacidad(int cap) { capacidad = cap; }
void Avion::setEstado(string est) { estado = est; }

// info de los aviones
void Avion::mostrarInfo() const {
    cout << "Avion " << numeroRegistro << " - " << modelo
         << " (Capacidad: " << capacidad << ", Estado: " << estado << ")" << endl;
}
bool Avion::operator==(const Avion& otro) const {
    return numeroRegistro == otro.numeroRegistro;
}

bool Avion::estaDisponible() const { return estado == "Disponible"; }