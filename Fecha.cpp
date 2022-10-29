#include <iostream>
using namespace std;
#include "Fecha.h"

Fecha::Fecha()
{
    _dia=1;
    _mes=1;
    _anio=1111;
}

int Fecha::getDia() { return _dia; }
void Fecha::setDia(int dia) { _dia = dia; }
int Fecha::getMes() { return _mes; }
void Fecha::setMes(int mes) { _mes = mes; }
int Fecha::getAnio() { return _anio; }
void Fecha::setAnio(int anio) { _anio = anio; }
void Fecha::mostrar(){
    cout << _dia << "/" << _mes << "/" << _anio << endl;
}

void Fecha::cargar(){

    cout<<"Dia: ";
    cin>>_dia;

    cout<<endl<<"Mes: ";
    cin>>_mes;

    cout<<endl<<"Anio: ";
    cin>>_anio;
}
