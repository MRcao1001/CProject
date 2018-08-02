#ifndef WATING_H
#define WATING_H

#include <QWidget>
#include <QTimer>
#include <QTimer>
#include "mywidget.h"
namespace Ui {
class wating;
}

class wating : public QWidget
{
    Q_OBJECT

public:
    explicit wating(QWidget *parent = 0);
    ~wating();
public slots:

signals:
    void loading();

private:
    Ui::wating *ui;
    QMovie *movie;
    QLabel *label;
    QLabel * tip_label;
    QFrame * background;
    QTimer *timer ;
};

#endif // WATING_H
