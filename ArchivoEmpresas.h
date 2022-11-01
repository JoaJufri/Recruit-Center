#ifndef ARCHIVOEMPRESAS_H_INCLUDED
#define ARCHIVOEMPRESAS_H_INCLUDED

using namespace std;
#include "Empresa.h"


class ArchivoEmpresas {

private:

public:

    Empresa leer(int pos);
    bool Modificar(Empresa obj,int pos);
    bool guardar(Empresa empresa);
    int getCantidad();
    int buscar(string cod);

};

#endif // ARCHIVOEMPRESAS_H_INCLUDED
