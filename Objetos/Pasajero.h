#ifndef CONTROLAEROPUERTO_PASAJERO_H
#define CONTROLAEROPUERTO_PASAJERO_H
#include <string>
using namespace std;
class Pasajero {
public:
    std::string nombre;
    std::string nacionalidad;
    std::string numero_de_pasaporte;
    std::string vuelo;
    int asiento;
    std::string destino;
    std::string origen;
    int equipaje_facturado;
    Pasajero* siguiente;

    Pasajero(std::string nombre, std::string nacionalidad, std::string numero_de_pasaporte,
             std::string vuelo, int asiento, std::string destino, std::string origen, int equipaje_facturado);

    const string &getNombre() const;

    void setNombre(const string &nombre);

    const string &getNacionalidad() const;

    void setNacionalidad(const string &nacionalidad);

    const string &getNumeroDePasaporte() const;

    void setNumeroDePasaporte(const string &numeroDePasaporte);

    const string &getVuelo() const;

    void setVuelo(const string &vuelo);

    int getAsiento() const;

    void setAsiento(int asiento);

    const string &getDestino() const;

    void setDestino(const string &destino);

    const string &getOrigen() const;

    void setOrigen(const string &origen);

    int getEquipajeFacturado() const;

    void setEquipajeFacturado(int equipajeFacturado);

    Pasajero *getSiguiente() const;

    void setSiguiente(Pasajero *siguiente);

};
#endif //CONTROLAEROPUERTO_PASAJERO_H
