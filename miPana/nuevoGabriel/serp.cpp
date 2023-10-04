#include <iostream>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>


#define AZUL 1
#define NEGRO 0
#define VERDE	2
#define CELESTE 3
#define ROJO 4
#define NARANJA 14
#define AMARILLO 6
#define BLANCO 7

using namespace std;

void colorear(int color){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color);
}

void bienvenida(){

    cout<<"\n            /^\\/^\\                                             ";
    cout<<"\n          _|__|  O|                                              ";
    cout<<"\n \\/     /~     \\_/ \\                                          ";
    cout<<"\n  \\____|__________/  \\                                         ";
    cout<<"\n         \\_______      \\                                       ";
    cout<<"\n                 `\\     \\                 \\                   ";
    cout<<"\n                   |     |                  \\                   ";
    cout<<"\n                  /      /                    \\                 ";
    cout<<"\n                 /     /                       \\\\              ";
    cout<<"\n               /      /                         \\ \\            ";
    cout<<"\n              /     /                            \\  \\          ";
    cout<<"\n            /     /             _----_            \\   \\        ";
    cout<<"\n           /     /           _-~      ~-_         |   |          ";
    cout<<"\n          (      (        _-~    _--_    ~-_     _/   |          ";
    cout<<"\n           \\      ~-____-~    _-~    ~-_    ~-_-~    /          ";
    cout<<"\n             ~-_           _-~          ~-_       _-~   - Gaona -";
    cout<<"\n                ~--______-~                ~-___-~               ";
		
}

class Dado
{
public:
	Dado();
	int tirar();
};

Dado::Dado() {
	srand(time(NULL));
}

//Método Tirar
int Dado::tirar() {
	return rand() % 6 + 1;
}

struct posiciones{
    int x,y;


};

class AtajosYpenalizaciones{

    protected:
        int numEscalera;
        int numSerpientes;
        int penalty;
        int maxTurns;
        int reward;
    public:
        posiciones *posicionEscalera;
        posiciones *posicionSnake;
        AtajosYpenalizaciones(){


        }

        void inicializarEscaleras(){
            posicionEscalera = new posiciones[numEscalera];
        }

        void inicializarSerpientes(){
            posicionSnake = new posiciones[numSerpientes];
        }

        void definirEscaleras(int n){

            numEscalera = n;

        }
        void definirNumSerpientes(int n){

            numSerpientes = n;
        }

        void imprimirPosEscaleras(){
            for(int i = 0 ; i < numEscalera; i++){
                cout<<"["<<posicionEscalera[i].x<<","<<posicionEscalera[i].y<<"]"<<endl;
            }
        }
        void setPenalty(int i){
            penalty = i;
        }
        void setMaxTurnos(int i){
            penalty = i;
        }
        void setReward(int i){
            reward = i;
        }

};

class JuegoSerpiente : public AtajosYpenalizaciones, public Dado{

    protected:
        int tamTablero;
        int player1,player2;
        int puntajeTotal[2];
        char *tablero;
    public:

        JuegoSerpiente(){
            player1 = 0;
            player2 = 0;
        }

        void setPlayer1(int x){
            player1 += x;

            tablero[player1] = '1';
        }
        int getPlayer1(){
            return player1;
        }
        void setPlayer2(int x){
            player2 += x;
        }
        int getPlayer2(){
            return player2;
        }

        void definirTamTablero(int n){
            
            tamTablero = n;

            tablero = new char[n];

            for(int i = 0; i < tamTablero; i++){

                tablero[i] = '*';
            }
        }
        void limpiarTablero(){
            for(int i = 0; i < tamTablero; i++){

                tablero[i] = '*';
            }
        }
        void mostrarTablero(){
            
            int rI,rJ;

            cout<<"\n\n\t[ MOSTRANDO TABLERO ]\n\n\n";

            for(int i = 0; i < tamTablero; i++){
                
                if(i != 0){

                    if(tablero[i] == 'L'){
                        colorear(VERDE);
                        cout<<tablero[i]<<"\t";

                    }else if(tablero[i] == '*'){
                
                        colorear(AZUL);
                        cout<<tablero[i]<<"\t";
                    }else{
                        colorear(NARANJA);
                        cout<<tablero[i]<<"\t";
                    }
                    
                    if(i % 6 == 0){
                        cout<<endl<<endl;
                    }else if(i == tamTablero-1){
                        cout<<tablero[i]<<"\t";
                    }

                }else{
                    continue;
                }

            }

        cout<<"\n\n";
        }
        
        
        void posicionarEscalera(){

            int rI,rJ;

            for(int i = 0; i < numEscalera; i++){

                if(tamTablero < 31){
                    rI = 2+ rand() % (16+1-2);
                    rJ = 19 + rand() % (25+1-19);
                    posicionEscalera[i].x = rI;
                    posicionEscalera[i].y = rJ;


                    tablero[rI] = 'L';
                    tablero[rJ] = 'L';

                }else{
                    
                    rI = 2+ rand() % (16+1-2);
                    rJ = 19 + rand() % (40+1-19);
                    posicionEscalera[i].x = rI;
                    posicionEscalera[i].y = rJ;


                    tablero[rI] = 'L';
                    tablero[rJ] = 'L';
                }
            }
        }
        
        char getaCHARfromTablero(int x){

            return tablero[x];
        }
};

char presioneParaContinuar(){
    
    char ch;
    cout<<"Press C to continue, E to end the game.. ";
    ch = getch();
    return ch;

}

int menu(int opc){

    colorear(BLANCO);
    system("cls");
    cout<<"\n\n\t\t[ BIENVENIDO A LADDERS Y SNAKES ]\n\n";
    cout<<"[1]. Definir Cantidad de Tableros \n";
    cout<<"[2]. Definir Parametros y Jugar\n";
    cout<<"[3]. Parametros Aleatorios y Jugar\n";
    cout<<"[4]. Salir\n\n";
    cout<<"[-]. Ingresa opcion : ";
    cin>>opc;
    return opc;

}

int main(){


    srand (time(NULL));
    int tam;
    int y;
    JuegoSerpiente p1;
    char auxSalir;
    char anterior;
    int x = 0;

    bool salir = false;
    int opc;
    bool findelJuego = false;


    bienvenida();
    cout<<"\n\n\n";
    system("pause");
     do{
        opc = menu(opc);
        switch (opc)
        {

        case 1:system("cls");
            cout<<"\n\n\t\t TABLERO \n\n";
            cout<<"\nIngresa Tamanio Tablero : "; 
            cin>>tam;
            p1.definirTamTablero(tam);
            p1.mostrarTablero();

            cout<<endl;
            break;

        case 2:system("cls");

            p1.limpiarTablero();
            p1.mostrarTablero();
            cout<<"Defina Cuantas escaleras habra : ";
            cin>>tam;            
            p1.definirEscaleras(tam);
            p1.inicializarEscaleras();
            p1.posicionarEscalera();
            p1.mostrarTablero();
            cout<<endl;
            p1.imprimirPosEscaleras();

            do{
                system("cls");
                p1.mostrarTablero();
                x = p1.tirar();
                y = p1.tirar();
                auxSalir = presioneParaContinuar();
                if(auxSalir == 'C' ){
                    
                    if(p1.getaCHARfromTablero(x) == 'L'){
                        cout<<"\n\nFelicidades, bonus de escalera\n";
                        system("pause");
                    p1.setPlayer1(p1.posicionEscalera[0].y);
                    }else{

                    p1.setPlayer1(x);
                    }

                    
                }
                if(auxSalir == 'E'){
                    findelJuego = true;
                }
                

            }while(findelJuego != true);

        
            break;

        case 3:system("cls");
            break;
        
        case 4:system("cls");
            cout<<"GRACIAS POR JUGAR CON NOSOTROSS\n\n";
            break;


        }
        colorear(BLANCO);
        system("pause");

    }while(salir != true);



    return 0;
}