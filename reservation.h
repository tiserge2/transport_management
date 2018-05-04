#ifndef RESERVATION_H
#define RESERVATION_H

#include <QWidget>

namespace Ui {
class Reservation;
}

class Reservation : public QWidget
{
    Q_OBJECT

public:
    explicit Reservation(QWidget *parent = 0);
    ~Reservation();

private:
    Ui::Reservation *ui;
};

#endif // RESERVATION_H
