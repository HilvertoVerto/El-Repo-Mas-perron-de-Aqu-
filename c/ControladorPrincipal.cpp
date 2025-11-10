#include "ControladorPrincipal.h"
#include <iostream>
#include <sys/stat.h>
#include <sys/types.h>

using namespace std;

ControladorPrincipal::ControladorPrincipal(const string& rutaBD) : rutaBD(rutaBD) {
    // Crear el directorio db/ si no existe
    struct stat st;
    if (stat("db", &st) != 0) {
        // El directorio no existe, crearlo
        #ifdef _WIN32
            _mkdir("db");
        #else
            mkdir("db", 0755);
        #endif
        cout << "Directorio 'db/' creado." << endl;
    }

    // Crear el repositorio
    repositorio = new RepositorioLibros(rutaBD);

    // Crear el controlador de menu
    controladorMenu = new ControladorMenu();
}

ControladorPrincipal::~ControladorPrincipal() {
    delete repositorio;
    delete controladorMenu;
}

void ControladorPrincipal::iniciar() {
    try {
        cout << "\n";
        cout << "========================================\n";
        cout << "   SISTEMA DE GESTION DE BIBLIOTECA    \n";
        cout << "========================================\n";
        cout << "\n";
        cout << "Inicializando base de datos...\n";

        // Inicializar la base de datos (crear tablas si no existen)
        repositorio->inicializar();

        cout << "Sistema inicializado correctamente.\n";
        cout << "Presione Enter para continuar...";
        cin.get();

    } catch (const exception& e) {
        cerr << "\nError al inicializar el sistema: " << e.what() << endl;
        cerr << "El programa se cerrara.\n";
        exit(1);
    }
}

void ControladorPrincipal::ejecutar() {
    try {
        // Cargar datos desde la base de datos
        cout << "\nCargando datos desde la base de datos...\n";
        auto [libros, categorias] = repositorio->cargarDatos();

        // Ejecutar el menu principal y obtener los datos modificados
        auto [librosModificados, categoriasModificadas] =
            controladorMenu->mostrarMenuPrincipal(libros, categorias);

        // Guardar los datos modificados en la base de datos
        cout << "\nGuardando cambios en la base de datos...\n";
        if (repositorio->guardarDatos(librosModificados, categoriasModificadas)) {
            cout << "Cambios guardados exitosamente.\n";
        } else {
            cerr << "Error al guardar los cambios.\n";
        }

        cout << "\n";
        cout << "========================================\n";
        cout << "   Gracias por usar el sistema!        \n";
        cout << "========================================\n";
        cout << "\n";

    } catch (const exception& e) {
        cerr << "\nError durante la ejecucion: " << e.what() << endl;
        cerr << "Los cambios podrian no haberse guardado.\n";
    }
}
