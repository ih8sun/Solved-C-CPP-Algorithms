#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <string>
#include <fstream>
#include "Episodio.h"
#include "Pelicula.h"
#include <vector>
#include "wconio.h"
//#include "resena.h"
#define TamPrincipal 100
using namespace std;

void menu(){
    clrscr();
    textbackground(5);
    cout<<"\n\n\t\t[ MANEJO DE CINE -> CINEPOLIS MEX]\n\n";
    cout<<"[1]. Cargar Archivo de datos desde Repositorio\n";
    cout<<"[2]. Mostrar Todas las Peliculas\n";
    cout<<"[3]. Mostrar todas las Series\n";
    cout<<"[4]. Mostrar todos los Videos\n";
    cout<<"[5]. Mostrar una serie / Pelicula\n";
    cout<<"[6]. Calificar un video / modificar Calificacion\n";
    cout<<"[7]. Agregar una nueva Serie/Pelicula\n";
    cout<<"[0]. Salir\n";
    cout<<"\n[?]. Ingresa opcion : ";
    fflush(stdin);

    textbackground(0);
}

string operator + (string ,string );
void mostrarTodasPeliculas(Video* [],int);
void mostrarTodasSeries(Video* [],int );
void mostrarTodosVideos(Video* [],int);
void buscarSeriePelicula(Video* [],int );
void modificarSerieOpelicula(Video * [],int );
void guardarNuevoArchivo(Video *[],int ,fstream &);
void modificarEspacios(string &);
void agregarSerieOPelicula(Video * [],int &);
template <typename T>
T mayor(T x, T y){

    if(x == y){
        cout<<"\n\n\t [ Equivalen lo Mismo ]\n\n";
        return x;
    }

    if(x > y){

        return x;
    }else{
        return y;
    }
}



int main() {
    
    //! Variables que manejan archivos
    fstream repositorio;
    bool salir = false;
    srand (time(NULL));

    //Variables que ayudaran a Cargar clases;
    string nombre,gen,director,nombreSerie,duracion,formato;
    int id,temporada,numEpisodio,opcion,calif;
    double estrella,califMin,califMax;


    //Cargar Datos..
    bool cargoDatos = false;
    char tipoVideo;
    bool modifico = true;

    //Creacion de Clases usando herencia y Polimorfismo
    Video *nuevoVideo[TamPrincipal];
    int contador = 0;


    int opc;
    do{
        menu();
        cin>>opc;
        switch (opc) {
            case 1:
                if(!cargoDatos) {
                    cargoDatos = true;
                    repositorio.open("repositorio.txt");

                    while (repositorio >> tipoVideo) {
                        
                        if (tipoVideo == 'p') {
                            repositorio >> id >> nombre >> gen >> formato >> duracion >> estrella >> calif >> director;
                            nuevoVideo[contador] = new Pelicula('p', id, nombre, gen, formato, duracion, estrella,
                                                                calif, director);
                            
                            Pelicula *aux;
                            aux = new Pelicula('p',id,nombre,gen,formato,duracion,estrella,calif,director);
                            aux->guardarBinario();
                            contador++;
                        } else {
                            repositorio >> id >> nombre >> gen >> formato >> duracion >> estrella >> calif
                                        >> nombreSerie >> numEpisodio >> temporada;
                            nuevoVideo[contador] = new Episodio('s', id, nombre, gen, formato, duracion, estrella,
                                                                calif, nombreSerie, numEpisodio, temporada);
                            
                            
                            Episodio *aux2;
                            aux2 = new Episodio('s',id,nombre,gen,formato,
                            duracion,estrella,calif,nombreSerie,numEpisodio,temporada);
                            
                            aux2->guardarBinarioS();
                            contador++;
                        
                        
                        }
                    }
                    
                    textbackground(5);
                    cout<<"\n\n\t\t[ REGISTROS CARGADOS CORRECTAMENTE ]\n\n";
                    textbackground(0);
                }else{
                    cout<<"\n\n\t\t[ YA SE CARGARON LOS DATOS AL PROGRAMA ]\n\n";
                }
                system("pause");
                break;
            case 2:
                if(cargoDatos){
                    mostrarTodasPeliculas(nuevoVideo,contador);
                }else{
                    cout<<"\n\n\t\t[ ANTES DEBE CARGAR LOS DATOS ]\n\n";
                    system("pause");
                }
                break;
            case 3:
                if(cargoDatos){
                    mostrarTodasSeries(nuevoVideo,contador);
                }else{
                    cout<<"\n\n\t\t[ ANTES DEBE CARGAR LOS DATOS ]\n\n";
                    system("pause");
                }
                break;
            case 4:
                mostrarTodosVideos(nuevoVideo,contador);
                system("pause");
                break;
            case 5:
                buscarSeriePelicula(nuevoVideo,contador);
                system("pause");
                break;
            case 6:
                modificarSerieOpelicula(nuevoVideo,contador);
                modifico = true;
                system("pause");
                break;

            case 7:
                agregarSerieOPelicula(nuevoVideo,contador);
                modifico = true;
                break;

            case 0:
                if(cargoDatos) {
                    if (modifico) {
                        repositorio.close();
                        system("pause");
                        if(remove("repositorio.txt") != 0){
                            perror("Error deleting file");
                        }else{
                            
                            clrscr();
                            puts("\n\n\t\tMODIFICANDO ARCHIVO\n\n");
                            espera(2);
                        }
                        repositorio.open("repositorio.txt",ios::out);
                        repositorio.close();
                        guardarNuevoArchivo(nuevoVideo,contador,repositorio);

                    } else {
                        cout << "\n\n\t\t[ GRACIAS POR USAR EL PROGRAMA ]\n\n";
                    }
                }else{
                    cout<<"\n\n\t\t[ ADIOS AMIGO ]\n\n";
                }
                salir = true;
                break;
        }


    }while(!salir);


    return 0;
}


void mostrarTodasPeliculas(Video* nuevoVideo[],int tamMax){

    int opc;
    double estrellas;
    string genero;
    bool entro = false;
    int i,j;


    try{
        cout<<"\n\n\t\t[ BUSQUEDA DE ALGUNA PELICULA ]\n\n";
        cout<<"[1]. Estrellas\n[2]. Genero\n[3]. Mostrar Todas\n";
        cout<<"Ingresa una opcion : ";
        cin>>opc;

        switch (opc) {
            case 1:
                cout<<"[ BUSQUEDA POR ESTRELLAS ]";
                cout<<"\n-> Ingresa la calificacion minima de peliculas a mostrar : ";
                cin>>estrellas;
                cout<<"--------------------------------------------------------------\n";
                for(i = 0; i < tamMax; i++){
                    if(nuevoVideo[i]->getEstrellas() >= estrellas && nuevoVideo[i]->getTipo() == 'p'){

                        nuevoVideo[i]->mostrar();
                        cout<<endl;
                        cout<<"--------------------------------------------------------------\n";
                        entro = true;
                    }

                }

                if(!entro){
                    cout<<"\n\n[ No se hallo ninguna pelicula con esa calificacion :( ]\n";
                }
                break;

            case 2:
                cout<<"[ BUSQUEDA POR GENERO ]";
                cout<<"\n-> Ingresa el tipo de genero de las pelicula a buscar : ";
                fflush(stdin);
                getline(cin,genero);
                cout<<"--------------------------------------------------------------\n";
                for(i = 0; i < tamMax; i++){
                    if((nuevoVideo[i]->getGenero().compare(genero) == 0) && nuevoVideo[i]->getTipo() == 'p'){

                        nuevoVideo[i]->mostrar();
                        cout<<endl;
                        cout<<"--------------------------------------------------------------\n";
                        entro = true;
                    }

                }

                if(!entro){
                    cout<<"\n\n[ No se hallo ninguna pelicula con esse genero :( ]\n";
                }
                break;
            case 3:

                cout<<"--------------------------------------------------------------\n";
                for(i = 0; i < tamMax; i++){
                    if(nuevoVideo[i]->getTipo() == 'p'){

                        nuevoVideo[i]->mostrar();
                        cout<<endl;
                        cout<<"--------------------------------------------------------------\n";
                        entro = true;
                    }

                }
                if(!entro){
                    cout<<"\n\n[ No se hallo ninguna pelicula registrada :( ]\n";
                }

                break;
            default:
                throw(opc);
                break;
        }

    }catch (int falseOPC){
        cout<<"Se requiere ingresar una opcion correcta...\n\n ";
    }

    system("pause");
}

void mostrarTodasSeries(Video* nuevoVideo[],int tamMax){

    int opc;
    double estrellas;
    string genero;
    bool entro = false;
    int i,j;


    try{
        cout<<"\n\n\t\t[ BUSQUEDA DE ALGUNA SERIE ]\n\n";
        cout<<"[1]. Estrellas\n[2]. Genero\n[3]. Mostrar Todas\n";
        cout<<"Ingresa una opcion : ";
        cin>>opc;

        switch (opc) {
            case 1:
                cout<<"[ BUSQUEDA POR ESTRELLAS ]";
                cout<<"\n-> Ingresa la calificacion minima de series a mostrar : ";
                cin>>estrellas;
                cout<<"--------------------------------------------------------------\n";
                for(i = 0; i < tamMax; i++){
                    if(nuevoVideo[i]->getEstrellas() >= estrellas && nuevoVideo[i]->getTipo() == 's'){

                        nuevoVideo[i]->mostrar();
                        cout<<"----------------------------------------------------------";
                        cout<<endl;
                        entro = true;
                    }
                }

                if(!entro){
                    cout<<"\n\n[ No se hallo ninguna series con esa calificacion :( ]\n";
                }
                break;

            case 2:
                cout<<"[ BUSQUEDA POR GENERO ]";
                cout<<"\n-> Ingresa el tipo de genero de las series a buscar : ";
                fflush(stdin);
                getline(cin,genero);
                modificarEspacios(genero);
                cout<<"--------------------------------------------------------------\n";
                for(i = 0; i < tamMax; i++){
                    if((nuevoVideo[i]->getGenero().compare(genero) == 0) && nuevoVideo[i]->getTipo() == 's'){

                        nuevoVideo[i]->mostrar();
                        cout<<"----------------------------------------------------------";
                        cout<<endl;
                        entro = true;
                    }
                }
                if(!entro){
                    cout<<"\n\n[ No se hallo ninguna pelicula con esse genero :( ]\n";
                }
                break;
            case 3:
                cout<<"--------------------------------------------------------------\n";
                for(i = 0; i < tamMax; i++){
                    if(nuevoVideo[i]->getTipo() == 's'){

                        nuevoVideo[i]->mostrar();
                        cout<<"----------------------------------------------------------";
                        cout<<endl;
                        entro = true;
                    }
                }
                if(!entro){
                    cout<<"\n\n[ No se hallo ninguna pelicula registrada :( ]\n";
                }

                break;
            default:
                throw(opc);
                break;
        }
    }catch (int falseOPC){
        cout<<"Se requiere ingresar una opcion correcta...\n\n ";
    }
    system("pause");
}

void mostrarTodosVideos(Video* nuevoVideo[],int tamMax){

    int i;

    if(tamMax != 0){

        cout<<"--------------------------------------------------------------\n";
        for(i = 0; i < tamMax; i++){

            nuevoVideo[i]->mostrar();
            cout<<"----------------------------------------------------------";
            cout<<endl;

        }
    }else{
        cout<<"\n\n\t\t[ Aun no hay ingreso de Datos ] \n\n";
    }

}

void buscarSeriePelicula(Video* nuevoVideo[],int tamMax){

    string codigoSP;
    int i,j,opc;
    int temporada = 0;
    if(tamMax != 0){
        cout<<"\n\n\t\t[ BUSCAR ALGUNA SERIE O PELICULA ] \n\n";
        cout<<"[1]. Serie\n[2]. Pelicula\n[?]. Ingresa opcion : ";
        cin>>opc;
        switch (opc) {
            case 1:
                cout<<"\nIngresa Nombre de Serie a Buscar : ";
                fflush(stdin);
                getline(cin,codigoSP);
                modificarEspacios(codigoSP);

                for(i = 0; i < tamMax; i++){
                    if(nuevoVideo[i]->getTipo() == 's'){
                        Episodio *temporal;
                        temporal = (Episodio *) nuevoVideo[i];

                        if(temporal->getNombreSerie().compare(codigoSP) == 0){

                            cout<<"\n[ SE ENCONTRO LA SERIE A BUSCAR ]\n";
                            cout<<"Nombre de Serie : "<<temporal->getNombreSerie()<<endl;
                            cout<<"Genero : "<<temporal->getGenero()<<endl;
                            cout<<"Formato : "<<temporal->getFormato()<<endl;
                            for(j = 0; j < tamMax; j++){
                                if(nuevoVideo[j]->getTipo() == 's'){
                                    Episodio *aux;
                                    aux = (Episodio *) nuevoVideo[j];
                                    if(aux->getNombreSerie().compare(codigoSP)){
                                        if(temporada < aux->getTemporada() ){
                                            temporada = aux->getTemporada();
                                        }
                                    }
                                }
                            }
                            cout<<"Temporadas : "<<temporada<<endl<<endl;
                            break;
                        }
                    }
                }

                break;

            case 2:
                cout<<"\nIngresa Nombre de Pelicula a Buscar : ";
                fflush(stdin);
                getline(cin,codigoSP);
                modificarEspacios(codigoSP);

                for(i = 0; i < tamMax; i++){
                    if(nuevoVideo[i]->getTipo() == 'p'){
                        Pelicula *nuevoTemp;
                        nuevoTemp = (Pelicula *)nuevoVideo[i];
                        if(nuevoTemp->getNombre().compare(codigoSP) == 0){
                            nuevoTemp->mostrar();
                            break;
                        }
                    }
                }

                break;
            default:
                cout<<"\n\n\t\t[ Se necesita una opcion correcta ]\n\n";
                break;
        }
    }else{
        cout<<"\n\n\t\t[ Aun no se ingresan datos ]\n\n";
    }

    system("pause");

}

void guardarNuevoArchivo(Video * nuevoVideo[],int tamMax,fstream &repositorio){
    
    Pelicula *aux;
    
    Episodio *temp;
    if(tamMax != 0) {
        remove("SoloSeries.bin");
        remove("SoloPeliculas.bin");

        
        repositorio.open("repositorio.txt", ios::app);

        for (int i = 0; i < tamMax; i++) {
            

            if (nuevoVideo[i]->getTipo() == 'p') {
                aux = (Pelicula *) nuevoVideo[i];
                repositorio << aux->getTipo()<< " "<< aux->getId() << " " << aux->getNombre() << " " << aux->getGenero() << " "
                            << aux->getFormato() << " " << aux->getDuracion() << " " << aux->getEstrellas()<< " " << aux->getCalif() << " "
                            << aux->getDirector();
                if (i != tamMax - 1) {
                    repositorio << endl;
                }

                aux->guardarBinario();
            } else {
                temp = (Episodio *) nuevoVideo[i];
                repositorio << temp->getTipo() << " "<< temp->getId()<<" " << temp->getNombre() << " " << temp->getGenero() << " "
                            << temp->getFormato() << " " << temp->getDuracion() << " " << temp->getEstrellas() << " " << temp->getCalif() <<" "
                            << temp->getNombreSerie() << " " << temp->getNumEpisodio() << " " << temp->getTemporada();
                if (i != tamMax - 1) {
                    repositorio << endl;
                }

                temp->guardarBinarioS();
            }
        }
    }else{
        cout<<"\n\n\t\t[ Aun No Hay Registros En El Sistema ] \n\n";
    }

}

string operator + (string x,string y){

    return x+y;
}

void modificarSerieOpelicula(Video* nuevoVideo[],int tamMax){
    
    string codigoSP;
    string strVar;
    int itrVar;
    double dblVar;
    bool entro = false;
    int opc,i;

    if(tamMax != 0){
        cout<<"\n\n\t\t[ MODIFICACION DE SERIE/PELICULA ]\n\n";
        cout<<"[1]. Serie\n[2]. Pelicula\n[?]. Ingrese opcion : ";
        cin>>opc;
        switch (opc) {
            case 1:
                cout<<"\nIngresa ID de Serie a Modificar : ";
                cin>>itrVar;

                for(i = 0; i < tamMax; i++){
                    if(nuevoVideo[i]->getTipo() == 's'){
                        Episodio *temporal;
                        temporal = (Episodio *) nuevoVideo[i];

                        if(temporal->getId() == itrVar){

                            cout<<"\n[ SE ENCONTRO LA SERIE A MODIFICAR ]\n";
                            entro = true;
                            temporal->setTipo('s');
                            cout<<"Nuevo Nombre de Serie : ";
                            fflush(stdin);
                            getline(cin,strVar);
                            modificarEspacios(strVar);
                            temporal->setNombreSerie(strVar);

                            cout<<"Nuevo ID : ";
                            cin>>itrVar;
                            temporal->setId(itrVar);

                            cout<<"Nuevo numero Temporada : ";
                            cin>>itrVar;
                            temporal->setTemporada(itrVar);


                            cout<<"Nuevo Nombre de Episodio : ";
                            fflush(stdin);
                            getline(cin,strVar);
                            modificarEspacios(strVar);
                            temporal->setNombre(strVar);

                            cout<<"Nuevo Genero de Episodio : ";
                            fflush(stdin);
                            getline(cin,strVar);
                            temporal->setGenero(strVar);

                            cout<<"Nuevo Tipo de Formato : ";
                            fflush(stdin);
                            getline(cin,strVar);
                            temporal->setFormato(strVar);

                            cout<<"Nuevo Duracion de Capitulo\n";
                            cout<<"DuracionEjemplo-> 00:00:00\nIngresa : ";
                            fflush(stdin);
                            getline(cin,strVar);
                            temporal->setDuracion(strVar);

                            cout<<"Nuevas Calificacion de Episodio : ";
                            fflush(stdin);
                            cin>>itrVar;
                            temporal->setCalif(itrVar);

                            cout<<"Nuevas Estrellas de Episodio : ";
                            fflush(stdin);
                            cin>>dblVar;
                            temporal->setEstrellas(dblVar);

                            nuevoVideo[i] = temporal;
                            entro = true;
                            cout<<"\n\n\t\tSERIE MODIFICADA CON EXITO\n\n";
                            break;
                        }

                    }
                }

                if(!entro){
                    cout<<"\n\n\t\t[ No se encontro ninguna serie con ese codigo ]\n\n";
                }
                break;


            case 2:
                cout<<"\nIngresa Nombre de Pelicula a Modificar : ";
                fflush(stdin);
                getline(cin,codigoSP);
                modificarEspacios(codigoSP);

                for(i = 0; i < tamMax; i++){
                    if(nuevoVideo[i]->getTipo() == 'p'){
                        Pelicula *temporal2;
                        temporal2 = (Pelicula *) nuevoVideo[i];
                        if(temporal2->getNombre().compare(codigoSP) == 0){

                            cout<<"\n[ SE ENCONTRO LA PELICULA A MODIFICAR ]\n";
                            cout<<"Nombre Nueva Pelicula : ";
                            fflush(stdin);
                            getline(cin,strVar);
                            modificarEspacios(strVar);
                            temporal2->setNombre(strVar);

                            cout<<"Nuevo ID : ";
                            cin>>itrVar;
                            temporal2->setId(itrVar);

                            cout<<"Nombre Nuevo Genero : ";
                            fflush(stdin);
                            getline(cin,strVar);
                            temporal2->setGenero(strVar);

                            cout<<"Nuevo Tipo de Formato : ";
                            fflush(stdin);
                            getline(cin,strVar);
                            temporal2->setFormato(strVar);

                            cout<<"Nuevo tiempo Duracion : ";
                            cout<<"DuracionEjemplo-> 00:00:00\nIngresa : ";
                            fflush(stdin);
                            getline(cin,strVar);
                            temporal2->setDuracion(strVar);

                            cout<<"Nuevo Director de Pelicula : ";
                            fflush(stdin);
                            cin>>strVar;
                            modificarEspacios(strVar);
                            temporal2->setDirector(strVar);

                            cout<<"Nuevas Estrellas de Pelicula : ";
                            fflush(stdin);
                            cin>>dblVar;
                            temporal2->setEstrellas(dblVar);

                            cout<<"Nuevas Calificacion de Pelicula : ";
                            fflush(stdin);
                            cin>>itrVar;
                            temporal2->setCalif(itrVar);


                            entro = true;
                            cout<<"\n\n\t\tPELICULA MODIFICADA CON EXITO\n\n";
                            nuevoVideo[i] = temporal2;
                            break;

                        }
                    }
                }

                if(!entro){
                    cout<<"\n\n\t\t[ No se encontro ninguna pelicula con ese nombre ]\n\n";
                }


                break;
            default:

                cout<<"\n\n\t\t[ Se Debio Ingresar un dato valido ]\n\n";
                system("pause");
                break;
        }
    }

}

void modificarEspacios(string &cad){

    int i = 0;

    for(i = 0 ; i < cad.length(); i++){
        
        if(isspace(cad[i])){
            cad[i] = '_';
        }

    }
}

void agregarSerieOPelicula(Video *nuevoVideo[],int &tamMax){

    string codigoSP;
    string strVar;
    int itrVar;
    double dblVar;
    bool entro = false;
    int opc,i;

        //temporal = (Episodio *) nuevoVideo[i];

    if(tamMax != 0){
        cout<<"\n\n\t\t[ INGRESO DE SERIE/PELICULA ]\n\n";
        cout<<"[1]. Serie\n[2]. Pelicula\n\n[?]. Ingrese opcion : ";
        cin>>opc;
        switch (opc) {
            case 1:

                Episodio *temporal;
                temporal = new Episodio();
                
                cout<<"\n";
                entro = true;
                temporal->setTipo('s');
                cout<<"Nuevo Nombre de Serie : ";

                fflush(stdin);
                getline(cin,strVar);
                modificarEspacios(strVar);
                temporal->setNombreSerie(strVar);

                cout<<"Ingresa ID : ";
                cin>>itrVar;
                temporal->setId(itrVar);

                cout<<"Ingresa numero Temporada : ";
                cin>>itrVar;
                temporal->setTemporada(itrVar);

                cout<<"Ingresa numero de Episodio : ";
                cin>>itrVar;
                temporal->setTemporada(itrVar);


                cout<<"Ingresa Nombre de Episodio : ";
                fflush(stdin);
                getline(cin,strVar);
                modificarEspacios(strVar);
                temporal->setNombre(strVar);

                cout<<"Ingresa Genero de Episodio : ";
                fflush(stdin);
                getline(cin,strVar);
                temporal->setGenero(strVar);

                cout<<"Ingresa Tipo de Formato : ";
                fflush(stdin);
                getline(cin,strVar);
                temporal->setFormato(strVar);

                cout<<"Ingresa Duracion de Capitulo\n";
                cout<<"DuracionEjemplo-> 00:00:00\nIngresa : ";
                fflush(stdin);
                getline(cin,strVar);
                temporal->setDuracion(strVar);

                cout<<"Ingresa Cuantas Personas Calificaron el episodio : ";
                fflush(stdin);
                cin>>itrVar;
                temporal->setCalif(itrVar);

                cout<<"Ingresa Estrellas promedio de Episodio [ 1- 5 ] : ";
                fflush(stdin);
                cin>>dblVar;
                temporal->setEstrellas(dblVar);

                nuevoVideo[tamMax] = temporal;
                entro = true;
                cout<<"\n\n\t\tSERIE AGREGADA CON EXITO\n\n";
                        
                tamMax++;

                break;


            case 2:


                Pelicula *temporal2;
                temporal2 = new Pelicula();

                temporal2->setTipo('p');

                cout<<"\n";
                cout<<"Nombre Nueva Pelicula : ";
                fflush(stdin);
                getline(cin,strVar);
                modificarEspacios(strVar);
                temporal2->setNombre(strVar);

                cout<<"Nuevo ID : ";
                cin>>itrVar;
                temporal2->setId(itrVar);

                cout<<"Nombre Nuevo Genero : ";
                fflush(stdin);
                getline(cin,strVar);
                temporal2->setGenero(strVar);

                cout<<"Nuevo Tipo de Formato : ";
                fflush(stdin);
                getline(cin,strVar);
                temporal2->setFormato(strVar);

                cout<<"Nuevo tiempo Duracion : ";
                cout<<"DuracionEjemplo-> 00:00:00\nIngresa : ";
                fflush(stdin);
                getline(cin,strVar);
                temporal2->setDuracion(strVar);

                cout<<"Nuevo Director de Pelicula : ";
                fflush(stdin);
                cin>>strVar;
                modificarEspacios(strVar);
                temporal2->setDirector(strVar);


                cout<<"Ingres Cuantas Personas votaron esta pelicula : ";
                fflush(stdin);
                cin>>itrVar;
                temporal2->setCalif(itrVar);

                cout<<"Ingresa Estrellas Obtenidas [ 1 - 5 ] : ";
                fflush(stdin);
                cin>>dblVar;
                temporal2->setEstrellas(dblVar);

                entro = true;
                cout<<"\n\n\t\tPELICULA MODIFICADA CON EXITO\n\n";
                nuevoVideo[tamMax] = temporal2;
                
                tamMax++;
                system("pause");

                break;
                
            default:

                cout<<"\n\n\t\t[ Se Debio Ingresar un dato valido ]\n\n";
                system("pause");
                break;
        }
    }else{
        cout<<"\n\n\t[ DEBE CARGAR O CREAR EL ARCHIVO ]\n\n";
        system("pause");
    }
}