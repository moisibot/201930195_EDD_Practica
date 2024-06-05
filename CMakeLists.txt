cmake_minimum_required(VERSION 3.28)
project(ControlAeropuerto)

set(CMAKE_CXX_STANDARD 17)

add_executable(ControlAeropuerto main.cpp
        Avion.cpp
        Avion.h
        Pasajero.cpp
        Pasajero.h
        Equipaje.cpp
        Equipaje.h
)
