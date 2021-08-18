#ifndef CELLA_H
#define CELLA_H


class cella
{
private:
    unsigned short x;
    unsigned short y;
public:
    cella() =default;
    ~cella()=default;
    cella(unsigned short, unsigned short);
    bool operator==(const cella&);
    unsigned short ShowX();
    unsigned short ShowY();
};

#endif // CELLA_H
