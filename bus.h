#ifndef BUS_H
#define BUS_H

#include <QWidget>

namespace Ui {
class Bus;
}

class Bus : public QWidget
{
    Q_OBJECT

public:
    explicit Bus(QWidget *parent = 0);
    ~Bus();

private:
    Ui::Bus *ui;
};

#endif // BUS_H
