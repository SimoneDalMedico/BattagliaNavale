#include "cella.h"

cella::cella(unsigned short _x, unsigned short _y):x(_x), y(_y) {}

bool cella::operator==(const cella& v)
{
    if(this->x==v.x && this->y==v.y){
        return true;
    }
    return false;
}

unsigned short cella::ShowX()
{
  return x;
}

unsigned short cella::ShowY()
{
    return y;
}
