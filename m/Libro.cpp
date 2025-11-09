#include "Libro.h"
#include <iostream>

// Constructor por defecto
Libro::Libro() : nombre(""), autor(""), anio(0), categoria("") {}

// Constructor con parámetros
Libro::Libro(const std::string& nombre, const std::string& autor, int anio, const std::string& categoria)
    : nombre(nombre), autor(autor), anio(anio), categoria(categoria) {}

// Getters
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
