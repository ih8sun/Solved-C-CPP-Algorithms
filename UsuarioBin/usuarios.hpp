#include <string>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#define MAX_LENGTH 100

using namespace std;


struct usuarios{

    string id;
    string password;
    usuarios *sgte;

}*primero,*ultimo;

struct auxUser{

    string id;
    string password;

};


void ingresarUser(auxUser a){

    usuarios *nuevo;
    nuevo = new usuarios();

    nuevo->id = a.id;
    nuevo->password = a.password;

    if(primero == NULL){
        primero->sgte = NULL;
        primero = nuevo;
        ultimo = primero;
    }else{
        ultimo->sgte = nuevo;
        nuevo->sgte = NULL;
        ultimo = nuevo;
    }
}


void desplegarLista(){
	usuarios* actual = new usuarios();
	actual = primero;
	if(primero != NULL){
		
		while(actual != NULL){

            cout<<" "<<actual->id<<" "<<actual->password<<endl;

			actual = actual->sgte;
		}
		
	}else{
		cout  << "\n La Lista se Encuentra Vacia\n\n";
	}
}


auxUser lineaAuser(char *a){

    auxUser elpepe;


    char delimitador[]  = " ";
    int cont = 1;
    char *ptr;

    ptr = strtok(a,delimitador);

    string str(ptr);


    elpepe.id = str;
    while((ptr=strtok(NULL,delimitador))!=NULL){
        if (cont == 1){
            string str2(ptr);
            elpepe.password = str2;
        }
        cont++;
    }

    return elpepe;

}

void cargarUsuarios(){

    usuarios *nuevo;
    nuevo = new usuarios();



    string auxID,auxPass;
    char aux[MAX_LENGTH];
    FILE *usuariosFile;
    auxUser a;


    usuariosFile = fopen("users.bin","rb");

    while(fgets(aux,MAX_LENGTH,usuariosFile)){
        
        a = lineaAuser(aux);

        ingresarUser(a);

    }


}



