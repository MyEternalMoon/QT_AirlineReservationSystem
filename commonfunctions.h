#ifndef COMMONFUNCTIONS_H
#define COMMONFUNCTIONS_H
#include <QString>
#include <QPixmap>
#include <QPainter>
#include <QDir>
#include <QFile>

bool copyFileToPath(QString, QString, bool);
bool isDirExistsAndCreateDir(QString);
bool bookTicket(QString userId, QString airlineId);
QPixmap radiusPix(QString url, int size);

#endif // COMMONFUNCTIONS_H
