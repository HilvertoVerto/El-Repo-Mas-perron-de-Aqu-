#include "MenuEliminarLibro-I_Menu.h"
#include <limits>

using namespace std;

MenuEliminarLibro::MenuEliminarLibro(const vector<Libro>& libros, const vector<Categoria>& categorias) {
    this->libros = libros;
    this->categorias = categorias;
}

tuple<vector<Libro>, vector<Categoria>> MenuEliminarLibro::ejecutar() {
    cout << "\n";
    cout << "========================================\n";
    cout << "          ELIMINAR LIBRO                \n";
    cout << "========================================\n";
    cout << "\n";

    // Verificar si hay libros
    if (libros.empty()) {
        cout << "No hay libros registrados para eliminar.\n";
        cout << "\nPresione Enter para continuar...";
        cin.get();
        return make_tuple(libros, categorias);
    }

    // Mostrar libros
    cout << "Libros disponibles:\n\n";
    for (size_t i = 0; i < libros.size(); i++) {
        cout << i + 1 << ". " << libros[i].getNombre() << "\n";
    }

    cout << "\n";
    cout << "========================================\n";

    // Pedir opción (índice)
    int opcion;
    cout << "\nSeleccione el numero del libro a eliminar: ";

    while (!(cin >> opcion) || opcion < 1 || opcion > static_cast<int>(libros.size())) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Opcion invalida. Debe ser un numero entre 1 y " << libros.size() << ": ";
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Obtener el índice del libro seleccionado
    int indice = opcion - 1;

    // Mostrar datos del libro seleccionado
    cout << "\n";
    cout << "========================================\n";
    cout << "      DATOS DEL LIBRO                   \n";
    cout << "========================================\n";
    cout << "Nombre: " << libros[indice].getNombre() << "\n";
    cout << "Autor: " << libros[indice].getAutor() << "\n";
    cout << "Año: " << libros[indice].getAnio() << "\n";
    cout << "========================================\n";
    cout << "\n";

    // Pedir confirmación
    string confirmacion;
    cout << "Para confirmar la eliminacion, escriba 'eliminar': ";
    getline(cin, confirmacion);

    // Verificar confirmación
    if (confirmacion == "eliminar") {
        // Eliminar el libro del vector
        libros.erase(libros.begin() + indice);

        cout << "\n";
        cout << "========================================\n";
        cout << "   Libro eliminado exitosamente!       \n";
        cout << "========================================\n";
    } else {
        cout << "\n";
        cout << "========================================\n";
        cout << "   Eliminacion cancelada.               \n";
        cout << "========================================\n";
    }

    cout << "\nPresione Enter para continuar...";
    cin.get();

    // Retornar la tupla con libros modificado y categorías sin modificar
    return make_tuple(libros, categorias);
}
