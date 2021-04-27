#ifndef PANTALLA_MODIFICAR_H
#define PANTALLA_MODIFICAR_H

#include <QDialog>

namespace Ui {
class pantalla_modificar;
}

class pantalla_modificar : public QDialog
{
    Q_OBJECT

public:
    explicit pantalla_modificar(QWidget *parent = nullptr);
    ~pantalla_modificar();

private:
    Ui::pantalla_modificar *ui;
};

#endif // PANTALLA_MODIFICAR_H
