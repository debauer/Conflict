#include "carriage.h"

#include <QString>
#include <QStringList>

/*
 * Transport/Wrapper klasse für Carriages der Steuerung
 * Core intern wird nur damit daten ausgetauscht.
 * Vorsicht beim number->QString konvertieren. QString::number benutzen!
 */

Carriage::Carriage(){
    this->direction = 0;
    this->id = 0;
    this->index = 0;
    this->data = "";
}

/*
 * Gibt String ohne <CR> zurück. Z.B. für die Debug Console oder zum senden übers Interface.
 */

QString Carriage::getString(){
    return QString::number(this->direction)
            .append("#")
            .append(QString::number(this->id))
            .append("#")
            .append(QString::number(this->index))
            .append("#")
            .append(this->data)
            .append("#");
}

QString Carriage::toString(){
    return this->getString();
}

Carriage::Carriage(int direction,int id, int index, QString data){
    this->set(direction,id,index,data);
}

Carriage::Carriage(int direction,int id, int index, int data){
    this->set(direction,id,index,QString::number(data));
}

Carriage::Carriage(QString str){
    this->set(str);
}

/* getter */

int Carriage::getDirection(){
    return this->direction;
}

int Carriage::getId(){
    return this->id;
}

int Carriage::getIndex(){
    return this->index;
}

QString Carriage::getData(){
    return this->data;
}

/* setter */
void Carriage::set(int direction,int id, int index, QString data){
    this->direction = direction;
    this->id = id;
    this->index = index;
    this->data = data;
}

void Carriage::set(int direction,int id, int index, int data){
    this->set(direction,id,index,QString::number(data));
}

void Carriage::set(QString str){
    QList<QString> data = str.split("#");
    this->direction = data.value(0).toInt();
    this->id = data.value(1).toInt();
    this->index = data.value(2).toInt();
    this->data = data.value(3);
}

void Carriage::setDirection(int direction){
    this->direction = direction;
}

void Carriage::setId(int id){
    this->id = id;
}

void Carriage::setIndex(int index){
    this->index = index;
}

void Carriage::setData(int data){
    this->setData(QString::number(data));
}

void Carriage::setData(QString data){
    this->data = data;
}
