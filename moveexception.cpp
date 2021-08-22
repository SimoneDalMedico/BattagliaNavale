#include "moveexception.h"

MoveException::MoveException(unsigned short int X, unsigned short int Y): std::runtime_error("Exception: la mossa in(" + std::to_string(X)+ ", " + std::to_string(Y) + ") non può essere eseguita"), x(X),y(Y){}
