#ifndef SUBWINDOW_H
#define SUBWINDOW_H

#include <QMainWindow>
#include <QColor>
#include <player.h>

namespace Ui {
class SubWindow;
}

class SubWindow : public QMainWindow
{
    Q_OBJECT
private:
    Ui::SubWindow *ui;

public:
    explicit SubWindow(QWidget *parent = 0);
    ~SubWindow();
    void setVisibleGoalkeeper(bool vis);
    void setVisibleDefender(bool vis);
    void setVisibleMidfielder(bool vis);
    void setVisibleAttacker(bool vis);
    void setVisibleChosenTeam(bool vis);
    void setVisibleSimulateButton(bool vis);
    void setColorGoalkeeper();
    void setColorDefender();
    void setColorMidfielder();
    void setColorAttacker();
    void setOKUnclickable();
    Player GoalkeeperTab[6];
    float money = 900;
    int counter = 0;
    int counter2 = 0;
    std::vector<Player> players;

    void SelectingTeam();
    void CheckboxCheck();
    void ChoosePlayer(float cost);
    void RejectPlayer(float cost);
private slots:
    //void SetPlayers();

private slots:

    void on_Goalkeeper1_ChB_stateChanged(int arg1);
    void on_Goalkeeper2_ChB_stateChanged(int arg1);
    void on_Goalkeeper3_ChB_stateChanged(int arg1);
    void on_Goalkeeper4_ChB_stateChanged(int arg1);
    void on_Goalkeeper5_ChB_stateChanged(int arg1);
    void on_Goalkeeper6_ChB_stateChanged(int arg1);
    void on_Goalkeeper7_ChB_stateChanged(int arg1);
    void on_Goalkeeper8_ChB_stateChanged(int arg1);
    void on_Goalkeeper9_ChB_stateChanged(int arg1);
    void on_Goalkeeper10_ChB_stateChanged(int arg1);
    void on_Goalkeeper11_ChB_stateChanged(int arg1);
    void on_Goalkeeper12_ChB_stateChanged(int arg1);
    void on_Goalkeeper13_ChB_stateChanged(int arg1);
    void on_Goalkeeper14_ChB_stateChanged(int arg1);
    void on_Goalkeeper15_ChB_stateChanged(int arg1);
    void on_Defender1_ChB_stateChanged(int arg1);
    void on_Defender6_ChB_stateChanged(int arg1);
    void on_Defender2_ChB_stateChanged(int arg1);
    void on_Defender3_ChB_stateChanged(int arg1);
    void on_Defender4_ChB_stateChanged(int arg1);
    void on_Defender5_ChB_stateChanged(int arg1);
    void on_Defender7_ChB_stateChanged(int arg1);
    void on_Defender8_ChB_stateChanged(int arg1);
    void on_Defender9_ChB_stateChanged(int arg1);
    void on_Defender10_ChB_stateChanged(int arg1);
    void on_Defender11_ChB_stateChanged(int arg1);
    void on_Defender12_ChB_stateChanged(int arg1);
    void on_Defender13_ChB_stateChanged(int arg1);
    void on_Defender14_ChB_stateChanged(int arg1);
    void on_Defender15_ChB_stateChanged(int arg1);
    void on_Midfielder1_ChB_stateChanged(int arg1);
    void on_Midfielder2_ChB_stateChanged(int arg1);
    void on_Midfielder3_ChB_stateChanged(int arg1);
    void on_Midfielder4_ChB_stateChanged(int arg1);
    void on_Midfielder5_ChB_stateChanged(int arg1);
    void on_Midfielder6_ChB_stateChanged(int arg1);
    void on_Midfielder7_ChB_stateChanged(int arg1);
    void on_Midfielder8_ChB_stateChanged(int arg1);
    void on_Midfielder9_ChB_stateChanged(int arg1);
    void on_Midfielder10_ChB_stateChanged(int arg1);
    void on_Midfielder11_ChB_stateChanged(int arg1);
    void on_Midfielder12_ChB_stateChanged(int arg1);
    void on_Midfielder13_ChB_stateChanged(int arg1);
    void on_Midfielder14_ChB_stateChanged(int arg1);
    void on_Midfielder15_ChB_stateChanged(int arg1);
    void on_Attacker1_ChB_stateChanged(int arg1);
    void on_Attacker2_ChB_stateChanged(int arg1);
    void on_Attacker3_ChB_stateChanged(int arg1);
    void on_Attacker4_ChB_stateChanged(int arg1);
    void on_Attacker5_ChB_stateChanged(int arg1);
    void on_Attacker6_ChB_stateChanged(int arg1);
    void on_Attacker7_ChB_stateChanged(int arg1);
    void on_Attacker8_ChB_stateChanged(int arg1);
    void on_Attacker9_ChB_stateChanged(int arg1);
    void on_Attacker10_ChB_stateChanged(int arg1);
    void on_Attacker11_ChB_stateChanged(int arg1);
    void on_Attacker12_ChB_stateChanged(int arg1);
    void on_Attacker13_ChB_stateChanged(int arg1);
    void on_Attacker14_ChB_stateChanged(int arg1);
    void on_Attacker15_ChB_stateChanged(int arg1);
    void on_Ok_clicked();
    void on_Cancel_clicked();
    void on_Prev_clicked();
    void on_ChosenTeam1_stateChanged(int arg1);
    void on_ChosenTeam2_stateChanged(int arg1);
    void on_ChosenTeam3_stateChanged(int arg1);
    void on_ChosenTeam4_stateChanged(int arg1);
    void on_ChosenTeam5_stateChanged(int arg1);
    void on_ChosenTeam6_stateChanged(int arg1);
    void on_ChosenTeam7_stateChanged(int arg1);
    void on_ChosenTeam8_stateChanged(int arg1);
    void on_ChosenTeam9_stateChanged(int arg1);
    void on_ChosenTeam10_stateChanged(int arg1);
    void on_ChosenTeam11_stateChanged(int arg1);
    void on_ChosenTeam12_stateChanged(int arg1);
    void on_ChosenTeam13_stateChanged(int arg1);
    void on_ChosenTeam14_stateChanged(int arg1);
    void on_ChosenTeam15_stateChanged(int arg1);
    void on_ChosenTeam16_stateChanged(int arg1);
    void on_ChosenTeam17_stateChanged(int arg1);
    void on_ChosenTeam18_stateChanged(int arg1);
    void on_ChosenTeam19_stateChanged(int arg1);
    void on_ChosenTeam20_stateChanged(int arg1);
    void on_ChosenTeam21_stateChanged(int arg1);
};

#endif // SUBWINDOW_H
