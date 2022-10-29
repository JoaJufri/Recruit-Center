#include<iostream>
#include<cstring>
using namespace std;
#include "ArchivoRecruiter.h"


Recruiter ArchivoRecruiter::leer(int pos){
    Recruiter recruiter;
    FILE *p;
    p=fopen("Recruiter.dat","rb");
    if(p==nullptr){return recruiter;}

    fseek(p,sizeof(Recruiter)*pos,SEEK_SET);
    fread(&recruiter,sizeof(Recruiter),1,p);
    fclose(p);
    return recruiter;
}

bool ArchivoRecruiter::guardar(Recruiter recruiter){

    FILE *p;
    p=fopen("Recruiter.dat","ab");
    if(p==nullptr){return false;}

    bool ok = fwrite(&recruiter,sizeof(Recruiter),1,p);
    fclose(p);
    return ok;
}


bool ArchivoRecruiter::Modificar(Recruiter recruiter, int pos){

    FILE *p;
    p=fopen("Recruiter.dat","rb+");
    if(p==nullptr){return false;}

    fseek(p,sizeof(Recruiter)*pos,SEEK_SET);
    bool ok = fwrite(&recruiter,sizeof(Recruiter),1,p);
    fclose(p);
    return ok;
}

int ArchivoRecruiter::getCantidad(){

    FILE *p;
    p=fopen("Recruiter.dat","rb");
    if(p==nullptr){return 0;}

    fseek(p,0,SEEK_END);
    int cant = ftell(p)/sizeof(Recruiter);
    fclose(p);
    return cant;
}

bool ArchivoRecruiter::loginExitoso(int _id, string pass){

    Recruiter recruiter;

    int tam = getCantidad();

    for(int i=0; i<tam; i++){

        recruiter=leer(i);

        if(recruiter.getID()==_id && recruiter.getPassword()== pass){
            return true;
        }
    }
    return false;

}


int ArchivoRecruiter::buscar(int _id){

    Recruiter recruiter;
    int tam = getCantidad();

    for(int i=0; i<tam; i++){

        recruiter=leer(i);
        if(recruiter.getID()==_id){return i;}
    }

    return -1;
}
