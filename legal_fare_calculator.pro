#/* **************************************************************
#*Copyright (c) 2017,Wuhan
#*All rights reserved.
#*
#*文件名称: legal_fare_calculator.pro
#*文件标识: 律师费用计算器Qt项目管理文件
#*
#*当前版本：V1.0
#*作者：Frank Liu
#*完成日期：20171113
#*
#*修改记录1：   //修改历史记录，包括修改日期、版本号、修改人及修改内容等
#*修改日期        版本号              修改人         修改内容

#* 20171113         V1.0              Frank            创建
#***************************************************************** */
#-------------------------------------------------
#
# Project created by QtCreator 2017-11-10T14:36:46
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = legal_fare_calculator
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwin.cpp

HEADERS  += mainwin.h

FORMS    += mainwin.ui

CONFIG += mobility
MOBILITY = 

RESOURCES += \
    images.qrc

DISTFILES += \
    ico.rc

RC_FILE += ico.rc
