#include "MenuAgregarCategoria-I_Menu.h"
#include <limits>
#include <algorithm>

using namespace std;

MenuAgregarCategoria::MenuAgregarCategoria(const vector<Libro>& libros, const vector<Categoria>& categorias) {
    this->libros = libros;
    this->categorias = categorias;
}

tuple<vector<Libro>, vector<Categoria>> MenuAgregarCategoria::ejecutar() {
    cout << "\n";
    cout << "========================================\n";
    cout << "     AGREGAR CATEGORIA LITERARIA        \n";
    cout << "========================================\n";
    cout << "\n";

    // Mostrar categorías actuales
    if (categorias.empty()) {
        cout << "No hay categorias registradas actualmente.\n";
    } else {
        cout << "Categorias actuales:\n\n";
        for (size_t i = 0; i < categorias.size(); i++) {
            cout << i + 1 << ". " << categorias[i].getNombre() << "\n";
        }
    }

    cout << "\n";
    cout << "========================================\n";

    // Pedir confirmación
    char respuesta;
    while (true) {
        cout << "\nQuieres agregar una nueva categoria?\n";
        cout << "(s)/si  (n)/no: ";

        cin >> respuesta;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (respuesta == 'n' || respuesta == 'N') {
            return make_tuple(libros, categorias);
        } else if (respuesta == 's' || respuesta == 'S') {
            break;
        } else {
            cout << "Opcion invalida. Debe ingresar 's' o 'n'.\n";
        }
    }

    // Listar de nuevo las categorías
    cout << "\n";
    if (categorias.empty()) {
        cout << "No hay categorias registradas actualmente.\n";
    } else {
        cout << "Categorias existentes:\n\n";
        for (size_t i = 0; i < categorias.size(); i++) {
            cout << i + 1 << ". " << categorias[i].getNombre() << "\n";
        }
    }

    // Pedir nombre de la nueva categoría
    string nombre;
    cout << "\nIngrese el nombre de la nueva categoria: ";
    getline(cin, nombre);

    // Verificar que no exista ya esa categoría
    bool existe = false;
    for (const auto& cat : categorias) {
        if (cat.getNombre() == nombre) {
            existe = true;
            break;
        }
    }

    if (existe) {
        cout << "\nLa categoria '" << nombre << "' ya existe. No se agregara.\n";
        return make_tuple(libros, categorias);
    }

    // Crear categoría y agregarla al vector
    // Como la categoría necesita un libro, usamos un string vacío o placeholder
    Categoria nuevaCategoria("", nombre);
    categorias.push_back(nuevaCategoria);

    cout << "\n¡Categoria agregada exitosamente!\n";

    return make_tuple(libros, categorias);
}
