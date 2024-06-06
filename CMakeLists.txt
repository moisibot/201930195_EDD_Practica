cmake_minimum_required(VERSION 3.28)
project(ControlAeropuerto)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)
include_directories(extern/json/single_include)

file(GLOB SOURCES "src/*.cpp")

add_executable(ControlAeropuerto main.cpp
        Avion.cpp
        Avion.h
        Pasajero.cpp
        Pasajero.h
        Equipaje.cpp
        Equipaje.h
        Estructura/Nodo.cpp
        Estructura/Nodo.h
        Estructura/ListaDobleEnlazada.cpp
        Estructura/ListaDobleEnlazada.h
        Estructura/ListaCircularDoble.cpp
        Estructura/ListaCircularDoble.h
        Estructura/Pila.cpp
        Estructura/Pila.h
        Estructura/Cola.cpp
        Estructura/Cola.h
        otras/GestorArchivos.cpp
        otras/GestorArchivos.h
        otras/GestorAeropuerto.cpp
        otras/GestorAeropuerto.h
        otras/GeneradorReportes.cpp
        otras/GeneradorReportes.h
        MenuConsola.cpp
        MenuConsola.h
)
