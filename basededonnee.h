#ifndef BASEDEDONNEE_H
#define BASEDEDONNEE_H
#include <QSqlDatabase>
#include <QDir>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QList>

class BaseDeDonnee
{
public:
    BaseDeDonnee();
    ~BaseDeDonnee();
    QSqlDatabase getDB();
    //void setDB(QSqlDatabase);
    bool connection();
    void removeConnection();
    void deconnection();
    bool insertDataBus(QString, QString, QString, QString);
    bool modifierDataBus(QString,QString,QString,QString,QString);
    QString getFeedbackMessage();
    void setFeedbackMessage(QString);
private:
    QSqlDatabase db;
    QString message;
};

#endif // BASEDEDONNEE_H
