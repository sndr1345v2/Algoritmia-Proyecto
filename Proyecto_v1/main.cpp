#include <QApplication>
#include <QDebug>
#include <principal.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    principal run;
    run.comenzar();

    return a.exec();




}
