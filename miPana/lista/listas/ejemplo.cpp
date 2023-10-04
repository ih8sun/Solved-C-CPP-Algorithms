#include <iostream>
#include <stdlib.h>

using namespace std;

struct cole{

    int *nombre;

    void inicializar(int x){
        nombre = new int[x];
    }

};

int main(){

    cole nuevoAlum;

    nuevoAlum.inicializar(3);

    nuevoAlum.nombre[0] = 12;
    nuevoAlum.nombre[1] = 12;
    nuevoAlum.nombre[3] = 15;

    for(int i = 0; i < 3; i++){
        cout<<nuevoAlum.nombre[i]<<endl;
    }

    return 0;
}