#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define tamMax 100
#include "menu.h"
#include "definiciones.h"
int main() {

    bool salir = false;
    int opc;
    int tamCocheC = 0;
    CocheCarga cocheCarga[tamMax];

    do{
        opc = menu();
        switch (opc) {
            case 1:
                ingresarCocheCarga(cocheCarga,&tamCocheC);
                pausar();
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                salir = true;
                pausar();
                break;
        }

    }while(!salir);

    return 0;
}
