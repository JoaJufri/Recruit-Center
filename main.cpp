#include <iostream>
#include <cstring>
using namespace std;
#include "funciones.h"
#include "rlutil.h"




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

    /*
    ArchivoCandidatos archivo;
    Candidato candidato;


    char otro='S';
    while(AltaCandidato() && toupper(otro)=='S'){

        int tam = archivo.getCantidad();
        candidato = archivo.leer(tam-1);
        candidato.Mostrar();
        cout<<endl<<"Otro ? S/N : ";
        cin>>otro;
    }

    */


    ///INICIO PROGRAMA

    PantallaInicio();
    MenuPpal();



    ///PRUEBA DE FILTROS
    //FiltroStack();
    //FiltroIngles();
    //FiltroSeniority();
    //FiltroExperiencia();
}

