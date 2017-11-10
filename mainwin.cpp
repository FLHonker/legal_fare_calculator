#include "mainwin.h"
#include "ui_mainwin.h"

MainWin::MainWin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWin)
{
    ui->setupUi(this);
    isUpLimit = true;
}

MainWin::~MainWin()
{
    delete ui;
}

// 计算律师费函数
void MainWin::calculate(double arg1)
{
    if(arg1 <= 10000)   //1万元以下的
        fare = 1500;
    else if(arg1 > 10000 && arg1 <= 100000)
    {
        if(isUpLimit)
            fare = arg1 * 0.09;
        else
            fare = arg1 * 0.06;
    }
    else if(arg1 > 100000 && arg1 < 500000)
    {
        if(isUpLimit)
            fare = arg1 * 0.06;
        else
            fare = arg1 * 0.05;
    }
    else if(arg1 > 500000 && arg1 <= 1000000)
    {
        if(isUpLimit)
            fare = arg1 * 0.05;
        else
            fare = arg1 * 0.04;
    }
    else if(arg1 > 1000000 && arg1 < 5000000)
    {
        if(isUpLimit)
            fare = arg1 * 0.04;
        else
            fare = arg1 * 0.03;
    }
    else    //大于500万的
    {
        if(isUpLimit)
            fare = arg1 * 0.04;
        else
            fare = arg1 * 0.03;
    }
    // 律师费文本框显示费用
    ui->lineEdit_fare->setText(QString::number(fare, 10, 2));
}

// 争议财产标的金额值改变，自动显示相应律师费
void MainWin::on_doubleSpinBox_money_valueChanged(double arg1)
{
    asset = arg1;
    calculate(asset);
}

// 选中"上限"
void MainWin::on_rBtn_upLimit_toggled(bool checked)
{
    isUpLimit = checked;
    calculate(asset);
}

// 选中"下限"
void MainWin::on_rBtn_downLimit_clicked()
{
    calculate(asset);
}

// 清除，清理
void MainWin::on_actionClear_triggered()
{
    ui->doubleSpinBox_money->clear();
    ui->lineEdit_fare->clear();
    ui->rBtn_upLimit->setChecked(true);
}

// 退出
void MainWin::on_actionExit_triggered()
{
    qApp->quit();
}

// 帮助
void MainWin::on_actionHelp_H_triggered()
{
    QString helpText("版权所有，严谨私自用于商业用途！\n按下列比例分段累加计算律师费：\n1万元及以下收费1500元；\n1万（不含）—10万元（含）部分收费比例为6%-9%；\n10万-50万元（含）部分为5%-6%；\n50万-100万元（含）部分为4%-5%；\n100万—500万元（含）部分为3%-4%。");
    QMessageBox::about(this, tr("帮助"), helpText);
}

// 关于
void MainWin::on_actionAbout_B_triggered()
{
    QString aboutText("@name：山东辰林律师事务所用，律师费计算器。\n@author：刘宇昂 （Frank Liu）\n@time：2017-11-10\n@version：V2.0\n根据卢立清 1.0.0.1版本改编。");
    QMessageBox::about(this, tr("关于律师费计算器"), aboutText);
}
