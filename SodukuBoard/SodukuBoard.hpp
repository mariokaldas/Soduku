#ifndef SODUKUBOARD
#define SODUKUBOARD

#include <iostream>
#include <vector>
#include <algorithm>
#include<map>
#include "../Exceptions/Exceptions.hpp"

using namespace std;

template <int SIZE>
class SodukuBoard
{

private:

    /* This 2D vector hold the play board (soduku board) that have all interactions */
    vector<vector<int>> board;

    /* This 3D vector holds the original puzzle */
    vector<vector<bool>> puzzle;

    /* This map holds all the supported grid sizes and their subgrid sizes */
    map<int,int> subGrid;

public:
    SodukuBoard(int puzzle[SIZE][SIZE]);

    /* Print the soduku board */
    void show();

    /* This function wont't be called by user so the range is 0-8 */
    void set_value(int row, int column, int value);

    /* This function wont't be called by user so the range is 0-8 */
    int get_value(int row, int column);

    /* This function wont't be called by user so the range is 0-8 (used in backtrack algorithm) */
    void resetCell(int row, int column);

    /* This function will be called by user so the range is 1-9 */
    bool notOccupied(int row, int column);

    /* This function will be called by user so the range is 1-9 */
    void make_move(int row, int column, int value);

    /* Validate soduku rule (no repetitive numbers in same row) : no violation(true), violation detected(false) */
    bool validate_row(int r);

    /* Validate soduku rule (no repetitive numbers in same column) : no violation(true), violation detected(false) */
    bool validate_column(int c);

    /* Validate soduku rule (no repetitive numbers in same 3x3 subgrid) : no violation(true), violation detected(false) */
    bool validate_subGrid(int r, int c);
};

#include"SodukuBoard.cpp"

#endif 