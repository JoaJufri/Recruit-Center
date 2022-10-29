#ifndef RECRUITER_H_INCLUDED
#define RECRUITER_H_INCLUDED

#include <iostream>
using namespace std;
class Recruiter {

private:
    int ID;
    char password[10];
    char nombre[20];
    char apellido[20];
public:
    void setID(int n);
    void setPassword(string);
    void setNombre(string);
    void setApellido(string);

    int getID();
    string getPassword();
    string getNombre();
    string getApellido();
    void Cargar();
    void Mostrar();
};



#endif // RECRUITER_H_INCLUDED
