#ifndef KANAL_H
#define KANAL_H

#include <QObject>
#include "data.h"

class Kanal : public Data{
    Q_OBJECT

    private:
        intValue minTemp[24];   // im Konstruktor Initialiert
        intValue maxTemp[24];   // im Konstruktor Initialiert
        intValue rpm            = {0,0,9999};
        intValue power          = {0,0,100};
        intValue manualPower    = {0,0,100};
        intValue startupTime    = {0,1,255};
        intValue minPower       = {0,0,100};
        intValue autoMode       = {0,0,1};
        intValue stopEnabled    = {0,0,1};
        intValue threshold      = {0,0,50};
    public:
        Kanal();



        int getManualPower();
        void setManualPower(int value);
        int getStartupTime();
        void setStartupTime(int value);
        int getMinPower() ;
        void setMinPower( int value);
        int getAutoMode() ;
        void setAutoMode( int value);
        int getStopEnabled() ;
        void setStopEnabled( int value);
        int getThreshold() ;
        void setThreshold( int value);
        int getPower    () ;
        void setPower   ( int value);
        int getRpm      () ;
        void setRpm     ( int value);
        int getMaxTemp  (int tId) ;
        void setMaxTemp (int tId , int value);
        int getMinTemp  (int tId) ;
        void setMinTemp (int tId , int value);

public slots:
        void ProcessData(Carriage *car);
};

#endif // KANAL_H
