//
// Created by alexito on 21/06/2021.
//

#ifndef NUEVOARG_DEFINICIONES_H
#define NUEVOARG_DEFINICIONES_H


typedef struct{

    char matricula[10];
    int anioFab;
    int cantAs;
    char operativo[2];

}Pasajero;

typedef struct{

    char matricula[10];
    int anioFab;
    char tipo[7];
    char revision2020[2];
}CocheCarga;

void ingresarCocheCarga(CocheCarga [], int *);
void listarCocheCarga(CocheCarga [], int );
void ingresarCochePasajero(Pasajero [],int *);
void listarCochePasajero(Pasajero [],int );
void ordenarCochesDescendente(Pasajero [],int );
void ordenarPasajerosAescendente(Pasajero [],int );
void calcularPasajerosAntiguo(Pasajero [],int *);
void calcularTotalAsientosPasajeros(Pasajero [],int *);

#endif //NUEVOARG_DEFINICIONES_H
