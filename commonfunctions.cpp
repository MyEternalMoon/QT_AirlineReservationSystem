#include "commonfunctions.h"
#include <QDebug>

//bool copyFileToPath(QString sourceDir ,QString toDir, bool coverFileIfExist)
//{
//    toDir.replace("\\","/");
//    if (sourceDir == toDir){
//        return true;
//    }
//    if (!QFile::exists(sourceDir)){
//        return false;
//    }
//    QDir *createfile = new QDir;
//    bool exist = createfile->exists(toDir);
//    if (exist){
//        if(coverFileIfExist){
//            createfile->remove(toDir);
//        }
//    }//end if
//    delete createfile;
//    if(!QFile::copy(sourceDir, toDir))
//    {
//        return false;
//    }

//    return true;
//}

QPixmap radiusPix(QString url, int size)
{
    QPixmap pixmapa(url);
    QPixmap pixmap(size,size);
    pixmap.fill(Qt::transparent);
    QPainter painter(&pixmap);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    QPainterPath path;
    path.addEllipse(0, 0, size, size);
    painter.setClipPath(path);
    painter.drawPixmap(0, 0, size, size, pixmapa);
    return pixmap;
}

bool isDirExistsAndCreateDir(QString dir)
{
    //如果文件夹未创建，则创建头像文件夹
    QDir Dir(dir);
    if (!Dir.exists())
        Dir.mkdir(Dir.absolutePath());
    return true;
}

bool isTableExistsAndCreateTables()
{
    QSqlDatabase db;
    if(QSqlDatabase::contains("qt_sql_default_connection"))
    {
        db = QSqlDatabase::database("qt_sql_default_connection");
    }
    else
    {
        db = QSqlDatabase::addDatabase("QSQLITE");
    }
    db.setDatabaseName("./qtdb.db");
    if (db.open())
    {
        QStringList lis = db.tables();
        if (!lis.contains("user"))
        {
            QSqlQuery sq(db);
            QString userSql = "CREATE TABLE airlines(\
                    airport_start VARCHAR2(10), \
                    airport_arrival VARCHAR2(10), \
                    airline_id VARCHAR2(15) PRIMARY KEY NOT NULL, \
                    leave_date DATE(1), \
                    leave_time TIME(1), \
                    arrival_date DATE(1), \
                    arrival_time TIME(1), \
                    price SMALLINT(1) DEFAULT 0, \
                    CHECK(price > 0))";
            sq.prepare(userSql);
            sq.exec();

            userSql = "CREATE TABLE user(\
                    username NVARCHAR2(20) PRIMARY KEY, \
                    password VARCHAR(20), \
                    isManager BOOL(1), \
                    head_url NVARCHAR(40) DEFAULT './head/no_head.jpg');";
            sq.exec(userSql);

            userSql = "CREATE TABLE U_A(\
                    username VARCHAR2(20) NOT NULL, \
                    airline_id NVARCHAR2(15) NOT NULL,\
                    price INT(1),\
                    order_date DATE(1), \
                    PRIMARY KEY(username, airline_idW)) WITHOUT ROWID";

            sq.exec(userSql);

            userSql = "INSERT INTO user values(?,?,?,?)";
            sq.prepare(userSql);
            sq.addBindValue("DJCTheManager");
            sq.addBindValue("djc123456");
            sq.addBindValue(true);
            sq.addBindValue("./head/no_head.png");

            sq.exec();

            isDirExistsAndCreateDir("./head");
            qDebug() << "not";
        }


    }
    return true;
}

bool isQStringTime(QString s)
{
    QStringList egspt= s.split(":");
    if (egspt.length()!=2)
        return false;
    else
        return true;

}

bool isQStringDate(QString s)
{
    QStringList egspt = s.split(".");
    if (egspt.length()==2 || egspt.length() == 3)
        return true;
    else
        return false;

}
