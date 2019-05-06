#include "ui_logindialog.h"
#include "logindialog.h"
#include <QFileDialog>


int LogInDialog::checkPassword()
{
    // set data base properities.
    if (_db.open())
    {
        QSqlQuery sq(_db);
        QString userName = ui->userNameLineEdit->text();
        QString userSql = QString::asprintf("SELECT password, isManager, head_url FROM user WHERE username = \'%s\'",
                                            userName.toStdString().c_str());
        QString enteredPass = ui->passwordLineEdit->text();
        QString correctPass;

        sq.prepare(userSql);
        sq.exec();
        // execute query.

        while (sq.next())
        {
             correctPass = sq.value(0).toString();
             _arth = sq.value(1).toBool();
             _headUrl = sq.value(2).toString().toStdString();
        }
        if (!enteredPass.isEmpty() && enteredPass.compare(correctPass) == 0)
        {
            _db.close();
            return 1;     // correct
        }
        else
        {
            _db.close();
            return 0;//wrong password.
        }
    }
    else
    {
        //Show infomation.
        ui->loginButton->setText("无法连接数据库!");
        return 0;
    }
}

int LogInDialog::isNewUserValid(QString user)
{
    if (_db.open())
    {
        QSqlQuery sq(_db);
        QString userSql = QString::asprintf("SELECT count(*) FROM user WHERE username = \'%s\'",
                                            user.toStdString().c_str());
        sq.prepare(userSql);
        sq.exec();
        sq.next();
        if (sq.value(0).toInt() == 0)
        {
            _db.close();
            return 1; // Valid
        }
        else
        {
            _db.close();
            return 0;
        }
    }
    else
    {
        return 0;
    }
}

int LogInDialog::isPasswordValid(QString pass)
{
    if (pass.size() < 6)
    {
        return 0; // invalid
    }
    else
    {
        return 1;
    }
}

int LogInDialog::registerUsers(QString user, QString pass)
{
    if (isNewUserValid(user) && isPasswordValid(pass))
    {
        if (_db.open())
        //Do something in database
        {
            QSqlQuery sq(_db);
            QString userQuery ="INSERT INTO user values(? ,?, ?, ?)";
            sq.prepare(userQuery);
            sq.addBindValue(user);
            sq.addBindValue(pass);
            sq.addBindValue(false);
            sq.addBindValue(_headUrl.c_str());
            sq.exec();
            _db.commit();
            _db.close();
        }
        return 1;
    }
    else
    {
//        qDebug() << "Invalid";
        return 0;
    }
}

void LogInDialog::selectHead()
{
    QFileDialog *fileDialog = new QFileDialog();
    fileDialog->setWindowTitle(QString("Choose Head"));
    fileDialog->setDirectory("");
    fileDialog->setNameFilter(tr("Images(*.png *.jpg *.jpeg)"));
    //设置可以选择多个文件,默认为只能选择一个文件QFileDialog::ExistingFiles
    fileDialog->setFileMode(QFileDialog::ExistingFiles);
    fileDialog->setViewMode(QFileDialog::Detail);

    QStringList fileNames;
    QString dstUrl; // 存入head路径的最终url(QString)
    if(fileDialog->exec())
    {
        fileNames = fileDialog->selectedFiles();
        QString dstName = fileNames.at(0).section("/",-1,-1);
        dstName = dstName.split(".").at(0);
        dstUrl = QString::asprintf("./head/%s.png",dstName.toStdString().c_str());

        isDirExistsAndCreateDir("./head");
        //把头像复制到文件夹中储存，这里可能有毛病，会覆盖同名
        copyFileToPath(fileNames.at(0),dstUrl,0);
        _headUrl = dstUrl.toStdString();

        QPixmap pixmap = radiusPix(dstUrl,100);
        ui->headLabel->setPixmap(pixmap);
        delete fileDialog;
    }
}
