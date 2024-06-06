#include "GestorArchivos.h"
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;
using namespace std;

vector<Avion> GestorArchivos::cargarAvionesDesdeJSON(const string& archivo) {
    vector<Avion> aviones;
    string contenido = leerArchivo(archivo);
    validarJSON(contenido);

    json data = json::parse(contenido);
    for (const auto& avion : data) {
        aviones.emplace_back(
                avion["registro"],
                avion["modelo"],
                avion["capacidad"],
                avion.value("estado", "Disponible")
        );
    }
    return aviones;
}

vector<Pasajero> GestorArchivos::cargarPasajerosDesdeJSON(const string& archivo) {
    vector<Pasajero> pasajeros;
    string contenido = leerArchivo(archivo);
    validarJSON(contenido);

    json data = json::parse(contenido);
    for (const auto& pasajero : data) {
        pasajeros.emplace_back(
                pasajero["pasaporte"],
                pasajero["nombre"],
                pasajero["apellido"],
                pasajero["vuelo"],
                pasajero["asiento"],
                pasajero.value("equipaje", 0)
        );
    }
    return pasajeros;
}

std::string GestorArchivos::leerArchivo(const std::string& archivo) {
    std::ifstream file(archivo);
    std::string contenido((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    return contenido;
}

void GestorArchivos::validarJSON(const std::string& json) {
    // Aquí puedes implementar una validación básica del formato JSON
    // Por ejemplo, verificar que el primer y último caracteres sean '{' y '}'
    if (json.empty() || json.front() != '{' || json.back() != '}') {
        throw std::invalid_argument("JSON inválido");
    }
}