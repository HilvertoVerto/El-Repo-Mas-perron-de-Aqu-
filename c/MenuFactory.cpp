#include "MenuFactory.h"
#include <algorithm>

using namespace std;

unique_ptr<I_Menu> MenuFactory::crearMenu(
    TipoMenu tipo,
    const vector<Libro>& libros,
    const vector<Categoria>& categorias
) {
    switch (tipo) {
        case TipoMenu::AGREGAR:
            return make_unique<MenuAgregar>(libros, categorias);

        case TipoMenu::AGREGAR_LIBRO:
            return make_unique<MenuAgregarLibro>(libros, categorias);

        case TipoMenu::AGREGAR_CATEGORIA:
            return make_unique<MenuAgregarCategoria>(libros, categorias);

        case TipoMenu::EDITAR:
            return make_unique<MenuEditar>(libros, categorias);

        case TipoMenu::ELIMINAR_LIBRO:
            return make_unique<MenuEliminarLibro>(libros, categorias);

        default:
            return nullptr;
    }
}

TipoMenu MenuFactory::stringATipoMenu(const string& tipo) {
    string tipoLower = tipo;
    transform(tipoLower.begin(), tipoLower.end(), tipoLower.begin(), ::tolower);

    if (tipoLower == "agregar") {
        return TipoMenu::AGREGAR;
    } else if (tipoLower == "agregar_libro" || tipoLower == "agregarlibro") {
        return TipoMenu::AGREGAR_LIBRO;
    } else if (tipoLower == "agregar_categoria" || tipoLower == "agregarcategoria") {
        return TipoMenu::AGREGAR_CATEGORIA;
    } else if (tipoLower == "editar") {
        return TipoMenu::EDITAR;
    } else if (tipoLower == "eliminar" || tipoLower == "eliminar_libro" || tipoLower == "eliminarlibro") {
        return TipoMenu::ELIMINAR_LIBRO;
    } else {
        return TipoMenu::INVALIDO;
    }
}
