/***************************************************************
*Copyright (c) 2017,Wuhan
*All rights reserved.
*
*文件名称: mainwin.h
*文件标识: 律师费用计算器窗体主函数头文件
*
*当前版本：V1.0
*作者：Frank Liu 
*完成日期：20171113
*
*修改记录1：   //修改历史记录，包括修改日期、版本号、修改人及修改内容等
*修改日期        版本号              修改人         修改内容

* 20171113         V1.0              Frank            创建
******************************************************************/

#ifndef MAINWIN_H
#define MAINWIN_H

#include <QMainWindow>
#include <QMessageBox>

namespace Ui {
class MainWin;
}

class MainWin : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWin(QWidget *parent = 0);
    ~MainWin();

private slots:
    void on_doubleSpinBox_money_valueChanged(double val);

    void on_actionClear_triggered();

    void on_actionExit_triggered();

    void on_actionHelp_H_triggered();

    void on_actionAbout_B_triggered();

    void on_comboBox_2_currentIndexChanged(int index);

    void on_comboBox_1_currentIndexChanged(int index);

private:
    Ui::MainWin *ui;
    double asset;  //资产
    double fare;   //费用
    QString moneyQstr;
    void ConvertMoneyCaps(long double moneySum);
    void calculate_zichan(double arg1);     // 计算资产评估服务收费函数
    void calculate_fangdichan(double arg2); // 计算房地产价格评估服务收费函数
};

#endif // MAINWIN_H
