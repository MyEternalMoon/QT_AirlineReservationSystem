#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMouseEvent>

// overwriting mouse move event
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    QPoint mouse = event->pos();
   // int x = mouse.x();
    int y = mouse.y();
    if (event->button() == Qt::LeftButton && y>0 && y<= this->height()/10)
    {
        _clickedFlag = 1;
        _mousePos = event->globalPos();
        _windowPos = this->frameGeometry().topLeft();
        this->setCursor(Qt::OpenHandCursor);
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    if (event->buttons() & Qt::LeftButton && _clickedFlag == 1)
    {
        QPoint relativePos = event->globalPos() - _mousePos;
        this->move(_windowPos + relativePos );
        this->setCursor(Qt::ClosedHandCursor);
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    _clickedFlag = 0;
    this->setCursor(Qt::ArrowCursor);
}

void MainWindow::changeBackgroundStyle(bool isEditing)
{
    if (isEditing)
    {
        ui->bglabel->setStyleSheet("border-image: url(:/img_background/mainbackground_manager.png);");
        ui->line->setStyleSheet("background-color:#f20c00");
        ui->line_2->setStyleSheet("background-color:#f20c00");
        ui->line_3->setStyleSheet("background-color:#f20c00");
        ui->warningLabel->show();
    }

    else
    {
        ui->bglabel->setStyleSheet("border-image: url(:/img_background/mainbackground.png);");
        ui->line->setStyleSheet("background:#2ca9e1");
        ui->line_2->setStyleSheet("background:#2ca9e1");
        ui->line_3->setStyleSheet("background:#2ca9e1");
        ui->warningLabel->hide();
    }
}
