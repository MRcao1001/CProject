#include "appdisplay.h"
#include "ui_appdisplay.h"

appDisplay::appDisplay(QWidget *parent) : QWidget(parent),
                                          ui(new Ui::appDisplay)
{
    ui->setupUi(this);
    //设置界面背景色
    QPalette palette(this->palette());
    palette.setColor(QPalette::Window, QColor(246, 246, 246));
    this->setPalette(palette);

    //    m_pushButton = new QPushButton(this);
    //    m_pushButton->setText(QObject::tr("测试按钮菜单"));
    //    m_pushButton->setMenu(m_menu);//设置菜单

    //this->setWindowOpacity(0.9);
    //this->setAttribute(Qt::WA_TranslucentBackground, true);
    //设置窗口标题栏文字
    this->setWindowTitle(QObject::tr("旧梦    君在何方"));
    //初始化所有控件
    InitializationWidget();
    //设置所有空间的样式属性
    SetUpTheLayout();

    //    h_user_name_button ->setMenu(m_menu);

    //从服务器获取信息显示
    showinfo();
    //页面按钮绑定槽函数
    connect(h_refresh_button, &QPushButton::clicked, this, &appDisplay::showinfo);
    //connect(h_user_name_button,&QPushButton::clicked,this,&appDisplay::openlogin);
    //connect(h_quit_button,&QPushButton::clicked,this,&appDisplay::quitAccount);
    //connect(storys_button,&QPushButton::clicked,this,&appDisplay::slt_setPageWidget);
    connect(read_page, &QPushButton::clicked, this, &appDisplay::slt_setPageWidget);
    connect(write_page, &QPushButton::clicked, this, &appDisplay::slt_setPageWidget);
    connect(send_mail, &QPushButton::clicked, this, &appDisplay::slt_setPageWidget);
}

void appDisplay::addFunc()
{
    qDebug() << "addFunc";
}

void appDisplay::delFunc()
{
    qDebug() << "delFunc";
}
appDisplay::~appDisplay()
{
    delete ui;
}

/*一般函数:在窗口对象生成后立即调用,初始化所有窗口部件*/
void appDisplay::InitializationWidget()
{
    background_layout = new QVBoxLayout; //整个背景的框架
    headFrame = new QFrame(this);        //菜单背景
    right_layout = new QHBoxLayout;
    left_top_layout = new QVBoxLayout;
    LOGO = new QLabel();
    app_name = new QLabel();
    menu_name = new QLabel();
    read_page = new QPushButton();
    write_page = new QPushButton();
    send_mail = new QPushButton();
    chat = new QPushButton();
    message_box = new QPushButton();
    look_firend = new QPushButton();
    aboutme = new QPushButton();
    head_layout = new QHBoxLayout;              //头部框架
    h_user_img_layout = new QVBoxLayout;        //用户头像框架
    h_user_img_button = new QPushButton();      //用户头像按钮
    h_user_info_layout = new QHBoxLayout;       //用户信息框架
    h_user_name_button = new QPushButton();     //用户名按钮,可以用来登录和切换用户
    h_user_leavl_label = new QLabel();          //等级标签
    h_user_vip_label = new QLabel();            //vip标识标签
    h_button_area_layout = new QHBoxLayout;     //头部按钮组框架
    h_message_button = new QPushButton();       //收件箱按钮-----未实现
    h_show_friend_button = new QPushButton();   //搜索添加好友按钮-----未实现
    h_refresh_button = new QPushButton();       //刷新界面内容按钮
    h_quit_button = new QPushButton();          //退出当前用户登录按钮
    h_search_area_layout = new QVBoxLayout;     //搜索框框架
    h_search_top = new QHBoxLayout;             //搜索框主体框架
    h_search_input = new QLineEdit();           //搜索输入框
    h_search_button = new QPushButton;          //搜索按钮
    h_search_bottom = new QHBoxLayout;          //搜索条件框架
    h_condition_chec = new QCheckBox;           //搜索条件复选框-----未实现
    menu_layout = new QVBoxLayout;              //左侧目录框架
    scroll_menu = new QScrollArea;              //未用到
    work_layout = new QVBoxLayout;              //工作区域框架
    type_bar_layout = new QHBoxLayout;          //工作区域按钮栏框架
    storys_button = new QPushButton();          //文章区域选择按钮
    edit_button = new QPushButton();            //写作区域选择按钮
    send_mail_button = new QPushButton();       //发离线私信区域选择按钮
    edit_area_layout = new QVBoxLayout;         //写作区域框架
    stackwidget_work = new QStackedWidget;      //这是主界面实现标签切换界面的容器
    story = new QTableWidget();                 //文章区域框架
    layout_write = new QVBoxLayout;             //文章区框架二
    title_label = new QLabel;                   //文章名提示标签
    page_title = new QLineEdit;                 //文章名输入框
    about_label = new QLabel;                   //文章摘要提示标签
    about_story = new QTextEdit;                //文章摘要输入框
    edit_label = new QLabel;                    //文章正文提示标签
    write_story = new QTextEdit;                //文章正文输入框
    layout_mail = new QVBoxLayout;              //邮件区框架
    sender_label = new QLabel;                  //邮件发送者提示
    sender_name = new QLineEdit;                //邮件发送者输入框
    reciver_label = new QLabel;                 //邮件接受者提示
    reciver_name = new QLineEdit;               //邮件接受者输入框
    topic_label = new QLabel;                   //主题提示
    topic_name = new QLineEdit;                 //主题输入框
    write_mail_label = new QLabel;              //邮件正文提示
    write_mail = new QTextEdit;                 //邮件正文输入框
    work_button_layout_view = new QHBoxLayout;  //文章区域下部分按钮框架
    work_button_layout_write = new QHBoxLayout; //写作区域下部分按钮框架
    work_button_layout_mail = new QHBoxLayout;  //发送离线私信区域下部分按钮框架
    refresh_button_view = new QPushButton();    //文章区刷新按钮-----未实现
    vip_button_view = new QPushButton();        //文章区只显示vip内容按钮-----未实现
    subimt_button_write = new QPushButton();    //写作区保存按钮-----未实现
    empty_button_write = new QPushButton();     //写作区清空所有内容按钮-----未实现
    subimt_button_mail = new QPushButton();     //发送邮件区域发送按钮-----未实现
    empty_button_mail = new QPushButton();      //发送邮件区域清空内容按钮-----未实现
    bottom_layout = new QHBoxLayout;            //底部框架
    tips_layout = new QHBoxLayout;              //底部信息提示栏框架
    date_label = new QLabel();                  //信息显示日期-----未实现
    info_lable = new QLabel();                  //信息内容-----未实现
    tip_img_label = new QLabel();               //信息图标:错误信息 提示信息 完成提示-----未实现
    effectlabel_reg = new QGraphicsDropShadowEffect;
}

/*一般函数在初始化所有部件之后立即调用,来实现窗口的静态布局*/
void appDisplay::SetUpTheLayout()
{
    //在界面上布局
    //menu = menuBar->addMenu("window");
    headFrame->setGeometry(0, 0, 1920, 1080);
    headFrame->setStyleSheet("background-image:url(:/Img/bg_osx.png)");
    h_user_img_button->setStyleSheet(QString("QPushButton{border-image: url(:/Img/userImg.png);border:none;border-radius:10px;padding:5px 50px;}\QPushButton:hover{border-image: url(:/Img/userImg_hover.png);}\QPushButton:pressed{border-image: url(:/Img/userImg.png);}"));
    h_user_img_button->setFixedSize(35, 35);

    h_user_name_button->setText(u8"请 登录 注册");
    h_user_name_button->setStyleSheet(QString("QPushButton{border-image: url(:/Img/top_btn.png);border:none;color:#808080;font-size:13px;}\QPushButton:hover{border:1px solid #dedede;background-color:#ebebeb;}\QPushButton:pressed{border-image: url(:/Img/top_btn_2.png);background-color:#2d61e0;color:#fff;}"));
    h_user_name_button->setFixedSize(134, 32);
    h_user_leavl_label->setText(u8"LV:99");
    h_user_leavl_label->setStyleSheet("font-size:12px;color:#ffffff;margin-left:10px");

    QMenu *m_menu = new QMenu(this);
    m_menu->setStyleSheet(
        "\
                QMenu {\
                background-color:#fff; /*整个背景*/\
                border-radius:none;/*整个菜单边缘*/\
                }\
            QMenu::item {\
                font-size: 10pt; \
                color: #202020;  /*字体颜色*/\
                border-bottom: 1px solid #ebebeb;    /*item选框*/\
                background-color:#fff;\
                padding:10px 10px; /*设置菜单项文字上下和左右的内边距，效果就是菜单中的条目左右上下有了间隔*/\
                 }\
            QMenu::item:selected { \
                background-color:#ebebeb;/*选中的样式*/\
                }\
            QMenu::item:pressed {/*菜单项按下效果*/\
                                      background-color: #2d61e0; \
                                      color: #fff; \
                                  }\
               ");
    m_menu->setFixedWidth(134);
    QAction *m_addAction = new QAction(m_menu);
    QAction *m_delAction = new QAction(m_menu);
    QAction *m_aboutlAction = new QAction(m_menu);
    m_addAction->setText(QObject::tr("登 录"));
    m_delAction->setText(QObject::tr("注 销"));
    m_aboutlAction->setText(QObject::tr("关于我们"));
    m_menu->addAction(m_addAction);
    m_menu->addAction(m_delAction);
    m_menu->addAction(m_aboutlAction);
    connect(m_addAction, &QAction::triggered, this, &appDisplay::openlogin);
    connect(m_delAction, &QAction::triggered, this, &appDisplay::quitAccount);
    h_user_name_button->setMenu(m_menu);

    QPixmap h_user_vip_img(":/Img/vip.png");
    h_user_vip_label->setPixmap(h_user_vip_img);
    h_user_vip_label->setStyleSheet("margin-left:10px");

    h_message_button->setStyleSheet(QString("QPushButton{border-image: url(:/Img/tips.png);border:none;border-radius:30px;padding:5px 50px;}\QPushButton:hover{border-image: url(:/Img/tips_hover.png);}\QPushButton:pressed{border-image: url(:/Img/tips.png);}"));
    h_message_button->setFixedSize(32, 32);
    h_show_friend_button->setStyleSheet(QString("QPushButton{border-image: url(:/Img/add.png);border:none;border-radius:30px;padding:5px 50px;}\QPushButton:hover{border-image: url(:/Img/add_hover.png);}\QPushButton:pressed{border-image: url(:/Img/add.png);}"));
    h_show_friend_button->setFixedSize(32, 32);
    h_refresh_button->setStyleSheet(QString("QPushButton{border-image: url(:/Img/rf.png);border:none;border-radius:12px;color:#fff;font-size:13px;}\QPushButton:hover{background:#f1f1f1;}\QPushButton:pressed{background:#fafafa;}"));
    h_refresh_button->setFixedSize(25, 25);
    h_quit_button->setStyleSheet(QString("QPushButton{border-image: url(:/Img/exit.png);border:none;border-radius:12px;color:#fff;font-size:13px;}\QPushButton:hover{background:#f1f1f1;}\QPushButton:pressed{background:#fafafa;}"));
    h_quit_button->setFixedSize(25, 25);

    h_search_input->setStyleSheet("font-size:16px;margin-top:10px;margin-left:10px;border:2px groove #a0a0a0;border-radius:5px;padding-top:5px;padding-bottom:5px;padding-left:20px;background-color:#ebebeb;color:#808080;border:1px solid #dadada;");
    h_search_input->setFixedSize(220, 45);
    h_search_input->setPlaceholderText(u8"搜索 文章/信件/用户");
    h_search_button->setStyleSheet(QString("QPushButton{border:1px solid #dadada;margin-top:10px;border-radius:5px;background-color:#fff;color:#808080;}\QPushButton:hover{border:1px solid #dedede;background-color:#ebebeb;}\QPushButton:pressed{border:none;background-color:#2d61e0;color:#fff}"));
    h_search_button->setText("查找");
    h_search_button->setFixedSize(60, 45);

    //这里放置树形结构
    treeWidget = new QTreeWidget();
    treeWidget->setColumnCount(1);
    treeWidget->setFixedWidth(20);
    treeWidget->setHeaderHidden(true);

    treeWidget->setStyleSheet("QTreeWidget::item{height:40px;};background-color:rgb(0,0,0,0);");
    //treeWidget->setStyleSheet("");
    treeWidget->setFont(QFont("Source Code Pro for Powerline", 12, QFont::Normal));
    //移除treeWidget->takeTopLevelItem(1);
    //TODO
    //left_bar->addWidget(treeWidget);//将树形结构暂时隐藏,后面调整
    //title

    LOGO->setStyleSheet("border-image:url(:/Img/blog_black.png)");
    LOGO->setFixedSize(26, 26);
    app_name->setText("QUIET BLOG");
    app_name->setStyleSheet("color:#202020;margin-left:10px;margin-top:8px");
    app_name->setFont(QFont("uroob", 18, QFont::Normal, true)); //uroob
    head_layout->addWidget(LOGO);
    head_layout->addWidget(app_name);
    menu_name->setText("功能选择");
    menu_name->setFont(QFont("Source Code Pro for Powerline", 12, QFont::Normal));
    menu_name->setStyleSheet("color:#807883;padding-left :30px;");
    //目录栏目的八个按钮
    QString style_str1 = "QPushButton{color:#fff;background:#2d61e0;border:0px;text-align : left; padding-left:70px}";
    QString style_str2 = "QPushButton{color:#202020;background:reg(0,0,0,0);border-image:url(:/Img/bg_osx2.png);border:0px;text-align : left; padding-left:70px}\
                QPushButton:hover{background:#dadada;border-image:none;}\
                QPushButton:pressed{color:#fff;background:#2d61e0;border-image:none;}";
    QString style_str3 = "QPushButton{color:#202020;background:reg(0,0,0,0);border-image:url(:/Img/bg_osx2.png);border:0px;text-align : left; padding-left:70px}\
                QPushButton:hover{background:#dadada;border-image:none;}\
                QPushButton:pressed{color:#fff;background:#2d61e0;border-image:none;}";
    QString style_str4 = "QPushButton{color:#202020;background:reg(0,0,0,0);border-image:url(:/Img/bg_osx2.png);border:0px;text-align : left; padding-left:70px}\
                QPushButton:hover{background:#dadada;border-image:none;}\
                QPushButton:pressed{color:#fff;background:#2d61e0;border-image:none;}";
    QString style_str5 = "QPushButton{color:#202020;background:reg(0,0,0,0);border-image:url(:/Img/bg_osx2.png);border:0px;text-align : left; padding-left:70px}\
                QPushButton:hover{background:#dadada;border-image:none;}\
                QPushButton:pressed{color:#fff;background:#2d61e0;border-image:none;}";
    QString style_str6 = "QPushButton{color:#202020;background:reg(0,0,0,0);border-image:url(:/Img/bg_osx2.png);border:0px;text-align : left; padding-left:70px}\
                QPushButton:hover{background:#dadada;border-image:none;}\
                QPushButton:pressed{color:#fff;background:#2d61e0;border-image:none;}";
    QString style_str7 = "QPushButton{color:#202020;background:reg(0,0,0,0);border-image:url(:/Img/bg_osx2.png);border:0px;text-align : left; padding-left:70px}\
                QPushButton:hover{background:#dadada;border-image:none;}\
                QPushButton:pressed{color:#fff;background:#2d61e0;border-image:none;}";
    read_page->setStyleSheet(QString(style_str1));
    read_page->setFixedSize(300, 60);
    read_page->setText("所有博客");
    read_page->setFont(QFont("anjalioldlipi", 10, QFont::Normal));
    write_page->setStyleSheet(QString(style_str2));
    write_page->setFixedSize(300, 60);
    write_page->setText("新建博客");
    write_page->setFont(QFont("anjalioldlipi", 10, QFont::Normal));
    send_mail->setStyleSheet(QString(style_str3));
    send_mail->setFixedSize(300, 60);
    send_mail->setText("发送信件");
    send_mail->setFont(QFont("anjalioldlipi", 10, QFont::Normal));
    look_firend->setStyleSheet(QString(style_str4));
    look_firend->setFixedSize(300, 60);
    look_firend->setText("我的好友");
    look_firend->setFont(QFont("anjalioldlipi", 10, QFont::Normal));
    chat->setStyleSheet(QString(style_str5));
    chat->setFixedSize(300, 60);
    chat->setText("实时聊天");
    chat->setFont(QFont("anjalioldlipi", 10, QFont::Normal));
    message_box->setStyleSheet(QString(style_str6));
    message_box->setFixedSize(300, 60);
    message_box->setText("私信盒子");
    message_box->setFont(QFont("anjalioldlipi", 10, QFont::Normal));
    aboutme->setStyleSheet(QString(style_str7));
    aboutme->setFixedSize(300, 60);
    aboutme->setText("关于我们");
    aboutme->setFont(QFont("anjalioldlipi", 10, QFont::Normal));

    QVBoxLayout *left_bar = new QVBoxLayout;

    left_bar->addLayout(h_search_area_layout);
    left_bar->addLayout(left_top_layout);
    //left_bar->addWidget(menu_name);
    left_top_layout->addWidget(read_page);
    left_top_layout->addWidget(write_page);
    left_top_layout->addWidget(send_mail);
    left_top_layout->addWidget(look_firend);
    left_top_layout->addWidget(chat);
    left_top_layout->addWidget(message_box);
    left_top_layout->addWidget(aboutme);
    left_top_layout->addStretch();
    left_top_layout->setContentsMargins(0, 30, 0, 0);
    storys_button->setFixedSize(150, 40);
    storys_button->setText("纵 观");
    storys_button->setFont(QFont("Source Code Pro for Powerline", 20, QFont::Normal));
    storys_button->setStyleSheet(QString("QPushButton{border:none;background-color:rgb(0,0,0,0);color:#808080;margin-left:0px;}"));
    edit_button->setFixedSize(150, 40);
    edit_button->setText("启 笔");
    edit_button->setFont(QFont("Source Code Pro for Powerline", 14, QFont::Normal));
    edit_button->setStyleSheet(QString("QPushButton{border:none;background-color:rgb(0,0,0,0);color:#cbcbcb;margin-left:0px}"));
    send_mail_button->setFixedSize(150, 40);
    send_mail_button->setText("传 书");
    send_mail_button->setFont(QFont("Source Code Pro for Powerline", 14, QFont::Normal));
    send_mail_button->setStyleSheet(QString("QPushButton{border:none;background-color:rgb(0,0,0,0);color:#cbcbcb;margin-left:0px}"));

    //这个区间内存放三个容器
    //对第一个容器进行布局
    writeArea[0] = new QWidget;
    //    writeArea[0]->resize(1920,800);
    QVBoxLayout *layout_view = new QVBoxLayout;
    /*表格属性设置*/
    //        story->setFixedWidth(900);
    story->setColumnCount(1);                                                                                                                                                                                                   //设置列数，行由代码动态添加
                                                                                                                                                                                                                                //        QStringList header;
                                                                                                                                                                                                                                //        header<<"Name"<<"Date"<<"Description"<<"Size";
                                                                                                                                                                                                                                //        story->setHorizontalHeaderLabels(header);
    story->setEditTriggers(QAbstractItemView::NoEditTriggers);                                                                                                                                                                  //将表格设置为禁止编辑
    story->setSelectionBehavior(QAbstractItemView::SelectRows);                                                                                                                                                                 //将表格设置为整行选择
    story->setFrameShape(QFrame::NoFrame);                                                                                                                                                                                      //将表格外边框设置为不可见
    story->setShowGrid(false);                                                                                                                                                                                                  //将表格内框线设置不可见
    story->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);                                                                                                                                                                  //隐藏滚动条
    story->setStyleSheet("selection-background-color:rgb(246, 246, 246);selection-color:#000;border-color:#f6f6f6;border-radius:8px; background:rgb(246, 246, 246); padding:0px;text-align :center;border:1px solid #dadada;"); //设置表格单元格被点击的样式
                                                                                                                                                                                                                                //        effectlabel_reg->setBlurRadius(16);        // 阴影圆角的大小
                                                                                                                                                                                                                                //        effectlabel_reg->setColor(QColor(186, 189, 187));      //阴影的颜色
                                                                                                                                                                                                                                //        effectlabel_reg->setOffset(0,0);
                                                                                                                                                                                                                                //        story->setGraphicsEffect(effectlabel_reg);
    story->verticalHeader()->setVisible(false);                                                                                                                                                                                 //横表头不可见
    story->horizontalHeader()->setVisible(false);                                                                                                                                                                               //竖表头不可见
    story->verticalHeader()->setDefaultSectionSize(300);                                                                                                                                                                        //行高
    story->horizontalHeader()->setStretchLastSection(true);                                                                                                                                                                     //表格宽度自适应父布局宽度
    story->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);                                                                                                                                          //单元格根据内容自适应宽度-----未使用
    refresh_button_view->setStyleSheet(QString("QPushButton{border-image: url(:/Img/load.png);border:none;border-radius:30px;padding:5px 50px;}"));
    refresh_button_view->setFixedSize(32, 32);
    vip_button_view->setStyleSheet(QString("QPushButton{border-image: url(:/Img/only_vip.png);border:none;border-radius:30px;padding:5px 50px;}"));
    vip_button_view->setFixedSize(32, 32);
    /*将表格和按钮置入框架中*/
    layout_view->addWidget(story);
    layout_view->addLayout(work_button_layout_view);
    layout_view->setContentsMargins(0, 10, 10, 0);
    work_button_layout_view->addStretch(12);
    work_button_layout_view->addWidget(refresh_button_view);
    work_button_layout_view->addStretch(1);
    work_button_layout_view->addWidget(vip_button_view);
    work_button_layout_view->addStretch(1);
    //将框架置入容器
    writeArea[0]->setLayout(layout_view);
    writeArea[0]->setContentsMargins(0, 0, 0, 0);
    stackwidget_work->addWidget(writeArea[0]);

    //对第二个容器进行布局
    writeArea[1] = new QWidget;
    //    writeArea[1]->resize(1920,1000);
    about_story->setFixedHeight(80);
    //        write_story->resize(1200,800);
    title_label->setText(u8"文章标题");
    about_label->setText(u8"摘要");
    edit_label->setText(u8"正文");
    subimt_button_write->setStyleSheet(QString("QPushButton{border-image: url(:/Img/upload.png);border:none;border-radius:30px;padding:5px 50px;}"));
    subimt_button_write->setFixedSize(32, 32);
    empty_button_write->setStyleSheet(QString("QPushButton{border-image: url(:/Img/clear.png);border:none;border-radius:30px;padding:5px 50px;}"));
    empty_button_write->setFixedSize(32, 32);

    layout_write->addWidget(title_label);
    layout_write->addWidget(page_title);
    layout_write->addWidget(about_label);
    layout_write->addWidget(about_story);
    layout_write->addWidget(edit_label);
    layout_write->addWidget(write_story);
    layout_write->addLayout(work_button_layout_write);
    work_button_layout_write->addStretch(12);
    work_button_layout_write->addWidget(subimt_button_write);
    work_button_layout_write->addStretch(1);
    work_button_layout_write->addWidget(empty_button_write);
    work_button_layout_write->addStretch(1);
    writeArea[1]->setLayout(layout_write);
    stackwidget_work->addWidget(writeArea[1]);

    //对第三个容器进行布局
    writeArea[2] = new QWidget;
    //    writeArea[2]->resize(1920,500);

    //        write_mail->resize(1920,500);
    write_mail->setText("这里是mail");
    sender_label->setText("发件人");
    reciver_label->setText("收件人");
    topic_label->setText("主题");
    write_mail_label->setText("正文");
    subimt_button_mail->setStyleSheet(QString("QPushButton{border-image: url(:/Img/send.png);border:none;border-radius:30px;padding:5px 50px;}"));
    subimt_button_mail->setFixedSize(32, 32);
    empty_button_mail->setStyleSheet(QString("QPushButton{border-image: url(:/Img/save.png);border:none;border-radius:30px;padding:5px 50px;}"));
    empty_button_mail->setFixedSize(32, 32);

    layout_mail->addWidget(sender_label);
    layout_mail->addWidget(sender_name);
    layout_mail->addWidget(reciver_label);
    layout_mail->addWidget(reciver_name);
    layout_mail->addWidget(topic_label);
    layout_mail->addWidget(topic_name);
    layout_mail->addWidget(write_mail_label);
    layout_mail->addWidget(write_mail);
    layout_mail->addLayout(work_button_layout_mail);
    work_button_layout_mail->addStretch(12);
    work_button_layout_mail->addWidget(subimt_button_mail);
    work_button_layout_mail->addStretch(1);
    work_button_layout_mail->addWidget(empty_button_mail);
    work_button_layout_mail->addStretch(1);
    writeArea[2]->setLayout(layout_mail);
    stackwidget_work->addWidget(writeArea[2]);
    stackwidget_work->setContentsMargins(0, 0, 0, 0);

    date_label->setFixedWidth(150);
    tip_img_label->setFixedSize(32, 32);

    //----menu部分控件

    //----work部分控件

    //---控件置入布局---第一层
    //    h_user_img_layout->addStretch();
    //    h_user_img_layout->addWidget(h_user_img_button);
    //    h_user_img_layout->addStretch();

    h_user_info_layout->addWidget(h_user_name_button);
    h_user_info_layout->addLayout(h_user_img_layout);

    //h_user_info_layout->addWidget(h_user_leavl_label);
    //h_user_info_layout->addWidget(h_user_vip_label);

    h_button_area_layout->addStretch(10);
    h_button_area_layout->addWidget(h_refresh_button);
    h_button_area_layout->addWidget(h_quit_button);

    h_search_area_layout->addLayout(h_search_top);
    h_search_top->addWidget(h_search_input);
    h_search_top->addWidget(h_search_button);

    //    type_bar_layout->addWidget(storys_button);
    //    type_bar_layout->addWidget(edit_button);
    //    type_bar_layout->addWidget(send_mail_button);
    //    type_bar_layout->addStretch();

    edit_area_layout->addWidget(stackwidget_work);
    edit_area_layout->setContentsMargins(0, 0, 0, 0);

    tips_layout->addWidget(date_label);
    tips_layout->addWidget(info_lable);
    tips_layout->addWidget(tip_img_label);

    //---布局置入布局---第二层

    //head_layout->addLayout(h_search_area_layout);
    head_layout->addStretch();
    head_layout->addLayout(h_button_area_layout);
    head_layout->addLayout(h_user_info_layout);
    head_layout->setContentsMargins(10, 0, 0, 0);
    QTableWidget *topbar = new QTableWidget;
    effectlabel_reg->setBlurRadius(40);               // 阴影圆角的大小
    effectlabel_reg->setColor(QColor(186, 189, 187)); //阴影的颜色
    effectlabel_reg->setOffset(0, 0);
    topbar->setGraphicsEffect(effectlabel_reg);
    topbar->setColumnCount(1);
    topbar->setFixedHeight(34);
    topbar->setLayout(head_layout);
    topbar->setStyleSheet("padding-top:0px;margin-top:0px;border:none");
    topbar->verticalHeader()->setVisible(false);   //横表头不可见
    topbar->horizontalHeader()->setVisible(false); //竖表头不可见
    //head_layout->addLayout(h_user_img_layout);

    menu_layout->addLayout(left_bar);
    bottom_layout->addLayout(menu_layout);
    bottom_layout->setContentsMargins(0, 0, 0, 0);
    //work_layout->addLayout(type_bar_layout);
    work_layout->setContentsMargins(0, 0, 0, 0);
    work_layout->addLayout(edit_area_layout);
    QHBoxLayout *work_layout_h = new QHBoxLayout;
    work_layout_h->setContentsMargins(0, 0, 0, 0);
    //    work_layout_h->addStretch();
    work_layout_h->addLayout(work_layout);
    //    work_layout_h->addStretch();
    //--布局置入布局---第三层
    background_layout->addWidget(topbar);
    right_layout->addLayout(bottom_layout);
    right_layout->addLayout(work_layout_h);
    //right_layout->addStretch();
    //right_layout->addLayout(tips_layout);
    right_layout->setContentsMargins(0, 0, 0, 0);
    background_layout->addLayout(right_layout);
    background_layout->addLayout(tips_layout);
    background_layout->setSpacing(0);
    background_layout->setContentsMargins(0, 0, 0, 0);

    //置入主布局
    setLayout(background_layout);
}

/*槽函数:用来响应点击用户名按钮之后弹出登录界面并在界面关闭之后执行showinfo()*/
void appDisplay::openlogin()
{
    qDebug() << "点击了用户名" << endl;
    myWidget *loginWindow = new myWidget;
    loginWindow->move(700, 130);
    loginWindow->show();
    //绑定信号和槽函数，当登录成功时执行
    connect(loginWindow, SIGNAL(IamClose()), this, SLOT(showinfo()));
}

/*槽函数:在程序开始运行时自动执行一次,在点击刷新,登录界面关闭时也会运行,主要调用net_server的relogin方法*/
void appDisplay::showinfo()
{
    qDebug() << "appDisplay::showinfo--->debug"
             << "刷新主页面信息";
    net_server ns;
    QString h_user_name_button_txt = ns.relogin();
    //点击刷新按钮或者重新登录时刷新文章列表
    story->clearContents(); //清空文章列表
    story->setRowCount(0);  //设置行为0,来清除空白行
    showTable();
    h_user_name_button->setText(h_user_name_button_txt);
    QString str = "旧梦   【" + h_user_name_button_txt + "】  前尘浅唱";
    char *caMsg = NULL;
    QByteArray temp = str.toLocal8Bit();
    if (h_user_name_button_txt == "Internet_error")
    {
        QMessageBox::about(this, tr("提示"), tr("\n        服务器异常，请检查网络连接！        \n"));
        h_user_name_button->setText("请登录/注册");
        this->setWindowTitle(QObject::tr("旧梦    君在何方"));
        return;
    }
    if (h_user_name_button_txt == "请登录/注册")
    {
        h_user_name_button->setText("请登录/注册");
        this->setWindowTitle(QObject::tr("旧梦    君在何方"));
        return;
    }
    caMsg = temp.data();
    this->setWindowTitle(QObject::tr(caMsg));
    //点击刷新按钮或者重新登录时刷新树形结构
    treeWidget->clear(); //清空树形结构的所有内容
    //重新生成父列表
    item_public = new QTreeWidgetItem(treeWidget, QStringList(QString("所有文章")));
    item_public->setIcon(0, QIcon(":/Img/public.png"));
    item_private = new QTreeWidgetItem(treeWidget, QStringList(QString("我的文章")));
    item_private->setIcon(0, QIcon(":/Img/private.png"));
    item_firend = new QTreeWidgetItem(treeWidget, QStringList(QString("我的朋友")));
    item_firend->setIcon(0, QIcon(":/Img/friend.png"));
    showTree("public");
    showTree(h_user_name_button_txt);
    showTree(h_user_name_button_txt + "Msg");

    return;
}

/*槽函数:在点击注销按钮之后执行,会清空界面所有信息并执行net_server的quitAccount方法*/
void appDisplay::quitAccount()
{
    if (QMessageBox::question(NULL, "确认注销", "注销意味着您需要再次登录\n确认要注销吗?\n\n", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes) == QMessageBox::Yes)
    {
        net_server ns;
        QString h_user_name_button_txt = ns.quitAccount();
        QMessageBox::about(this, tr("提示"), tr("\n     注销成功!        \n"));
        this->setWindowTitle(QObject::tr("旧梦    君在何方"));
        h_user_name_button->setText(h_user_name_button_txt);
        treeWidget->clear();    //清空树形结构的所有内容
        story->clearContents(); //清空文章列表
        story->setRowCount(0);  //设置行为0,来清除空白行
    }
    else
    {
        return;
    }
}

/*槽函数:实现在工作区内点击不同的标题选项卡切换不同界面*/
void appDisplay::slt_setPageWidget()
{

    QString style_str1 = "QPushButton{color:#202020;background:reg(0,0,0,0);border-image:url(:/Img/bg_osx2.png);border:0px;text-align : left; padding-left:70px}\
            QPushButton:hover{background:#dadada;border-image:none;}\
            QPushButton:pressed{color:#fff;background:#2d61e0;border-image:none;}";
    QString style_str2 = "QPushButton{color:#202020;background:reg(0,0,0,0);border-image:url(:/Img/bg_osx2.png);border:0px;text-align : left; padding-left:70px}\
            QPushButton:hover{background:#dadada;border-image:none;}\
            QPushButton:pressed{color:#fff;background:#2d61e0;border-image:none;}";
    QString style_str3 = "QPushButton{color:#202020;background:reg(0,0,0,0);border-image:url(:/Img/bg_osx2.png);border:0px;text-align : left; padding-left:70px}\
            QPushButton:hover{background:#dadada;border-image:none;}\
            QPushButton:pressed{color:#fff;background:#2d61e0;border-image:none;}";
    QString style_str4 = "QPushButton{color:#202020;background:reg(0,0,0,0);border-image:url(:/Img/bg_osx2.png);border:0px;text-align : left; padding-left:70px}\
            QPushButton:hover{background:#dadada;border-image:none;}\
            QPushButton:pressed{color:#fff;background:#2d61e0;border-image:none;}";
    QString style_str5 = "QPushButton{color:#202020;background:reg(0,0,0,0);border-image:url(:/Img/bg_osx2.png);border:0px;text-align : left; padding-left:70px}\
            QPushButton:hover{background:#dadada;border-image:none;}\
            QPushButton:pressed{color:#fff;background:#2d61e0;border-image:none;}";
    QString style_str6 = "QPushButton{color:#202020;background:reg(0,0,0,0);border-image:url(:/Img/bg_osx2.png);border:0px;text-align : left; padding-left:70px}\
            QPushButton:hover{background:#dadada;border-image:none;}\
            QPushButton:pressed{color:#fff;background:#2d61e0;border-image:none;}";
    QString style_str7 = "QPushButton{color:#202020;background:reg(0,0,0,0);border-image:url(:/Img/bg_osx2.png);border:0px;text-align : left; padding-left:70px}\
            QPushButton:hover{background:#dadada;border-image:none;}\
            QPushButton:pressed{color:#fff;background:#2d61e0;border-image:none;}";

    QString style_str1_p = "QPushButton{color:#fff;background:#2d61e0;border:0px;text-align : left; padding-left:70px}";
    QString style_str2_p = "QPushButton{color:#fff;background:#2d61e0;border:0px;text-align : left; padding-left:70px}";
    QString style_str3_p = "QPushButton{color:#fff;background:#2d61e0;border:0px;text-align : left; padding-left:70px}";
    QString style_str4_p = "QPushButton{color:#fff;background:#2d61e0;border:0px;text-align : left; padding-left:70px}";
    QString style_str5_p = "QPushButton{color:#fff;background:#2d61e0;border:0px;text-align : left; padding-left:70px}";
    QString style_str6_p = "QPushButton{color:#fff;background:#2d61e0;border:0px;text-align : left; padding-left:70px}";
    QString style_str7_p = "QPushButton{color:#fff;background:#2d61e0;border:0px;text-align : left; padding-left:70px}";
    //获取触发槽的是哪个部件所发出的信号，并获取到那个指针
    QPushButton *widget = static_cast<QPushButton *>(sender());
    if (widget == read_page)
    {
        read_page->setStyleSheet(QString(style_str1_p));
        write_page->setStyleSheet(QString(style_str2));
        send_mail->setStyleSheet(QString(style_str3));
        look_firend->setStyleSheet(QString(style_str4));
        chat->setStyleSheet(QString(style_str5));
        message_box->setStyleSheet(QString(style_str6));
        aboutme->setStyleSheet(QString(style_str7));
        stackwidget_work->setCurrentIndex(0);
    }
    else if (widget == write_page)
    {
        read_page->setStyleSheet(QString(style_str1));
        write_page->setStyleSheet(QString(style_str2_p));
        send_mail->setStyleSheet(QString(style_str3));
        look_firend->setStyleSheet(QString(style_str4));
        chat->setStyleSheet(QString(style_str5));
        message_box->setStyleSheet(QString(style_str6));
        aboutme->setStyleSheet(QString(style_str7));
        stackwidget_work->setCurrentIndex(1);
    }
    else if (widget == send_mail)
    {
        read_page->setStyleSheet(QString(style_str1));
        write_page->setStyleSheet(QString(style_str2));
        send_mail->setStyleSheet(QString(style_str3_p));
        look_firend->setStyleSheet(QString(style_str4));
        chat->setStyleSheet(QString(style_str5));
        message_box->setStyleSheet(QString(style_str6));
        aboutme->setStyleSheet(QString(style_str7));
        stackwidget_work->setCurrentIndex(2);
    }
}

/*槽函数:在showinfo函数中调用,函数调用了net_server的showtable_server方法,根据服务器的返回值动态显示表格内容*/
void appDisplay::showTable()
{
    int RowCont = 0;
    RowCont = story->rowCount();
    //返回一个Qlist，信息之间使用#连接，每行是一条记录
    QList<QString> table_list;
    net_server ns;
    table_list = ns.showtable_server();
    for (int x = 0; x < table_list.length(); x++)
    {
        //赋值,将传递来的整个字符串拆分
        QString data = table_list.at(x);
        qDebug() << "客户端--table_list的内容" << data;
        QString author_info = data.section('#', 0, 0).trimmed();
        QString pageName = data.section("#", 1, 1).trimmed();
        QString pagedate = data.section("#", 2, 2).trimmed();
        QString pagetype = data.section("#", 3, 3).trimmed();
        QString like = data.section("#", 4, 4).trimmed();
        QString diss = data.section("#", 5, 5).trimmed();

        QTableWidget *tb = new QTableWidget(3, 1);

        //                effectlabel_reg->setBlurRadius(16);        // 阴影圆角的大小
        //                effectlabel_reg->setColor(QColor(186, 189, 187));      //阴影的颜色
        //                effectlabel_reg->setOffset(0,0);
        //                tb->setGraphicsEffect(effectlabel_reg);
        tb->setStyleSheet("selection-background-color:#fff;selection-color:#000;border-color:#f6f6f6;border-radius:8px; background:rgb(0,0,0,0); padding:20px;text-align :center;margin:20px;border:1px solid #dadada;"); //设置表格单元格被点击的样式
        tb->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tb->verticalHeader()->setVisible(false);
        tb->horizontalHeader()->setVisible(false);
        tb->horizontalHeader()->setStretchLastSection(true);
        tb->verticalHeader()->setStretchLastSection(true);
        tb->setFrameShape(QFrame::NoFrame);
        tb->setShowGrid(false);
        QTableWidgetItem *title = new QTableWidgetItem(pageName);
        title->setFont(QFont("nomorl", 14, QFont::Normal));
        QTableWidgetItem *author = new QTableWidgetItem(author_info);
        QTableWidgetItem *page = new QTableWidgetItem(pagetype);
        tb->setItem(0, 0, title);
        tb->setItem(1, 0, author);
        tb->setItem(2, 0, page);
        story->insertRow(RowCont); //增加一行
        story->setCellWidget(RowCont, 0, tb);
    }
}

/*槽函数:在showinfo函数中调用,函数调用了showtree_public_server方法,根据服务器返回的QList动态显示树形结构的内容*/
void appDisplay::showTree(QString username_tostps)
{
    //QTreeWidgetItem *item1_3 = new QTreeWidgetItem(item1,QStringList(QString("wewqewq")));
    //在net_server的showTree_server 中，分为三个部分，
    //第一部分：showTree_public_server请求服务器发送 public 表的所有内容到本地，然后以链表的方式传递到界面并显示，
    //第二部分：showTree_private_server传入当前用户名到net_server，如果用户名内容不是 请登录/注册 就传递到服务器并返回用户名所在表的所有内容
    //第三部分：showTree_friend_server串入当前用户名到net server,...，返回好友名称列表
    QList<QString> getlist1;
    net_server ns;
    getlist1 = ns.showTree_public_server(username_tostps);
    qDebug() << getlist1.size();
    if (username_tostps == "public")
    {
        for (int i = 0; i < getlist1.size(); i++)
        {
            QString info = getlist1.at(i);
            QTreeWidgetItem *item = new QTreeWidgetItem(item_public, QStringList(QString(info)));
            item_public->addChild(item);
        }
    }
    else if (username_tostps.contains("Msg", Qt::CaseSensitive))
    {
        for (int i = 0; i < getlist1.size(); i++)
        {
            QString info = getlist1.at(i);
            QTreeWidgetItem *item = new QTreeWidgetItem(item_firend, QStringList(QString(info)));
            item_firend->addChild(item);
        }
    }
    else
    {
        for (int i = 0; i < getlist1.size(); i++)
        {
            QString info = getlist1.at(i);
            QTreeWidgetItem *item = new QTreeWidgetItem(item_private, QStringList(QString(info)));
            item_private->addChild(item);
        }
    }
}
