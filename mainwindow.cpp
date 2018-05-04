#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //center the window to the screen
    this->setGeometry(QStyle::alignedRect(
                          Qt::LeftToRight,
                          Qt::AlignCenter,
                          this->size(),
                          qApp->desktop()->availableGeometry()
                      ));
    //ajout des menus dans la barre de menu
    //ceci a ete fait dans design view

    //insertion des images dans le tabwidget
    //insere dans le design view

    //connection des boutons ajouter avec les slot permettant de
    //lancer les fenetres pour lajout d'informations dans la base
    connect(ui->boutonAjouterBus,SIGNAL(clicked(bool)),this,SLOT(actionBus()));
    connect(ui->boutonAjouterReservation,SIGNAL(clicked(bool)),this,SLOT(actionReservation()));
    connect(ui->boutonAjouterVoyage,SIGNAL(clicked(bool)),this,SLOT(actionVoyage()));
    connect(ui->boutonAjouterConducteur,SIGNAL(clicked(bool)),this,SLOT(actionConducteur()));

    //coonection des action dans les menus bar avec les slots
    //correspondants
    connect(ui->actionAjouter_Conducteur,SIGNAL(toggled(bool)),this,SLOT(actionConducteur()));
    connect(ui->actionAjouter_Reservation,SIGNAL(toggled(bool)),this,SLOT(actionReservation()));
    connect(ui->actionAjouter_Voyage,SIGNAL(toggled(bool)),this,SLOT(actionVoyage()));
    connect(ui->actionAjouter_Bus,SIGNAL(toggled(bool)),this,SLOT(actionBus()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::actionBus() {
    Bus *bus = new Bus;
    bus->setGeometry(QStyle::alignedRect(
                          Qt::LeftToRight,
                          Qt::AlignCenter,
                          bus->size(),
                          qApp->desktop()->availableGeometry()
                      ));
    bus->show();
}

void MainWindow::actionConducteur() {
    Conducteur *conducteur = new Conducteur;
    conducteur->setGeometry(QStyle::alignedRect(
                          Qt::LeftToRight,
                          Qt::AlignCenter,
                          conducteur->size(),
                          qApp->desktop()->availableGeometry()
                      ));
    conducteur->show();
}
void MainWindow::actionReservation() {
    Reservation *reservation = new Reservation;
    reservation->setGeometry(QStyle::alignedRect(
                          Qt::LeftToRight,
                          Qt::AlignCenter,
                          reservation->size(),
                          qApp->desktop()->availableGeometry()
                      ));
    reservation->show();
}

void MainWindow::actionVoyage() {
    Voyage *voyage = new Voyage;
    voyage->setGeometry(QStyle::alignedRect(
                          Qt::LeftToRight,
                          Qt::AlignCenter,
                          voyage->size(),
                          qApp->desktop()->availableGeometry()
                      ));
    voyage->show();
}
