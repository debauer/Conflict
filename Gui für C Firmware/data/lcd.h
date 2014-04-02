#ifndef LCD_H
#define LCD_H

#include "data.h"

class Lcd : public Data{
    Q_OBJECT

    intValue backlight      = {0,0,100}; // Backlight helligkeit
    intValue contrast       = {0,0,100}; // Kontrast
    intValue content[256];  // im Konstruktor Initialiert // welcher Inhalt
    intValue screens[32];   // im Konstruktor Initialiert // Wie lange in 0,5s Steps

public:
    Lcd();

    void updateLCD(); // Contrast + Backlight
    void updateScreens();
    void updateContent();

    int  getBacklight();
    void setBacklight(int value);

    int  getContrast();
    void setContrast(int value);

    int  getScreens(int id);
    void setScreens(int id, int value);

    int  getContent(int id);
    void setContent(int id, int value);

public slots:
    void ProcessData(Carriage *car);
};

#endif // LCD_H
