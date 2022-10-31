#ifndef ARCHIVOCLIENTES_H_INCLUDED
#define ARCHIVOCLIENTES_H_INCLUDED


using namespace std;
#include "Empresa.h"


class ArchivoClientes {

private:

public:

    Empresa leer(int pos);
    buscar(int _dni);
    bool guardar(Empresa empresa);
    bool Modificar(Empresa empresa, int pos);
    int getCantidad();
    bool vaciar();
    bool leerTodos(Empresa *vec, int tam);

~ArchivoClientes();

};

#endif // ARCHIVOCLIENTES_H_INCLUDED
