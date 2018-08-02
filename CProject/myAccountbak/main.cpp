#include "mywidget.h"
#include "appdisplay.h"
#include <QApplication>
#include <QProcess>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    myWidget w;
    appDisplay from;
    from.move(150,50);
    from.show();
//    w.move(760,180);
//    w.show();

    return a.exec();
}
