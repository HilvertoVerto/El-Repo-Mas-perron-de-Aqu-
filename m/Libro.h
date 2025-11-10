#ifndef LIBRO_H
#define LIBRO_H

#include <string>

class Libro {
private:
    int id;
    std::string nombre;
    std::string autor;
    int anio;
    std::string categoria;

public:
    // Constructor por defecto
    Libro();

    // Constructor con parametros (sin ID, se asigna automaticamente)
    Libro(const std::string& nombre, const std::string& autor, int anio, const std::string& categoria);

    // Getters (metodos constantes)
    int getId() const;
    std::string getNombre() const;
    std::string getAutor() const;
    int getAnio() const;
    std::string getCategoria() const;

    // Setters (argumentos constantes)
    void setId(int id);
    void setNombre(const std::string& nombre);
    void setAutor(const std::string& autor);
    void setAnio(const int anio);
    void setCategoria(const std::string& categoria);

    // Metodo para mostrar informacion del libro
    void mostrarInfo() const;
};

#endif // LIBRO_H
