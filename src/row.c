#include "sudoku.h"

/* int checkRows(Square *** sudoku)
 *
 * checkRows function checks all rows to see if there is 
 * only one possibility in that row for a number to exist
 */
int checkRows(Square *** sudoku)
{
    int i, j, k;
    int sum[9];
    int place[9];

    /* Loop through all rows */
    for (i = 0; i < SIZE_ROWS; i++)
    {
        /* Initialize sum and place to 0 */
        for (j = 0; j < 9; j++)
        {
            place[j] = 0;
            sum[j] = 0;
        }
         

        /* Loop though each square in the row */
        for (j = 0; j < SIZE_COL; j++)
        {
            if (sudoku[i][j]->number != 0)
            {
                continue;
            }

            /* Loop through all possibles */
            for (k = 0; k < 9; k++)
            {
                
                /* Check if number (k) is possible */
                if (sudoku[i][j]->possible[k] == 0)
                {
                    sum[k]++;
                    place[k] = j;
                }
            }
        }

        for (k = 0; k < 9; k++)
        {
            if (sum[k] == 1)
            {
                sudoku[i][place[k]]->number = k + 1;
                sudoku[i][place[k]]->solvable = 0;
                UNSOLVED--;

                updateSudoku(sudoku, i, place[k]);
                updateBoxes(sudoku, i, place[k]);

                return 1;
            }
        }
    }

    return 0;
}