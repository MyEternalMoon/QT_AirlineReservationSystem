#include "airlinewidget.h"
#include "ui_airlinewidget.h"

airlineWidget::airlineWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::airlineWidget)
{
    ui->setupUi(this);
}

airlineWidget::airlineWidget(QWidget *parent, QString fromCity, QString toCity,QDate fromDate, QDate toDate, QTime fromTime, QTime toTime, int price, QString id):
    QWidget(parent),
    ui(new Ui::airlineWidget)
{

    ui->setupUi(this);
    ui->fromCityLabel->setText(fromCity);
    isEditing = false;
    ui->toCityLabel->setText(toCity);

    ui->priceLabel->setText(QString::number(price));
    ui->idLabel->setText(id);

    ui->fromDateLabel->setText(fromDate.toString("yy-MM-dd"));
    ui->toDateLabel->setText(toDate.toString("yy-MM-dd"));


    ui->fromTimeLabel->setText(fromTime.toString("hh:mm"));
    ui->toTimeLabel->setText(toTime.toString("hh:mm"));
    connect(ui->editButton,SIGNAL(clicked(bool)),this,SLOT(editAirlines()));
}

QString airlineWidget::getID()
{
    return ui->idLabel->text();
}

void airlineWidget::hideOrShowEditButton(bool isToShow)
{
    if (isToShow)
    {
        ui->editButton->show();
    }
    else
    {
        ui->editButton->hide();

    }
}

void airlineWidget::editAirlines()
{
    if (!isEditing)
    {
        isEditing = true;
        ui->editButton->setStyleSheet("border-image: url(:/img_normal/ok.png);");
    }
    else
    {
        isEditing = false;
        //check if valid
        ui->editButton->setStyleSheet("border-image: url(:/img_normal/edit_button.png);");
        QList<QString> values;
        values.append(ui->fromCityLabel->text());
        values.append(ui->toCityLabel->text());
        values.append(ui->priceLabel->text());
        values.append(ui->idLabel->text());
        emit airlineEidted(values);
    }
    QList<QLineEdit*> ledt = ui->frame->findChildren<QLineEdit*>();
    foreach(QLineEdit* edt, ledt)
    {
        edt->setReadOnly(!isEditing);
    }
}

airlineWidget::~airlineWidget()
{
    delete ui;
}
