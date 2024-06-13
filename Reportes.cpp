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
            NodoAvion* ultimo = nullptr;
            do {
                archivo << "  nodo" << actual << " [label=\"{{" << actual->avion->getNumeroDeRegistro() << "}|{Vuelo: " << actual->avion->getVuelo() << "\\nModelo: " << actual->avion->getModelo() << "\\nFabricante: " << actual->avion->getFabricante() << "\\nAño: " << actual->avion->getAnoFabricacion() << "\\nCapacidad: " << actual->avion->getCapacidad() << "\\nPeso Max. Despegue: " << actual->avion->getPesoMaxDespegue() << "\\nAerolinea: " << actual->avion->getAerolinea() << "\\nEstado: " << actual->avion->getEstado() << "}}\"];" << std::endl;

                if (actual->getSiguiente()) {
                    archivo << "  nodo" << actual << " -> nodo" << actual->getSiguiente() << ";" << std::endl;
                    archivo << "  nodo" << actual->getSiguiente() << " -> nodo" << actual << " [constraint=false];" << std::endl;
                } else {
                    ultimo = actual;
                }

                actual = actual->getSiguiente();
            } while (actual != avionesDisponibles.getCabeza());

            archivo << "  nodo" << ultimo << " -> nodo" << avionesDisponibles.getCabeza() << " [constraint=true];" << std::endl;
            archivo << "  nodo" << avionesDisponibles.getCabeza() << " -> nodo" << ultimo << " [constraint=false];" << std::endl;
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
            NodoAvion* ultimo = nullptr;
            do {
                archivo << "  nodo" << actual << " [label=\"{{" << actual->avion->getNumeroDeRegistro() << "}|{Vuelo: " << actual->avion->getVuelo() << "\\nModelo: " << actual->avion->getModelo() << "\\nFabricante: " << actual->avion->getFabricante() << "\\nAño: " << actual->avion->getAnoFabricacion() << "\\nCapacidad: " << actual->avion->getCapacidad() << "\\nPeso Max. Despegue: " << actual->avion->getPesoMaxDespegue() << "\\nAerolinea: " << actual->avion->getAerolinea() << "\\nEstado: " << actual->avion->getEstado() << "}}\"];" << std::endl;

                if (actual->getSiguiente()) {
                    archivo << "  nodo" << actual << " -> nodo" << actual->getSiguiente() << ";" << std::endl;
                    archivo << "  nodo" << actual->getSiguiente() << " -> nodo" << actual << " [constraint=false];" << std::endl;
                } else {
                    ultimo = actual;
                }

                actual = actual->getSiguiente();
            } while (actual != avionesMantenimiento.getCabeza());

            archivo << "  nodo" << ultimo << " -> nodo" << avionesMantenimiento.getCabeza() << " [constraint=true];" << std::endl;
            archivo << "  nodo" << avionesMantenimiento.getCabeza() << " -> nodo" << ultimo << " [constraint=false];" << std::endl;
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
        archivo << "  rankdir=LR;" << std::endl; // Orientación horizontal

        Pasajero* actual = colaRegistro.getFrente();
        int i = 0;
        while (actual) {
            archivo << "  nodo" << i << " [label=\"{No.Pasaporte: " << actual->getNumeroDePasaporte() << "\\nNombre: " << actual->getNombre() << "\\nEquipaje: " << actual->getEquipajeFacturado() << "}\"];" << std::endl;

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
        archivo << "  rankdir=LR;" << std::endl; // Orientación horizontal

        Equipaje* actual = pilaEquipaje.getCima();
        int i = 0;
        while (actual) {
            archivo << "  nodo" << i << " [label=\"{Cantidad: " << actual->getCantidad() << "}\"];" << std::endl;

            if (actual->getSiguiente()) {
                archivo << "  nodo" << i << " -> nodo" << (i + 1) << ";" << std::endl;
            }

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
        archivo << "  rankdir=LR;" << std::endl; // Orientación horizontal

        Nodo* actual = listaPasajeros.getCabeza();
        int i = 0;
        while (actual) {
            archivo << "  nodo" << i << " [label=\"{No.Pasaporte: " << actual->pasajero->getNumeroDePasaporte() << "\\nNombre: " << actual->pasajero->getNombre() << "\\nEquipaje: " << actual->pasajero->getEquipajeFacturado() << "}\"];" << std::endl;

            if (actual->siguiente) {
                archivo << "  nodo" << i << " -> nodo" << (i + 1) << ";" << std::endl;
            }

            if (actual->anterior) {
                archivo << "  nodo" << i << " -> nodo" << (i - 1) << " [constraint=false];" << std::endl;
            }

            actual = actual->siguiente;
            i++;
        }

        archivo << "}" << std::endl;
        archivo.close();
        std::cout << "Reporte de lista de pasajeros generado correctamente." << std::endl;
    } else {
        std::cout << "No se pudo crear el archivo para el reporte de lista de pasajeros." << std::endl;
    }
}