#ifndef CONTROLAEROPUERTO_AVION_H
#define CONTROLAEROPUERTO_AVION_H
#include <string>
using namespace std;

class Avion {
public:
        std::string vuelo;
        std::string numero_de_registro;
    std::string modelo;
        std::string fabricante;
        int ano_fabricacion;
        int capacidad;
        int peso_max_despegue;
        std::string aerolinea;
        std::string estado;
        Avion* siguiente;
        Avion* anterior;
    Avion();

        Avion(std::string vuelo, std::string numero_de_registro, std::string modelo, std::string fabricante, int ano_fabricacion,
              int capacidad, int peso_max_despegue, std::string aerolinea, std::string estado);

    const string &getVuelo() const;

    const string &getNumeroDeRegistro() const;

    const string &getModelo() const;

    const string &getFabricante() const;

    int getAnoFabricacion() const;

    int getCapacidad() const;

    int getPesoMaxDespegue() const;

    const string &getAerolinea() const;

    const string &getEstado() const;

    void setVuelo(const string &vuelo);

    void setNumeroDeRegistro(const string &numeroDeRegistro);

    void setModelo(const string &modelo);

    void setFabricante(const string &fabricante);

    void setAnoFabricacion(int anoFabricacion);

    void setCapacidad(int capacidad);

    void setPesoMaxDespegue(int pesoMaxDespegue);

    void setAerolinea(const string &aerolinea);

    void setEstado(const string &estado);

    void setSiguiente(Avion *siguiente);

    void setAnterior(Avion *anterior);

    /*  string getVuelo();
   string getNumeroDeRegistro();
   string getModelo();
   string getFabricante();
   int getAnoFabricacion();
   int getCapacidad();
   int getPesoMaxDespegue();
   string getAerolinea();
   string getEstado();
   void setEstado(string estado);

   // Setters
   /*
   voidtVuelo(string v) ;
   void setNumeroRegistro(string reg) ;
   void setModelo(string mod) ;
   void setFabricante(string fab) ;
   void setAnoFabricacion(int ano) ;
   void setCapacidad(int cap) ;
   void setPesoMaxDespegue(int pesoMax) ;
   void setAerolinea(string aerolinea) ;
   void setEstado(string est) ;
*/
    void mostrarInfo() const;
    bool estaDisponible() const;

    Avion *getSiguiente() const;

    Avion *getAnterior() const;
};
#endif //CONTROLAEROPUERTO_AVION_H
