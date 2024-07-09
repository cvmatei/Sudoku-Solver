#include "sudoku.h"

int UNSOLVED = 81;

int main()
{
    int ** puzzle;
    Square *** sudoku;

    puzzle = createPuzzle();

    printPuzzle(puzzle);

    sudoku = setUpPuzzle(puzzle);

    checkPuzzle(sudoku);
    
    return 0;
}