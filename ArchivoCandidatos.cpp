
#include <cstring>
#include "ArchivoCandidatos.h"
using namespace std;

Candidato ArchivoCandidatos::leer(int pos){
    Candidato candidato;
    FILE *p;
    p=fopen("Candidatos.dat","rb");
    if(p==nullptr){return candidato;}

    fseek(p,sizeof(Candidato)*pos,SEEK_SET);
    fread(&candidato,sizeof(Candidato),1,p);
    fclose(p);
    return candidato;
}

bool ArchivoCandidatos::guardar(Candidato candidato){

    FILE *p;
    p=fopen("Candidatos.dat","ab");
    if(p==nullptr){return false;}

    bool ok = fwrite(&candidato,sizeof(Candidato),1,p);
    fclose(p);
    return ok;
}


bool ArchivoCandidatos::Modificar(Candidato candidato, int pos){

    FILE *p;
    p=fopen("Candidatos.dat","rb+");
    if(p==nullptr){return false;}

    fseek(p,sizeof(Candidato)*pos,SEEK_SET);
    bool ok = fwrite(&candidato,sizeof(Candidato),1,p);
    fclose(p);
    return ok;
}

int ArchivoCandidatos::getCantidad(){

    FILE *p;
    p=fopen("Candidatos.dat","rb");
    if(p==nullptr){return 0;}

    fseek(p,0,SEEK_END);
    int cant = ftell(p)/sizeof(Candidato);
    fclose(p);
    return cant;
}

bool ArchivoCandidatos::leerTodos(Candidato *vec, int tam){

    FILE *p;
    p=fopen("Candidatos.dat","rb");
    if(p==nullptr){return false;}

    fread(vec,sizeof(Candidato),tam,p);
    fclose(p);
    return true;
}


int ArchivoCandidatos::buscar(int _dni){

    Candidato candidato;

    int tam = getCantidad();

    for(int i=0; i<tam; i++){

        candidato = leer(i);
        if(candidato.getDNI()==_dni){return i;}
    }

    return -1;
}
