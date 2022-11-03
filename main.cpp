#include <iostream>
#include <cstring>
using namespace std;
#include "funciones.h"
#include "rlutil.h"
#include "ArchivoBusquedas.h"
#include "ArchivoCandidatos.h"
#include "ArchivoEmpresas.h"
#include "EmpresaTrabajada.h"
#include "ArchivoRecruiter.h"
#include "ArchivoFavoritos.h"
#include "ArchivoElegidos.h"







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

    //PantallaInicio();
    //MenuPpal();

  /*  Empresa cliente;
    ArchivoEmpresas archivo;



    int tam = archivo.getCantidad();
    for(int i=0; i<tam; i++){
        cliente = archivo.leer(i);
        cliente.Mostrar();
        cout<<"========================================"<<endl;
    }
 */


    ///PRUEBA DE FILTROS
    //FiltroStack();
    //FiltroIngles();
    //FiltroSeniority();
    //FiltroExperiencia();
}

