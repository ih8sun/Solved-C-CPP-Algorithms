#include <iostream>
#include <conio.h>
using namespace std;

long long potencia(int base,int exponente){
	long long res=0;

	if (exponente==0)
		return 1;
	if (exponente==1)
		return base;
	res=potencia(base,exponente/2);
	res *=res;
	if(exponente%2==1)
	res*=base;
	return res;
}
int main(){
	neg:
	cout<<"************************************************"<<endl;
	cout<<"|             POTENCIA DE UN NUMERO            |"<<endl;
	cout<<"************************************************"<<endl;
	int base,exponente;
	cout<<"Ingresar numero : ";
	cin>>base;
	cout<<"Exponente       : ";
	cin>>exponente;
	if(exponente<0){
	cout<<"\nExponente negativo, intente otra vez "<<endl;
	getch();
	system("cls");
	goto neg;
	}
	cout<<"Potencia        : "<<potencia(base,exponente);
	getch();
	cout<<endl<<endl;
	cout<<"************************************************"<<endl;
	cout<<"/////////GRACIAS POR USAR ESTE PROGRAMA/////////"<<endl;
	cout<<"************************************************"<<endl;
}
