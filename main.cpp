#include "mainwindow.h"
#include "subwindow.h"
#include "goalkeeper.h"
#include "match.h"
#include "player.h"
#include <QApplication>


//vector<Player> Match::players;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    SubWindow b;
    MainWindow c;

    c.show();
    b.show();
    b.setGeometry(260,260,0,0);
    c.setGeometry(1260,260,0,0);
    b.setVisibleGoalkeeper(true);
    b.setVisibleDefender(true);
    b.setVisibleMidfielder(true);
    b.setVisibleAttacker(true);
    b.setVisibleChosenTeam(false);
    b.setColorGoalkeeper();
    b.setVisibleSimulateButton(false);
    b.setOKUnclickable();

    return a.exec();
}
