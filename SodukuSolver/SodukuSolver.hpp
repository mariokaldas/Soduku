#ifndef SODUKUSOLVER
#define SODUKUSOLVER

#include "../SodukuBoard/SodukuBoard.hpp"
#include <map>

template<int SIZE>
class SodukuSolver{

    private:

        /* This map holds the dimentions of all the empty cells (row,column) to iterate over the empty cells only easily */
        multimap<int,int> emptyCells;

        /* Reference for the soduku board */
        SodukuBoard<SIZE>& board;

    public:

        SodukuSolver(SodukuBoard<SIZE>& board);

        /* Solving algorithm */
        void solve();
    

};

#include"SodukuSolver.cpp"

#endif