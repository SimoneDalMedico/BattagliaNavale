#ifndef BUTTONB_H
#define BUTTONB_H
#include <QWidget>
#include <QPushButton>

class ButtonB : public QPushButton
{
    Q_OBJECT
public:
    ButtonB(unsigned short, unsigned short, QWidget* parent=nullptr);

signals:
    void clickedCell(unsigned short, unsigned short);
private:
    unsigned short x;
    unsigned short y;

private slots:
    void cellEmitter();
};

#endif // BUTTONB_H
