#include "main.cpp"
#include "gtest/gtest.h"

// Note that the following array declarations only initialize 12x12 grids.
// The ROWS and COLUMNS constants have values 42 and 62 however.
// In this case the 'missing' values will be 'zero-initialized'.
// This means they will have the value 0, which corresponds to the enum member Dead.
// Effectively we only describe a portion of the top-left part of the universe to test with.
// The rest of the universe will implicitly be made up of dead cells.
Cell glider0[ROWS][COLUMNS] = {
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Live, Live, Live, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Live, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Live, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
};

Cell glider1[ROWS][COLUMNS] = {
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Live, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Live, Live, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Live, Dead, Live, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
};

Cell glider2[ROWS][COLUMNS] = {
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Live, Live, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Live, Dead, Live, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Live, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
};

Cell glider3[ROWS][COLUMNS] = {
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Live, Live, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Live, Live, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Live, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
};

Cell glider4[ROWS][COLUMNS] = {
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Live, Live, Live, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Dead, Live, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Live, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
    {Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead, Dead},
};

void array_copy(Cell source [ROWS][COLUMNS], Cell dest [ROWS][COLUMNS]) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLUMNS; j++) {
            dest[i][j] = source[i][j];
        }
    }
}

// Check if the inner part of two universes match.
// Note that by design the outer dead frame is not checked.
bool generation_match(Cell generation [ROWS][COLUMNS], Cell reference [ROWS][COLUMNS]) {
    for(int i = 1; i < ROWS-1; i++) {
        for(int j = 1; j < COLUMNS-1; j++) {
            if(generation[i][j] != reference[i][j])
                return false;
        }
    }

    return true;
}

// Check if the universe has an outer dead frame.
bool has_dead_frame(Cell universe [ROWS][COLUMNS]) {
    for(int i = 0; i < ROWS; i++) {
        if(universe[i][0] != Dead || universe[i][COLUMNS-1] != Dead)
            return false;
    }

    for(int i = 1; i < COLUMNS-1; i++) {
        if(universe[0][i] != Dead || universe[ROWS-1][i] != Dead)
            return false;
    }

    return true;
}

TEST(next_gen, glider_0)
{
    Cell now [ROWS][COLUMNS];
    Cell next [ROWS][COLUMNS];
    array_copy(glider0, now);
    next_generation(now, next);
    EXPECT_TRUE(generation_match(next, glider1));
    EXPECT_TRUE(has_dead_frame(next));
}

TEST(next_gen, glider_1)
{
    Cell now [ROWS][COLUMNS];
    Cell next [ROWS][COLUMNS];
    array_copy(glider1, now);
    next_generation(now, next);
    EXPECT_TRUE(generation_match(next, glider2));
    EXPECT_TRUE(has_dead_frame(next));
}

TEST(next_gen, glider_2)
{
    Cell now [ROWS][COLUMNS];
    Cell next [ROWS][COLUMNS];
    array_copy(glider2, now);
    next_generation(now, next);
    EXPECT_TRUE(generation_match(next, glider3));
    EXPECT_TRUE(has_dead_frame(next));
}

TEST(next_gen, glider_3)
{
    Cell now [ROWS][COLUMNS];
    Cell next [ROWS][COLUMNS];
    array_copy(glider3, now);
    next_generation(now, next);
    EXPECT_TRUE(generation_match(next, glider4));
    EXPECT_TRUE(has_dead_frame(next));
}
