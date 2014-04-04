#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>

#include "carriage.h"

#include "qextserialport.h"
#include "qextserialenumerator.h"
#include "QSignalMapper"
#include "conflict_core.h"

namespace Ui {
class MainWindow;
}

class ConflictCore;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    ConflictCore* newCore();
    ConflictCore* aktivCore;
    //QWidget* loadUiFile();

    QSignalMapper* signalMapper;
    QSignalMapper* sliderSignalMapper;


public slots:
    void newCoreSerial(int ser);
    void newCoreETH(QString ip);
    void debugConsole(Carriage *car);
    void debugConsole(QString str);
    void updateGui(ConflictCore* core,QString dataClass);
};

#endif // MAINWINDOW_H
