#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDesktopWidget>
#include <QIcon>
#include "bus.h"
#include "conducteur.h"
#include "reservation.h"
#include "voyage.h"

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

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
