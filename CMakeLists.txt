cmake_minimum_required(VERSION 3.28)
project(ControlAeropuerto)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)
include_directories(extern/json/single_include)

file(GLOB SOURCES "src/*.cpp")

add_executable(ControlAeropuerto main.cpp
        Objetos/Avion.cpp
        Objetos/Avion.h
        Objetos/Pasajero.cpp
        Objetos/Pasajero.h
        Objetos/Equipaje.cpp
        Objetos/Equipaje.h
        Estructura/ListaDoblementeEnlazada.cpp
        Estructura/ListaDoblementeEnlazada.h
        Estructura/ListaCircularDoble.cpp
        Estructura/ListaCircularDoble.h
        Estructura/Pila.cpp
        Estructura/Pila.h
        Estructura/Cola.cpp
        Estructura/Cola.h
        Estructura/Nodo.cpp
        Estructura/Nodo.h
        Reportes.cpp
        Reportes.h

)
