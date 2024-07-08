#ifndef SUDOKU_H
#define SUDOKU_H

#include <stdio.h>
#include <stdlib.h>

extern char POSSIBLE;

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
void printPuzzle(int ** puzzle);
Square *** setUpPuzzle(int ** puzzle);

#endif