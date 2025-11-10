#include "ControladorMenu.h"
#include "../utils/LimpiarPantalla.h"
#include <iostream>
#include <limits>

using namespace std;

ControladorMenu::ControladorMenu() {}

int ControladorMenu::leerEnteroValido(const string& mensaje, int min, int max) {
    int opcion;
    bool entradaValida = false;

    while (!entradaValida) {
        cout << mensaje;

        // Intentar leer un entero
        if (cin >> opcion) {
            // Si se leyó correctamente, verificar rango
            if (opcion >= min && opcion <= max) {
                entradaValida = true;
            } else {
                cout << "Error: El numero debe estar entre " << min << " y " << max << ".\n";
            }
        } else {
            // Si fallo la lectura (ej: se ingreso un string)
            cout << "Error: Debe ingresar un numero entero.\n";

            // Limpiar el estado de error de cin
            cin.clear();
        }

        // Limpiar el buffer de entrada
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return opcion;
}

string ControladorMenu::leerStringNoVacio(const string& mensaje) {
    string entrada;
    bool entradaValida = false;

    while (!entradaValida) {
        cout << mensaje;
        getline(cin, entrada);

        if (!entrada.empty()) {
            entradaValida = true;
        } else {
            cout << "Error: La entrada no puede estar vacia.\n";
        }
    }

    return entrada;
}

tuple<vector<Libro>, vector<Categoria>> ControladorMenu::mostrarMenuPrincipal(
    vector<Libro> libros,
    vector<Categoria> categorias
) {
    bool salir = false;

    while (!salir) {
        // Limpiar la pantalla antes de mostrar el menú
        LimpiarPantalla();

        cout << "\n";
        cout << "========================================\n";
        cout << "       SISTEMA DE GESTION DE LIBROS     \n";
        cout << "========================================\n";
        cout << "\n";
        cout << "1. Agregar Libro\n";
        cout << "2. Agregar Categoria\n";
        cout << "3. Editar Libro\n";
        cout << "4. Eliminar Libro\n";
        cout << "5. Ver Libros\n";
        cout << "6. Ver Categorias\n";
        cout << "0. Salir\n";
        cout << "\n";
        cout << "========================================\n";

        int opcion = leerEnteroValido("\nSeleccione una opcion: ", 0, 6);

        switch (opcion) {
            case 1: {
                try {
                    auto menu = MenuFactory::crearMenu(TipoMenu::AGREGAR_LIBRO, libros, categorias);
                    if (menu != nullptr) {
                        auto resultado = menu->ejecutar();
                        libros = get<0>(resultado);
                        categorias = get<1>(resultado);
                    }
                } catch (const exception& e) {
                    cout << "\nError: " << e.what() << "\n";
                }
                break;
            }

            case 2: {
                try {
                    auto menu = MenuFactory::crearMenu(TipoMenu::AGREGAR_CATEGORIA, libros, categorias);
                    if (menu != nullptr) {
                        auto resultado = menu->ejecutar();
                        libros = get<0>(resultado);
                        categorias = get<1>(resultado);
                    }
                } catch (const exception& e) {
                    cout << "\nError: " << e.what() << "\n";
                }
                break;
            }

            case 3: {
                try {
                    auto menu = MenuFactory::crearMenu(TipoMenu::EDITAR, libros, categorias);
                    if (menu != nullptr) {
                        auto resultado = menu->ejecutar();
                        libros = get<0>(resultado);
                        categorias = get<1>(resultado);
                    }
                } catch (const exception& e) {
                    cout << "\nError: " << e.what() << "\n";
                }
                break;
            }

            case 4: {
                try {
                    auto menu = MenuFactory::crearMenu(TipoMenu::ELIMINAR_LIBRO, libros, categorias);
                    if (menu != nullptr) {
                        auto resultado = menu->ejecutar();
                        libros = get<0>(resultado);
                        categorias = get<1>(resultado);
                    }
                } catch (const exception& e) {
                    cout << "\nError: " << e.what() << "\n";
                }
                break;
            }

            case 5:
                cout << "\n========================================\n";
                cout << "           LISTA DE LIBROS              \n";
                cout << "========================================\n\n";
                if (libros.empty()) {
                    cout << "No hay libros registrados.\n";
                } else {
                    for (size_t i = 0; i < libros.size(); i++) {
                        cout << i + 1 << ". " << libros[i].getNombre()
                             << " - " << libros[i].getAutor()
                             << " (" << libros[i].getAnio() << ")"
                             << " [" << libros[i].getCategoria() << "]\n";
                    }
                }
                cout << "\nPresione Enter para continuar...";
                cin.get();
                break;

            case 6:
                cout << "\n========================================\n";
                cout << "         LISTA DE CATEGORIAS            \n";
                cout << "========================================\n\n";
                if (categorias.empty()) {
                    cout << "No hay categorias registradas.\n";
                } else {
                    for (size_t i = 0; i < categorias.size(); i++) {
                        cout << i + 1 << ". " << categorias[i].getNombre()
                             << " - " << categorias[i].getDescripcion() << "\n";
                    }
                }
                cout << "\nPresione Enter para continuar...";
                cin.get();
                break;

            case 0:
                cout << "\nSaliendo del sistema...\n";
                salir = true;
                break;

            default:
                cout << "\nOpcion invalida.\n";
                break;
        }
    }

    // Retornar los datos modificados
    return make_tuple(libros, categorias);
}
