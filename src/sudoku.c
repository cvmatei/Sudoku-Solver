#include "sudoku.h"

int UNSOLVED = 81;

int main()
{
    int ** puzzle;
    Square *** sudoku;

    puzzle = createPuzzle();

    sudoku = setUpPuzzle(puzzle);

    printPuzzle(sudoku);

    checkPuzzle(sudoku);

    checkPuzzle(sudoku);

    checkPuzzle(sudoku);

    checkPuzzle(sudoku);

    

    printf("\n\n\n");

    printPuzzle(sudoku);
    
    return 0;
}