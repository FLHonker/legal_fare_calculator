#include "mainwin.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWin w;
    /* 设置背景颜色
    QPalette palette(w.palette());
    palette.setColor(QPalette::Background, Qt::lightGray);
    w.setPalette(palette);
    */
    w.show();

    return app.exec();
}
