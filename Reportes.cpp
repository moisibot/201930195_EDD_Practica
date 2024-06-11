#include "Reportes.h"
#include <fstream>
#include <string>
#include <iostream>
#include "Estructura/Cola.h"
#include "Estructura/Pila.h"

void generarReporteAvionesDisponibles(ListaCircularDoble& avionesDisponibles, const std::string& nombreArchivo) {
    std::ofstream archivo(nombreArchivo + ".dot");
    if (archivo.is_open()) {
        archivo << "digraph AvionesDisponibles {" << std::endl;
        archivo << "  node [shape=record];" << std::endl;

        NodoAvion* actual = avionesDisponibles.getCabeza();
        if (actual) {
            do {
                archivo << "  nodo" << actual << " [label=\"{{" << actual->avion->getNumeroDeRegistro() << "}|{Vuelo: " << actual->avion->getVuelo() << "\\nModelo: " << actual->avion->getModelo() << "\\nFabricante: " << actual->avion->getFabricante() << "\\nAño: " << actual->avion->getAnoFabricacion() << "\\nCapacidad: " << actual->avion->getCapacidad() << "\\nPeso Max. Despegue: " << actual->avion->getPesoMaxDespegue() << "\\nAerolinea: " << actual->avion->getAerolinea() << "\\nEstado: " << actual->avion->getEstado() << "}}\"];" << std::endl;

                if (actual->getSiguiente()) {
                    archivo << "  nodo" << actual << " -> nodo" << actual->getSiguiente() << ";" << std::endl;
                } else {
                    archivo << "  nodo" << actual << " -> nodo" << avionesDisponibles.getCabeza() << " [constraint=false];" << std::endl;
                }

                actual = actual->getSiguiente();
            } while (actual != avionesDisponibles.getCabeza());
        }

        archivo << "}" << std::endl;
        archivo.close();
        std::cout << "Reporte de aviones disponibles generado correctamente." << std::endl;
    } else {
        std::cout << "No se pudo crear el archivo para el reporte de aviones disponibles." << std::endl;
    }
}

void generarReporteAvionesMantenimiento(ListaCircularDoble& avionesMantenimiento, const std::string& nombreArchivo) {
    std::ofstream archivo(nombreArchivo + ".dot");
    if (archivo.is_open()) {
        archivo << "digraph AvionesMantenimiento {" << std::endl;
        archivo << "  node [shape=record];" << std::endl;

        NodoAvion* actual = avionesMantenimiento.getCabeza();
        if (actual) {
            do {
                archivo << "  nodo" << actual << " [label=\"{{" << actual->avion->getNumeroDeRegistro() << "}|{Vuelo: " << actual->avion->getVuelo() << "\\nModelo: " << actual->avion->getModelo() << "\\nFabricante: " << actual->avion->getFabricante() << "\\nAño: " << actual->avion->getAnoFabricacion() << "\\nCapacidad: " << actual->avion->getCapacidad() << "\\nPeso Max. Despegue: " << actual->avion->getPesoMaxDespegue() << "\\nAerolinea: " << actual->avion->getAerolinea() << "\\nEstado: " << actual->avion->getEstado() << "}}\"];" << std::endl;

                if (actual->getSiguiente()) {
                    archivo << "  nodo" << actual << " -> nodo" << actual->getSiguiente() << ";" << std::endl;
                } else {
                    archivo << "  nodo" << actual << " -> nodo" << avionesMantenimiento.getCabeza() << " [constraint=false];" << std::endl;
                }

                actual = actual->getSiguiente();
            } while (actual != avionesMantenimiento.getCabeza());
        }

        archivo << "}" << std::endl;
        archivo.close();
        std::cout << "Reporte de aviones en mantenimiento generado correctamente." << std::endl;
    } else {
        std::cout << "No se pudo crear el archivo para el reporte de aviones en mantenimiento." << std::endl;
    }
}

void generarReporteColaRegistro(Cola& colaRegistro, const std::string& nombreArchivo) {
    std::ofstream archivo(nombreArchivo + ".dot");
    if (archivo.is_open()) {
        archivo << "digraph ColaRegistro {" << std::endl;
        archivo << "  node [shape=record];" << std::endl;
        Pasajero* actual = colaRegistro.getFrente(); // Actualiza aquí si la función se llama de otra manera
        int i = 0;
        while (actual) {
            archivo << "  nodo" << i << " [label=\"{{" << actual->getNumeroDePasaporte() << "}|{Nombre: " << actual->getNombre() << "\\nVuelo: " << actual->getVuelo() << "\\nAsiento: " << actual->getAsiento() << "\\nDestino: " << actual->getDestino() << "\\nOrigen: " << actual->getOrigen() << "\\nEquipaje: " << actual->getEquipajeFacturado() << "}}\"];" << std::endl;

            if (actual->getSiguiente()) {
                archivo << "  nodo" << i << " -> nodo" << (i + 1) << ";" << std::endl;
            }

            actual = actual->getSiguiente();
            i++;
        }

        archivo << "}" << std::endl;
        archivo.close();
        std::cout << "Reporte de cola de registro generado correctamente." << std::endl;
    } else {
        std::cout << "No se pudo crear el archivo para el reporte de cola de registro." << std::endl;
    }
}

void generarReportePilaEquipaje(Pila& pilaEquipaje, const std::string& nombreArchivo) {
    std::ofstream archivo(nombreArchivo + ".dot");
    if (archivo.is_open()) {
        archivo << "digraph PilaEquipaje {" << std::endl;
        archivo << "  node [shape=record];" << std::endl;

        Equipaje* actual = pilaEquipaje.getCima();
        Equipaje* anterior = nullptr;
        int i = 0;
        while (actual) {
            archivo << "  nodo" << i << " [label=\"{Cantidad: " << actual->getCantidad() << "}\"];" << std::endl;

            if (anterior) {
                archivo << "  nodo" << i << " -> nodo" << (i - 1) << ";" << std::endl;
            }

            anterior = actual;
            actual = actual->getSiguiente();
            i++;
        }

        archivo << "}" << std::endl;
        archivo.close();
        std::cout << "Reporte de pila de equipaje generado correctamente." << std::endl;
    } else {
        std::cout << "No se pudo crear el archivo para el reporte de pila de equipaje." << std::endl;
    }
}

void generarReporteListaPasajeros(ListaDoblementeEnlazada& listaPasajeros, const std::string& nombreArchivo) {
    std::ofstream archivo(nombreArchivo + ".dot");
    if (archivo.is_open()) {
        archivo << "digraph ListaPasajeros {" << std::endl;
        archivo << "  node [shape=record];" << std::endl;

        Nodo* actual = listaPasajeros.getCabeza();
        if (actual) { // Verifica si la lista no está vacía
            int i = 0;
            while (actual) {
                archivo << "  nodo" << i << " [label=\"{{" << actual->pasajero->getNumeroDePasaporte() << "}|{Nombre: " << actual->pasajero->getNombre() << "\\nVuelo: " << actual->pasajero->getVuelo() << "\\nAsiento: " << actual->pasajero->getAsiento() << "\\nDestino: " << actual->pasajero->getDestino() << "\\nOrigen: " << actual->pasajero->getOrigen() << "\\nEquipaje: " << actual->pasajero->getEquipajeFacturado() << "}}\"];" << std::endl;

                if (actual->getSiguiente()) {
                    archivo << "  nodo" << i << " -> nodo" << (i + 1) << ";" << std::endl;
                }

                actual = actual->getSiguiente();
                i++;
            }
        } else {
            std::cout << "La lista de pasajeros está vacía." << std::endl;
        }

        archivo << "}" << std::endl;
        archivo.close();
        std::cout << "Reporte de lista de pasajeros generado correctamente." << std::endl;
    } else {
        std::cout << "No se pudo crear el archivo para el reporte de lista de pasajeros." << std::endl;
    }
}