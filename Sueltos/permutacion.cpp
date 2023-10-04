#include <iostream> 
#include <string.h>

using namespace std;

int formas = 0;

void Cambiar(char *x, char *y){ // CHAR X == IZQ , CHAR Y = I 
    
    char pivote;
    pivote = *x;
    *x = *y;
    *y = pivote;
}
void permutar(char *Ar, int izq, int der){

    if (izq == der){
        
        if (formas < 10){
            cout << "0" << formas << ".\t" << Ar << endl; //! 01 , 02 
        }
        else{
            cout << formas << ".\t" << Ar << endl; 
        }
        formas++; 
    }
    else{           
        for (int i = izq; i <= der; i++){
            
            // todo Cambiar( AR + 1) , (AR + 3) => AR[1] = B, AR[3] =D

            Cambiar((Ar + izq), (Ar + i)); // AR + izq = 1  = AR[1] 
            permutar(Ar, izq + 1, der);
            Cambiar((Ar + izq), (Ar + i)); // AR +


        }
    }
}

int main()
{
    int n = 0;
    char Abogados[] = "ABCDE"; //! 0 - 1 - 2- 3 - 4

    cout << "\n\n\t[ PERMUTACIONES - MESA - ABOGADOS ] \n\n";

    n = strlen(Abogados); //5

    permutar(Abogados, 0, n - 1);
    cout << "\nSe realizo " << formas << " permutaciones en total\n"<< endl;
    return 0;
}