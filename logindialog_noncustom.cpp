#include "logindialog.h"
#include "ui_logindialog.h"
#include <QMouseEvent>

// overwriting mouse move event
void LogInDialog::mousePressEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    QPoint mouse = event->pos();
//    int x = mouse.x();
    int y = mouse.y();
    if (event->button() == Qt::LeftButton && y>0 && y<= this->height()/10)
    {
        _clickedFlag = 1;
        _mousePos = event->globalPos();
        _windowPos = this->frameGeometry().topLeft();
        this->setCursor(Qt::OpenHandCursor);
    }
}

void LogInDialog::mouseMoveEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    if (event->buttons() & Qt::LeftButton && _clickedFlag == 1)
    {
        QPoint relativePos = event->globalPos() - _mousePos;
        this->move(_windowPos + relativePos );
        this->setCursor(Qt::ClosedHandCursor);
    }
}

void LogInDialog::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    _clickedFlag = 0;
    this->setCursor(Qt::ArrowCursor);
}
