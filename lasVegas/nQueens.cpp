//
// Created by alexito on 17/06/2021.
//

#include <iostream>
#include <list>
#include <math.h>
#include "nQueens.h"
#include <stdlib.h>

using namespace std;

NQueens::NQueens(const int n)
{
    mBoard.resize(n);
}

void NQueens::RepPlaceQueensLasVegas(const int k)
{
    while (!PlaceQueensLasVegas(k));
}

bool NQueens::PlaceQueensLasVegas(const int k)
{
    // Possible free squares in a row.
    list<int> possibleSquares;
    for (int i = 0; i < mBoard.size(); i++) {
        possibleSquares.push_back(i);
    }
    // Place the first k queens randomly.
    for (int i = 0; i < k; i++) {
        // Local copy of the possible squares in a row.
        list<int> currentPossibleSquares = possibleSquares;
        /* Place the square in the first possible square found, or return
         * false if there aren't any possible square in the current board. */
        int randomColumn;
        do {
            // There is no square to place the i-th queen.
            if (currentPossibleSquares.empty()) {
                return false;
            }
            randomColumn = *next(currentPossibleSquares.begin(), rand() % currentPossibleSquares.size());
            // Remove the current square in order to don't get it in another iteration.
            currentPossibleSquares.remove(randomColumn);
        }
        while (!CanPlace(i, randomColumn));
        // Place the i-th queen at this column.
        mBoard[i] = randomColumn;
    }
    // Place the rest of queens by backtracking.
    return PlaceQueensBacktracking(k);
}

bool NQueens::PlaceQueensBacktracking(const int row)
{
    // Out of board bounds.
    if (row >= mBoard.size()) return true;
    // Check if we can place thw row-th queen at any column.
    for (int i = 0; i < mBoard.size(); i++) {
        // Check if queen at row-th row can be placed at i-th column.
        if (CanPlace(row, i)) {
            // Place the row-th queen at this column.
            mBoard[row] = i;
            // It was the last placed queen, a solution has been found.
            if (row == mBoard.size() - 1) {
                return true;
            } else {
                /* If a solution has been found return true, else
                 * check solving with the non-explored columns. */
                if (PlaceQueensBacktracking(row + 1)) {
                    return true;
                }
            }
        }
    }
    // Row-th queen can't be placed in any column.
    return false;
}

bool NQueens::CanPlace(const int row, const int column) const
{
    /* Check if a queen can be placed at [row, column], just
     * watching if would be killed by any previous queen . */
    for (int i = 0; i < row; ++i)
    {
        // The i-th queen would kill the row-th queen.
        /* - mBoard[i] == y2 => columns are same.
         * - |i - row| == |mBoard[i] - column| => in diagonals. */
        if ((mBoard[i] == column) | (abs(i - row) == abs(mBoard[i] - column))) {
            return false;
        }
    }
    // No queen kills the row-th queens.
    return true;
}

void NQueens::PrintBoard() const
{
    cout << mBoard.size() << " Queens Solution:" << endl;
    for (int i = 0; i < mBoard.size(); i++) {
        for (int j = 0; j < mBoard[i]; j++) {
            cout << "x";
        }
        cout << "O";
        for (int j = mBoard[i] + 1; j < mBoard.size(); j++) {
            cout << "x";
        }
        cout << endl;
    }
}
