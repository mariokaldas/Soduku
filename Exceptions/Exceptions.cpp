#include"Exceptions.hpp"

outOfRange_exception:: outOfRange_exception(string message):message(message){}

menu_exception:: menu_exception(string message):message(message){}

invalidMove_exception:: invalidMove_exception(string message):message(message){}

const char* outOfRange_exception:: what() const noexcept{

    return message.c_str();
}  

const char* menu_exception:: what() const noexcept{

    return message.c_str();
}  

const char* invalidMove_exception:: what() const noexcept{

    return message.c_str();
}  