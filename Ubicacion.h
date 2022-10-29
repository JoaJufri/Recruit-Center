#ifndef UBICACION_H_INCLUDED
#define UBICACION_H_INCLUDED


#include <iostream>

using namespace std;
class Ubicacion {

private:
    char pais[35];
    char provincia[35];
    char ciudad[35];
public:
    void setPais(string p);
    void setProvincia(string prov);
    void setCiudad(string ciu);

    string getPais();
    string getProvincia();
    string getCiudad();
    void Cargar();
    void Mostrar();
    Ubicacion();


};


#endif // UBICACION_H_INCLUDED
