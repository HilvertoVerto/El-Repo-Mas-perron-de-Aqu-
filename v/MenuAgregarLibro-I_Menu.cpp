#include "MenuAgregarLibro-I_Menu.h"
#include <limits>

using namespace std;

MenuAgregarLibro::MenuAgregarLibro(const vector<Libro>& libros, const vector<Categoria>& categorias) {
    this->libros = libros;
    this->categorias = categorias;
}

tuple<vector<Libro>, vector<Categoria>> MenuAgregarLibro::ejecutar() {
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
                 << " - " << libros[i].getAutor()
                 << " (" << libros[i].getAnio() << ")\n";
        }
    }

    cout << "\n";
    cout << "========================================\n";

    // Verificar que existan categorías
    if (categorias.empty()) {
        cout << "\nNo hay categorias disponibles. Debe agregar categorias primero.\n";
        return make_tuple(libros, categorias);
    }

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

    // Pedir datos del nuevo libro (menos la categoría)
    string nombre, autor;
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

    // Listar categorías disponibles
    cout << "\nCategorias disponibles:\n\n";
    for (size_t i = 0; i < categorias.size(); i++) {
        cout << i + 1 << ". " << categorias[i].getNombre() << "\n";
    }

    // Pedir selección de categoría
    int seleccion;
    while (true) {
        cout << "\nSeleccione el numero de la categoria: ";
        if (cin >> seleccion) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (seleccion >= 1 && seleccion <= static_cast<int>(categorias.size())) {
                break;
            } else {
                cout << "Numero invalido. Debe estar entre 1 y " << categorias.size() << ".\n";
            }
        } else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada invalida. Ingrese un numero.\n";
        }
    }

    // Obtener la categoría seleccionada
    string categoriaSeleccionada = categorias[seleccion - 1].getNombre();

    // Crear libro con la categoría seleccionada
    Libro nuevoLibro(nombre, autor, anio, categoriaSeleccionada);
    libros.push_back(nuevoLibro);

    cout << "\n¡Libro agregado exitosamente!\n";

    return make_tuple(libros, categorias);
}
