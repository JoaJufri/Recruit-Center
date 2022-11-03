#include <iostream>
#include <cstring>

using namespace std;
#include "Busqueda.h"

void Busqueda::setActiva(bool act){activa=act;}

bool Busqueda::getActiva(){return activa;}

int Busqueda::getID(){return id;}

int Busqueda::getAniosExp(){return aniosExp;}

int Busqueda::getIDRecruiter(){return idRecruiter;}

float Busqueda::getOfertaSalarial(){return oferta_salarial;}

bool Busqueda::getRemoto(){return remoto;}

string Busqueda::getNivelIngles(){return nivel_ingles;}


string Busqueda::getSeniority(){return seniority;}

string Busqueda::getCodigoCliente(){return codigo_cliente;}

void Busqueda::cargarCadenaStack(int pos){

    fflush(stdin);
    int j;
    for(j=0; j<tam_stack; j++){
        Stack[pos][j]=cin.get();
        if(Stack[pos][j]=='\n') break;
    }
    Stack[pos][j]='\0';
    fflush(stdin);

}

bool Busqueda::StackVacio(int pos){

      int caracteres=0;

      for(int i=0; i<tam_stack; i++){
            //Mientras no sea el fin de cadena ('\0') y no sea un espacio, sumo un caracter al contador
            if(Stack[pos][i]!='\0' && Stack[pos][i]!=' '){caracteres++;}
      }

      //Si tiene mas de 0, no esta vacia y devuelvo false, sino, está vacía y devuelvo true
      if(caracteres>0){return false;}
      return true;

    }


void Busqueda::CargaDeStack(){

 for(int i=0; i<cant_stack; i++){

     for(int j=0; j<tam_stack; j++){

         Stack[i][j]=' ';
     }
 }

    char op;
    cout<<"Cargar Stack? S/N : ";
    cin>>op;
    cout<<endl;

    int i=0;
    while(toupper(op)=='S' && i<cant_stack){

        cout<<"Ingrese stack: ";
        cargarCadenaStack(i);
        i++;

        if(i<cant_stack){
        cout<<"Cargar mas al stack ? S/N: ";
        cin>>op;
        }
        else{op='N';}

        cout<<endl;
    }

}

void Busqueda::MostrarStack(){

    for(int i=0; i<cant_stack; i++){

        if(!StackVacio(i)){
            cout<<"\t";
            for(int j=0; j<tam_stack; j++){

                if(!StackVacio(i)){

                cout<<Stack[i][j];
                }

            }
            cout<<endl;
        }

    }
    cout<<endl;

}


void Busqueda::Cargar(){

    cout<<"ID: ";
    cin>>id;

    cout<<endl<<"ID del Recruiter: ";
    cin>>idRecruiter;

    cin.ignore();
    cout<<endl<<"COD CLIENTE: ";
    string aux;
    getline(cin,aux);
    aux=aMayusculas(aux);
    strcpy(codigo_cliente,aux.c_str());

    cout<<endl<<"Oferta salarial: $";
    cin>>oferta_salarial;

    cout<<endl<<"¿ Acepta trabajo Remoto ? S/N : ";
    char op;
    cin>>op;
    if(toupper(op)=='S'){
        remoto=true;
    }
    else{remoto=false;}

    cout<<endl;

    cin.ignore();
    cout<<"Nivel de Ingles: ";
    getline(cin,aux);
    strcpy(nivel_ingles,aux.c_str());

    cout<<endl;

    CargaDeStack();

    cout<<"Anios de Exp: ";
    cin>>aniosExp;

    cout<<endl<<"Seniority: ";
    cin.ignore();
    getline(cin,aux);
    strcpy(seniority,aux.c_str());

    activa=true;
    cout<<endl;
    cout<<"========================================================"<<endl;

}

void Busqueda::Mostrar(){

    cout<<"Busqueda #"<<id<<endl;
    cout<<"============="<<endl;
    cout<<"ID del Recruiter: "<<idRecruiter<<endl;
    cout<<"Codigo de Empresa del Cliente: "<<codigo_cliente<<endl;
    cout<<"Salario Ofrecido: "<<oferta_salarial<<endl;
    cout<<"Trabajo Remoto: ";
    if(remoto){
        cout<<"SI"<<endl;
    }
    else{cout<<"NO"<<endl;}
    cout<<"Nivel de Ingles: "<<nivel_ingles<<endl;
    cout<<"Stack: "<<endl;
    MostrarStack();
    cout<<"Anios de Experiencia: "<<aniosExp<<endl;
    cout<<"Seniority deseado: "<<seniority<<endl;
    Separador('=');
}
