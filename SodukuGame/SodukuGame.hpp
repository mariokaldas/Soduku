#ifndef SODUKUGAME
#define SODUKUGAME

#include "../SodukuBoard/SodukuBoard.hpp"
#include "../SodukuSolver/SodukuSolver.hpp"
#include <map>

template<int SIZE>
class SodukuGame{

    private:
        SodukuBoard<SIZE> board;
        SodukuSolver<SIZE> solver;

        /* It's string to easily detect invalid input (if not integer) */
        string userChoice;

    public:

        SodukuGame(int puzzle [SIZE][SIZE]);

        /* Print the options menu returns: true(valid input), false(invalid input) */
        int menu();

        /* Handles the user input returns: true(Accepted move or catched exception), false(Exit game) */
        int handleInput();

        /* Take input from user and detect the invalid input */
        void takeInput();
};

#include"SodukuGame.cpp"

#endif
