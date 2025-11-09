#include "MenuEditar-I_Menu.h"
#include <limits>

using namespace std;

MenuEditar::MenuEditar(const vector<Libro>& libros, const vector<Categoria>& categorias) {
    this->libros = libros;
    this->categorias = categorias;
}

tuple<vector<Libro>, vector<Categoria>> MenuEditar::ejecutar() {
    cout << "\n";
    cout << "========================================\n";
    cout << "          EDITAR LIBRO                  \n";
    cout << "========================================\n";
    cout << "\n";

    // Verificar si hay libros
    if (libros.empty()) {
        cout << "No hay libros registrados para editar.\n";
        cout << "\nPresione Enter para continuar...";
        cin.get();
        return make_tuple(libros, categorias);
    }

    // Mostrar libros con sus categorías
    cout << "Libros disponibles:\n\n";
    for (size_t i = 0; i < libros.size(); i++) {
        cout << i + 1 << ". " << libros[i].getNombre()
             << " - " << categorias[i].getNombre() << "\n";
    }

    cout << "\n";
    cout << "========================================\n";

    // Pedir opción
    int opcion;
    cout << "\nSeleccione el numero del libro a editar: ";

    while (!(cin >> opcion) || opcion < 1 || opcion > static_cast<int>(libros.size())) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Opcion invalida. Debe ser un numero entre 1 y " << libros.size() << ": ";
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Siguiente parte - A implementar
    /*
    // Aquí iría el código para:
    // 1. Mostrar los datos actuales del libro seleccionado
    // 2. Pedir los nuevos datos (nombre, autor, año, categoría)
    // 3. Actualizar el libro y categoría en los vectores
    // 4. Retornar la tupla actualizada
    */

    return make_tuple(libros, categorias);
}
