#ifndef ORDENAR_DIALOG_H
#define ORDENAR_DIALOG_H

#include <QDialog>
#include <pantalla_mostrar.h>
#include <vector>

namespace Ui {
class ordenar_dialog;
}

class ordenar_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit ordenar_dialog(QWidget *parent = nullptr);
    ~ordenar_dialog();

    pantalla_mostrar objeto_mostrar;

    QStandardItemModel *model_venta = new QStandardItemModel;


    void mostrar_ordenar_encuestas();
    template <typename venta>
    void mostrar_ordenar_ventas(QList <venta>);
    void actualiza_listaVentaCopy();


private:
    Ui::ordenar_dialog *ui;

    void test_find();
    QList <venta> listaVentav1;
    QList <venta> listaVentaCopy;

    QList <encuesta> listaEncuestav1;

signals:
    void regresa_menu();

private slots:
    void on_pushButton_regresarMenu_clicked();
    void on_comboBox_ordenar_currentTextChanged(const QString &arg1);

    void recibe_listas_ordenar(QList<venta>, QList<encuesta>);
    void on_comboBox_ordenar_2_currentTextChanged(const QString &arg1);
};

#endif // ORDENAR_DIALOG_H
