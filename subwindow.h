#ifndef SUBWINDOW_H
#define SUBWINDOW_H

#include <QMainWindow>
#include <QColor>
#include <player.h>
#include <QCheckBox>
#include <QGroupBox>
#include "database.h"
#include "team.h"
#include "mainwindow.h"

namespace Ui {
class SubWindow;
}

class SubWindow : public QMainWindow
{
    Q_OBJECT
private:
    Ui::SubWindow *ui;

    MainWindow &mainWindowRef;
    std::vector<QCheckBox*> goalkeepersCheckB;
    std::vector<QCheckBox*> defendersCheckB;
    std::vector<QCheckBox*> midfieldersCheckB;
    std::vector<QCheckBox*> attackersCheckB;
    std::vector<QCheckBox*> ChosenTeam;

    void createCheckboxes();
    void createChosenCheckboxes();
public:
    explicit SubWindow(MainWindow &_mainWindow, QWidget *parent = 0);
    ~SubWindow();
    void setVisibleGoalkeeper(bool vis);
    void setVisibleDefender(bool vis);
    void setVisibleMidfielder(bool vis);
    void setVisibleAttacker(bool vis);
    void setVisibleChosenTeam(bool vis);
    void setVisibleSimulateButton(bool vis);
    void setVisibleChosenCounter(bool vis);
    void SetVisibleRetry(bool vis);
    void setColorGoalkeeper();
    void setColorDefender();
    void setColorMidfielder();
    void setColorAttacker();
    void setOKUnclickable();
    void setDisabled();
    void DifficultyMessage();
    void setText1(QString tex1);
    void setText2(QString tex2);
    void setText3(QString tex3);
    void SetWinners();
    void SetPassiveBonus();
    void WinnerMessage();


    float money = 750;
    int counter = 0;
    int counter2 = 0;
    int roundcounter = 0;
    int j = 0;

    void SelectingTeam();
    void SelectingChosenTeam();
    void SelectingInGameTeam();
    void CheckboxCheck(QCheckBox* checkB, PlayerInfo& player);
    void CheckboxCheck2(QCheckBox* checkB, PlayerInfo& player);
    void CheckboxCheck3(QCheckBox* checkB, PlayerInfo& player);
    void IncrementRound(int counter);
    void ChoosePlayer(float cost);
    void RejectPlayer(float cost);


private slots:

    void on_Ok_clicked();
    void on_Cancel_clicked();
    void on_Prev_clicked();
    void on_actionExit_triggered();
    void on_actionHow_to_Play_triggered();
    void on_actionAbout_triggered();
    void on_actionEasy_triggered();
    void on_actionMedium_triggered();
    void on_actionHard_triggered();
    void on_Simulate_clicked();
    void on_Simulate_2_clicked();
    void on_checkBox_clicked();
    void on_checkBox_2_clicked();
    void on_checkBox_3_clicked();
    void on_checkBox_4_clicked();
    void on_checkBox_5_clicked();
    void on_checkBox_6_clicked();
    void on_checkBox_25_clicked();
    void on_checkBox_7_clicked();
    void on_checkBox_8_clicked();
    void on_checkBox_9_clicked();
    void on_checkBox_10_clicked();
    void on_checkBox_11_clicked();
    void on_checkBox_12_clicked();
    void on_checkBox_13_clicked();

    void on_checkBox_16_clicked();
    void on_checkBox_17_clicked();
    void on_checkBox_18_clicked();
    void on_checkBox_19_clicked();
    void on_checkBox_20_clicked();
    void on_checkBox_21_clicked();
    void on_checkBox_22_clicked();

    void on_checkBox_64_clicked();
    void on_checkBox_65_clicked();
    void on_checkBox_66_clicked();
    void on_Retry_clicked();
    void on_lineEdit_textEdited(const QString &arg1);
};

#endif // SUBWINDOW_H
