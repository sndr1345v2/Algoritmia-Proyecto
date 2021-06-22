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

    QStandardItemModel *model_venta = new QStandardItemModel;
    QStandardItemModel *model_articulos = new QStandardItemModel;



    template <typename encuesta>
    void mostrar_ordenar_encuestas(QList <encuesta>);

    template <typename venta>
    void mostrar_ordenar_ventas(QList <venta>);

    template <typename articulo>
    void mostrar_ordenar_articulos(QList <articulo>);

    void actualiza_listaVentaCopy();
    void actualiza_listaEncuestaCopy();
    void actualiza_listaArticuloCopy();


private:
    Ui::ordenar_dialog *ui;

    void test_find();
    QList <venta> listaVentav1;
    QList <venta> listaVentaCopy;

    QList <encuesta> listaEncuestav1;
    QList <encuesta> listaEncuestaCopy;

    QList <articulo> listaArticulov1;
    QList <articulo> listaArticuloCopy;

signals:
    void regresa_menu();

private slots:
    void on_pushButton_regresarMenu_clicked();
    void on_comboBox_ordenar_currentTextChanged(const QString &arg1);
    void on_comboBox_ordenar_2_currentTextChanged(const QString &arg1);
    void on_comboBox_ordenar_3_currentTextChanged(const QString &arg1);

    void recibe_listas_ordenar(QList<venta>, QList<encuesta>, QList<articulo>);

};

#endif // ORDENAR_DIALOG_H
