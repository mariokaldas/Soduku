#include"SodukuSolver.hpp"

template<int SIZE>
SodukuSolver<SIZE>:: SodukuSolver(SodukuBoard<SIZE>& board):board(board){

    for(int r=0; r<SIZE; r++)
    {
        for(int c=0; c<SIZE; c++)
        {
            if(board.notOccupied(r+1,c+1) == true)
            {
                /* Save the dimention of every empty cell */
                emptyCells.insert({r,c});
            }
        }
    }
}

template<int SIZE>
void SodukuSolver<SIZE>::solve()
{

    /* To manipulate the current cell value */
    int value;

    /* This flag used to handle the first cell case (nit decrementing the iterator to be out of range) */
    bool flag = false;

    for(const auto& element: emptyCells)
    {
        /* Resets every modified cell by user to start from the beginning by the algorithm */
        board.resetCell(element.first,element.second);
    }

    /* Iterate over empty cells only */
    for(auto it=emptyCells.begin(); it != emptyCells.end(); it++)
    {
        /* Flag indicates that we need to modify first empty cell again */
        if(flag == true)
        {
            it = emptyCells.begin();
            flag = false;
        }

        value = board.get_value(it->first,it->second);

        /* If value reached the max : reset the cell and step back (two times as in the next iteration will be incremented) */
        if(value == SIZE)
        {
            board.resetCell(it->first,it->second);
            it--;

            /* If current iterator pointing at the first empty cell don't step back again */
            if(it == emptyCells.begin())
            {
                flag = true;
                continue;
            }

            it--;
            continue;
        }

        board.set_value(it->first, it->second, ++value);

        /* Increment cell value till it success all validation constrains */
        while(board.validate_subGrid(it->first,it->second)!=true || board.validate_row(it->first)!=true || board.validate_column(it->second)!=true)
        {
            if(value == SIZE)
            {
                board.resetCell(it->first,it->second);
                it--;
    
                if(it == emptyCells.begin())
                {
                    flag = true;
                    continue;
                }
    
                it--;
                break;
            }
            board.set_value(it->first, it->second, ++value);
        }
    }
    cout << "Puzzle solved successfully" << endl;
}
