#include "bus.h"
#include "ui_bus.h"
#include "basededonnee.h"

Bus::Bus(QString modeInsertion,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Bus)
{
    DB.connection();
    ui->setupUi(this);
    //nous allons ajouter les elements dans la list combo
    QStringList list=(QStringList()<<"Rouge"<<"Verte"<<"Bleue"<<"Noire"<<"Jaune"<<"Grise");
    ui->couleurBus->addItems(list);
//    information = new Information("Enregistrement reussi");
    //connection du bouton enregistrer bus
    if(modeInsertion == "MODIFICATION") {
        connect(ui->enregistrerBus, SIGNAL(clicked(bool)), this, SLOT(modifierData()));
    }
    if(modeInsertion == "INSERTION") {
        connect(ui->enregistrerBus,SIGNAL(clicked(bool)),this,SLOT(insertData()));
    }
    connect(ui->reinitialiserBus,SIGNAL(clicked(bool)),this,SLOT(reinitialiserChampBus()));
}

Bus::~Bus()
{   DB.deconnection();
    DB.removeConnection();
    delete ui;
}

void Bus::insertData() {
    QString marque = ui->marqueBus->text();
    QString plaque = ui->plaqueBus->text();
    QString couleur = ui->couleurBus->currentText();
    QString nombrePlace = ui->nombrePlaceBus->text();
    if(!marque.isEmpty() && !plaque.isEmpty()) {
        if(DB.insertDataBus(marque,plaque,couleur,nombrePlace)) {
            qDebug() << "Data inserted";
            QMessageBox::information(this, "Succes", "Enregistrement reussi.");
            // information->show();
            emit signalRafraichirVueBus(marque, plaque,couleur, nombrePlace);
            this->close();
        } else {
            qDebug() << "Data not inserted";
            QMessageBox::critical(this, "Erreur d'insertion", DB.getFeedbackMessage());
        }
    } else {
        QMessageBox::critical(this, "Insertion", "Ne doit contenir de champ vide.");
    }
}

void Bus::mettreChamp(QString marque,QString plaque,QString marque1,QString plaque1) {
    ui->marqueBus->setText(marque);
    ui->plaqueBus->setText(plaque);
    this->plaqueAvantModif = plaque;
}

void Bus::modifierData() {
    QString marque = ui->marqueBus->text();
    QString plaque = ui->plaqueBus->text();
    QString couleur = ui->couleurBus->currentText();
    QString nombrePlace = ui->nombrePlaceBus->text();
    if(!marque.isEmpty() && !plaque.isEmpty()) {
        if(DB.modifierDataBus(marque,plaque,couleur,nombrePlace,this->plaqueAvantModif)){
            qDebug() << "Data modification save successfully in the db";
            QMessageBox::information(this, "Reussite", "Votre donnee a ete modifiee avec succes.");
            emit signalEnleverLigne();
            this->close();
        }
    } else {
        QMessageBox::critical(this, "Insertion", "Ne doit contenir de champ vide.");
    }
}

void Bus::reinitialiserChampBus() {
    ui->marqueBus->setText("");
    ui->plaqueBus->setText("");
    //ui->nombrePlaceBus->set
}
