#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDesktopWidget>
#include <QIcon>
#include "bus.h"
#include "conducteur.h"
#include "reservation.h"
#include "voyage.h"
#include "QSqlTableModel"
#include <QSqlDatabase>
#include "basededonnee.h"
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void actionBus();
    void actionConducteur();
    void actionReservation();
    void actionVoyage();
    void retirerLigne();
    void start_timer();
    void stop_timer();
    void updateTableBus();

    void actionModifierBus();
    bool rafraichirVueBus(QString, QString, QString, QString);



private:
    Ui::MainWindow *ui;
    BaseDeDonnee DB;
    QSqlTableModel *modelBus;
    QSqlTableModel *modelVoyage;
    QSqlTableModel *modelConducteur;
    QSqlTableModel *modelReservation;
    Bus *bus;
    QTimer *updateInterval;

};

#endif // MAINWINDOW_H
