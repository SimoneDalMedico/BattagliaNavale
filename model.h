#ifndef MODEL_H
#define MODEL_H
#include <string>
#include <stdexcept>
#include <map>
#include <cstdlib>
#include <stdlib.h>
#include "giocatore.h"
#include "computer.h"
#include "moveexception.h"
enum Player{none=0,playerG=1, playerC=2, playerMancata=3};

class Model
{
public:
    Model()=default;
    virtual void move(unsigned short int, unsigned short int) =0;
    virtual void reset() =0;


protected:

    Player grigliaComputer[100];
    Player grigliaGiocatore[100];
    bool turn = false;
};

#endif // MODEL_H
