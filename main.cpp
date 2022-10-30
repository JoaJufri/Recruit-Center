#include <iostream>
#include <cstring>
using namespace std;
#include "funciones.h"
#include "rlutil.h"
#include "ArchivoBusquedas.h"
#include "ArchivoCandidatos.h"
#include "EmpresaTrabajada.h"
#include "ArchivoRecruiter.h"
#include "ArchivoFavoritos.h"
#include "ArchivoElegidos.h"






int main()
{
    rlutil::setBackgroundColor(rlutil::BLUE);
    rlutil::cls();



    rlutil::cls();

    //CARGA BUSQUEDAS
    /*
    ArchivoBusquedas archivo;
    Busqueda busqueda;

    busqueda.Cargar();
    archivo.guardar(busqueda);
    system("cls");

    rlutil::anykey();
    */
    //Carga Recruiters
    /*
    ArchivoRecruiter archivo;
    Recruiter recruiter;

    recruiter.Cargar();
    archivo.guardar(recruiter);
    rlutil::cls();
    */
    //Carga Candidatos
    /*
    ArchivoCandidatos archivo;
    Candidato candidato;

    candidato.Cargar();
    archivo.guardar(candidato);
    */



    ///INICIO PROGRAMA

    //PantallaInicio();
    MenuPpal();


    ///PRUEBA DE FILTROS
    //FiltroStack();
    //FiltroIngles();
    //FiltroSeniority();
    //FiltroExperiencia();
}
