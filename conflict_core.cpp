#include <conflict_core.h>


ConflictCore::ConflictCore(){
    //QObject::connect(this, SIGNAL(newCarriage(Carriage*)),&this->channels,SLOT(ProcessData(Carriage*)));
    //QObject::connect(&channels, SIGNAL(Changed()),this,SLOT(ChangedData()));
}

void ConflictCore::connectSerial(int port){
    this->interface = new Uart(this);
    this->connectInterface(QString::number(port));
    this->printDebug(QString("New Serial"));
}

void ConflictCore::connectETH(QString ip){
    //this->interface = new eth(this);
    this->connectInterface(ip);
}

void ConflictCore::connectInterface(QString str){
    this->interface->Open(str);
    this->printDebug(QString("Interface") + str + QString("wird geöffnet"));
    if(this->interface->IsOpen()){
        this->interfaceOpen = true;
        this->printDebug(QString("Interface Open"));
    }
}

void ConflictCore::printDebug(QString str){
    emit this->debugOutput(QString("Debug: ") + str);
}

void ConflictCore::disconnect(){
    this->interface = NULL;
}

void ConflictCore::restart(){
    this->printDebug(QString("restart"));
    // Sende restart String
}

void ConflictCore::ChangedData(){
    emit Changed();
}

// Reicht daten des Interfaces an die Daten Klassen weiter. Filterung ist angedacht aber nicht implementiert.
// Derzeit bekommt jede Daten Klasse
// Interface Signale -> Core Slot -> Core Signal -> DataClasses Slots.
void ConflictCore::rcvCarriage(Carriage *car){
    //this->printDebug(QString("Carriage - ") + car->toString());
    emit this->newCarriage(car);
}
