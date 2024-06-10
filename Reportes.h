#ifndef CONTROLAEROPUERTO_REPORTES_H
#define CONTROLAEROPUERTO_REPORTES_H
#include "Estructura/ListaCircularDoble.h"
#include "Estructura/Cola.h"
#include "Estructura/ListaDoblementeEnlazada.h"
#include "Estructura/Pila.h"

void generarReporteAvionesDisponibles(ListaCircularDoble& avionesDisponibles, const std::string& nombreArchivo);
void generarReporteAvionesMantenimiento(ListaCircularDoble& avionesMantenimiento, const std::string& nombreArchivo);
void generarReporteColaRegistro(Cola& colaRegistro, const std::string& nombreArchivo);
void generarReportePilaEquipaje(Pila& pilaEquipaje, const std::string& nombreArchivo);
void generarReporteListaPasajeros(ListaDoblementeEnlazada& listaPasajeros, const std::string& nombreArchivo);

#endif//CONTROLAEROPUERTO_REPORTES_H
