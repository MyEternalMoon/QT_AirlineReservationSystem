#include "orderwidget.h"
#include "ui_orderwidget.h"

orderWidget::orderWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::orderWidget)
{
    ui->setupUi(this);
}

orderWidget::~orderWidget()
{
    delete ui;
}
