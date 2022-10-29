#ifndef ARCHIVOELEGIDOS_H_INCLUDED
#define ARCHIVOELEGIDOS_H_INCLUDED

#include "Favoritos.h"

class ArchivoElegidos {

private:

public:

    Favoritos leer(int pos);
    buscar(int _dni);
    bool guardar(Favoritos favorito);
    bool Modificar(Favoritos favorito, int pos);
    int getCantidad();
    bool vaciar();
    bool leerTodos(Favoritos *vec, int tam);


};

#endif // ARCHIVOELEGIDOS_H_INCLUDED
