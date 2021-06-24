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

private slots:
    void on_pushButton_5_clicked();

private:
    Ui::pantalla_registrar *ui;
signals:
    void regresar_menu();
};

#endif // PANTALLA_REGISTRAR_H
