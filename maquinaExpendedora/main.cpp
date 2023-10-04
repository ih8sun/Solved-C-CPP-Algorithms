#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <cstdlib>
#include <time.h>
#define COLOR_BLACK 0
#define COLOR_BLUE 1
#define COLOR_GREEN	2
#define COLOR_CYAN 3
#define COLOR_RED 4
#define COLOR_MAGENTA 5
#define COLOR_BROWN 6
#define COLOR_LIGHTBLUE 9
#define COLOR_LIGHTGREEN 10
#define COLOR_LIGHTCYAN 11
#define COLOR_LIGHTRED 12
#define COLOR_LIGHTMAGENTA 12
#define COLOR_YELOW 14
#define COLOR_WHITE 15
#define COLOR_BLINK 128
#define MAX_LENGTH 256
#define COLOR_LIGHTGRAY 8
#define maxSize 8
using namespace std;

void gotoxy(int x,int y){
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y= y;
    SetConsoleCursorPosition(hcon,dwPos);
}
void colorear(int color){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color);
}
void dibujarMaquina(string [][maxSize],int [][maxSize], float [][maxSize]);
void rellenar(string [][maxSize],int [][maxSize], float [][maxSize]);
void vaciarMaquina(string [][maxSize],int [][maxSize], float [][maxSize]);
void llenarMaquina(string [][maxSize],int [][maxSize], float [][maxSize],bool &);
float costosTotales(float [][maxSize]);
float realizarVenta(string [][maxSize],int [][maxSize], float [][maxSize]);
void comprobarStock(string [][maxSize],int [][maxSize], float [][maxSize]);
void menu(){
    system("cls");
    colorear(COLOR_YELOW);
    cout<< "\n\n\t  __  __                ___     _         _            _"
        << "\n\t |  \\/  |___ _ _ _  _  | _ \\_ _(_)_ _  __(_)_ __  __ _| |"
        << "\n\t | |\\/| / -_) ' \\ || | |  _/ '_| | ' \\/ _| | '_ \\/ _` | |"
        << "\n\t |_|  |_\\___|_||_\\_,_| |_| |_| |_|_||_\\__|_| .__/\\__,_|_|"
        << "\n\t                                           |_|           "
        << "\n";
    colorear(COLOR_WHITE);
    cout<<"[1]. Vaciar Maquina Expendedora\n";
    cout<<"[2]. LLenar Maquina Expendedora\n";
    cout<<"[3]. Realizar alguna Venta\n";
    cout<<"[4]. Monto Recaudado\n";
    cout<<"[5]. Costos Totales\n";
    cout<<"[6]. Stocks Insuficientes\n";
    cout<<"[7]. Salir\n";
    cout<<"\n[?]. Ingresa una opcion : ";
}

int main() {

    //VARIABLES PARA EL MENU
    string nombreProducto[maxSize][maxSize];
    int stockProducto[maxSize][maxSize];
    float precioProducto[maxSize][maxSize];
    float ventasX = 0;
    float totalCosto;
    bool salir = false;
    int opc;
    bool entro = true;
    //Variables Ramdoms
    rellenar(nombreProducto,stockProducto,precioProducto);
    srand (time(NULL));
    do{
        menu();
        cin>>opc;
        if(cin.fail()){
            opc = -1;
            cin.clear();
            cin.ignore();
        }
        switch (opc) {
            case 1:
                vaciarMaquina(nombreProducto,stockProducto,precioProducto);
                entro = false;
                break;
            case 2:
                llenarMaquina(nombreProducto,stockProducto,precioProducto,entro);
                break;
            case 3:
                ventasX += realizarVenta(nombreProducto,stockProducto,precioProducto);
                system("pause");
                break;
            case 4:
                cout<<"\n\nDinero recaudado de la maquina es de $/."<<ventasX<<endl<<endl;
                system("pause");
                break;
            case 5:
                totalCosto = costosTotales(precioProducto);
                cout<<"\n\nCostos totales de la maquina es de $/."<<totalCosto<<endl<<endl;
                system("pause");
                break;
            case 6:
                comprobarStock(nombreProducto,stockProducto,precioProducto);
                cout<<endl;
                system("pause");
                break;
            case 7:
                salir = true;
                break;
        }

    }while(!salir);

    return 0;
}

void vaciarMaquina(string nom[][maxSize],int stock[][maxSize], float pr[][maxSize]){

    int i,j;

    for(i = 0; i < maxSize; i++){
        for(j = 0; j < maxSize; j++){
            nom[i][j] = "\x00";
        }
    }

    for(i = 0; i < maxSize; i++){
        for(j = 0; j < maxSize; j++){
            stock[i][j] = 0;
        }
    }

    for(i = 0; i < maxSize; i++){
        for(j = 0; j < maxSize; j++){
            pr[i][j] = 0;
        }
    }

}

void llenarMaquina(string nom[][maxSize],int stock[][maxSize], float pr[][maxSize],bool &entro) {

    int i,j,opc;

    if(entro){
        cout<<"\n\n\t\t[ DATOS INTRODUCIDOS ]\n\n";
        cout<<"\nYa hay datos introducidos en la maquina\n";
        cout<<"[1]. Limpiar Maquina y llenar nuevos Datos\n";
        cout<<"[2]. Regresar al Menu\n\n[?]. Ingresa opc : ";
        cin>>opc;
        switch (opc) {
            case 1:
                entro = false;
                break;
            case 2:
                entro = true;
                break;
        }
    }

    if(!entro) {
        system("cls");
        cout<<"\n\n\t\t[ LLENANDO MAQUINA EXPENDEDORA ]\n\n";
        for (i = 0; i < maxSize; i++) {
            entro = true;
            for (j = 0; j < maxSize; j++) {
                cout << "Ingresa nombre de Producto [" << i << "][" << j << "] : ";
                fflush(stdin);
                getline(cin, nom[i][j]);
                cout << "Ingresa stock de Producto [" << i << "][" << j << "] : ";
                cin >> stock[i][j];
                cout << "Ingresa precio de Producto [" << i << "][" << j << "] : ";
                cin >> pr[i][j];
            }
            cout << endl;
        }
    }
}

void dibujarMaquina(string nom[][maxSize],int stock[][maxSize], float pr[][maxSize]){
    system("cls");

    //Variables Matriz
    int X = 3;
    int Y = 4 ;

    int i;
    bool entro = true;
    //HORIZONTALES
    for(i = 2; i < 78; i++){
        gotoxy(i,3); printf("%c",205);
        gotoxy(i,7); printf("%c",205);
        gotoxy(i,11); printf("%c",205);
        gotoxy(i,15); printf("%c",205);
        gotoxy(i,19); printf("%c",205);
        gotoxy(i,23); printf("%c",205);
        gotoxy(i,27); printf("%c",205);
        gotoxy(i,31); printf("%c",205);
        gotoxy(i,35); printf("%c",205);
    }


    //VERTICALES
    for(i = 4; i < 35; i++){
        gotoxy(2,i); printf("%c",186);
        gotoxy(11,i); printf("%c",186);
        gotoxy(20,i); printf("%c",186);
        gotoxy(29,i); printf("%c",186);
        gotoxy(38,i); printf("%c",186);
        gotoxy(48,i); printf("%c",186);
        gotoxy(58,i); printf("%c",186);
        gotoxy(68,i); printf("%c",186);
        gotoxy(77,i); printf("%c",186);

    }

    colorear(COLOR_WHITE);
    //ESQUINAS
    do {
        gotoxy(2, 3);
        printf("%c", 201); //norOeste
        gotoxy(2, 35);
        printf("%c", 200);//surOeste
        gotoxy(77, 3);
        printf("%c", 187);//norEste
        gotoxy(77, 35);
        printf("%c", 188);//suOeste

        //ESQUINAS 2
        gotoxy(2, 7);
        printf("%c", 204);
        gotoxy(2, 11);
        printf("%c", 204);
        gotoxy(2, 15);
        printf("%c", 204);
        gotoxy(2, 19);
        printf("%c", 204);
        gotoxy(2, 23);
        printf("%c", 204);
        gotoxy(2, 27);
        printf("%c", 204);
        gotoxy(2, 31);
        printf("%c", 204);
        gotoxy(77, 7);
        printf("%c", 185);//norEste
        gotoxy(77, 11);
        printf("%c", 185);//suOeste
        gotoxy(77, 15);
        printf("%c", 185);//suOeste
        gotoxy(77, 19);
        printf("%c", 185);//suOeste
        gotoxy(77, 23);
        printf("%c", 185);//suOeste
        gotoxy(77, 27);
        printf("%c", 185);//suOeste

        //Esquinas 3


        gotoxy(11, 3);
        printf("%c", 203);
        gotoxy(20, 3);
        printf("%c", 203);
        gotoxy(29, 3);
        printf("%c", 203);
        gotoxy(38, 3);
        printf("%c", 203);
        gotoxy(48, 3);
        printf("%c", 203);
        gotoxy(58, 3);
        printf("%c", 203);
        gotoxy(68, 3);
        printf("%c", 203);

        gotoxy(11, 35);
        printf("%c", 202);
        gotoxy(20, 35);
        printf("%c", 202);
        gotoxy(29, 35);
        printf("%c", 202);
        gotoxy(38, 35);
        printf("%c", 202);
        gotoxy(48, 35);
        printf("%c", 202);
        gotoxy(58, 35);
        printf("%c", 202);
        gotoxy(68, 35);
        printf("%c", 202);
    }while(!entro);

    for(int k = 0; k < maxSize; k++){
        gotoxy(X, 4);
        cout<<nom[0][k];
        gotoxy(X,5);
        cout<<stock[0][k];
        gotoxy(X,6);
        cout<<"$/. "<<pr[0][k];

        if(k < 4) {
            X = X + 9;
        }else{
            X = X + 10;
        }
    }
    X = 3;
    for(int k = 0; k < maxSize; k++){
        gotoxy(X, 8);
        cout<<nom[1][k];
        gotoxy(X,9);
        cout<<stock[1][k];
        gotoxy(X,10);
        cout<<"$/. "<<pr[1][k];
        if(k < 4) {
            X = X + 9;
        }else{
            X = X + 10;
        }
    }
    X = 3;
    for(int k = 0; k < maxSize; k++){
        gotoxy(X, 12);
        cout<<nom[2][k];
        gotoxy(X,13);
        cout<<stock[2][k];
        gotoxy(X,14);
        cout<<"$/. "<<pr[2][k];
        if(k < 4) {
            X = X + 9;
        }else{
            X = X + 10;
        }
    }
    X = 3;
    for(int k = 0; k < maxSize; k++){
        gotoxy(X, 16);
        cout<<nom[3][k];
        gotoxy(X,17);
        cout<<stock[3][k];
        gotoxy(X,18);
        cout<<"$/. "<<pr[3][k];
        if(k < 4) {
            X = X + 9;
        }else{
            X = X + 10;
        }
    }
    X = 3;
    for(int k = 0; k < maxSize; k++){
        gotoxy(X, 20);
        cout<<nom[4][k];
        gotoxy(X,21);
        cout<<stock[4][k];
        gotoxy(X,22);
        cout<<"$/. "<<pr[4][k];
        if(k < 4) {
            X = X + 9;
        }else{
            X = X + 10;
        }
    }
    X = 3;
    for(int k = 0; k < maxSize; k++){
        gotoxy(X, 24);
        cout<<nom[5][k];
        gotoxy(X,25);
        cout<<stock[5][k];
        gotoxy(X,26);
        cout<<"$/. "<<pr[5][k];
        if(k < 4) {
            X = X + 9;
        }else{
            X = X + 10;
        }
    }
    X = 3;
    for(int k = 0; k < maxSize; k++){
        gotoxy(X, 28);
        cout<<nom[6][k];
        gotoxy(X,29);
        cout<<stock[6][k];
        gotoxy(X,30);
        cout<<"$/. "<<pr[6][k];
        if(k < 4) {
            X = X + 9;
        }else{
            X = X + 10;
        }
    }
    X = 3;
    for(int k = 0; k < maxSize; k++){
        gotoxy(X, 32);
        cout<<nom[7][k];
        gotoxy(X,33);
        cout<<stock[7][k];
        gotoxy(X,34);
        cout<<"$/. "<<pr[7][k];
        if(k < 4) {
            X = X + 9;
        }else{
            X = X + 10;
        }
    }

//    COORDENADAS
    int F = 7;
    colorear(COLOR_LIGHTGREEN);
    for(int h = 0; h < maxSize; h++) {
        gotoxy(F, 1);
        cout<<h;

        if( h < 4) {
            F += 9;
        }else{
            F += 10;
        }
    }

    colorear(COLOR_RED);
    int C = 5;
    for(int m = 0; m < maxSize;  m++){
        gotoxy(0,C);
        cout<<m;
        C += 4;
    }


}

void rellenar(string nom[][maxSize],int stock[][maxSize], float pr[][maxSize]){

    for(int i = 0; i < maxSize;i++){
        for(int j = 0; j < maxSize; j++){
            stock[i][j] = 1 + rand()%(16-1);
            pr[i][j] = 50 + rand()%(201-1);
        }
    }
    nom[0][0] = "CocaCola";
    nom[0][1] = "Snacks";
    nom[0][2] = "Piqueo";
    nom[0][3] = "Chetos";
    nom[0][4] = "M&M";
    nom[0][5] = "Doritos";
    nom[0][6] = "Lay's";
    nom[0][7] = "Ruffles";

    nom[1][0] = "Sublime";
    nom[1][1] = "Tobleron";
    nom[1][2] = "Nestle";
    nom[1][3] = "Mentitas";
    nom[1][4] = "Nachos";
    nom[1][5] = "Fanta";
    nom[1][6] = "Chifles";
    nom[1][7] = "Pop-Corn";

    nom[2][0] = "Monster";
    nom[2][1] = "RedBull";
    nom[2][2] = "FourLoKo";
    nom[2][3] = "Snakes";
    nom[2][4] = "Gomitas";
    nom[2][5] = "Trululu";
    nom[2][6] = "Jenjibre";
    nom[2][7] = "Pinguino";

    nom[3][0] = "Chetos F";
    nom[3][1] = "Lentejas";
    nom[3][2] = "Blackout";
    nom[3][3] = "QueRico!";
    nom[3][4] = "Sprite";
    nom[3][5] = "Doritos M";
    nom[3][6] = "SDKalixto";
    nom[3][7] = "LongHorn";

    nom[4][0] = "KolaReal";
    nom[4][1] = "BigCola";
    nom[4][2] = "Snufer";
    nom[4][3] = "Glorias";
    nom[4][4] = "Ate";
    nom[4][5] = "Mueganos";
    nom[4][6] = "Cocada";
    nom[4][7] = "Alegrias";

    nom[5][0] = "Frutitas";
    nom[5][1] = "LemonC";
    nom[5][2] = "Obleas";
    nom[5][3] = "Macarron";
    nom[5][4] = "Rollitos";
    nom[5][5] = "Jamon";
    nom[5][6] = "Tortitas";
    nom[5][7] = "Alfajor";

    nom[6][0] = "Psyllium";
    nom[6][1] = "Harina";
    nom[6][2] = "SalFlav";
    nom[6][3] = "Frescura";
    nom[6][4] = "Sonia CH";
    nom[6][5] = "Mexicanos";
    nom[6][6] = "Big Kola";
    nom[6][7] = "Takis";

    nom[7][0] = "Antojito";
    nom[7][1] = "TakisIII";
    nom[7][2] = "Pretzels";
    nom[7][3] = "Herdez";
    nom[7][4] = "Chchrron!";
    nom[7][5] = "Oho!";
    nom[7][6] = "Chrruitos";
    nom[7][7] = "Canelone";
}

float costosTotales(float precios[][maxSize]){

    float x = 0;
    int i,j;

    for(i = 0; i < maxSize; i++){
        for(j = 0; j < maxSize; j++){
            x += precios[i][j];
        }
    }

    return x;
}


void comprobarStock(string nom[][maxSize],int stock[][maxSize], float pr[][maxSize]){

    int i,j;
    cout<<"\n\n\t\t[ COMPROBANDO STOCK ]\n\n";
    for(i = 0; i < maxSize; i++){
        for(j = 0; j < maxSize; j++){
            if(stock[i][j] <= 3){
                if(stock[i][j] == 1){
                    cout<<"Producto -> "<<nom[i][j]<<endl;
                    cout<<"Stock -> "<<stock[i][j]<<endl;
                    cout<<"Precio -> $/."<<pr[i][j]<<endl;
                    cout<<"Se recomienda aumentar stock URGENTE\n";
                    cout<<endl;
                }else{
                    cout<<"Producto -> "<<nom[i][j]<<endl;
                    cout<<"Stock -> "<<stock[i][j]<<endl;
                    cout<<"Precio -> $/."<<pr[i][j]<<endl;
                    cout<<"Se recomienda aumentar stock\n";
                    cout<<endl;
                }
            }
        }
    }
}

float realizarVenta(string nom[][maxSize],int stock[][maxSize], float pr[][maxSize]){

    dibujarMaquina(nom,stock,pr);
    int f,c;
    bool correcto = false;
    float dinero;

    colorear(COLOR_WHITE);
    cout<<"\n\n\n\t\t\t [ REALIZAR UNA VENTA ]\n\n";

    do {
        colorear(COLOR_RED);
        cout << "Ingresa Fila : ";
        cin >> f;
        if(correcto >= 0 && correcto <= 7){
            correcto = true;
        }else{
            correcto = false;
        }
    }while(!correcto);

    do {
        colorear(COLOR_LIGHTGREEN);
        cout << "Ingresa Columna : ";
        cin >> c;
        if(correcto >= 0 && correcto <= 7){
            correcto = true;
        }else{
            correcto = false;
        }
    }while(!correcto);

    if(stock[f][c] != 0){
        colorear(COLOR_WHITE);
        cout<<"\nUsted Ha seleccionado\n";
        cout<<"\nNombre Producto ->  "<<nom[f][c];
        cout<<"\nStock Producto ->  "<<stock[f][c];
        cout<<"\nPrecio Producto ->  "<<pr[f][c]<<endl;

        cout<<endl;
        do{
            cout<<"\nIngrese el dinero a la maquina : ";
            cin>>dinero;
            if(dinero == 0){
                cout<<"No se puede ingresar 0\n";

            }
            if(dinero >= pr[f][c]){

                if(dinero == pr[f][c]){
                    cout<<"\n\nSE REALIZO UNA VENTA EXITOSA\n\n";
                    stock[f][c]--;
                    return dinero;
                }else{
                    cout<<"\n\nSE REALIZO UNA VENTA EXITOSA\n\n";
                    cout<<"Dinero Usuario  ->  "<<dinero<<endl;
                    cout<<"Precio Producto ->  "<<pr[f][c]<<endl;
                    cout<<"Su vuelto       ->  "<<dinero-pr[f][c]<<endl<<endl;
                    stock[f][c]--;
                    return dinero-pr[f][c];

                }
            }else{
                cout<<"Debe ingresar El dinero suficiente para comprar\n";
                correcto = false;
            }
        }while(!correcto);
    }else{
        cout<<"\n\n[ NO HAY STOCK DE ESTE PRODUCTO ]\n\n";
    }

    return 0;
}