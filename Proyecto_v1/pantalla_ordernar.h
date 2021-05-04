#ifndef PANTALLA_ORDERNAR_H
#define PANTALLA_ORDERNAR_H

#include <QDialog>

namespace Ui {
class pantalla_ordernar;
}

class pantalla_ordernar : public QDialog
{
    Q_OBJECT

public:
    explicit pantalla_ordernar(QWidget *parent = nullptr);
    ~pantalla_ordernar();

private:
    Ui::pantalla_ordernar *ui;
};

#endif // PANTALLA_ORDERNAR_H
