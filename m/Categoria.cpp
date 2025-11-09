#include "Categoria.h"
#include <iostream>

// Constructor por defecto
Categoria::Categoria() : libro(""), nombre("") {}

// Constructor con parámetros
Categoria::Categoria(const std::string& libro, const std::string& nombre)
    : libro(libro), nombre(nombre) {}

// Getters
std::string Categoria::getLibro() const {
    return libro;
}

std::string Categoria::getNombre() const {
    return nombre;
}

// Setters
void Categoria::setLibro(const std::string& libro) {
    this->libro = libro;
}

void Categoria::setNombre(const std::string& nombre) {
    this->nombre = nombre;
}

// Método para mostrar información
void Categoria::mostrarInfo() const {
    std::cout << "Categoría: " << nombre << std::endl;
    std::cout << "Libro: " << libro << std::endl;
}
