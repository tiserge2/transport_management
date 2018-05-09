#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTableView>
#include <QtSql/QSqlTableModel>
#include <QtSql/QtSql>
#include <QtSql/QSqlQuery>

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
    updateInterval = new QTimer(this);

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

    connect(ui->boutonModifierBus,SIGNAL(clicked(bool)),this, SLOT(actionModifierBus()));

    //connection avec la base de donnee
    //1-connection avec la base de donnee
    if(DB.connection()){
        ui->statusBar->showMessage("La base de donnee a ete ouverte avec succes.");
    } else {
        ui->statusBar->showMessage("Erreur de connection avec la base de donnee");
    }

    //2-Gestion des models et des vues

    //Gestion du model de bus
    //QSqlDatabase database;
    //DB.setDB(database);
    modelBus = new QSqlTableModel(this, DB.getDB());
    modelBus->setTable("bus");
    modelBus->setEditStrategy(QSqlTableModel::OnManualSubmit);
    modelBus->select();
    modelBus->setHeaderData(0, Qt::Horizontal, tr("Plaque Bus"));
    modelBus->setHeaderData(1, Qt::Horizontal, tr("Marque"));
    modelBus->setHeaderData(2, Qt::Horizontal, tr("Couleur"));
    modelBus->setHeaderData(3, Qt::Horizontal, tr("Nombre de place"));
    //Gestion  de la vue de bus
    ui->tableViewBus->setModel(modelBus);
    ui->tableViewBus->setAlternatingRowColors(true);
    ui->tableViewBus->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableViewBus->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableViewBus->verticalHeader()->setVisible(false);
    ui->tableViewBus->horizontalHeader()->setStretchLastSection(true);
    ui->tableViewBus->show();

    //Gestion du model de voyage
    modelVoyage = new QSqlTableModel(this, DB.getDB());
    modelVoyage->setTable("voyage");
    modelVoyage->setEditStrategy(QSqlTableModel::OnManualSubmit);
    modelVoyage->select();
    modelVoyage->setHeaderData(0, Qt::Horizontal, tr("ID Voyage"));
    modelVoyage->setHeaderData(1, Qt::Horizontal, tr("Plaque Bus"));
    modelVoyage->setHeaderData(2, Qt::Horizontal, tr("CIN conducteur"));
    modelVoyage->setHeaderData(3, Qt::Horizontal, tr("Date Voyage"));
    modelVoyage->setHeaderData(4, Qt::Horizontal, tr("Heure Voyage"));
    modelVoyage->setHeaderData(5, Qt::Horizontal, tr("Prix Voyage"));
    modelVoyage->setHeaderData(6, Qt::Horizontal, tr("Point de Depart"));
    modelVoyage->setHeaderData(7, Qt::Horizontal, tr("Point d'arrivee"));
    modelVoyage->setHeaderData(8, Qt::Horizontal, tr("Etat"));
    //Gestion  de la vue de bus
    ui->tableViewVoyage->setModel(modelVoyage);
    ui->tableViewVoyage->setAlternatingRowColors(true);
    ui->tableViewVoyage->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableViewVoyage->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableViewVoyage->verticalHeader()->setVisible(false);
    ui->tableViewVoyage->horizontalHeader()->setStretchLastSection(true);
    ui->tableViewVoyage->show();

    //Gestion du model du conducteur
    modelConducteur = new QSqlTableModel(this, DB.getDB());
    modelConducteur->setTable("conducteur");
    modelConducteur->setEditStrategy(QSqlTableModel::OnManualSubmit);
    modelConducteur->select();
    modelConducteur->setHeaderData(0, Qt::Horizontal, tr("CIN "));
    modelConducteur->setHeaderData(1, Qt::Horizontal, tr("Nom"));
    modelConducteur->setHeaderData(2, Qt::Horizontal, tr("Prenom"));
    modelConducteur->setHeaderData(3, Qt::Horizontal, tr("Sexe"));
    modelConducteur->setHeaderData(4, Qt::Horizontal, tr("Statut"));
    modelConducteur->setHeaderData(5, Qt::Horizontal, tr("Groupe sanguin"));
    modelConducteur->setHeaderData(7, Qt::Horizontal, tr("Adresse"));
    //Gestion  de la vue de bus
    ui->tableViewConducteur->setModel(modelConducteur);
    ui->tableViewConducteur->setAlternatingRowColors(true);
    ui->tableViewConducteur->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableViewConducteur->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableViewConducteur->verticalHeader()->setVisible(false);
    ui->tableViewConducteur->horizontalHeader()->setStretchLastSection(true);
    ui->tableViewConducteur->show();

    //Gestion du model de reservation
    modelReservation = new QSqlTableModel(this, DB.getDB());
    modelReservation->setTable("reservation");
    modelReservation->setEditStrategy(QSqlTableModel::OnManualSubmit);
    modelReservation->select();
    modelReservation->setHeaderData(0, Qt::Horizontal, tr("CIN"));
    modelReservation->setHeaderData(1, Qt::Horizontal, tr("Nom"));
    modelReservation->setHeaderData(2, Qt::Horizontal, tr("Prenom"));
    modelReservation->setHeaderData(6, Qt::Horizontal, tr("Zone d'arrivee"));
    modelReservation->setHeaderData(7, Qt::Horizontal, tr("Adresse"));
    modelReservation->setHeaderData(8, Qt::Horizontal, tr("Telephone"));
    modelReservation->setHeaderData(9, Qt::Horizontal, tr("Groupe Sanguin"));
    modelReservation->setHeaderData(10, Qt::Horizontal, tr("Montant avance"));
    modelReservation->setHeaderData(11, Qt::Horizontal, tr("Monnaie"));
    //Gestion  de la vue de bus
    ui->tableViewReservation->setModel(modelReservation);
    ui->tableViewReservation->setAlternatingRowColors(true);
    ui->tableViewReservation->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableViewReservation->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableViewReservation->verticalHeader()->setVisible(false);
    ui->tableViewReservation->horizontalHeader()->setStretchLastSection(true);
    ui->tableViewReservation->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::actionBus() {
    DB.deconnection();
    DB.removeConnection();
    bus = new Bus("INSERTION");
    connect(bus,SIGNAL(signalRafraichirVueBus(QString,QString,QString,QString)), this, SLOT(rafraichirVueBus(QString,QString,QString,QString)));
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

bool MainWindow::rafraichirVueBus(QString marque, QString plaque, QString couleur, QString siege) {
    qDebug() << "We are in the refresh view function";
    if(modelBus->insertRow(0)) {
        modelBus->setData(modelBus->index(0,0), plaque);
        modelBus->setData(modelBus->index(0,1), marque);
        modelBus->setData(modelBus->index(0,2), couleur);
        modelBus->setData(modelBus->index(0,3), siege);
        if(modelBus->submitAll()) {
            qDebug() << "all data are set in the bus view";
        } else {
            qDebug() << "cannot set data in the bus view";
        }
    } else {
        qDebug() << "cannot insert new row";
    }
}

void MainWindow::actionModifierBus() {
    bus = new Bus("MODIFICATION");
    connect(bus,SIGNAL(signalRafraichirVueBus(QString,QString,QString,QString)), this, SLOT(rafraichirVueBus(QString,QString,QString,QString)));
    bus->setGeometry(QStyle::alignedRect(
                          Qt::LeftToRight,
                          Qt::AlignCenter,
                          bus->size(),
                          qApp->desktop()->availableGeometry()
                      ));
    if(ui->tableViewBus->selectionModel()->hasSelection()){
        QModelIndexList selection(ui->tableViewBus->selectionModel()->selectedIndexes());
        QVector <QVector <int> > dataIndexes;
        QVector < int > dataIndex;
        foreach (QModelIndex index, selection) {
            dataIndex.clear();
            dataIndex.push_back(index.row());
            dataIndex.push_back(index.column());
            dataIndexes.push_back(dataIndex);
            qDebug() << dataIndex;
        }

        QString plaque = ui->tableViewBus->model()->data(ui->tableViewBus->model()->index(dataIndexes.at(0).value(0),dataIndexes.at(0).value(1))).toString();
        QString marque = ui->tableViewBus->model()->data(ui->tableViewBus->model()->index(dataIndexes.at(1).value(0),dataIndexes.at(1).value(1))).toString();
        QString couleur = ui->tableViewBus->model()->data(ui->tableViewBus->model()->index(dataIndexes.at(2).value(0),dataIndexes.at(2).value(1))).toString();
        QString nombrePlace = ui->tableViewBus->model()->data(ui->tableViewBus->model()->index(dataIndexes.at(3).value(0),dataIndexes.at(3).value(1))).toString();
        qDebug() << plaque << marque << couleur << nombrePlace;
        bus->mettreChamp(marque, plaque,"","");
        qDebug() << dataIndexes.at(0).value(0);
        connect(bus,SIGNAL(signalEnleverLigne()), this, SLOT(start_timer()));
        connect(updateInterval,SIGNAL(timeout()),this,SLOT(updateTableBus()));
        connect(updateInterval,SIGNAL(timeout()), this, SLOT(stop_timer()));
        bus->show();
    } else {
        QMessageBox::critical(this, "Selection", "Il n'y a pas de ligne selectionner.");
    }
}

void MainWindow::retirerLigne() {
//    qDebug() << i;
    if(modelBus->removeRow(0)) {
        qDebug() << "row has been removed successfully";
    } else {
        qDebug() << "Cannot remove the row";
    }
}

void MainWindow::updateTableBus() {
    DB.connection();
    modelBus->select();
    ui->tableViewBus->reset();
}

void MainWindow::start_timer() {
    updateInterval->setInterval(100);
    updateInterval->start();
}

void MainWindow::stop_timer() {
    updateInterval->stop();
}
