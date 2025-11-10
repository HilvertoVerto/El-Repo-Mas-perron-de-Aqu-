#include "RepositorioLibros.h"
#include <iostream>

using namespace std;
using namespace sqlite_orm;

RepositorioLibros::RepositorioLibros(const string& rutaBD)
    : rutaBD(rutaBD), storage(crearStorage(rutaBD)) {}

void RepositorioLibros::inicializar() {
    try {
        // sync_schema() crea las tablas si no existen, o las actualiza si cambiaron
        storage.sync_schema();
        cout << "Base de datos inicializada correctamente en: " << rutaBD << endl;
    } catch (const exception& e) {
        cerr << "Error al inicializar la base de datos: " << e.what() << endl;
        throw;
    }
}

tuple<vector<Libro>, vector<Categoria>> RepositorioLibros::cargarDatos() {
    vector<Libro> libros;
    vector<Categoria> categorias;

    try {
        // Cargar todos los libros de la base de datos
        libros = storage.get_all<Libro>();

        // Cargar todas las categorias de la base de datos
        categorias = storage.get_all<Categoria>();

        cout << "Datos cargados: " << libros.size() << " libros, "
             << categorias.size() << " categorias." << endl;

    } catch (const exception& e) {
        cerr << "Error al cargar datos: " << e.what() << endl;
    }

    return make_tuple(libros, categorias);
}

bool RepositorioLibros::guardarDatos(const vector<Libro>& libros, const vector<Categoria>& categorias) {
    try {
        // Iniciar transaccion para garantizar atomicidad
        storage.transaction([&]() mutable {
            // Eliminar todos los registros existentes
            storage.remove_all<Libro>();
            storage.remove_all<Categoria>();

            // Insertar todos los libros
            for (const auto& libro : libros) {
                // Si el libro tiene ID -1, es nuevo y se insertara con autoincrement
                // Si tiene un ID valido, se respeta ese ID
                if (libro.getId() == -1) {
                    Libro libroTemporal = libro;
                    storage.insert(libroTemporal);
                } else {
                    storage.replace(libro);
                }
            }

            // Insertar todas las categorias
            for (const auto& categoria : categorias) {
                if (categoria.getId() == -1) {
                    Categoria categoriaTemporal = categoria;
                    storage.insert(categoriaTemporal);
                } else {
                    storage.replace(categoria);
                }
            }

            return true;
        });

        cout << "Datos guardados exitosamente: " << libros.size() << " libros, "
             << categorias.size() << " categorias." << endl;
        return true;

    } catch (const exception& e) {
        cerr << "Error al guardar datos: " << e.what() << endl;
        return false;
    }
}

int RepositorioLibros::insertarLibro(const Libro& libro) {
    try {
        // insert() retorna el ID del registro insertado
        return storage.insert(libro);
    } catch (const exception& e) {
        cerr << "Error al insertar libro: " << e.what() << endl;
        return -1;
    }
}

int RepositorioLibros::insertarCategoria(const Categoria& categoria) {
    try {
        return storage.insert(categoria);
    } catch (const exception& e) {
        cerr << "Error al insertar categoria: " << e.what() << endl;
        return -1;
    }
}

bool RepositorioLibros::actualizarLibro(const Libro& libro) {
    try {
        // update() actualiza el registro con el ID especificado
        storage.update(libro);
        return true;
    } catch (const exception& e) {
        cerr << "Error al actualizar libro: " << e.what() << endl;
        return false;
    }
}

bool RepositorioLibros::actualizarCategoria(const Categoria& categoria) {
    try {
        storage.update(categoria);
        return true;
    } catch (const exception& e) {
        cerr << "Error al actualizar categoria: " << e.what() << endl;
        return false;
    }
}

bool RepositorioLibros::eliminarLibro(int id) {
    try {
        // remove<T>(id) elimina el registro con ese ID
        storage.remove<Libro>(id);
        return true;
    } catch (const exception& e) {
        cerr << "Error al eliminar libro: " << e.what() << endl;
        return false;
    }
}

bool RepositorioLibros::eliminarCategoria(int id) {
    try {
        storage.remove<Categoria>(id);
        return true;
    } catch (const exception& e) {
        cerr << "Error al eliminar categoria: " << e.what() << endl;
        return false;
    }
}
