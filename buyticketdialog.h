#ifndef BUYTICKETDIALOG_H
#define BUYTICKETDIALOG_H
#include <QPoint>
#include <QDialog>

namespace Ui {
class buyTicketDialog;
}

class buyTicketDialog : public QDialog
{
    Q_OBJECT

public:
    int _clickedFlag;
    QPoint _mousePos;
    QPoint _windowPos;
    explicit buyTicketDialog(QWidget *parent = 0);
    buyTicketDialog(QWidget *parent,QString user, QString id, QString from, QString to, QString fromTime, QString price);
    ~buyTicketDialog();

protected:
    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
private:
    Ui::buyTicketDialog *ui;
};

#endif // BUYTICKETDIALOG_H
