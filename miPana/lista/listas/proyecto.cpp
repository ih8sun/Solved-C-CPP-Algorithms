#include <iostream> //Creamos nuestras Librerias para desarrollar el programa
#include <stdlib.h>// encargada de manejar consola de sistema, punteros etc
#include <string.h>// encargada de manejar tipos de cadena
#include <fstream>//Encargado de la creacion de archivos
#include <stdio.h>//Encargado de fluijo de salida y entrada con mas exactitud

using namespace std;

struct CursoE{// Estrcutura que almacenara los cursos de estudiates

    string nombreCurso;
    string codCurso;
    int notas[5];
};

struct CursoP{//Estrucctura que almacenara cursos de Profesores

    string nombreCurso;
    string codCurso; 
    
};

struct Estudiante{//Estrucctura que registrara los estudiantes

    string nombreAlum;//nombre
    string codAlum;//codigo
    int edad;//edad
    int CCRE;//CANTIDAD DE CURSOS REGISTRADOS
    CursoE *nuevoCursoAlum;//Puntero hacia la estructura Curso Estudiante


    void inicializarCursoEst(){//Asignamos dinamicamente memoria para crear el array
        nuevoCursoAlum = new CursoE[CCRE];//de cursos
    }
};

struct Profesor{

    string nombreProfe;//EsTRUCTURA Que registrara los profesores,nombre
    string codProfe;//codigo
    int edad;//edad
    int CCRP;//CANTIDAD DE CURSOS REGISTRADOS 
    CursoP *nuevoCursoProfe;//Puntero hacia la estructura Curso Estudiante

    void inicializarCursoProf(){//Inicializamos y asignanmos memoria para array CursoP
        nuevoCursoProfe = new CursoP[CCRP];
    }
    
};


struct Colegio{//lista final encargada de Almacenar las otras estructuras 
//Y realizar la estructura de datos dinamICA
    int eleccion;//SI ES 0 == Profesor, SI ES 1 == ALUMNO, si es diferente no ingresa
    Estudiante estudiante;//Estrutuctura de Estudiante
    Profesor profesor;//eSTRUCTURA DE pROFESORES
	Colegio* siguiente;//Apuntador a la siguiente pos de memoria

    void eLe(){;//SI NO ELIJE BIEN OPCION NO INGRESARA 
        eleccion = 3;
    }

} *primero, *ultimo;//PRIEMR ELEMENTO DE LA LISTA Y ULTIMO


//PROTOTIPO DE FUNCIONES
void insertarNodo(int x);
void desplegarEstudiantes();
void desplegarProfesor();
void buscarCursoEstudiante();
void buscarCursoProfesor();
void EstudiantesAprobados();
void GuardarRegistrosEstudiantes(ofstream &);
void GuardarRegistrosProfesores(ofstream &);
void menu(){//MENU ENCARGADO DE BRINDAR OPCIONES
    system("cls");
    cout<<"\n\n\t\t[ MENU PRINCIPAL DE REGISTROS ]\n\n";
    cout<<"[1]. Registrar Alumno\n";
    cout<<"[2]. Registrar Profesor\n";
    cout<<"[3]. Mostrar Todos los Estudiantes Registrados\n";
    cout<<"[4]. Mostrar Todos los Profesores Registrados\n";
    cout<<"[5]. Buscar Cursos - Estudiantes\n";
    cout<<"[6]. Buscar Cursos - Profesores\n";
    cout<<"[7]. Listar Estudiantes \n";
    cout<<"[8]. Salir\n";
    cout<<"\n[-]. Ingresa opcion : ";
}


int main()
{
    //VARIABLES ENCARGADAS DE MENU 
    bool salir = false;
    int opc,x;

    //VARIABLES ENCARGADAS DE CONTROLAR LOS TEXTOS
    
    bool creadoE = false,creadoP = false;
    ofstream miArchivoEstudiante;
    ofstream miArchivoProfesor;


    do{//HARA TODO ESTO PROCESO HASTA QUE..
        menu();
        cin>>opc;//RECOGEMOS OPCION
        switch (opc)
        {
        case 1://LLAMAMOS A LA FUNCION INSERTAR , PARA INSERTAR ESTUDIANTE
            insertarNodo(1);
            system("pause");
            creadoE = true;//INDICAMOS QUE YA SE REGISTRO ESTUDIANTE
            break;
        
        case 2://LLAMAMOS A LA FUNCION INSERTAR , PARA INSERTAR PROFESOR
            insertarNodo(2);
            system("pause");
            creadoP = true;//INDICAMOS QUE YA SE REGISTRO PROFESOR
            break;
        
        case 3://DESPLEGAMOS ESTUDIANTES
            desplegarEstudiantes();
            break;
        
        case 4://DESPLEGAMOS PROFESOR
            desplegarProfesor();
            break;

        case 5://BUSCAMOS ALGUN ESTUDIANTE POR CURSO
            buscarCursoEstudiante();
            break;
        
        case 6://USCAMOS ALGUN ESTUDIANTE POR PROFESOR
            buscarCursoProfesor();
            break;
        
        case 7://LISTADO DE ESTUDIANTES APROBADOS MAYOR A 61
            EstudiantesAprobados();
            break;

        case 8://OPCION DE SALIR
            if(creadoP){//SI CREADO ES VERDAD -> PROFESOR
            //LLAMARA A LA FUNCION GUARDAR REGISTROS UY GUARDAREMOS LOS DATOS
            miArchivoProfesor.open("RegistroProfesor.txt",ios::app);
            GuardarRegistrosProfesores(miArchivoProfesor);
            salir = true;
            }
            if(creadoE){//SI CREADO ES VERDAD -> ESTUDIANTE

            //LLAMARA A LA FUNCION GUARDAR REGISTROS UY GUARDAREMOS LOS DATOS
            miArchivoEstudiante.open("RegistroEstudiante.txt",ios::app);
            GuardarRegistrosEstudiantes(miArchivoEstudiante);
            salir = true;
            }
            salir = true;
            break;
        }

    }while(salir != true);//SALIR SEA DIFERENTE DE VERDAD

    return 0;
}


void insertarNodo(int x){

	Colegio* nuevo = new Colegio();//CREAMOS NUESTRA VARIABLE AUXILIAR NUEVO
	//cin >> nuevo->dato;

    nuevo->eLe();//INICIALIZAMOS VALOR,

    //VARIABLES PARA MANEJO DE LA ENTRADA DE DATOS
    int ponerNotas = 0,opc;
    int notas = 0;


    if(x == 1){//REGISTRA ALUMNO
        nuevo->eleccion = 1;//PASARA A 1 LA ELECION
        system("cls");//LIMPIARA PANTALLA

        cout<<"\n\n\t\t[ REGISTRO DE ESTUDIANTE ] \n\n";//REGISTRARA ESTUDIANTE
        cout<<"Ingresa nuevo nombre de Estudiante : ";//PEDIRA NOMBRE
        fflush(stdin);
        getline(cin,nuevo->estudiante.nombreAlum);

        cout<<"Ingresa nuevo codigo de Estudiante : ";//CODIGO
        fflush(stdin);
        getline(cin,nuevo->estudiante.codAlum);

        cout<<"Ingresa nueva edad de Estudiante : ";//EDAD
        cin>>nuevo->estudiante.edad;

        cout<<"Ingresa cantidad de cursos Registrados : ";
        cin>>nuevo->estudiante.CCRE;//CANTIDAD DE CURSO R

        nuevo->estudiante.inicializarCursoEst();//ASIGNARA MEMORIA PARA CURSOS R

        for(int i = 0; i < nuevo->estudiante.CCRE; i++){//HARA UN ARRAY DE ESOS CURSOS
            cout<<"\n\n\t[ CURSO -> "<<i<<" ] "<<endl;//PARA RECOPILAR SU INFORMACION
            cout<<"\nIngresa Nombre de Curso : ";
            fflush(stdin);//NOMBRE
            getline(cin,nuevo->estudiante.nuevoCursoAlum[i].nombreCurso);

            cout<<"Ingresa Codigo de Curso : ";
            fflush(stdin);//CODIGO
            getline(cin,nuevo->estudiante.nuevoCursoAlum[i].codCurso);
            
            cout<<"\nDesea Colocar notas ? \n[1]. Si\n[2]. No\n\n[-]. Ingresa opcion : ";
            cin>>opc;//SI ELIJE 1, PODRA LLENAR NOTAS, SINO SE GUARDARA EN 0
            if(opc == 1){

                cout<<"\nIngresa Nota de primer Parcial : ";
                cin>>nuevo->estudiante.nuevoCursoAlum[i].notas[0];
                notas += nuevo->estudiante.nuevoCursoAlum[i].notas[0];

                cout<<"\nIngresa Nota de segundo Parcial : ";
                cin>>nuevo->estudiante.nuevoCursoAlum[i].notas[1];
                notas += nuevo->estudiante.nuevoCursoAlum[i].notas[1];

                cout<<"\nIngresa Nota final de Actividades : ";
                cin>>nuevo->estudiante.nuevoCursoAlum[i].notas[2];
                notas += nuevo->estudiante.nuevoCursoAlum->notas[2];

                cout<<"\nIngresa Nota de examen final : ";
                cin>>nuevo->estudiante.nuevoCursoAlum[i].notas[3];
                notas += nuevo->estudiante.nuevoCursoAlum[i].notas[3];

                notas /= 4;

                nuevo->estudiante.nuevoCursoAlum[i].notas[4] = notas;

            }else{
                for(int j = 0; j < 5; j++){
                    nuevo->estudiante.nuevoCursoAlum[i].notas[j] = 0;
                }
            }

        }
        cout<<"\n\n\t\t[ SE AGREGARON LOS DATOS AL ESTUDIANTE ]\n\n";
    
    }else{
        system("cls");
        
        nuevo->eleccion = 0;//ELECCION 0 DE PROFESOR

        cout<<"\n\n\t\t[ REGISTRO DE PROFESOR ] \n\n";
        cout<<"Ingresa nuevo nombre de Profesor : ";
        fflush(stdin);//NOMBRE
        getline(cin,nuevo->profesor.nombreProfe);

        cout<<"Ingresa nuevo codigo de Profesor : ";
        fflush(stdin);//CODIGO
        getline(cin,nuevo->profesor.codProfe);

        cout<<"Ingresa nueva edad de Profesor : ";
        cin>>nuevo->profesor.edad;//EDAD

        cout<<"Ingresa cantidad de cursos Asignados : ";
        cin>>nuevo->profesor.CCRP;//CURSOS

        nuevo->profesor.inicializarCursoProf();//ASIGNAREMOS MEMORIA PARA CURSOS
        //DE PROFESOR
        for(int i = 0; i < nuevo->profesor.CCRP ; i++){//DE I HASTA CURSOS ASIGNADOS

            cout<<"\n\n\t[ CURSO -> "<<i<<" ] "<<endl;
            cout<<"\nIngresa Nombre de Curso : ";
            fflush(stdin);//NOMBRE
            getline(cin,nuevo->profesor.nuevoCursoProfe[i].nombreCurso);

            cout<<"Ingresa Codigo de Curso : ";
            fflush(stdin);//CODIGO
            getline(cin,nuevo->profesor.nuevoCursoProfe[i].codCurso);            
        }
        
        cout<<"\n\n\t\t[ SE AGREGARON LOS DATOS AL PROFESOR ]\n\n";
    }



	if(primero == NULL){//SI LA LISTA ESTA VACIA
		primero = nuevo;//NUEVO PASARA A SER PRIMERO
		primero->siguiente = NULL;//PRIMERO SIGUIENTE TENDRA NULL
		ultimo = nuevo;//Y EL ULTIMO TAMBIEN SERA EL NUEVO
	}else{
		ultimo->siguiente = nuevo;//SINO, EL SIGUIENTE SERA NUEVO
		nuevo->siguiente = NULL;//NUEVO SIGUIENTE SERA NULL
		ultimo = nuevo;//ULTIMO SERA NUEVO
	}

}

void desplegarEstudiantes(){

    Colegio *actual = new Colegio();//VARIABLE AUXILIAR
    actual = primero;//PASAREMOS VALORES DE TODA LA LISTA A ACTUAL

    if(primero != NULL){//SI LA LISTA NO ESTA VACIA ENTRA

        while(actual != NULL){//SI ACTUAL ES DIFERENET DE NULL, CONTINUARA
            
            if(actual->eleccion == 1){//IMPRIMIMOS ESTUDIANTE
                cout<<"\n\n\t\tDESPLEGANDO ESTUDIANTES...\n";
                cout<<"\nNombre de Alumno   ->  "<<actual->estudiante.nombreAlum;
                cout<<"\nCodigo de Alumno   ->  "<<actual->estudiante.codAlum;
                cout<<"\nEdad de Alumno     ->  "<<actual->estudiante.edad;
                cout<<"\nCursos Registrados ->  "<<actual->estudiante.CCRE;
                cout<<"\n\n\t[ DESPLEGANDO CURSOS ]\n\n";
                for(int i = 0; i < actual->estudiante.CCRE; i++){
                    cout<<"\nNombre de Curso    ->  "<<actual->estudiante.nuevoCursoAlum[i].nombreCurso;
                    cout<<"\nCodigo de Curso    ->  "<<actual->estudiante.nuevoCursoAlum[i].codCurso;
                    cout<<"\nNota Parcial 1     ->  "<<actual->estudiante.nuevoCursoAlum[i].notas[0];
                    cout<<"\nNota Parcial 2     ->  "<<actual->estudiante.nuevoCursoAlum[i].notas[1];
                    cout<<"\nNota Actividades   ->  "<<actual->estudiante.nuevoCursoAlum[i].notas[2];
                    cout<<"\nNota Examen F.     ->  "<<actual->estudiante.nuevoCursoAlum[i].notas[3];
                    cout<<"\nPromedio Final     ->  "<<actual->estudiante.nuevoCursoAlum[i].notas[4]<<endl;
                }
            }
                actual = actual->siguiente;//ACTUAL PASARA A SER EL SIGUIENTE DE LA 
        }       //LISTA
        cout<<endl;
        system("pause");
    }else{
        cout<<"\n\n\t\t AUN NO HAY REGISTROS \n\n";
        system("pause");
    }


}

void desplegarProfesor(){

	Colegio* actual = new Colegio();

	actual = primero;
	
    if(primero != NULL){//SI ESTA VACIO NO ENTRA
		
		while(actual != NULL){//SI ACTUAL ES DIFERENET DE NULL, CONTINUARA

            if(actual->eleccion == 0){//IMPRIMIMOS profeosr
                cout<<"\n\n\t\tDESPLEGANDO PROFESORES...\n\n";
                cout<<"Nombre de Profesor   ->   "<<actual->profesor.nombreProfe<<endl;
                cout<<"Codigo de Profesor   ->   "<<actual->profesor.codProfe<<endl;
                cout<<"Edad de Profesor     ->   "<<actual->profesor.edad<<endl;
                cout<<"Cursos Asignados     ->   "<<actual->profesor.CCRP<<endl;

                cout<<"\n\n\t\tDESPLEGANDO CURSOS...\n\n";
                for(int j = 0; j < actual->profesor.CCRP; j++){
                cout<<"Nombre de Curso      ->   "<<actual->profesor.nuevoCursoProfe[j].nombreCurso<<endl;
                cout<<"Codigo de Curso      ->   "<<actual->profesor.nuevoCursoProfe[j].codCurso<<endl<<endl;
                }
            }
			actual = actual->siguiente;;//ACTUAL PASARA A SER EL SIGUIENTE DE LA 
            //LISTA
		}
        cout<<endl;
		system("pause");
	}else{
		cout  << "\n\n\t\tAUN NO HAY REGISTROS\n\n";
		system("pause");
	}
}

void buscarCursoEstudiante(){

    string Curso;
    bool entro = false;
    cout<<"\n\n\t\t[ BUSQUEDA POR CURSO - ESTUDIANTE ] \n\n";

    cout<<"Ingresa curso a Buscar : ";
    fflush(stdin);
    getline(cin,Curso);//PEDIMOS CURSO A BUSCAR

    Colegio *actual = new Colegio();
    actual = primero;

    cout<<endl;

    while(actual != NULL){
        //SI LA LISTA ES DIFERENTE DE NULL ENTRA
        if(actual->eleccion == 1){//ELEGIMOS ESTUDIANTES

            for(int j = 0; j < actual->estudiante.CCRE;j++){
                //RECORRERA TODOS LOS ESTUDIANTES Y SUS CURSOS
                if(actual->estudiante.nuevoCursoAlum[j].nombreCurso.compare(Curso)==0){
                    
                    cout<<"Alumno inscrito ->   "<<actual->estudiante.nombreAlum<<endl;
                    cout<<"Codigo Alumno   ->   "<<actual->estudiante.codAlum<<endl;
                    cout<<"Nombre de Curso ->   "<<actual->estudiante.nuevoCursoAlum[j].nombreCurso<<endl;
                    cout<<"Codigo de Curso ->   "<<actual->estudiante.nuevoCursoAlum[j].codCurso<<endl<<endl;
                    entro = true;
                }
            }
        }
        actual = actual->siguiente;

    }

    if(entro != true){
        cout<<"\n\n\t\tNO SE ENCONTRO EL CURSO -> [ "<<Curso<<" ] "<<endl;
    }   


    cout<<endl;
    system("pause");
}

void buscarCursoProfesor(){

    string Curso;
    bool entro = false;
    cout<<"\n\n\t\t[ BUSQUEDA POR CURSO - ESTUDIANTE ] \n\n";

    cout<<"Ingresa curso a Buscar : ";
    fflush(stdin);
    getline(cin,Curso);//PEDIMOS CURSO A BUSCAR

    Colegio *actual = new Colegio();
    actual = primero;

    cout<<endl;

    while(actual != NULL){
    //SI LA LISTA ES DIFERENTE DE NULL ENTRA
        if(actual->eleccion == 0){

            for(int j = 0; j < actual->profesor.CCRP;j++){
                //RECORRERA TODOS LOS ESTUDIANTES Y SUS CURSOS
                if(actual->profesor.nuevoCursoProfe[j].nombreCurso.compare(Curso)==0){
                    
                    cout<<"Alumno inscrito ->   "<<actual->profesor.nombreProfe<<endl;
                    cout<<"Codigo Alumno   ->   "<<actual->profesor.codProfe<<endl;
                    cout<<"Nombre de Curso ->   "<<actual->profesor.nuevoCursoProfe[j].nombreCurso<<endl;
                    cout<<"Codigo de Curso ->   "<<actual->profesor.nuevoCursoProfe[j].codCurso<<endl<<endl;
                    entro = true;
                }
            }
        }
        actual = actual->siguiente;

    }

    if(entro != true){
        cout<<"\n\n\t\tNO SE ENCONTRO EL CURSO -> [ "<<Curso<<" ] "<<endl;
    }

    cout<<endl;
    system("pause");
}

void EstudiantesAprobados(){

    bool entro = false;

    Colegio *actual;

    actual = primero;
    cout<<endl;
    
    cout<<"\n\n\t\tALUMNOS APROBADOS...\n\n";
    while(actual != NULL){
        //RECORRERA TODOS LOS ESTUDIANTES APROBADOS HASTA QUE SEA NULL
        if(actual->eleccion == 1){
            for(int j = 0; j < actual->estudiante.CCRE; j++){
                
                if(actual->estudiante.nuevoCursoAlum[j].notas[4] >= 61){
                    //SI EL PROMEDIO ES MAYOR A 61 ENTONCES IMPRIME YA QUE ESTA APROBADO
                    cout<<"\nNombre de Alumno  ->   "<<actual->estudiante.nombreAlum<<endl;
                    cout<<"Codigo de Alumno    ->   "<<actual->estudiante.codAlum<<endl;
                    cout<<"Nombre de Curso     ->   "<<actual->estudiante.nuevoCursoAlum[j].nombreCurso<<endl;
                    cout<<"Codigo de Curso     ->   "<<actual->estudiante.nuevoCursoAlum[j].codCurso<<endl;
                    cout<<"Promedio General    ->   "<<actual->estudiante.nuevoCursoAlum[j].notas[4]<<endl<<endl;
                }
            }
        }
        actual = actual->siguiente;
    }

    system("pause");
}

void GuardarRegistrosEstudiantes(ofstream &x){

    Colegio *actual;

    actual = primero;

    while (actual != NULL){//RECORRERA TODOS LOS ESTUDIANTES Y SUS CURSOS
        
        if(actual->eleccion == 1){//ELEJIMOS ESTUDIANTES
            x<<actual->eleccion<<",";// Y LE PASAMOS AL ARCHIVO TODOS LOS DATOS
            x<<actual->estudiante.nombreAlum<<",";
            x<<actual->estudiante.codAlum<<",";
            x<<actual->estudiante.edad<<",";
            x<<actual->estudiante.CCRE<<",";
            for(int j = 0; j < actual->estudiante.CCRE; j++){
                x<<actual->estudiante.nuevoCursoAlum[j].nombreCurso<<",";
                x<<actual->estudiante.nuevoCursoAlum[j].codCurso<<",";
                x<<actual->estudiante.nuevoCursoAlum[j].notas[0]<<",";
                x<<actual->estudiante.nuevoCursoAlum[j].notas[1]<<",";
                x<<actual->estudiante.nuevoCursoAlum[j].notas[2]<<",";
                x<<actual->estudiante.nuevoCursoAlum[j].notas[3]<<",";
                x<<actual->estudiante.nuevoCursoAlum[j].notas[4]<<",";
            }
            
        }
        x<<"\n";//SIEMPRE CON UN SALTO DE LINEA AL ULTIMO
        actual = actual->siguiente;
    }
    x.close();
}


void GuardarRegistrosProfesores(ofstream &x){

    Colegio *actual;

    actual = primero;

    while (actual != NULL){//RECORRERA TODOS LOS ESTUDIANTES Y SUS CURSOS
        
        if(actual->eleccion == 0){//ELEJIMOS profesores
            x<<actual->eleccion<<",";// Y LE PASAMOS AL ARCHIVO TODOS LOS DATOS
            x<<actual->profesor.nombreProfe<<",";
            x<<actual->profesor.codProfe<<",";
            x<<actual->profesor.edad<<",";
            x<<actual->profesor.CCRP<<",";
            for(int j = 0; j < actual->profesor.CCRP; j++){
                x<<actual->profesor.nuevoCursoProfe[j].nombreCurso<<",";
                x<<actual->profesor.nuevoCursoProfe[j].codCurso<<",";
            }

        }

        x<<"\n";
        actual = actual->siguiente;
    }
    x.close();
}