/********************************************************************************
** Form generated from reading UI file 'mainwin.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIN_H
#define UI_MAINWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWin
{
public:
    QAction *actionClear;
    QAction *actionExit;
    QAction *actionHelp_H;
    QAction *actionAbout_B;
    QWidget *centralWidget;
    QLabel *label;
    QLabel *label_2;
    QDoubleSpinBox *doubleSpinBox_money;
    QLabel *label_3;
    QRadioButton *rBtn_upLimit;
    QRadioButton *rBtn_downLimit;
    QLabel *label_4;
    QLineEdit *lineEdit_fare;
    QLabel *label_5;
    QGroupBox *groupBox;
    QMenuBar *menuBar;
    QMenu *menu_F;
    QMenu *menu_H;

    void setupUi(QMainWindow *MainWin)
    {
        if (MainWin->objectName().isEmpty())
            MainWin->setObjectName(QStringLiteral("MainWin"));
        MainWin->resize(404, 223);
        MainWin->setMaximumSize(QSize(404, 223));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icon/icon/Calculator_1001px.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWin->setWindowIcon(icon);
        actionClear = new QAction(MainWin);
        actionClear->setObjectName(QStringLiteral("actionClear"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icon/icon/clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClear->setIcon(icon1);
        actionExit = new QAction(MainWin);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/icon/icon/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon2);
        actionHelp_H = new QAction(MainWin);
        actionHelp_H->setObjectName(QStringLiteral("actionHelp_H"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/icon/icon/help.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionHelp_H->setIcon(icon3);
        actionAbout_B = new QAction(MainWin);
        actionAbout_B->setObjectName(QStringLiteral("actionAbout_B"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/icon/icon/about-us.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbout_B->setIcon(icon4);
        centralWidget = new QWidget(MainWin);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 30, 131, 21));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(11);
        label->setFont(font);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(340, 30, 21, 21));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font1.setPointSize(11);
        font1.setItalic(false);
        label_2->setFont(font1);
        doubleSpinBox_money = new QDoubleSpinBox(centralWidget);
        doubleSpinBox_money->setObjectName(QStringLiteral("doubleSpinBox_money"));
        doubleSpinBox_money->setGeometry(QRect(190, 30, 141, 22));
        doubleSpinBox_money->setMaximum(1e+10);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(60, 80, 71, 21));
        label_3->setFont(font);
        rBtn_upLimit = new QRadioButton(centralWidget);
        rBtn_upLimit->setObjectName(QStringLiteral("rBtn_upLimit"));
        rBtn_upLimit->setGeometry(QRect(140, 80, 51, 21));
        rBtn_upLimit->setChecked(true);
        rBtn_downLimit = new QRadioButton(centralWidget);
        rBtn_downLimit->setObjectName(QStringLiteral("rBtn_downLimit"));
        rBtn_downLimit->setGeometry(QRect(200, 80, 51, 21));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(50, 130, 54, 21));
        label_4->setFont(font);
        lineEdit_fare = new QLineEdit(centralWidget);
        lineEdit_fare->setObjectName(QStringLiteral("lineEdit_fare"));
        lineEdit_fare->setGeometry(QRect(110, 130, 151, 21));
        QFont font2;
        font2.setFamily(QStringLiteral("SansSerif"));
        font2.setPointSize(11);
        lineEdit_fare->setFont(font2);
        lineEdit_fare->setReadOnly(true);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(270, 130, 21, 21));
        label_5->setFont(font1);
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(50, 60, 221, 51));
        MainWin->setCentralWidget(centralWidget);
        groupBox->raise();
        label->raise();
        label_2->raise();
        doubleSpinBox_money->raise();
        label_3->raise();
        rBtn_upLimit->raise();
        rBtn_downLimit->raise();
        label_4->raise();
        lineEdit_fare->raise();
        label_5->raise();
        menuBar = new QMenuBar(MainWin);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 404, 22));
        menu_F = new QMenu(menuBar);
        menu_F->setObjectName(QStringLiteral("menu_F"));
        menu_H = new QMenu(menuBar);
        menu_H->setObjectName(QStringLiteral("menu_H"));
        MainWin->setMenuBar(menuBar);

        menuBar->addAction(menu_F->menuAction());
        menuBar->addAction(menu_H->menuAction());
        menu_F->addAction(actionClear);
        menu_F->addSeparator();
        menu_F->addAction(actionExit);
        menu_H->addAction(actionHelp_H);
        menu_H->addAction(actionAbout_B);

        retranslateUi(MainWin);

        QMetaObject::connectSlotsByName(MainWin);
    } // setupUi

    void retranslateUi(QMainWindow *MainWin)
    {
        MainWin->setWindowTitle(QApplication::translate("MainWin", "\345\276\213\345\270\210\350\264\271\350\256\241\347\256\227\345\231\250 V2.0", Q_NULLPTR));
        actionClear->setText(QApplication::translate("MainWin", "\346\270\205\351\231\244(&D)", Q_NULLPTR));
        actionClear->setShortcut(QApplication::translate("MainWin", "Ctrl+D", Q_NULLPTR));
        actionExit->setText(QApplication::translate("MainWin", "\351\200\200\345\207\272(&Q)", Q_NULLPTR));
        actionExit->setShortcut(QApplication::translate("MainWin", "Ctrl+Q", Q_NULLPTR));
        actionHelp_H->setText(QApplication::translate("MainWin", "\345\270\256\345\212\251(&H)", Q_NULLPTR));
        actionHelp_H->setShortcut(QApplication::translate("MainWin", "Ctrl+H", Q_NULLPTR));
        actionAbout_B->setText(QApplication::translate("MainWin", "\345\205\263\344\272\216(&B)", Q_NULLPTR));
        actionAbout_B->setShortcut(QApplication::translate("MainWin", "Ctrl+B", Q_NULLPTR));
        label->setText(QApplication::translate("MainWin", "\344\272\211\350\256\256\350\264\242\344\272\247\346\240\207\347\232\204\351\207\221\351\242\235\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWin", "\345\205\203", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWin", "\350\264\271\347\224\250\351\231\220\345\210\266\357\274\232", Q_NULLPTR));
        rBtn_upLimit->setText(QApplication::translate("MainWin", "\344\270\212\351\231\220", Q_NULLPTR));
        rBtn_downLimit->setText(QApplication::translate("MainWin", "\344\270\213\351\231\220", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWin", "\345\276\213\345\270\210\350\264\271\357\274\232", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWin", "\345\205\203", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWin", "\350\256\276\347\275\256", Q_NULLPTR));
        menu_F->setTitle(QApplication::translate("MainWin", "\346\226\207\344\273\266(&F)", Q_NULLPTR));
        menu_H->setTitle(QApplication::translate("MainWin", "\345\270\256\345\212\251(&H)", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWin: public Ui_MainWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIN_H
