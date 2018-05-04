#include "conducteur.h"
#include "ui_conducteur.h"

Conducteur::Conducteur(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Conducteur)
{
    ui->setupUi(this);
}

Conducteur::~Conducteur()
{
    delete ui;
}
