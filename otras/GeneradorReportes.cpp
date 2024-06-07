#include "GeneradorReportes.h"
#include <fstream>
#include <sstream>
#include <cstdlib>  // para system()
using namespace std;
void GeneradorReportes::generarReporteAvionesDisponibles(const ListaCircularDoble<Avion, string>& aviones) {
    stringstream ss;
    ss << "digraph AvionesDisponibles {\n";
    ss << "  rankdir=LR;\n";
    ss << "  node [shape=box];\n";
    for (auto iter = aviones.begin(); iter != aviones.end(); ++iter) {
        ss << generarDotAvion(*iter);
    }
    ss << "}\n";
    escribirArchivoDot(ss.str(), "aviones_disponibles");
    ejecutarGraphviz("aviones_disponibles");
}

string GeneradorReportes::generarDotAvion(const Avion& avion) {
    stringstream ss;
    ss << "  \"" << avion.getNumeroRegistro() << "\" [label=\"Registro: " << avion.getNumeroRegistro()
       << "\\nModelo: " << avion.getModelo() << "\\nCapacidad: " << avion.getCapacidad() << "\"];\n";
    return ss.str();
}

void GeneradorReportes::escribirArchivoDot(const string& contenido, const string& nombre) {
    ofstream archivo(nombre + ".dot");
    archivo << contenido;
    archivo.close();
}

void GeneradorReportes::ejecutarGraphviz(const string& nombre) {
    system(("dot -Tpng " + nombre + ".dot -o " + nombre + ".png").c_str());
    system(("xdg-open " + nombre + ".png").c_str());
}
