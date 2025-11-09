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
    cout << "Categoria: " << categorias[indice].getNombre() << "\n";
    cout << "========================================\n";
    cout << "\n";

    // Pedir nuevos datos
    cout << "Ingrese los nuevos datos del libro:\n\n";

    // Pedir nuevo nombre
    string nuevoNombre;
    cout << "Nuevo nombre del libro: ";
    getline(cin, nuevoNombre);

    // Pedir nuevo autor
    string nuevoAutor;
    cout << "Nuevo autor: ";
    getline(cin, nuevoAutor);

    // Pedir nuevo año
    int nuevoAnio;
    cout << "Nuevo año de publicacion: ";
    while (!(cin >> nuevoAnio) || nuevoAnio < 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Año invalido. Ingrese un año valido: ";
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Pedir nueva categoría
    string nuevaCategoria;
    cout << "Nueva categoria: ";
    getline(cin, nuevaCategoria);

    // Usar los setters para actualizar el libro
    libros[indice].setNombre(nuevoNombre);
    libros[indice].setAutor(nuevoAutor);
    libros[indice].setAnio(nuevoAnio);
    libros[indice].setCategoria(nuevaCategoria);

    // Actualizar la categoría correspondiente
    categorias[indice].setLibro(nuevoNombre);
    categorias[indice].setNombre(nuevaCategoria);

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
