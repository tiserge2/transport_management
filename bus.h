#ifndef BUS_H
#define BUS_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QTableView>
#include <QMessageBox>
#include "basededonnee.h"

namespace Ui {
class Bus;
}

class Bus : public QWidget
{
    Q_OBJECT

public:
    explicit Bus(QString, QWidget *parent=0);
    ~Bus();
    void mettreChamp(QString, QString,QString,QString);

public slots:
    void insertData();
    void modifierData();
    void reinitialiserChampBus();

signals:
    void signalRafraichirVueBus(QString, QString, QString, QString);
    void signalEnleverLigne();

private:
    Ui::Bus *ui;
    BaseDeDonnee DB;
    QString plaqueAvantModif;
};

#endif // BUS_H
