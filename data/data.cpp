#include "data.h"

data::data(){

}

void data::SetValue (intValue *ptr, int value){
    // Min/Max Grenzen überprüfen.
    int newValue;
    if(value <= ptr->max && value >= ptr->min){
        // Value im erlaubten Bereich
        newValue = value;
    }else if(value > ptr->max){
        // value zu groß, setze auf max
        newValue = ptr->max;
    }else if(value < ptr->min){
        // value zu klein, setze auf min
        newValue = ptr->min;
    }else{
        // else halt... wer weis. Setze auf max.
        newValue = ptr->max;
    }

    if(newValue != ptr->value){
        emit this->Changed();
    }
}
