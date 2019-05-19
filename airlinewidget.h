#ifndef AIRLINEWIDGET_H
#define AIRLINEWIDGET_H
#include <QWidget>
#include <QDebug>
#include <QTime>

namespace Ui {
class airlineWidget;
}

class airlineWidget : public QWidget
{
    Q_OBJECT

public:
    explicit airlineWidget(QWidget *parent = 0);
    airlineWidget(QWidget* parent, QString fromCity, QString toCity, QDate fromDate, QDate toDate, QTime fromTime, QTime toTime, int price, QString id);
    void hideOrShowEditButton(bool isToShow);

    QString getID();
    int getPrice();
    ~airlineWidget();

private slots:
    void editAirlines();
signals:
    airlineEidted(QList<QString> sql); // airport start, end ,price ,id;


private:
    bool isEditing;
    Ui::airlineWidget *ui;
};

#endif // AIRLINEWIDGET_H
