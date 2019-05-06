#include "airlinewidget.h"
#include "ui_airlinewidget.h"

airlineWidget::airlineWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::airlineWidget)
{
    ui->setupUi(this);
}

airlineWidget::airlineWidget(QWidget *parent, QString fromCity, QString toCity, QTime fromTime, QTime toTime, int price, QString id):
    QWidget(parent),
    ui(new Ui::airlineWidget)
{

    ui->setupUi(this);
    ui->fromCityLabel->setText(fromCity);

    ui->toCityLabel->setText(toCity);

    ui->priceLabel->setText(QString::number(price));
    ui->idLabel->setText(id);

    ui->fromTimeLabel->setText(fromTime.toString("hh:mm"));
    ui->toTimeLabel->setText(toTime.toString("hh:mm"));
}

QString airlineWidget::getID()
{
    return ui->idLabel->text();
}

airlineWidget::~airlineWidget()
{
    delete ui;
}
