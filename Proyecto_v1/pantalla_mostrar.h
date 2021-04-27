#ifndef PANTALLA_MOSTRAR_H
#define PANTALLA_MOSTRAR_H

#include <QDialog>

namespace Ui {
class pantalla_mostrar;
}

class pantalla_mostrar : public QDialog
{
    Q_OBJECT

public:
    explicit pantalla_mostrar(QWidget *parent = nullptr);
    ~pantalla_mostrar();

private:
    Ui::pantalla_mostrar *ui;
};

#endif // PANTALLA_MOSTRAR_H
