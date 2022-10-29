#include <cstring>
#include "Recruiter.h"
using namespace std;

void Recruiter::setID(int n){
    ID=n;
}

void Recruiter::setPassword(string pass){

    strcpy(password,pass.c_str());
}

void Recruiter::setNombre(string n){
    strcpy(nombre,n.c_str());
}

void Recruiter::setApellido(string ap){
    strcpy(apellido,ap.c_str());
}

int Recruiter::getID(){ return ID;}

string Recruiter::getPassword(){return password;}

string Recruiter::getNombre(){return nombre;}

string Recruiter::getApellido(){return apellido;}

void Recruiter::Cargar(){

    /*
    int ID;
    char password[10];
    char nombre[20];
    char apellido[20];
    */
    string aux;
    cout<<"ID: ";
    cin>>ID;

    cout<<endl<<"Password: ";
    cin>>aux;
    strcpy(password,aux.c_str());

    cout<<endl<<"Nombre: ";
    cin>>aux;
    strcpy(nombre,aux.c_str());

    cout<<endl<<"Apellido: ";
    cin>>aux;
    strcpy(apellido,aux.c_str());
    cout<<endl;

}


void Recruiter::Mostrar(){

    cout<<"ID: "<<ID<<endl;
    cout<<"Password: "<<password<<endl;
    cout<<"Nombre: "<<nombre<<endl;
    cout<<"Apellido: "<<apellido<<endl;

}
