#include "bus.h"
#include "ui_bus.h"

Bus::Bus(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Bus)
{
    ui->setupUi(this);
}

Bus::~Bus()
{
    delete ui;
}
