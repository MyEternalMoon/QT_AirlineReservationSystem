#include "mainwindow.h"
#include "logindialog.h"
#include <QApplication>
#include "commonfunctions.h"
#include <iostream>


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    QSplashScreen *splash = new QSplashScreen();
    splash->setStyleSheet("border-image:/img_normal/warning.png");
    splash->show();

    isTableExistsAndCreateTables();

    LogInDialog l;

  //  isTableExistsAndCreateTables();
   // MainWindow m;
    l.show();
    splash->close();
    delete splash;
    return a.exec();

}
