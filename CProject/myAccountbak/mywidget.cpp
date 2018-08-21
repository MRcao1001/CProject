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
    //设置界面背景色
    QPalette palette(this->palette());
    palette.setColor(QPalette::Background, Qt::white);

    this->setPalette(palette);
    this->setFixedSize(500, 700);
    this->setWindowTitle(QObject::tr("欢迎登录，注册 "));
    this->setStyleSheet("background-image:url(:/Img/bg_osx.png)");
    //初始化界面元素
    InitializationWidget();
    //设置界面元素的样式及布局
    set_up_layout();
    //    if(clause_agree->isChecked()){
    //        qDebug()<<"选择了";
    //        clause_next->setEnabled(true);
    //        qApp->processEvents();
    //    }
    //按钮信号绑定槽函数
    connect(reg_tip1, &QPushButton::clicked, this, &myWidget::slt_setPageWidget);
    connect(login_tip1, &QPushButton::clicked, this, &myWidget::slt_setPageWidget);
    connect(login_btn, &QPushButton::clicked, this, &myWidget::login_server);
    connect(reg_btn, &QPushButton::clicked, this, &myWidget::reg_server);
    connect(clause_agree, &QRadioButton::toggled, this, &myWidget::m_isChecked);
    connect(clause_back, &QPushButton::clicked, this, &myWidget::slt_setPageWidget);
    connect(clause_next, &QPushButton::clicked, this, &myWidget::slt_setPageWidget);
}

myWidget::~myWidget()
{
}

/*此函数在窗口对象生成后立即调用,初始化所有窗口部件*/
void myWidget::InitializationWidget()
{

    stackWidget = new QStackedWidget; //创建QStackedWidget对象
    headFrame = new QFrame(this);     //菜单背景
    pageButton = new QPushButton();   //创建登录标签按钮
    page2Button = new QPushButton();  //创建
    line = new QLabel();
    //按照下标进行一下QWidget的区分
    widget[0] = new QWidget;

    layout_login = new QVBoxLayout;
    title_layout_login = new QHBoxLayout;
    tips_layout_login = new QHBoxLayout;
    pic_layout_login = new QHBoxLayout;

    //创建图片容器设置其样式----star
    label_login = new QLabel();
    label_login_title = new QLabel();
    label_login_tips = new QLabel();
    effectlabel_login = new QGraphicsDropShadowEffect;
    loginmv = new QMovie(":/Img/regImg.gif");
    //创建提示图标&输入框---star
    //登录部分
    username_pic = new QLabel();
    password_pic = new QLabel();
    username_txt = new QLineEdit();
    password_txt = new QLineEdit();
    login_btn = new QPushButton();
    cancle = new QPushButton();
    login_tips = new QHBoxLayout;
    login_tip1 = new QPushButton();
    login_tip2 = new QPushButton();

    group = new QHBoxLayout;
    //创建两个纵向排列布局
    pic_group = new QVBoxLayout;
    input_group = new QVBoxLayout;
    //创建一个button布局
    button_group = new QHBoxLayout;
    widget[1] = new QWidget;
    layout_reg = new QVBoxLayout;
    pic_layout_reg = new QHBoxLayout;

    //创建图片容器设置其样式----star
    label_reg = new QLabel();
    effectlabel_reg = new QGraphicsDropShadowEffect;
    reg_username_pic = new QLabel();
    reg_password_pic = new QLabel();
    reg_make_sure_pic = new QLabel();
    reg_phone_pic = new QLabel();

    tips1 = new QLabel();
    tips2 = new QLabel();
    tips3 = new QLabel();
    tips4 = new QLabel();

    reg_username_txt = new QLineEdit();
    reg_password_txt = new QLineEdit();
    reg_make_sure_txt = new QLineEdit();
    reg_phone_txt = new QLineEdit();
    reg_btn = new QPushButton();
    reg_tips = new QHBoxLayout;
    reg_tip1 = new QPushButton();
    //创建一个横向排列布局
    reg_group = new QHBoxLayout;
    //创建三个个个纵向排列布局
    reg_pic_group = new QVBoxLayout;
    reg_input_group = new QVBoxLayout;
    tips_img_group = new QVBoxLayout;
    //创建一个button布局
    reg_button_group = new QHBoxLayout;

    //注册的gif
    regmv = new QMovie(":/Img/1010.gif");

    menu_bar = new QHBoxLayout;

    mainLayout = new QVBoxLayout;

    widget[2] = new QWidget;
    clause_box = new QVBoxLayout;
    clause_title_box = new QHBoxLayout;
    clause_title = new QLabel;
    clause_page_box = new QHBoxLayout;
    clause_page = new QTextEdit;
    clause_agree_box = new QHBoxLayout;
    clause_agree = new QRadioButton;
    clause_agree_tips = new QLabel;
    clause_button_box = new QHBoxLayout;
    clause_back = new QPushButton;
    clause_next = new QPushButton;
}

/*此函数在初始化所有部件之后立即调用,来实现窗口的静态布局*/
void myWidget::set_up_layout()
{
    //设置头部按钮的按下,接触,离开三个状态的样式
    //按钮"登录"
    headFrame->setGeometry(0, 0, 1920, 1080);
    headFrame->setStyleSheet("background-image:url(:/Img/bg_osx.png)");
    pageButton->setText(u8"登录");
    pageButton->setGeometry(0, 0, 80, 50);
    pageButton->setStyleSheet(QString("QPushButton{font-size:32px;color:#404040;background:#fff;border:none;margin-top:20px;margin-left:10px;}\
                                      QPushButton:hover{color:#707070;}\
                                      QPushButton:pressed{color:#a0a0a0;}"));
    //按钮"注册"
    page2Button->setText(u8"注册");
    page2Button->setGeometry(0, 0, 80, 50);
    page2Button->setStyleSheet(QString("QPushButton{font-size:22px;color:#a0a0a0;background:#fff;border:none;margin-top:30px;margin-left:10px;}\
                                      QPushButton:hover{color:#707070;}\
                                      QPushButton:pressed{color:#a0a0a0;}"));

    //label_login->setMovie(loginmv);
    label_login->setStyleSheet("border-radius:12px;padding:2px 4px;border-image: url(:/Img/ubuntu.png);background:rgb(0,0,0,0)");
    label_login->setFixedSize(400, 250);
    label_login_title->setText("QuietBlog");
    label_login_title->setStyleSheet("color:#808080");
    label_login_title->setFont(QFont("normal", 40, QFont::Normal));
    title_layout_login->addStretch();
    title_layout_login->addWidget(label_login_title);
    title_layout_login->addStretch();
    label_login_tips->setText("使用您的轻博客账户登录以在Ubuntu下浏览\n精彩的文章并与你的好友分享你的所见所闻,这一切不需要任何费用");
    label_login_tips->setAlignment(Qt::AlignCenter);
    label_login_tips->setStyleSheet("color:#202020");
    label_login_tips->setFont(QFont("Source Code Pro for Powerline", 10, QFont::Normal));
    tips_layout_login->addStretch();
    tips_layout_login->addWidget(label_login_tips);
    tips_layout_login->addStretch();

    //loginmv->start();
    //输入框部分和按钮样式设置
    username_txt->setFont(QFont("Source Code Pro for Powerline", 10, QFont::Normal));
    username_txt->setPlaceholderText("手机号/邮箱/QQ号");
    username_txt->setFixedWidth(250);
    username_txt->setMaxLength(64);
    username_txt->setAlignment(Qt::AlignCenter);
    username_txt->setStyleSheet("margin-bottom:10px;margin-left:20px;border:1px groove #a0a0a0;border-radius:6px;padding:3px 10px;");

    password_txt->setFont(QFont("Source Code Pro for Powerline", 10, QFont::Normal));
    password_txt->setContextMenuPolicy(Qt::NoContextMenu);
    password_txt->setPlaceholderText("密码");
    password_txt->setEchoMode(QLineEdit::Password);
    password_txt->setFixedWidth(250);
    password_txt->setMaxLength(12);
    password_txt->setAlignment(Qt::AlignCenter);
    password_txt->setStyleSheet("margin-top:10px;margin-left:20px;border:2px groove #a0a0a0;border-radius:6px;padding:3px 50px;");

    QPixmap user_icon(":/Img/User.png");
    //username_pic->setPixmap(user_icon);
    username_pic->setStyleSheet("background:rgb(0,0,0,0)");
    username_pic->setText("Blog ID:");
    username_pic->setAlignment(Qt::AlignRight);
    //username_pic->resize(user_icon.width(),user_icon.height());
    QPixmap pwd_icon(":/Img/pwd.png");
    //password_pic->setPixmap(pwd_icon);
    password_pic->setStyleSheet("background:rgb(0,0,0,0)");
    password_pic->setText("密码:");
    password_pic->setAlignment(Qt::AlignRight);
    //password_pic->resize(user_icon.width(),user_icon.height());

    login_btn->setStyleSheet(QString("QPushButton{border:1px solid #a8a8a8;margin-top:10px;border-radius:5px;background-color:#fff;color:#808080;}\
                                     QPushButton:hover{color:202020;background:#ebebeb;border:1px solid #a8a8a8;}\
                                     QPushButton:pressed{color:#fff;background:#2d61e0;border:none}"));
    login_btn->setText(u8"完 成");
    login_btn->setFixedSize(80, 40);

    cancle->setStyleSheet(QString("QPushButton{border:1px solid #a8a8a8;margin-top:10px;border-radius:5px;background-color:#fff;color:#808080;}\
                                     QPushButton:hover{color:202020;background:#ebebeb;border:1px solid #a8a8a8;}\
                                     QPushButton:pressed{color:#fff;background:#2d61e0;border:none}"));
    cancle->setText(u8"稍 后");
    cancle->setFixedSize(80, 40);

    login_tip1->setText("创建新Blog ID...");
    login_tip1->setStyleSheet("QPushButton{border:none;background:rgb(0,0,0,0);color:#397cd6;}");
    login_tip1->setFont(QFont("anjalioldlipi", 8, QFont::Bold));
    login_tip2->setText("忘记了Blog ID或密码吗?");
    login_tip2->setStyleSheet("QPushButton{border:none;background:rgb(0,0,0,0);color:#397cd6;}");
    login_tip2->setFont(QFont("anjalioldlipi", 8, QFont::Bold));
    login_tips->addStretch();
    login_tips->addWidget(login_tip1);
    login_tips->addStretch();
    login_tips->addWidget(login_tip2);
    login_tips->addStretch();
    effectlabel_login->setBlurRadius(14);  // 阴影圆角的大小
    effectlabel_login->setColor(Qt::gray); //阴影的颜色
    effectlabel_login->setOffset(0, 2);
    //label_login->setGraphicsEffect(effectlabel_login);
    //创建gif空间,置于图片容器
    //登录的gif
    widget[0]->resize(400, 400);
    loginmv->setScaledSize(QSize(400, 300));
    //将输入框和提示图标元素置入其对应的布局
    pic_group->addWidget(username_pic);
    pic_group->addStretch();
    pic_group->addWidget(password_pic);

    input_group->addWidget(username_txt);
    input_group->addStretch();
    input_group->addWidget(password_txt);

    button_group->addStretch(5);
    button_group->addWidget(cancle);
    button_group->addStretch(2);
    button_group->addWidget(login_btn);
    button_group->addStretch(4);

    //将输入框布局和图标布局置入其父布局
    group->addStretch(3);
    group->addLayout(pic_group);
    group->addLayout(input_group);
    group->addStretch(5);

    //向图片布局两侧添加弹簧
    pic_layout_login->addStretch();
    pic_layout_login->addWidget(label_login);
    pic_layout_login->addStretch();
    //将以上布局置入主布局
    layout_login->addLayout(title_layout_login);
    layout_login->addLayout(tips_layout_login);
    layout_login->addLayout(pic_layout_login);
    layout_login->addStretch();
    layout_login->addLayout(group);
    layout_login->addStretch();
    QHBoxLayout *loading = new QHBoxLayout;
    label_laoding = new QLabel(this);
    label_height = new QLabel(this);
    label_height->setFixedHeight(22);
    label_height->setStyleSheet("background:rgb(0,0,0,0)");
    label_laoding->setGeometry(0, 0, 22, 22);
    movie_loading = new QMovie(":/Img/loading_mac.gif");
    movie_loading->setScaledSize(QSize(22,22));
    label_laoding->setScaledContents(true);
    label_laoding->setStyleSheet("background:rgb(0,0,0,0)");
    label_laoding->setMovie(movie_loading);
    movie_loading->start();
    label_laoding->hide();
    loading->addStretch();
    loading->addWidget(label_height);
    loading->addWidget(label_laoding);
    loading->addStretch();
    layout_login->addLayout(loading);
    layout_login->addStretch();
    layout_login->addLayout(button_group);
    layout_login->addStretch();
    layout_login->addLayout(login_tips);
    //将添加了不同控件的主布局置入到对应的widget[]中
    widget[0]->setLayout(layout_login);
    //调用stackWidget方法添加三个widget到页面
    stackWidget->addWidget(widget[0]);
    /*---end***********************************登录页面的布局操作**************************************************************/

    /*---star***********************************注册页面的布局操作**************************************************************/

    //注册部分页面元素设置
    //按照下标进行一下QWidget的区分

    widget[1]->resize(400, 400);

    //   effectlabel_reg->setBlurRadius(14);        // 阴影圆角的大小
    //   effectlabel_reg->setColor(Qt::gray);      //阴影的颜色
    //   effectlabel_reg->setOffset(0,2);
    //   label_reg->setGraphicsEffect(effectlabel_reg);
    //注册部分
    QPixmap reg_user_icon(":/Img/reg_usr.png");
    QPixmap reg_password_icon(":/Img/reg_pwd.png");
    QPixmap reg_make_sure_icon(":/Img/makesure_pwd.png");
    QPixmap reg_phone_icon(":/Img/phone.png");

    regmv->setScaledSize(QSize(400, 270));
    //动图设置
    //   label_reg->setMovie(regmv);
    //   label_reg->setStyleSheet("border-radius:10px;padding:2px 4px;");
    //   regmv->start();
    label_reg->setText("提供BLog ID 详情");
    label_reg->setFont(QFont("Normal", 18, QFont::Normal));
    label_reg->setAlignment(Qt::AlignLeft);
    //图标设置
    //   reg_username_pic->setPixmap(reg_user_icon);
    //   reg_username_pic->resize(reg_user_icon.width(),reg_user_icon.height());
    reg_username_pic->setText("Blog ID:");
    reg_username_pic->setStyleSheet("background:rgb(0,0,0,0)");
    reg_username_pic->setAlignment(Qt::AlignRight);
    //   reg_password_pic->setPixmap(reg_password_icon);
    //   reg_password_pic->resize(reg_password_icon.width(),reg_password_icon.height());
    reg_password_pic->setText("密码:");
    reg_password_pic->setStyleSheet("background:rgb(0,0,0,0)");
    reg_password_pic->setAlignment(Qt::AlignRight);
    //   reg_make_sure_pic->setPixmap(reg_make_sure_icon);
    //   reg_make_sure_pic->resize(reg_make_sure_icon.width(),reg_make_sure_icon.height());
    reg_make_sure_pic->setText("确认密码:");
    reg_make_sure_pic->setStyleSheet("background:rgb(0,0,0,0)");
    reg_make_sure_pic->setAlignment(Qt::AlignRight);
    //   reg_phone_pic->setPixmap(reg_phone_icon);
    //   reg_phone_pic->resize(reg_phone_icon.width(),reg_phone_icon.height());
    reg_phone_pic->setText("联系方式:");
    reg_phone_pic->setStyleSheet("background:rgb(0,0,0,0)");
    reg_phone_pic->setAlignment(Qt::AlignRight);

    //输入框设置
    reg_username_txt->setFont(QFont("Source Code Pro for Powerline", 10, QFont::Normal));
    reg_username_txt->setPlaceholderText("手机号/QQ号/邮箱");
    reg_username_txt->setFixedSize(250, 30);
    reg_username_txt->setMaxLength(64);
    reg_username_txt->setAlignment(Qt::AlignCenter);
    reg_username_txt->setStyleSheet("margin-left:20px;border:1px groove #a0a0a0;border-radius:6px;padding:3px 10px;");

    reg_password_txt->setFont(QFont("Source Code Pro for Powerline", 10, QFont::Normal));
    reg_password_txt->setContextMenuPolicy(Qt::NoContextMenu);
    reg_password_txt->setPlaceholderText("请输入密码");
    reg_password_txt->setEchoMode(QLineEdit::Password);
    reg_password_txt->setFixedSize(250, 30);
    reg_password_txt->setMaxLength(12);
    reg_password_txt->setAlignment(Qt::AlignCenter);
    reg_password_txt->setStyleSheet("margin-left:20px;border:2px groove #a0a0a0;border-radius:6px;padding:3px 40px;");

    reg_make_sure_txt->setFont(QFont("Source Code Pro for Powerline", 10, QFont::Normal));
    reg_make_sure_txt->setContextMenuPolicy(Qt::NoContextMenu);
    reg_make_sure_txt->setPlaceholderText("确认密码");
    reg_make_sure_txt->setEchoMode(QLineEdit::Password);
    reg_make_sure_txt->setFixedSize(250, 30);
    reg_make_sure_txt->setMaxLength(12);
    reg_make_sure_txt->setAlignment(Qt::AlignCenter);
    reg_make_sure_txt->setStyleSheet("margin-left:20px;border:2px groove #a0a0a0;border-radius:6px;padding:3px 40px;");

    reg_phone_txt->setFont(QFont("Source Code Pro for Powerline", 10, QFont::Normal));
    reg_phone_txt->setPlaceholderText("请输入手机号用于找回密码");
    reg_phone_txt->setFixedSize(250, 30);
    reg_phone_txt->setMaxLength(11);
    reg_phone_txt->setAlignment(Qt::AlignCenter);
    reg_phone_txt->setStyleSheet("margin-left:20px;border:1px groove #a0a0a0;border-radius:6px;padding:3px 40px;");

    reg_btn->setStyleSheet(QString("QPushButton{border:1px solid #a8a8a8;padding-top:5px;border-radius:5px;background-color:#fff;color:#808080;}\
                                  QPushButton:hover{color:202020;background:#ebebeb;border:1px solid #a8a8a8;}\
                                  QPushButton:pressed{color:#fff;background:#2d61e0;border:none}"));
    reg_btn->setText(u8"加 入");
    reg_btn->setFixedSize(100, 35);
    reg_btn->setFont(QFont("anjalioldlipi", 10, QFont::Normal));
    reg_tip1->setText("已有Blog ID? 返回登录");
    reg_tip1->setStyleSheet("QPushButton{border:none;background:rgb(0,0,0,0);color:#397cd6;}");
    reg_tip1->setFont(QFont("anjalioldlipi", 8, QFont::Bold));
    reg_tips->addStretch();
    reg_tips->addWidget(reg_tip1);
    reg_tips->addStretch();

    tips1->setStyleSheet("background:#f2f2f2;border:none;padding:3px;color:#909090;");
    tips1->setFixedSize(32,32);
    tips2->setStyleSheet("background:#f1f1f1;border:none;padding:3px;color:#909090");
    tips2->setFixedSize(32,32);
    tips3->setStyleSheet("background:#f0f0f0;border:none;padding:3px;color:#909090");
    tips3->setFixedSize(32,32);
    tips4->setStyleSheet("background:#efefef;border:none;padding:3px;color:#909090");
    tips4->setFixedSize(32,32);

    reg_pic_group->addWidget(reg_username_pic);
    reg_pic_group->addStretch();
    reg_pic_group->addWidget(reg_password_pic);
    reg_pic_group->addStretch();
    reg_pic_group->addWidget(reg_make_sure_pic);
    reg_pic_group->addStretch();
    reg_pic_group->addWidget(reg_phone_pic);

    reg_input_group->addWidget(reg_username_txt);
    reg_input_group->addStretch();
    reg_input_group->addWidget(reg_password_txt);
    reg_input_group->addStretch();
    reg_input_group->addWidget(reg_make_sure_txt);
    reg_input_group->addStretch();
    reg_input_group->addWidget(reg_phone_txt);

    tips_img_group->addWidget(tips1);
    tips_img_group->addStretch();
    tips_img_group->addWidget(tips2);
    tips_img_group->addStretch();
    tips_img_group->addWidget(tips3);
    tips_img_group->addStretch();
    tips_img_group->addWidget(tips4);

    //   reg_button_group->addStretch();
    reg_button_group->addWidget(reg_btn);
    //   reg_button_group->addStretch();

    QHBoxLayout *loading_reg = new QHBoxLayout;
    label_laoding_reg = new QLabel(this);
    label_height_reg = new QLabel(this);
    label_height_reg->setFixedHeight(22);
    label_height_reg->setStyleSheet("background:rgb(0,0,0,0)");
    label_laoding_reg->setGeometry(0, 0, 22, 22);
    movie_loading_reg = new QMovie(":/Img/loading_mac.gif");
    movie_loading_reg->setScaledSize(QSize(22,22));
    label_laoding_reg->setScaledContents(true);
    label_laoding_reg->setStyleSheet("background:rgb(0,0,0,0)");
    label_laoding_reg->setMovie(movie_loading);
    movie_loading_reg->start();
    label_laoding_reg->hide();
    loading_reg->addStretch();
    loading_reg->addWidget(label_height_reg);
    loading_reg->addWidget(label_laoding_reg);
    loading_reg->addStretch();

    reg_group->addStretch();
    reg_group->addLayout(reg_pic_group);
    reg_group->addLayout(reg_input_group);
    reg_group->addLayout(tips_img_group);
    reg_group->addStretch();
    //向图片布局两侧添加弹簧
    pic_layout_reg->addWidget(label_reg);
    pic_layout_reg->addStretch();
    //将以上布局置入主布局
    layout_reg->addLayout(pic_layout_reg);
    layout_reg->addStretch(2);
    layout_reg->addLayout(reg_group);
    layout_reg->addStretch(1);
    layout_reg->addLayout(loading_reg);
    layout_reg->addStretch(1);
    layout_reg->addLayout(reg_button_group);
    layout_reg->addStretch(1);
    layout_reg->addLayout(reg_tips);
    layout_reg->addStretch(1);
    //将添加了不同控件的主布局置入到对应的widget[]中
    widget[1]->setLayout(layout_reg);
    //调用stackWidget方法添加三个widget到页面
    stackWidget->addWidget(widget[1]);

    /*---end***********************************注册页面的布局操作**************************************************************/

    widget[2]->resize(400, 400);
    clause_title->setText("您需要仔细阅读以下条款:");
    clause_title->setStyleSheet("color:#202020;background:rgb(0,0,0,0)");
    clause_title->setFont(QFont("Normal", 12, QFont::Normal));
    clause_title_box->addWidget(clause_title);
    net_server ns;
    clause_page->setText(ns.getClause());
    clause_page_box->addWidget(clause_page);
    clause_page->setStyleSheet("color:#202020;background:#fff;border:1px solid #a8a8a8;border-radius:5px;");
    clause_page->setFont(QFont("Source Code Pro for Powerline", 10, QFont::Normal));
    //clause_agree->setText("_");
    //clause_agree->setStyleSheet("border:1px solid #a8a8a8;background:rgb(0,0,0,0)");
    clause_agree->setFont(QFont("Source Code Pro for Powerline", 10, QFont::Normal));
    clause_agree->setStyleSheet("background:#ebebeb");
    clause_agree_box->addStretch();
    clause_agree_tips->setText("我同意");
    clause_agree_tips->setFont(QFont("Source Code Pro for Powerline", 8, QFont::Normal));
    clause_agree_tips->setStyleSheet("background:#ebebeb;color:#808080");
    clause_agree_box->addWidget(clause_agree);
    clause_agree_box->addWidget(clause_agree_tips);
    clause_back->setText("稍后");
    clause_back->setFixedSize(80, 40);
    clause_back->setStyleSheet(QString("QPushButton{border:1px solid #a8a8a8;margin-top:10px;border-radius:5px;background-color:#fff;color:#808080;}\
                                     QPushButton:hover{color:202020;background:#ebebeb;border:1px solid #a8a8a8;}\
                                     QPushButton:pressed{color:#fff;background:#2d61e0;border:none}"));
    clause_back->setFont(QFont("Normal", 10, QFont::Normal));

    clause_next->setText("不同意");
    clause_next->setFixedSize(80, 40);
    clause_next->setStyleSheet(QString("QPushButton{border:1px solid #a8a8a8;margin-top:10px;border-radius:5px;background-color:#fff;color:#808080;}\
                                             QPushButton:hover{color:202020;background:#ebebeb;border:1px solid #a8a8a8;}\
                                             QPushButton:pressed{color:#fff;background:#2d61e0;border:none}"));
    clause_next->setFont(QFont("Normal", 10, QFont::Normal));
    clause_next->setEnabled(false);
    clause_button_box->addStretch();
    clause_button_box->addWidget(clause_back);
    clause_button_box->addStretch();
    clause_button_box->addWidget(clause_next);
    clause_button_box->addStretch();
    clause_box->addLayout(clause_title_box);
    clause_box->addLayout(clause_page_box);
    clause_box->addLayout(clause_agree_box);
    clause_box->addLayout(clause_button_box);
    widget[2]->setLayout(clause_box);
    stackWidget->addWidget(widget[2]);
    /*---star***************************创建一个头部选项卡布局并置入两个按钮*******××××××××××××××××××××××**************************/

    menu_bar->addWidget(pageButton);
    menu_bar->addWidget(line);
    menu_bar->addWidget(page2Button);
    menu_bar->addStretch();
    /*---end***************************创建一个头部选项卡布局并置入两个按钮*********××××××××××××××××××××××************************/

    /*---star******************************将布局内容显示到窗口************************************××××××××××××××××××××××*******/
    //将之前创建的:头部选项卡布局,可变页面布局,完成按钮全部置入mainlayout

    //mainLayout->addLayout(menu_bar);
    mainLayout->addWidget(stackWidget);

    //显示mainlayout布局
    setLayout(mainLayout);
}

/*点击不同的标题选项卡切换不同界面的函数*/
void myWidget::slt_setPageWidget()
{
    //获取触发槽的是哪个部件所发出的信号，并获取到那个指针
    QPushButton *widget = static_cast<QPushButton *>(sender());
    if (widget == reg_tip1)
    {
        stackWidget->setCurrentIndex(0); //根据触发的按钮来进行所要显示的QWidget
    }
    else if (widget == login_tip1)
    {
        stackWidget->setCurrentIndex(2);
    }
    else if (widget == clause_back)
    {
        stackWidget->setCurrentIndex(0);
    }
    else if (widget == clause_next)
    {
        stackWidget->setCurrentIndex(1);
    }
}

/*槽函数:在获取到缓冲窗口发出的loading信号之后调用*/
void myWidget::myclose()
{
    IamClose();
    this->close();
}

void myWidget::error_login(){
    label_laoding->hide();
    QMessageBox::about(this, tr("提示"), tr("\n   用户名或密码错误    \n"));
}
/*槽函数:点击登录按钮执行登录操作,调用net_server的login_server方法*/
void myWidget::login_server()
{
    net_server net;
    username_str = username_txt->text();
    password_str = password_txt->text();
    qDebug() << "按下了登录" << endl
             << "用户名：" << username_str << endl
             << "密码：" << password_str;
    if (username_txt == NULL || password_txt == NULL)
    {
        QMessageBox::about(this, tr("无法登录"), tr("\n        用户名或者密码为空！         \n"));
        return;
    }
//    wating *w = new wating(this);
//    w->setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
//    w->setWindowModality(Qt::ApplicationModal);
//    w->move(880, 450);
//    w->show();
//    connect(w, SIGNAL(loading()), this, SLOT(myclose()));
//    connect(this, SIGNAL(server_is_returned_true()), w, SIGNAL(loading()));
//    connect(this, SIGNAL(server_is_returned_false()), w, SLOT(close()));
    int ret = net.login_server(username_str, password_str);
    qDebug() << "myWidget::login_server--->获取到loginserver的返回值" << ret << endl;
    login_btn->setText(u8"完 成");
    label_laoding->show();
    //在获取到返回值之后停顿一秒来欣赏美妙的loading动画
    if (ret == 1)
    {
        QTimer::singleShot(2000, this, SLOT(myclose()));
        return;
    }

    else if (ret == 0)
    {
        QTimer::singleShot(1000, this, SLOT(error_login()));
        return;
    }
    else
    {
        label_laoding->hide();
        QMessageBox::about(this, tr("提示"), tr("无法连接到服务器，请检查网络连接后再试！"));
        return;
    }
}

/*槽函数:点击注册按钮执行注册操作,调用net_server的reg_server方法*/
void myWidget::reg_server()
{
    net_server net;
    reg_username_str = reg_username_txt->text();
    reg_password_str = reg_password_txt->text();
    reg_make_sure_str = reg_make_sure_txt->text();
    reg_phone_str = reg_phone_txt->text();
    qDebug() << "按下了注册" << endl
             << "用户名：" << reg_username_str << endl
             << "密码：" << reg_password_str << endl
             << "确认密码：" << reg_make_sure_str << endl
             << "手机号：" << reg_phone_str;

    QPixmap tips_true_img(":/Img/true.png");
    QPixmap tips_error_img(":/Img/error.png");
    tips1->setToolTip("格式正确");
    tips2->setToolTip("格式正确");
    tips3->setToolTip("格式正确");
    tips4->setToolTip("格式正确");
    tips1->setPixmap(tips_true_img);
    tips1->resize(tips_true_img.width(), tips_true_img.height());
    tips2->setPixmap(tips_true_img);
    tips2->resize(tips_true_img.width(), tips_true_img.height());
    tips3->setPixmap(tips_true_img);
    tips3->resize(tips_true_img.width(), tips_true_img.height());
    tips4->setPixmap(tips_true_img);
    tips4->resize(tips_true_img.width(), tips_true_img.height());
    if (reg_username_str == NULL)
    {
        tips1->setToolTip("用户名不能为空");
        tips1->setPixmap(tips_error_img);
        tips1->resize(tips_error_img.width(), tips_error_img.height());
    }
    else if (reg_password_str != reg_make_sure_str)
    {
        tips2->setToolTip("两次输入的密码不相同");
        tips3->setPixmap(tips_error_img);
        tips3->resize(tips_error_img.width(), tips_error_img.height());
        tips2->setPixmap(tips_error_img);
        tips2->resize(tips_error_img.width(), tips_error_img.height());
    }
    else if (reg_password_str == NULL || reg_make_sure_str == NULL)
    {
        tips2->setToolTip("密码不能为空");
        tips3->setToolTip("密码不能为空");
        tips2->setPixmap(tips_error_img);
        tips2->resize(tips_error_img.width(), tips_error_img.height());
        tips3->setPixmap(tips_error_img);
        tips3->resize(tips_error_img.width(), tips_error_img.height());
    }
    else if (reg_phone_str == NULL)
    {
        tips4->setToolTip("手机号不能为空");
        tips4->setPixmap(tips_error_img);
        tips4->resize(tips_error_img.width(), tips_error_img.height());
    }
    else
    {
        tips1->setPixmap(tips_true_img);
        tips1->resize(tips_true_img.width(), tips_true_img.height());
        tips2->setPixmap(tips_true_img);
        tips2->resize(tips_true_img.width(), tips_true_img.height());
        tips3->setPixmap(tips_true_img);
        tips3->resize(tips_true_img.width(), tips_true_img.height());
        tips4->setPixmap(tips_true_img);
        tips4->resize(tips_true_img.width(), tips_true_img.height());
        int ret = net.reg_server(reg_username_str, reg_password_str, reg_phone_str);
        label_laoding_reg->show();
        if (ret == 1)
        {
            QMessageBox::about(this, tr("提示"), tr("注册成功"));
            label_laoding_reg->hide();
            //this->close();
            pageButton->setStyleSheet(QString("QPushButton{font-size:32px;color:#404040;background:#fff;border:none;margin-top:20px;margin-left:10px;}\
                                          QPushButton:hover{color:#707070;}\
                                          QPushButton:pressed{color:#a0a0a0;}"));
            page2Button->setStyleSheet(QString("QPushButton{font-size:22px;color:#a0a0a0;background:#fff;border:none;margin-top:20px;margin-left:10px;}\
                                               QPushButton:hover{color:#707070;}\
                                               QPushButton:pressed{color:#a0a0a0;}"));
            stackWidget->setCurrentIndex(0); //根据触发的按钮来进行所要显示的QWidget
            return;
        }

        else if (ret == 0)
        {
            QMessageBox::about(this, tr("提示"), tr("注册失败"));
            label_laoding_reg->hide();
            return;
        }

        else if (ret == 2)
        {
            QMessageBox::about(this, tr("提示"), tr("用户已经被注册，请更换用户名"));
            label_laoding_reg->hide();
            return;
        }
        else
        {
            QMessageBox::about(this, tr("提示"), tr("无法连接到服务器，请检查网络连接后再试！"));
            label_laoding_reg->hide();
            return;
        }
    }
}

/*槽函数:选择单选框*/
void myWidget::m_isChecked()
{
    if (clause_agree->isChecked())
    {
        qDebug() << "选择了";
        clause_next->setEnabled(true);
        clause_next->setText("确认");
        qApp->processEvents();
    }
    else
    {
        qDebug() << "取消选择";
        clause_next->setEnabled(false);
        clause_next->setText("不同意");
        qApp->processEvents();
    }
}

