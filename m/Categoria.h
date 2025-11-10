#ifndef CATEGORIA_H
#define CATEGORIA_H

#include <string>

class Categoria {
private:
    int id;
    std::string nombre;
    std::string descripcion;

public:
    // Constructor por defecto
    Categoria();

    // Constructor con parametros (sin ID, se asigna automaticamente)
    Categoria(const std::string& nombre, const std::string& descripcion);

    // Getters (metodos constantes)
    int getId() const;
    std::string getNombre() const;
    std::string getDescripcion() const;

    // Setters (argumentos constantes)
    void setId(int id);
    void setNombre(const std::string& nombre);
    void setDescripcion(const std::string& descripcion);

    // Metodo para mostrar informacion de la categoria
    void mostrarInfo() const;
};

#endif // CATEGORIA_H
