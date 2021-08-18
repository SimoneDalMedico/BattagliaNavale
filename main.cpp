#include <QApplication>
#include <iostream>
#include "vistaposizione.h"
#include "vistagioco.h"
#include "controller.h"
#include "modellogioco.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ModelloPosizione p;

    ModelloGioco g(&p);
    Controller c(&p, &g);
    VistaPosizione q(&c);


    c.setViewP(&q);


    vistaGioco vs(&c);




    c.setViewG(&vs);
    q.show();
    //c.resetGameP(); //DA ELIMINARE SE NN FUNZIA


    return a.exec();
}
