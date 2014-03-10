#include "kanal.h"

Kanal::Kanal(){
    int i;
    for(i = 0;i<24;i++){
        maxTemp[i].max = 255;
        maxTemp[i].min = 0;
        maxTemp[i].value = 0;

        minTemp[i].max = 255;
        minTemp[i].min = 0;
        minTemp[i].value = 0;
    }
}

void Kanal::ProcessData(Carriage *car){
}

int Kanal::getManualPower(){
    return manualPower.value;
}

void Kanal::setManualPower(int value){
    this->SetValue(&manualPower, value);
}

int Kanal::getStartupTime(){
    return startupTime.value;
}

void Kanal::setStartupTime(int value){
    SetValue (&startupTime, value);
}

int Kanal::getMinPower(){
    return minPower.value;
}

void Kanal::setMinPower(int value){
    SetValue (&minPower, value);
}

int Kanal::getAutoMode(){
    return autoMode.value;
}

void Kanal::setAutoMode(int value){
    SetValue (&autoMode, value);
}

int Kanal::getStopEnabled(){
    return stopEnabled.value;
}

void Kanal::setStopEnabled(int value){
    SetValue (&stopEnabled, value);
}

int Kanal::getThreshold(){
    return threshold.value;
}

void Kanal::setThreshold(int value){
    SetValue (&threshold, value);
}

int Kanal::getPower(){
    return power.value;
}

void Kanal::setPower(int value){
    SetValue (&power, value);
}

int Kanal::getRpm(){
    return rpm.value;
}

void Kanal::setRpm(int value){
    SetValue (&rpm, value);
}

int Kanal::getMaxTemp(int tId){
    return maxTemp[tId].value;
}

void Kanal::setMaxTemp(int tId ,int value){
    SetValue (&maxTemp[tId], value);
}

int Kanal::getMinTemp(int tId){
    return minTemp[tId].value;
}

void Kanal::setMinTemp(int tId ,int value){
    SetValue (&minTemp[tId], value);
}
