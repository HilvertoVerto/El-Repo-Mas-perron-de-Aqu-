#ifndef CONTROLADOR_MENU_H
#define CONTROLADOR_MENU_H

#include <vector>
#include <tuple>
#include "../m/Libro.h"
#include "../m/Categoria.h"
#include "MenuFactory.h"

class ControladorMenu {
private:
    // Metodo para leer un entero con validacion
    int leerEnteroValido(const std::string& mensaje, int min, int max);

    // Metodo para leer un string no vacio
    std::string leerStringNoVacio(const std::string& mensaje);

public:
    ControladorMenu();

    // Mostrar menu principal y gestionar opciones
    // Recibe los datos, los maneja durante la sesion y los retorna modificados
    std::tuple<std::vector<Libro>, std::vector<Categoria>> mostrarMenuPrincipal(
        std::vector<Libro> libros,
        std::vector<Categoria> categorias
    );
};

#endif
