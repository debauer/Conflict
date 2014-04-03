#include "conflict_core.h"


ConflictCore::ConflictCore(){

    kanal[0].setId(0);
    kanal[1].setId(1);
    kanal[2].setId(2);
    kanal[3].setId(3);

    QSignalMapper *signalMapper = new QSignalMapper(this);

    signalMapper->setMapping(&dfm, QString("dfm"));
    QObject::connect(&dfm, SIGNAL(Changed()),signalMapper, SLOT (map()));
    signalMapper->setMapping(&kanal[0], QString("kanal0"));
    QObject::connect(&kanal[0], SIGNAL(Changed()),signalMapper, SLOT (map()));
    signalMapper->setMapping(&kanal[1], QString("kanal1"));
    QObject::connect(&kanal[1], SIGNAL(Changed()),signalMapper, SLOT (map()));
    signalMapper->setMapping(&kanal[2], QString("kanal2"));
    QObject::connect(&kanal[2], SIGNAL(Changed()),signalMapper, SLOT (map()));
    signalMapper->setMapping(&kanal[3], QString("kanal3"));
    QObject::connect(&kanal[3], SIGNAL(Changed()),signalMapper, SLOT (map()));
    signalMapper->setMapping(&system, QString("system"));
    QObject::connect(&system, SIGNAL(Changed()),signalMapper, SLOT (map()));
    signalMapper->setMapping(&led, QString("led"));
    QObject::connect(&led, SIGNAL(Changed()),signalMapper, SLOT (map()));
    signalMapper->setMapping(&lcd, QString("led"));
    QObject::connect(&lcd, SIGNAL(Changed()),signalMapper, SLOT (map()));

    QObject::connect(signalMapper, SIGNAL(mapped(QString)),this, SLOT(ChangedData(QString)));


    QObject::connect(this, SIGNAL(newCarriage(Carriage*)),&dfm      ,SLOT(ProcessData(Carriage*)));
    QObject::connect(this, SIGNAL(newCarriage(Carriage*)),&kanal[0] ,SLOT(ProcessData(Carriage*)));
    QObject::connect(this, SIGNAL(newCarriage(Carriage*)),&kanal[1] ,SLOT(ProcessData(Carriage*)));
    QObject::connect(this, SIGNAL(newCarriage(Carriage*)),&kanal[2] ,SLOT(ProcessData(Carriage*)));
    QObject::connect(this, SIGNAL(newCarriage(Carriage*)),&kanal[3] ,SLOT(ProcessData(Carriage*)));
    QObject::connect(this, SIGNAL(newCarriage(Carriage*)),&system   ,SLOT(ProcessData(Carriage*)));
    QObject::connect(this, SIGNAL(newCarriage(Carriage*)),&lcd   ,SLOT(ProcessData(Carriage*)));
    QObject::connect(this, SIGNAL(newCarriage(Carriage*)),&led   ,SLOT(ProcessData(Carriage*)));
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

void ConflictCore::ChangedData(QString str){
    this->printDebug(QString("Changed - ") + str);
    emit Changed(this,str);
}

// Reicht daten des Interfaces an die Daten Klassen weiter. Filterung ist angedacht aber nicht implementiert.
// Derzeit bekommt jede Daten Klasse
// Interface Signale -> Core Slot -> Core Signal -> DataClasses Slots.
void ConflictCore::rcvCarriage(Carriage *car){
    //this->printDebug(QString("Carriage - ") + car->toString());
    emit this->newCarriage(car);
}
