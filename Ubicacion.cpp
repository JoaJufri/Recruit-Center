#include <iostream>
#include <cstring>
#include "Ubicacion.h"
using namespace std;

void Ubicacion::setPais(string p){

    strcpy(pais,p.c_str());
}

void Ubicacion::setCiudad(string ciu){

    strcpy(ciudad,ciu.c_str());
}

void Ubicacion::setProvincia(string prov){

    strcpy(provincia,prov.c_str());
}

string Ubicacion::getCiudad(){return ciudad;}

string Ubicacion::getProvincia(){return provincia;}

string Ubicacion::getPais(){return pais;}

Ubicacion::Ubicacion(){

    pais[0]='-';
    pais[1]='\0';
    provincia[0]='-';
    provincia[1]='\0';
    ciudad[0]='-';
    ciudad[1]='\0';
}


void Ubicacion::Cargar(){


    string aux;
    cout<<"Pais: ";
    getline(cin,aux);
    setPais(aux);
    cout<<endl;


    cout<<"Provincia: ";
    getline(cin,aux);
    setProvincia(aux);
    cout<<endl;


    cout<<"Ciudad: ";
    getline(cin,aux);
    setCiudad(aux);
    cout<<endl;
}

void Ubicacion::Mostrar(){

    cout<<"Pais: "<<pais<<endl;

    cout<<"Provincia: "<<provincia<<endl;

    cout<<"Ciudad: "<<ciudad<<endl;
}
