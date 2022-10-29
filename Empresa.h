#ifndef EMPRESA_H_INCLUDED
#define EMPRESA_H_INCLUDED

#include <iostream>
#include "Ubicacion.h"
using namespace std;

class Empresa {

private:
    char cod[5];
    char nombre[30];
    char CUIT[12];
    long int telRRHH;
    Ubicacion ubicacion;
public:
    void setCodigo(string c);
    void setNombre(string n);
    void setCUIT(string c);
    void setTelRRHH(long int t);
    void setUbicacion(Ubicacion ubi);

    string getCodigo();
    string getNombre();
    string getCUIT();
    long int getTelRRHH();
    Ubicacion getUbicacion();
    void Cargar();
    void Mostrar();

};




#endif // EMPRESA_H_INCLUDED
