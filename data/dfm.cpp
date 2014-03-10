#include "channel.h"


Dfm::Dfm(){
}

void Dfm::ProcessData(Carriage *car){
    // Prüfen ob es ein Carriage für diese Klasse ist
    if(car->getId() == 70 || car->getId() == 60){
        int id = car->getId();
        int dir = car->getDirection();
        int index = car->getIndex();
        int data = car->getData().toInt();
        switch(id){
            case 60: this->SetValue(&this->waterFlow,data); break;
            case 70: if(id == 70 && index == 1){
                        this->SetValue(&this->pulsePerLiter,data);
                     }else if(id == 70 && index == 1){
                        this->SetValue(&this->minFlow,data);
                     }
            break;
        }
    }

//    if((car->getId() >= 10 && car->getId() < 30) || (car->getId() >= 60 && car->getId() < 77)){
//        int id = car->getId();
//        int dir = car->getDirection();
//        int index = car->getIndex();
//        int data = car->getData().toInt();

//        if(id < 20 ){                       // min temp
//            channels[id - 10].setMinTemp(index,data);
//        }else if(id < 30 ){                 // max temp
//            channels[id - 20].setMaxTemp(index,data);
//        }else{
//            switch(id){
//                case 60: this->SetValue(&this->waterFlow,data); break;
//                case 61: channels[index].setRpm(data); break;
//                case 62: channels[index].setPower(data); break;
//                case 70: if(id == 70 && index == 1){
//                            this->SetValue(&this->pulsePerLiter,data);
//                         }else if(id == 70 && index == 1){
//                            this->SetValue(&this->minFlow,data);
//                         }
//                break;
//                case 71: channels[index].setManualPower(data); break;
//                case 72: channels[index].setStartupTime(data); break;
//                case 73: channels[index].setMinPower(data); break;
//                case 74: channels[index].setAutoMode(data); break;
//                case 75: channels[index].setStopEnabled(data); break;
//                case 76: channels[index].setThreshold(data); break;
//                default:break;
//            }
//        }
//    }
}

void Dfm::ChangedBean(){
    emit this->Changed();
}
