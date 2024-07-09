#include "sudoku.h"

/* int solveSquare(Square * square)
* 
* Once a square has been determined to have only 
* one possibility then the number is entered and 
* the global variable UNSOLVED is decremented 
*
*/
int solveSquare(Square * square)
{
    int x;

    for (x = 0; x < 9; x++)
    {
        if (square->possible[x] == 0)
        {
            square->number = x +1;
            square->solvable = 0;
            UNSOLVED--;
        }
    }
    return 0;
}
