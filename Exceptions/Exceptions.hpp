
#include<iostream>

using namespace std;

class Soduku_exceptions : public exception{};

/* Thrown id the passed row or column exceeds the size of the grid */
class outOfRange_exception : public Soduku_exceptions{

    private:
        string message;

    public:
    outOfRange_exception(string message);
    const char* what() const noexcept override;  
};

/* Thrown in case of invalid input at option menu */
class menu_exception : public Soduku_exceptions{

    private:
        string message;

    public:
    menu_exception(string message);
    const char* what() const noexcept override;
};

/* Thrown in case of trying to overwrite occupied cells or violating soduku rules */
class invalidMove_exception : public Soduku_exceptions{

    private:
        string message;

    public:
    invalidMove_exception(string message);
    const char* what() const noexcept override;
};
