#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QtUiTools/QUiLoader>
#include <QDebug>
#include <QDir>

#include "ui_conflictwidget.h"
#include "conflictwidget.h"

//QList<ConflictCore> *core;
//ConflictCore *core;
PortSettings portSettings;
QList<QextPortInfo> serialPorts;
QextSerialPort *SerialPort;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    int i;

    ui->setupUi(this);

    /* Serial Menü*/
    serialPorts = QextSerialEnumerator::getPorts();
    signalMapper = new QSignalMapper (this);
    for(i = 0;i < serialPorts.size();i++){
        if((QString)serialPorts.at(i).portName != (QString)""){
            QAction *menueSerialPorts = new QAction((QString)serialPorts.at(i).portName.toLocal8Bit().constData() + QString(),this);
            ui->menuVerbinden->addAction(menueSerialPorts);
            QObject::connect (menueSerialPorts, SIGNAL(triggered()), signalMapper, SLOT(map())) ;
            signalMapper -> setMapping (menueSerialPorts, i);
        }
    }
    QObject::connect (signalMapper, SIGNAL(mapped(int)), this, SLOT(newCoreSerial(int)));

    /* ETH Menü */

    /* sonstiges Connects */
}

MainWindow::~MainWindow(){
    delete ui;
}

ConflictCore* MainWindow::newCore(){
     ConflictCore *core = new ConflictCore();
     QObject::connect (core, SIGNAL(debugOutput(QString)), this, SLOT(debugConsole(QString)));
     QObject::connect (core, SIGNAL(Changed(ConflictCore*,QString)), this, SLOT(updateGui(ConflictCore*,QString)));
     QObject::connect(ui->ledColorGreen, SIGNAL(valueChanged(int)),core->led, SLOT (setGreen(int)));
     QObject::connect(ui->ledColorRed, SIGNAL(valueChanged(int)),core->led, SLOT (setRed(int)));
     QObject::connect(ui->ledColorBlue, SIGNAL(valueChanged(int)),core->led, SLOT (setBlue(int)));
     QObject::connect(ui->ledModus, SIGNAL(currentIndexChanged(int)),core->led, SLOT (setMode(int)));
     return core;
}\

void MainWindow::newCoreSerial(int serId){
     ConflictCore *core = this->newCore();
     core->connectSerial(serId);
     ConflictWidget *conflictWidget = new ConflictWidget();
     Ui::ConflictWidget *conflictUi = conflictWidget->getObject();
     //ui->Tabs->addTab(conflictWidget,QString(""));
}

void MainWindow::newCoreETH(QString ip){
     ConflictCore *core = this->newCore();
     core->connectETH(ip);
}

/* Haupt Update Worker */
void MainWindow::updateGui(ConflictCore* core,QString dataClass){
     if(dataClass == QString('led')){
        ui->console->append(QString("updateGui LED"));
     }
}

void MainWindow::debugConsole(Carriage *car){
     ui->console->append(car->toString());
}

void MainWindow::debugConsole(QString str){
     ui->console->append(str);
}

