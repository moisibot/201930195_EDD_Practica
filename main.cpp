#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "nlohmann/json.hpp"
#include "Objetos/Avion.h"
#include "Objetos/Pasajero.h"
#include "Objetos/Equipaje.h"
#include "Estructura/ListaCircularDoble.h"
#include "Estructura/Cola.h"
#include "Estructura/Pila.h"
#include "Estructura/ListaDoblementeEnlazada.h"
#include "Reportes.h"
using namespace std;
using json = nlohmann::json;
void cargarAviones(const std::string& archivoAviones, ListaCircularDoble& listaAvionesDisponibles, ListaCircularDoble& listaAvionesMantenimiento) {
    std::ifstream archivo(archivoAviones);
    if (archivo.is_open()) {
        std::cout << "Archivo de aviones abierto correctamente." << std::endl;
        std::string contenido;
        archivo.seekg(0, std::ios::end);
        contenido.resize(archivo.tellg());
        archivo.seekg(0, std::ios::beg);
        archivo.read(&contenido[0], contenido.size());
        archivo.close();

        json datos = json::parse(contenido);
        for (const auto& avion : datos) {
            std::string vuelo = avion["vuelo"];
            std::string numeroRegistro = avion["numero_de_registro"];
            std::string modelo = avion["modelo"];
            std::string fabricante = avion["fabricante"];
            int anoFabricacion = avion["ano_fabricacion"];
            int capacidad = avion["capacidad"];
            int pesoMaxDespegue = avion["peso_max_despegue"];
            std::string aerolinea = avion["aerolinea"];
            std::string estado = avion["estado"];

            Avion* nuevoAvion = new Avion(vuelo, numeroRegistro, modelo, fabricante, anoFabricacion, capacidad, pesoMaxDespegue, aerolinea, estado);
            if (estado == "Disponible") {
                listaAvionesDisponibles.insertarAvion(nuevoAvion);
            } else {
                listaAvionesMantenimiento.insertarAvion(nuevoAvion);
            }
        }
    } else {
        std::cout << "No se pudo abrir el archivo de aviones." << std::endl;
    }
}

void cargarPasajeros(const std::string& archivoPasajeros, ListaDoblementeEnlazada& listaPasajeros) {
    std::ifstream archivo(archivoPasajeros);
    if (archivo.is_open()) {
        std::cout << "Archivo de pasajeros abierto correctamente." << std::endl;
        std::string contenido;
        archivo.seekg(0, std::ios::end);
        contenido.resize(archivo.tellg());
        archivo.seekg(0, std::ios::beg);
        archivo.read(&contenido[0], contenido.size());
        archivo.close();

        json datos = json::parse(contenido);
        for (const auto& pasajero : datos) {
            std::string nombre = pasajero["nombre"];
            std::string nacionalidad = pasajero["nacionalidad"];
            std::string numeroPasaporte = pasajero["numero_de_pasaporte"];
            std::string vuelo = pasajero["vuelo"];
            int asiento = pasajero["asiento"];
            std::string destino = pasajero["destino"];
            std::string origen = pasajero["origen"];
            int equipajeFacturado = pasajero["equipaje_facturado"];

            Pasajero* nuevoPasajero = new Pasajero(nombre, nacionalidad, numeroPasaporte, vuelo, asiento, destino, origen, equipajeFacturado);
            listaPasajeros.insertarPasajero(nuevoPasajero);
        }
    } else {
        std::cout << "No se pudo abrir el archivo de pasajeros." << std::endl;
    }
}
void cargarMovimientos(const std::string& archivoMovimientos, ListaCircularDoble& listaAvionesDisponibles, ListaCircularDoble& listaAvionesMantenimiento, Cola& colaRegistro, Pila& pilaEquipaje, ListaDoblementeEnlazada& listaPasajeros) {
    std::ifstream archivo(archivoMovimientos);
    if (archivo.is_open()) {
        std::cout << "Archivo de movimientos abierto correctamente." << std::endl;
        std::string linea;
        while (std::getline(archivo, linea)) {
            std::istringstream iss(linea);
            std::string comando;
            std::getline(iss, comando, ',');
            if (comando == "IngresoEquipajes") {
            } else if (comando == "MantenimientoAviones") {
                std::string estado, numeroRegistro;
                std::getline(iss, estado, ',');
                std::getline(iss, numeroRegistro, ';');
                if (estado == "Ingreso") {
                    listaAvionesDisponibles.moverAvion(numeroRegistro, listaAvionesMantenimiento);
                } else if (estado == "Salida") {
                    listaAvionesMantenimiento.moverAvion(numeroRegistro, listaAvionesDisponibles);
                }
            }
        }
        archivo.close();
    } else {
        std::cout << "No se pudo abrir el archivo de movimientos." << std::endl;
    }
}

void consultarPasajero(ListaDoblementeEnlazada& listaPasajeros) {
    std::string numeroPasaporte;
    std::cout << "Ingrese el número de pasaporte: ";
    std::cin >> numeroPasaporte;
    Pasajero* pasajero = listaPasajeros.buscarPasajero(numeroPasaporte);
    if (pasajero) {
        std::cout << "Nombre: " << pasajero->getNombre() << std::endl;
        std::cout << "Nacionalidad: " << pasajero->getNacionalidad() << std::endl;
        std::cout << "Número de pasaporte: " << pasajero->getNumeroDePasaporte() << std::endl;
        std::cout << "Vuelo: " << pasajero->getVuelo() << std::endl;
        std::cout << "Asiento: " << pasajero->getAsiento() << std::endl;
        std::cout << "Destino: " << pasajero->getDestino() << std::endl;
        std::cout << "Origen: " << pasajero->getOrigen() << std::endl;
        std::cout << "Equipaje facturado: " << pasajero->getEquipajeFacturado() << std::endl;
    } else {
        std::cout << "No se encontró un pasajero con ese número de pasaporte." << std::endl;
    }
}
void generarImagenDesdeArchivoDot(const std::string& archivoEntrada, const std::string& archivoSalida, const std::string& formato) {
    std::string comando = "dot -T" + formato + " -o " + archivoSalida + " " + archivoEntrada;
    int resultado = std::system(comando.c_str());
    if (resultado != 0) {
        std::cout << "Error al generar la imagen desde el archivo dot." << std::endl;
    } else {
        std::cout << "Imagen generada correctamente: " << archivoSalida << std::endl;
    }
}

void mostrarMenu(ListaCircularDoble& avionesDisponibles, ListaCircularDoble& avionesMantenimiento, Cola& colaPasajeros, Pila& pilaEquipajes, ListaDoblementeEnlazada& listaPasajeros, Cola& colaRegistro, Pila& pilaEquipaje) {
    int opcion;
    do {
        std::cout << "1. Cargar aviones\n";
        std::cout << "2. Cargar pasajeros\n";
        std::cout << "3. Cargar movimientos\n";
        std::cout << "4. Consultar pasajeros\n";
        std::cout << "5. Reportes\n";
        std::cout << "6. Mostrar todos los datos cargados\n";
        std::cout << "7. Salir\n";
        std::cout << "Ingrese una opción: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                cargarAviones("/home/moisibot/CLionProjects/ControlAeropuerto/aviones.json", avionesDisponibles, avionesMantenimiento);
                break;
            case 2:
                cargarPasajeros("/home/moisibot/CLionProjects/ControlAeropuerto/pasajeros.json", listaPasajeros);

                break;
            case 3:
                cargarMovimientos("/home/moisibot/CLionProjects/ControlAeropuerto/movimientos.txt", avionesDisponibles,
                                  avionesMantenimiento, colaPasajeros, pilaEquipajes, listaPasajeros);
                break;
            case 4:
                consultarPasajero(listaPasajeros);
                break;
            case 5:
                int opcionReporte;
                do {
                    std::cout << "Seleccione el reporte que desea generar:\n";
                    std::cout << "1. Lista de aviones disponibles\n";
                    std::cout << "2. Lista de aviones en mantenimiento\n";
                    std::cout << "3. Cola de registro\n";
                    std::cout << "4. Pila de equipaje\n";
                    std::cout << "5. Lista de pasajeros\n";
                    std::cout << "6. Volver al menú principal\n";
                    std::cout << "Opción: ";
                    std::cin >> opcionReporte;

                    switch (opcionReporte) {
                        case 1:
                            generarReporteAvionesDisponibles(avionesDisponibles, "avionesDisponibles");
                            generarImagenDesdeArchivoDot("avionesDisponibles.dot","avionesDisponibles.png", "png");
                            break;
                        case 2:
                            generarReporteAvionesMantenimiento(avionesMantenimiento, "avionesMantenimiento");
                            generarImagenDesdeArchivoDot("avionesMantenimiento.dot","avionesMantenimiento.png", "png");
                            break;
                        case 3:
                            generarReporteColaRegistro(colaRegistro, "colaRegistro");
                            generarImagenDesdeArchivoDot("colaRegistro.dot","colaRegistro.png", "png");
                            break;
                        case 4:
                            generarReportePilaEquipaje(pilaEquipaje, "pilaEquipaje");
                            generarImagenDesdeArchivoDot("pilaEquipaje.dot","pilaEquipaje.png", "png");
                            break;
                        case 5:
                            generarReporteListaPasajeros(listaPasajeros, "listaPasajeros");
                            generarImagenDesdeArchivoDot("listaPasajeros.dot","listaPasajeros.png", "png");
                            break;
                        case 6:
                            mostrarMenu(avionesDisponibles, avionesMantenimiento, colaPasajeros, pilaEquipajes, listaPasajeros, colaRegistro, pilaEquipaje);
                            break;
                        default:
                            std::cout << "Opción no válida\n";
                    }
                } while (opcionReporte != 6);

                break;
            case 6:
                std::cout << "Aviones Disponibles:" << std::endl;
                avionesDisponibles.imprimirLista();
                std::cout << "Aviones en Mantenimiento:" << std::endl;
                avionesMantenimiento.imprimirLista();

                std::cout << "Pasajeros en Cola:" << std::endl;
                while (!colaPasajeros.estaVacia()) {
                    Pasajero* pasajero = colaPasajeros.desencolar();
                    std::cout << "Nombre: " << pasajero->getNombre() << ", Pasaporte: " << pasajero->getNumeroDePasaporte() << std::endl;
                    delete pasajero;
                }

                std::cout << "Equipajes en Pila:" << std::endl;
                while (!pilaEquipajes.estaVacia()) {
                    std::cout << "Cantidad: " << pilaEquipajes.desapilar() << std::endl;
                }

                break;
            case 7:
                std::cout << "Saliendo...\n";
                break;
            default:
                std::cout << "Opción no válida\n";
        }
    } while (opcion != 5);
}

int main() {
    ListaCircularDoble avionesDisponibles;
    ListaCircularDoble avionesMantenimiento;
    Cola colaPasajeros, colaRegistro ;
    Pila pilaEquipajes,pilaEquipaje;
    ListaDoblementeEnlazada listaPasajeros;


/*
    cargarAviones("/home/moisibot/CLionProjects/ControlAeropuerto/aviones.json", avionesDisponibles, avionesMantenimiento);
    cargarPasajeros("/home/moisibot/CLionProjects/ControlAeropuerto/pasajeros.json", colaPasajeros);
    cargarMovimientos("/home/moisibot/CLionProjects/ControlAeropuerto/movimientos.txt", avionesDisponibles, avionesMantenimiento, colaPasajeros, pilaEquipajes, listaPasajeros);
    }
    */
    mostrarMenu(avionesDisponibles, avionesMantenimiento, colaPasajeros, pilaEquipajes, listaPasajeros, colaRegistro,pilaEquipaje );
    return 0;
}