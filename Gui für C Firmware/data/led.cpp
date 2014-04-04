#include "led.h"

Led::Led() : Data(){
}

void Led::ProcessData(Carriage *car){
    switch(car->getId()){
        case 78:
            this->SetValue(&mode,car->getData().toInt());
            break;
        case 79:
            if(car->getIndex() == 1){
                this->SetValue(&red,car->getData().toInt());
            }else if(car->getIndex() == 2){
                this->SetValue(&green,car->getData().toInt());
            }else if(car->getIndex() == 3){
                this->SetValue(&blue,car->getData().toInt());
            }
            break;
        default:
            break;
    }
}

int Led::getRed(){
    return red.value;
}

void Led::setRed(int value){
    this->SetValue(&red, value);
    emit PushToHw(new Carriage(0,79, 1, red.value));
}

int Led::getBlue(){
    return blue.value;
}

void Led::setBlue(int value){
    this->SetValue(&blue, value);

    emit PushToHw(new Carriage(0,79, 3, blue.value));
}

int Led::getGreen(){
    return green.value;
}

void Led::setGreen(int value){
    this->SetValue(&green, value);
    emit PushToHw(new Carriage(0,79, 2, green.value));
}

int Led::getMode(){
    return mode.value;
}

void Led::setMode(int value){
    this->SetValue(&mode, value);
    emit PushToHw(new Carriage(0,78, 1, mode.value));
}

