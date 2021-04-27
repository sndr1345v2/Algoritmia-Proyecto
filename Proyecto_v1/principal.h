#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QObject>
#include <menu_dialog.h>
#include <pantalla_modificar.h>

class principal : public QObject
{
    Q_OBJECT
public:
    explicit principal(QObject *parent = nullptr);
    menu_dialog *menu;
    pantalla_modificar *modificar;

void comenzar();


signals:

public slots:

    //bool recibe_senal(bool);

};

#endif // PRINCIPAL_H
