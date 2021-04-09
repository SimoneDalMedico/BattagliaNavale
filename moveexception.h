#ifndef MOVEEXCEPTION_H
#define MOVEEXCEPTION_H
#include <stdexcept>
#include <string>

class MoveException: public std::runtime_error
{
public:
    MoveException(unsigned short int, unsigned short int);

private:
    unsigned short int x;
    unsigned short int y;
};

#endif // MOVEEXCEPTION_H
