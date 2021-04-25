#ifndef MENU_DIALOG_H
#define MENU_DIALOG_H

#include <QDialog>

namespace Ui {
class menu_dialog;
}

class menu_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit menu_dialog(QWidget *parent = nullptr);
    ~menu_dialog();

private:
    Ui::menu_dialog *ui;
};

#endif // MENU_DIALOG_H
