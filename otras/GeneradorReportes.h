

#ifndef CONTROLAEROPUERTO_GENERADORREPORTES_H
#define CONTROLAEROPUERTO_GENERADORREPORTES_H

#include <string>
#include "GestorAeropuerto.h"

class GeneradorReportes {
public:
    static void generarReporteAvionesDisponibles(const ListaCircularDoble<Avion, string>& aviones);
    static void generarReporteAvionesMantenimiento(const ListaCircularDoble<Avion, string>& aviones);
    static void generarReporteColaRegistro(const Cola<Pasajero>& cola);
    static void generarReportePilaEquipaje(const Pila<Equipaje>& pila);
    static void generarReporteListaPasajeros(const ListaDobleEnlazada<Pasajero>& lista);

private:
    static std::string generarDotAvion(const Avion& avion);
    static std::string generarDotPasajero(const Pasajero& pasajero);
    static std::string generarDotEquipaje(const Equipaje& equipaje);
    static void escribirArchivoDot(const std::string& contenido, const std::string& nombre);
    static void ejecutarGraphviz(const std::string& nombre);
};

#endif //CONTROLAEROPUERTO_GENERADORREPORTES_H
