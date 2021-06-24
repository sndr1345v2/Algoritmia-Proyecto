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

private slots:
    void on_btnIdArticulo_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::pantalla_modificar *ui;
signals:
    void regresar_menu();
};

#endif // PANTALLA_MODIFICAR_H
