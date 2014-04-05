#ifndef LED_H
#define LED_H

#include "data.h"

class Led : public Data{
    Q_OBJECT

    intValue red        = {0,0,100};
    intValue blue       = {0,0,100};
    intValue green      = {0,0,100};
    intValue mode       = {0,0,255};

public:
    Led();

    int getRed();
    int getBlue();
    int getGreen();
    int getMode();

signals:
    // Changed() von parant!
public slots:
    void setMode(int value);
    void setGreen(int value);
    void setBlue(int value);
    void setRed(int value);
    void ProcessData(Carriage *car); // Parant Member überladen

};

#endif // LED_H
