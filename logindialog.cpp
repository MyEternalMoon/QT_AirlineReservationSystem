#include "logindialog.h"
#include "ui_logindialog.h"


LogInDialog::LogInDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LogInDialog)
{
    ui->setupUi(this);
    _clickedFlag = 0;
    _mode = 0;
    _arth = 1;
    _headUrl = "./head/no_head.png";
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground, true);
    ui->nameWarningLabel->hide();
    ui->passwordWarningLabel->hide();
    ui->headSelectButton->hide();

    if(QSqlDatabase::contains("qt_sql_default_connection"))
    {
        _db = QSqlDatabase::database("qt_sql_default_connection");
    }
    else
    {
        _db = QSqlDatabase::addDatabase("QSQLITE");
    }
    _db.setDatabaseName("./qtdb.db");
    //initialize database connection.

    initSignalsAndSlots();
}

void LogInDialog::checkLogIn()
{
    QString user = ui->userNameLineEdit->text();
    QString pass = ui->passwordLineEdit->text();
    if (_mode == 1) // register and login(check if available & login)
    {
        if (registerUsers(user, pass))
        {
            if (!ui->managerCheckBox->isChecked())
                _arth = 1;
            MainWindow* w = new MainWindow(NULL,user.toStdString(),_headUrl,_arth);
            w->show();
            this->hide();
        }
        else
        {
            if (!isPasswordValid(pass))
            {
                ui->passwordWarningLabel->show();
            }
            if (!isNewUserValid((user)))
            {
                ui->nameWarningLabel->show();
            }
        }
    }

    else // connect to database and check if password is right.
    {
        if (checkPassword())
        {
            if (ui->managerCheckBox->isChecked())
                _arth = 1;
            MainWindow* w = new MainWindow(NULL,user.toStdString(),_headUrl,_arth);
            w->show();
            this->hide();
        }
        else
        {
            ui->passwordWarningLabel->show();
        }
    }
}

void LogInDialog::registerOnClicked()
{
    if (_mode == 0)
    {
        _mode = 1;
        ui->loginButton->setText(QString::fromLocal8Bit("×¢²á"));
        ui->managerCheckBox->hide();
        ui->headSelectButton->setText(QString::fromLocal8Bit("Ñ¡ÔñÍ·Ïñ"));
        ui->headSelectButton->show();
        ui->registerButton->setStyleSheet("QPushButton#registerButton{border-image: url(:/img_normal/login.png);}\
                                      QPushButton#registerButton:hover{border-image: url(:/img_hover/login_hover.png);}\
                                       QPushButton#registerButton:pressed{border-image: url(:/img_normal/login.png);}");
    }
    else
    {
        _mode = 0;
        ui->loginButton->setText(QString::fromLocal8Bit("µÇ Â¼"));
        ui->managerCheckBox->show();
        ui->headSelectButton->hide();
        ui->registerButton->setStyleSheet("QPushButton#registerButton{border-image: url(:/img_normal/register.png);}\
                                      QPushButton#registerButton:hover{border-image: url(:/img_hover/register_hover.png);}\
                                       QPushButton#registerButton:pressed{border-image: url(:/img_normal/register.png);}");
    }
}

void LogInDialog::initSignalsAndSlots()
{
    connect(ui->exitButton,SIGNAL(clicked()),this,SLOT(close()));
    connect(ui->loginButton,SIGNAL(clicked(bool)),this,SLOT(checkLogIn()));
    connect(ui->registerButton,SIGNAL(clicked()),this,SLOT(registerOnClicked()));
    connect(ui->headSelectButton,SIGNAL(clicked(bool)),this,SLOT(selectHead()));
}

LogInDialog::~LogInDialog()
{
    delete ui;
}
