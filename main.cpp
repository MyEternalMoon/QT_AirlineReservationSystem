#include "mainwindow.h"
#include "airlines.h"
#include "logindialog.h"
#include <fstream>
#include <QApplication>
#include <iostream>

using std::ofstream;

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    LogInDialog l;
   // MainWindow m;
    l.show();
    return a.exec();

}
