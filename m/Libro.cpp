#include "Libro.h"
#include <iostream>

// Constructor por defecto
Libro::Libro() : id(-1), nombre(""), autor(""), anio(0), categoria("") {}

// Constructor con parametros
Libro::Libro(const std::string& nombre, const std::string& autor, int anio, const std::string& categoria)
    : id(-1), nombre(nombre), autor(autor), anio(anio), categoria(categoria) {}

// Getters
int Libro::getId() const {
    return id;
}

std::string Libro::getNombre() const {
    return nombre;
}

std::string Libro::getAutor() const {
    return autor;
}

int Libro::getAnio() const {
    return anio;
}

std::string Libro::getCategoria() const {
    return categoria;
}

// Setters
void Libro::setId(int id) {
    this->id = id;
}

void Libro::setNombre(const std::string& nombre) {
    this->nombre = nombre;
}

void Libro::setAutor(const std::string& autor) {
    this->autor = autor;
}

void Libro::setAnio(const int anio) {
    this->anio = anio;
}

void Libro::setCategoria(const std::string& categoria) {
    this->categoria = categoria;
}

// Método para mostrar información
void Libro::mostrarInfo() const {
    std::cout << "Libro: " << nombre << std::endl;
    std::cout << "Autor: " << autor << std::endl;
    std::cout << "Año: " << anio << std::endl;
    std::cout << "Categoría: " << categoria << std::endl;
}
