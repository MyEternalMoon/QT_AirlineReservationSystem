#include "mainwindow.h"
#include "logindialog.h"
#include <QApplication>
#include <iostream>


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    LogInDialog l;
   // MainWindow m;
    l.show();
    return a.exec();

}
