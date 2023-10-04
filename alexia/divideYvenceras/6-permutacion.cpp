#include <bits/stdc++.h>
#include <string.h>

using namespace std;

int formas = 0;


void Cambiar(char *x, char *y)
{

    char pivote;
    pivote = *x;
    *x = *y;
    *y = pivote;
}


void permutar(char *Ar, int izq, int der){

   int i;

   if (izq == der){
      //* Si en caso todas las formas posibles ya
      //*esten en el arreglo Ar, entonces lo imprimimos
     if(formas < 10 ){
        cout<<"0"<<formas<<".\t"<<Ar<<endl;
     }else{
        cout<<formas<<".\t"<<Ar<<endl;
     }

     formas++;//! Vamos aumentando el numero de permutaciones
   } 
   else{
       for (i = izq; i <= der; i++){
          Cambiar((Ar+izq), (Ar+i));
          permutar(Ar, izq+1, der);
          Cambiar((Ar+izq), (Ar+i));
        }
   }
}

int main()
{
    char abodago[] = "AEB";

    cout<<"\n\n\t[ PERMUTACIONES - MESA - ABOGADOS ] \n\n";
    
        
    int n = strlen(abodago);


    permutar(abodago, 0, n-1);
    cout<<"\nSe realizo "<<formas<<" permutaciones.en total\n"<<endl;
    return 0;
}
