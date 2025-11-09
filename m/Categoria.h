#ifndef CATEGORIA_H
#define CATEGORIA_H

#include <string>

class Categoria {
private:
    std::string nombre;
    std::string descripcion;

public:
    // Constructor por defecto
    Categoria();

    // Constructor con parametros
    Categoria(const std::string& nombre, const std::string& descripcion);

    // Getters (metodos constantes)
    std::string getNombre() const;
    std::string getDescripcion() const;

    // Setters (argumentos constantes)
    void setNombre(const std::string& nombre);
    void setDescripcion(const std::string& descripcion);

    // Metodo para mostrar informacion de la categoria
    void mostrarInfo() const;
};

#endif // CATEGORIA_H
