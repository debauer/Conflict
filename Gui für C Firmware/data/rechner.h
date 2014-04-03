#ifndef RECHNER_H
#define RECHNER_H

#include <QObject>
#include "data.h"

class Rechner : public Data{
    Q_OBJECT
public:
    Rechner();

    void UpdateClock();         // Uhrzeit
    void UpdateSysData();       // CPU Freq, CPU/RAM/GPU usage
    void SetCpuFreq(int d);
    void SetCpuUsage(int d);
    void SetGpuUsage(int d);
    void SetRamUsage(int d);

private:
    intValue hour    = {0,0,23};
    intValue minute    = {0,0,59};
    intValue secund    = {0,0,59};
    intValue cpuFreq    = {0,0,9999};
    intValue cpuUsage   = {0,0,100};
    intValue gpuUsage   = {0,0,100};
    intValue ramUsage   = {0,0,100};

signals:



public slots:
    void ProcessData(Carriage *car);

};

#endif // RECHNER_H
