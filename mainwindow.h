#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>

#include "carriage.h"

#include "conflict_core.h"
#include "qextserialport.h"
#include "qextserialenumerator.h"
#include "QSignalMapper"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    ConflictCore* newCore();
    //QWidget* loadUiFile();
public slots:
    void newCoreSerial(int ser);
    void newCoreETH(QString ip);
    void debugConsole(Carriage *car);
    void debugConsole(QString str);
    void updateGui();
};

#endif // MAINWINDOW_H
