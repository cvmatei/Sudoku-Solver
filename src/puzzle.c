#include "sudoku.h"

Sudoku * createSudoku(Square *** squares, Box ** boxes)
{
    Sudoku * sudoku;
    sudoku = malloc(sizeof(Sudoku));

    sudoku->squares = squares;
    sudoku->boxes = boxes;

    return sudoku;
}

Sudoku * setUpPuzzle(int ** puzzle)
{
    Square *** sudoku;
    Box ** boxes;
    int i, j, x;
    int currentBox = 0;

    sudoku = (Square***)malloc(sizeof(Square**)*9);
    boxes = createBoxes();

    /* loop through rows */
    for (i = 0; i < 9; i++)
    {
        /* malloc space for each row */
        sudoku[i] = (Square**)malloc(sizeof(Square*)*9);

        /* loop through columns */
        for (j = 0; j < 9; j++)
        {
            /* malloc space for each square */
            sudoku[i][j] = (Square*)malloc(sizeof(Square)*9);

            sudoku[i][j] ->number = puzzle[i][j];

            /* assign row ad column numbers to each square */
            sudoku[i][j] ->row = i;
            sudoku[i][j] ->col = j;
            sudoku[i][j] ->solvable = 9;

            boxes[currentBox]->squares[ boxes[currentBox]->numbers ] = sudoku[i][j];
            sudoku[i][j]->box = boxes[currentBox];
            boxes[currentBox]->numbers++;

            for (x = 0; x < 9; x++)
            {
                sudoku[i][j] ->possible[x] = 0;
            }

            if (j == 2)
                currentBox++;
            if (j == 5)
                currentBox++;
        }

        currentBox -= 2;
        if (i == 2)
            currentBox = 3;
        if (i == 5)
            currentBox = 6;
    }

    /* loop through rows */
    for (i = 0; i < 9; i++)
    {
        /* loop through columns */
        for (j = 0; j < 9; j++)
        {
            if (sudoku[i][j] ->number != 0)
            {
                sudoku[i][j] ->solvable = 0;
                updateSudoku(sudoku, i, j);
                updateBoxes(sudoku, i, j);
                UNSOLVED--;
            }
        }
    }

    return createSudoku(sudoku, boxes);
}

int updateSudoku(Square *** sudoku, int row, int col)
{
    int x;
    int number = sudoku[row][col] ->number;

    for (x = 0; x < 9; x++)
    {
        if (sudoku[x][col] ->possible[number - 1] == 0)
        {
            sudoku[x][col] ->solvable--;
        }
        sudoku[x][col] ->possible[number - 1] = 1;
    }

    for (x = 0; x < 9; x++)
    {
        if (sudoku[row][x] ->possible[number - 1] == 0)
        {
            sudoku[row][x] ->solvable--;
        }
        sudoku[row][x] ->possible[number - 1] = 1;
    }

    return 1;
}

int checkPuzzle(Square *** sudoku, Box ** boxes)
{
    int i, j, x;

    /* loop through rows */
    for (i = 0; i < 9; i++)
    {
        /* loop through columns */
        for (j = 0; j < 9; j++)
        {
            if (sudoku[i][j] ->solvable == 1)
            {
                solveSquare(sudoku[i][j]);
                updateSudoku(sudoku, i, j);
                updateBoxes(sudoku, i, j);
            }
        }
    }

    boxSingles(sudoku, boxes);

    return 1;
}

int ** createPuzzle()
{
    int ** puzzle;
    int i, j;
    int array[9][9] = {0, 1, 9,     0, 0, 2,    0, 0, 0,
                       4, 7, 0,     6, 9, 0,    0, 0, 1,
                       0, 0, 0,     4, 0, 0,    0, 9, 0, 

                       8, 9, 4,     5, 0, 7,    0, 0, 0,
                       0, 0, 0,     0, 0, 0,    0, 0, 0,
                       0, 0, 0,     2, 0, 1,    9, 5, 8,

                       0, 5, 0,     0, 0, 6,    0, 0, 0,
                       6, 0, 0,     0, 2, 8,    0, 7, 9,
                       0, 0, 0,     1, 0, 0,    8, 6, 0 };

    puzzle = (int**)malloc(sizeof(int*)*9);

    for (i = 0; i < 9; i++)
    {
        puzzle[i] = (int*)malloc(sizeof(int)*9);

        for (j = 0; j < 9; j++)
        {
            puzzle[i][j] = array[i][j];
        }
    }

    return puzzle;
}

void printPuzzle(Square *** puzzle)
{
    int i, j;

    printf("-------------------------------\n");
    for (i = 0; i < 9; i++)
    {
        /* print each row */
        printf("|");
        for (j = 0; j < 9; j++)
        {
            printf(" %d ", puzzle[i][j]->number);

            if (((j + 1) % 3) == 0)
            {
                printf("|");
            }
        }
        printf("\n");

        if (((i + 1) % 3) == 0)
        {
            printf("-------------------------------\n");
        }
    }
}