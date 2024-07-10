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

    for (int i = 0; i < SIZE_ROWS; i++) {
        free(puzzle[i]);  // Free each row
    }
    free(puzzle);

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

    for (int i = 0; i < SIZE_ROWS; i++) {
        for (int j = 0; j < SIZE_COL; j++) {
            free(sudoku->squares[i][j]);  // Free each Square pointer
        }
        free(sudoku->squares[i]);  // Free each Square* row
    }
    free(sudoku->squares);  // Free the array of Square** pointers

    for (int x = 0; x < 9; x++) {
        free(sudoku->boxes[x]->squares);  // Free each squares array
        free(sudoku->boxes[x]);           // Free each Box
    }
    free(sudoku->boxes);  // Free the array of Box pointers

    free(sudoku);
    
    return 0;
}