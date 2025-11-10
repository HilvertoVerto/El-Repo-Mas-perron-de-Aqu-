#ifndef I_MENU_H
#define I_MENU_H

#include <vector>
#include <tuple>
#include "../m/Libro.h"
#include "../m/Categoria.h"

class I_Menu {
protected:
    std::vector<Libro> libros;
    std::vector<Categoria> categorias;

public:
    virtual ~I_Menu() {}

    virtual std::tuple<std::vector<Libro>, std::vector<Categoria>> ejecutar() = 0;
};

#endif
