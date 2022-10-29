#ifndef BUSQUEDA_H_INCLUDED
#define BUSQUEDA_H_INCLUDED

#include <iostream>
#include <cstring>
using namespace std;
#include "funciones.h"


class Busqueda {

private:
    int id;
    int idRecruiter;
    float oferta_salarial;
    bool remoto;
    char nivel_ingles[6];
    char Stack[cant_stack][tam_stack];
    int aniosExp;
    char seniority[4];
    bool activa;

    void cargarCadenaStack(int pos);
    bool StackVacio(int pos);
    void MostrarStack();

public:
    void setActiva(bool act);
    int getID();
    int getIDRecruiter();
    float getOfertaSalarial();
    bool getRemoto();
    string getNivelIngles();
    void getStackString(string Mstr[][tam_stack]);
    int getAniosExp();
    string getSeniority();
    bool getActiva();
    void CargaDeStack();
    void Cargar();
    void Mostrar();

};


#endif // BUSQUEDA_H_INCLUDED
