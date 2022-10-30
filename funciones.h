#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include "Recruiter.h"
#include "Fecha.h"
const int ANCHO_VENTANA = 120;
const int ALTO_VENTANA = 30;

const int cant_stack = 10;
const int tam_stack = 15;

//Visuales
void Logo(int posicionX, int posicionY);
void cargarCadena(char *pal, int tam);
void DivisorHorizontal(int y, char figura);
void cartelPixel(int posx,int posy,int ancho, int alto);
void Separador(char simbolo);
void Alerta(string alerta,bool pausa, bool cls);


//Menus

void MenuPpal();
void MenuLogin(int &IdBusquedaActiva);
void MenuSeleccion(Recruiter usuario,int &IdBusquedaActiva);
void MenuBusqueda(int _idRecruiter,int &IdBusquedaActiva);
void MenuSelecPersonal(Recruiter usuario,int &IdBusquedaActiva);
//Interfaz de Menus
int InterfazBusqueda();
int InterfazSeleccion();
void PantallaInicio();

int PruebaLogin();
void cartelPixel(int posx, int posy, int ancho, int alto);
int InterfazBusqueda();

//Filtros
void FiltroSalario();
void FiltroStack();
void FiltroIngles();
void FiltroSeniority();
void FiltroExperiencia();
//otras
int CalcularAniosExp(Fecha ingreso, Fecha egreso);
string aMayusculas(string s);
bool ExisteElegido(int _dni, int IdBusquedaActiva);
void MostrarBusquedasDisponibles(int _id);
void MostrarElegidos(int IDRecruiter);
#endif // FUNCIONES_H_INCLUDED
