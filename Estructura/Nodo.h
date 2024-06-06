#ifndef CONTROLAEROPUERTO_NODO_H
#define CONTROLAEROPUERTO_NODO_H

template <typename T>
class Nodo {
public:
    T dato;
    Nodo<T>* siguiente;
    Nodo<T>* anterior;
    Nodo(T d) : dato(d), siguiente(nullptr), anterior(nullptr){}
};
#endif //CONTROLAEROPUERTO_NODO_H
