#include "rechner.h"

Rechner::Rechner(){

}


void Rechner::SetCpuFreq(int d){
    this->SetValue(&cpuFreq,d);
}

void Rechner::SetCpuUsage(int d){
    this->SetValue(&cpuUsage,d);
}

void Rechner::SetGpuUsage(int d){
    this->SetValue(&gpuUsage,d);
}

void Rechner::SetRamUsage(int d){
    this->SetValue(&ramUsage,d);
}

void Rechner::ProcessData(Carriage *car){
}
