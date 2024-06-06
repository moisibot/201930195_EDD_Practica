
#ifndef CONTROLAEROPUERTO_MENUCONSOLA_H
#define CONTROLAEROPUERTO_MENUCONSOLA_H


#include "otras/GestorAeropuerto.h"
#include "otras/GestorArchivos.h"
#include "otras/GeneradorReportes.h"
#include "otras/GestorAeropuerto.h"

class MenuConsola {
private:
    GestorAeropuerto& aeropuerto;

public:
    MenuConsola(GestorAeropuerto& gestor) : aeropuerto(gestor) {}

    void mostrarMenuPrincipal();
    void cargarArchivos();
    void realizarMovimientos();
    void consultarPasajero();
    void generarReportes();

private:
    void limpiarPantalla();
    int solicitarOpcion(int min, int max);
    string solicitarArchivo(const string& tipo);
};

#endif //CONTROLAEROPUERTO_MENUCONSOLA_H
