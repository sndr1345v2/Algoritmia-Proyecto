#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QObject>

class principal : public QObject
{
    Q_OBJECT
public:
    explicit principal(QObject *parent = nullptr);

signals:

};

#endif // PRINCIPAL_H
