#ifndef CONTROLAEROPUERTO_LISTACIRCULARDOBLE_H
#define CONTROLAEROPUERTO_LISTACIRCULARDOBLE_H
#include "../Objetos/Avion.h"
#include <string>

class NodoAvion {
public:
    Avion* avion;
    NodoAvion* siguiente;
    NodoAvion* anterior;

    NodoAvion(Avion* avion);

    Avion *getAvion() const;
    void setAvion(Avion *avion);
    NodoAvion *getSiguiente() const;
    void setSiguiente(NodoAvion *siguiente);
    NodoAvion *getAnterior() const;
    void setAnterior(NodoAvion *anterior);
};

class ListaCircularDoble {
private:
    NodoAvion* cabeza;

public:
    ListaCircularDoble();
    ~ListaCircularDoble();
    void insertarAvion(Avion* avion);
    void insertarNodo(NodoAvion* nodoAvion);
    void eliminarAvion(const std::string& numeroRegistro);
    NodoAvion* buscarAvion(const std::string& numeroRegistro);
    void moverAvion(const std::string& numeroRegistro, ListaCircularDoble& otraLista);
    void imprimirLista();

    NodoAvion *getCabeza() const;

    void setCabeza(NodoAvion *cabeza);
};

#endif  // CONTROLAEROPUERTO_LISTACIRCULARDOBLE_H
