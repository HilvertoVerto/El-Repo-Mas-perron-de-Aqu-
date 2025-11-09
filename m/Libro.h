#ifndef LIBRO_H
#define LIBRO_H

#include <string>

class Libro {
private:
    std::string nombre;
    std::string autor;
    int anio;
    std::string categoria;

public:
    // Constructor por defecto
    Libro();

    // Constructor con parámetros
    Libro(const std::string& nombre, const std::string& autor, int anio, const std::string& categoria);

    // Getters (métodos constantes)
    std::string getNombre() const;
    std::string getAutor() const;
    int getAnio() const;
    std::string getCategoria() const;

    // Setters (argumentos constantes)
    void setNombre(const std::string& nombre);
    void setAutor(const std::string& autor);
    void setAnio(const int anio);
    void setCategoria(const std::string& categoria);

    // Método para mostrar información del libro
    void mostrarInfo() const;
};

#endif // LIBRO_H
