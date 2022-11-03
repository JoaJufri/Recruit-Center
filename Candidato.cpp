#include <iostream>
#include <cstring>

using namespace std;
#include "funciones.h"
#include "Candidato.h"


void Candidato::setDNI(long int d){dni=d;}

void Candidato::setNombre(string n){strcpy(nombre,n.c_str());}

void Candidato::setApellido(string a){strcpy(apellido,a.c_str());}

void Candidato::setMail(string m){strcpy(mail,m.c_str());}

void Candidato::setNivelIngles(string n){strcpy(nivel_ingles,n.c_str());}

void Candidato::setTelefono(long int t){telefono=t;}

void Candidato::setEmpresasTrabajadas(EmpresaTrabajada *vec){

    for(int i=0; i<3; i++){
        vEmpresas[i]=vec[i];
    }
}

void Candidato::setSeniority(string s){
    strcpy(seniority,s.c_str());
}



void Candidato::setUbicacion(Ubicacion ubi){ubicacion=ubi;}

void Candidato::setSalarioPretendido(float s){salarioPretendido=s;}

void Candidato::setStack(char vec[][tam_stack]){

    for(int i=0; i<cant_stack; i++){

        for(int j=0; j<tam_stack; j++){

            Stack[i][j]=vec[i][j];
        }
    }

}


long int Candidato::getDNI(){return dni;}

string Candidato::getNombre(){return nombre;}

string Candidato::getApellido(){return apellido;}

string Candidato::getMail(){return mail;}

string Candidato::getNivelIngles(){return nivel_ingles;}

long int Candidato::getTelefono(){return telefono;}

EmpresaTrabajada *Candidato::getEmpresasTrabajadas(){return vEmpresas;}

///Recibe un array de 3 empresas y lo carga
void Candidato::getEmpresasTrabajadas(EmpresaTrabajada vec[]){

    for(int i=0; i<3; i++){

        vec[i]=vEmpresas[i];
    }
}

string Candidato::getSeniority(){return seniority;}



Ubicacion Candidato::getUbicacion(){return ubicacion;}

float Candidato::getSalarioPretendido(){return salarioPretendido;}


void Candidato::CargaDeStack(){

    //Vacio Matriz de stack
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


void Candidato::Cargar(){

    cout<<"DNI: ";
    cin>>dni;

    cin.ignore();
    string aux;
    cout<<endl<<"Nombre: ";
    getline(cin,aux);
    strcpy(nombre,aux.c_str());

    cout<<endl<<"Apellido: ";
    getline(cin,aux);
    strcpy(apellido,aux.c_str());


    cout<<endl<<"Mail: ";
    getline(cin,aux);
    strcpy(mail,aux.c_str());


    cout<<endl<<"Telefono: ";
    cin>>telefono;

    cin.ignore();
    cout<<endl<<"Seniority: ";
    getline(cin,aux);
    strcpy(seniority,aux.c_str());
    cout<<endl;

    cout<<"Nivel de ingles: ";
    getline(cin,aux);
    strcpy(nivel_ingles,aux.c_str());

    cout<<"Salario pretendido: ";
    cin>>salarioPretendido;

    cin.ignore();
    cout<<endl<<"Ubicacion: "<<endl;
    ubicacion.Cargar();

    //OPCIONAL : HACER FUNCION PRIVADA EN CLASE CANDIDATO PARA ESTO. EJ : void CargaExperiencia()
    char opcion;

    for(int i=0; i<3; i++){

        cout<<endl<<"Desea Cargar una Empresa? S/N : ";
        cin>>opcion;
        if(toupper(opcion)=='S'){
            cin.ignore();
            vEmpresas[i].EmpresaTrabajada::Cargar();
        }
        else{
            i=3;
        }
    }

    //Carga por teclado Matriz de Stack
    CargaDeStack();

}


void Candidato::Cargar(int _dni){

    if(_dni!=-1){
        dni=_dni;
    }
    else{
        cout<<"DNI: ";
        cin>>dni;
    }
    cin.ignore();
    string aux;
    cout<<endl<<"Nombre: ";
    getline(cin,aux);
    strcpy(nombre,aux.c_str());

    cout<<endl<<"Apellido: ";
    getline(cin,aux);
    strcpy(apellido,aux.c_str());


    cout<<endl<<"Mail: ";
    getline(cin,aux);
    strcpy(mail,aux.c_str());


    cout<<endl<<"Telefono: ";
    cin>>telefono;

    cin.ignore();
    cout<<endl<<"Seniority: ";
    getline(cin,aux);
    strcpy(seniority,aux.c_str());
    cout<<endl;

    cout<<"Nivel de ingles: ";
    getline(cin,aux);
    strcpy(nivel_ingles,aux.c_str());

    cout<<"Salario pretendido: ";
    cin>>salarioPretendido;

    cin.ignore();
    cout<<endl<<"Ubicacion: "<<endl;
    ubicacion.Cargar();

    //OPCIONAL : HACER FUNCION PRIVADA EN CLASE CANDIDATO PARA ESTO. EJ : void CargaExperiencia()
    char opcion;

    for(int i=0; i<3; i++){

        cout<<endl<<"Desea Cargar una Empresa? S/N : ";
        cin>>opcion;
        if(toupper(opcion)=='S'){
            cin.ignore();
            vEmpresas[i].EmpresaTrabajada::Cargar();
        }
        else{
            i=3;
        }
    }

    //Carga por teclado Matriz de Stack
    CargaDeStack();

}



void Candidato::Mostrar(){

    cout<<"Contacto: "<<endl;
    cout<<"----------"<<endl;
    cout<<"DNI: "<<dni<<endl;
    cout<<"Nombre Completo: "<<apellido<<" "<<nombre<<endl;
    cout<<"Mail: "<<mail<<endl;
    cout<<"Telefono: "<<telefono<<endl;

    ubicacion.Mostrar();
    cout<<endl;

    cout<<"Seniority: "<<seniority<<endl<<endl;
    cout<<"Nivel de Inlges: "<<nivel_ingles<<endl;
    //Mostrar Stack
    cout<<"Stack: "<<endl;
    MostrarStack();

    cout<<"Experiencia: "<<endl;
    for(int i=0; i<3; i++){

        if(vEmpresas[i].getEstado()){
            vEmpresas[i].Mostrar();
            cout<<endl;
        }
    }
    cout<<endl;

    cout<<"Salario Pretendido: "<<salarioPretendido<<endl;

}


void Candidato::cargarCadenaStack(int pos){

    fflush(stdin);
    int j;
    for(j=0; j<tam_stack; j++){
        Stack[pos][j]=cin.get();
        if(Stack[pos][j]=='\n') break;
    }
    Stack[pos][j]='\0';
    fflush(stdin);

}

//Funcion para copiar el stack en un array recibido como parametro
void Candidato::CopiarStack(char stck[][tam_stack]){

    for(int i=0; i<cant_stack; i++){

        for(int j=0; j<tam_stack; j++){
            stck[i][j] = Stack[i][j];
        }
    }
}

bool Candidato::StackVacio(int pos){

      int caracteres=0;

      for(int i=0; i<tam_stack; i++){
            //Mientras no sea el fin de cadena ('\0') y no sea un espacio, sumo un caracter al contador
            if(Stack[pos][i]!='\0' && Stack[pos][i]!=' '){caracteres++;}
      }

      //Si tiene mas de 0, no esta vacia y devuelvo false, sino, está vacía y devuelvo true
      if(caracteres>0){return false;}
      return true;

    }




//Funcion para copiar el stack en un vec de string q se recibe como parametro
void Candidato::getStackString(string vec[cant_stack]){

    for(int i=0; i<cant_stack; i++){
        string aux;
        for(int j=0; j<tam_stack; j++){
            aux += Stack[i][j];

        }
        vec[i]=aux;
    }
}


void Candidato::MostrarStack(){

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

