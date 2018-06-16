#include "subwindow.h"
#include "ui_subwindow.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "player.h"
#include "goalkeeper.h"
#include "defender.h"
#include "midfielder.h"
#include "database.h"
#include "statistics.h"
#include "simulation.h"
#include "simulationround.h"
#include <QLCDNumber>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QQuickStyle>
#include <QString>
#include "team.h"
#include <windows.h>
#include <QTime>
#include <QPalette>
#include <regex>

SubWindow::SubWindow(MainWindow &_mainWindow, QWidget *parent) :
    mainWindowRef(_mainWindow), QMainWindow(parent),
    ui(new Ui::SubWindow)
{
    ui->setupUi(this);
    QQuickStyle::setStyle("Material");
    ui->centralwidget->setStyleSheet("background:rgb(252,238,225)");
    ui->SelectTeamWidget->setStyleSheet("text-color:white");
    ui->SelectTeamWidget->setStyleSheet("background:rgb(254,254,200);");
    ui->ChosenTeam->setStyleSheet("background:rgb(254,254,200);");
    DataBase::loadDataBase();
    createCheckboxes();
    SelectingTeam();
}

void SubWindow::createCheckboxes(){                                                         // tworzenie checkboxów zawodników

    QVBoxLayout *vbox = new QVBoxLayout;
    QVBoxLayout *vbox2 = new QVBoxLayout;
    QVBoxLayout *vbox3 = new QVBoxLayout;
    QVBoxLayout *vbox4 = new QVBoxLayout;
    int xy = 10;
    QFont newFont("Gill Sans MT", 10);



    for (int i =0;i<15;i++){
        QString value = "";
        value.setNum(DataBase::playerz[i].price, 'g', 3);
        QString text = DataBase::playerz[i].name + " (" + value + "$)";
        QCheckBox *checkB = new QCheckBox(text);
        vbox->addWidget(checkB);
        goalkeepersCheckB.push_back(checkB);
        checkB->setFont(newFont);
        xy += 20;
    }

    for (int i =15;i<30;i++){
        QString value = "";
        value.setNum(DataBase::playerz[i].price, 'g', 3);
        QString text = DataBase::playerz[i].name + " (" + value + "$)";
        QCheckBox *checkB = new QCheckBox(text);
        vbox2->addWidget(checkB);
        defendersCheckB.push_back(checkB);
        checkB->setFont(newFont);
        xy += 20;
    }

    for (int i =30;i<45;i++){
        QString value = "";
        value.setNum(DataBase::playerz[i].price, 'g', 3);
        QString text = DataBase::playerz[i].name + " (" + value + "$)";
        QCheckBox *checkB = new QCheckBox(text);
        vbox3->addWidget(checkB);
        midfieldersCheckB.push_back(checkB);
        checkB->setFont(newFont);
        xy += 20;
    }

    for (int i =45;i<DataBase::playerz.size();i++){
        QString value = "";
        value.setNum(DataBase::playerz[i].price, 'g', 3);
        QString text = DataBase::playerz[i].name + " (" + value + "$)";
        QCheckBox *checkB = new QCheckBox(text);
        vbox4->addWidget(checkB);
        attackersCheckB.push_back(checkB);
        checkB->setFont(newFont);
        xy += 20;
    }

    vbox->addStretch(1);
    vbox2->addStretch(1);
    vbox3->addStretch(1);
    vbox4->addStretch(1);
    ui->goalkeepersGBox->setLayout(vbox);
    ui->defendersGBox->setLayout(vbox2);
    ui->midfieldersGB->setLayout(vbox3);
    ui->attackersGB->setLayout(vbox4);
}

void SubWindow::ChoosePlayer(float cost)                                                        // zmiana budżetu po wybraniu zawodnika
{
    money -= cost;
    ui->MoneyLeft->display(money);
    counter++;
    ui->PlayerCounter->display(counter);
}

void SubWindow::RejectPlayer(float cost)                                                        // zmiana budżetu po usunięciu zawodnika
{
    money += cost;
    ui->MoneyLeft->display(money);
    counter--;
    ui->PlayerCounter->display(counter);
}

void SubWindow::setOKUnclickable()                                                              // reakcja na przycisk OK
{
    ui->Ok->setEnabled(false);
}

void SubWindow::setVisibleGoalkeeper(bool vis)                                                  // ustawienie widzialności bramkarzy
{
    ui->goalkeepersGBox->setVisible(vis);
}

void SubWindow::setVisibleDefender(bool vis)                                                    // ustawienie widzialności obrońców
{
    ui->defendersGBox->setVisible(vis);
}

void SubWindow::setVisibleMidfielder(bool vis)                                                  // ustawienie widzialności pomocników
{
    ui->midfieldersGB->setVisible(vis);
}

void SubWindow::setVisibleAttacker(bool vis)                                                    // ustawienie widzialności napastników
{
    ui->attackersGB->setVisible(vis);
}

void SubWindow::setColorGoalkeeper()                                                            // kolor bramkarzy
{
    ui->goalkeepersGBox->setStyleSheet("background:rgb(254,254,200);");
}

void SubWindow::setColorDefender()                                                              // kolor obrońców
{
    ui->defendersGBox->setStyleSheet("background:rgb(56,0,60);");
}

void SubWindow::setColorMidfielder()                                                            // kolor pomocników
{
    ui->midfieldersGB->setStyleSheet("background:rgb(56,0,60);");
}

void SubWindow::setColorAttacker()                                                              // kolor napastników
{
    ui->attackersGB->setStyleSheet("background:rgb(56,0,60);");
}

void SubWindow::setVisibleChosenTeam(bool vis)                                                  // widoczność wybranej drużyny
{
    ui->ChosenTeam->setVisible(vis);
    ui->groupBox->setVisible(vis);
}

void SubWindow::setVisibleChosenCounter(bool vis)                                               // widoczność licznika wybranych i licznika rund
{
    ui->ChosenCounter->setVisible(vis);
    ui->RoundCounter->setVisible(vis);
}

void SubWindow::setVisibleSimulateButton(bool vis)                                              // widoczność przycisków symulacji
{
    ui->Simulate->setVisible(vis);
    ui->Simulate_2->setVisible(vis);
}

void SubWindow::setDisabled()                                                                   // ukrywanie checkboxów zawodników
{
    ui->goalkeepersGBox->setEnabled(false);
    ui->defendersGBox->setEnabled(false);
    ui->midfieldersGB->setEnabled(false);
    ui->attackersGB->setEnabled(false);
}

void SubWindow::DifficultyMessage()                                                             // okno informacyjne po włączeniu programu
{
    QMessageBox::information(this, "Start", "Choose difficulty level in Options to start.\nRemember, you can change it only once.");
}

SubWindow::~SubWindow()
{
    delete ui;
}

void SubWindow::CheckboxCheck(QCheckBox* checkB, PlayerInfo& player)                            // reakcja na interakcję z checkboxem
{
    if (checkB->isChecked())
        ChoosePlayer(player.price);
    else
        RejectPlayer(player.price);

    mainWindowRef.setPlayerLabel(player);

    if (counter == 21){
        ui->Ok->setEnabled(true);
    }
    else {
        ui->Ok->setEnabled(false);
    }
}

void SubWindow::SelectingTeam()                                                                 // powiązanie checkboxów z funkcjami
{

    for (int i=0;i<goalkeepersCheckB.size();i++) {
        connect(goalkeepersCheckB[i],&QCheckBox::stateChanged,this,
                [i, this]{ CheckboxCheck(goalkeepersCheckB[i], DataBase::playerz[i]); });
    }

    for (int i=0;i<defendersCheckB.size();i++) {
        connect(defendersCheckB[i],&QCheckBox::stateChanged,this,
                [i, this]{ CheckboxCheck(defendersCheckB[i], DataBase::playerz[i + 15]); });
    }

    for (int i=0;i<midfieldersCheckB.size();i++) {
        connect(midfieldersCheckB[i],&QCheckBox::stateChanged,this,
                [i, this]{ CheckboxCheck(midfieldersCheckB[i], DataBase::playerz[i + 30]); });
    }
    for (int i=0;i<attackersCheckB.size();i++) {
        connect(attackersCheckB[i],&QCheckBox::stateChanged,this,
                [i, this]{ CheckboxCheck(attackersCheckB[i], DataBase::playerz[i + 45]); });
    }
}

void SubWindow::on_Ok_clicked()                                                                 // reakcja na przycisk OK
{
    try
    {
        if (money < 0){
            throw 1;
        }

        else{
            if(QMessageBox::question(this, "Are you sure?", "Do you want to start simulation?", QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes)
            {
            ui->SelectTeamWidget->setVisible(false);
            ui->MoneyLeft->setVisible(false);
            ui->label->setVisible(false);
            ui->label_2->setVisible(false);
            ui->label_3->setVisible(false);
            ui->label_4->setVisible(false);
            ui->label_5->setVisible(false);
            ui->label_6->setVisible(false);
            ui->PlayerCounter->setVisible(false);            ui->ChosenTeam->setVisible(true);
            ui->Simulate->setVisible(true);
            ui->Simulate_2->setVisible(true);
            ui->Simulate->setEnabled(false);
            ui->Simulate_2->setEnabled(false);
            ui->Ok->setVisible(false);
            ui->ChosenCounter->setVisible(true);
            ui->Matches->setVisible(true);
            ui->frame->setVisible(false);
            ui->frame_2->setVisible(false);
            ui->frame_3->setVisible(false);
            ui->defendersGBox->setVisible(false);
            ui->groupBox->setVisible(true);
            ui->Matches->setVisible(true);
            ui->Matches_2->setVisible(true);
            ui->Matches_3->setVisible(true);
            ui->Matches_7->setVisible(true);
            ui->Matches_8->setVisible(true);
            ui->Matches_9->setVisible(true);
            ui->Matches_10->setVisible(true);
            ui->lineEdit->setVisible(false);

            for (int i = 0; i < goalkeepersCheckB.size(); i++)
            {
                if (goalkeepersCheckB[i]->isChecked())
                {
                    DataBase::chosen.push_back(DataBase::playerz[i]);
                }
            }

            for (int i = 0; i < defendersCheckB.size(); i++)
            {
                if (defendersCheckB[i]->isChecked())
                {
                    DataBase::chosen.push_back(DataBase::playerz[i + 15]);
                }
            }

            for (int i = 0; i < midfieldersCheckB.size(); i++)
            {
                if (midfieldersCheckB[i]->isChecked())
                {
                    DataBase::chosen.push_back(DataBase::playerz[i + 30]);
                }
            }

            for (int i = 0; i < attackersCheckB.size(); i++)
            {
                if (attackersCheckB[i]->isChecked())
                {
                    DataBase::chosen.push_back(DataBase::playerz[i + 45]);
                }
            }
            SetPassiveBonus();
            createChosenCheckboxes();
            SelectingChosenTeam();
            }
        }
    }
    catch(...)
    {
         QMessageBox::warning(this, "Error", "The limit has been exceeded");
    }
}

void SubWindow::on_Cancel_clicked()                                                                 // reakcja na przycisk Cancel
{
    for (int i = 0; i < ChosenTeam.size(); i++)
        delete ChosenTeam[i];

    ChosenTeam.clear();
    delete ui->ChosenTeam->layout();

    for (int i = 0; i < goalkeepersCheckB.size(); i++)
        delete goalkeepersCheckB[i];
    goalkeepersCheckB.clear();
    delete ui->goalkeepersGBox->layout();

    for (int i = 0; i < defendersCheckB.size(); i++)
        delete defendersCheckB[i];
    defendersCheckB.clear();
    delete ui->defendersGBox->layout();

    for (int i = 0; i < midfieldersCheckB.size(); i++)
        delete midfieldersCheckB[i];
    midfieldersCheckB.clear();
    delete ui->midfieldersGB->layout();

    for (int i = 0; i < attackersCheckB.size(); i++)
        delete attackersCheckB[i];
    attackersCheckB.clear();
    delete ui->attackersGB->layout();

    DataBase::Teams.erase(DataBase::Teams.begin(), DataBase::Teams.end());
    DataBase::Teams.clear();


    this->close(); 
}

void SubWindow::on_Prev_clicked()                                                                   // reakcja na przycisk Prev
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
        ui->Simulate_2->setVisible(false);
        ui->Ok->setVisible(true);
        ui->ChosenCounter->setVisible(false);
        ui->groupBox->setVisible(false);
        ui->defendersGBox->setVisible(true);

    }
    else
        this->close();
}

void SubWindow::CheckboxCheck2(QCheckBox* checkB, PlayerInfo& player)                               // wybieranie zawodników do gry
{
    if (checkB->isChecked())
    {
        counter2++;
        ui->ChosenCounter->display(counter2);
    }
    else
    {
        counter2--;
        ui->ChosenCounter->display(counter2);
    }
    mainWindowRef.setPlayerLabel(player);

    if (counter2 == 11){
        ui->Simulate->setEnabled(true);
        ui->Simulate_2->setEnabled(true);
    }
    else {
        ui->Simulate->setEnabled(false);
        ui->Simulate_2->setEnabled(false);
    }
}

void SubWindow::createChosenCheckboxes(){                                                           // tworzenie checkboxów wybranych zawodników

    QVBoxLayout *vbox5 = new QVBoxLayout;
    for (int i = 0; i < ChosenTeam.size(); i++)
        delete ChosenTeam[i];

    ChosenTeam.clear();
    delete ui->ChosenTeam->layout();
    int xy = 10;
    QFont newFont("Gill Sans MT", 10);

    for (int i =0;i<21;i++){
        QString value = "";
        value.setNum(DataBase::chosen[i].price, 'g', 3);
        QString text = DataBase::chosen[i].name + " (" + value + "$)";
        QCheckBox *checkB = new QCheckBox(text);
        checkB->setText(text);
        vbox5->addWidget(checkB);
        ChosenTeam.push_back(checkB);
        checkB->setFont(newFont);
        xy += 20;
    }

    vbox5->addStretch(1);
    ui->ChosenTeam->setLayout(vbox5);

}

void SubWindow::SelectingChosenTeam()                                                               // powiązanie checkboxów wybranych zawodników z funkcjami
{
    for (int i=0;i<ChosenTeam.size();i++) {
        connect(ChosenTeam[i],&QCheckBox::stateChanged,this,
                [i, this]{ CheckboxCheck2(ChosenTeam[i], DataBase::chosen[i]); });
    }
}

void SubWindow::on_actionExit_triggered()
{
    this->close();
}

void SubWindow::on_actionHow_to_Play_triggered()                                                    // reakcja na opcę How to Play
{
    QMessageBox::information(this, "How to Play?", "Choose your team and try to win the league!");
}

void SubWindow::on_actionAbout_triggered()                                                          // reakcja na opcję About
{
    QMessageBox::information(this, "About", "Author: Pawel Wawszczyk\n\nAll rights reserved\n\nGliwice, 2018");
}

void SubWindow::on_actionEasy_triggered()                                                           // reakcja na wybór poziomy trudności łatwego
{
    money = 900;
    ui->MoneyLeft->display(money);
    ui->goalkeepersGBox->setEnabled(true);
    ui->defendersGBox->setEnabled(true);
    ui->midfieldersGB->setEnabled(true);
    ui->attackersGB->setEnabled(true);
    ui->menuDifficulty_level->setEnabled(false);

}

void SubWindow::on_actionMedium_triggered()                                                         // reakcja na wybór poziomy trudności średniego
{
    money = 800;
    ui->MoneyLeft->display(money);
    ui->goalkeepersGBox->setEnabled(true);
    ui->defendersGBox->setEnabled(true);
    ui->midfieldersGB->setEnabled(true);
    ui->attackersGB->setEnabled(true);
    ui->menuDifficulty_level->setEnabled(false);
}

void SubWindow::on_actionHard_triggered()                                                           // reakcja na wybór poziomy trudności trudnego
{
    money = 700;
    ui->MoneyLeft->display(money);
    ui->goalkeepersGBox->setEnabled(true);
    ui->defendersGBox->setEnabled(true);
    ui->midfieldersGB->setEnabled(true);
    ui->attackersGB->setEnabled(true);
    ui->menuDifficulty_level->setEnabled(false);
}

void SubWindow::on_Simulate_clicked()                                                               // reakcja na przycisk Simulate
{
    mainWindowRef.setTable();
    simulation s(*this, mainWindowRef);
    ui->RoundCounter->setVisible(true);
    if(counter2 == 11)
    {
        ui->Prev->setVisible(false);
        ui->Simulate->setEnabled(false);
        ui->Simulate_2->setEnabled(false);
        for (int i = 0; i < ChosenTeam.size(); i++)
        {
            if (ChosenTeam[i]->isChecked())
            {
                DataBase::InGamePlayers.push_back(DataBase::chosen[i]);
            }
        }
        s.MakeSeason();
    }

}

void SubWindow::on_Simulate_2_clicked()                                                             // reakcja na przycisk Simulate Round
{
    mainWindowRef.setTable();
    simulationround s(*this, mainWindowRef);
    ui->RoundCounter->setVisible(true);
    if(counter2 == 11)
    {
        ui->Prev->setVisible(false);
        ui->Simulate->setEnabled(false);
        ui->Simulate_2->setEnabled(false);
        if (roundcounter < 38)
        {
            for (int i = 0; i < ChosenTeam.size(); i++)
            {
                if (ChosenTeam[i]->isChecked())
                {
                    DataBase::InGamePlayers.push_back(DataBase::chosen[i]);
                }
            }

            s.MakeSeason(j);
            ui->Simulate_2->setEnabled(true);
            roundcounter++;
            j++;
            if (j == 19)
                j = 0;
            ui->RoundCounter->display(roundcounter);
        }
        else
        {
            if (DataBase::Clone[0].name == "My Team")
            {
                WinnerMessage();
            }
            SetWinners();
            Player p;
            p.SetAge();
            SetVisibleRetry(true);
        }

    }
}

// wyświetlanie tekstów dotyczących wyników meczów

void SubWindow::setText1(QString tex1)
{
    ui->Matches_4->setText(tex1);
}

void SubWindow::setText2(QString tex2)
{
    ui->Matches_5->setText(tex2);
}

void SubWindow::setText3(QString tex3)
{
    ui->Matches_6->setText(tex3);
}

void SubWindow::IncrementRound(int counter)                                                     // inkrementacja rundy sezonu
{
    ui->RoundCounter->display(counter);
}

void SubWindow::SetWinners()                                                                    // wyświetlanie wygranych i spadkowiczów
{
    QFont newFont("Gill Sans MT", 12, QFont::Bold);
    QString winners = "Champions: " + DataBase::Clone[0].name;
    ui->Matches_7->setFont(newFont);
    ui->Matches_7->setText(winners);    
    winners = "Runner-Up: " + DataBase::Clone[1].name + ".";
    ui->Matches_8->setFont(newFont);
    ui->Matches_8->setText(winners);
    winners = "Third place: " + DataBase::Clone[2].name + ".";
    ui->Matches_9->setFont(newFont);
    ui->Matches_9->setText(winners);
    winners = "Relegated:\n\n" + DataBase::Clone[17].name + "\n\n" + DataBase::Clone[18].name + "\n\n" + DataBase::Clone[19].name;
    ui->Matches_10->setFont(newFont);
    ui->Matches_10->setText(winners);

}

void SubWindow::SetPassiveBonus()                                                               // ustawienie bonusów pasywnych
{
    if(ui->checkBox->isChecked())
        DataBase::Teams[15].power *= 1.2;
    if(ui->checkBox_2->isChecked())
        DataBase::Teams[15].power *= 1.1;
    if(ui->checkBox_3->isChecked())
        DataBase::Teams[15].power *= 1.07;
    if(ui->checkBox_4->isChecked())
        DataBase::Teams[15].power *= 1.14;
    if(ui->checkBox_5->isChecked())
        DataBase::Teams[15].power *= 1.12;
    if(ui->checkBox_6->isChecked())
        DataBase::Teams[15].power *= 1.06;
    if(ui->checkBox_25->isChecked())
        DataBase::Teams[15].power *= 1.03;
    if(ui->checkBox_7->isChecked())
        DataBase::Teams[15].power *= 1.02;
    if(ui->checkBox_8->isChecked())
        DataBase::Teams[15].power *= 1.01;
    if(ui->checkBox_9->isChecked())
        DataBase::Teams[15].power *= 1.02;
    if(ui->checkBox_10->isChecked())
        DataBase::Teams[15].power *= 1.01;
    if(ui->checkBox_11->isChecked())
        DataBase::Teams[15].power *= 1.04;
    if(ui->checkBox_12->isChecked())
        DataBase::Teams[15].power *= 1.02;
    if(ui->checkBox_13->isChecked())
        DataBase::Teams[15].power *= 1.06;
    if(ui->checkBox_16->isChecked())
    {
        for (int i = 0; i < DataBase::chosen.size(); i++)
        {
            DataBase::chosen[i].fitness *= 1.1;
        }
    }
    if(ui->checkBox_17->isChecked())
    {
        for (int i = 0; i < DataBase::chosen.size(); i++)
        {
            DataBase::chosen[i].fitness *= 1.09;
        }
    }
    if(ui->checkBox_18->isChecked())
    {
        for (int i = 0; i < DataBase::chosen.size(); i++)
        {
            DataBase::chosen[i].fitness *= 1.08;
        }
    }
    if(ui->checkBox_19->isChecked())
    {
        for (int i = 0; i < DataBase::chosen.size(); i++)
        {
            DataBase::chosen[i].fitness *= 1.07;
        }
    }
    if(ui->checkBox_20->isChecked())
    {
        for (int i = 0; i < DataBase::chosen.size(); i++)
        {
            DataBase::chosen[i].fitness *= 1.06;
        }
    }
    if(ui->checkBox_21->isChecked())
    {
        for (int i = 0; i < DataBase::chosen.size(); i++)
        {
            DataBase::chosen[i].fitness *= 1.05;
        }
    }
    if(ui->checkBox_22->isChecked())
    {
        for (int i = 0; i < DataBase::chosen.size(); i++)
        {
            DataBase::chosen[i].fitness *= 1.04;
        }
    }
    if(ui->checkBox_64->isChecked())
    {
        DataBase::Teams[15].power *= 1.2;
    }
    if(ui->checkBox_22->isChecked())
    {
        DataBase::Teams[15].power *= 1.2;
    }
    if(ui->checkBox_22->isChecked())
    {
        DataBase::Teams[15].power *= 1.4;
    }
}

// reakcje na checkboxy dotyczące bonusów pasywnych

void SubWindow::on_checkBox_clicked()
{
    if(ui->checkBox->isChecked())
    {
    money -= 52;
    ui->MoneyLeft->display(money);
    }
    else
    {
    money += 52;
    ui->MoneyLeft->display(money);
    }
}

void SubWindow::on_checkBox_2_clicked()
{
    if(ui->checkBox_2->isChecked())
    {
    money -= 40;
    ui->MoneyLeft->display(money);
    }
    else
    {
    money += 40;
    ui->MoneyLeft->display(money);
    }
}

void SubWindow::on_checkBox_3_clicked()
{
    if(ui->checkBox_3->isChecked())
    {
    money -= 37;
    ui->MoneyLeft->display(money);
    }
    else
    {
    money += 37;
    ui->MoneyLeft->display(money);
    }
}

void SubWindow::on_checkBox_4_clicked()
{
    if(ui->checkBox_4->isChecked())
    {
    money -= 46;
    ui->MoneyLeft->display(money);
    }
    else
    {
    money += 46;
    ui->MoneyLeft->display(money);
    }
}

void SubWindow::on_checkBox_5_clicked()
{
    if(ui->checkBox_5->isChecked())
    {
    money -= 29;
    ui->MoneyLeft->display(money);
    }
    else
    {
    money += 29;
    ui->MoneyLeft->display(money);
    }
}

void SubWindow::on_checkBox_6_clicked()
{
    if(ui->checkBox_6->isChecked())
    {
    money -= 20;
    ui->MoneyLeft->display(money);
    }
    else
    {
    money += 20;
    ui->MoneyLeft->display(money);
    }
}

void SubWindow::on_checkBox_25_clicked()
{
    if(ui->checkBox_25->isChecked())
    {
    money -= 23;
    ui->MoneyLeft->display(money);
    }
    else
    {
    money += 23;
    ui->MoneyLeft->display(money);
    }
}

void SubWindow::on_checkBox_7_clicked()
{
    if(ui->checkBox_7->isChecked())
    {
    money -= 11;
    ui->MoneyLeft->display(money);
    }
    else
    {
    money += 11;
    ui->MoneyLeft->display(money);
    }
}

void SubWindow::on_checkBox_8_clicked()
{
    if(ui->checkBox_8->isChecked())
    {
    money -= 9;
    ui->MoneyLeft->display(money);
    }
    else
    {
    money += 9;
    ui->MoneyLeft->display(money);
    }
}

void SubWindow::on_checkBox_9_clicked()
{
    if(ui->checkBox_9->isChecked())
    {
    money -= 10;
    ui->MoneyLeft->display(money);
    }
    else
    {
    money += 10;
    ui->MoneyLeft->display(money);
    }
}

void SubWindow::on_checkBox_10_clicked()
{
    if(ui->checkBox_10->isChecked())
    {
    money -= 12;
    ui->MoneyLeft->display(money);
    }
    else
    {
    money += 12;
    ui->MoneyLeft->display(money);
    }
}

void SubWindow::on_checkBox_11_clicked()
{
    if(ui->checkBox_11->isChecked())
    {
    money -= 14;
    ui->MoneyLeft->display(money);
    }
    else
    {
    money += 14;
    ui->MoneyLeft->display(money);
    }
}

void SubWindow::on_checkBox_12_clicked()
{
    if(ui->checkBox_12->isChecked())
    {
    money -= 8;
    ui->MoneyLeft->display(money);
    }
    else
    {
    money += 8;
    ui->MoneyLeft->display(money);
    }
}

void SubWindow::on_checkBox_13_clicked()
{
    if(ui->checkBox_13->isChecked())
    {
    money -= 10;
    ui->MoneyLeft->display(money);
    }
    else
    {
    money += 10;
    ui->MoneyLeft->display(money);
    }
}



void SubWindow::on_checkBox_16_clicked()
{
    if(ui->checkBox_16->isChecked())
    {
    money -= 12;
    ui->MoneyLeft->display(money);
    }
    else
    {
    money += 12;
    ui->MoneyLeft->display(money);
    }
}

void SubWindow::on_checkBox_17_clicked()
{
    if(ui->checkBox_16->isChecked())
    {
    money -= 11;
    ui->MoneyLeft->display(money);
    }
    else
    {
    money += 11;
    ui->MoneyLeft->display(money);
    }
}

void SubWindow::on_checkBox_18_clicked()
{
    if(ui->checkBox_16->isChecked())
    {
    money -= 10;
    ui->MoneyLeft->display(money);
    }
    else
    {
    money += 10;
    ui->MoneyLeft->display(money);
    }
}

void SubWindow::on_checkBox_19_clicked()
{
    if(ui->checkBox_16->isChecked())
    {
    money -= 9;
    ui->MoneyLeft->display(money);
    }
    else
    {
    money += 9;
    ui->MoneyLeft->display(money);
    }
}

void SubWindow::on_checkBox_20_clicked()
{
    if(ui->checkBox_16->isChecked())
    {
    money -= 8;
    ui->MoneyLeft->display(money);
    }
    else
    {
    money += 8;
    ui->MoneyLeft->display(money);
    }
}

void SubWindow::on_checkBox_21_clicked()
{
    if(ui->checkBox_16->isChecked())
    {
    money -= 7;
    ui->MoneyLeft->display(money);
    }
    else
    {
    money += 7;
    ui->MoneyLeft->display(money);
    }
}

void SubWindow::on_checkBox_22_clicked()
{
    if(ui->checkBox_16->isChecked())
    {
    money -= 6;
    ui->MoneyLeft->display(money);
    }
    else
    {
    money += 6;
    ui->MoneyLeft->display(money);
    }
}

void SubWindow::on_checkBox_64_clicked()
{
    if(ui->checkBox_64->isChecked())
    {
    money -= 40;
    ui->MoneyLeft->display(money);
    }
    else
    {
    money += 40;
    ui->MoneyLeft->display(money);
    }
}

void SubWindow::on_checkBox_65_clicked()
{
    if(ui->checkBox_65->isChecked())
    {
    money -= 40;
    ui->MoneyLeft->display(money);
    }
    else
    {
    money += 40;
    ui->MoneyLeft->display(money);
    }
}

void SubWindow::on_checkBox_66_clicked()
{
    if(ui->checkBox_66->isChecked())
    {
    money -= 50;
    ui->MoneyLeft->display(money);
    }
    else
    {
    money += 50;
    ui->MoneyLeft->display(money);
    }
}

void SubWindow::WinnerMessage()
{
    QMessageBox::information(this, "Winner!!!", "Congratulations! You won the game! \nIf you want, you can try again." );
}

void SubWindow::on_Retry_clicked()
{
    ui->SelectTeamWidget->setVisible(true);
    ui->MoneyLeft->setVisible(true);
    ui->label->setVisible(true);
    ui->label_2->setVisible(true);
    ui->label_3->setVisible(true);
    ui->label_4->setVisible(true);
    ui->label_5->setVisible(true);
    ui->label_6->setVisible(true);
    ui->PlayerCounter->setVisible(true);
    ui->ChosenTeam->setVisible(false);
    ui->Simulate->setVisible(false);
    ui->Simulate->setEnabled(true);
    ui->Simulate_2->setVisible(false);
    ui->Simulate_2->setEnabled(true);
    ui->Ok->setVisible(true);
    ui->ChosenCounter->setVisible(false);
    ui->Matches->setVisible(false);
    ui->frame->setVisible(true);
    ui->frame_2->setVisible(true);
    ui->frame_3->setVisible(true);
    ui->defendersGBox->setVisible(true);
    ui->groupBox->setVisible(false);
    ui->Matches->setVisible(false);
    ui->Matches_2->setVisible(false);
    ui->Matches_3->setVisible(false);
    ui->Matches_7->setVisible(false);
    ui->Matches_8->setVisible(false);
    ui->Matches_9->setVisible(false);
    ui->Matches_10->setVisible(false);
    ui->RoundCounter->setVisible(false);
    ui->Retry->setVisible(false);
    mainWindowRef.setTableVisible(false);

    DataBase::Teams.erase(DataBase::Teams.begin(), DataBase::Teams.end());
    DataBase::Clone.erase(DataBase::Clone.begin(), DataBase::Clone.end());
    DataBase::playerz.erase(DataBase::playerz.begin(), DataBase::playerz.end());
    DataBase::chosen.erase(DataBase::chosen.begin(), DataBase::chosen.end());
    DataBase::InGamePlayers.erase(DataBase::InGamePlayers.begin(), DataBase::InGamePlayers.end());
    ChosenTeam.erase(ChosenTeam.begin(), ChosenTeam.end());
    DataBase::loadDataBase();
    ui->MoneyLeft->display(money);
    ui->menuDifficulty_level->setEnabled(true);
    ui->goalkeepersGBox->setEnabled(false);
    ui->defendersGBox->setEnabled(false);
    ui->midfieldersGB->setEnabled(false);
    ui->attackersGB->setEnabled(false);
    for (int i=0;i<goalkeepersCheckB.size();i++)
    {
        goalkeepersCheckB[i]->setChecked(false);
    }
    for (int i=0;i<defendersCheckB.size();i++)
    {
        defendersCheckB[i]->setChecked(false);
    }
    for (int i=0;i<midfieldersCheckB.size();i++)
    {
        midfieldersCheckB[i]->setChecked(false);
    }
    for (int i=0;i<attackersCheckB.size();i++)
    {
        attackersCheckB[i]->setChecked(false);
    }
    ui->checkBox_2->setChecked(false);
    ui->checkBox_3->setChecked(false);
    ui->checkBox_4->setChecked(false);
    ui->checkBox_5->setChecked(false);
    ui->checkBox_6->setChecked(false);
    ui->checkBox_25->setChecked(false);
    ui->checkBox_7->setChecked(false);
    ui->checkBox_8->setChecked(false);
    ui->checkBox_9->setChecked(false);
    ui->checkBox_10->setChecked(false);
    ui->checkBox_11->setChecked(false);
    ui->checkBox_12->setChecked(false);
    ui->checkBox_13->setChecked(false);
    ui->checkBox_16->setChecked(false);
    ui->checkBox_17->setChecked(false);
    ui->checkBox_18->setChecked(false);
    ui->checkBox_19->setChecked(false);
    ui->checkBox_20->setChecked(false);
    ui->checkBox_21->setChecked(false);
    ui->checkBox_22->setChecked(false);
    ui->checkBox_64->setChecked(false);
    ui->checkBox_65->setChecked(false);
    ui->checkBox_66->setChecked(false);
    ui->Matches->setText("");
    ui->Matches_2->setText("");
    ui->Matches_3->setText("");
    ui->Matches_4->setText("");
    ui->Matches_5->setText("");
    ui->Matches_6->setText("");
    ui->Matches_7->setText("");
    ui->Matches_8->setText("");
    ui->Matches_9->setText("");
    ui->Matches_10->setText("");
    ui->lineEdit->setVisible(true);
    roundcounter = 0;
    ui->RoundCounter->display(roundcounter );
    counter2 = 0;
    ui->ChosenCounter->display(counter);
    j = 0;
}

void SubWindow::SetVisibleRetry(bool vis)
{
    ui->Retry->setVisible(vis);
}

void SubWindow::on_lineEdit_textEdited(const QString &arg1)
{
    std::regex pattern = std::regex("[A-Za-z0-9]+");
    string tex = ui->lineEdit->text().toStdString();
    if(regex_match(tex, pattern))
    {
        DataBase::Teams[15].name = ui->lineEdit->text();
    }
    else
    {
        QMessageBox::information(this, "Warning", "Wrong name! Use only letters!");
        std::string text = ui->lineEdit->text().toStdString();
        std::string textChanged = text.substr(0,text.size() - 1);
        ui->lineEdit->setText(QString::fromStdString(textChanged));
    }
}
