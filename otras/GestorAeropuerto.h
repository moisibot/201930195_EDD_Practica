
#ifndef CONTROLAEROPUERTO_GESTORAEROPUERTO_H
#define CONTROLAEROPUERTO_GESTORAEROPUERTO_H

#include <vector>
#include "../Avion.h"
#include "../Estructura/ListaCircularDoble.h"
#include "../Pasajero.h"
#include "../Equipaje.h"
#include "../Estructura/Cola.h"
#include "../Estructura/Pila.h"
#include "../Estructura/ListaDobleEnlazada.h"

class GestorAeropuerto {
private:
    ListaCircularDoble<Avion, string> avionesDisponibles;
    ListaCircularDoble<Avion, string> avionesMantenimiento;
    Cola<Pasajero> colaRegistro;
    Pila<Equipaje> pilaEquipaje;
    ListaDobleEnlazada<Pasajero> listaPasajeros;

public:
    void cargarAviones(const std::vector<Avion>& aviones);
    void cargarPasajeros(const std::vector<Pasajero>& pasajeros);
    void registrarPasajero();
    void procesarEquipaje();
    void moverAvion(const std::string& numeroRegistro, const std::string& nuevoEstado);
    Pasajero* buscarPasajeroPorPasaporte(const std::string& pasaporte);
    void asignarVuelosPasajeros();
    bool hayAvionesDisponibles() const;
    void cambiarEstadoAvion(const std::string& numeroRegistro, const std::string& nuevoEstado);
};
#endif //CONTROLAEROPUERTO_GESTORAEROPUERTO_H
