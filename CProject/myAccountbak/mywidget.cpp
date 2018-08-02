#include "mywidget.h"
#include <qgridlayout.h>
#include <qlabel.h>
#include <qpushbutton.h>
#include <qstackedwidget.h>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDebug>
#include <QMovie>
#include <QGraphicsDropShadowEffect>
#include <QLineEdit>
#include <QPixmap>
#include <QHelpEvent>
#include <QToolTip>
#include <QMessageBox>

myWidget::myWidget(QWidget *parent)
    : QWidget(parent)
{
    ui->setupUi(this);
    QPalette palette(this->palette());
    palette.setColor(QPalette::Background, Qt::black);
    this->setPalette(palette);
    this->setWindowTitle(QObject::tr("欢迎登录，注册 "));
/*----star*************************************标题选项卡布局设置**************************************/
    //创建QStackedWidget对象
    stackWidget = new QStackedWidget;
    //创建几个QPushButton来控制widget的显示
    pageButton = new QPushButton();
    page2Button = new QPushButton();
    line=new QLabel();

    //设置头部按钮的按下,接触,离开三个状态的样式
        //按钮"登录"
    pageButton->setText(u8"登录");
    pageButton->setGeometry(0,0,80,50);
    pageButton->setStyleSheet(QString("QPushButton{font-size:32px;color:#404040;background:#fff;border:none;margin-top:20px;margin-left:10px;}\
                                      QPushButton:hover{color:#707070;}\
                                      QPushButton:pressed{color:#a0a0a0;}"));
        //按钮"注册"
    page2Button->setText(u8"注册");
    page2Button->setGeometry(0,0,80,50);
    page2Button->setStyleSheet(QString("QPushButton{font-size:22px;color:#a0a0a0;background:#fff;border:none;margin-top:30px;margin-left:10px;}\
                                      QPushButton:hover{color:#707070;}\
                                      QPushButton:pressed{color:#a0a0a0;}"));

    //将两个个按钮的clicked事件绑定到函数
    connect(pageButton, &QPushButton::clicked, this, &myWidget::slt_setPageWidget);
    connect(page2Button, &QPushButton::clicked, this, &myWidget::slt_setPageWidget);
    //创建两个个QWidget对象
    QWidget *widget[2];
/*----end*************************************标题选项卡布局设置*************************************************************/




/*---star***********************************登录页面的布局操作**************************************************************/

        //按照下标进行一下QWidget的区分
        widget[0] = new QWidget;
        widget[0]->resize(400, 400);
        QVBoxLayout *layout_login = new QVBoxLayout;
        QHBoxLayout *pic_layout_login = new QHBoxLayout;

        //创建图片容器设置其样式----star
        QLabel *label_login = new QLabel();
        QGraphicsDropShadowEffect *effectlabel_login = new QGraphicsDropShadowEffect;
        effectlabel_login->setBlurRadius(14);        // 阴影圆角的大小
        effectlabel_login->setColor(Qt::gray);      //阴影的颜色
        effectlabel_login->setOffset(0,2);
        label_login->setGraphicsEffect(effectlabel_login);
        //创建gif空间,置于图片容器
            //登录的gif
        QMovie *loginmv = new QMovie(":/Img/regImg.gif");
        loginmv->setScaledSize(QSize(400,300));


        //创建图片容器设置其样式----end

        //创建提示图标&输入框---star
            //登录部分
        QLabel *username_pic = new QLabel();
        QPixmap user_icon(":/Img/User.png");
        QLabel *password_pic = new QLabel();
        QPixmap pwd_icon(":/Img/pwd.png");
        username_txt = new QLineEdit();
        password_txt = new QLineEdit();
        login_btn =  new QPushButton();
        //绑定登录按钮到槽函数
        connect(login_btn,&QPushButton::clicked,this,&myWidget::login_server);
        //创建一个横向排列布局
        QHBoxLayout *group = new QHBoxLayout;
        //创建两个个纵向排列布局
        QVBoxLayout *pic_group = new QVBoxLayout;
        QVBoxLayout *input_group = new QVBoxLayout;
        //创建一个button布局
        QHBoxLayout *button_group = new QHBoxLayout;
                //动图显示部分
            label_login->setMovie(loginmv);
            label_login->setStyleSheet("border-radius:12px;padding:2px 4px;");
            loginmv->start();
                //输入框部分和按钮样式设置
            username_txt->setFont(QFont("Source Code Pro for Powerline" , 12 ,  QFont::Normal));
            username_txt->setPlaceholderText("手机号/邮箱/QQ号");
            username_txt->setFixedWidth(250);
            username_txt->setMaxLength(64);
            username_txt->setAlignment(Qt::AlignCenter);
            username_txt->setStyleSheet("margin-bottom:10px;margin-left:20px;border:1px groove #a0a0a0;border-radius:6px;padding:8px 10px;");

            password_txt->setFont(QFont("Source Code Pro for Powerline" , 12 ,  QFont::Normal));
            password_txt->setContextMenuPolicy(Qt::NoContextMenu);
            password_txt->setPlaceholderText("密码");
            password_txt->setEchoMode(QLineEdit::Password);
            password_txt->setFixedWidth(250);
            password_txt->setMaxLength(12);
            password_txt->setAlignment(Qt::AlignCenter);
            password_txt->setStyleSheet("margin-top:10px;margin-left:20px;border:2px groove #a0a0a0;border-radius:6px;padding:8px 50px;");

            username_pic->setPixmap(user_icon);
            username_pic->resize(user_icon.width(),user_icon.height());
            password_pic->setPixmap(pwd_icon);
            password_pic->resize(user_icon.width(),user_icon.height());

            login_btn->setStyleSheet(QString("QPushButton{font-size:16px;color:#fff;background:#4169E1;border:none;border-radius:10px;padding:8px 50px;margin-top:20px;margin-left:10px;}\
                                              QPushButton:hover{background:#fff;color:#2e59dc;border:2px groove #4169E1}\
                                              QPushButton:pressed{color:#fff;background:#2e59dc;border:none}"));
            login_btn->setText(u8"完 成");



            //将输入框和提示图标元素置入其对应的布局
            pic_group->addWidget(username_pic);
            pic_group->addStretch();
            pic_group->addWidget(password_pic);

            input_group->addWidget(username_txt);
            input_group->addStretch();
            input_group->addWidget(password_txt);

            button_group->addStretch();
            button_group->addWidget(login_btn);
            button_group->addStretch();

            //将输入框布局和图标布局置入其父布局
            group->addStretch();
            group->addLayout(pic_group);
            group->addLayout(input_group);
            group->addStretch();

            //向图片布局两侧添加弹簧
            pic_layout_login->addStretch();
            pic_layout_login->addWidget(label_login);
            pic_layout_login->addStretch();
            //将以上布局置入主布局
            layout_login->addLayout(pic_layout_login);
            layout_login->addStretch();
            layout_login->addLayout(group);
            layout_login->addStretch();
            layout_login->addLayout(button_group);
            layout_login->addStretch();
            //将添加了不同控件的主布局置入到对应的widget[]中
            widget[0]->setLayout(layout_login);
            //调用stackWidget方法添加三个widget到页面
            stackWidget->addWidget(widget[0]);
/*---end***********************************登录页面的布局操作**************************************************************/

/*---star***********************************注册页面的布局操作**************************************************************/

            //注册部分页面元素设置
            //按照下标进行一下QWidget的区分
            widget[1] = new QWidget;
            widget[1]->resize(400, 400);
            QVBoxLayout *layout_reg = new QVBoxLayout;
            QHBoxLayout *pic_layout_reg = new QHBoxLayout;

            //创建图片容器设置其样式----star
            QLabel *label_reg = new QLabel();
            QGraphicsDropShadowEffect *effectlabel_reg = new QGraphicsDropShadowEffect;
            effectlabel_reg->setBlurRadius(14);        // 阴影圆角的大小
            effectlabel_reg->setColor(Qt::gray);      //阴影的颜色
            effectlabel_reg->setOffset(0,2);
            label_reg->setGraphicsEffect(effectlabel_reg);
            //注册部分
            QLabel *reg_username_pic = new QLabel();
            QPixmap reg_user_icon(":/Img/reg_usr.png");
            QLabel *reg_password_pic = new QLabel();
            QPixmap reg_password_icon(":/Img/reg_pwd.png");
            QLabel *reg_make_sure_pic = new QLabel();
            QPixmap reg_make_sure_icon(":/Img/makesure_pwd.png");
            QLabel *reg_phone_pic = new QLabel();
            QPixmap reg_phone_icon(":/Img/phone.png");

            tips1 = new QLabel();
            tips2 = new QLabel();
            tips3 = new QLabel();
            tips4 = new QLabel();

            reg_username_txt = new QLineEdit();
            reg_password_txt = new QLineEdit();
            reg_make_sure_txt = new QLineEdit();
            reg_phone_txt = new QLineEdit();
            reg_btn = new QPushButton();
            //绑定注册按钮到槽函数
            connect(reg_btn, &QPushButton::clicked,this,&myWidget::reg_server);
            //创建一个横向排列布局
            QHBoxLayout *reg_group = new QHBoxLayout;
            //创建三个个个纵向排列布局
            QVBoxLayout *reg_pic_group = new QVBoxLayout;
            QVBoxLayout *reg_input_group = new QVBoxLayout;
            QVBoxLayout *tips_img_group = new QVBoxLayout;
            //创建一个button布局
            QHBoxLayout *reg_button_group = new QHBoxLayout;

            //注册的gif
            QMovie *regmv = new QMovie(":/Img/1010.gif");
            regmv->setScaledSize(QSize(400,270));
            //动图设置
            label_reg->setMovie(regmv);
            label_reg->setStyleSheet("border-radius:10px;padding:2px 4px;");
            regmv->start();
            //图标设置
            reg_username_pic->setPixmap(reg_user_icon);
            reg_username_pic->resize(reg_user_icon.width(),reg_user_icon.height());
            reg_password_pic->setPixmap(reg_password_icon);
            reg_password_pic->resize(reg_password_icon.width(),reg_password_icon.height());
            reg_make_sure_pic->setPixmap(reg_make_sure_icon);
            reg_make_sure_pic->resize(reg_make_sure_icon.width(),reg_make_sure_icon.height());
            reg_phone_pic->setPixmap(reg_phone_icon);
            reg_phone_pic->resize(reg_phone_icon.width(),reg_phone_icon.height());

            //输入框设置
            reg_username_txt->setFont(QFont("Source Code Pro for Powerline" , 12 ,  QFont::Normal));
            reg_username_txt->setPlaceholderText("手机号/QQ号/邮箱");
            reg_username_txt->setFixedWidth(250);
            reg_username_txt->setMaxLength(64);
            reg_username_txt->setAlignment(Qt::AlignCenter);
            reg_username_txt->setStyleSheet("margin-top:10px;margin-left:20px;border:1px groove #a0a0a0;border-radius:6px;padding:8px 10px;");

            reg_password_txt->setFont(QFont("Source Code Pro for Powerline" , 12 ,  QFont::Normal));
            reg_password_txt->setContextMenuPolicy(Qt::NoContextMenu);
            reg_password_txt->setPlaceholderText("请输入密码");
            reg_password_txt->setEchoMode(QLineEdit::Password);
            reg_password_txt->setFixedWidth(250);
            reg_password_txt->setMaxLength(12);
            reg_password_txt->setAlignment(Qt::AlignCenter);
            reg_password_txt->setStyleSheet("margin-top:10px;margin-left:20px;border:2px groove #a0a0a0;border-radius:6px;padding:8px 50px;");

            reg_make_sure_txt->setFont(QFont("Source Code Pro for Powerline" , 12 ,  QFont::Normal));
            reg_make_sure_txt->setContextMenuPolicy(Qt::NoContextMenu);
            reg_make_sure_txt->setPlaceholderText("确认密码");
            reg_make_sure_txt->setEchoMode(QLineEdit::Password);
            reg_make_sure_txt->setFixedWidth(250);
            reg_make_sure_txt->setMaxLength(12);
            reg_make_sure_txt->setAlignment(Qt::AlignCenter);
            reg_make_sure_txt->setStyleSheet("margin-top:10px;margin-left:20px;border:2px groove #a0a0a0;border-radius:6px;padding:8px 50px;");

            reg_phone_txt->setFont(QFont("Source Code Pro for Powerline" , 12 ,  QFont::Normal));
            reg_phone_txt->setPlaceholderText("请输入手机号用于找回密码");
            reg_phone_txt->setFixedWidth(250);
            reg_phone_txt->setMaxLength(11);
            reg_phone_txt->setAlignment(Qt::AlignCenter);
            reg_phone_txt->setStyleSheet("margin-top:10px;margin-left:20px;border:1px groove #a0a0a0;border-radius:6px;padding:8px 50px;");

            reg_btn->setStyleSheet(QString("QPushButton{font-size:16px;color:#fff;background:#4169E1;border:none;border-radius:10px;padding:8px 50px;margin-top:20px;margin-left:10px;}\
                                           QPushButton:hover{background:#fff;color:#2e59dc;border:2px groove #4169E1}\
                                           QPushButton:pressed{color:#fff;background:#2e59dc;border:none}"));
                                           reg_btn->setText(u8"加 入");


            tips1->setStyleSheet("margin-top:8px");
            tips2->setStyleSheet("margin-top:8px");
            tips3->setStyleSheet("margin-top:8px");
            tips4->setStyleSheet("margin-top:8px");


            reg_pic_group->addWidget(reg_username_pic);
            reg_pic_group->addWidget(reg_password_pic);
            reg_pic_group->addWidget(reg_make_sure_pic);
            reg_pic_group->addWidget(reg_phone_pic);

            reg_input_group->addWidget(reg_username_txt);
            reg_input_group->addWidget(reg_password_txt);
            reg_input_group->addWidget(reg_make_sure_txt);
            reg_input_group->addWidget(reg_phone_txt);

            tips_img_group->addWidget(tips1);
            tips_img_group->addWidget(tips2);
            tips_img_group->addWidget(tips3);
            tips_img_group->addWidget(tips4);

            reg_button_group->addStretch();
            reg_button_group->addWidget(reg_btn);
            reg_button_group->addStretch();

            reg_group->addStretch();
            reg_group->addLayout(reg_pic_group);
            reg_group->addLayout(reg_input_group);
            reg_group->addLayout(tips_img_group);
            reg_group->addStretch();
            //向图片布局两侧添加弹簧
            pic_layout_reg->addStretch();
            pic_layout_reg->addWidget(label_reg);
            pic_layout_reg->addStretch();
            //将以上布局置入主布局
            layout_reg->addLayout(pic_layout_reg);
            layout_reg->addStretch();
            layout_reg->addLayout(reg_group);
            layout_reg->addStretch();
            layout_reg->addLayout(reg_button_group);
            layout_reg->addStretch();
            //将添加了不同控件的主布局置入到对应的widget[]中
            widget[1]->setLayout(layout_reg);
            //调用stackWidget方法添加三个widget到页面
            stackWidget->addWidget(widget[1]);

            /*---end***********************************注册页面的布局操作**************************************************************/



            /*---star***************************创建一个头部选项卡布局并置入两个按钮*******××××××××××××××××××××××**************************/
            QHBoxLayout *menu_bar = new QHBoxLayout;
            menu_bar->addWidget(pageButton);
            menu_bar->addWidget(line);
            menu_bar->addWidget(page2Button);
            menu_bar->addStretch();
            /*---end***************************创建一个头部选项卡布局并置入两个按钮*********××××××××××××××××××××××************************/




            /*---star******************************将布局内容显示到窗口************************************××××××××××××××××××××××*******/
            //将之前创建的:头部选项卡布局,可变页面布局,完成按钮全部置入mainlayout
            QVBoxLayout *mainLayout = new QVBoxLayout;
            mainLayout->addLayout(menu_bar);
            mainLayout->addWidget(stackWidget);

            //显示mainlayout布局
            setLayout(mainLayout);
            /*---end******************************将布局内容显示到窗口**********************************××××××××××××××××××××××××*********/

}


/*---star***********************点击不同的标题选项卡切换不同界面的函数*************×××××××××××××××××××××××××*********************/
void myWidget::slt_setPageWidget()
{
    //获取触发槽的是哪个部件所发出的信号，并获取到那个指针
    QPushButton *widget = static_cast<QPushButton*>(sender());
    if (widget == pageButton)
    {
        widget->setStyleSheet(QString("QPushButton{font-size:32px;color:#404040;background:#fff;border:none;margin-top:20px;margin-left:10px;}\
                                      QPushButton:hover{color:#707070;}\
                                      QPushButton:pressed{color:#a0a0a0;}"));
        page2Button->setStyleSheet(QString("QPushButton{font-size:22px;color:#a0a0a0;background:#fff;border:none;margin-top:20px;margin-left:10px;}\
                                           QPushButton:hover{color:#707070;}\
                                           QPushButton:pressed{color:#a0a0a0;}"));
        stackWidget->setCurrentIndex(0);//根据触发的按钮来进行所要显示的QWidget
    }
    else if (widget == page2Button)
    {
        widget->setStyleSheet(QString("QPushButton{font-size:32px;color:#404040;background:#fff;border:none;margin-top:20px;margin-left:10px;}\
                                      QPushButton:hover{color:#707070;}\
                                      QPushButton:pressed{color:#a0a0a0;}"));
        pageButton->setStyleSheet(QString("QPushButton{font-size:22px;color:#a0a0a0;background:#fff;border:none;margin-top:20px;margin-left:10px;}\
                                          QPushButton:hover{color:#707070;}\
                                          QPushButton:pressed{color:#a0a0a0;}"));
        stackWidget->setCurrentIndex(1);
    }

}
/*---end*************************点击不同的标题选项卡切换不同界面的函数******************×××××××××××××××××××××××××****************/


/*---star***********************点击登录/注册获取输入框的内容并且传递到服务器判断***********************××××××××××××××××*************/
void myWidget::myclose(){
    IamClose();
    this->close();
}

void myWidget::login_server(){
    net_server net;
    username_str = username_txt->text();
    password_str =password_txt->text();
    qDebug()<<"按下了登录"<<endl<<"用户名："<<username_str<<endl<<"密码："<<password_str;
    if(username_txt == NULL || password_txt == NULL){
        QMessageBox::about(this,tr("无法登录"),tr("\n        用户名或者密码为空！         \n"));
        return;
    }
    int ret = net.login_server(username_str,password_str);
    qDebug()<<"myWidget::login_server--->获取到loginserver的返回值"<<ret<<endl;
    login_btn->setText(u8"完 成");
    if(ret == 1){
        wating *w = new wating(this);
        w->setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
        w->setWindowModality(Qt::ApplicationModal);
        w->move(880,450);
        w->show();
        connect(w,SIGNAL(loading()),this,SLOT(myclose()));
//        QMessageBox::about(this,tr("提示"),tr("\n   登录成功    \n"));
//        IamClose();
//        this->close();
        return;
    }

    else if(ret == 0) {
        QMessageBox::about(this,tr("提示"),tr("\n   用户名或密码错误    \n"));
        return;
    }
    else {
        QMessageBox::about(this,tr("提示"),tr("无法连接到服务器，请检查网络连接后再试！"));
        return;
    }
}

void myWidget::reg_server(){
    net_server net;
    reg_username_str = reg_username_txt->text();
    reg_password_str = reg_password_txt->text();
    reg_make_sure_str = reg_make_sure_txt->text();
    reg_phone_str = reg_phone_txt->text();
    qDebug()<<"按下了注册"<<endl<<"用户名："<<reg_username_str<<endl<<"密码："<<reg_password_str<<endl<<"确认密码："<<reg_make_sure_str<<endl<<"手机号："<<reg_phone_str;


    QPixmap tips_true_img(":/Img/true.png");
    QPixmap tips_error_img(":/Img/error.png");
    tips1->setToolTip("格式正确");
    tips2->setToolTip("格式正确");
    tips3->setToolTip("格式正确");
    tips4->setToolTip("格式正确");
    tips1->setPixmap(tips_true_img);
    tips1->resize(tips_true_img.width(),tips_true_img.height());
    tips2->setPixmap(tips_true_img);
    tips2->resize(tips_true_img.width(),tips_true_img.height());
    tips3->setPixmap(tips_true_img);
    tips3->resize(tips_true_img.width(),tips_true_img.height());
    tips4->setPixmap(tips_true_img);
    tips4->resize(tips_true_img.width(),tips_true_img.height());
    if(reg_username_str == NULL){
        tips1->setToolTip("用户名不能为空");
        tips1->setPixmap(tips_error_img);
        tips1->resize(tips_error_img.width(),tips_error_img.height());
    }
    else if(reg_password_str != reg_make_sure_str){
        tips2->setToolTip("两次输入的密码不相同");
        tips3->setPixmap(tips_error_img);
        tips3->resize(tips_error_img.width(),tips_error_img.height());
        tips2->setPixmap(tips_error_img);
        tips2->resize(tips_error_img.width(),tips_error_img.height());
    }
    else if(reg_password_str == NULL || reg_make_sure_str == NULL){
        tips2->setToolTip("密码不能为空");
        tips3->setToolTip("密码不能为空");
        tips2->setPixmap(tips_error_img);
        tips2->resize(tips_error_img.width(),tips_error_img.height());
        tips3->setPixmap(tips_error_img);
        tips3->resize(tips_error_img.width(),tips_error_img.height());
    }
    else if(reg_phone_str == NULL){
        tips4->setToolTip("手机号不能为空");
        tips4->setPixmap(tips_error_img);
        tips4->resize(tips_error_img.width(),tips_error_img.height());
    }
    else {
        tips1->setPixmap(tips_true_img);
        tips1->resize(tips_true_img.width(),tips_true_img.height());
        tips2->setPixmap(tips_true_img);
        tips2->resize(tips_true_img.width(),tips_true_img.height());
        tips3->setPixmap(tips_true_img);
        tips3->resize(tips_true_img.width(),tips_true_img.height());
        tips4->setPixmap(tips_true_img);
        tips4->resize(tips_true_img.width(),tips_true_img.height());
        int ret=net.reg_server(reg_username_str,reg_password_str,reg_phone_str);
        if(ret == 1){
            QMessageBox::about(this,tr("提示"),tr("注册成功"));
            //this->close();
            pageButton->setStyleSheet(QString("QPushButton{font-size:32px;color:#404040;background:#fff;border:none;margin-top:20px;margin-left:10px;}\
                                          QPushButton:hover{color:#707070;}\
                                          QPushButton:pressed{color:#a0a0a0;}"));
            page2Button->setStyleSheet(QString("QPushButton{font-size:22px;color:#a0a0a0;background:#fff;border:none;margin-top:20px;margin-left:10px;}\
                                               QPushButton:hover{color:#707070;}\
                                               QPushButton:pressed{color:#a0a0a0;}"));
            stackWidget->setCurrentIndex(0);//根据触发的按钮来进行所要显示的QWidget
            return;
        }

        else if(ret == 0) {
            QMessageBox::about(this,tr("提示"),tr("注册失败"));
            return;
        }

        else if(ret == 2) {
            QMessageBox::about(this,tr("提示"),tr("用户已经被注册，请更换用户名"));
            return;
        }
        else {
            QMessageBox::about(this,tr("提示"),tr("无法连接到服务器，请检查网络连接后再试！"));
            return;
        }
    }



}

/*---end***********************点击登录/注册获取输入框的内容并且传递到服务器判断******************××××××××××××××××******************/

myWidget::~myWidget()
{

}
