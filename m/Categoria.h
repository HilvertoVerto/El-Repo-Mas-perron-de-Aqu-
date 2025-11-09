#ifndef CATEGORIA_H
#define CATEGORIA_H

#include <string>

class Categoria {
private:
    std::string libro;
    std::string nombre;

public:
    // Constructor por defecto
    Categoria();

    // Constructor con parámetros
    Categoria(const std::string& libro, const std::string& nombre);

    // Getters (métodos constantes)
    std::string getLibro() const;
    std::string getNombre() const;

    // Setters (argumentos constantes)
    void setLibro(const std::string& libro);
    void setNombre(const std::string& nombre);

    // Método para mostrar información de la categoría
    void mostrarInfo() const;
};

#endif // CATEGORIA_H
