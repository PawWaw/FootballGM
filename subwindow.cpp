#include "subwindow.h"
#include "ui_subwindow.h"

SubWindow::SubWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SubWindow)
{
    ui->setupUi(this);
}

void SubWindow::setVisibleGoalkeeper(bool vis)
{
    ui->GoalKeeperWidget->setVisible(vis);
}

void SubWindow::setVisibleDefender(bool vis)
{
    ui->DefendersWidget->setVisible(vis);
}

void SubWindow::setVisibleMidfielder(bool vis)
{
    ui->MidfieldersWidget->setVisible(vis);
}

void SubWindow::setVisibleAttacker(bool vis)
{
    ui->AttackersWidget->setVisible(vis);
}

SubWindow::~SubWindow()
{
    delete ui;
}

void SubWindow::on_Goalkeeper1_ChB_clicked() //nie dziala
{
    if(ui->Goalkeeper1_ChB->isChecked())
    {
        ui->OK->setEnabled(true);
    }
}
