#ifndef SUDOKU_H
#define SUDOKU_H

#include <stdio.h>
#include <stdlib.h>

extern int UNSOLVED;
extern int SIZE_ROWS;
extern int SIZE_COL;

typedef struct Sudoku
{
    struct Square *** squares;
    struct Box ** boxes;
} Sudoku;

typedef struct Box
{
    struct Square ** squares;
    int numbers;
    int possible[9];
    int solvable;
    struct Box * next;
} Box;

typedef struct Square
{
    int number;
    int possible[9];
    int solvable;
    Box * box;
    int row;
    int col;
} Square;


int ** createPuzzle();
Sudoku * setUpPuzzle(int ** puzzle);
void printPuzzle(Square *** squares);

Sudoku * createSudoku(Square *** squares, Box ** boxes);

int checkPuzzle(Square *** sudoku, Box ** boxes);
int updateSudoku(Square *** sudoku, int row, int col);

/* square functions */
int solveSquare(Square * square);

/* box functions */
Box ** createBoxes();
int updateBoxes(Square *** sudoku, int row, int col);
int boxSingles(Square *** sudoku, Box ** boxes);

/* row functions */
int checkRows(Square *** sudoku);

#endif