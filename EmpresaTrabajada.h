#ifndef EMPRESATRABAJADA_H_INCLUDED
#define EMPRESATRABAJADA_H_INCLUDED
#include "Empresa.h"
#include "Fecha.h"

class EmpresaTrabajada : public Empresa {

private:
    char seniority[4];
    Fecha fechaIngreso;
    Fecha fechaEgreso;
    bool estado;
public:
    void setSeniority(string sen);
    void setFechaIngreso(Fecha ingreso);
    void setFechaEgreso(Fecha egreso);
    void setEstado(bool est);

    string getSeniority();
    Fecha getFechasIngreso();
    Fecha getFechaEgreso();
    bool getEstado();
    EmpresaTrabajada();
    void Cargar();
    void Mostrar();

};

#endif // EMPRESATRABAJADA_H_INCLUDED
