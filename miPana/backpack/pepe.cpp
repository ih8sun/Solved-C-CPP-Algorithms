#include <cstdio>
#include <iostream>
#include <algorithm> //uso del sort
#include <cmath>
#include <windows.h>
#include <cstdlib>
using namespace std;

struct Node
{
    double peso;
    double beneficio;
    bool operator<(Node &t1)
    {
        return (this->beneficio / peso) > (t1.beneficio / t1.peso);
    }
};

Node *total;

int out;
int total_beneficio;
int total_peso;
int cantidad_ar, mochilamax;

COORD coord = {0, 0}; //coordenadas para la funcion Gotoxy

void gotoxy(int x, int y)
{

    coord.X = x;                                                      //coordenadas
    coord.Y = y;                                                      //coordenadas
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); // codidgo para posiciones
}

double podar(int i)
{
    double v = mochilamax - total_peso;
    double brp = 0.0;
    while (i <= cantidad_ar && total[i].peso < v)
    {
        v -= total[i].peso;
        brp += total[i].beneficio;
        i++;
    }
    if (i <= cantidad_ar)
    {
        brp += total[i].beneficio / total[i].peso * v;
    }
    return total_beneficio + brp;
}

void backtracking(int f)
{
    if (f == cantidad_ar)
    {
        out = max(out, total_beneficio);
        return;
    }
    for (int i = 0; i < 2; i++)
    {
        if (i)
        {
            if (podar(f + 1) > out)
                backtracking(f + 1);
        }
        else
        {
            if (total_peso + total[f].peso <= mochilamax)
            {
                total_beneficio += total[f].beneficio;
                total_peso += total[f].peso;
                backtracking(f + 1);
                total_beneficio -= total[f].beneficio;
                total_peso -= total[f].peso;
            }
        }
    }
}

int main()
{

    //presentacion();
    system("cls");
    int v = 0;
    gotoxy(20, 7);
    cout << "	ingrese el peso maximo de la mochila: " << endl;
    gotoxy(30, 8);
    cin >> mochilamax;
    gotoxy(20, 9);
    cout << "	ingrese la cantidad de articulos: " << endl;
    gotoxy(30, 10);
    cin >> cantidad_ar;

    total = new Node[cantidad_ar];
    int j = 11;
    for (int i = 0; i < cantidad_ar; i++)
    {

        gotoxy(20, j);
        cout << "peso[" << i + 1 << "]: ";
        cin >> total[i].peso;
        gotoxy(40, j);
        cout << "beneficio[" << i + 1 << "]: ";
        cin >> total[i].beneficio;
        v += total[i].beneficio;
        j++;
    }
    sort(total, total + cantidad_ar);
    out = 0;
    total_peso = 0;
    total_beneficio = 0;
    backtracking(0);

    cout << "el beneficio maximo obtenido es: " << out;
    delete[] total;

    return 0;
}