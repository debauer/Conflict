#ifndef LED_H
#define LED_H

#include "data.h"

class led : public Data{
    Q_OBJECT

    intValue red      = {0,0,100};
    intValue blue      = {0,0,100};
    intValue green      = {0,0,100};

public:
    led();

    int getRed();
    void setRed(int value);

    int getBlue();
    void setBlue(int value);

    int getGreen();
    void setGreen(int value);

public slots:
    void ProcessData(Carriage *car);

};

#endif // LED_H
