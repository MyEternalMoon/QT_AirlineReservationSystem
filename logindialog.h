#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include "mainwindow.h"
#include "commonfunctions.h"
#include <QString>
#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>


namespace Ui {
class LogInDialog;
}

class LogInDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LogInDialog(QWidget *parent = 0);
    ~LogInDialog();

private:
    int _mode;
    //mode = 1: registering; mode = 0: login.
    int _clickedFlag;
    string _headUrl;
    int _arth;
    QPoint _mousePos;
    QPoint _windowPos;
    QSqlDatabase _db;
    Ui::LogInDialog *ui;

    int checkPassword();
    int registerUsers(QString user, QString pass);
    int isNewUserValid(QString user);
    int isPasswordValid(QString pass);

protected:
    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);

private slots:
    /*!
     * \brief selectHead
     * When select head button is clicked call this method
     * Open a FileDialog and choose a picture(or default head)
     * The picture will be copied to a certain directory and the new url is an attribute in database
     */
     void selectHead();

    /*!
     * \brief checkLogIn
     * When login button is clicked call this method
     * In this method, Qt connects to database and check if account exists or if the password is right
     * If wrong, information is shown, else the head picture will be changed.
     * Then open main window and hide login dialog.
     *
     * If it is working in mode 1(register)
     * Check if name and password valid, and copy head, and insert them into database.
     */
    void checkLogIn();


    /*!
     * \brief registerOnClicked
     * When register button is clicked ,call this method.
     * Change working mode to register mode(mode 1) and hide some labels.
     * In this method, Qt connects to database and create a new account.
     * Then call checkLogin()
     */
    void registerOnClicked();


    /*!
     * \brief initSignalsAndSlots
     */
    void initSignalsAndSlots();

//signals:
//    void openMainWindow(QString, int);
};


#endif // LOGINDIALOG_H
