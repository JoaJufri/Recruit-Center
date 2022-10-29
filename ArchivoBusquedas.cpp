#include <iostream>
#include "ArchivoBusquedas.h"


Busqueda ArchivoBusquedas::leer(int pos){
    Busqueda busqueda;
    FILE *p;
    p=fopen("Busquedas.dat","rb");
    if(p==nullptr){return busqueda;}

    fseek(p,sizeof(Busqueda)*pos,SEEK_SET);
    fread(&busqueda,sizeof(Busqueda),1,p);
    fclose(p);
    return busqueda;
}

bool ArchivoBusquedas::guardar(Busqueda busqueda){

    FILE *p;
    p=fopen("Busquedas.dat","ab");
    if(p==nullptr){return false;}

    bool ok = fwrite(&busqueda,sizeof(Busqueda),1,p);
    fclose(p);
    return ok;
}


bool ArchivoBusquedas::Modificar(Busqueda busqueda, int pos){

    FILE *p;
    p=fopen("Busquedas.dat","rb+");
    if(p==nullptr){return false;}

    fseek(p,sizeof(Busqueda)*pos,SEEK_SET);
    bool ok = fwrite(&busqueda,sizeof(Busqueda),1,p);
    fclose(p);
    return ok;
}

int ArchivoBusquedas::getCantidad(){

    FILE *p;
    p=fopen("Busquedas.dat","rb");
    if(p==nullptr){return 0;}

    fseek(p,0,SEEK_END);
    int cant = ftell(p)/sizeof(Busqueda);
    fclose(p);
    return cant;
}

int ArchivoBusquedas::buscar(int _id){
    Busqueda busqueda;
    int tam = getCantidad();

    for(int i=0; i<tam; i++){
        busqueda = leer(i);
        if(busqueda.getID()==_id){
            return i;
        }
    }
    return -1;
}
