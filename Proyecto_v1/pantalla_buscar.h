#ifndef PANTALLA_BUSCAR_H
#define PANTALLA_BUSCAR_H

#include <QDialog>

namespace Ui {
class pantalla_buscar;
}

class pantalla_buscar : public QDialog
{
    Q_OBJECT

public:
    explicit pantalla_buscar(QWidget *parent = nullptr);
    ~pantalla_buscar();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::pantalla_buscar *ui;

signals:
    void regresar_menu();

};

#endif // PANTALLA_BUSCAR_H
