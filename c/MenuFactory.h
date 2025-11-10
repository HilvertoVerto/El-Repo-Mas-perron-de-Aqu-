#ifndef MENU_FACTORY_H
#define MENU_FACTORY_H

#include <memory>
#include <string>
#include "../v/I_Menu.h"
#include "../v/MenuAgregarLibro-I_Menu.h"
#include "../v/MenuAgregarCategoria-I_Menu.h"
#include "../v/MenuEditar-I_Menu.h"
#include "../v/MenuEliminarLibro-I_Menu.h"

enum class TipoMenu {
    AGREGAR_LIBRO,
    AGREGAR_CATEGORIA,
    EDITAR,
    ELIMINAR_LIBRO,
    INVALIDO
};

class MenuFactory {
public:
    static std::unique_ptr<I_Menu> crearMenu(
        TipoMenu tipo,
        const std::vector<Libro>& libros,
        const std::vector<Categoria>& categorias
    );

    static TipoMenu stringATipoMenu(const std::string& tipo);
};

#endif
