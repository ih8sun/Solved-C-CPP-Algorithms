#include <iostream>

using namespace std;

int nro_m = 0;

int minimo(int datos[], int longitud){
	int menor=datos[0];
	for(int i=1;i<longitud;i++){
		if(menor>datos[i])
			menor=datos[i];
	}
	return menor;
}

void inicializar(int **resul){
	for(int i = 0; i < nro_m; i++){
		for(int j = 0; j < nro_m; j++){
			resul[i][j] = 0;
		}
	}
}

void matrices(int **resul, int d[], int iter){
	if(iter < nro_m){
		if(iter == 1){
			for(int s = 0;s < nro_m-iter; s++){
				resul[s][s+iter] = d[s]*d[s+1]*d[s+2];
			}
		}
		else{
			int minimos[iter] = {0};
			for(int s = 0;s < nro_m-iter; s++){
				for(int t=0; t<iter; t++){
					//minimos[0] = result[1][2]+(d[0]*d[1]*d[3]);
					//minimos[1] = result[0][1]+(d[0]*d[2]*d[3]);
					//minimos[0] = result[2][3]+(d[1]*d[2]*d[4]);
					//minimos[1] = result[1][2]+(d[1]*d[3]*d[4]);
					
					//minimos[0] = resul[1][3]+(d[0]*d[1]*d[4])
					//minimos[1] = resul[0][1]+resul[2][3]+(d[0]*d[2]*d[4])
					//minimos[2] = resul[0][2]+(d[0]*d[3]*d[4])
					minimos[t] = (d[s]*d[s+t+1]*d[s+iter+1]);
					if(iter == 2)
						minimos[t] += resul[iter-t+s-1][iter-t+s];
					if(iter == 3){
						if(t == 1)
							minimos[t] += resul[t-1][t] + resul[iter-t][iter];
						else
							minimos[t] += resul[iter-(t/2)-2][iter-(t/2)];
					}
					
				}
				//resul[0][2] = minimo(minimos, iter);
				//resul[1][3] = minimo(minimos, iter);
				
				//resul[0][3] = minimo(minimos, iter)
				resul[s][s+iter] = minimo(minimos, iter);				
			}
		}
			
		/*resul[0][1] = 5785;
		resul[1][2] = 1335;
		resul[2][3] = 9078;*/
		
		matrices(resul, d, iter+1);
	}
}

void mostrar(int **resul){
	for(int i = 0; i < nro_m; i++){
		for(int j = 0; j < nro_m; j++){
			cout<<resul[i][j]<<"\t";
		}
		cout<<endl;
	}
}

int main(){
	//cantidad matrices
	cout<<"ingrese cantidad de matrices: ";
	cin>>nro_m;
	int M[nro_m][2] = {0};
	//cantidad de filas y columnas de las matrices
	for(int i=1; i <= nro_m; i++){
		cout<<"ingrese cantidad de filas de la matriz ["<<i<<"]: ";
		cin>>M[i-1][0];
		cout<<"ingrese cantidad de columnas de la matriz ["<<i<<"]: ";
		cin>>M[i-1][1];
	}
	
	for(int i=0; i < nro_m; i++){
		cout<<"Matriz["<<i+1<<"] FxC = "<<M[i][0]<<"x"<<M[i][1]<<endl;
	}
	//matriz de nxn, donde n cantidad de matrices
	int** resul = new int*[nro_m];
	for(int i = 0; i < nro_m; i++)
		resul[i] = new int[nro_m];
	
	//vector de dimensiones n
	int d[nro_m+1] = {0};
	d[0] = M[0][0];
	for(int i=1; i < nro_m+1; i++)
		d[i] = M[i-1][1];
	
	inicializar(resul);
	
	matrices(resul, d, 1);
	
	mostrar(resul);
	
	//int a[4] = {123, 334, 224, 7652};
	
	//cout<<minimo(a, 4);
}
