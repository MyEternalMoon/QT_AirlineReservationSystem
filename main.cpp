#include "mainwindow.h"
#include "logindialog.h"
#include <QApplication>
#include "commonfunctions.h"
#include <iostream>


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    LogInDialog l;
    isTableExistsAndCreateTables();
  //  isTableExistsAndCreateTables();
   // MainWindow m;
    l.show();
    return a.exec();

}
