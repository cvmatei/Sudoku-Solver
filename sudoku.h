#ifndef SUDOKU_H
#define SUDOKU_H

#include <stdio.h>
#include <stdlib.h>

extern int UNSOLVED;

typedef struct Box
{
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
int checkPuzzle(Square *** sudoku);
int solveSquare(Square * square);
void printPuzzle(Square *** sudoku);
Square *** setUpPuzzle(int ** puzzle);
int updateSudoku(Square *** sudoku, int row, int col);

#endif