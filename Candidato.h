#ifndef CANDIDATO_H_INCLUDED
#define CANDIDATO_H_INCLUDED

#include <cstring>
#include "funciones.h"
#include "EmpresaTrabajada.h"


class Candidato {

private:
    long int dni;
    char nombre[15];
    char apellido[15];
    char mail[30];
    char nivel_ingles[6];
    long int telefono;
    EmpresaTrabajada vEmpresas[3];
    char seniority[4];
    //Constantes tam y cant definidas en "funciones.h"
    char Stack[cant_stack][tam_stack];
    Ubicacion ubicacion;
    float salarioPretendido;

    void CargaDeStack();
    bool StackVacio(int pos);
    void cargarCadenaStack(int pos);
public:
    void setDNI(long int d);
    void setNombre(string n);
    void setApellido(string a);
    void setMail(string m);
    void setNivelIngles(string n);
    void setTelefono(long int t);
    void setEmpresasTrabajadas(EmpresaTrabajada *vec);
    void setSeniority(string s);
    void setStack(char vec[][tam_stack]);
    void setUbicacion(Ubicacion ubi);
    void setSalarioPretendido(float s);

    long int getDNI();
    string getNombre();
    string getApellido();
    string getMail();
    string getNivelIngles();
    long int getTelefono();
    EmpresaTrabajada *getEmpresasTrabajadas();
    void getEmpresasTrabajadas(EmpresaTrabajada vec[]);
    string getSeniority();
    void getStackString(string vec[]);
    void CopiarStack(char stck[][tam_stack]);
    void MostrarStack();
    Ubicacion getUbicacion();
    float getSalarioPretendido();
    void Cargar();
    void Cargar(int _dni=-1);
    void Mostrar();

};




#endif // CANDIDATO_H_INCLUDED
