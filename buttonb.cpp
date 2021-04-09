#include "buttonb.h"

ButtonB::ButtonB(unsigned short X, unsigned short Y,QWidget* parent):QPushButton(parent), x(X), y(Y)
{
    connect(this,SIGNAL(clicked()),this,SLOT(cellEmitter()));
}

void ButtonB::cellEmitter()
{
    emit clickedCell(x,y);
}
