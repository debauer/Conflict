#ifndef DATA_H
#define DATA_H

#include <QObject>
#include "../structs.h"
#include "../carriage.h"

/*
 *  Von dieser Klasse wird jede Datenklasse abgeleitet werden.
 *  Parant Class of all data Classes
 */

class Data : public QObject{
    Q_OBJECT
public:
    void SetValue (intValue (*ptr), int value);
    Data();
signals:
    void Changed();
public slots:
    void ProcessData(Carriage *car);
};

#endif // DATA_H
