#include <iostream>
using namespace std;


void sqr(int &x){

    x = x*x;
}

int main(){

    int a = 3;
    sqr(a);

    cout<<a<<endl;

}