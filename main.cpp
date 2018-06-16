#include "subwindow.h"
#include "goalkeeper.h"

#include "player.h"
#include <QApplication>



//vector<Player> Match::players;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow c;
    SubWindow b(c);

    c.show();
    b.show();
    b.setGeometry(0,100,0,0);
    c.setGeometry(1000,100,0,0);
    c.setTableVisible(false);
    b.setVisibleGoalkeeper(true);
    b.setVisibleDefender(true);
    b.setVisibleMidfielder(true);
    b.setVisibleAttacker(true);
    b.setVisibleChosenTeam(false);
    b.setColorGoalkeeper();
    b.setVisibleSimulateButton(false);
    b.setOKUnclickable();
    b.setVisibleChosenCounter(false);
    b.setDisabled();
    b.DifficultyMessage();
    b.SetVisibleRetry(false);


    return a.exec();
}
