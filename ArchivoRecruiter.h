#ifndef ARCHIVORECRUITER_H_INCLUDED
#define ARCHIVORECRUITER_H_INCLUDED

#include "Recruiter.h"

using namespace std;

class ArchivoRecruiter {

private:


public:

    Recruiter leer(int pos);
    bool guardar(Recruiter recruiter);
    bool Modificar(Recruiter recruiter, int pos);
    int getCantidad();
    int buscar(int _id);
    bool loginExitoso(int _id, string pass);

};

#endif // ARCHIVORECRUITER_H_INCLUDED
