/***************************************************************
*Copyright (c) 2017,Wuhan
*All rights reserved.
*
*文件名称: mainwin.cpp
*文件标识: 律师费用计算器窗体主函数文件
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
#include "ui_mainwin.h"

MainWin::MainWin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWin)
{
    ui->setupUi(this);
}

MainWin::~MainWin()
{
    delete ui;
}

void MainWin::on_doubleSpinBox_money_valueChanged(double val)
{
    asset = val;

    // 人民币单位选择
    if(ui->comboBox_2->currentIndex()==1)  // 使用万元单位
    {
        asset *= 10000;
        ui->yuan_1->setText("万元");
        ui->yuan_2->setText("万元");
    }
    else if(ui->comboBox_2->currentIndex()==0)   // 使用元单位
    {
         ui->yuan_1->setText("元");
         ui->yuan_2->setText("元");
    }

    // 计算费用
    if(ui->comboBox_1->currentIndex()==0)  // 计算资产评估服务收费
    {
        calculate_zichan(asset);
    }
    else if(ui->comboBox_1->currentIndex()==1)
    {
        calculate_fangdichan(asset);
    }
}

// 计算资产评估服务收费函数
void MainWin::calculate_zichan(double arg1)
{
    ui->statusBar->clearMessage();  //清除历史信息
    ConvertMoneyCaps(arg1);      //大写金额转换
    if(arg1 <= 2000)   //2000元起
    {
        fare = 0;
    }
    else if(arg1 <= 1000000)     //100万元以下的
    {
        fare = arg1 * 0.007;
    }
    else if(arg1 > 1000000 && arg1 <= 10000000)
    {
        fare = 7000 + (arg1 - 1000000) * 0.004;
    }
    else if(arg1 > 10000000 && arg1 <= 50000000)
    {
        fare = 7000 + 36000 + (arg1 - 10000000) * 0.0012;
    }
    else if(arg1 > 50000000 && arg1 <= 100000000)
    {
        fare = 7000 + 36000 + 48000 + (arg1 - 50000000) * 0.0008;
    }
    else if(arg1 > 100000000 && arg1 <= 1000000000)
    {
        fare = 7000 + 36000 + 48000 + 40000 + (arg1 - 100000000) * 0.00015;
    }
    else if(arg1 > 1000000000)
    {
        fare = 7000 + 36000 + 48000 + 40000 + 135000 + (arg1 - 1000000000) * 0.0001;
    }

    if(ui->comboBox_2->currentIndex()==1)  // 使用万元单位
        fare /= 10000;
    // 费用文本框显示费用
    ui->lineEdit_fare->setText(QString::number(fare, 10, 2));
    ui->label_money->setText(moneyQstr);
}

// 计算房地产价格评估服务收费函数
void MainWin::calculate_fangdichan(double arg2)
{
    ui->statusBar->clearMessage();  //清除历史信息
    ConvertMoneyCaps(arg2);      //大写金额转换
    if(arg2 <= 1000000)     //100万元以下的
    {
        fare = arg2 * 0.005;
    }
    else if(arg2 > 1000000 && arg2 <= 10000000)
    {
        fare = 5000 + (arg2 - 1000000) * 0.0025;
    }
    else if(arg2 > 10000000 && arg2 <= 20000000)
    {
        fare = 27500 + (arg2 - 10000000) * 0.0015;
    }
    else if(arg2 > 20000000 && arg2 <= 50000000)
    {
        fare = 42500 + (arg2 - 50000000) * 0.0008;
    }
    else if(arg2 > 50000000 && arg2 <= 80000000)
    {
        fare = 66500 + (arg2 - 80000000) * 0.0004;
    }
    else if(arg2 > 80000000 && arg2 <= 100000000)
    {
        fare = 78500 + (arg2 - 80000000) * 0.0002;
    }
    else if(arg2 > 100000000)
    {
        fare = 82500 + (arg2 - 100000000) * 0.0001;
    }

    if(ui->comboBox_2->currentIndex()==1)  // 使用万元单位
        fare /= 10000;
    // 费用文本框显示费用
    ui->lineEdit_fare->setText(QString::number(fare, 10, 2));
    ui->label_money->setText(moneyQstr);
}


// 将数字金额转化为汉字
void MainWin::ConvertMoneyCaps(long double moneySum)
{
    long int temp_i = (long int)moneySum;  /**//* 整数部分 */
    float temp_f = moneySum - temp_i; /**//* 小数部分 */
    int digit = 0, i, j, k, num_i;
    QString money("");
    char num[20], *p;
    char name[][4] = {"元","拾","佰","仟","万","亿"};
    char numchar[][4] = {"零","壹","贰","叁","肆","伍","陆","柒","捌","玖"};
    ltoa(temp_i, num, 10);  /**//* 整数部分转换成字符串后在处理 */
    p = num;
    digit = strlen(num);            /**//* 整数部分位数 */
    /**//*--------处理整数部分 start--------*/
    for(i = 1; i <= digit; i ++)
    {
        k = (digit - i) % 4;
        if(isdigit(*p))
        {
            num_i = *p & 0xF; /* 把字符转换成数字,比如 '0'-> 0,'1' -> 1*/
            /**//*--------转换数字开始---------*/
            if(num_i)
            {
                money = money+ numchar[num_i];
            }
            else
            {
                if(k && (*(p + 1) &0xF))
                    money += "零";
            }
            /**//*--------转换数字结束-------*/
            /**//*---------添加计数单位开始----*/
            if(k)
            {
                if(num_i)
                money = money + name[k];
            }
            else
            {
                j = digit - i;
                if(j)
                    money = money + name[j/4 + 3];
                else
                {
                    if(ui->comboBox_2->currentIndex()==0)
                        money += "元";
                    else
                        money += "万元";
                }
            }
            /**//*--------添加计数单位结束--------*/
            p++;
        }
        else
        {
            money = "遇到非数字退出!";
            return;
        }
    }
    /**//*--------处理整数部分 End --------*/
    /**//*--------处理小数部分 start--------*/
    if(temp_f > 0.01)
    {
        if((int)(temp_f*10)) money = money + numchar[(int)(temp_f*10)] + "角";
        if((int)(temp_f*100)%10) money = money + numchar[(int)(temp_f*100)%10] + "分";
    }
    /**//*--------处理小数部分 End--------*/
    money += "整";
    moneyQstr = money;
}

// 清除，清理
void MainWin::on_actionClear_triggered()
{
    ui->doubleSpinBox_money->clear();
    ui->lineEdit_fare->clear();
    ui->label_money->setText("");
    ui->statusBar->clearMessage();
}

// 退出
void MainWin::on_actionExit_triggered()
{
    qApp->quit();
}

// 帮助
void MainWin::on_actionHelp_H_triggered()
{
    QString helpText("版权所有，严谨私自用于商业用途！\n");
    QMessageBox::about(this, tr("帮助"), helpText);
}

// 关于
void MainWin::on_actionAbout_B_triggered()
{
    QString aboutText("@name：山东辰林律师事务所用，多功能评估服务费用计算器。\n@author：刘宇昂（Frank Liu）\n@email: frankliu624@mail.com\n@time：2019-06-26\n@version：V0.9\n");
    QMessageBox::about(this, tr("关于多功能评估服务费用计算器"), aboutText);
}

void MainWin::on_comboBox_2_currentIndexChanged(int index)
{
    asset = ui->doubleSpinBox_money->value();
    on_doubleSpinBox_money_valueChanged(asset);
}

void MainWin::on_comboBox_1_currentIndexChanged(int index)
{
    asset = ui->doubleSpinBox_money->value();
    on_doubleSpinBox_money_valueChanged(asset);
}
