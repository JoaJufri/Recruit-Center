#ifndef FAVORITOS_H_INCLUDED
#define FAVORITOS_H_INCLUDED

#include "Candidato.h"

class Favoritos : public Candidato {

private:
    int idBusqueda;
    int idRecruiter;

public:

    void setIdBusqueda(int b);
    void setIdRecruiter(int i);
    int getIdBusqueda();
    int getIdRecruiter();

    void Mostrar();

};

#endif // FAVORITOS_H_INCLUDED
