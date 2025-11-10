#ifndef MENU_AGREGAR_CATEGORIA_I_MENU_H
#define MENU_AGREGAR_CATEGORIA_I_MENU_H

#include "I_Menu.h"
#include <iostream>

class MenuAgregarCategoria : public I_Menu {
public:
    MenuAgregarCategoria(const std::vector<Libro>& libros, const std::vector<Categoria>& categorias);
    std::tuple<std::vector<Libro>, std::vector<Categoria>> ejecutar() override;
};

#endif
