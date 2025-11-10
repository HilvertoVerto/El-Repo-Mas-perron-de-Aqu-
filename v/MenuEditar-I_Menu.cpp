#include "MenuEditar-I_Menu.h"
#include "../utils/LimpiarPantalla.h"
#include <limits>

using namespace std;

MenuEditar::MenuEditar(const vector<Libro>& libros, const vector<Categoria>& categorias) {
    this->libros = libros;
    this->categorias = categorias;
}

tuple<vector<Libro>, vector<Categoria>> MenuEditar::ejecutar() {
    LimpiarPantalla();

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

    // Mostrar libros
    cout << "Libros disponibles:\n\n";
    for (size_t i = 0; i < libros.size(); i++) {
        cout << i + 1 << ". " << libros[i].getNombre()
             << " - " << libros[i].getAutor()
             << " (" << libros[i].getAnio() << ")\n";
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

    // Obtener el índice del libro seleccionado
    int indice = opcion - 1;

    // Mostrar datos actuales del libro
    cout << "\n";
    cout << "========================================\n";
    cout << "      DATOS ACTUALES DEL LIBRO          \n";
    cout << "========================================\n";
    cout << "Nombre: " << libros[indice].getNombre() << "\n";
    cout << "Autor: " << libros[indice].getAutor() << "\n";
    cout << "Año: " << libros[indice].getAnio() << "\n";
    cout << "Categoria: " << libros[indice].getCategoria() << "\n";
    cout << "========================================\n";
    cout << "\n";

    // Pedir nuevos datos
    cout << "Ingrese los nuevos datos del libro (presione Enter para mantener el valor actual):\n\n";

    // Pedir nuevo nombre
    string nuevoNombre;
    cout << "Nuevo nombre del libro [" << libros[indice].getNombre() << "]: ";
    getline(cin, nuevoNombre);
    // Si está vacío, mantener el valor actual
    if (nuevoNombre.empty()) {
        nuevoNombre = libros[indice].getNombre();
    }

    // Pedir nuevo autor
    string nuevoAutor;
    cout << "Nuevo autor [" << libros[indice].getAutor() << "]: ";
    getline(cin, nuevoAutor);
    // Si está vacío, mantener el valor actual
    if (nuevoAutor.empty()) {
        nuevoAutor = libros[indice].getAutor();
    }

    // Pedir nuevo año
    int nuevoAnio = libros[indice].getAnio();
    string anioStr;
    cout << "Nuevo año de publicacion [" << libros[indice].getAnio() << "]: ";
    getline(cin, anioStr);

    // Si no está vacío, intentar convertir a número
    if (!anioStr.empty()) {
        bool anioValido = false;
        while (!anioValido) {
            try {
                nuevoAnio = stoi(anioStr);
                if (nuevoAnio < 0) {
                    cout << "Año invalido. Ingrese un año valido [" << libros[indice].getAnio() << "]: ";
                    getline(cin, anioStr);
                    if (anioStr.empty()) {
                        nuevoAnio = libros[indice].getAnio();
                        anioValido = true;
                    }
                } else {
                    anioValido = true;
                }
            } catch (...) {
                cout << "Año invalido. Ingrese un año valido [" << libros[indice].getAnio() << "]: ";
                getline(cin, anioStr);
                if (anioStr.empty()) {
                    nuevoAnio = libros[indice].getAnio();
                    anioValido = true;
                }
            }
        }
    }

    // Usar los setters para actualizar el libro
    libros[indice].setNombre(nuevoNombre);
    libros[indice].setAutor(nuevoAutor);
    libros[indice].setAnio(nuevoAnio);

    // Mostrar mensaje de confirmación
    cout << "\n";
    cout << "========================================\n";
    cout << "   Libro editado exitosamente!         \n";
    cout << "========================================\n";
    cout << "\nPresione Enter para continuar...";
    cin.get();

    // Retornar la tupla actualizada
    return make_tuple(libros, categorias);
}
