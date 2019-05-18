#include "buyticketdialog.h"
#include "ui_buyticketdialog.h"
#include <QMouseEvent>

buyTicketDialog::buyTicketDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::buyTicketDialog)
{
    ui->setupUi(this);
}

buyTicketDialog::buyTicketDialog(QWidget *parent, QString user, QString id, QString from, QString to, QString fromTime, QString price) :
    QDialog(parent),
    ui(new Ui::buyTicketDialog)
{
    ui->setupUi(this);
    ui->userLabel->setText(QString::fromLocal8Bit("[OnAir]用户 %1").arg(user));
    ui->airlineLabel->setText(QString::fromLocal8Bit("%1, %2到%3, 航班号:%4").arg(fromTime).arg(from).arg(to).arg(id));
    ui->priceLabel->setText(QString::fromLocal8Bit("本次票价为: %1").arg(price));


    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground);
}

buyTicketDialog::~buyTicketDialog()
{
    delete ui;
}

// overwriting mouse move event
void buyTicketDialog::mousePressEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    QPoint mouse = event->pos();
   // int x = mouse.x();
    int y = mouse.y();
    if (event->button() == Qt::LeftButton && y>0 && y<= this->height()/5)
    {
        _clickedFlag = 1;
        _mousePos = event->globalPos();
        _windowPos = this->frameGeometry().topLeft();
        this->setCursor(Qt::OpenHandCursor);
    }
}

void buyTicketDialog::mouseMoveEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    if (event->buttons() & Qt::LeftButton && _clickedFlag == 1)
    {
        QPoint relativePos = event->globalPos() - _mousePos;
        this->move(_windowPos + relativePos );
        this->setCursor(Qt::ClosedHandCursor);
    }
}

void buyTicketDialog::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    _clickedFlag = 0;
    this->setCursor(Qt::ArrowCursor);
}
