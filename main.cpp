#include "otras/GestorAeropuerto.h"
#include "MenuConsola.h"

using namespace std;

int main() {
    GestorAeropuerto gestor;
    MenuConsola menu(gestor);

    menu.mostrarMenuPrincipal();
    return 0;
}
