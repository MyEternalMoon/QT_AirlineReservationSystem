#include "orderwidget.h"
#include "ui_orderwidget.h"
#include <QDate>
orderWidget::orderWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::orderWidget)
{
    ui->setupUi(this);
}

void orderWidget::initInfo(QString user, QString id, QDate date, int price)
{
    ui->userLabel->setText(QString::fromLocal8Bit("用户名: %1").arg(user));
    ui->airlineLabel->setText(QString::fromLocal8Bit("航班号: %1").arg(id));
    ui->priceLabel->setText(QString::fromLocal8Bit("订单金额: %1.00").arg(price));
    ui->dateLabel->setText(QString::fromLocal8Bit("订单日期:%1").arg(date.toString("yyyy.MM.dd")));
}

orderWidget::~orderWidget()
{
    delete ui;
}
