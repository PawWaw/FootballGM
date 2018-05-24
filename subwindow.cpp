#include "subwindow.h"
#include "ui_subwindow.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "player.h"
#include "match.h"
#include "goalkeeper.h"
#include <QLCDNumber>
#include <QMessageBox>

SubWindow::SubWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SubWindow)
{
    ui->setupUi(this);
    SelectingTeam();
    ui->centralwidget->setStyleSheet("background:rgb(255,255,245)");
    ui->SelectTeamWidget->setStyleSheet("text-color:white");
    ui->SelectTeamWidget->setStyleSheet("background:rgb(254,254,200);");
    ui->ChosenTeam->setStyleSheet("background:rgb(254,254,200);");
    Match::players.clear();
}

void SubWindow::ChoosePlayer(float cost)
{
    money -= cost;
    ui->MoneyLeft->display(money);
    counter++;
    ui->PlayerCounter->display(counter);
    CheckboxCheck();
}

void SubWindow::RejectPlayer(float cost)
{
    money += cost;
    ui->MoneyLeft->display(money);
    counter--;
    ui->PlayerCounter->display(counter);
    CheckboxCheck();
}

void SubWindow::setOKUnclickable()
{
    ui->Ok->setEnabled(false);
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

void SubWindow::setColorGoalkeeper()
{
    ui->Goalkeepers->setStyleSheet("background:rgb(254,254,200);");
}

void SubWindow::setColorDefender()
{
    ui->DefendersWidget->setStyleSheet("background:rgb(56,0,60);");
}

void SubWindow::setColorMidfielder()
{
    ui->MidfieldersWidget->setStyleSheet("background:rgb(56,0,60);");
}

void SubWindow::setColorAttacker()
{
    ui->AttackersWidget->setStyleSheet("background:rgb(56,0,60);");
}

void SubWindow::setVisibleAttacker(bool vis)
{
    ui->AttackersWidget->setVisible(vis);
}

void SubWindow::setVisibleChosenTeam(bool vis)
{
    ui->ChosenTeam->setVisible(vis);
}

void SubWindow::setVisibleSimulateButton(bool vis)
{
    ui->Simulate->setVisible(vis);
}

SubWindow::~SubWindow()
{
    delete ui;
}

void SubWindow::CheckboxCheck()
{
    if (counter == 21){
        ui->Ok->setEnabled(true);
    }
    else {
        ui->Ok->setEnabled(false);
    }
}

void SubWindow::SelectingTeam()
{
    connect(ui->Goalkeeper1_ChB,SIGNAL(stateChanged(int)),this,SLOT(CheckboxCheck(int)));
    connect(ui->Goalkeeper2_ChB,SIGNAL(stateChanged(int)),this,SLOT(CheckboxCheck(int)));
    connect(ui->Goalkeeper3_ChB,SIGNAL(stateChanged(int)),this,SLOT(CheckboxCheck(int)));
    connect(ui->Goalkeeper4_ChB,SIGNAL(stateChanged(int)),this,SLOT(CheckboxCheck(int)));
    connect(ui->Goalkeeper5_ChB,SIGNAL(stateChanged(int)),this,SLOT(CheckboxCheck(int)));
    connect(ui->Goalkeeper6_ChB,SIGNAL(stateChanged(int)),this,SLOT(CheckboxCheck(int)));
    connect(ui->Goalkeeper7_ChB,SIGNAL(stateChanged(int)),this,SLOT(CheckboxCheck(int)));
    connect(ui->Goalkeeper8_ChB,SIGNAL(stateChanged(int)),this,SLOT(CheckboxCheck(int)));
    connect(ui->Goalkeeper9_ChB,SIGNAL(stateChanged(int)),this,SLOT(CheckboxCheck(int)));
    connect(ui->Goalkeeper10_ChB,SIGNAL(stateChanged(int)),this,SLOT(CheckboxCheck(int)));
    connect(ui->Goalkeeper11_ChB,SIGNAL(stateChanged(int)),this,SLOT(CheckboxCheck(int)));
    connect(ui->Goalkeeper12_ChB,SIGNAL(stateChanged(int)),this,SLOT(CheckboxCheck(int)));
    connect(ui->Goalkeeper13_ChB,SIGNAL(stateChanged(int)),this,SLOT(CheckboxCheck(int)));
    connect(ui->Goalkeeper14_ChB,SIGNAL(stateChanged(int)),this,SLOT(CheckboxCheck(int)));
    connect(ui->Goalkeeper15_ChB,SIGNAL(stateChanged(int)),this,SLOT(CheckboxCheck(int)));
    connect(ui->Defender1_ChB,SIGNAL(stateChanged(int)),this,SLOT(CheckboxCheck(int)));
    connect(ui->Defender2_ChB,SIGNAL(stateChanged(int)),this,SLOT(CheckboxCheck(int)));
    connect(ui->Defender3_ChB,SIGNAL(stateChanged(int)),this,SLOT(CheckboxCheck(int)));
    connect(ui->Defender4_ChB,SIGNAL(stateChanged(int)),this,SLOT(CheckboxCheck(int)));
    connect(ui->Defender5_ChB,SIGNAL(stateChanged(int)),this,SLOT(CheckboxCheck(int)));
    connect(ui->Defender6_ChB,SIGNAL(stateChanged(int)),this,SLOT(CheckboxCheck(int)));
    connect(ui->Defender7_ChB,SIGNAL(stateChanged(int)),this,SLOT(CheckboxCheck(int)));
    connect(ui->Defender8_ChB,SIGNAL(stateChanged(int)),this,SLOT(CheckboxCheck(int)));
    connect(ui->Defender9_ChB,SIGNAL(stateChanged(int)),this,SLOT(CheckboxCheck(int)));
    connect(ui->Defender10_ChB,SIGNAL(stateChanged(int)),this,SLOT(CheckboxCheck(int)));
    connect(ui->Defender11_ChB,SIGNAL(stateChanged(int)),this,SLOT(CheckboxCheck(int)));
    connect(ui->Defender12_ChB,SIGNAL(stateChanged(int)),this,SLOT(CheckboxCheck(int)));
    connect(ui->Defender13_ChB,SIGNAL(stateChanged(int)),this,SLOT(CheckboxCheck(int)));
    connect(ui->Defender14_ChB,SIGNAL(stateChanged(int)),this,SLOT(CheckboxCheck(int)));
    connect(ui->Defender15_ChB,SIGNAL(stateChanged(int)),this,SLOT(CheckboxCheck(int)));
    connect(ui->Midfielder1_ChB,SIGNAL(stateChanged(int)),this,SLOT(CheckboxCheck(int)));
    connect(ui->Midfielder2_ChB,SIGNAL(stateChanged(int)),this,SLOT(CheckboxCheck(int)));
    connect(ui->Midfielder3_ChB,SIGNAL(stateChanged(int)),this,SLOT(CheckboxCheck(int)));
    connect(ui->Midfielder4_ChB,SIGNAL(stateChanged(int)),this,SLOT(CheckboxCheck(int)));
    connect(ui->Midfielder5_ChB,SIGNAL(stateChanged(int)),this,SLOT(CheckboxCheck(int)));
    connect(ui->Midfielder6_ChB,SIGNAL(stateChanged(int)),this,SLOT(CheckboxCheck(int)));
    connect(ui->Midfielder7_ChB,SIGNAL(stateChanged(int)),this,SLOT(CheckboxCheck(int)));
    connect(ui->Midfielder8_ChB,SIGNAL(stateChanged(int)),this,SLOT(CheckboxCheck(int)));
    connect(ui->Midfielder9_ChB,SIGNAL(stateChanged(int)),this,SLOT(CheckboxCheck(int)));
    connect(ui->Midfielder10_ChB,SIGNAL(stateChanged(int)),this,SLOT(CheckboxCheck(int)));
    connect(ui->Midfielder11_ChB,SIGNAL(stateChanged(int)),this,SLOT(CheckboxCheck(int)));
    connect(ui->Midfielder12_ChB,SIGNAL(stateChanged(int)),this,SLOT(CheckboxCheck(int)));
    connect(ui->Midfielder13_ChB,SIGNAL(stateChanged(int)),this,SLOT(CheckboxCheck(int)));
    connect(ui->Midfielder14_ChB,SIGNAL(stateChanged(int)),this,SLOT(CheckboxCheck(int)));
    connect(ui->Midfielder15_ChB,SIGNAL(stateChanged(int)),this,SLOT(CheckboxCheck(int)));
    connect(ui->Attacker1_ChB,SIGNAL(stateChanged(int)),this,SLOT(CheckboxCheck(int)));
    connect(ui->Attacker2_ChB,SIGNAL(stateChanged(int)),this,SLOT(CheckboxCheck(int)));
    connect(ui->Attacker3_ChB,SIGNAL(stateChanged(int)),this,SLOT(CheckboxCheck(int)));
    connect(ui->Attacker4_ChB,SIGNAL(stateChanged(int)),this,SLOT(CheckboxCheck(int)));
    connect(ui->Attacker5_ChB,SIGNAL(stateChanged(int)),this,SLOT(CheckboxCheck(int)));
    connect(ui->Attacker6_ChB,SIGNAL(stateChanged(int)),this,SLOT(CheckboxCheck(int)));
    connect(ui->Attacker7_ChB,SIGNAL(stateChanged(int)),this,SLOT(CheckboxCheck(int)));
    connect(ui->Attacker8_ChB,SIGNAL(stateChanged(int)),this,SLOT(CheckboxCheck(int)));
    connect(ui->Attacker9_ChB,SIGNAL(stateChanged(int)),this,SLOT(CheckboxCheck(int)));
    connect(ui->Attacker10_ChB,SIGNAL(stateChanged(int)),this,SLOT(CheckboxCheck(int)));
    connect(ui->Attacker11_ChB,SIGNAL(stateChanged(int)),this,SLOT(CheckboxCheck(int)));
    connect(ui->Attacker12_ChB,SIGNAL(stateChanged(int)),this,SLOT(CheckboxCheck(int)));
    connect(ui->Attacker13_ChB,SIGNAL(stateChanged(int)),this,SLOT(CheckboxCheck(int)));
    connect(ui->Attacker14_ChB,SIGNAL(stateChanged(int)),this,SLOT(CheckboxCheck(int)));
    connect(ui->Attacker15_ChB,SIGNAL(stateChanged(int)),this,SLOT(CheckboxCheck(int)));
}

void SubWindow::on_Goalkeeper1_ChB_stateChanged(int arg1)
{
    if (ui->Goalkeeper1_ChB->isChecked())
    {
       ChoosePlayer(31.2);
       return;
    }
    else
    {
        RejectPlayer(31.2);
        return;
    }
}

void SubWindow::on_Goalkeeper2_ChB_stateChanged(int arg1)
{
    if (ui->Goalkeeper2_ChB->isChecked())
    {
        ChoosePlayer(28.3);
        return;
    }
    else
    {
        RejectPlayer(28.3);
        return;
    }
}

void SubWindow::on_Goalkeeper3_ChB_stateChanged(int arg1)
{
    if (ui->Goalkeeper3_ChB->isChecked())
    {
        ChoosePlayer(24.8);
        return;
    }
    else
    {
        RejectPlayer(24.8);
        return;
    }
}

void SubWindow::on_Goalkeeper4_ChB_stateChanged(int arg1)
{
    if (ui->Goalkeeper4_ChB->isChecked())
    {
        ChoosePlayer(20.2);
        return;
    }
    else
    {
        RejectPlayer(20.2);
        return;
    }
}

void SubWindow::on_Goalkeeper5_ChB_stateChanged(int arg1)
{
    if (ui->Goalkeeper5_ChB->isChecked())
    {
        ChoosePlayer(22.7);
        return;
    }
    else
    {
        RejectPlayer(22.7);
        return;
    }
}

void SubWindow::on_Goalkeeper6_ChB_stateChanged(int arg1)
{
    if (ui->Goalkeeper6_ChB->isChecked())
        {
            ChoosePlayer(24.2);
            return;
        }
        else
        {
            RejectPlayer(24.2);
            return;
        }
}

void SubWindow::on_Goalkeeper7_ChB_stateChanged(int arg1)
{
    if (ui->Goalkeeper7_ChB->isChecked())
        {
            ChoosePlayer(22.0);
            return;
        }
        else
        {
            RejectPlayer(22.0);
            return;
        }
}

void SubWindow::on_Goalkeeper8_ChB_stateChanged(int arg1)
{
    if (ui->Goalkeeper8_ChB->isChecked())
        {
            ChoosePlayer(27.3);
            return;
        }
        else
        {
            RejectPlayer(27.3);
            return;
        }
}

void SubWindow::on_Goalkeeper9_ChB_stateChanged(int arg1)
{
    if (ui->Goalkeeper9_ChB->isChecked())
        {
            ChoosePlayer(26.7);
            return;
        }
        else
        {
            RejectPlayer(26.7);
            return;
        }
}

void SubWindow::on_Goalkeeper10_ChB_stateChanged(int arg1)
{
    if (ui->Goalkeeper10_ChB->isChecked())
        {
            ChoosePlayer(23.8);
            return;
        }
        else
        {
            RejectPlayer(23.8);
            return;
        }
}

void SubWindow::on_Goalkeeper11_ChB_stateChanged(int arg1)
{
    if (ui->Goalkeeper11_ChB->isChecked())
        {
            ChoosePlayer(22.8);
            return;
        }
        else
        {
            RejectPlayer(22.8);
            return;
        }
}

void SubWindow::on_Goalkeeper12_ChB_stateChanged(int arg1)
{
    if (ui->Goalkeeper12_ChB->isChecked())
        {
            ChoosePlayer(24.8);
            return;
        }
        else
        {
            RejectPlayer(24.8);
            return;
        }
}

void SubWindow::on_Goalkeeper13_ChB_stateChanged(int arg1)
{
    if (ui->Goalkeeper13_ChB->isChecked())
        {
            ChoosePlayer(23.2);
            return;
        }
        else
        {
            RejectPlayer(23.2);
            return;
        }
}

void SubWindow::on_Goalkeeper14_ChB_stateChanged(int arg1)
{
    if (ui->Goalkeeper14_ChB->isChecked())
        {
            ChoosePlayer(25.2);
            return;
        }
        else
        {
            RejectPlayer(25.2);
            return;
        }
}

void SubWindow::on_Goalkeeper15_ChB_stateChanged(int arg1)
{
    if (ui->Goalkeeper15_ChB->isChecked())
        {
            ChoosePlayer(22.2);
            return;
        }
        else
        {
            RejectPlayer(22.2);
            return;
        }
}

void SubWindow::on_Defender1_ChB_stateChanged(int arg1)
{
    if (ui->Defender1_ChB->isChecked())
        {
            ChoosePlayer(36.4);
            return;
        }
        else
        {
            RejectPlayer(36.4);
            return;
        }
}

void SubWindow::on_Defender2_ChB_stateChanged(int arg1)
{
    if (ui->Defender2_ChB->isChecked())
        {
            ChoosePlayer(32.3);
            return;
        }
        else
        {
            RejectPlayer(32.3);
            return;
        }
}

void SubWindow::on_Defender3_ChB_stateChanged(int arg1)
{
    if (ui->Defender3_ChB->isChecked())
        {
            ChoosePlayer(36.2);
            return;
        }
        else
        {
            RejectPlayer(36.2);
            return;
        }
}

void SubWindow::on_Defender4_ChB_stateChanged(int arg1)
{
    if (ui->Defender4_ChB->isChecked())
        {
            ChoosePlayer(30.3);
            return;
        }
        else
        {
            RejectPlayer(30.3);
            return;
        }
}

void SubWindow::on_Defender5_ChB_stateChanged(int arg1)
{
    if (ui->Defender5_ChB->isChecked())
        {
            ChoosePlayer(29.3);
            return;
        }
        else
        {
            ChoosePlayer(29.3);
            return;
        }
}

void SubWindow::on_Defender6_ChB_stateChanged(int arg1)
{
    if (ui->Defender6_ChB->isChecked())
        {
            ChoosePlayer(25.8);
            return;
        }
        else
        {
            RejectPlayer(25.8);
            return;
        }
}

void SubWindow::on_Defender7_ChB_stateChanged(int arg1)
{
    if (ui->Defender7_ChB->isChecked())
        {
            ChoosePlayer(22.8);
            return;
        }
        else
        {
            RejectPlayer(22.8);
            return;
        }
}

void SubWindow::on_Defender8_ChB_stateChanged(int arg1)
{
    if (ui->Defender8_ChB->isChecked())
        {
            ChoosePlayer(20.8);
            return;
        }
        else
        {
            ChoosePlayer(20.8);
            return;
        }
}

void SubWindow::on_Defender9_ChB_stateChanged(int arg1)
{
    if (ui->Defender9_ChB->isChecked())
        {
            ChoosePlayer(22.4);
            return;
        }
        else
        {
            RejectPlayer(22.4);
            return;
        }
}

void SubWindow::on_Defender10_ChB_stateChanged(int arg1)
{
    if (ui->Defender10_ChB->isChecked())
        {
            ChoosePlayer(23.8);
            return;
        }
        else
        {
            RejectPlayer(23.8);
            return;
        }
}

void SubWindow::on_Defender11_ChB_stateChanged(int arg1)
{
    if (ui->Defender11_ChB->isChecked())
        {
            ChoosePlayer(22.8);
            return;
        }
        else
        {
            RejectPlayer(22.8);
            return;
        }
}

void SubWindow::on_Defender12_ChB_stateChanged(int arg1)
{
    if (ui->Defender12_ChB->isChecked())
        {
            ChoosePlayer(29.8);
            return;
        }
        else
        {
            RejectPlayer(29.8);
            return;
        }
}

void SubWindow::on_Defender13_ChB_stateChanged(int arg1)
{
    if (ui->Defender13_ChB->isChecked())
        {
            ChoosePlayer(25.8);
            return;
        }
        else
        {
            RejectPlayer(25.8);
            return;
        }
}

void SubWindow::on_Defender14_ChB_stateChanged(int arg1)
{
    if (ui->Defender14_ChB->isChecked())
        {
            ChoosePlayer(19.7);
            return;
        }
        else
        {
            RejectPlayer(19.7);
            return;
        }
}

void SubWindow::on_Defender15_ChB_stateChanged(int arg1)
{
    if (ui->Defender15_ChB->isChecked())
        {
            ChoosePlayer(20.8);
            return;
        }
        else
        {
            RejectPlayer(20.8);
            return;
        }
}

void SubWindow::on_Midfielder1_ChB_stateChanged(int arg1)
{
    if (ui->Midfielder1_ChB->isChecked())
        {
            ChoosePlayer(54.0);
            return;
        }
        else
        {
            RejectPlayer(54.0);
            return;
        }
}

void SubWindow::on_Midfielder2_ChB_stateChanged(int arg1)
{
    if (ui->Midfielder2_ChB->isChecked())
        {
            ChoosePlayer(43.4);
            return;
        }
        else
        {
            RejectPlayer(43.4);
            return;
        }
}

void SubWindow::on_Midfielder3_ChB_stateChanged(int arg1)
{
    if (ui->Midfielder3_ChB->isChecked())
        {
            ChoosePlayer(44.4);
            return;
        }
        else
        {
            RejectPlayer(44.4);
            return;
        }
}

void SubWindow::on_Midfielder4_ChB_stateChanged(int arg1)
{
    if (ui->Midfielder4_ChB->isChecked())
        {
            ChoosePlayer(41.4);
            return;
        }
        else
        {
            RejectPlayer(41.4);
            return;
        }
}

void SubWindow::on_Midfielder5_ChB_stateChanged(int arg1)
{
    if (ui->Midfielder5_ChB->isChecked())
        {
            ChoosePlayer(30.3);
            return;
        }
        else
        {
            RejectPlayer(30.3);
            return;
        }
}

void SubWindow::on_Midfielder6_ChB_stateChanged(int arg1)
{
    if (ui->Midfielder6_ChB->isChecked())
        {
            ChoosePlayer(27.8);
            return;
        }
        else
        {
            RejectPlayer(27.8);
            return;
        }
}

void SubWindow::on_Midfielder7_ChB_stateChanged(int arg1)
{
    if (ui->Midfielder7_ChB->isChecked())
        {
            ChoosePlayer(30.6);
            return;
        }
        else
        {
            RejectPlayer(30.6);
            return;
        }
}

void SubWindow::on_Midfielder8_ChB_stateChanged(int arg1)
{
    if (ui->Midfielder8_ChB->isChecked())
        {
            ChoosePlayer(38.9);
            return;
        }
        else
        {
            RejectPlayer(38.9);
            return;
        }
}

void SubWindow::on_Midfielder9_ChB_stateChanged(int arg1)
{
    if (ui->Midfielder9_ChB->isChecked())
        {
            ChoosePlayer(53.5);
            return;
        }
        else
        {
            RejectPlayer(53.5);
            return;
        }
}

void SubWindow::on_Midfielder10_ChB_stateChanged(int arg1)
{
    if (ui->Midfielder10_ChB->isChecked())
        {
            ChoosePlayer(26.8);
            return;
        }
        else
        {
            RejectPlayer(26.8);
            return;
        }
}

void SubWindow::on_Midfielder11_ChB_stateChanged(int arg1)
{
    if (ui->Midfielder11_ChB->isChecked())
        {
            ChoosePlayer(25.5);
            return;
        }
        else
        {
            RejectPlayer(25.5);
            return;
        }
}

void SubWindow::on_Midfielder12_ChB_stateChanged(int arg1)
{
    if (ui->Midfielder12_ChB->isChecked())
        {
            ChoosePlayer(39.3);
            return;
        }
        else
        {
            RejectPlayer(39.3);
            return;
        }
}

void SubWindow::on_Midfielder13_ChB_stateChanged(int arg1)
{
    if (ui->Midfielder13_ChB->isChecked())
        {
            ChoosePlayer(27.1);
            return;
        }
        else
        {
            RejectPlayer(27.1);
            return;
        }
}

void SubWindow::on_Midfielder14_ChB_stateChanged(int arg1)
{
    if (ui->Midfielder14_ChB->isChecked())
        {
            ChoosePlayer(27.6);
            return;
        }
        else
        {
            RejectPlayer(27.6);
            return;
        }
}

void SubWindow::on_Midfielder15_ChB_stateChanged(int arg1)
{
    if (ui->Midfielder15_ChB->isChecked())
        {
            ChoosePlayer(32.3);
            return;
        }
        else
        {
            RejectPlayer(32.3);
            return;
        }
}

void SubWindow::on_Attacker1_ChB_stateChanged(int arg1)
{
    if (ui->Attacker1_ChB->isChecked())
        {
            ChoosePlayer(64.1);
            return;
        }
        else
        {
            RejectPlayer(64.1);
            return;
        }
}

void SubWindow::on_Attacker2_ChB_stateChanged(int arg1)
{
    if (ui->Attacker2_ChB->isChecked())
        {
            ChoosePlayer(59.6);
            return;
        }
        else
        {
            RejectPlayer(59.6);
            return;
        }
}

void SubWindow::on_Attacker3_ChB_stateChanged(int arg1)
{
    if (ui->Attacker3_ChB->isChecked())
        {
            ChoosePlayer(49.0);
            return;
        }
        else
        {
            RejectPlayer(49.0);
            return;
        }
}

void SubWindow::on_Attacker4_ChB_stateChanged(int arg1)
{
    if (ui->Attacker4_ChB->isChecked())
        {
            ChoosePlayer(57.6);
            return;
        }
        else
        {
            RejectPlayer(57.6);
            return;
        }
}

void SubWindow::on_Attacker5_ChB_stateChanged(int arg1)
{
    if (ui->Attacker5_ChB->isChecked())
        {
            ChoosePlayer(44.0);
            return;
        }
        else
        {
            RejectPlayer(44.0);
            return;
        }
}

void SubWindow::on_Attacker6_ChB_stateChanged(int arg1)
{
    if (ui->Attacker6_ChB->isChecked())
        {
            ChoosePlayer(36.4);
            return;
        }
        else
        {
            RejectPlayer(36.4);
            return;
        }
}

void SubWindow::on_Attacker7_ChB_stateChanged(int arg1)
{
    if (ui->Attacker7_ChB->isChecked())
        {
            ChoosePlayer(52.5);
            return;
        }
        else
        {
            RejectPlayer(52.5);
            return;
        }
}

void SubWindow::on_Attacker8_ChB_stateChanged(int arg1)
{
    if (ui->Attacker8_ChB->isChecked())
        {
            ChoosePlayer(51.5);
            return;
        }
        else
        {
            RejectPlayer(51.5);
            return;
        }
}

void SubWindow::on_Attacker9_ChB_stateChanged(int arg1)
{
    if (ui->Attacker9_ChB->isChecked())
        {
            ChoosePlayer(30.3);
            return;
        }
        else
        {
            RejectPlayer(30.3);
            return;
        }
}

void SubWindow::on_Attacker10_ChB_stateChanged(int arg1)
{
    if (ui->Attacker10_ChB->isChecked())
        {
            ChoosePlayer(26.7);
            return;
        }
        else
        {
            RejectPlayer(26.7);
            return;
        }
}

void SubWindow::on_Attacker11_ChB_stateChanged(int arg1)
{
    if (ui->Attacker11_ChB->isChecked())
        {
            ChoosePlayer(29.8);
            return;
        }
        else
        {
            RejectPlayer(29.8);
            return;
        }
}

void SubWindow::on_Attacker12_ChB_stateChanged(int arg1)
{
    if (ui->Attacker12_ChB->isChecked())
        {
            ChoosePlayer(33.8);
            return;
        }
        else
        {
            RejectPlayer(33.8);
            return;
        }
}

void SubWindow::on_Attacker13_ChB_stateChanged(int arg1)
{
    if (ui->Attacker13_ChB->isChecked())
        {
            ChoosePlayer(29.4);
            return;
        }
        else
        {
            RejectPlayer(29.4);
            return;
        }
}

void SubWindow::on_Attacker14_ChB_stateChanged(int arg1)
{
    if (ui->Attacker14_ChB->isChecked())
        {
            ChoosePlayer(53.5);
            return;
        }
        else
        {
            RejectPlayer(53.5);
            return;
        }
}

void SubWindow::on_Attacker15_ChB_stateChanged(int arg1)
{
    if (ui->Attacker15_ChB->isChecked())
        {
            ChoosePlayer(33.4);
            return;
        }
        else
        {
            RejectPlayer(33.4);
            return;
        }
}

void SubWindow::on_Ok_clicked()
{
    if (money < 0){
        QMessageBox::information(this, "Error", "The limit has been exceeded");
    }
    else{
        ui->SelectTeamWidget->setVisible(false);
        ui->MoneyLeft->setVisible(false);
        ui->label_3->setVisible(false);
        ui->label_4->setVisible(false);
        ui->PlayerCounter->setVisible(false);
        ui->ChosenTeam->setVisible(true);
        ui->Simulate->setVisible(true);
        if (ui->Goalkeeper1_ChB->isChecked())
        {
            Player p = {0, 0, 0, 0, 0, 0, 0, 0, 0, "Goalkeeper", "David De Gea", 1.9, 28, "Spain"};
            //Match::players.push_back(p);
        }
        if (ui->Goalkeeper2_ChB->isChecked())
        {
            //Player p = {0, 0, 0, 0, 0, 0, 0, 0, 0, "Ederson"};
            //Match::players.push_back(p);
        }
        if (ui->Goalkeeper3_ChB->isChecked())
        {
            //Player p = {0, 0, 0, 0, 0, 0, 0, 0, 0, "Nick Pope"};
            //Match::players.push_back(p);
        }
        if (ui->Goalkeeper4_ChB->isChecked())
        {
            //Player p = {0, 0, 0, 0, 0, 0, 0, 0, 0, "Rob Elliot"};
            //Match::players.push_back(p);
        }
        if (ui->Goalkeeper5_ChB->isChecked())
        {
            //Player p = {0, 0, 0, 0, 0, 0, 0, 0, 0, "Asmir Begović"};
            //Match::players.push_back(p);
        }
        if (ui->Goalkeeper6_ChB->isChecked())
        {
            //Player p = {0, 0, 0, 0, 0, 0, 0, 0, 0, "Loris Karius"};
            //Match::players.push_back(p);
        }
        if (ui->Goalkeeper7_ChB->isChecked())
        {
            //Player p = {0, 0, 0, 0, 0, 0, 0, 0, 0, "Martin Dubravka"};
            //Match::players.push_back(p);
        }
        if (ui->Goalkeeper8_ChB->isChecked())
        {
            //Player p = {0, 0, 0, 0, 0, 0, 0, 0, 0, "Thibaut Courtois"};
            //Match::players.push_back(p);
        }
        if (ui->Goalkeeper9_ChB->isChecked())
        {
            //Player p = {0, 0, 0, 0, 0, 0, 0, 0, 0, "Petr Cech"};
            //Match::players.push_back(p);
        }
        if (ui->Goalkeeper10_ChB->isChecked())
        {
            //Player p = {0, 0, 0, 0, 0, 0, 0, 0, 0, "Lukasz Fabianski"};
            //Match::players.push_back(p);
        }
        if (ui->Goalkeeper11_ChB->isChecked())
        {
            //Player p = {0, 0, 0, 0, 0, 0, 0, 0, 0, "Matthew Ryan"};
            //Match::players.push_back(p);
        }
        if (ui->Goalkeeper12_ChB->isChecked())
        {
            //Player p = {0, 0, 0, 0, 0, 0, 0, 0, 0, "Jordan Pickford"};
            //Match::players.push_back(p);
        }
        if (ui->Goalkeeper13_ChB->isChecked())
        {
            //Player p = {0, 0, 0, 0, 0, 0, 0, 0, 0, "Jonas Lossl"};
            //Match::players.push_back(p);
        }
        if (ui->Goalkeeper14_ChB->isChecked())
        {
            //Player p = {0, 0, 0, 0, 0, 0, 0, 0, 0, "Jack Butland"};
            //Match::players.push_back(p);
        }
        if (ui->Goalkeeper15_ChB->isChecked())
        {
            //Player p = {0, 0, 0, 0, 0, 0, 0, 0, 0, "Heurelho Gomes"};
            //Match::players.push_back(p);
        }
        if (ui->Defender1_ChB->isChecked())
        {
            //Player p = {0, 0, 0, 0, 0, 0, 0, 0, 0, "Cesar Azpilicueta"};
            //Match::players.push_back(p);
        }
        if (ui->Defender2_ChB->isChecked())
        {
            //Player p = {0, 0, 0, 0, 0, 0, 0, 0, 0, "Nicolas Otamendi"};
            //Match::players.push_back(p);
        }
        if (ui->Defender3_ChB->isChecked())
        {
            //Player p = {0, 0, 0, 0, 0, 0, 0, 0, 0, "Antonio Valencia"};
            //Match::players.push_back(p);
        }
        if (ui->Defender4_ChB->isChecked())
        {
            //Player p = {0, 0, 0, 0, 0, 0, 0, 0, 0, "Jan Vertonghen"};
            //Match::players.push_back(p);
        }
        if (ui->Defender5_ChB->isChecked())
        {
            //Player p = {0, 0, 0, 0, 0, 0, 0, 0, 0, "Sead Kolasinac"};
            //Match::players.push_back(p);
        }
        if (ui->Defender6_ChB->isChecked())
        {
            //Player p = {0, 0, 0, 0, 0, 0, 0, 0, 0, "Nathan Ake"};
            //Match::players.push_back(p);
        }
        if (ui->Defender7_ChB->isChecked())
        {
            //Player p = {0, 0, 0, 0, 0, 0, 0, 0, 0, "James Tarkowski"};
            //Match::players.push_back(p);
        }
        if (ui->Defender8_ChB->isChecked())
        {
            //Player p = {0, 0, 0, 0, 0, 0, 0, 0, 0, "Ragnar Klavan"};
            //Match::players.push_back(p);
        }
        if (ui->Defender9_ChB->isChecked())
        {
            //Player p = {0, 0, 0, 0, 0, 0, 0, 0, 0, "Cuco Martina"};
            //Match::players.push_back(p);
        }
        if (ui->Defender10_ChB->isChecked())
        {
            //Player p = {0, 0, 0, 0, 0, 0, 0, 0, 0, "Jamaal Lascelles"};
            //Match::players.push_back(p);
        }
        if (ui->Defender11_ChB->isChecked())
        {
            //Player p = {0, 0, 0, 0, 0, 0, 0, 0, 0, "Mathias Jorgensen"};
            //Match::players.push_back(p);
        }
        if (ui->Defender12_ChB->isChecked())
        {
            //Player p = {0, 0, 0, 0, 0, 0, 0, 0, 0, "Hector Bellerin"};
            //Match::players.push_back(p);
        }
        if (ui->Defender13_ChB->isChecked())
        {
            //Player p = {0, 0, 0, 0, 0, 0, 0, 0, 0, "Alfie Mawson"};
            //Match::players.push_back(p);
        }
        if (ui->Defender14_ChB->isChecked())
        {
            //Player p = {0, 0, 0, 0, 0, 0, 0, 0, 0, "Brad Smith"};
            //Match::players.push_back(p);
        }
        if (ui->Defender15_ChB->isChecked())
        {
            //Player p = {0, 0, 0, 0, 0, 0, 0, 0, 0, "Marvin Zeegelaar"};
            //Match::players.push_back(p);
        }
        if (ui->Midfielder1_ChB->isChecked())
        {
            //Player p = {0, 0, 0, 0, 0, 0, 0, 0, 0, "Mohamed Salah"};
            //Match::players.push_back(p);
        }
        if (ui->Midfielder2_ChB->isChecked())
        {
            //Player p = {0, 0, 0, 0, 0, 0, 0, 0, 0, "Raheem Sterling"};
            //Match::players.push_back(p);
        }
        if (ui->Midfielder3_ChB->isChecked())
        {
            //Player p = {0, 0, 0, 0, 0, 0, 0, 0, 0, "Riyad Mahrez"};
            //Match::players.push_back(p);
        }
        if (ui->Midfielder4_ChB->isChecked())
        {
            //Player p = {0, 0, 0, 0, 0, 0, 0, 0, 0, "Heung Min Son"};
            //Match::players.push_back(p);
        }
        if (ui->Midfielder5_ChB->isChecked())
        {
            //Player p = {0, 0, 0, 0, 0, 0, 0, 0, 0, "Pascal Gross"};
            //Match::players.push_back(p);
        }
        if (ui->Midfielder6_ChB->isChecked())
        {
            //Player p = {0, 0, 0, 0, 0, 0, 0, 0, 0, "Abdoulaye Doucoure"};
            //Match::players.push_back(p);
        }
        if (ui->Midfielder7_ChB->isChecked())
        {
            //Player p = {0, 0, 0, 0, 0, 0, 0, 0, 0, "Jesse Lingard"};
            //Match::players.push_back(p);
        }
        if (ui->Midfielder8_ChB->isChecked())
        {
            //Player p = {0, 0, 0, 0, 0, 0, 0, 0, 0, "Henrikh Mkhitaryan"};
            //Match::players.push_back(p);
        }
        if (ui->Midfielder9_ChB->isChecked())
        {
            //Player p = {0, 0, 0, 0, 0, 0, 0, 0, 0, "Eden Hazard"};
            //Match::players.push_back(p);
        }
        if (ui->Midfielder10_ChB->isChecked())
        {
            //Player p = {0, 0, 0, 0, 0, 0, 0, 0, 0, "Aaron Mooy"};
            //Match::players.push_back(p);
        }
        if (ui->Midfielder11_ChB->isChecked())
        {
            //Player p = {0, 0, 0, 0, 0, 0, 0, 0, 0, "Joe Allen"};
            //Match::players.push_back(p);
        }
        if (ui->Midfielder12_ChB->isChecked())
        {
            //Player p = {0, 0, 0, 0, 0, 0, 0, 0, 0, "Paul Pogba"};
            //Match::players.push_back(p);
        }
        if (ui->Midfielder13_ChB->isChecked())
        {
            //Player p = {0, 0, 0, 0, 0, 0, 0, 0, 0, "Oriol Romeu"};
            //Match::players.push_back(p);
        }
        if (ui->Midfielder14_ChB->isChecked())
        {
            //Player p = {0, 0, 0, 0, 0, 0, 0, 0, 0, "Ilkay Gundogan"};
            //Match::players.push_back(p);
        }
        if (ui->Midfielder15_ChB->isChecked())
        {
            //Player p = {0, 0, 0, 0, 0, 0, 0, 0, 0, "Xherdan Shaqiri"};
            //Match::players.push_back(p);
        }
        if (ui->Attacker1_ChB->isChecked())
        {
            //Player p = {0, 0, 0, 0, 0, 0, 0, 0, 0, "Harry Kane"};
            //Match::players.push_back(p);
        }
        if (ui->Attacker2_ChB->isChecked())
        {
            //Player p = {0, 0, 0, 0, 0, 0, 0, 0, 0, "Sergio Aguero"};
            //Match::players.push_back(p);
        }
        if (ui->Attacker3_ChB->isChecked())
        {
            //Player p = {0, 0, 0, 0, 0, 0, 0, 0, 0, "Roberto Firmino"};
            //Match::players.push_back(p);
        }
        if (ui->Attacker4_ChB->isChecked())
        {
            //Player p = {0, 0, 0, 0, 0, 0, 0, 0, 0, "Romelu Lukaku"};
            //Match::players.push_back(p);
        }
        if (ui->Attacker5_ChB->isChecked())
        {
            //Player p = {0, 0, 0, 0, 0, 0, 0, 0, 0, "Jamie Vardy"};
            //Match::players.push_back(p);
        }
        if (ui->Attacker6_ChB->isChecked())
        {
            //Player p = {0, 0, 0, 0, 0, 0, 0, 0, 0, "Wayne Rooney"};
            //Match::players.push_back(p);
        }
        if (ui->Attacker7_ChB->isChecked())
        {
            //Player p = {0, 0, 0, 0, 0, 0, 0, 0, 0, "Alvaro Morata"};
            //Match::players.push_back(p);
        }
        if (ui->Attacker8_ChB->isChecked())
        {
            //Player p = {0, 0, 0, 0, 0, 0, 0, 0, 0, "Alexandre Lacazette"};
            //Match::players.push_back(p);
        }
        if (ui->Attacker9_ChB->isChecked())
        {
            //Player p = {0, 0, 0, 0, 0, 0, 0, 0, 0, "Callum Wilson"};
            //Match::players.push_back(p);
        }
        if (ui->Attacker10_ChB->isChecked())
        {
            //Player p = {0, 0, 0, 0, 0, 0, 0, 0, 0, "Jay Rodriguez"};
            //Match::players.push_back(p);
        }
        if (ui->Attacker11_ChB->isChecked())
        {
            //Player p = {0, 0, 0, 0, 0, 0, 0, 0, 0, "Glenn Murray"};
            //Match::players.push_back(p);
        }
        if (ui->Attacker12_ChB->isChecked())
        {
            //Player p = {0, 0, 0, 0, 0, 0, 0, 0, 0, "Chicharito"};
            //Match::players.push_back(p);
        }
        if (ui->Attacker13_ChB->isChecked())
        {
            //Player p = {0, 0, 0, 0, 0, 0, 0, 0, 0, "Steve Mounie"};
            //Match::players.push_back(p);
        }
        if (ui->Attacker14_ChB->isChecked())
        {
            //Player p = {0, 0, 0, 0, 0, 0, 0, 0, 0, "P. E. Aubameyang"};
            //Match::players.push_back(p);
        }
        if (ui->Attacker15_ChB->isChecked())
        {
            //Player p = {0, 0, 0, 0, 0, 0, 0, 0, 0, "Islam Slimani"};
            //Match::players.push_back(p);
        }

    }
     //Player k;
     //k = Match::players.back();
     //ui->ChosenTeam1->setText(k.position);
     //Match::players.pop_back();
     /*
     k = Match::players.back();
     ui->ChosenTeam2->setText(k.position);
     Match::players.pop_back();
     k = Match::players.back();
     ui->ChosenTeam3->setText(k.position);
     Match::players.pop_back();
     k = Match::players.back();
     ui->ChosenTeam4->setText(k.position);
     Match::players.pop_back();
     k = Match::players.back();
     ui->ChosenTeam5->setText(k.position);
     Match::players.pop_back();
     k = Match::players.back();
     ui->ChosenTeam6->setText(k.position);
     Match::players.pop_back();
     k = Match::players.back();
     ui->ChosenTeam7->setText(k.position);
     Match::players.pop_back();
     k = Match::players.back();
     ui->ChosenTeam8->setText(k.position);
     Match::players.pop_back();
     k = Match::players.back();
     ui->ChosenTeam9->setText(k.position);
     Match::players.pop_back();
     k = Match::players.back();
     ui->ChosenTeam10->setText(k.position);
     Match::players.pop_back();
     k = Match::players.back();
     ui->ChosenTeam11->setText(k.position);
     Match::players.pop_back();
     k = Match::players.back();
     ui->ChosenTeam12->setText(k.position);
     Match::players.pop_back();
     k = Match::players.back();
     ui->ChosenTeam13->setText(k.position);
     Match::players.pop_back();
     k = Match::players.back();
     ui->ChosenTeam14->setText(k.position);
     Match::players.pop_back();
     k = Match::players.back();
     ui->ChosenTeam15->setText(k.position);
     Match::players.pop_back();
     k = Match::players.back();
     ui->ChosenTeam16->setText(k.position);
     Match::players.pop_back();
     k = Match::players.back();
     ui->ChosenTeam17->setText(k.position);
     Match::players.pop_back();
     k = Match::players.back();
     ui->ChosenTeam18->setText(k.position);
     Match::players.pop_back();
     k = Match::players.back();
     ui->ChosenTeam19->setText(k.position);
     Match::players.pop_back();
     k = Match::players.back();
     ui->ChosenTeam20->setText(k.position);
     Match::players.pop_back();
     k = Match::players.back();
     ui->ChosenTeam21->setText(k.position);
     Match::players.pop_back();
     */

}

void SubWindow::on_Cancel_clicked()
{
    this->close(); 
}

void SubWindow::on_Prev_clicked()
{
    if (ui->SelectTeamWidget->isHidden())
    {
        ui->SelectTeamWidget->setVisible(true);
        ui->MoneyLeft->setVisible(true);
        ui->label_3->setVisible(true);
        ui->label_4->setVisible(true);
        ui->PlayerCounter->setVisible(true);
        ui->ChosenTeam->setVisible(false);
        ui->Simulate->setVisible(false);
    }
    else
        this->close();
}

void SubWindow::on_ChosenTeam1_stateChanged(int arg1)
{
    if (ui->ChosenTeam1->isChecked())
    {
        counter2++;
        ui->ChosenCounter->display(counter2);
        return;
    }
    else
    {
        counter2--;
        ui->ChosenCounter->display(counter2);
        return;
    }
}

void SubWindow::on_ChosenTeam2_stateChanged(int arg1)
{
    if (ui->ChosenTeam2->isChecked())
    {
        counter2++;
        ui->ChosenCounter->display(counter2);
        return;
    }
    else
    {
        counter2--;
        ui->ChosenCounter->display(counter2);
        return;
    }
}

void SubWindow::on_ChosenTeam3_stateChanged(int arg1)
{
    if (ui->ChosenTeam3->isChecked())
    {
        counter2++;
        ui->ChosenCounter->display(counter2);
        return;
    }
    else
    {
        counter2--;
        ui->ChosenCounter->display(counter2);
        return;
    }
}

void SubWindow::on_ChosenTeam4_stateChanged(int arg1)
{
    if (ui->ChosenTeam4->isChecked())
    {
        counter2++;
        ui->ChosenCounter->display(counter2);
        return;
    }
    else
    {
        counter2--;
        ui->ChosenCounter->display(counter2);
        return;
    }
}

void SubWindow::on_ChosenTeam5_stateChanged(int arg1)
{
    if (ui->ChosenTeam5->isChecked())
    {
        counter2++;
        ui->ChosenCounter->display(counter2);
        return;
    }
    else
    {
        counter2--;
        ui->ChosenCounter->display(counter2);
        return;
    }
}

void SubWindow::on_ChosenTeam6_stateChanged(int arg1)
{
    if (ui->ChosenTeam6->isChecked())
    {
        counter2++;
        ui->ChosenCounter->display(counter2);
        return;
    }
    else
    {
        counter2--;
        ui->ChosenCounter->display(counter2);
        return;
    }
}

void SubWindow::on_ChosenTeam7_stateChanged(int arg1)
{
    if (ui->ChosenTeam7->isChecked())
    {
        counter2++;
        ui->ChosenCounter->display(counter2);
        return;
    }
    else
    {
        counter2--;
        ui->ChosenCounter->display(counter2);
        return;
    }
}

void SubWindow::on_ChosenTeam8_stateChanged(int arg1)
{
    if (ui->ChosenTeam8->isChecked())
    {
        counter2++;
        ui->ChosenCounter->display(counter2);
        return;
    }
    else
    {
        counter2--;
        ui->ChosenCounter->display(counter2);
        return;
    }
}

void SubWindow::on_ChosenTeam9_stateChanged(int arg1)
{
    if (ui->ChosenTeam9->isChecked())
    {
        counter2++;
        ui->ChosenCounter->display(counter2);
        return;
    }
    else
    {
        counter2--;
        ui->ChosenCounter->display(counter2);
        return;
    }
}

void SubWindow::on_ChosenTeam10_stateChanged(int arg1)
{
    if (ui->ChosenTeam10->isChecked())
    {
        counter2++;
        ui->ChosenCounter->display(counter2);
        return;
    }
    else
    {
        counter2--;
        ui->ChosenCounter->display(counter2);
        return;
    }
}

void SubWindow::on_ChosenTeam11_stateChanged(int arg1)
{
    if (ui->ChosenTeam11->isChecked())
    {
        counter2++;
        ui->ChosenCounter->display(counter2);
        return;
    }
    else
    {
        counter2--;
        ui->ChosenCounter->display(counter2);
        return;
    }
}

void SubWindow::on_ChosenTeam12_stateChanged(int arg1)
{
    if (ui->ChosenTeam12->isChecked())
    {
        counter2++;
        ui->ChosenCounter->display(counter2);
        return;
    }
    else
    {
        counter2--;
        ui->ChosenCounter->display(counter2);
        return;
    }
}

void SubWindow::on_ChosenTeam13_stateChanged(int arg1)
{
    if (ui->ChosenTeam13->isChecked())
    {
        counter2++;
        ui->ChosenCounter->display(counter2);
        return;
    }
    else
    {
        counter2--;
        ui->ChosenCounter->display(counter2);
        return;
    }
}

void SubWindow::on_ChosenTeam14_stateChanged(int arg1)
{
    if (ui->ChosenTeam14->isChecked())
    {
        counter2++;
        ui->ChosenCounter->display(counter2);
        return;
    }
    else
    {
        counter2--;
        ui->ChosenCounter->display(counter2);
        return;
    }
}

void SubWindow::on_ChosenTeam15_stateChanged(int arg1)
{
    if (ui->ChosenTeam15->isChecked())
    {
        counter2++;
        ui->ChosenCounter->display(counter2);
        return;
    }
    else
    {
        counter2--;
        ui->ChosenCounter->display(counter2);
        return;
    }
}

void SubWindow::on_ChosenTeam16_stateChanged(int arg1)
{
    if (ui->ChosenTeam16->isChecked())
    {
        counter2++;
        ui->ChosenCounter->display(counter2);
        return;
    }
    else
    {
        counter2--;
        ui->ChosenCounter->display(counter2);
        return;
    }
}

void SubWindow::on_ChosenTeam17_stateChanged(int arg1)
{
    if (ui->ChosenTeam17->isChecked())
    {
        counter2++;
        ui->ChosenCounter->display(counter2);
        return;
    }
    else
    {
        counter2--;
        ui->ChosenCounter->display(counter2);
        return;
    }
}

void SubWindow::on_ChosenTeam18_stateChanged(int arg1)
{
    if (ui->ChosenTeam18->isChecked())
    {
        counter2++;
        ui->ChosenCounter->display(counter2);
        return;
    }
    else
    {
        counter2--;
        ui->ChosenCounter->display(counter2);
        return;
    }
}

void SubWindow::on_ChosenTeam19_stateChanged(int arg1)
{
    if (ui->ChosenTeam19->isChecked())
    {
        counter2++;
        ui->ChosenCounter->display(counter2);
        return;
    }
    else
    {
        counter2--;
        ui->ChosenCounter->display(counter2);
        return;
    }
}

void SubWindow::on_ChosenTeam20_stateChanged(int arg1)
{
    if (ui->ChosenTeam20->isChecked())
    {
        counter2++;
        ui->ChosenCounter->display(counter2);
        return;
    }
    else
    {
        counter2--;
        ui->ChosenCounter->display(counter2);
        return;
    }
}

void SubWindow::on_ChosenTeam21_stateChanged(int arg1)
{
    if (ui->ChosenTeam21->isChecked())
    {
        counter2++;
        ui->ChosenCounter->display(counter2);
        return;
    }
    else
    {
        counter2--;
        ui->ChosenCounter->display(counter2);
        return;
    }
}
