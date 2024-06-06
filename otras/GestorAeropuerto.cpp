#include "GestorAeropuerto.h"

void GestorAeropuerto::cargarAviones(const vector<Avion>& aviones) {
    for (const auto& avion : aviones) {
        if (avion.getEstado() == "Disponible")
            avionesDisponibles.insertar(avion);
        else
            avionesMantenimiento.insertar(avion);
    }
}

void GestorAeropuerto::registrarPasajero() {
    if (!colaRegistro.estaVacia()) {
        Pasajero p = colaRegistro.desencolar();
        listaPasajeros.insertar(p);
        if (p.tieneEquipaje()) {
            pilaEquipaje.push(Equipaje(p.getNumeroPasaporte(), p.getPesoEquipaje(), &p));
        }
    }
}

void GestorAeropuerto::asignarVuelosPasajeros() {
    if (!hayAvionesDisponibles()) return;

    Avion avion = avionesDisponibles.pop();
    int asientosAsignados = 0;
    while (!colaRegistro.estaVacia() && asientosAsignados < avion.getCapacidad()) {
        Pasajero p = colaRegistro.desencolar();
        p.setNumeroVuelo(avion.getNumeroRegistro());
        p.setNumeroAsiento(to_string(asientosAsignados + 1));
        listaPasajeros.insertar(p);
        asientosAsignados++;
    }
    avionesMantenimiento.insertar(avion);  // Mover a mantenimiento después del vuelo
}
void GestorAeropuerto::moverAvion(const std::string& numeroRegistro, const std::string& nuevoEstado) {
    Avion* avion = avionesDisponibles.buscar(numeroRegistro);
    if (avion) {
        avionesDisponibles.eliminar(*avion);
        avionesDisponibles.moverEntreEstados(avion, nuevoEstado);
    } else {
        avion = avionesMantenimiento.buscar(numeroRegistro);
        if (avion) {
            avionesMantenimiento.eliminar(*avion);
            avionesMantenimiento.moverEntreEstados(avion, nuevoEstado);
        }
    }
}
bool GestorAeropuerto::hayAvionesDisponibles() const {
    return !avionesDisponibles.estaVacia();
}

void GestorAeropuerto::cargarPasajeros(const std::vector<Pasajero>& pasajeros) {
    for (const auto& pasajero : pasajeros) {
        colaRegistro.encolar(pasajero);
    }
}

Pasajero* GestorAeropuerto::buscarPasajeroPorPasaporte(const std::string& pasaporte) {
    for (auto it = listaPasajeros.begin(); it != listaPasajeros.end(); it = it->siguiente) {
        if (it->dato.getNumeroPasaporte() == pasaporte) {
            return &(it->dato);
        }
    }
    return nullptr;
}
