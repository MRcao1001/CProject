#ifndef APPDISPLAY_H
#define APPDISPLAY_H

#include "mywidget.h"
#include "net_server.h"
#include <QWidget>
#include <QtWidgets/QWidget>
#include <qgridlayout.h>
#include <qlabel.h>
#include <QLabel>
#include <QLayout>
#include <QPushButton>
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
#include <QLineEdit>
#include <QPixmap>
#include <QCheckBox>
#include <QFrame>
#include <QScrollArea>
#include <QTreeView>
#include <QListView>
#include <QStandardItemModel>
#include <QTextEdit>
#include <QListWidget>
#include <QTableWidget>
#include <QHeaderView>
#include <QTreeWidget>
#include <QComboBox>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QComboBox>
namespace Ui {
class appDisplay;
}

class appDisplay : public QWidget
{
    Q_OBJECT

public:
    explicit appDisplay(QWidget *parent = 0);
    ~appDisplay();
    void InitializationWidget();
    void SetUpTheLayout();

public slots:
    void openlogin();
    void showinfo();
    void quitAccount();
    void slt_setPageWidget();
    void showTable();
    void showTree(QString username_tostps);
    void addFunc();
    void delFunc();
private:
    Ui::appDisplay *ui;
    int row=0;
    int colum=0;

    QVBoxLayout *background_layout;
    //----1----
    //-head-layout
    QFrame *headFrame;
    QHBoxLayout *right_layout;
    QVBoxLayout *left_top_layout;
    QLabel *LOGO;
    QLabel *app_name;
    QLabel *menu_name;
    QPushButton *read_page;
    QPushButton *write_page;
    QPushButton *send_mail;
    QPushButton *look_firend;
    QPushButton *chat;
    QPushButton *message_box;
    QPushButton *aboutme;

    QHBoxLayout *head_layout;

    //--h_user_img_layout
    QVBoxLayout *h_user_img_layout;
    QPushButton *h_user_img_button;
    //--h_user_info_layout
    QHBoxLayout *h_user_info_layout;
    QPushButton *h_user_name_button;
    QLabel *h_user_leavl_label;
    QLabel *h_user_vip_label;
    //--h_button_area_layout
    QHBoxLayout *h_button_area_layout;
    QPushButton *h_message_button;
    QPushButton *h_show_friend_button;
    QPushButton *h_refresh_button;
    QPushButton *h_quit_button;
    //--h_search_area_layout
    QVBoxLayout *h_search_area_layout;
    //---h_search_top
    QHBoxLayout *h_search_top;
    QLineEdit *h_search_input;
    QPushButton *h_search_button;
    //---h_search_bottom
    QHBoxLayout *h_search_bottom;
    QCheckBox *h_condition_chec;
    //----2----
    QHBoxLayout *bottom_layout;
    //-menu-layout
    QVBoxLayout *menu_layout;
    //--scroll_area
    QScrollArea *scroll_menu;//https://blog.csdn.net/liang19890820/article/details/52402002
    QTreeWidget *treeWidget;
    QTreeWidgetItem *item_public ;
    QTreeWidgetItem *item_private;
    QTreeWidgetItem *item_firend;
    //---menu-tree_view
    QStandardItemModel left_list;//https://blog.csdn.net/qq_35158695/article/details/72717170--https://blog.csdn.net/czyt1988/article/details/18996407
    //----treeItem_folder_friend
    //----treeItem_folder_private
    //----treeItem_folder_public
    //----3----
    //  work-layout
    QVBoxLayout *work_layout;
    //  type_bar_layout
    QHBoxLayout *type_bar_layout;
    QPushButton *storys_button;
    QPushButton *edit_button;
    QPushButton *send_mail_button;
    //  edit_area_layout
    QStackedWidget *stackwidget_work;
    QWidget *writeArea[4];//这是主界面实现标签切换界面的容器
    QVBoxLayout *layout_write;
    QLabel *title_label;
    QLineEdit *page_title;
    QLabel *about_label;
    QTextEdit *about_story;
    QLabel *edit_label;
    QTextEdit *write_story;

    QVBoxLayout *layout_mail;
    QTextEdit *write_mail;
    QLabel *sender_label;
    QLineEdit *sender_name;
    QLabel *reciver_label;
    QComboBox *reciver_name;
    QLabel *topic_label;
    QLineEdit *topic_name;
    QLabel *write_mail_label;

    QVBoxLayout *edit_area_layout;
    QScrollArea *scroll_edit;
    //	1、listview
    QTableWidget *story;
    //  work_button_layout
    QHBoxLayout *work_button_layout_view;
    QHBoxLayout *work_button_layout_write;
    QHBoxLayout *work_button_layout_mail;
    QPushButton *refresh_button_view;
    QPushButton *vip_button_view;
    QPushButton *subimt_button_write;
    QPushButton *empty_button_write;
    QPushButton *subimt_button_mail;
    QPushButton *empty_button_mail;
    //----4----
    //  tips-layout
    QHBoxLayout *tips_layout;
    //  date_label
    QLabel *date_label;
    //  info_leble
    QLabel *info_lable;
    //  tip_img_label
    QLabel *tip_img_label;
    QGraphicsDropShadowEffect *effectlabel_reg;
    QGraphicsDropShadowEffect *effectlabel_index;

    };

#endif // APPDISPLAY_H
