#include<iostream>
#include<cstring>
#include "EmpresaTrabajada.h"

using namespace std;

//Constructor
EmpresaTrabajada::EmpresaTrabajada(){
    setEstado(false);
}


void EmpresaTrabajada::setSeniority(string sen){

    strcpy(seniority,sen.c_str());
}

void EmpresaTrabajada::setFechaIngreso(Fecha ingreso){
    fechaIngreso=ingreso;
}

void EmpresaTrabajada::setFechaEgreso(Fecha egreso){
    fechaEgreso=egreso;
}

void EmpresaTrabajada::setEstado(bool est){
    estado=est;
}

string EmpresaTrabajada::getSeniority(){return seniority;}

Fecha EmpresaTrabajada::getFechasIngreso(){return fechaIngreso;}

Fecha EmpresaTrabajada::getFechaEgreso(){return fechaEgreso;}

bool EmpresaTrabajada::getEstado(){return estado;}

void EmpresaTrabajada::Cargar(){

    Empresa::Cargar();
    string aux;
    cout<<"Seniority: ";
    getline(cin,aux);
    cout<<endl;
    strcpy(seniority,aux.c_str());
    cout<<endl<<"Fecha de ingreso:"<<endl;
    fechaIngreso.cargar();
    cout<<"Fecha de egreso:"<<endl;
    fechaEgreso.cargar();
    estado=true;
}

void EmpresaTrabajada::Mostrar(){

    Empresa::Mostrar();
    cout<<"Seniority en la empresa: "<<seniority<<endl;
    cout<<"Fecha de ingreso: ";
    fechaIngreso.mostrar();
    cout<<"Fecha de Egreso: ";
    fechaEgreso.mostrar();
}
