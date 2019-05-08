#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::MainWindow(QWidget *parent, string name, std::string url, int arth) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initSignalsAndSlots();
    this->setWindowFlags(Qt::FramelessWindowHint);

    _name = QString(name.c_str());
    _arth = arth;
    _clickedFlag = 0;
    _url = QString(url.c_str());

    if(QSqlDatabase::contains("qt_sql_default_connection"))
    {
        _db = QSqlDatabase::database("qt_sql_default_connection");
    }
    else
    {
        _db = QSqlDatabase::addDatabase("QSQLITE");
    }
    _db.setDatabaseName("./qtdb.db");
    //initialize database connection.

    initAirlines();
    initInfomation();
}


void MainWindow:: initSignalsAndSlots()
{
    connect(ui->exitButton, SIGNAL(clicked(bool)),this,SLOT(close()));
    connect(ui->minimumButton,SIGNAL(clicked(bool)),this,SLOT(showMinimized()));
    connect(ui->listWidget,SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(ticketClicked(QListWidgetItem*)));
    connect(ui->bookTicketrejectBtn,SIGNAL(clicked(bool)),this,SLOT(ticketRejected()));
    connect(ui->bookTicketAcceptbtn,SIGNAL(clicked(bool)),this,SLOT(bookTicketClicked());
}

void MainWindow::initInfomation()
{
    QString info;
    //显示用户信息
    if (_arth == 1)
    {
        info = QString::asprintf("Dear Manager");
    }
    else
    {
        info = QString::asprintf("Client.");
    }
    ui->userInfoLabel->setText(_name);
    ui->arthorLabel->setText(info);

//    显示头像
    QPixmap pix = radiusPix(_url, ui->haedLabel->width());
    ui->haedLabel->setPixmap(pix);

}

void MainWindow::initAirlines()
{
    if (_db.open())
    {
        QSqlQuery sq(_db);
        QString userSql = "SElECT * FROM airlines";
        sq.prepare(userSql);
        if (sq.exec())
        {
            while(sq.next())
            {
//                qDebug() << sq.value(0).toString()<< sq.value(1).toString() <<
//                                                   sq.value(3).toDateTime().time() <<sq.value(4).toDateTime().time()
//                                                  << sq.value(5).toInt() <<sq.value(2).toString();
                createARow(sq.value(0).toString(), sq.value(1).toString(),
                           sq.value(3).toDateTime().time(),sq.value(4).toDateTime().time(),
                           sq.value(5).toInt(),sq.value(2).toString());
            }
        }
    }
}

void MainWindow::createARow(QString fromCity, QString toCity, QTime fromTime, QTime toTime, int price, QString id)
{
    QListWidgetItem* item = new QListWidgetItem;
    airlineWidget* info = new airlineWidget(this,fromCity,toCity,fromTime,toTime,price,id);
    item->setSizeHint(QSize(820,80));

    ui->listWidget->addItem(item);
    ui->listWidget->setItemWidget(item,info);

}

void MainWindow::bookTicketClicked()
{
    QListWidgetItem* cur = ui->listWidget->currentItem();
    QString currentID = ui->listWidget->itemWidget(cur)->findChild<QLabel>("idLabel")->text();
    if (bookTicket(currentID, _name))
    {
        // Do something such as turn to view of purchased tickets/
    }

}

void MainWindow::ticketClicked(QListWidgetItem* i)
{
    //BookTicketWidget slides up

    QWidget* id = ui->listWidget->itemWidget(i);
    QString currentID = id->findChild<QLabel*>("idLabel")->text();
    //get airlinewidget by listItem
    //use findChild<>(QString Objname) to find idLabel and get id.

    ui->bookTicketInfolabel->setText(QString::fromLocal8Bit("确定要购买机票\"%1\"吗").arg(currentID));
    if (ui->bookTicketWidget->y()==650)
    {
        QPropertyAnimation* qp_geo= new QPropertyAnimation(ui->bookTicketWidget,"geometry");
        qp_geo->setDuration(500);
        qp_geo->setStartValue(QRect(80,650,820,120));
        qp_geo->setEndValue(QRect(80,530,820,120));
        qp_geo->start(QAbstractAnimation::DeleteWhenStopped);
    }
}

void MainWindow::ticketRejected()
{
    //BookTicketWidget slides down
    QPropertyAnimation* qp= new QPropertyAnimation(ui->bookTicketWidget,"geometry");
    qp->setDuration(300);
    qp->setStartValue(QRect(80,530,820,120));
    qp->setEndValue(QRect(80,650,820,120));
    qp->start(QAbstractAnimation::DeleteWhenStopped);
}

void MainWindow::clearAirlinesWidget()
{
    // release all memories of listwidgetItems
    for (int i = 0;i<ui->listWidget->count();i++)
    {
        QListWidgetItem* item = ui->listWidget->takeItem(0);
        QWidget* air = ui->listWidget->itemWidget(item);

        delete item;
        delete air;
    }
}

MainWindow::~MainWindow()
{
    clearAirlinesWidget();
    delete ui;
}



