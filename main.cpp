/***************************************************************
*Copyright (c) 2017,Wuhan
*All rights reserved.
*
*文件名称: main.cpp
*文件标识: 律师费用计算器主函数文件
*
*当前版本：V1.0
*作者：Frank Liu 
*完成日期：20171113
*
*修改记录1：   //修改历史记录，包括修改日期、版本号、修改人及修改内容等
*修改日期        版本号              修改人         修改内容

* 20171113         V1.0              Frank            创建
******************************************************************/
#include "mainwin.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    #if (QT_VERSION >= QT_VERSION_CHECK(5, 6, 0))
        QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    #endif
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
