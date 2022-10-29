#ifndef ARCHIVOBUSQUEDAS_H_INCLUDED
#define ARCHIVOBUSQUEDAS_H_INCLUDED
using namespace std;
#include "Busqueda.h"

class ArchivoBusquedas {

private:

public:

    Busqueda leer(int pos);
    bool guardar(Busqueda busqueda);
    bool Modificar(Busqueda busqueda, int pos);
    int getCantidad();
    int buscar(int _id);

};


#endif // ARCHIVOBUSQUEDAS_H_INCLUDED
