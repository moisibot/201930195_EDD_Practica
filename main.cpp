#include <iostream>
#include "cstdlib"
using namespace std;

int main() {
int opcion;
bool repetir = true;

do{
    system("cls");
    cout << "\nMenu de Opciones\n" << endl;
    cout << "1. Carga de aviones" << endl;
    cout << "2. Carga de pasajeros" << endl;
    cout << "3. carga de movimientos" << endl;
    cout << "4. consultar pasajero" << endl;
    cout << "5. visualizar reportes" << endl;
    cout << "6. salir" << endl;

    cout << "Ingrese una opcion:" << endl;
    cin>>opcion;
    switch (opcion){
        case 1:

            break;

        case 2:

            break;

        case 3:

            break;

        case 4:

            break;

        case 5:

            break;

        case 6:
repetir=false;

            break;
    }
}while(repetir);
    return 0;
}
