#ifndef LCD_H
#define LCD_H

#include "data.h"

class lcd : public Data{
    Q_OBJECT

    intValue backlight      = {0,0,100}; // Backlight helligkeit
    intValue contrast       = {0,0,100}; // Kontrast
    intValue content[256]   = {0,0,255}; // welcher Inhalt
    intValue screens[32]    = {0,0,255}; // Wie lange in 0,5s Steps

public:
    lcd();

    void updateLCD(); // Contrast + Backlight
    void updateScreens();
    void updateContent();

    intValue getBacklight();
    void setBacklight(intValue &value);

    intValue getContrast();
    void setContrast(intValue &value);

    intValue getScreens(int id);
    void setScreens(int id, intValue &value);

    intValue getContent(int id);
    void setContent(int id, intValue &value);

public slots:
    void ProcessData(Carriage *car);
};

#endif // LCD_H
