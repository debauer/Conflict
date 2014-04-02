#ifndef CONFLICT_CORE_H
#define CONFLICT_CORE_H
#include <qextserialport.h>
#include <qextserialenumerator.h>
#include <QSignalMapper>
#include <mainwindow.h>
#include <QSharedMemory>
#include <QBuffer>
#include <QDebug>
#include <QObject>
#include <QString>

#include "driver/absInterface.h"
#include "driver/uart.h"
#include "carriage.h"
#include "data/kanal.h"
#include "data/dfm.h"
#include "data/rechner.h"

/*
 *
 * Namenkonvention: (unfertig)
 * updateXYZ() - daten an HW schicken
 * setXYZ() - setze Object Daten, bei Datenänderung Signal: Changed();
 * rcvXYZ() - daten von Interface empfangen
 *
 */


class ConflictCore : public QObject{
        Q_OBJECT
    private:
        AbsInterface *interface;
        bool interfaceOpen;
        void connectInterface(QString str);
    public:
        ConflictCore();
        Rechner system;
//        System system;
        Dfm dfm;
        Kanal kanal[4];

        void connectSerial(int port);
        void connectETH(QString ip);
        void disconnect();
        void printDebug(QString);
        void rcvCarriage(Carriage *car); //
    public slots:
        void restart(); //
        void ChangedData(); // Akkregator der Changed Signale von Daten Klassen. Emittet ebenfalls Changed()
    signals:
        void Changed();
        void newCarriage(Carriage *car);
        void debugOutput(QString  str);
};

#endif // CONFLICT_CORE_H
