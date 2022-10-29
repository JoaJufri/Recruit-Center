#ifndef ARCHIVOFAVORITOS_H_INCLUDED
#define ARCHIVOFAVORITOS_H_INCLUDED

#include "Favoritos.h"
using namespace std;


class ArchivoFavoritos {

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


#endif // ARCHIVOFAVORITOS_H_INCLUDED
