#ifndef SUDOKU_H
#define SUDOKU_H

#include <stdio.h>
#include <stdlib.h>

extern int UNSOLVED;

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
void printPuzzle(Square *** sudoku);

Sudoku * createSudoku(Square *** squares, Box ** boxes);

int checkPuzzle(Square *** sudoku);
int updateSudoku(Square *** sudoku, int row, int col);

/* square functions */
int solveSquare(Square * square);

/* box functions */
Box ** createBoxes();
int updateBoxes(Square *** sudoku, int row, int col);

#endif