//
// Created by alexito on 20/06/2021.
//

#include "menu.h"
#include <conio.h>
#include <windows.h>
#include <stdio.h>

void gotoxy(int x, int y){

    HANDLE hCon;
    COORD dwPos;

    dwPos.X = x;
    dwPos.Y = y;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hCon, dwPos);
}

void pausar(){
    printf("\nPresione una tecla para continuar...");
    getch();
    printf("\n\n");
}

void limpiarPantalla(){

    system("cls");
}

void tamanoVentana(int *x, int *y){

    HANDLE hConsole;
    COORD coordScreen = {0, 0};
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (!GetConsoleScreenBufferInfo(hConsole, &csbi)){
        return;
    }
    *x = csbi.dwSize.X;
    *y = csbi.dwSize.Y;
    return;
}

void colorTexto(int ForgC){

    WORD wColor;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}

void colorfondo(int ForgC){

    if(ForgC == 0){
        system("color ff");
    }else{
        system("color f7");
    }
    return;
}

int menu(){

    limpiarPantalla();
    int opc;

    colorfondo(1);
    colorTexto(2);
    printf("\n\n\t\t[ MENU DE OPERACIONES ]\n\n");
    printf("[1]. Ingresar coches de carga\n");
    printf("[2]. Listar coches de carga\n");
    printf("[3]. Ingresar coches de pasajeros\n");
    printf("[4]. Listar coches de pasajeros\n");
    printf("[5]. Ordenar coches de carga por anio descendente\n");
    printf("[6]. Ordenar coches de carga por tipo ascendente\n");
    printf("[7]. Calcular coche de pasajeros mas antiguo\n");
    printf("[8]. Calcular el total de Asientos\n");
    printf("[9]. Salir\n\n");
    printf("[?]. Ingrese una opcion : ");
    scanf("%i",&opc);

    return opc;

}

