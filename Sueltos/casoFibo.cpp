#include <iostream>
#include <windows.h>
#include <math.h>
using namespace std;


int factorial(int n) {

   if(n < 0) {
       return 0;
    }
   else if(n > 1){
        return n*factorial(n-1);
   }
   return 1;
}

double Serie(int n) {
	double sumaTotal = 1;
	for (int i = 1; i <= n; i++) {
		if (i % 2 == 0) {
			sumaTotal -= (pow(i, 2) + 1) / factorial(i);
		}
		else {
			sumaTotal += (pow(i, 2) + 1) / factorial(i);
		}
	}
    sumaTotal -= 1;
    cout<<"\nLa Suma de los 4 primeros terminos es : "<<sumaTotal<<endl;
	return sumaTotal;
}



void Graficar(int n) {
	int aux = 1;
	for (int i = 1; i <=n ; i++) {
		for (int j = 1; j <= i; j++) {
			cout << aux<<" ";
		}
		aux++;
		cout << endl;
	}
}

int main() {
	int opcion, n;
	do {
        system("cls");
		cout << "\n\t Menu de opciones\n" << endl;
		cout << "1) Hallar la suma de los n terminos" << endl;
		cout << "2) Graficar" << endl;
		cout << "3) Salir" << endl;
		cout << "Ingrese opcion: ";
		cin >> opcion;
		if (opcion == 1) {
			cout << "N: ";
			cin >> n;
			Serie(n);
		}
		else if (opcion == 2) {
			cout << "Ingrese numero de filas: ";
			cin >> n;
			Graficar(n);
		}
        system("pause");
	} while (opcion != 3);

	return 0;
}