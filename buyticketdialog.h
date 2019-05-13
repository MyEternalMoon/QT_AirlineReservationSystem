#ifndef BUYTICKETDIALOG_H
#define BUYTICKETDIALOG_H

#include <QDialog>

namespace Ui {
class buyTicketDialog;
}

class buyTicketDialog : public QDialog
{
    Q_OBJECT

public:
    explicit buyTicketDialog(QWidget *parent = 0);
    buyTicketDialog(QWidget *parent,QString user, QString id, QString from, QString to, QString fromTime, QString price);
    ~buyTicketDialog();

private:
    Ui::buyTicketDialog *ui;
};

#endif // BUYTICKETDIALOG_H
