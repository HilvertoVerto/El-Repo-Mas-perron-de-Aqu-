#include "LimpiarPantalla.h"
#include <cstdlib>

void LimpiarPantalla(){
	#ifdef _WIN32
		system("cls");
	#else
		system("clear");
	#endif
}
