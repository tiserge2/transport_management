#include "mainwindow.h"
#include <QApplication>
#include <QSplashScreen>
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    //QSplashScreen *splash = new QSplashScreen;
//    splash->setPixmap(QPixmap(":/images/src/travelbus1.png"));
//    splash->show();
//    splash->setEnabled(false);
//    splash->showMessage("Bienvenue dans le gestionnaire de tranport...",Qt::AlignRight | Qt::AlignBottom | Qt::black);
//    QTimer::singleShot(5000,splash, SLOT(close()));
//    QTimer::singleShot(5000,&w, SLOT(show()));
    w.show();

    return a.exec();
}
