#include <QCoreApplication>
#include <qt_library_example.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qt_library_example run;
    run.imprimir_pantalla();

    return a.exec();
}
