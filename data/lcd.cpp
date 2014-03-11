#include "lcd.h"

lcd::lcd(){
}

intValue lcd::getBacklight(){
    return backlight.value;
}

void lcd::setBacklight(intValue &value){
    this->SetValue(&backlight, value);
}

intValue lcd::getContrast(){
    return contrast.value;
}

void lcd::setContrast(intValue &value){
    this->SetValue(&contrast, value);
}

intValue lcd::getScreens(){
    return screens[id].value;
}

void lcd::setScreens(int id, intValue &value){
    this->SetValue(&screens[id], value);
}

intValue lcd::getContent(int id){
    return content[id].value;
}

void lcd::setContent(int id, intValue &value){
    this->SetValue(&content[id], value);
}
