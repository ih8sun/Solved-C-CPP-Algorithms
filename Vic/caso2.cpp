#include <iostream>
#include <string>
#include <stdlib.h> 
#define max 8
using namespace std;
using namespace std;

typedef struct {
  int frente;
  int final;
  string vector[max];
} queue;


void Crear(queue &); 
bool IsEmpty(queue );
int getElements(queue );
bool IsFull(queue );
void insertar(queue &, string );
void eliminar(queue &);
void Recorrer(queue );


int main(){

  cout<<"\n\n\t\t[ MANEJO DE COLAS CIRCULARES ]\n\n";
  queue C;
  //Pasaremos a crear la cola
  Crear(C);
  
  insertar(C,"J");

  insertar(C,"K");

  insertar(C,"L");

  eliminar(C);

  eliminar(C);

  insertar(C,"M");

  eliminar(C);

  insertar(C,"N");




    return 0;
}

void Crear(queue &Cola) {
  Cola.frente = -1;
  Cola.final = -1;
}


bool IsEmpty(queue Cola) {
  if(Cola.frente == -1) {
    return true;
  } 
  return false;
}


int getElements(queue Cola) {
  if(IsEmpty(Cola)) {
    return 0;
  }

  if(Cola.final < Cola.frente) {
    return Cola.frente - Cola.final + 1;
  }
  
  return max - Cola.final + Cola.frente + 1;
}


bool IsFull(queue Cola) {
  if(getElements(Cola) == max) {
    return true;
  }
  return false;
}


void insertar(queue &Cola, string elemento) {
  if(!IsFull(Cola)) {

    if(IsEmpty(Cola)) { 
      Cola.final++;
    }


    if(Cola.frente == max - 1) {
      Cola.frente = 0;
    } else { 
      Cola.frente++;
    }

    Cola.vector[Cola.frente] = elemento;
    cout << "insertar: <" << elemento << ">" << endl;
    cout << "final: " << Cola.final << endl;
    cout <<"frente: " << Cola.frente << "\n" << endl;
  } else {
    cout << "Esta llena, no pudo entrar <" << elemento << ">" << endl;
  }
}


void eliminar(queue &Cola) {
  if(!IsEmpty(Cola)) {

    cout << "Se ha borrado " << Cola.vector[Cola.final] << endl; 

    if(getElements(Cola) == 1) {
      Crear(Cola); //kha?

    } else {
      Cola.final++; 
    }
  } else {
    cout << "Vacia no se puede borrar nada" << endl;
  }
}


void Recorrer(queue Cola) {
  if(!IsEmpty(Cola)) {
    int x;

    if(Cola.final <= Cola.frente) {
      for(x = 0; x <= Cola.frente; x++) {
        cout << "Cola.vector["<< x << "]: " << Cola.vector[x] << endl;
      }
    } else {
      //kha?
      for(x = Cola.final; x < max; x++) {
        cout << "Cola.vector["<< x << "]: " << Cola.vector[x] << endl;
      }
      for(x = 0; x <= Cola.frente; x--) {
        cout << "Cola.vector["<< x << "]: " << Cola.vector[x] << endl;
      }

    }
  } else {
    cout << "No existor egistros" << endl;
  }
}