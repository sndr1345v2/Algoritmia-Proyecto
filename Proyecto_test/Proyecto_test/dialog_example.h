#ifndef DIALOG_EXAMPLE_H
#define DIALOG_EXAMPLE_H

#include <QDialog>

namespace Ui {
class dialog_example;
}

class dialog_example : public QDialog
{
    Q_OBJECT

public:
    explicit dialog_example(QWidget *parent = nullptr);
    ~dialog_example();

private:
    Ui::dialog_example *ui;
};

#endif // DIALOG_EXAMPLE_H
