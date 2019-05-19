#ifndef COMMONFUNCTIONS_H
#define COMMONFUNCTIONS_H
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSplashScreen>
#include <QPixmap>
#include <QPainter>
#include <QDir>
#include <QFile>

//bool copyFileToPath(QString, QString, bool);
bool isDirExistsAndCreateDir(QString);
bool isTableExistsAndCreateTables();

bool isQStringTime(QString s);
bool isQStringDate(QString s);
bool isQStringAirlineId(QString s);
bool isQStringAirport(QString s);


QPixmap radiusPix(QString url, int size);

#endif // COMMONFUNCTIONS_H
