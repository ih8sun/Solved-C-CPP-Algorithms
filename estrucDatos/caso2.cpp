#include <iostream>
#include <stdlib.h>
#include <string>
#include <windows.h>
using namespace std;

void gotoxy(int x,int y){
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y= y;
    SetConsoleCursorPosition(hcon,dwPos);
}

struct nodo{

    string nombre;
    string artista;
    int anio;
    int num_Canciones;
    string genero;
    double precio;
	nodo* siguiente;

} *primero, *ultimo;

void insertarNodo(int  []);
void desplegarLista(int  []);
void desplegarListaGENERO(int  []);

void titulo(){

    system("cls");
    gotoxy(40,2);
    cout<<"[ DESPLEGANDO MIS DISCOS FAVORITOS ]";

    gotoxy(0,5);
    cout<<"NOMBRE";

    gotoxy(20,5);
    cout<<"ARTISTA";

    gotoxy(39,5);
    cout<<"ANIO";

    gotoxy(53,5);
    cout<<"NUM_CANCIONES";

    gotoxy(73,5);
    cout<<"GENERO";

    gotoxy(92,5);
    cout<<"PRECIO";


}
string nombre(int x){

    switch (x)
    {

    case 0: return "ROCK";
        break;

    case 1:
        return "POP";
        break;
    
    case 2:return "BALADA";
        break;

    case 3:return "SALSA";
        break;
    
    case 4:return "REGUETON";
        break;

    }
    return " ";
}

void menu(){
    system("cls");
    cout<<"\n\n\t\t[ MENU DE OPCIONES ]\n\n";
    cout<<"[1]. Ingresar un Disco\n";
    cout<<"[2]. Desplegar discos\n";
    cout<<"[3]. Desplegar Genero mas Repetido\n";
    cout<<"[4]. Salir\n";
    cout<<"\n[?]. Ingresa una opcion : ";
}

void inicializar(int generos []){
    
    for(int i = 0 ; i < 5; i++){
        generos[i] = 0;
    }
}

int main(){

    bool salir = false;
    int opc,i;
    int generos[5];
    int tam = 0;

    inicializar(generos);

    do{
        menu();
        cin>>opc;
        switch (opc)
        {
        case 1:
            insertarNodo(generos);
            tam++;
            break;
        
        case 2:
            desplegarLista(generos);
            break;

        case 3:
            if(tam > 9){
            desplegarListaGENERO(generos);
            }else{
                cout<<"\nContinue registrando hasta que llegue a 10 registros..\n\n";
                system("pause");
            }
            break;

        case 4:
            salir = true;
            cout<<"\n\n\t\t[ GRACIAS POR USAR NUESTRO PROGRAMA ]\n\n";
            break;
        }


    }while(salir != true);

    system("pause");
	return 0;
}



void insertarNodo(int generos[]){

	nodo* nuevo = new nodo();
    int opc;
    string aux;
    bool correcto = false;

    cout<<"\n\n\t\t[ INGRESO DE DISCO ]\n\n";
    
	cout << "\nIngrese el nombre del Album : ";
    fflush(stdin);
	getline(cin,nuevo->nombre);
    aux = nuevo->nombre;
    
	cout << "\nIngrese el Artista del Album : ";
    fflush(stdin);
	getline(cin,nuevo->artista);
    
	cout << "\nIngrese el Anio del Album : ";
	cin>>nuevo->anio;
    
	cout << "\nIngrese el numero de canciones del Album : ";
	cin>>nuevo->num_Canciones;
    
    do{
        cout << "\nElige el genero del Album\n\n";
        cout<<"[1]. ROCK\n[2]. POP\n[3]. BALADA\n[4]. SALSA\n[5]. REGUETON\n\n[?]. Ingresa : ";
        cin>>opc;
        opc--;

        
        switch (opc)
        {
        case 0:
            nuevo->genero = "ROCK";
            correcto = true;
            generos[opc] = generos[opc] + 1;
            break;
        case 1:
            nuevo->genero = "POP";
            generos[opc] = generos[opc] + 1;
            correcto = true;
            break;
        case 2:
            nuevo->genero = "BALADA";
            generos[opc] = generos[opc] + 1;
            correcto = true;
            break;
        case 3:
            nuevo->genero = "SALSA";
            generos[opc] = generos[opc] + 1;
            correcto = true;
            break;
        case 4:
            nuevo->genero = "REGUETON";
            generos[opc] = generos[opc] + 1;
            correcto = true;
            break;

        default:
            cout<<"\nIngresa una opcion correcta : ";
            system("pause");
            break;
        }

    }while(correcto != true);

	cout << "\nIngrese el precio del Album : ";
    cin>>nuevo->precio;


	if(primero == NULL){
		primero = nuevo;
		primero->siguiente = NULL;
		ultimo = nuevo;
	}else{
		ultimo->siguiente = nuevo;
		nuevo->siguiente = NULL;
		ultimo = nuevo;
	}

    for(int i = 0; i < aux.length(); i++){
        aux[i] = toupper(aux[i]);
    }

    
	cout << "\n\n\t\t[ Disco -> " << aux<<" <-Ingresado ]\n\n";

    system("pause");
}

void desplegarLista(int generos[]){
	nodo* actual = new nodo();
	actual = primero;

    int y = 8;

    
	if(primero != NULL){
		
        titulo();
		while(actual != NULL){
        gotoxy(0,y);
        cout<<actual->nombre;

        gotoxy(20,y);
        cout<<actual->artista;

        gotoxy(39,y);
        cout<<actual->anio;

        gotoxy(59,y);
        cout<<actual->num_Canciones;

        gotoxy(74,y);
        cout<<actual->genero;

        gotoxy(94,y);
        cout<<actual->precio;
        y++;

        actual = actual->siguiente;
		}

        gotoxy(0,y+5);
        system("pause");
		
	}else{
		cout  << "\n La Lista se Encuentra Vacia\n\n";
        system("pause");
	}

}

void desplegarListaGENERO(int generos[]){
	nodo* actual = new nodo();
	actual = primero;

    int y = 8,mayor = 0, posM;

    
	if(primero != NULL){
		
        titulo();
		while(actual != NULL){
        gotoxy(0,y);
        cout<<actual->nombre;

        gotoxy(20,y);
        cout<<actual->artista;

        gotoxy(39,y);
        cout<<actual->anio;

        gotoxy(59,y);
        cout<<actual->num_Canciones;

        gotoxy(74,y);
        cout<<actual->genero;

        gotoxy(94,y);
        cout<<actual->precio;
        y++;

        actual = actual->siguiente;
		}

        for(int i = 0; i < 5; i++){
            if(mayor < generos[i]){
                mayor = generos[i];
                posM = i;
            }
        }

        gotoxy(0,y+5);
        cout<<"EL GENERO MAS REPETIDO ES : "<<nombre(posM)<<endl;

        gotoxy(0,y+8);
        system("pause");
		
	}else{
		cout  << "\n La Lista se Encuentra Vacia\n\n";
        system("pause");
	}
}