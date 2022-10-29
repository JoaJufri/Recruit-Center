#include "Favoritos.h"
using namespace std;

//sets
void Favoritos::setIdBusqueda(int b){idBusqueda=b;}
void Favoritos::setIdRecruiter(int i){idRecruiter=i;}
//gets
int Favoritos::getIdBusqueda(){return idBusqueda;}
int Favoritos::getIdRecruiter(){return idRecruiter;}


void Favoritos::Mostrar(){

    Candidato::Mostrar();
}
