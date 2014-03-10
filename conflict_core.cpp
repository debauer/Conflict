#include <conflict_core.h>


ConflictCore::ConflictCore(){
    QObject::connect(&dfm, SIGNAL(Changed()),this,SLOT(ChangedData()));
    QObject::connect(&kanal[0], SIGNAL(Changed()),this,SLOT(ChangedData()));
    QObject::connect(&kanal[1], SIGNAL(Changed()),this,SLOT(ChangedData()));
    QObject::connect(&kanal[2], SIGNAL(Changed()),this,SLOT(ChangedData()));
    QObject::connect(&kanal[3], SIGNAL(Changed()),this,SLOT(ChangedData()));
    QObject::connect(&system, SIGNAL(Changed()),this,SLOT(ChangedData()));

    QObject::connect(this, SIGNAL(newCarriage(Carriage*)),&dfm,SLOT(ProcessData(Carriage*));
    QObject::connect(this, SIGNAL(newCarriage(Carriage*)),&kanal[0],SLOT(ProcessData(Carriage*));
    QObject::connect(this, SIGNAL(newCarriage(Carriage*)),&kanal[1],SLOT(ProcessData(Carriage*));
    QObject::connect(this, SIGNAL(newCarriage(Carriage*)),&kanal[2],SLOT(ProcessData(Carriage*));
    QObject::connect(this, SIGNAL(newCarriage(Carriage*)),&kanal[3],SLOT(ProcessData(Carriage*));
    QObject::connect(this, SIGNAL(newCarriage(Carriage*)),&system,SLOT(ProcessData(Carriage*));
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
