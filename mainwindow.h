#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidgetItem>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QTime>
#include <QPropertyAnimation>
#include <QDateTime>
#include <QListWidgetItem>
#include "commonfunctions.h"
#include "airlinewidget.h"
#include "airlines.h"
#include "airlines.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    MainWindow(QWidget *parent, string name, string url,int arth);
    ~MainWindow();

private:
    QString _name; // User's name
    QString _url; // url of head
    QSqlDatabase _db;
    int _arth; // User's arthority. 0->Manager, 1->Client

    airlines _airlines[100];
    int _amount; //smaller than 100

    QPoint _mousePos;
    QPoint _windowPos;
    bool _clickedFlag;

    void initSignalsAndSlots();
    void initInfomation();

    void initAirlines();
    void createARow(QString fromCity, QString toCity, QTime fromTime, QTime toTime, int price, QString id);
    void clearAirlinesWidget();

    Ui::MainWindow *ui;
//protected slots:
//    void started(QString, int);
private slots:
    void ticketClicked(QListWidgetItem *i);
    void ticketRejected();

protected:
    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);

};

#endif // MAINWINDOW_H
