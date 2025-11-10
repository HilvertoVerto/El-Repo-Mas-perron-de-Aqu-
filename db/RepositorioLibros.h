#ifndef REPOSITORIO_LIBROS_H
#define REPOSITORIO_LIBROS_H

#include <vector>
#include <string>
#include <tuple>
#include <sqlite_orm/sqlite_orm.h>
#include "../m/Libro.h"
#include "../m/Categoria.h"

// Definir el esquema de la base de datos usando SQLite ORM
inline auto crearStorage(const std::string& rutaBD) {
    using namespace sqlite_orm;

    return make_storage(rutaBD,
        // Tabla de libros
        make_table("libros",
            make_column("id", &Libro::setId, &Libro::getId, primary_key().autoincrement()),
            make_column("nombre", &Libro::setNombre, &Libro::getNombre),
            make_column("autor", &Libro::setAutor, &Libro::getAutor),
            make_column("anio", &Libro::setAnio, &Libro::getAnio),
            make_column("categoria", &Libro::setCategoria, &Libro::getCategoria)
        ),
        // Tabla de categorias
        make_table("categorias",
            make_column("id", &Categoria::setId, &Categoria::getId, primary_key().autoincrement()),
            make_column("nombre", &Categoria::setNombre, &Categoria::getNombre),
            make_column("descripcion", &Categoria::setDescripcion, &Categoria::getDescripcion)
        )
    );
}

using Storage = decltype(crearStorage(""));

class RepositorioLibros {
private:
    std::string rutaBD;
    Storage storage;

public:
    // Constructor: recibe la ruta del archivo de base de datos
    RepositorioLibros(const std::string& rutaBD);

    // Inicializar la base de datos (crear tablas si no existen)
    void inicializar();

    // Cargar datos desde la base de datos
    std::tuple<std::vector<Libro>, std::vector<Categoria>> cargarDatos();

    // Guardar datos en la base de datos (sincronizacion completa)
    bool guardarDatos(const std::vector<Libro>& libros, const std::vector<Categoria>& categorias);

    // Operaciones CRUD individuales
    int insertarLibro(const Libro& libro);
    int insertarCategoria(const Categoria& categoria);
    bool actualizarLibro(const Libro& libro);
    bool actualizarCategoria(const Categoria& categoria);
    bool eliminarLibro(int id);
    bool eliminarCategoria(int id);
};

#endif
