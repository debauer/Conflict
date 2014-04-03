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
    int id;
    void SetValue (intValue (*ptr), int value);
    void setId(int id);
    Data();
signals:
    void Changed();
public slots:
    void ProcessData(Carriage *car);
};

#endif // DATA_H
