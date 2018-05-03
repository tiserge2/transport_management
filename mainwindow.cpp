#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ajout des menus dans la barre de menu
    //ceci a ete fait dans design view

    //insertion des images dans le tabwidget
    //insere dans le design view
}

MainWindow::~MainWindow()
{
    delete ui;
}
