#include<iostream>
#include "funciones.h"
#include "rlutil.h"

//Revisar estos includes
#include "ArchivoBusquedas.h"
#include "ArchivoCandidatos.h"
#include "ArchivoRecruiter.h"
#include "ArchivoFavoritos.h"
#include "ArchivoElegidos.h"
#include "ArchivoEmpresas.h"
#include "EmpresaTrabajada.h"
using namespace std;


void cargarCadena(char *pal, int tam){

    int i;
    fflush(stdin);
    for(i=0; i<tam; i++){

        pal[i]=cin.get();
        if(pal[i]=='\n'){
            break;
        }
    }
    pal[i]='\0';
    fflush(stdin);
}


// Dibuja una linea horizontal en la cordenada y recibida, con la figura recibida. (ocupa todo el ancho de pantalla)
void DivisorHorizontal(int y, char figura){

    for(int i=1; i<=ANCHO_VENTANA; i++){

        rlutil::locate(i,y);
        cout<<figura;
    }
    cout<<endl;
}

void Separador(char simbolo){

    for(int i=0; i<ANCHO_VENTANA; i++){
        cout<<simbolo;
    }
    cout<<endl;
}

void cartelPixel(int posx, int posy, int ancho, int alto) {

        for (int i = posx; i < posx + ancho; i++) {
            rlutil::locate(i, posy);
            cout << char(219);
            rlutil::locate(i, posy + alto);
            cout << char(219);
        }

        for (int i = posy; i < posy + alto; i++) {
            rlutil::locate(posx, i);
            cout << char(219);
            rlutil::locate(posx + ancho, i);
            cout << char(219);
        }
        //Ultimo pixel del cartel (esquina inf. derecha)
        rlutil::locate(posx+ancho,posy+alto);
        cout<<char(219);
}


void Alerta(string alerta, bool pausa, bool cls){

    if(cls){
        rlutil::cls();
    }

    int y = ALTO_VENTANA/2;
    int tam = alerta.length();
    int x = ANCHO_VENTANA/2-tam/2;
    int margen=2;
    rlutil::locate(x,y);
    cout<<alerta;
    //Dibujo un cartel al rededor del string con 2 espacios de margen por eje
    cartelPixel(x-margen,y-margen,tam+margen*2,margen*2);

    if(pausa){

        //Ubico una pausa para leer el cartel.
        rlutil::locate(40,25);
        system("pause");
    }

}


string aMayusculas(string s){

    int tam = s.length();

    for(int i=0; i<tam; i++){

        s[i] = toupper(s[i]);
    }
    return s;
}

int JerarquiaNivelIngles(string nivelIngles){
        nivelIngles=aMayusculas(nivelIngles);
        char Niveles[6][2]={ {'A','1'},{'A','2'},{'B','1'},{'B','2'},{'C','1'},{'C','2'} };

        for(int i=0; i<6; i++){
            string aux;
            for(int j=0; j<2; j++){

                aux+=Niveles[i][j];
            }
            if(aux==nivelIngles){
                return i;
            }
        }
        return -1;
    }


void MostrarElegidos(int IDRecruiter){

    ArchivoBusquedas archB;
    int tamB = archB.getCantidad();

    Busqueda *vbusquedas = new Busqueda[tamB];

    for(int i=0; i<tamB; i++){

        vbusquedas[i]=archB.leer(i);
    }

    ArchivoElegidos archE;
    int tamE = archE.getCantidad();

    Favoritos *velegidos = new Favoritos[tamE];
    archE.leerTodos(velegidos,tamE);

    bool hay_registro=false;
    ArchivoRecruiter archR;
    Recruiter UsuarioAct;

    for(int i=0; i<tamB; i++){

        if(vbusquedas[i].getActiva()==false && vbusquedas[i].getIDRecruiter()==IDRecruiter){
            hay_registro=true;
            int busqueda = vbusquedas[i].getID();
            string CodigoCliente = vbusquedas[i].getCodigoCliente();
            ArchivoEmpresas archivoEmpresas;
            Empresa cliente;
            int x=archivoEmpresas.buscar(CodigoCliente);
            cliente=archivoEmpresas.leer(x);
            Separador('=');
            cout<<"BUSQUEDA # "<<busqueda<<endl;
            int pos = archR.buscar(IDRecruiter);
            UsuarioAct=archR.leer(pos);
            cout<<"RECRUITER: "<<UsuarioAct.getApellido()<<" "<<UsuarioAct.getNombre()<<endl;
            cout<<"CLIENTE : "<<cliente.getNombre()<<endl;
            Separador('=');
            cout<<"Candidatos Seleccionados: "<<endl;
            for(int j=0; j<tamE; j++){

                if(velegidos[j].getIdBusqueda()==busqueda){

                    velegidos[j].Mostrar();
                    Separador('*');

                }
            }
        }
    }
    if(hay_registro){
        system("pause");
    }
    else{
        string msj = "NO HAY BUSQUEDAS FINALIZADAS PARA EL USUARIO LOGEADO";
        Alerta(msj,true,true);
    }

    delete[] vbusquedas;
    delete[] velegidos;
}

// FILTROS ----------------------------------------------------------------------------------------------

void FiltroSalario(){

    ArchivoFavoritos archFavoritos;

    float salario;
    string msj="Ingrese salario maximo deseado:         ";
    Alerta(msj,false,true);
    rlutil::locate(ANCHO_VENTANA/2 + msj.length()/2 -8,15);
    cin>>salario;
    cout<<endl;

    int tam=archFavoritos.getCantidad();

    Favoritos *vFavoritos = new Favoritos[tam];

    for(int i=0; i<tam; i++){
        vFavoritos[i]=archFavoritos.leer(i);
    }

    //Cuento las coincidencias para el filtro aplicado
    int coincidencias=0;

    for(int i=0; i<tam; i++){

        if(vFavoritos[i].getSalarioPretendido()<=salario){

            coincidencias++;
        }
    }

    if(coincidencias>0){
        //Vacio el archivo
        archFavoritos.vaciar();

        //Agrego las coincidencias al archivo vacio
        for(int i=0; i<tam; i++){

            if(vFavoritos[i].getSalarioPretendido()<=salario){

                archFavoritos.guardar(vFavoritos[i]);
            }
        }

        msj = "Coincidencias encontradas, ver 'Favoritos'";
        Alerta(msj,true,true);
    }
    else{

        //Si no hay coincidencias
        msj="No se hallaron coincidencias, no hay nuevos favoritos";
        Alerta(msj,true,true);
    }

    delete[] vFavoritos;

}


void FiltroStack(){

    ArchivoFavoritos archFavoritos;

    cin.ignore();
    string _stack;
    string msj="Ingrese lenguaje de Stack buscado:                ";
    Alerta(msj,false,true);
    rlutil::locate(ANCHO_VENTANA/2 + msj.length()/2 -15,15);
    getline(cin,_stack);
    _stack=aMayusculas(_stack);
    /// Concateno el '\0' Y Calculo la cantidad de " " espacios faltantes (El array de stack se llena completa de espacios vacios)

    int espacios = tam_stack - _stack.length()-1;
    _stack+='\0';
    for(int i=0; i<espacios; i++){
        //Agrego espacios
        _stack+=" ";
    }

    cout<<endl;

    int tam = archFavoritos.getCantidad();
    Favoritos *favs = new Favoritos[tam];

    archFavoritos.leerTodos(favs,tam);

    bool coincidencias = false;

    /// BUSCO SI HAY COINCIDENCIAS PARA SABER SI HAY Q BORRAR EL ARCHIVO
    for(int x=0; x<tam; x++){
        string Vstack[cant_stack];
        favs[x].getStackString(Vstack);

        for(int i=0; i<cant_stack; i++){
            int valor_comp = _stack.compare(Vstack[i]);
            if(valor_comp==0){
                coincidencias=true;
                break;
            }

        }
        if(coincidencias) break;
    }

    if(coincidencias){

        /// Vacio archivo favoritos
        archFavoritos.vaciar();
        /// Recorro de nuevo y esta vez guardo las coincidencias en el archivo previamente borrado

        for(int x=0; x<tam; x++){
            string Vstack[cant_stack];
            favs[x].getStackString(Vstack);
            for(int i=0; i<cant_stack; i++){

                if(Vstack[i].compare(_stack)==0){
                    // Guardo Los Favoritos que machearon
                    archFavoritos.guardar(favs[x]);
                }

            }
        }

        msj="Coincidencias encontradas, ver 'Favoritos' ";
        Alerta(msj,true,true);
    }

    else{

        msj="No se hallaron coincidencias, no hay nuevos favoritos";
        Alerta(msj,true,true);
    }

    /// LIBERO LA MEMORIA
    delete[] favs;

}


void FiltroIngles(){


    ArchivoFavoritos archFavoritos;

    string _ingles;
    string msj="Ingrese Nivel de Ingles buscado:      ";
    Alerta(msj,false,true);
    rlutil::locate(ANCHO_VENTANA/2 + msj.length()/2 -5,15);
    cin.ignore();
    getline(cin,_ingles);


    int nivel_ingresado = JerarquiaNivelIngles(_ingles);
    int nivel_actual;
    int tam = archFavoritos.getCantidad();

    Favoritos *favs = new Favoritos[tam];

    archFavoritos.leerTodos(favs,tam);
    bool coincidencias;
    for(int i=0; i<tam; i++){
        string XX = favs[i].getNivelIngles();
        nivel_actual=JerarquiaNivelIngles(XX);
        if(nivel_actual>=nivel_ingresado){
            coincidencias = true;
            break;
        }
    }

    if(coincidencias){
        //Vacio archivo de favoritos
        archFavoritos.vaciar();

        for(int i=0; i<tam; i++){
            string XX = favs[i].getNivelIngles();
            nivel_actual = JerarquiaNivelIngles(XX);
            if(nivel_actual>=nivel_ingresado){

                archFavoritos.guardar(favs[i]);
            }
        }

        msj="Coincidencias encontradas, ver 'Favoritos' ";
        Alerta(msj,true,true);
    }
    else{
        msj="No se hallaron coincidencias, no hay nuevos favoritos ";
        Alerta(msj,true,true);
    }
    //Libera la memoria
    delete[] favs;

}


void FiltroSeniority(){

    ArchivoFavoritos archivofavs;
    string _seniority;
    string msj = "Ingrese el Seniority actual deseado:      ";
    Alerta(msj,false,true);
    rlutil::locate(ANCHO_VENTANA/2 + msj.length()/2 - 4,15);
    cin.ignore();
    getline(cin,_seniority);
    _seniority=aMayusculas(_seniority);

    int tam = archivofavs.getCantidad();

    Favoritos *favs = new Favoritos[tam];

    archivofavs.leerTodos(favs,tam);

    bool coincidencias=false;

    for(int i=0; i<tam; i++){
        if(favs[i].getSeniority()==_seniority){
            coincidencias = true;
            break;
        }
    }

    if(coincidencias){

        archivofavs.vaciar();

        for(int i=0; i<tam; i++){

            if(favs[i].getSeniority()==_seniority){

                archivofavs.guardar(favs[i]);
            }

        }

        msj="Coincidencias encontradas, ver 'Favoritos' ";
        Alerta(msj,true,true);
    }
    else{
        msj="No se hallaron coincidencias, no hay nuevos favoritos ";
        Alerta(msj,true,true);
    }

    delete[] favs;


}

///Funcion para dar de alta un candidato (no permite dar de alta un dni existente en el archivo)
bool AltaCandidato(){

    system("cls");
    ArchivoCandidatos archivo;
    Candidato candidato;
    int _dni;
    char op='S';
    bool ok=false;

    while(toupper(op)=='S'){
        system("cls");
        cout<<"Ingrese dni: ";
        cin>>_dni;
        if(archivo.buscar(_dni)>=0){

            cout<<endl<<"Candidato existente, reintentar ? S/N: ";
            cin>>op;

        }
        else{
            op='N';
            candidato.Cargar(_dni);
            ok = archivo.guardar(candidato);

        }


    }
    return ok;
}


///Funcion auxiliar para Filtro experiencia
int CalcularAniosExp(Fecha ingreso, Fecha egreso){


    int anios_transcurridos = egreso.getAnio() - ingreso.getAnio();
    if(anios_transcurridos==0) return 0;

    int total_dias=0;

    int diasxanioEgreso = ( (egreso.getMes()-1)*30 + egreso.getDia() );
    int diasxanioIngreso = 365 - ( (ingreso.getMes()-1)*30+ingreso.getDia() );
    total_dias += diasxanioIngreso+diasxanioEgreso;

    int anioing = ingreso.getAnio();
    int anioegr = egreso.getAnio();

    int x = anioing+1;
    for(int i=x; i<anioegr; i++){

        total_dias += 365;

    }
    total_dias/=365;
    return total_dias;
}


void FiltroExperiencia(){

    ArchivoFavoritos archFavoritos;

    int exp=0;
    int anios;
    string msj="Ingrese años de experiencia buscados:  ";
    Alerta(msj,false,true);
    rlutil::locate(ANCHO_VENTANA/2 + msj.length()/2 ,15);
    cin>>anios;

    int tam=archFavoritos.getCantidad();

    Favoritos *favs = new Favoritos[tam];

    archFavoritos.leerTodos(favs,tam);
    bool coincidencias = false;

    for(int i=0; i<tam; i++){
        EmpresaTrabajada vExperiencias[3];
        favs[i].getEmpresasTrabajadas(vExperiencias);
        exp=0;
        for(int j=0; j<3; j++){

            Fecha Fingreso=vExperiencias[j].getFechasIngreso();
            Fecha Fegreso = vExperiencias[j].getFechaEgreso();
            if(vExperiencias[j].getEstado()){
                exp+=CalcularAniosExp(Fingreso,Fegreso);
            }
        }
            if(exp>=anios){
                coincidencias=true;
                break;
            }
    }

    if(coincidencias){

        archFavoritos.vaciar();
        for(int i=0; i<tam; i++){
        EmpresaTrabajada vExperiencias[3];
        favs[i].getEmpresasTrabajadas(vExperiencias);
        exp=0;

            for(int j=0; j<3; j++){

                Fecha ingreso=vExperiencias[j].getFechasIngreso();
                Fecha egreso = vExperiencias[j].getFechaEgreso();
                if(vExperiencias[j].getEstado()){
                    exp+=CalcularAniosExp(ingreso,egreso);
                }
            }

            if(exp>=anios){

                archFavoritos.guardar(favs[i]);
            }
        }

        msj="Coincidencias encontradas, ver 'Favoritos' ";
        Alerta(msj,true,true);
    }
    else{
        msj="No se encontraron coincidencias, no hay nuevos favoritos";
        Alerta(msj,true,true);
    }

    delete[] favs;

}


void FiltroUbicacion(){
    ArchivoFavoritos archFavoritos;
    string prov;
    string msj="Ingrese Provincia buscada:                      ";
    Alerta(msj,false,true);
    rlutil::locate(ANCHO_VENTANA/2+msj.length()/2 - 20,15);
    cin.ignore();
    getline(cin,prov);

    prov=aMayusculas(prov);
    int tam = archFavoritos.getCantidad();
    Favoritos *favs = new Favoritos[tam];
    archFavoritos.leerTodos(favs,tam);
    bool coincidencias = false;
    for(int i=0; i<tam; i++){
        if(favs[i].getUbicacion().getProvincia()==prov){
            coincidencias=true;
            break;
        }
    }

    if(coincidencias){

        archFavoritos.vaciar();
        for(int i=0; i<tam; i++){
            if(favs[i].getUbicacion().getProvincia()==prov){
                archFavoritos.guardar(favs[i]);
            }
        }
        msj="Coincidencias encontradas, ver 'Favoritos' ";
        Alerta(msj,true,true);
    }
    else{
        msj="No se hallaron coincidencias, no hay nuevos Favoritos.";
        Alerta(msj,true,true);
    }
    delete[] favs;
}


///MENUS

//BUSQUEDAS - MENU

void MostrarBusquedasDisponibles(int _id){

    ArchivoBusquedas archivo;
    Busqueda busqueda;

    int tam = archivo.getCantidad();

    for(int i=0; i<tam; i++){

        busqueda = archivo.leer(i);
        if(busqueda.getIDRecruiter()==_id && busqueda.getActiva()){

            busqueda.Mostrar();
            cout<<endl;
        }
    }
}


int InterfazBusqueda(){

   rlutil::setBackgroundColor(rlutil::BLACK);
   rlutil::setColor(rlutil::CYAN);
   rlutil::cls();
   rlutil::hidecursor();

   bool on=true;
   int opcion_elegida;
   int x = 36;
   int y = 6;
   const int DESPLAZAMIENTO = 7;
   rlutil::locate(x,y);
   cout<<char(16);
   while(on){

        rlutil::locate(47,6);
        cout<<"BUSQUEDAS DISPONIBLES";
        cartelPixel(45,4,25,4);

        rlutil::locate(40,13);
        cout<<"ACTIVAR BUSQUEDA / MOSTRAR B.ACTIVA";
        cartelPixel(38,11,39,4);

        rlutil::locate(55,20);
        cout<<"ATRAS";
        cartelPixel(53,18,8,4);

        int tecla = rlutil::getkey();

        switch(tecla){

        case 14: //UP
            {
                rlutil::locate(x,y);
                cout<<" ";
                y-=DESPLAZAMIENTO;
                if(y<6){y=6;}

            }
            break;

        case 15: //DOWN
            {
                rlutil::locate(x,y);
                cout<<" ";
                y+=DESPLAZAMIENTO;
                if(y>20){
                    y=20;
                }

            }
            break;

        case 1: //ENTER
            {
                if(y==6){opcion_elegida=1;}
                if(y==13){opcion_elegida=2;}
                if(y==20){opcion_elegida=0;}
                on=false;
            }
            break;

        default:

            break;
        }

        rlutil::locate(x,y);
        cout<<char(16);
    }

    return opcion_elegida;
}


///////////////////// **** MENU SELECCION DE BUSQUEDA  *** ////////////////////////////////////////////////////////

void MenuBusqueda(Recruiter usuario,int &IdBusquedaActiva){

    bool on=true;
    int op;


    while(on){

        op=InterfazBusqueda();
        string msj;
        switch(op){

        case 1:
            {
                system("cls");
                //Mostrar Busquedas que coincidan con el id del recruiter
                MostrarBusquedasDisponibles(usuario.getID());
                cout<<endl;
                system("pause");
            }
            break;

        case 2:
            {
                system("cls");
                if(IdBusquedaActiva!=-1){
                    //Mostrar B.activa
                    cout<<"Busqueda activa: "<<endl;
                    ArchivoBusquedas archivoB;
                    Busqueda busquedaActiva;
                    int x=archivoB.buscar(IdBusquedaActiva);
                    busquedaActiva=archivoB.leer(x);
                    busquedaActiva.Mostrar();
                    system("pause");

                }
                else{
                    int _id;
                    ArchivoBusquedas archivoB;
                    Busqueda busqueda;
                    msj="Ingrese ID de busqueda a Activar:    ";
                    int largo = msj.length();
                    Alerta(msj,false,true);
                    rlutil::showcursor();
                    rlutil::locate(ANCHO_VENTANA/2 + largo/2-2,15);
                    cin>>_id;
                    rlutil::hidecursor();
                    int pos=archivoB.buscar(_id);
                    if(pos!=-1){

                        busqueda=archivoB.leer(pos);
                        if(busqueda.getIDRecruiter()==usuario.getID() && busqueda.getActiva()){
                            IdBusquedaActiva=busqueda.getID();
                            msj="Busqueda Activada correctamente";
                            Alerta(msj,true,true);
                        }
                        else{
                            msj="La Busqueda ingresada no coincide con el Recruiter logeado";
                            Alerta(msj,true,true);
                        }
                    }
                    else{
                        msj="La busqueda ingresada no existe! ";
                        Alerta(msj,true,true);
                    }
                }
            }

            break;

        case 0:
            on=false;
            break;

        default:

            break;
        }
    }

}




bool ExisteElegido(int _dni, int IdBusquedaActiva){

    ArchivoElegidos archivoElegidos;
    int cant = archivoElegidos.getCantidad();
    Favoritos *vElegidos = new Favoritos[cant];
    archivoElegidos.leerTodos(vElegidos,cant);
    for(int i=0; i<cant; i++){
        if(vElegidos[i].getDNI()==_dni && vElegidos[i].getIdBusqueda()==IdBusquedaActiva){
            delete[] vElegidos;
            return true;
        }
    }
    delete[] vElegidos;
    return false;
}


/////////////////////////////////// *** MENU FILTROS** /////////////////////////////////////////////////

void MenuFiltros(Recruiter usuario,int& IdBusquedaActiva){

    ArchivoFavoritos archivoFav;
    int cant = archivoFav.getCantidad();
    if(cant<=0){
        ArchivoCandidatos archivocand;
        int cant2 = archivocand.getCantidad();
        Candidato *candidatos = new Candidato[cant2];
        Favoritos *favoritos = new Favoritos[cant2];
        archivocand.leerTodos(candidatos,cant2);


        for(int i=0; i<cant2; i++){

            //Carga los candidatos en el archivo de favoritos
            favoritos[i].setIdBusqueda(IdBusquedaActiva);
            favoritos[i].setIdRecruiter(usuario.getID());
            favoritos[i].setDNI(candidatos[i].getDNI());
            favoritos[i].setNombre(candidatos[i].getNombre());
            favoritos[i].setApellido(candidatos[i].getApellido());
            favoritos[i].setMail(candidatos[i].getMail());
            favoritos[i].setNivelIngles(candidatos[i].getNivelIngles());
            favoritos[i].setTelefono(candidatos[i].getTelefono());
            favoritos[i].setEmpresasTrabajadas(candidatos[i].getEmpresasTrabajadas());
            favoritos[i].setSeniority(candidatos[i].getSeniority());
            //Matriz auxiliar para setear stack
            char stck[cant_stack][tam_stack];
            candidatos[i].CopiarStack(stck);
            favoritos[i].setStack(stck);
            favoritos[i].setUbicacion(candidatos[i].getUbicacion());
            favoritos[i].setSalarioPretendido(candidatos[i].getSalarioPretendido());
            archivoFav.guardar(favoritos[i]);

        }


        delete[] candidatos;
        delete[] favoritos;
    }

    bool on = true;
        char op;
        while(on){
            system("cls");
            int x = 10;
            int x2=0;
            string msj="1 - Filtrar por Salario pretendido";
            int largo = msj.length();
            rlutil::locate(x,6);
            cout<<msj;
            cartelPixel(x-1,5,largo+1,2);
            msj="2 - Filtrar por Stack";
            largo = msj.length();
            rlutil::locate(x,10);
            cout<<msj;
            cartelPixel(x-1,9,largo+1,2);
            msj="3 - Filtrar por Nivel de Ingles";
            largo = msj.length();
            rlutil::locate(x,14);
            cout<<msj;
            cartelPixel(x-1,13,largo+1,2);
            msj="4 - Filtrar por Seniority actual";
            x2= 70;
            largo = msj.length();
            rlutil::locate(x2,6);
            cout<<msj;
            cartelPixel(x2-1,5,largo+1,2);
            msj="5 - Filtrar por Experiencia Total";
            largo = msj.length();
            rlutil::locate(x2,10);
            cout<<msj;
            cartelPixel(x2-1,9,largo+1,2);

            msj="6 - Filtrar por Ubicacion";
            largo = msj.length();
            rlutil::locate(x2,14);
            cout<<msj;
            cartelPixel(x2-1,13,largo+1,2);

            msj="7 - Borrar Filtros aplicados";
            largo = msj.length();
            rlutil::locate(ANCHO_VENTANA/2 - largo/2,22);
            cout<<msj;
            cartelPixel(ANCHO_VENTANA/2 - largo/2-1,21,largo+1,2);

            msj="0 - Volver a Seleccion ";
            largo = msj.length();
            rlutil::locate(ANCHO_VENTANA/2 - largo/2,26);
            cout<<msj;
            cartelPixel(ANCHO_VENTANA/2 - largo/2 -1 ,25,largo,2);

            msj="Elegir opcion:  ";
            largo = msj.length();
            rlutil::locate(ANCHO_VENTANA/2 - largo/2,29);
            cout<<msj;
            rlutil::showcursor();
            rlutil::locate(ANCHO_VENTANA/2 + largo/2,29);
            cin>>op;
            rlutil::hidecursor();

            switch(op){

            case '1':
                {
                    FiltroSalario();
                }
                break;

            case '2':
                {
                    FiltroStack();
                }
                break;

            case '3':
                {
                    FiltroIngles();
                }
                break;

            case '4':
                {
                    FiltroSeniority();
                }
                break;

            case '5':
                {
                    FiltroExperiencia();
                }
                break;

            case '6':
                {
                    FiltroUbicacion();
                }
                break;

            case '7':
                {
                    archivoFav.vaciar();
                    msj="Filtros borrados correctamente, se vacio el archivo de favoritos.";
                    Alerta(msj,true,true);
                    //Lo saco para que vuelva a cargar los favoritos con todos los candidatos
                    on = false;
                }
                break;

            case '0':
                {
                    on=false;
                }
                break;

            default:

                break;
            }
        }

}


/////////////**** Menu Seleccion de Personal ***** (filtros/canidatos/favoritos/Envio de Candidatos/Atras)****//////////////////////////////////

void MenuSelecPersonal(Recruiter usuario, int& IdBusquedaActiva){

    bool on=true;
    char op;
    ArchivoFavoritos archivoF;

    while(on==true && IdBusquedaActiva!=-1){

        rlutil::cls();

        Logo(1,6);
        Logo(95,6);

        string msj="1 - Lista de Candidatos";
        int largo = msj.length();
        int x = ANCHO_VENTANA/2 - largo/2;
        rlutil::locate(x, 6);
        cout<<msj;
        cartelPixel(x-1,5,largo+1,2);

        msj="2 - Filtros";
        largo = msj.length();
        x = ANCHO_VENTANA/2 - largo/2;
        rlutil::locate(x, 10);
        cout<<msj;
        cartelPixel(x-1,9,largo+1,2);

        msj="3 - Favoritos";
        largo=msj.length();
        x = ANCHO_VENTANA/2 - largo/2;
        rlutil::locate(x, 14);
        cout<<msj;
        cartelPixel(x-1,13,largo+1,2);

        msj="4 - Envio de Candidatos";
        largo = msj.length();
        x = ANCHO_VENTANA/2 - largo/2;
        rlutil::locate(x, 18);
        cout<<msj;
        cartelPixel(x-1,17,largo+1,2);

        msj="0 - Atras";
        largo=msj.length();
        x = ANCHO_VENTANA/2 - largo/2;
        rlutil::locate(x, 22);
        cout<<msj;
        cartelPixel(x-1,21,largo+1,2);

        msj="Elija una opcion:   ";
        largo=msj.length();
        x = ANCHO_VENTANA/2 - largo/2;
        rlutil::locate(x, 26);
        cout<<msj;

        x = ANCHO_VENTANA/2 + largo/2;
        rlutil::showcursor();
        rlutil::locate(x-2, 26);
        cin>>op;
        rlutil::hidecursor();
        switch(op){

        case '1':
            {   //Muestro Lista Total de Candidatos.
                system("cls");
                ArchivoCandidatos archivoC;

                int tam = archivoC.getCantidad();
                Candidato *candidatos = new Candidato[tam];

                archivoC.leerTodos(candidatos,tam);
                Separador('-');
                Separador('=');
                Separador('-');
                for(int i=0; i<tam; i++){

                    candidatos[i].Mostrar();
                    Separador('=');
                }
                system("pause");
                delete[] candidatos;

            }

            break;

        case '2'://Menu de Filtros
            {
                system("cls");

                MenuFiltros(usuario,IdBusquedaActiva);

            }

            break;

        case '3':
            {
                system("cls");
                //Si el archivo Favoritos tiene registros, los muestro
                int cant=archivoF.getCantidad();
                if(cant>0){

                    Favoritos *favoritos = new Favoritos[cant];

                    archivoF.leerTodos(favoritos,cant);

                    for(int i=0; i<cant; i++){

                        favoritos[i].Mostrar();
                        Separador('=');
                    }
                    system("pause");
                    delete[] favoritos;
                }
                //SI NO, ESTA VACIO, INFORMO:
                else{

                    string msj="El archivo de Favoritos esta vacío";
                    Alerta(msj,true,true);
                }

            }


            break;

        case '4':
            {
                system("cls");

                //Archivo final de candidatos elegidos
                ArchivoElegidos archivoElegidos;
                Favoritos elegido;


                if(archivoF.getCantidad()>0){
                    char opcion;
                    string msj = "Agregar Candidato a la busqueda activa? S/N :  ";
                    /// Hace un cartel centrado en la pantalla (mensaje,pausa,borrarpantalla)
                    Alerta(msj,false,true);
                    /// Posiciona el cin en la posicion deseada dentro del cartel
                    rlutil::locate(ANCHO_VENTANA/2 + msj.length()/2 -1,15);
                    cin>>opcion;
                    while(toupper(opcion)=='S'){

                        msj="Ingresar DNI del candidato seleccionado :          ";
                        Alerta(msj,false,true);
                        int _dni;
                        rlutil::locate(ANCHO_VENTANA/2 + msj.length()/2 -8,15);
                        cin>>_dni;
                        //Me aseguro de que el dni ingresado exista en los Favoritos
                        if(archivoF.buscar(_dni)<0){
                            msj="Candidato Inexistente. ";
                            Alerta(msj,true,true);
                        }
                        else{

                            //Compruebo si existe el candidato en el archivo final para esta busqueda (no debe repetirse un candidato para la misma busqueda)
                            if(ExisteElegido(_dni,IdBusquedaActiva)){
                                msj="ERROR, El candidato ingresado ya ha sido enviado a la Busqueda Activa";
                                Alerta(msj,true,true);
                            }
                            else{
                                //Si existe y no esta repetido para la busqueda, lo guardo en el archivo Elegidos.Dat
                                int posicion=archivoF.buscar(_dni);
                                elegido = archivoF.leer(posicion);
                                elegido.setIdBusqueda(IdBusquedaActiva);
                                elegido.setIdRecruiter(usuario.getID());
                                archivoElegidos.guardar(elegido);
                                msj="Candidato Enviado con exito";
                                Alerta(msj,true,true);
                            }

                        }

                        msj="Desea Agregar otro candidato a la Busqueda ? S/N :  ";
                        Alerta(msj,false,true);
                        rlutil::locate(ANCHO_VENTANA/2 + msj.length()/2 -1,15);
                        cin>>opcion;
                    }

                    rlutil::cls();
                    char opcion2;

                    msj="Desea Finalizar la Busqueda activa con los candidatos actuales ? S/N :  ";
                    Alerta(msj,false,true);
                    rlutil::locate(ANCHO_VENTANA/2 + msj.length()/2 -1,15);
                    cin>>opcion2;

                    if(toupper(opcion2)=='S'){
                        ArchivoBusquedas archivoB;
                        Busqueda busqueda;

                        int pos = archivoB.buscar(IdBusquedaActiva);
                        busqueda = archivoB.leer(pos);
                        ///Desactivo la busqueda activa y actualizo el archivo
                        busqueda.setActiva(false);
                        archivoB.Modificar(busqueda,pos);

                        ///Cambio la bandera de busqueda activa, ahora el usuario tiene que activar otra ( si tiene )
                        IdBusquedaActiva = -1;
                    }


                }
                else{
                    string nofavs="No hay ningun favorito para cargar. ";
                    Alerta(nofavs,true,true);
                }


            }
            break;

        case '0':
            {
                on=false;
            }
            break;

        default:

            break;
        }
    }

}

int InterfazSeleccion(){
    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::setColor(rlutil::LIGHTBLUE);
    rlutil::cls();
    int opcion_elegida;
    bool on=true;
    int tecla;

    //Lo que me tengo que correr en y desde una opcion a otra (dejo 2 espacios entre cartel y cartel.. 5+2 = 7)
    const int DESPLAZAMIENTO = 7;

    rlutil::hidecursor();


        rlutil::cls();
        rlutil::locate(55,6);
        cout<<"BUSQUEDAS";
        cartelPixel(53,4,13,4);

        rlutil::locate(50,13);
        cout<<"SELECCION DE PERSONAL";
        cartelPixel(48,11,24,4);

        rlutil::locate(50,20);
        cout<<"BUSQUEDAS FINALIZADAS";
        cartelPixel(48,18,24,4);

        rlutil::locate(57,27);
        cout<<"ATRAS";
        cartelPixel(54,25,10,4);


    //Cursor en la primera opcion
    int x=46;
    int y=6;
    rlutil::locate(x,y);
    cout<<char(16);
    while(on==true){

        tecla = rlutil::getkey();

        switch(tecla){

        case 15: //DOWN
                {
                   rlutil::locate(x,y);
                   cout<<" ";
                   y+=DESPLAZAMIENTO;
                   if(y>27){
                        y=27;
                    }

                }

            break;

        case 14: //UP
                {
                    rlutil::locate(x,y);
                    cout<<" ";
                    y-=DESPLAZAMIENTO;
                    if(y<6){y=6;}
                }
            break;

        case 1: //ENTER
                {
                    if(y==6){opcion_elegida=1;}
                    if(y==13){opcion_elegida=2;}
                    if(y==20){opcion_elegida=3;}
                    if(y==27){opcion_elegida=0;}
                    on=false;
                }
            break;

        default:

            break;
        }

        //Dibujo cursor
        rlutil::locate(x,y);
        cout<<char(16);
    }

    return opcion_elegida;
}

void MenuSeleccion(Recruiter usuario,int &IdBusquedaActiva){

    bool on=true;
    int op;

    while(on){


        op = InterfazSeleccion();
        switch(op){

        case 1:
            {
                system("cls");
                MenuBusqueda(usuario,IdBusquedaActiva);
            }
            break;

        case 2:
            {
                system("cls");
                MenuSelecPersonal(usuario, IdBusquedaActiva);
            }
            break;
            //304568215 y 27548692
        case 3:
            {
                rlutil::cls();
                ArchivoElegidos archelegidos;
                int tam = archelegidos.getCantidad();
                if(tam>0){

                    MostrarElegidos(usuario.getID());
                }
                else{
                    string msj = "No Hay Busquedas finalizadas";
                    Alerta(msj,true,true);
                }
            }
            break;

        case 0:
            {
                on=false;
            }
            break;

        default:

            break;
        }
    }

}

///////////////////////**** MENU DE LOGIN (ID/PASSWORD) **** ///////////////////////////////////
void MenuLogin(int &IdBusquedaActiva){

    bool on=true;
    char op;
    int _id;
    string pass;
    ArchivoRecruiter archivo;
    string msj;
    while(on){
        bool logeado=false;

        if(!logeado){
        msj="Ingrese ID:       ";
        Alerta(msj,false,true);
        rlutil::locate(ANCHO_VENTANA/2 + msj.length()/2- 5,15);
        cin>>_id;
        msj="Ingrese password:            ";
        Alerta(msj,false,true);
        rlutil::locate(ANCHO_VENTANA/2 + msj.length()/2- 10,15);
        cin>>pass;

        logeado = archivo.loginExitoso(_id,pass);
        }
        //Si el login es exitoso mandar al menu de seleccion
        //Sino pregunta si desea reintentar, si dice que no, mandar al menu ppal

        if(logeado){
            Recruiter usuario;
            ArchivoRecruiter archivoUsuario;
            int pos=archivoUsuario.buscar(_id);
            usuario = archivoUsuario.leer(pos);
            system("cls");
            string notificacion = "Bienvenido, " + usuario.getNombre();
            Alerta(notificacion,true,true);

            //Entra al menu de seleccion
            MenuSeleccion(usuario,IdBusquedaActiva);
            on=false;
        }
        else{
            msj="ID o password incorrectos, reintentar ? S/N:  ";
            Alerta(msj,false,true);
            rlutil::locate(ANCHO_VENTANA/2 + msj.length()/2- 1,15);
            cin>>op;
            if(toupper(op)!='S'){
                on=false;
            }
        }
    }

}

void MenuPpal(){

    bool on=true;

    while(on){
    int IdBusquedaActiva=-1;
    ArchivoFavoritos archivoF;
    archivoF.vaciar();
    system("cls");

    int op = PruebaLogin();
        switch(op){

        case 1: //LOGIN
            {
                system("cls");
                MenuLogin(IdBusquedaActiva);
            }
            break;

        case 0: //SALIR
            {
                string msj = "Adios :)";
                Alerta(msj,true,true);
                rlutil::cls();
                on=false;
            }
            break;

        default:
            //SOLO SALE CON 0
            break;
        }

    }

}



void Logo(int posicionX, int posicionY){

    int logo[17][25]=
    {{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0},
    {1,0,0,0,0,0,1,1,1,0,0,0,0,0,1,0,0,0,1,1,1,0,1,1,1},
    {1,0,0,0,0,1,1,1,1,1,0,0,0,0,1,0,0,0,1,0,1,0,1,0,1},
    {1,0,0,0,1,1,1,1,2,1,1,0,0,0,1,0,0,0,1,0,1,0,1,0,0},
    {1,0,0,0,1,1,1,1,1,2,1,0,0,0,1,0,0,0,1,0,1,0,1,0,0},
    {1,0,0,0,1,1,1,1,1,1,1,0,0,0,1,0,0,0,1,1,1,0,1,0,0},
    {1,0,0,0,0,1,1,1,1,1,0,0,0,0,1,0,0,0,1,1,0,0,1,0,0},
    {1,0,0,0,0,0,1,1,1,0,0,0,0,0,1,0,0,0,1,1,0,0,1,0,0},
    {1,0,0,0,0,0,0,3,0,0,0,0,0,0,1,0,0,0,1,0,1,0,1,0,0},
    {1,0,0,0,0,0,0,3,0,0,0,0,0,0,1,0,0,0,1,0,1,0,1,0,0},
    {1,0,0,0,0,0,0,3,0,0,0,0,0,0,1,0,0,0,1,0,1,0,1,0,0},
    {1,0,0,0,0,0,0,3,0,0,0,0,0,0,1,0,0,0,1,0,1,0,1,0,1},
    {1,0,0,0,0,0,0,3,0,0,0,0,0,0,1,0,0,0,1,0,1,0,1,1,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0}};

    for(int i=0; i<17; i++){
            int y = i+posicionY;
        for(int j=0; j<25; j++){
            int x = j+posicionX;
            rlutil::locate(x,y);

            switch(logo[i][j]){

            case 1:
                {
                    rlutil::setColor(rlutil::LIGHTCYAN);
                    cout<<char(219);
                }
                break;

            case 2:
                {
                    rlutil::setColor(rlutil::WHITE);
                    cout<<char(219);
                }
                break;

            case 3:
                {
                    rlutil::setColor(rlutil::BROWN);
                    cout<<char(219);
                }
                break;

            default:
                {
                    cout<<" ";
                }
                break;
            }
        }
    }

}

void PantallaInicio(){

Logo(ANCHO_VENTANA/2 - 12,ALTO_VENTANA/2 - 9);
    rlutil::locate(50,27);
    rlutil::hidecursor();
    cout<<"Cargando.."<<endl;

    rlutil::setColor(rlutil::LIGHTCYAN);
    for(int i=0; i<=ANCHO_VENTANA; i++){
        Sleep(20);
        rlutil::locate(i,28);
        cout<<char(219);
    }
    cout<<endl;
    system("pause");

}

int PruebaLogin(){
    int opcion_elegida=0;
    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::cls();
    rlutil::hidecursor();
    string msj ="BIENVENIDO A RECRUIT CENTER :)";

    rlutil::setColor(rlutil::LIGHTBLUE);
    /////////////////////////
    DivisorHorizontal(1,'=');
    DivisorHorizontal(2,'|');
    DivisorHorizontal(3,'=');
    /////////////////////////
    DivisorHorizontal(28,'=');
    DivisorHorizontal(29,'|');
    DivisorHorizontal(30,'=');
    /////////////////////////

    cartelPixel((ANCHO_VENTANA/2-msj.size()/2 -2),7,34,4);
    rlutil::locate(ANCHO_VENTANA/2- msj.size()/2,9);
    cout<<msj<<endl;
    Logo(3,8);
    Logo(90,8);
    rlutil::setColor(rlutil::LIGHTBLUE);
    rlutil::locate(55,18);
    cout<<"LOGIN"<<endl;
    cartelPixel(53,16,8,4);


    rlutil::locate(55,24);
    cout<<"SALIR"<<endl;
    cartelPixel(53,22,8,4);

    rlutil::locate(1,1);


   int tecla=0;
   int y=18;
   int x=51;
   rlutil::hidecursor();
   rlutil::locate(51,18);
   cout<<char(16);
   while(tecla!=1){

        tecla=rlutil::getkey();

        switch(tecla){

        case 15: //DOWN
            {
                rlutil::locate(x,y);
                //Borra caracter anterior
                cout<<" ";
                y+=24-18;
                if(y>24){
                    y=24;
                }
            }

            break;

        case 14: //UP
            {
                rlutil::locate(x,y);
                //Borra caracter anterior
                cout<<" ";
                y-=24-18;
                if(y<18){
                    y=18;
                }
            }
            break;

        case 1: //ENTER
            {
                //La opcion de login esta en 18 en y
                if(y==18){
                    opcion_elegida = 1;
                }
                else{opcion_elegida= 0;}
            }
            break;

        default:

            break;
        }

        rlutil::locate(x,y);
        cout<<char(16);

   }

    //UP :   14
    //DOWN : 15
    //LEFT : 16
    //RIGHT: 17
    //ENTER 1

    return opcion_elegida;
}





