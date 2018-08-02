#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QtWidgets/QWidget>
#include <QLabel>
#include <QGraphicsDropShadowEffect>
#include "ui_mywidget.h"
#include "./net_server.h"
#include "./appdisplay.h"
#include <QLineEdit>
#include <QPixmap>
#include <unistd.h>
#include "wating.h"
class QStackedWidget;
class QPushButton;
namespace Ui {
class myWidget;
}

class myWidget : public QWidget
{
    Q_OBJECT

public:
    explicit myWidget(QWidget *parent = 0);
    ~myWidget();

public slots:
    void slt_setPageWidget();//根据所点击的按钮来进行相应widget显示的槽
    void login_server();//登录处理函数
    void reg_server();//注册处理函数
    void myclose();

signals:
    void IamClose();

private:
    Ui::myWidget *ui;
    QStackedWidget *stackWidget;
    QPushButton *pageButton;
    QPushButton *page2Button;
    QPushButton *login_btn;
    QPushButton *reg_btn;
    QLineEdit *reg_username_txt;
    QLineEdit *reg_password_txt;
    QLineEdit *reg_make_sure_txt;
    QLineEdit *reg_phone_txt;

    QLineEdit *username_txt ;
    QLineEdit *password_txt ;
    QLabel *line;

    QString username_str;
    QString password_str;
    QString reg_username_str;
    QString reg_password_str;
    QString reg_make_sure_str;
    QString reg_phone_str;

    QLabel *tips1;
    QLabel *tips2;
    QLabel *tips3;
    QLabel *tips4;
};

#endif // MYWIDGET_H
