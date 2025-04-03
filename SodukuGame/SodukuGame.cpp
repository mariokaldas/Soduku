#include "SodukuGame.hpp"

template <int SIZE>
SodukuGame<SIZE>::SodukuGame(int puzzle[SIZE][SIZE]) : board(puzzle), solver(board)
{
    board.show();
}

template <int SIZE>
int SodukuGame<SIZE>::menu()
{
    cout << "1) Enter a move " << endl;
    cout << "2) Solve automatically " << endl;
    cout << "3) Load puzzle from file " << endl;
    cout << "4) Save current puzzle to file " << endl;
    cout << "5) Exit " << endl;

    try
    {
        takeInput();
    }
    catch (const Soduku_exceptions &e)
    {
        cout << endl;
        cout << e.what() << endl;
        cout << endl;
        return -1;
    }
    return 1;
}

template <int SIZE>
void SodukuGame<SIZE>::takeInput()
{
    cout << "Choice : ";
    cin >> this->userChoice;

    if (userChoice.length() == 1 && userChoice[0] >= '1' && userChoice[0] <= '5')
        ;

    else
    {
        throw menu_exception("Invalid input");
    }

    cout << endl;
}

template <int SIZE>
int SodukuGame<SIZE>::handleInput()
{
    switch (this->userChoice[0])
    {

    case '1':

        int r, c, val;

        cout << "SIZE: " << SIZE <<endl;
        switch (SIZE)
        {
        case 4:
            cout << "Enter row (1-4), column (1-4), and value (1-4) : ";
            break;

        case 9:
            cout << "Enter row (1-9), column (1-9), and value (1-9) : ";
            break;

        case 16:
            cout << "Enter row (1-16), column (1-16), and value (1-16) : ";
            break;

        case 25:
            cout << "Enter row (1-25), column (1-25), and value (1-25) : ";
            break;

        case 36:
            cout << "Enter row (1-36), column (1-36), and value (1-36) : ";
            break;

        default:
            break;
        }

        cin >> r >> c >> val;
        try
        {
            board.make_move(r, c, val);
            cout << endl;
            cout << "Move accepted" << endl;
        }
        catch (const Soduku_exceptions &e)
        {
            cout << endl;
            cout << e.what() << endl;
            cout << endl;
        }
        break;

    case '2':

        cout << "Solving automatically ..." << endl
             << endl;

        solver.solve();
        break;

    case '3':
        break;

    case '4':
        break;

    case '5':
        return 0;
        break;
    }

    board.show();
    return 1;
}
