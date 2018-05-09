#include "basededonnee.h"

BaseDeDonnee::BaseDeDonnee()
{
    //this->db = database;
    qDebug() << "Database object will be created";
}

BaseDeDonnee::~BaseDeDonnee() {
    qDebug() << "Database object will be removed";
    delete this;
}

bool BaseDeDonnee::connection() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("transportDataBase");
    return db.open();
}

void BaseDeDonnee::deconnection() {
    db.close();
    qDebug() << "La base de donnee a ete deconnecte...";
}

QSqlDatabase BaseDeDonnee::getDB(){
    return this->db;
}

bool BaseDeDonnee::insertDataBus(QString marque, QString plaque, QString couleur, QString siege) {
    if(this->connection()){
        //lets prepare the insert query
        QSqlQuery query(this->db);
        QString queryText("INSERT INTO bus(plaque_bus, marque,couleur,nombre_siege)"
                          "values(?, ?, ?, ?);");
        query.clear();
        query.prepare(queryText);
        query.addBindValue(plaque);
        query.addBindValue(marque);
        query.addBindValue(couleur);
        query.addBindValue(siege);
        if(query.exec()) {
            qDebug() << "Data has been inserted to db";
            this->deconnection();
            return true;
        } else {
            qDebug() << "Data cannot be inserted\n" << query.lastError().NoError;
            if(query.lastError().NoError == 0){
                this->setFeedbackMessage("Chaque plaque doit etre unique");
            }
            return false;
        }
    } else {
        qDebug() << "Cannot open Database";
        return false;
    }
}

void BaseDeDonnee::removeConnection() {
    qDebug() << "Old Database has been removed to the list of connection";
    this->db.removeDatabase("transportDataBase");
}

QString BaseDeDonnee::getFeedbackMessage() {
    return this->message;
}

void BaseDeDonnee::setFeedbackMessage(QString message) {
    this->message = message;
}

bool BaseDeDonnee::modifierDataBus(QString marque, QString plaque, QString couleur, QString siege, QString plaqueAncien) {
    if(this->connection()) {
        //lets prepare the modification query
        QSqlQuery query(this->db);
        QString queryText("UPDATE bus "
                          "SET plaque_bus = '"+ plaque+"', marque = '"+marque+"', couleur = '"+couleur+"', nombre_siege = '"+siege+"' WHERE plaque_bus= '"+plaqueAncien+"';");
        query.clear();
        //query.prepare(queryText);
        if(query.exec(queryText)) {
            qDebug() << "Data has been modified";
            this->deconnection();
            return true;
        } else {
            qDebug() << "Data cannot be modified" << query.lastError();
            return false;
        }
    } else {
        qDebug() << "Cannot connect to the databse";
        return false;
    }
}
