
#ifndef CONTROLAEROPUERTO_GESTORARCHIVOS_H
#define CONTROLAEROPUERTO_GESTORARCHIVOS_H


#include <vector>
#include <string>
#include "../Avion.h"
#include "../Pasajero.h"

class GestorArchivos {
public:
    static std::vector<Avion> cargarAvionesDesdeJSON(const std::string& archivo);
    static std::vector<Pasajero> cargarPasajerosDesdeJSON(const std::string& archivo);
    static std::vector<std::string> leerComandosDeArchivo(const std::string& archivo);

private:
    static std::string leerArchivo(const std::string& archivo);
    static void validarJSON(const std::string& json);
};


#endif //CONTROLAEROPUERTO_GESTORARCHIVOS_H
