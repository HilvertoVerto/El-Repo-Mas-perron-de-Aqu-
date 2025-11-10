#ifndef MENU_EDITAR_I_MENU_H
#define MENU_EDITAR_I_MENU_H

#include "I_Menu.h"
#include <iostream>

class MenuEditar : public I_Menu {
public:
    MenuEditar(const std::vector<Libro>& libros, const std::vector<Categoria>& categorias);
    std::tuple<std::vector<Libro>, std::vector<Categoria>> ejecutar() override;
};

#endif
