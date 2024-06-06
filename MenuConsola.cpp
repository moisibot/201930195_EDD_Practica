#include "MenuConsola.h"
#include <iostream>
#include <limits>
#include <fstream>
using namespace std;

void MenuConsola::mostrarMenuPrincipal() {
    while (true) {
        limpiarPantalla();
        cout << "=== SISTEMA DE GESTIÓN DE AEROPUERTO ===" << endl;
        cout << "1. Cargar Archivos" << endl;
        cout << "2. Realizar Movimientos" << endl;
        cout << "3. Consultar Pasajero" << endl;
        cout << "4. Generar Reportes" << endl;
        cout << "5. Salir" << endl;

        int opcion = solicitarOpcion(1, 5);
        switch (opcion) {
            case 1: cargarArchivos(); break;
            case 2: realizarMovimientos(); break;
            case 3: consultarPasajero(); break;
            case 4: //generarReportes(); break;
            case 5: return;
        }
    }
}

void MenuConsola::cargarArchivos() {
    string archivoAviones = solicitarArchivo("aviones");
    string archivoPasajeros = solicitarArchivo("pasajeros");

    auto aviones = GestorArchivos::cargarAvionesDesdeJSON(archivoAviones);
    auto pasajeros = GestorArchivos::cargarPasajerosDesdeJSON(archivoPasajeros);

    aeropuerto.cargarAviones(aviones);
    aeropuerto.cargarPasajeros(pasajeros);

    cout << "Archivos cargados exitosamente." << endl;
    system("pause");
}

void MenuConsola::consultarPasajero() {
    cout << "Ingrese el número de pasaporte: ";
    string pasaporte;
    cin >> pasaporte;

    Pasajero* p = aeropuerto.buscarPasajeroPorPasaporte(pasaporte);
    if (p) {
        p->mostrarInfo();
    } else {
        cout << "Pasajero no encontrado." << endl;
    }
    system("pause");
}

void MenuConsola::realizarMovimientos() {
    string comando;
    while (true) {
        cout << "Ingrese un comando (IngresoEquipaje, MantenimientoAviones, Salir): ";
        cin >> comando;

        if (comando == "IngresoEquipaje") {
            aeropuerto.registrarPasajero();
            // Realizar acciones adicionales si es necesario
        } else if (comando == "MantenimientoAviones") {
            string numeroRegistro, nuevoEstado;
            cout << "Ingrese el número de registro del avión: ";
            cin >> numeroRegistro;
            cout << "Ingrese el nuevo estado (Disponible o Mantenimiento): ";
            cin >> nuevoEstado;
            aeropuerto.moverAvion(numeroRegistro, nuevoEstado);
        } else if (comando == "Salir") {
            break;
        } else {
            cout << "Comando inválido. Intente nuevamente." << endl;
        }
    }
}
/*
void MenuConsola::generarReportes() {
    cout << "Generando reportes..." << endl;
    GeneradorReportes::generarReporteAvionesDisponibles(aeropuerto.getAvionesDisponibles());
    GeneradorReportes::generarReporteAvionesMantenimiento(aeropuerto.getAvionesMantenimiento());
    GeneradorReportes::generarReporteColaRegistro(aeropuerto.getColaRegistro());
    GeneradorReportes::generarReportePilaEquipaje(aeropuerto.getPilaEquipaje());
    GeneradorReportes::generarReporteListaPasajeros(aeropuerto.getListaPasajeros());
    cout << "Reportes generados exitosamente." << endl;
}*/

void MenuConsola::limpiarPantalla() {
    std::cout << "\033[2J\033[1;1H"; // Secuencia de escape para limpiar la pantalla en sistemas Unix
}

int MenuConsola::solicitarOpcion(int min, int max) {
    int opcion;
    while (true) {
        std::cout << "Ingrese una opción (" << min << "-" << max << "): ";
        std::cin >> opcion;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Opción inválida. Intente nuevamente." << std::endl;
        } else if (opcion >= min && opcion <= max) {
            break;
        } else {
            std::cout << "Opción fuera de rango. Intente nuevamente." << std::endl;
        }
    }
    return opcion;
}

std::string MenuConsola::solicitarArchivo(const std::string& tipo) {
    std::string archivo;
    while (true) {
        std::cout << "Ingrese el nombre del archivo de " << tipo << ": ";
        std::cin >> archivo;

        // Verificar si el archivo existe
        std::ifstream file(archivo);
        if (file.good()) {
            break;
        } else {
            std::cout << "El archivo no existe. Intente nuevamente." << std::endl;
        }
    }
    return archivo;
}