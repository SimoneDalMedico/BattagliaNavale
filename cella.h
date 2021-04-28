#ifndef CELLA_H
#define CELLA_H


class cella
{
private:
    unsigned short int x;
    unsigned short int y;
public:
    cella() =default;
    ~cella()=default;
    cella(unsigned short int, unsigned short int);
    unsigned short int ShowX();
    unsigned short int ShowY();
};

#endif // CELLA_H
