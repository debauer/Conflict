#ifndef DATA_H
#define DATA_H

#include <QObject>
#include "../structs.h"
#include "../carriage.h"

/*
 *  von dieser klasse sollte jede Datenklasse abgeleitet werden.
 */

class Data : public QObject{
    Q_OBJECT
public:
    void SetValue (intValue (*ptr), int value);
    Data();
signals:
    void Changed();
public slots:
    virtual void ProcessData(Carriage *car) = 0;
};

#endif // DATA_H
