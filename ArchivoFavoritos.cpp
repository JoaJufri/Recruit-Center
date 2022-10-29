#include <iostream>
using namespace std;
#include "ArchivoFavoritos.h"


Favoritos ArchivoFavoritos::leer(int pos){
    Favoritos favorito;
    FILE *p;
    p=fopen("Favoritos.dat","rb");
    if(p==nullptr){return favorito;}

    fseek(p,sizeof(Favoritos)*pos,SEEK_SET);
    fread(&favorito,sizeof(Favoritos),1,p);
    fclose(p);
    return favorito;
}

bool ArchivoFavoritos::guardar(Favoritos favorito){

    FILE *p;
    p=fopen("Favoritos.dat","ab");
    if(p==nullptr){return false;}

    bool ok = fwrite(&favorito,sizeof(Favoritos),1,p);
    fclose(p);
    return ok;
}

bool ArchivoFavoritos::Modificar(Favoritos favorito,int pos){

    FILE *p;
    p=fopen("Favoritos.dat","rb+");
    if(p==nullptr){return false;}

    fseek(p,sizeof(Favoritos)*pos,SEEK_SET);
    bool ok = fwrite(&favorito,sizeof(Favoritos),1,p);
    fclose(p);
    return ok;
}


int ArchivoFavoritos::getCantidad(){

    FILE *p;
    p=fopen("Favoritos.dat","rb");
    if(p==nullptr){return false;}

    fseek(p,0,SEEK_END);

    int cant = ftell(p)/sizeof(Favoritos);
    fclose(p);
    return cant;
}

bool ArchivoFavoritos::leerTodos(Favoritos *vec, int tam){

    FILE *p;
    p=fopen("Favoritos.dat","rb");
    if(p==nullptr){return false;}

    fread(vec,sizeof(Favoritos),tam,p);

    fclose(p);
    return true;
}


bool ArchivoFavoritos::vaciar(){

    FILE *p;
    p=fopen("Favoritos.dat","wb");
    if(p==nullptr){return false;}

    fclose(p);
    return true;
}

int ArchivoFavoritos::buscar(int _dni){

    Favoritos favorito;

    int tam = getCantidad();

    for(int i=0; i<tam; i++){

        favorito = leer(i);
        if(favorito.getDNI()==_dni){return i;}
    }

    return -1;
}
