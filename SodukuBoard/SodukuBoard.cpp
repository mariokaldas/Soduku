//#include"SodukuBoard.hpp"
#include<math.h>


template<int SIZE>
SodukuBoard<SIZE>:: SodukuBoard(int puzzle[SIZE][SIZE]): subGrid({ {4,2},{9,3},{16,4},{25,5},{36,6} }){

    /* SIZE vectors */
    board.reserve(SIZE);
    for (int i = 0; i < SIZE; i++)
    {
        /* Copy every vector in the passed array into the soduku board */
        vector<int> row(puzzle[i], puzzle[i] + SIZE); 

        /* every vector has SIZE integers */
        board.push_back(row); 
    }

    /* SIZE vectors */
    this->puzzle.reserve(SIZE); 
    for (int i = 0; i < SIZE; i++)
    {
        vector<bool> row(SIZE,false);

        /* every vector has SIZE booleans */
        this->puzzle.push_back(row); 
    }

    /* make every empty cell in the puzzle board as true to check on later (save the original puzzle) */
    for(int row=0; row < SIZE; row++)
    {
        for(int col=0; col < SIZE; col++)
        {
            if(puzzle[row][col] == 0)
            {
                /* Iterating over original puzzle to mark the empty cells and occupied cells */
                this->puzzle.at(row).at(col) = true;
            }
        }
    }

}

template<int SIZE>
void SodukuBoard<SIZE>::show()
{


    for (int i = 0; i < SIZE; i++)
    {
        vector<int> row(board.at(i));

        if (i % subGrid.at(SIZE) == 0)
        {
            cout << "-----------------------------------------------" << endl;
        }

        for (int j = 0; j < SIZE; j++)
        {
            if (j % subGrid.at(SIZE) == 0 && j != 0)
            {
                cout << "| ";
            }

            if (row.at(j) == 0)
                cout << '.' << " ";

            else
                cout << row.at(j) << " ";
        }
        cout << endl;
    }
    cout << "-----------------------------------------------" << endl;
}

template<int SIZE>
void SodukuBoard<SIZE>::set_value(int row, int column, int value)
{
    /* Used by developer: no constrains applied */
    board.at(row).at(column) = value;
}

template<int SIZE>
int SodukuBoard<SIZE>::get_value(int row, int column)
{    
    return board.at(row).at(column);
}

template<int SIZE>
void SodukuBoard<SIZE>:: resetCell(int row, int column)
{
    board.at(row).at(column) = 0;
}

template<int SIZE>
bool SodukuBoard<SIZE>:: notOccupied(int row, int column)
{
    return puzzle.at(row-1).at(column-1);
}

template<int SIZE>
void SodukuBoard<SIZE>:: make_move(int row, int column, int value)
{
    int temp=0;

    if(row < 1 || row > SIZE){

        throw outOfRange_exception("Row MUST be integer in range 1-SIZE");
    }
    if(column < 1 || column > SIZE){

        throw outOfRange_exception("column MUST be integer in range 1-SIZE");
    }
    if(value < 1 || value > SIZE){

        throw outOfRange_exception("Value MUST be integer in range 1-SIZE");
    }
    if( this->notOccupied(row,column) != true){

        throw invalidMove_exception("Invalid move : The cell is already occupied");
    }

    /* Save previous value in case the current value violating soduku rules */
    temp = board.at(row - 1).at(column - 1);
    board.at(row - 1).at(column - 1) = value;

    if(validate_subGrid(row-1,column-1)!=true || validate_row(row-1)!=true || validate_column(column-1)!=true)
    {
        board.at(row - 1).at(column - 1) = temp;
        throw invalidMove_exception("Invalid move: This move violates soduku rules");
    }
}


template<int SIZE>
bool SodukuBoard<SIZE>::validate_row(int r)
{

    vector<int> ocuurance(SIZE+1, 0);
    int value;

    for (int col = 0; col < SIZE; col++)
    {
        value = get_value(r, col);
        if (value != 0)
        {
            ocuurance.at(value)++;
        }
    }

    for (const auto &element : ocuurance)
    {
        if (element > 1)
        {
            return false;
        }
    }
    return true;
}

template<int SIZE>
bool SodukuBoard<SIZE>::validate_column(int c)
{

    vector<int> ocuurance(SIZE+1, 0);
    int value;

    for (int row = 0; row < SIZE; row++)
    {
        value = get_value(row, c);
        if (value != 0)
        {
            ocuurance.at(value)++;
        }
    }

    for (const auto &element : ocuurance)
    {
        if (element > 1)
        {
            return false;
        }
    }
    return true;
}

template<int SIZE>
bool SodukuBoard<SIZE>::validate_subGrid(int r, int c)
{

    /* This shift use to iterate over the current subgrid */
    int row_shift = ((r / subGrid.at(SIZE)) * subGrid.at(SIZE));
    int col_shift = ((c / subGrid.at(SIZE)) * subGrid.at(SIZE));

    vector<int> ocuurance(SIZE+1, 0);
    int value;

    for (int row = 0; row < subGrid.at(SIZE); row++)
    {
        for (int col = 0; col < subGrid.at(SIZE); col++)
        {
            value = get_value((row + row_shift),(col + col_shift));
            if (value != 0)
            {
                ocuurance.at(value)++;
            }
        }
    }
    for (const auto &element : ocuurance)
    {
        if (element > 1)
        {
            return false;
        }
    }
    return true;

}