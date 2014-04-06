#include "conflict_core.h"

void ConflictCore::makeMapping(Data* obj, QString str){
    signalMapper->setMapping(obj,str);
    QObject::connect(obj, SIGNAL(Changed()),signalMapper, SLOT (map()));
    QObject::connect(this, SIGNAL(newCarriage(Carriage*)),obj ,SLOT(ProcessData(Carriage*)));
    QObject::connect(obj, SIGNAL(PushToHw(Carriage*)),this,SLOT(sendCarriage(Carriage*)));
    //QObject::connect(this, SIGNAL(syncData()),obj,SLOT(RequestData()));
}


ConflictCore::ConflictCore(){

    kanal[0].setId(1);
    kanal[1].setId(2);
    kanal[2].setId(3);
    kanal[3].setId(4);

    signalMapper = new QSignalMapper(this);

    makeMapping(&dfm,QString("dfm"));
    makeMapping(&kanal[0], QString("kanal1"));
    makeMapping(&kanal[1], QString("kanal2"));
    makeMapping(&kanal[2], QString("kanal3"));
    makeMapping(&kanal[3], QString("kanal4"));
    makeMapping(&system, QString("system"));
    makeMapping(&led, QString("led"));
    makeMapping(&lcd, QString("lcd"));

    QObject::connect(signalMapper, SIGNAL(mapped(QString)),this, SLOT(ChangedData(QString)));

    QObject::connect(this, SIGNAL(syncData()),&led,SLOT(RequestData());
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
        emit this->syncData();
        this->printDebug(QString("Sync Data"));
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
    emit this->syncData();
    interface->SendString((new Carriage(0,1,170,85))->toString());
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

void ConflictCore::sendCarriage(Carriage *car){
    this->printDebug(QString("Sende Carriage:") + car->toString());
    interface->SendString(car->toString());
}
