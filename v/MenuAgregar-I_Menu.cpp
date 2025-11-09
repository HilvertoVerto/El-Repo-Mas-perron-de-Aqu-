#include "MenuAgregar-I_Menu.h"
#include <limits>

using namespace std;

MenuAgregar::MenuAgregar(const vector<Libro>& libros, const vector<Categoria>& categorias) {
    this->libros = libros;
    this->categorias = categorias;
}

tuple<vector<Libro>, vector<Categoria>> MenuAgregar::ejecutar() {
    cout << "\n";
    cout << "========================================\n";
    cout << "          AGREGAR LIBRO                 \n";
    cout << "========================================\n";
    cout << "\n";

    // Mostrar libros actuales
    if (libros.empty()) {
        cout << "No hay libros registrados actualmente.\n";
    } else {
        cout << "Libros actuales:\n\n";
        for (size_t i = 0; i < libros.size(); i++) {
            cout << i + 1 << ". " << libros[i].getNombre()
                 << " - " << categorias[i].getNombre() << "\n";
        }
    }

    cout << "\n";
    cout << "========================================\n";

    // Pedir confirmación
    char respuesta;
    while (true) {
        cout << "\nQuieres agregar un nuevo libro?\n";
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

    // Pedir datos del nuevo libro
    string nombre, autor, categoria;
    int anio;

    cout << "\nIngrese el nombre del libro: ";
    getline(cin, nombre);

    cout << "Ingrese el autor: ";
    getline(cin, autor);

    cout << "Ingrese el año: ";
    while (!(cin >> anio)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Año invalido. Ingrese un numero: ";
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Ingrese la categoria: ";
    getline(cin, categoria);

    // Crear objetos y agregarlos a los vectores
    Libro nuevoLibro(nombre, autor, anio, categoria);
    Categoria nuevaCategoria(nombre, categoria);

    libros.push_back(nuevoLibro);
    categorias.push_back(nuevaCategoria);

    cout << "\n¡Libro agregado exitosamente!\n";

    return make_tuple(libros, categorias);
}
