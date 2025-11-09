#include "MenuPrincipal.h"
#include <iostream>
#include <limits>

using namespace std;

MenuPrincipal::MenuPrincipal() : opcion(0) {}

int MenuPrincipal::mostrarMenu() {
    while (true) {
        cout << "\n";
        cout << "========================================\n";
        cout << "          GESTOR DE LIBROS              \n";
        cout << "========================================\n";
        cout << "\n";
        cout << "1. Añadir libro\n";
        cout << "2. Eliminar libro\n";
        cout << "3. Editar libro\n";
        cout << "4. Salir\n";
        cout << "\n";
        cout << "========================================\n";
        cout << "Seleccione una opcion: ";

        if(cin >> opcion && opcion > 0 && opcion <= 4)
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Opcion invalida. Debe ser un numero entre 1 y 4: ";
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return opcion;
}
