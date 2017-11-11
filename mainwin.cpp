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
    ui->statusBar->clearMessage();  //清除历史信息
    ConvertMoneyCaps(arg1);      //大写金额转换
    if(arg1 <= 10000)   //1万元以下的
    {
        if(isUpLimit)
            fare = 3000;
        else
            fare = 2500;
    }
    else if(arg1 > 10000 && arg1 <= 100000)
    {
        if(isUpLimit)
            fare = 3000 + (arg1 - 10000) * 0.09;
        else
            fare = 2500 + (arg1 - 10000) * 0.06;
    }
    else if(arg1 > 100000 && arg1 < 500000)
    {
        if(isUpLimit)
            fare = 3000 + 10000 * 0.09 + (arg1 - 100000) * 0.06;
        else
            fare = 3000 + 10000 * 0.06 + (arg1 - 100000) * 0.05;
    }
    else if(arg1 > 500000 && arg1 <= 1000000)
    {
        if(isUpLimit)
            fare = 3000 + 10000 * 0.09 + 400000 * 0.06 + (arg1 - 500000) * 0.05;
        else
            fare = 3000 + 10000 * 0.09 + 400000 * 0.05 + (arg1 - 500000) + arg1 * 0.04;
    }
    else if(arg1 > 1000000)
    {
        if(isUpLimit)
            fare = 3000 + 10000 * 0.09 + 400000 * 0.06 + 500000 * 0.05 + (arg1 - 1000000) * 0.04;
        else
            fare = 3000 + 10000 * 0.09 + 400000 * 0.06 + 500000 * 0.04 + (arg1 - 1000000) * 0.03;

        if(arg1 > 5000000)  //大于500万的部分由率诗书无所和委托人协商确定
        {
            ui->lineEdit_fare->setText(QString::number(fare, 10, 2) + tr("+"));
            ui->label_money->setText(moneyQstr);
            ui->statusBar->showMessage(tr("大于500万的部分由率诗书无所和委托人协商确定!"));
            //QMessageBox::warning(this, tr("注意"), tr("大于500万的部分由率诗书无所和委托人协商确定!"));
            return;
        }
    }

    // 律师费文本框显示费用
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
                    money += "元";
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
    ui->label_money->clear();
    ui->statusBar->clearMessage();
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
    QString helpText("版权所有，严谨私自用于商业用途！\n按下列比例分段累加计算律师费：\n1万元及以下收费2500-3000元；\n1万（不含）—10万元（含）部分收费比例为6%-9%；\n10万-50万元（含）部分为5%-6%；\n50万-100万元（含）部分为4%-5%；\n100万—500万元（含）部分为3%-4%;\n500万以上部分由律师事务所和委托人学号协商确定。\n");
    QMessageBox::about(this, tr("帮助"), helpText);
}

// 关于
void MainWin::on_actionAbout_B_triggered()
{
    QString aboutText("@name：山东辰林律师事务所用，律师费计算器。\n@author：刘宇昂 （Frank Liu）\n@time：2017-11-10\n@version：V2.0\n根据卢立清 1.0.0.1版本改编。");
    QMessageBox::about(this, tr("关于律师费计算器"), aboutText);
}
