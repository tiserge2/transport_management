#include "voyage.h"
#include "ui_voyage.h"

Voyage::Voyage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Voyage)
{
    ui->setupUi(this);
}

Voyage::~Voyage()
{
    delete ui;
}
