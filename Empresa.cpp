#include <iostream>
#include <cstring>
#include "Empresa.h"

using namespace std;

void Empresa::setCodigo(string c){
    strcpy(cod,c.c_str());
}

void Empresa::setCUIT(string c){
    strcpy(CUIT,c.c_str());
}

void Empresa::setNombre(string n){
    strcpy(nombre,n.c_str());
}

void Empresa::setTelRRHH(long int t){
    telRRHH=t;
}

void Empresa::setUbicacion(Ubicacion ubi){
    ubicacion=ubi;
}

string Empresa::getCodigo(){return cod;}

string Empresa::getNombre(){return nombre;}

string Empresa::getCUIT(){return CUIT;}

long int Empresa::getTelRRHH(){return telRRHH;}

Ubicacion Empresa::getUbicacion(){ return ubicacion;}


void Empresa::Cargar(){

    string aux;
    cout<<"Codigo de empresa: ";
    getline(cin,aux);
    setCodigo(aux);
    cout<<endl;

    cout<<"Nombre : ";
    getline(cin,aux);
    setNombre(aux);
    cout<<endl;

    cout<<"CUIT: ";
    cin>>CUIT;
    cout<<endl;

    cout<<"Tel. de RRHH: ";
    cin>>telRRHH;
    cout<<endl;

    cin.ignore();
    cout<<"Ubicacion: "<<endl;
    ubicacion.Cargar();
}

void Empresa::Mostrar(){

    cout<<"Codigo: ["<<cod<<"]"<<endl;
    cout<<"Nombre: "<<nombre<<endl;
    cout<<"CUIT: "<<CUIT<<endl;
    cout<<"Tel.RRHH: "<<telRRHH<<endl;
    ubicacion.Mostrar();
    cout<<endl;

}
