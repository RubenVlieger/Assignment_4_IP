#include <iostream>
#include <fstream>
#include <cassert>
#include<windows.h>


using namespace std;

enum Cell {Dead=0, Live};                         // a cell is either Dead or Live (we use the fact that dead = 0 and live = 1)

const char DEAD             = '.' ;               // the presentation of a dead cell (both on file and screen)
const char LIVE             = '*' ;               // the presentation of a live cell (both on file and screen)
const int NO_OF_ROWS        = 40 ;                // the number of rows (height) of the universe (both on file and screen)
const int NO_OF_COLUMNS     = 60 ;                // the number of columns (width) of the universe (both on file and screen)
const int ROWS              = NO_OF_ROWS    + 2 ; // the number of rows in a universe array, including the 'frame' of dead cells
const int COLUMNS           = NO_OF_COLUMNS + 2 ; // the number of columns in a universe array, including the 'frame' of dead cells

Cell cell_at (Cell universe [ROWS][COLUMNS], int row, int column)
{
    // pre-condition
    
    //assert(row > 0);
    if((row > 0) && (row < ROWS) &&
       (column > 0) && (column < COLUMNS))
    {
        return universe [row][column];
    }
    else
    {
        return Dead;
    }
    
    //return universe[row][column]; // fout want moet + 1 ofzo
}



//  Part 1: setting the scene
bool read_universe_file (string filename, Cell universe [ROWS][COLUMNS])
{
    // pre-conditions, post-conditions, implementation
    ifstream inputfile(filename);

    assert(inputfile.good() && inputfile.is_open());

    for(int r = 0; r < ROWS; r++)
    {
        for(int c = 0; c < COLUMNS; c++)
        {   
            // If this condition is true then it is in one of the border cells of the grid and it has to place a dead cell in that location.
            if((r == 0) || (r==ROWS-1) || (c==0) || (c==COLUMNS-1))
                universe[r][c] == Dead;

            else
            {
                char cell_char;
                inputfile.get(cell_char);
                // This uses a tenary operator to check if the read char is equal to the '*' or '.' character and translate it to a Cell.
                Cell cell = (cell_char == LIVE) ? Live : Dead;
                
                // We have to offset the row and columns by 1 because the edges 
                universe[r][c] = cell;
            }
        }
    }
    inputfile.close();
    return true;
}

void show_universe (Cell universe [ROWS][COLUMNS])
{
    // pre-conditions, post-conditions, implementation
    for (int r = 1; r < ROWS; r++)
    {
        for (int c = 1; c < COLUMNS; c++)
        {
            char char_cell = (universe[r][c] == Live) ? LIVE : DEAD;
            cout << char_cell;
        }
        cout << endl;
    }
}


int how_many_live_neighbours(Cell universe[ROWS][COLUMNS], int row, int column)
{
    int neighbour_count = 0;
    /* This loops over all of the neighbours and checks each neighbouring cell from the rows (row - 1) to (row + 1)
       and the columns (column - 1) to (column + 1). */
    for(int r = -1; r <= 1; r++)
        for(int c = -1; c <= 1; c++)
            if(r != 0 && c != 0) // This check is made so it doesn't count its own value.
                if(cell_at(universe, row - r, column - c) == Live)
                    neighbour_count++;

    return neighbour_count;
}

//  Part 2: the next generation
void next_generation (Cell now[ROWS][COLUMNS], Cell next [ROWS][COLUMNS])
{
    // pre-conditions, post-conditions, implementation
    for (int r = 1; r < ROWS; r++)
    {
        for(int c = 1; c < COLUMNS; c++)
        {
            int neighbour_count = how_many_live_neighbours(now, r, c);
            /* Underpopulation if the cell is alive and it has less than two neighbours */
            if((cell_at(now, r, c) == Live) && (neighbour_count < 2))
            {
                next[r][c] = Dead;
            }
            /* The cell can live on if it has two or three neighbours */
            else if ((cell_at(now, r, c) == Live) && (neighbour_count == 2 || neighbour_count == 3))
            {
                next[r][c] = Live;
            }
            /* The cell dies from overpopulation if it has more than three neighbours. */
            else if ((cell_at(now, r, c) == Live) && (neighbour_count > 3))
            {
                next[r][c] = Dead;
            }
            /* The cell reproduces if it has exactly three neighbours and it is not currently alive. */
            else if ((cell_at(now, r, c) == Dead) && (neighbour_count == 3))
            {
                next[r][c] = Live;
            }
            /* To overcome the issue of unititalized variables in the next array it 
               should always become dead if no previous condition was met */
            else if (cell_at(now, r, c) == Dead)
            {
                next[r][c] = Dead;
            }   
        }
    }
}

// void swap_arrays(Cell& array1[ROWS][COLUMNS], Cell& array2[ROWS][COLUMNS])
// {
//     Cell tempArray[ROWS][COLUMNS] = array1;
//     array1 = array2;
//     array2 = tempArray;
// }

#ifndef TESTING
int main ()
{
    Cell now[ROWS][COLUMNS];    
    Cell next[ROWS][COLUMNS];

    read_universe_file("Gosper_glider_gun.txt", now);

    while(true)
    {

        //swap_arrays(now, next);
        show_universe(now);
        next_generation(now, next);
        std::swap(now, next);
        Sleep(1000);
        cout << endl;

        //delay(wacht ff);
    }



    return 0;
}
#endif
