/* ---------------------------------------------------------------------------
** main.cpp
** Plays with the N Queens Las Vegas solver.
**
** Author: Alex Santiago
** -------------------------------------------------------------------------*/

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "nQueens.h"


using namespace std;

int main(){
    // Initialize random seed.
    srand(time(NULL));

    /* 8 queens. Check that the amount of successes tends to p. */
    NQueens board8(8);
    int n = 0;
    for (int i = 0; i < 200000; i++) {
        n += board8.PlaceQueensLasVegas(8);
    }
    // Should be around p = 0’1293.
    cout << "8 Queens probability of success with k=8: " << n / 200000.0 << "%" << endl << endl;

    /* 39 Queens. Compare k values. */
    NQueens board39(39);
    for (int k = 22; k < 35; k++) {
        clock_t begin = clock();
        for (int i = 0; i < 200; i++) {
            board39.RepPlaceQueensLasVegas(k);
        }
        clock_t end = clock();
        cout << "39 Queens with k=" << k << ": " << (end - begin) * 1000 / 200.0 / CLOCKS_PER_SEC << "ms" << endl;
    }
    cout << endl;

    /* 100 Queens. Find a solution. */
    NQueens board100(100);
    board100.RepPlaceQueensLasVegas(85);
    board100.PrintBoard();
    cout << endl;

    /* 1000 Queens. Find a solution. */
    NQueens board1000(1000);
    board1000.RepPlaceQueensLasVegas(950);
    board1000.PrintBoard();
}