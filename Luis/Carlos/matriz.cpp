#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
    float Vec[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    float Mat[5][5];
    float *Pfl, **Pmat;


    Pmat = new float*[5];

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            Pmat[i][j] = Mat[i][j];
        }
    }

    Pfl = new float[5];


    for(int i = 0; i < 5; i++){
            Pfl[i] = Vec[i];
    }
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
        {
            if (i == j)
            {
                *(*(Pmat + i) + j) = *(Vec + i) * *(Pfl + i);
                *(Pfl + i) = *(*(Mat + i) + j);
            }
            else
                Mat[i][j] = 0.0;
        }


    for(int i = 0; i < 5; i++){
            cout<<Pfl[i]<<"   ";
        cout<<endl;
    }
}
