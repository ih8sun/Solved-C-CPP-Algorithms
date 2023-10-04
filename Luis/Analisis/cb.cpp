//Ejercicio 2
#include <iostream>

using namespace std;
int n;

void Binomial(int **B, int i){
	if(i<=n){
		for(int k=0; k<i+1; k++){
			B[i][k] = (k==0 || k==i) ? 1 : B[i-1][k-1]+B[i-1][k];
		}		
		Binomial(B, i+1);		
	}		
}

int main(){
	cout<<"Ingresar el grado: "; 
	cin>>n;
	
	int** B = new int*[n+1];
	for(int i = 0; i < n+1; i++)
		B[i] = new int[i+1];
	
	Binomial(B, 0);
	
	//Imprimmir
	for(int i=0; i<=n; i++){
		cout<<"Grado "<<i<<": ";
		for(int j=0; j<i+1; j++){
			cout<<B[i][j]<<" ";
		}
		cout<<endl;
	}
}
