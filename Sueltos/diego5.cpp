#include <iostream>
using namespace std;

int main(){

    int a,b,res;

    cout<<"Ingresa A : ";
    cin>>a;
    cout<<"Ingresa B : ";
    cin>>b;

    if(a % 2 == 0){
        b = b*5;
        cout<<"El numero fue par, B -> "<<b<<endl;
    }else{
        res = b%9;
        cout<<"El numero fue impar, B -> "<<res<<endl;
    }

    return 0;
}