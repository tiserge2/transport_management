#include "reservation.h"
#include "ui_reservation.h"

Reservation::Reservation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Reservation)
{
    ui->setupUi(this);
}

Reservation::~Reservation()
{
    delete ui;
}
