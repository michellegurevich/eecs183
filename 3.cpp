/**
 * ohhi.cpp
 *
 * EECS 183, Winter 2015
 * Project 3: 0h h1
 *
 * Ezra Lesser, Michelle Gurevich
 * elesser, mgur
 *
 * Builds a boardgame, checks inputs for the game, and solves game if prompted.
 */

#include <iostream>
#include <cctype>
#include "utility.h"
#include "ohhi.h"

///////////////////////////////////////
// UTILITY FUNCTIONS //////////////////
///////////////////////////////////////

int count_unknown_squares(const int board[MAX_SIZE][MAX_SIZE], int size) {
    int count = 0;

    // counts the number of unknown squares
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (board[i][j] == UNKNOWN) {
                ++count;
            }
        }
    }
    return count;
}


///////////////////////////////////////
// VALIDITY CHECKS ////////////////////
///////////////////////////////////////

bool row_has_no_threes_of_color(const int board[MAX_SIZE][MAX_SIZE],
                                int size, int row, int color) {
    bool no_threes = true;
    int num_in_row = 0;
    
    // counts total amount of a color in row, resets if other color appears
    const int MAX_OF_COLOR = 2;
    for (int i = 0; i < size; ++i) {
        if (board[row][i] == color) {
            ++num_in_row;
            if (num_in_row > MAX_OF_COLOR) {
                no_threes = false;
            }
        }
        else {
            num_in_row = 0;
        }
    }
    return no_threes;
}

bool col_has_no_threes_of_color(const int board[MAX_SIZE][MAX_SIZE],
                                int size, int col, int color) {
    bool no_threes = true;
    int num_in_row = 0;

    // counts total amount of a color in column, resets if other color appears
    const int MAX_OF_COLOR = 2;
    for (int i = 0; i < size; ++i) {
        if (board[i][col] == color) {
            ++num_in_row;
            if (num_in_row > MAX_OF_COLOR) {
                no_threes = false;
            }
        }
        else {
            num_in_row = 0;
        }
    }
    return no_threes;
}

bool board_has_no_threes(const int board[MAX_SIZE][MAX_SIZE], int size) {
    bool no_threes = true;

    for (int i = 0; i < size; ++i) {
        // checks that board does not contain three of a color in row
        if (!row_has_no_threes_of_color(board, size, i, RED)) {
            no_threes = false;
        }
        else if (!row_has_no_threes_of_color(board, size, i, BLUE)) {
            no_threes = false;
        }
        // checks that board does not contain three of a color in column
        else if (!col_has_no_threes_of_color(board, size, i, RED)) {
            no_threes = false;
        }
        else if (!col_has_no_threes_of_color(board, size, i, BLUE)) {
            no_threes = false;
        }
    }
    return no_threes;
}

bool rows_are_different(const int board[MAX_SIZE][MAX_SIZE],
                        int size, int row1, int row2) {
    bool different = false;

    // checks that each row contains different combinations of colors
    for (int i = 0; i < size; ++i) {
        if ((board[row1][i] != board[row2][i])
            || (board[row1][i] == 0)
            || (board[row2][i] == 0)) {
            different = true;
        }
    }
    return different;
}


bool cols_are_different(const int board[MAX_SIZE][MAX_SIZE],
                        int size, int col1, int col2) {
    bool different = false;

    // checks that each column contains different combinations of colors
    for (int i = 0; i < size; ++i) {
        if ((board[i][col1] != board[i][col2])
            || (board[i][col1] == 0)
            || (board[i][col2] == 0)) {
            different = true;
        }
    }
    return different;
}

bool board_has_no_duplicates(const int board[MAX_SIZE][MAX_SIZE], int size) {
    bool no_duplicates = true;

    for (int i = 0; i < size - 1; ++i) {
        for (int j = i + 1; j < size; ++j) {

            // checks that there do not exist duplicate column combinations
            if (!(cols_are_different(board, size, i, j))) {
                no_duplicates = false;
            }
            
            // checks that there do not exist duplicate row combinations
            if (!(rows_are_different(board, size, i, j))) {
                no_duplicates = false;
            }
        }
    }
    return no_duplicates;
}


///////////////////////////////////////
// SOLVING FUNCTIONS //////////////////
///////////////////////////////////////

void solve_three_in_a_row(int board[MAX_SIZE][MAX_SIZE],
                          int size, int row, bool announce) {

    for (int i = 0; i < size - 1; ++i) {
        if (board[row][i] == board[row][i + 1] && board[row][i] != UNKNOWN) {
            int color = board[row][i];
            int opposite_color = 0;

            if (color == RED) {
                opposite_color = BLUE;
            }
            else {
                opposite_color = RED;
            }

            // makes third entry in row opposite color to preceding two entries
            if ((i - 1) >= 0 && board[row][i - 1] == UNKNOWN) {
                mark_square_as(board, size, row, i - 1,
                    opposite_color, announce);
            }
            // makes third entry in row opposite color to following two entries
            if ((i + 2) < size && board[row][i + 2] == UNKNOWN) {
                mark_square_as(board, size, row, i + 2,
                    opposite_color, announce);
            }
        }

        // makes middle entry in row opposite color to surrounding two entries
        if (i + 2 < size && board[row][i] == board[row][i + 2] &&
            board[row][i] != UNKNOWN) {

            int color = board[row][i];
            int opposite_color = 0;

            if (color == RED) {
                opposite_color = BLUE;
            }
            else {
                opposite_color = RED;
            }
            if (board[row][i + 1] == UNKNOWN) {
                mark_square_as(board, size, row, i + 1,
                    opposite_color, announce);
            }
        }
    }
    return;
}

void solve_three_in_a_column(int board[MAX_SIZE][MAX_SIZE],
                             int size, int col, bool announce) {

    for (int i = 0; i < size - 1; ++i) {
        if (board[i][col] == board[i + 1][col] && board[i][col] != UNKNOWN) {
            int color = board[i][col];
            int opposite_color = 0;

            if (color == RED) {
                opposite_color = BLUE;
            }
            else {
                opposite_color = RED;
            }

            // makes third entry in col opposite color to preceding two entries
            if ((i - 1) >= 0 && board[i - 1][col] == UNKNOWN) {
                mark_square_as(board, size, i - 1, col,
                               opposite_color, announce);
            }
            // makes third entry in col opposite color to following two entries
            if ((i + 2) < size && board[i + 2][col] == UNKNOWN) {
                mark_square_as(board, size, i + 2, col,
                               opposite_color, announce);
            }
        }
        
        // makes middle entry in col opposite color to surrounding two entries
        if (i + 2 < size && board[i][col] == board[i + 2][col] &&
            board[i][col] != UNKNOWN) {

            int color = board[i][col];
            int opposite_color = 0;

            if (color == RED) {
                opposite_color = BLUE;
            }
            else {
                opposite_color = RED;
            }
            if (board[i + 1][col] == UNKNOWN) {
                mark_square_as(board, size, i + 1, col,
                               opposite_color, announce);
            }
        }
    }
    return;
}


void solve_balance_row(int board[MAX_SIZE][MAX_SIZE],
                       int size, int row, bool announce) {
    int count_red = 0;
    int count_blue = 0;

    for (int i = 0; i < size; ++i) {
        if (board[row][i] == RED) {
            ++count_red;
        }
        else if (board[row][i] == BLUE) {
            ++count_blue;
        }
    }

    // checks that half of row is red so it can make rest of row blue
    if (count_red == size / 2) {
        for (int i = 0; i < size; ++i) {
            if (board[row][i] == UNKNOWN) {
                mark_square_as(board, size, row, i, BLUE, announce);
            }
        }
    }
    // checks that half of row is a blue so it can make rest of row red
    else if (count_blue == size / 2) {
        for (int i = 0; i < size; ++i) {
            if (board[row][i] == UNKNOWN) {
                mark_square_as(board, size, row, i, RED, announce);
            }
        }
    }
    return;
}

void solve_balance_column(int board[MAX_SIZE][MAX_SIZE],
                          int size, int col, bool announce) {
    int count_red = 0;
    int count_blue = 0;

    for (int i = 0; i < size; ++i) {
        if (board[i][col] == RED) {
            ++count_red;
        }
        else if (board[i][col] == BLUE) {
            ++count_blue;
        }
    }

    // checks that half of column is red so it can make rest of column blue
    if (count_red == size / 2) {
        for (int i = 0; i < size; ++i) {
            if (board[i][col] == UNKNOWN) {
                mark_square_as(board, size, i, col, BLUE, announce);
            }
        }
    }
    // checks that half of column is blue so it can make rest of column red
    else if (count_blue == size / 2) {
        for (int i = 0; i < size; ++i) {
            if (board[i][col] == UNKNOWN) {
                mark_square_as(board, size, i, col, RED, announce);
            }
        }
    }
    return;
}


///////////////////////////////////////
// GAMEPLAY FUNCTIONS /////////////////
///////////////////////////////////////

bool board_is_solved(const int board[MAX_SIZE][MAX_SIZE], int size) {
    if (count_unknown_squares(board, size) != 0) {
        return false;
    }
    if (!board_is_valid(board, size)) {
        return false;
    }
    return true;
}

bool check_valid_input(int size, int row_input, char col_input,
    char color_char, int &row, int &col) {

    // checks that row input is a valid one
    if (row_input >= 1 && row_input <= size) {
        row = row_input - 1;
    }
    else {
        cout << "Sorry, that's not a valid input." << endl;
        return false;
    }

    // checks that column input is a valid one
    if (col_input >= 'A' && col_input <= ('A' + size - 1)) {
        col = col_input - 'A';
    }
    else if (col_input >= 'a' && col_input <= ('a' + size - 1)) {
        col = col_input - 'a';
    }
    else {
        cout << "Sorry, that's not a valid input." << endl;
        return false;
    }

    // lowercase letters are higher than uppercase equivalents
    const int CONVERT = 'a' - 'A';
    if (!(color_char == RED_LETTER || color_char == BLUE_LETTER ||
          color_char == UNKNOWN_LETTER || color_char == RED_LETTER + CONVERT ||
          color_char == BLUE_LETTER + CONVERT ||
          color_char == UNKNOWN_LETTER + CONVERT)) {

        cout << "Sorry, that's not a valid input." << endl;
        return false;
    }
    return true;
}

bool check_valid_move(const int original_board[MAX_SIZE][MAX_SIZE],
                      const int current_board[MAX_SIZE][MAX_SIZE],
                      int size, int row, int col, int color) {
    
    // reponds if player tries to change original squares
    if (original_board[row][col] != UNKNOWN) {
        cout << "Sorry, original squares cannot be changed." << endl;
        return false;
    }

    int new_board[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            new_board[i][j] = current_board[i][j];
        }
    }
    
    // responds if a move violates a rule
    new_board[row][col] = color;
    if (board_is_valid(new_board, size)) {
        return true;
    }
    else {
        cout << "Sorry, that move violates a rule." << endl;
        return false;
    }
}


///////////////////////////////////////
// S'MORE FUNCTIONS ///////////////////
///////////////////////////////////////


void solve_lookahead_row(int board[MAX_SIZE][MAX_SIZE],
                         int size,
                         int row,
                         bool announce) {
    // your code here
}

void solve_lookahead_column(int board[MAX_SIZE][MAX_SIZE],
                            int size,
                            int col,
                            bool announce) {
    // your code here
}
