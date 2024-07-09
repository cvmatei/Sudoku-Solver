#include "sudoku.h"

int UNSOLVED = 81;

int main()
{
    int ** puzzle;
    Sudoku * sudoku;

    puzzle = createPuzzle();

    sudoku = setUpPuzzle(puzzle);

    printPuzzle(sudoku->squares);

    checkPuzzle(sudoku->squares, sudoku->boxes);

    checkPuzzle(sudoku->squares, sudoku->boxes);

    printf("\n\n\n");

    printPuzzle(sudoku->squares);
    
    return 0;
}