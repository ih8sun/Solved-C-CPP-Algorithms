#include<iostream>
using namespace std;

int mcd_proceso(int a, int b){
	if(b == 0){
		return a;
	}
	return mcd_proceso(b, a % b);
}

int main(){
	int n, num1, num2;
	
	cout<<"ingrese cantidad de numeros: ";
	cin>>n;
	
	for(int i=0 ; i<n ; i++){
		cout<<"ingrese ["<<i+1<<"] numeros: ";
		cin>>num2;
		if(i == 0)
			num1 = num2;	// num1 = 315 
		if(i > 1)                               // por ver si es necesario XD
			num1 = mcd_proceso(num1,num2);		//
		mcd_proceso(num1,num2);		//315, 441
		cout <<num1<<"\t"<<num2<<"\t"<<mcd_proceso(num1,num2)<<endl;
	}
	cout<<"MCD (Recursivo) es : "<<mcd_proceso(num1,num2);
	
	return 0;
}
