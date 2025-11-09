#ifndef MENU_ELIMINAR_LIBRO_I_MENU_H
#define MENU_ELIMINAR_LIBRO_I_MENU_H

#include "I_Menu.h"
#include <iostream>

class MenuEliminarLibro : public I_Menu {
public:
    MenuEliminarLibro(const std::vector<Libro>& libros, const std::vector<Categoria>& categorias);
    std::tuple<std::vector<Libro>, std::vector<Categoria>> ejecutar() override;
};

#endif
