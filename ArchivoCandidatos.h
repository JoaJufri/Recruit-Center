#ifndef ARCHIVOCANDIDATOS_H_INCLUDED
#define ARCHIVOCANDIDATOS_H_INCLUDED

#include <iostream>
using namespace std;
#include "Candidato.h"

class ArchivoCandidatos {

private:

public:
    Candidato leer(int pos);
    bool guardar(Candidato candidato);
    bool Modificar(Candidato candidato, int pos);
    int getCantidad();
    int buscar(int _dni);
    bool leerTodos(Candidato *vec, int tam);

};



#endif // ARCHIVOCANDIDATOS_H_INCLUDED
