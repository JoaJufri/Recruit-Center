#include <iostream>
#include <cstring>
using namespace std;
#include "funciones.h"
#include "rlutil.h"

#include "ArchivoCandidatos.h"
#include "ArchivoBusquedas.h"

int main()
{
    rlutil::setBackgroundColor(rlutil::BLUE);
    rlutil::cls();


    //Carga Recruiters
    /*
    ArchivoRecruiter archivo;
    Recruiter recruiter;

    recruiter.Cargar();
    archivo.guardar(recruiter);
    rlutil::cls();
    */
    /////////////////////////Carga Candidatos/////////////////////////////////////


    ArchivoCandidatos archivo;
    Candidato candidato;

/*
    char otro='S';
    while(toupper(otro)=='S'){
        AltaCandidato();
        int tam = archivo.getCantidad();
        candidato = archivo.leer(tam-1);
        candidato.Mostrar();
        cout<<endl<<"Otro ? S/N : ";
        cin>>otro;
    }

*/

    ///MOSTRAR CANDIDATOS CARGADOS HASTA AHORA

    int tam = archivo.getCantidad();
    cout<<"CARGADOS: "<<tam<<endl;
    system("pause");
    system("cls");
    for(int i=0; i<tam; i++){
        candidato=archivo.leer(i);
        candidato.Mostrar();
    }



    ///INICIO PROGRAMA

    //PantallaInicio();
    //MenuPpal();


}

