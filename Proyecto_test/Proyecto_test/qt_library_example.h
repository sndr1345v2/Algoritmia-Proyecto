#ifndef QT_LIBRARY_EXAMPLE_H
#define QT_LIBRARY_EXAMPLE_H

#include <QObject>
#include <clasecmasmas.h>

class qt_library_example : public QObject
{
    Q_OBJECT
public:
    explicit qt_library_example(QObject *parent = nullptr);

    ClaseCmasmas objeto;

    void imprimir_pantalla();

signals:

};

#endif // QT_LIBRARY_EXAMPLE_H
