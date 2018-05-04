#ifndef CONDUCTEUR_H
#define CONDUCTEUR_H

#include <QWidget>

namespace Ui {
class Conducteur;
}

class Conducteur : public QWidget
{
    Q_OBJECT

public:
    explicit Conducteur(QWidget *parent = 0);
    ~Conducteur();

private:
    Ui::Conducteur *ui;
};

#endif // CONDUCTEUR_H
