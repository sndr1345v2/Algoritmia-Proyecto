#ifndef MULTIUSOS_H
#define MULTIUSOS_H

#include <QDialog>

namespace Ui {
class multiusos;
}

class multiusos : public QDialog
{
    Q_OBJECT

public:
    explicit multiusos(QWidget *parent = nullptr);
    ~multiusos();

private:
    Ui::multiusos *ui;
};

#endif // MULTIUSOS_H
