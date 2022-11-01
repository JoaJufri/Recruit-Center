
using namespace std;
#include "funciones.h"
#include "ArchivoEmpresas.h"

Empresa ArchivoEmpresas::leer(int pos){

    Empresa obj;
    FILE *p;
    p=fopen("Empresas.dat","rb");
    if(p==NULL){return obj;}

    fseek(p,sizeof(Empresa)*pos,SEEK_SET);
    fread(&obj,sizeof(Empresa),1,p);
    fclose(p);
    return obj;
}

bool ArchivoEmpresas::guardar(Empresa empresa){

    FILE *p;
    p=fopen("Empresas.dat","ab");
    if(p==NULL){return false;}

    bool ok = fwrite(&empresa,sizeof(Empresa),1,p);
    fclose(p);
    return ok;
}

int ArchivoEmpresas::getCantidad(){

    FILE *p;
    p=fopen("Empresas.dat","rb");
    if(p==NULL){return 0;}

    fseek(p,0,SEEK_END);
    int cantidad = ftell(p)/sizeof(Empresa);
    fclose(p);
    return cantidad;
}

bool ArchivoEmpresas::Modificar(Empresa obj,int pos){

    FILE *p;
    p=fopen("Empresas.dat","rb+");
    if(p==NULL){return false;}

    fseek(p,sizeof(Empresa)*pos,SEEK_SET);
    bool ok = fwrite(&obj,sizeof(Empresa),1,p);
    fclose(p);
    return ok;
}


int ArchivoEmpresas::buscar(string cod){

    cod=aMayusculas(cod);
    int tam = getCantidad();

    for(int i=0; i<tam; i++){
        Empresa obj=leer(i);
        if(obj.getCodigo()==cod){
            return i;
        }
    }
    return -1;
}
