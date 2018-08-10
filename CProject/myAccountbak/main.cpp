#include "mywidget.h"
#include "appdisplay.h"
#include <QApplication>
#include <QProcess>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    myWidget w;
    appDisplay from;
    from.move(300,100);
    from.show();
//    w.move(760,180);
//    w.show();

    return a.exec();
}
