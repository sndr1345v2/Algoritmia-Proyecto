#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QObject>
#include <menu_dialog.h>

class principal : public QObject
{
    Q_OBJECT
public:
    explicit principal(QObject *parent = nullptr);
    menu_dialog *menu;

void comenzar();


signals:

public slots:

    bool recibe_senal(bool);


};

#endif // PRINCIPAL_H
