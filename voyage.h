#ifndef VOYAGE_H
#define VOYAGE_H

#include <QWidget>

namespace Ui {
class Voyage;
}

class Voyage : public QWidget
{
    Q_OBJECT

public:
    explicit Voyage(QWidget *parent = 0);
    ~Voyage();

private:
    Ui::Voyage *ui;
};

#endif // VOYAGE_H
