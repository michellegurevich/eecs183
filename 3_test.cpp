/**
 * test.cpp
 *
 * EECS 183, Winter 2015
 * Project 3: 0h h1 Test Suite
 *
 * Michelle Gurevich, Ezra Lesser
 * mgur, elesser
 *
 * Tests the functions of ohhi.cpp to ensure the work correctly.
 */

#include <iostream>
#include <cassert>
#include "utility.h"
#include "ohhi.h"

void test_count_unknown_squares();
void test_solve_three_in_a_row();
void test_solve_three_in_a_column();
void test_solve_balance_row();
void test_solve_balance_column();
void test_board_has_no_duplicates();
void test_check_valid_input();
void test_check_valid_move();
void test_cols_are_different();
void test_row_has_no_threes_of_color();

const int board_0[][MAX_SIZE] = {
    {0,0,0,0},
    {1,1,0,0},
    {0,2,2,0},
    {0,0,2,0}
};

const int board_1[][MAX_SIZE] = {
    {1,2,2,1},
    {1,2,2,1},
    {0,0,0,0},
    {0,0,0,0}
};

const int board_rme6[][MAX_SIZE] = {
    {1,1,0,0},
    {2,2,0,0},
    {2,2,0,0},
    {1,1,0,0}
};

const int board_rme7[][MAX_SIZE] = {
    {1,1,0,0},
    {2,1,0,0},
    {2,2,0,0},
    {1,2,0,0}
};

const int board_rme8[][MAX_SIZE] = {
    {1,1,0,0},
    {2,2,0,0},
    {0,2,0,0},
    {1,1,0,0}
};

const int board_rme9[][MAX_SIZE] = {
    {1,1,0,0},
    {2,2,0,0},
    {0,2,0,0},
    {1,1,0,0}
};

const int board_rme10[][MAX_SIZE] = {
    {1,1,0,0},
    {2,2,0,0},
    {0,0,0,0},
    {1,1,0,0}
};

const int board_rme11[][MAX_SIZE] = {
    {2,2,0,0},
    {1,1,2,2},
    {1,1,2,0},
    {2,0,1,0}
};

const int board_rme12[][MAX_SIZE] = {
    {2,2,0,0},
    {1,1,2,2},
    {1,1,2,2},
    {2,0,2,0}
};

const int board_rme13[][MAX_SIZE] = {
    {1,2,2,1},
    {2,1,1,2},
    {1,2,1,2},
    {2,1,2,1}
};

const int board_rme14[][MAX_SIZE] = {
    {1,2,2,1},
    {2,1,1,2},
    {1,2,2,1},
    {2,1,2,1}
};

const int board_rme15[][MAX_SIZE] = {
    {1,2,2,1},
    {2,1,1,2},
    {1,2,1,1},
    {2,1,2,2}
};


int main() {
    test_count_unknown_squares();
    test_solve_three_in_a_row();
    test_solve_three_in_a_column();
    test_solve_balance_row();
    test_solve_balance_column();
    test_board_has_no_duplicates();
    test_check_valid_input();
    test_check_valid_move();
    test_cols_are_different();
    test_row_has_no_threes_of_color();

    return 0;
}


void test_count_unknown_squares() {
    cout << "Testing count_unknown_squares()" << endl;
    
    if (count_unknown_squares(board_0, 4) != 11) {
        cout << "Error: count_unknown_squares with board_0" << endl;
    }
    if (count_unknown_squares(board_0, 2) != 2) {
        cout << "Error: count_unknown_squares with board_0" << endl;
    }
    if (count_unknown_squares(board_1, 4) != 8) {
        cout << "End testing count_unknown_squares() with board_1" << endl << endl;
    }
    if (count_unknown_squares(board_1, 2) != 0) {
        cout << "End testing count_unknown_squares() with board_1" << endl << endl;
    }
}

// tests if the function solves three in a row
void test_solve_three_in_a_row() {
    cout << "testing solve_three_in_a_row()" << endl;
    
    int board_row[][MAX_SIZE] = {
        {2,2,0,0,0,0},
        {1,1,2,2,0,2},
        {1,2,1,2,0,0},
        {2,0,2,0,0,1},
        {2,1,1,2,1,0},
        {0,0,0,0,1,1}
    };
    
    for (int i = 0; i < 6; i++) {
        solve_three_in_a_row(board_row, 6, i, false);
    }

    print_board(board_row, 6);
}

// tests if the function solves three in a column
void test_solve_three_in_a_column() {
    cout << "testing solve_three_in_a_column()" << endl;
    
    int board_col[][MAX_SIZE] = {
        {2,0,0,0,1,0},
        {1,0,2,2,1,0},
        {1,0,1,2,0,1},
        {2,0,2,0,0,0},
        {0,1,0,1,0,0},
        {0,1,2,0,0,0}
    };
    
    for (int j = 0; j < 6; j++) {
        solve_three_in_a_column(board_col, 6, j, false);
    }

    print_board(board_col, 6);
}

// tests if the function fills the rest of a row with the necessary color
void test_solve_balance_row() {
    cout << "testing solve_balance_row()" << endl;
    
    int board_row[][MAX_SIZE] = {
        {2,2,0,0,0,0},
        {1,1,2,2,0,2},
        {1,2,1,2,0,0},
        {2,0,2,0,2,1},
        {2,1,1,2,1,2},
        {0,0,0,0,1,1}
    };
    
    for (int i = 0; i < 6; i++) {
        solve_balance_row(board_row, 6, i, false);
    }

    print_board(board_row, 6);
}

// tests if the function fills the rest of a column with the necessary color
void test_solve_balance_column() {
    cout << "testing solve_balance_column()" << endl;
    
    int board_col[][MAX_SIZE] = {
        {2,0,0,0,1,1},
        {1,0,2,2,1,0},
        {1,0,1,2,0,1},
        {2,0,2,0,0,0},
        {1,1,0,1,0,0},
        {2,1,2,2,0,1}
    };
    
    for (int j = 0; j < 6; j++) {
        solve_balance_column(board_col, 6, j, false);
    }

    print_board(board_col, 6);
}

// tests if various boards contain duplicate rows or columns
void test_board_has_no_duplicates() {
    cout << "testing board_has_no_duplicates()" << endl;
    
    if (!board_has_no_duplicates(board_rme11, 4))
        cout << "error: rme 11 should return true";
    if (board_has_no_duplicates(board_rme12, 4))
        cout << "error: rme 12 should return false";
    if (!board_has_no_duplicates(board_rme13, 4))
        cout << "error: rme 11 should return true";
    if (board_has_no_duplicates(board_rme14, 4))
        cout << "error: rme 12 should return false";
    if (board_has_no_duplicates(board_rme15, 4))
        cout << "error: rme 12 should return false";
}

// test if various inputs are registered as valid
void test_check_valid_input() {
    cout << "testing check_valid_input()" << endl;
    
    int row = 2;
    int col = 2;
    assert(check_valid_input(4, 1, 'A', 'o', row, col) == true);
    assert(check_valid_input(4, 1, 'a', 'O', row, col) == true);
    assert(check_valid_input(4, 2, 'a', '-', row, col) == true);
    assert(check_valid_input(4, 1, '!', 'o', row, col) == false);
    assert(check_valid_input(4, 1, 'B', 'X', row, col) == true);
    assert(check_valid_input(4, 1, 'D', 'x', row, col) == true);
    assert(check_valid_input(4, 1, 'd', 'X', row, col) == true);
    assert(check_valid_input(4, 5, 'B', 'x', row, col) == false);
    assert(check_valid_input(4, 4, 'E', 'x', row, col) == false);
    assert(check_valid_input(6, 0, 'E', 'x', row, col) == false);
    assert(check_valid_input(6, 4, 'E', 'r', row, col) == false);
    assert(check_valid_input(6, 4, 'E', 'b', row, col) == false);
    assert(check_valid_input(6, 4, 'E', 'R', row, col) == false);
    assert(check_valid_input(6, 4, 'E', 'B', row, col) == false);
    assert(check_valid_input(4, 3, 'd', 'O', row, col) == true);
    assert(check_valid_input(6, 4, 'E', '0', row, col) == false);
    assert(check_valid_input(6, 4, 'E', 0, row, col) == false);
    assert(check_valid_input(6, 4, 'E', '1', row, col) == false);
    assert(check_valid_input(6, 4, 'E', '2', row, col) == false);
}

// tests if various moves are valid ones
void test_check_valid_move() {
    cout << "testing check_valid_move()" << endl;
    
    int board_original[][MAX_SIZE] = {
        {2,2,0,0,0,0},
        {1,1,2,2,0,2},
        {1,2,1,2,0,0},
        {2,0,0,0,2,1},
        {2,1,1,2,1,2},
        {0,0,0,0,1,1}
    };

    int board_current[][MAX_SIZE] = {
        {2,2,0,0,0,0},
        {1,1,2,2,0,2},
        {1,2,1,2,0,0},
        {2,0,2,0,2,1},
        {2,1,1,2,1,2},
        {0,0,0,0,1,1}
    };
    
    if (check_valid_move(board_original, board_current, 6, 0, 1, RED)) {
        cout << "error: changed original tile" << endl;
    }
    if (!check_valid_move(board_original, board_current, 6, 0, 2, RED)) {
        cout << "error: did not change original title" << endl;
    }
    if (check_valid_move(board_original, board_current, 6, 1, 5, BLUE)) {
        cout << "error: wrong color" << endl;
    }
    if (!check_valid_move(board_original, board_current, 6, 1, 5, RED)) {
        cout << "error: was right color" << endl;
    }
    if (!check_valid_move(board_original, board_current, 6, 3, 2, RED)) {
        cout << "error: was valid move" << endl;
    }
}

// tests whether function returns correctly for columns being different or same
void test_cols_are_different() {
    cout << "testing cols_are_different()" << endl;
    
    if (cols_are_different(board_rme6, 4, 0, 1)) {
        cout << "error: rme 6 rows 0,1 should return false";
    }
    if (!cols_are_different(board_rme7, 4, 0, 1)) {
        cout << "error: rme 7 rows 0,1 should return true";
    }
    if (!cols_are_different(board_rme8, 4, 0, 1)) {
        cout << "error: rme 8 rows 0,1 should return true";
    }
    if (!cols_are_different(board_rme9, 4, 2, 3)) {
        cout << "error: rme 9 rows 2,3 should return true";
    }
    if (!cols_are_different(board_rme10, 4, 0, 1)) {
        cout << "error: rme 10 rows 0,1 should return true";
    }
}

// tests if function correctly checks for row containing no threes of one color
void test_row_has_no_threes_of_color() {
    cout << "testing row_has_no_threes_of_color()" << endl;

    const int board_0[][MAX_SIZE] = {
        {2,0},
        {2,2}
    };
    
    assert(row_has_no_threes_of_color(board_0, 2, 1, RED) == true);
    assert(row_has_no_threes_of_color(board_0, 2, 1, BLUE) == true);
    assert(row_has_no_threes_of_color(board_0, 2, 1, UNKNOWN) == true);
    
    assert(row_has_no_threes_of_color(board_0, 2, 0, RED) == true);
    assert(row_has_no_threes_of_color(board_0, 2, 0, BLUE) == true);
    assert(row_has_no_threes_of_color(board_0, 2, 0, UNKNOWN) == true);
    
    const int board_1[][MAX_SIZE] = {
        {2,0,2,1},
        {2,2,2,0},
        {0,2,2,0},
        {0,2,0,0}
    };

    assert(row_has_no_threes_of_color(board_1, 4, 3, RED) == true);
    assert(row_has_no_threes_of_color(board_1, 4, 3, BLUE) == true);
    assert(row_has_no_threes_of_color(board_1, 4, 3, UNKNOWN) == true);
    
    assert(row_has_no_threes_of_color(board_1, 4, 2, RED) == true);
    assert(row_has_no_threes_of_color(board_1, 4, 2, BLUE) == true);
    assert(row_has_no_threes_of_color(board_1, 4, 2, UNKNOWN) == true);
    
    assert(row_has_no_threes_of_color(board_1, 4, 1, RED) == true);
    assert(row_has_no_threes_of_color(board_1, 4, 1, BLUE) == false);
    assert(row_has_no_threes_of_color(board_1, 4, 1, UNKNOWN) == true);
    
    assert(row_has_no_threes_of_color(board_1, 4, 0, RED) == true);
    assert(row_has_no_threes_of_color(board_1, 4, 0, BLUE) == true);
    assert(row_has_no_threes_of_color(board_1, 4, 0, UNKNOWN) == true);
    
    const int board_2[][MAX_SIZE] = {
        {2,0,2,1,1,1},
        {2,2,2,0,0,0},
        {1,2,2,1,1,1},
        {0,2,0,0,0,0},
        {0,0,0,0,0,0},
        {0,0,0,0,0,0}
    };
    
    assert(row_has_no_threes_of_color(board_2, 6, 5, RED) == true);
    assert(row_has_no_threes_of_color(board_2, 6, 5, BLUE) == true);
    assert(row_has_no_threes_of_color(board_2, 6, 5, UNKNOWN) == false);
    
    assert(row_has_no_threes_of_color(board_2, 6, 4, RED) == true);
    assert(row_has_no_threes_of_color(board_2, 6, 4, BLUE) == true);
    assert(row_has_no_threes_of_color(board_2, 6, 4, UNKNOWN) == false);

    assert(row_has_no_threes_of_color(board_2, 6, 3, RED) == true);
    assert(row_has_no_threes_of_color(board_2, 6, 3, BLUE) == true);
    assert(row_has_no_threes_of_color(board_2, 6, 3, UNKNOWN) == false);
    
    assert(row_has_no_threes_of_color(board_2, 6, 2, RED) == false);
    assert(row_has_no_threes_of_color(board_2, 6, 2, BLUE) == true);
    assert(row_has_no_threes_of_color(board_2, 6, 2, UNKNOWN) == true);
    
    assert(row_has_no_threes_of_color(board_2, 6, 1, RED) == true);
    assert(row_has_no_threes_of_color(board_2, 6, 1, BLUE) == false);
    assert(row_has_no_threes_of_color(board_2, 6, 1, UNKNOWN) == false);
    
    assert(row_has_no_threes_of_color(board_2, 6, 0, RED) == false);
    assert(row_has_no_threes_of_color(board_2, 6, 0, BLUE) == true);
    assert(row_has_no_threes_of_color(board_2, 6, 0, UNKNOWN) == true);
    
    const int board_3[][MAX_SIZE] = {
        {2,2},
        {2,2}
    };
    
    assert(row_has_no_threes_of_color(board_3, 2, 0, RED) == true);
    assert(row_has_no_threes_of_color(board_3, 2, 1, RED) == true);
    
    assert(row_has_no_threes_of_color(board_3, 2, 0, BLUE) == true);
    assert(row_has_no_threes_of_color(board_3, 2, 1, BLUE) == true);
    
    assert(row_has_no_threes_of_color(board_3, 2, 0, UNKNOWN) == true);
    assert(row_has_no_threes_of_color(board_3, 2, 1, UNKNOWN) == true);

    const int board_4[][MAX_SIZE] = {
        {2,2,2,2},
        {2,2,2,2},
        {2,2,2,2},
        {2,2,2,2}
    };
    
    assert(row_has_no_threes_of_color(board_4, 2, 0, RED) == true);
    assert(row_has_no_threes_of_color(board_4, 2, 1, RED) == true);
    assert(row_has_no_threes_of_color(board_4, 2, 2, RED) == true);
    assert(row_has_no_threes_of_color(board_4, 2, 3, RED) == true);
    
    assert(row_has_no_threes_of_color(board_4, 2, 0, BLUE) == true);
    assert(row_has_no_threes_of_color(board_4, 2, 1, BLUE) == true);
    assert(row_has_no_threes_of_color(board_4, 2, 2, BLUE) == true);
    assert(row_has_no_threes_of_color(board_4, 2, 3, BLUE) == true);
    
    assert(row_has_no_threes_of_color(board_4, 2, 0, UNKNOWN) == true);
    assert(row_has_no_threes_of_color(board_4, 2, 1, UNKNOWN) == true);
    assert(row_has_no_threes_of_color(board_4, 2, 2, UNKNOWN) == true);
    assert(row_has_no_threes_of_color(board_4, 2, 3, UNKNOWN) == true);

    const int board_5[][MAX_SIZE] = {
        {1,2,0,0,0,1},
        {0,0,0,0,0,2},
        {0,0,0,0,0,0},
        {0,0,0,0,0,0},
        {0,0,0,0,0,0},
        {0,0,0,0,0,1}
    };

    assert(row_has_no_threes_of_color(board_5, 2, 0, RED) == true);
    assert(row_has_no_threes_of_color(board_5, 2, 1, RED) == true);
    assert(row_has_no_threes_of_color(board_5, 2, 2, RED) == true);
    assert(row_has_no_threes_of_color(board_5, 2, 3, RED) == true);
    assert(row_has_no_threes_of_color(board_5, 2, 4, RED) == true);
    assert(row_has_no_threes_of_color(board_5, 2, 4, RED) == true);

    assert(row_has_no_threes_of_color(board_5, 2, 0, BLUE) == true);
    assert(row_has_no_threes_of_color(board_5, 2, 1, BLUE) == true);
    assert(row_has_no_threes_of_color(board_5, 2, 2, BLUE) == true);
    assert(row_has_no_threes_of_color(board_5, 2, 3, BLUE) == true);
    assert(row_has_no_threes_of_color(board_5, 2, 4, BLUE) == true);
    assert(row_has_no_threes_of_color(board_5, 2, 4, BLUE) == true);

    assert(row_has_no_threes_of_color(board_5, 2, 0, UNKNOWN) == true);
    assert(row_has_no_threes_of_color(board_5, 2, 1, UNKNOWN) == true);
    assert(row_has_no_threes_of_color(board_5, 2, 2, UNKNOWN) == true);
    assert(row_has_no_threes_of_color(board_5, 2, 3, UNKNOWN) == true);
    assert(row_has_no_threes_of_color(board_5, 2, 4, UNKNOWN) == true);
    assert(row_has_no_threes_of_color(board_5, 2, 5, UNKNOWN) == true);
    
    const int board_26[][MAX_SIZE] = {
        {1, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {1, 0, 1, 0, 0, 1},
        {0, 0, 0, 0, 0, 2},
        {0, 2, 0, 2, 0, 1},
        {0, 0, 1, 1, 0, 2}
    };
    for (int i = 0; i < 6; ++i) {
        assert(row_has_no_threes_of_color(board_26, 6, i, RED));
        assert(row_has_no_threes_of_color(board_26, 6, i, BLUE));
    }
    assert(row_has_no_threes_of_color(board_26, 6, 0, UNKNOWN));
    assert(!row_has_no_threes_of_color(board_26, 6, 1, UNKNOWN));
    assert(row_has_no_threes_of_color(board_26, 6, 2, UNKNOWN));
    assert(!row_has_no_threes_of_color(board_26, 6, 3, UNKNOWN));
    assert(row_has_no_threes_of_color(board_26, 6, 4, UNKNOWN));
    assert(row_has_no_threes_of_color(board_26, 6, 5, UNKNOWN));
    
    const int board_28[][MAX_SIZE] = {
        {0, 1, 0, 0, 0, 2, 0, 0},
        {0, 2, 0, 0, 2, 0, 0, 1},
        {0, 2, 0, 0, 1, 0, 2, 0},
        {0, 1, 2, 2, 1, 0, 0, 0},
        {0, 1, 0, 0, 2, 0, 0, 0},
        {1, 2, 2, 1, 0, 0, 2, 1},
        {0, 1, 0, 0, 0, 0, 1, 0},
        {0, 1, 0, 0, 0, 0, 2, 0}
    };
    for (int i = 0; i < 8; ++i) {
        assert(row_has_no_threes_of_color(board_28, 8, i, RED));
        assert(row_has_no_threes_of_color(board_28, 8, i, BLUE));
    }
    assert(!row_has_no_threes_of_color(board_28, 8, 0, UNKNOWN));
    assert(row_has_no_threes_of_color(board_28, 8, 1, UNKNOWN));
    assert(row_has_no_threes_of_color(board_28, 8, 2, UNKNOWN));
    assert(!row_has_no_threes_of_color(board_28, 8, 3, UNKNOWN));
    assert(!row_has_no_threes_of_color(board_28, 8, 4, UNKNOWN));
    assert(row_has_no_threes_of_color(board_28, 8, 5, UNKNOWN));
    assert(!row_has_no_threes_of_color(board_28, 8, 6, UNKNOWN));
    assert(!row_has_no_threes_of_color(board_28, 8, 7, UNKNOWN));
    
    const int board_29[][MAX_SIZE] = {
        {2, 0, 1, 0},
        {0, 2, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 1, 2}
    };
    for (int i = 0; i < 4; ++i) {
        assert(row_has_no_threes_of_color(board_29, 4, i, RED));
        assert(row_has_no_threes_of_color(board_29, 4, i, BLUE));
        assert(row_has_no_threes_of_color(board_29, 4, i, UNKNOWN));
    }
    
    const int board_30[][MAX_SIZE] = {
        {2, 2, 2, 1},
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0}
    };
    for (int i = 0; i < 4; ++i) {
        assert(row_has_no_threes_of_color(board_30, 4, i, RED));
    }
    assert(!row_has_no_threes_of_color(board_30, 4, 0, BLUE));
    assert(row_has_no_threes_of_color(board_30, 4, 1, BLUE));
    assert(row_has_no_threes_of_color(board_30, 4, 2, BLUE));
    assert(row_has_no_threes_of_color(board_30, 4, 3, BLUE));
    assert(row_has_no_threes_of_color(board_30, 4, 0, UNKNOWN));
    assert(!row_has_no_threes_of_color(board_30, 4, 1, UNKNOWN));
    assert(row_has_no_threes_of_color(board_30, 4, 2, UNKNOWN));
    assert(row_has_no_threes_of_color(board_30, 4, 3, UNKNOWN));
    
    const int board_33[][MAX_SIZE] = {
        {1, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 1},
        {0, 0, 2, 0, 0, 1},
        {0, 0, 2, 0, 0, 0},
        {1, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0}
    };
    for (int i = 0; i < 6; ++i) {
        assert(row_has_no_threes_of_color(board_33, 6, i, RED));
        assert(row_has_no_threes_of_color(board_33, 6, i, BLUE));
    }
    assert(!row_has_no_threes_of_color(board_33, 6, 0, UNKNOWN));
    assert(!row_has_no_threes_of_color(board_33, 6, 1, UNKNOWN));
    assert(row_has_no_threes_of_color(board_33, 6, 2, UNKNOWN));
    assert(!row_has_no_threes_of_color(board_33, 6, 3, UNKNOWN));
    assert(!row_has_no_threes_of_color(board_33, 6, 4, UNKNOWN));
    assert(!row_has_no_threes_of_color(board_33, 6, 5, UNKNOWN));
    
    const int board_34[][MAX_SIZE] = {
        {2, 0, 1, 2, 0, 1, 0, 2},
        {1, 0, 0, 0, 2, 2, 0, 0},
        {2, 0, 2, 0, 0, 1, 0, 2},
        {1, 2, 1, 0, 0, 0, 2, 1},
        {0, 0, 2, 0, 0, 1, 0, 0},
        {1, 2, 0, 0, 0, 2, 0, 0},
        {1, 1, 2, 2, 1, 0, 0, 2},
        {2, 0, 0, 2, 0, 1, 0, 0}
    };
    for (int i = 0; i < 8; ++i) {
        assert(row_has_no_threes_of_color(board_34, 8, i, RED));
        assert(row_has_no_threes_of_color(board_34, 8, i, BLUE));
    }
    assert(row_has_no_threes_of_color(board_34, 8, 0, UNKNOWN));
    assert(!row_has_no_threes_of_color(board_34, 8, 1, UNKNOWN));
    assert(row_has_no_threes_of_color(board_34, 8, 2, UNKNOWN));
    assert(!row_has_no_threes_of_color(board_34, 8, 3, UNKNOWN));
    assert(row_has_no_threes_of_color(board_34, 8, 4, UNKNOWN));
    assert(!row_has_no_threes_of_color(board_34, 8, 5, UNKNOWN));
    assert(row_has_no_threes_of_color(board_34, 8, 6, UNKNOWN));
    assert(row_has_no_threes_of_color(board_34, 8, 7, UNKNOWN));
}