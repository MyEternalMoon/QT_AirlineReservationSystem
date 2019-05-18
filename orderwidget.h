#ifndef ORDERWIDGET_H
#define ORDERWIDGET_H

#include <QWidget>

namespace Ui {
class orderWidget;
}

class orderWidget : public QWidget
{
    Q_OBJECT

public:
    explicit orderWidget(QWidget *parent = 0);
    ~orderWidget();

private:
    Ui::orderWidget *ui;
};

#endif // ORDERWIDGET_H
