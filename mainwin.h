#ifndef MAINWIN_H
#define MAINWIN_H

#include <QMainWindow>
#include <QMessageBox>
#include <QButtonGroup>

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
    void on_doubleSpinBox_money_valueChanged(double arg1);

    void on_rBtn_upLimit_toggled(bool checked);

    void on_rBtn_downLimit_clicked();

    void on_actionClear_triggered();

    void on_actionExit_triggered();

    void on_actionHelp_H_triggered();

    void on_actionAbout_B_triggered();

private:
    Ui::MainWin *ui;
    bool isUpLimit;
    double asset;  //财产
    double fare;   //律师费
    void calculate(double arg1);
};

#endif // MAINWIN_H
