#include "Categoria.h"
#include <iostream>

// Constructor por defecto
Categoria::Categoria() : id(-1), nombre(""), descripcion("") {}

// Constructor con parametros
Categoria::Categoria(const std::string& nombre, const std::string& descripcion)
    : id(-1), nombre(nombre), descripcion(descripcion) {}

// Getters
int Categoria::getId() const {
    return id;
}

std::string Categoria::getNombre() const {
    return nombre;
}

std::string Categoria::getDescripcion() const {
    return descripcion;
}

// Setters
void Categoria::setId(int id) {
    this->id = id;
}

void Categoria::setNombre(const std::string& nombre) {
    this->nombre = nombre;
}

void Categoria::setDescripcion(const std::string& descripcion) {
    this->descripcion = descripcion;
}

// Metodo para mostrar informacion
void Categoria::mostrarInfo() const {
    std::cout << "Categoria: " << nombre << std::endl;
    std::cout << "Descripcion: " << descripcion << std::endl;
}
