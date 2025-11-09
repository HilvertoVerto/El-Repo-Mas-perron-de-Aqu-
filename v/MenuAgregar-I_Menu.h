#ifndef MENU_AGREGAR_I_MENU_H
#define MENU_AGREGAR_I_MENU_H

#include "I_Menu.h"
#include <iostream>

class MenuAgregar : public I_Menu {
public:
    MenuAgregar(const std::vector<Libro>& libros, const std::vector<Categoria>& categorias);
    std::tuple<std::vector<Libro>, std::vector<Categoria>> ejecutar() override;
};

#endif
