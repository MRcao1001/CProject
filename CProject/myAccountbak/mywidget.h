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
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QRadioButton>
#include <QTextEdit>
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
    void InitializationWidget();
    void set_up_layout();

public slots:
    void slt_setPageWidget();//根据所点击的按钮来进行相应widget显示的槽
    void login_server();//登录处理函数
    void reg_server();//注册处理函数
    void myclose();
    void m_isChecked();

signals:
    void IamClose();
    void server_is_returned_true();
    void server_is_returned_false();

private:
    Ui::myWidget *ui;
    QFrame *headFrame;
    QStackedWidget *stackWidget;
    QPushButton *pageButton;
    QPushButton *page2Button;
    QPushButton *login_btn;
    QPushButton *cancle;
    QHBoxLayout *login_tips;
    QHBoxLayout *reg_tips;
    QPushButton *login_tip1;
    QPushButton *login_tip2;
    QPushButton *reg_tip1;
    QPushButton *reg_btn;
    QLineEdit *reg_username_txt;
    QLineEdit *reg_password_txt;
    QLineEdit *reg_make_sure_txt;
    QLineEdit *reg_phone_txt;
    QWidget *widget[3];
    QLineEdit *username_txt ;
    QLineEdit *password_txt ;
    QLabel *line;
    QVBoxLayout *layout_login;
    QHBoxLayout *pic_layout_login;
    //创建图片容器设置其样式----star
    QLabel *label_login_title;
    QLabel *label_login_tips;
    QHBoxLayout *title_layout_login;
    QHBoxLayout *tips_layout_login;
    QLabel *label_login;
    QGraphicsDropShadowEffect *effectlabel_login;
    QString username_str;
    QString password_str;
    QString reg_username_str;
    QString reg_password_str;
    QString reg_make_sure_str;
    QString reg_phone_str;
    QMovie *loginmv;
    QLabel *username_pic;
    QLabel *password_pic;
    QHBoxLayout *group;
    //创建两个纵向排列布局
    QVBoxLayout *pic_group;
    QVBoxLayout *input_group;
    //创建一个button布局
    QHBoxLayout *button_group;
    QVBoxLayout *layout_reg;
    QHBoxLayout *pic_layout_reg;
    QLabel *label_reg;
    QGraphicsDropShadowEffect *effectlabel_reg;
    QLabel *reg_username_pic;
    QLabel *reg_password_pic;
    QLabel *reg_make_sure_pic;
    QLabel *reg_phone_pic;
    QHBoxLayout *reg_group;
    //创建三个个个纵向排列布局
    QVBoxLayout *reg_pic_group;
    QVBoxLayout *reg_input_group;
    QVBoxLayout *tips_img_group;
    //创建一个button布局
    QHBoxLayout *reg_button_group;
    QHBoxLayout *menu_bar;
    QVBoxLayout *mainLayout;
    //注册的gif
    QMovie *regmv;
    QLabel *tips1;
    QLabel *tips2;
    QLabel *tips3;
    QLabel *tips4;
    //注册条款界面
    QVBoxLayout *clause_box;
    QHBoxLayout *clause_title_box;
    QLabel *clause_title;
    QHBoxLayout *clause_page_box;
    QTextEdit *clause_page;
    QHBoxLayout *clause_agree_box;
    QRadioButton *clause_agree;
    QLabel *clause_agree_tips;
    QHBoxLayout *clause_button_box;
    QPushButton *clause_back;
    QPushButton *clause_next;
};

#endif // MYWIDGET_H
