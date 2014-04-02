#ifndef DFM_H
#define DFM_H

#include <QObject>
#include "data.h"

/*
 *
 */

class Dfm : public Data{
    Q_OBJECT

    private:
        intValue waterFlow;
        intValue pulsePerLiter;
        intValue minFlow;
    public:
        Dfm();
    public slots:
        void ProcessData(Carriage *car);

};

#endif // DFM_H
