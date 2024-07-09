#include "sudoku.h"

int UNSOLVED = 81;
int SIZE_ROWS = 9;
int SIZE_COL = 9;

int main()
{
    int ** puzzle;
    int progress = 0;
    Sudoku * sudoku;

    puzzle = createPuzzle();

    sudoku = setUpPuzzle(puzzle);

    printPuzzle(sudoku->squares);

    while (UNSOLVED > 0)
    {
        progress = checkPuzzle(sudoku->squares, sudoku->boxes);

        if (progress == 0)
        {
            break;
        }
    }

    printf("\n\n");

    printPuzzle(sudoku->squares);
    
    return 0;
}