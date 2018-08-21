#include "wating.h"
#include "ui_wating.h"
#include "mywidget.h"

wating::wating(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::wating)
{
    ui->setupUi(this);
    QPalette pal = palette();
    pal.setColor(QPalette::Background, QColor(0x00,0xff,0x00,0x00));
    setPalette(pal);
    this->setFixedSize(32,32);
    background = new QFrame(this);
    background->setStyleSheet("background-color:rgb(0,0,0,0);border-radius:10px;");
    background->setGeometry(0, 0, 0, 0);
    label = new QLabel(background);
    label->setGeometry(0, 0, 32, 32);
    movie = new QMovie(":/Img/loading_mac.gif");
    movie->setScaledSize(QSize(32,32));
    label->setScaledContents(true);
    label->setMovie(movie);
    movie->start();
    qDebug()<<"loading";
    connect(this,SIGNAL(loading()),this,SLOT(close()));
}


wating::~wating()
{
    delete background;
    delete label;
    delete movie;
    delete ui;
}
