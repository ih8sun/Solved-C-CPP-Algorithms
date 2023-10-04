#include <iostream>

using namespace std;

bool validar( char destino, int mes, int dias, int adultos, int ninhos, char todoInc )
{
	bool validos;
	if ( ( destino == 'V' || destino == 'C' || destino == 'P') && (mes >= 1 && mes <= 12)
	     && dias >= 4 && adultos >= 1 && ninhos >= 0 && ( todoInc == 'S' || todoInc == 'N') )
		validos = true;
	else
		validos = false;
	return validos;
}
	
float obtenerPrecioDiaAdulto( char destino, int mes, char todoInc ) 
{
	float precioDiaAdulto;
	switch ( destino )	
	{
		case 'V': 	if ( mes == 5 || mes == 6 || mes == 7 || mes == 8 )
						if ( todoInc == 'S')
							precioDiaAdulto = 300;
						else
							precioDiaAdulto = 280;
					else
						if ( todoInc == 'S' ) 
							precioDiaAdulto = 250;
						else
							precioDiaAdulto = 230;
					break;
		case 'C': 	if ( mes == 9 || mes == 10 || mes == 11 )
						if ( todoInc == 'S')
							precioDiaAdulto = 280;
						else
							precioDiaAdulto = 250;
					else
						if ( todoInc == 'S' ) 
							precioDiaAdulto = 240;
						else
							precioDiaAdulto = 210;
					break;
		case 'P': 	if ( mes == 12 || mes == 1 || mes == 2 || mes == 3 )
						if ( todoInc == 'S')
							precioDiaAdulto = 390;
						else
							precioDiaAdulto = 350;
					else
						if ( todoInc == 'S') 
							precioDiaAdulto = 310;
						else
							precioDiaAdulto = 270;
	}
	return precioDiaAdulto;
}	
	
float calcularPrecioDiaNinho( float precioDiaAdulto, int ninhos )
{
	float precioDiaNinho, porcDesc;
	int i, edad, suma, edadMayor;
	suma = 0;
	edadMayor = 0;
	for(i=1;i<=ninhos;i++)
	{
		while (true)
		{
			cout << "Ingrese edad del menor " << i << ": ";
			cin >> edad;
			if ( edad >=1 && edad <= 18 )
				break;
			else
				cout << "... edad incorrecta" << endl;
			suma = suma + edad;
			if ( edad > edadMayor )
				edadMayor = edad;
		}
	}
	if ( ninhos < 4 ) 
		porcDesc = suma*1.0 / ninhos;
	else
		porcDesc = edadMayor*1.0; 
	precioDiaNinho = ( 1 - porcDesc / 100 ) * precioDiaAdulto;
	return precioDiaNinho;
}
	
void calcularMostrarTotales( int adultos, int ninhos, int dias, float precioDiaAdulto,
                             float precioDiaNinho )
{
	float totalAdultos, totalNinhos, totalGlobal, nuevoTotalGlobal;
	totalAdultos = precioDiaAdulto * adultos * dias;
	totalNinhos = precioDiaNinho * ninhos* dias;
	totalGlobal = totalAdultos + totalNinhos;
	cout << "Total a pagar por adultos es " << totalAdultos << " dólares" << endl;
	cout << "Total a pagar por niños es " << totalNinhos << " dólares" << endl;
	cout << "Total global a pagar es " << totalGlobal << " dólares" << endl;
	if ( ( adultos + ninhos ) > 5 && dias > 7 )
	{
		nuevoTotalGlobal = totalGlobal*0.9;
		cout << "El nuevo total global por viajar más de 5 personas y más de 7 días es " <<  
		         nuevoTotalGlobal << " dólares" << endl;
	}
}

int main()
{
	char destino, todoInc;
	int mes, dias, adultos, ninhos;
	bool datosValidos;
	float precioDiaAdulto, precioDiaNinho;
	
	while ( true )
	{
		cout << "Ingrese destino elegido Cancun(C), Varadero(V), PuntaCana(P): ";
		cin >> destino;
		cout << "Ingrese mes del viaje (1-12): ";
		cin >> mes;
		cout << "Ingrese cantidad de días de estadia: ";
		cin >> dias;
		cout << "Ingrese cantidad de adultos que viajarán: ";
		cin >> adultos;
		cout << "Ingrese cantidad de niños que viajarán: ";
		cin >> ninhos;
		cout << "Modalidad todo incluido ? (S/N): ";
		cin >> todoInc;
		datosValidos = validar( destino, mes, dias, adultos, ninhos, todoInc );
		if ( datosValidos == false )
			cout << "Uno o mas datos ingresados son incorrectos" << endl;
		else
			break;	
	}
	precioDiaAdulto = obtenerPrecioDiaAdulto( destino, mes, todoInc );
	if ( ninhos > 0 ) 
		precioDiaNinho = calcularPrecioDiaNinho( precioDiaAdulto, ninhos );
	else
		precioDiaNinho = 0;
	calcularMostrarTotales( adultos, ninhos, dias, precioDiaAdulto, precioDiaNinho);
	return 0;
}