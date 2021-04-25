#include "cella.h"

cella::cella(unsigned short _x, unsigned short _y)
{
    x=_x;
    y=_y;
}

unsigned short cella::ShowX()
{
  return x;
}

unsigned short cella::ShowY()
{
    return y;
}
