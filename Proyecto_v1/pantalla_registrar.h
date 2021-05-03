#ifndef PANTALLA_REGISTRAR_H
#define PANTALLA_REGISTRAR_H

#include <QDialog>

namespace Ui {
class pantalla_registrar;
}

class pantalla_registrar : public QDialog
{
    Q_OBJECT

public:
    explicit pantalla_registrar(QWidget *parent = nullptr);
    ~pantalla_registrar();

private:
    Ui::pantalla_registrar *ui;
};

#endif // PANTALLA_REGISTRAR_H
