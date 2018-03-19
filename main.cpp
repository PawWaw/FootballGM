#include "mainwindow.h"
#include "subwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    SubWindow b;
    b.show();
    b.setVisibleGoalkeeper(true);
    b.setVisibleDefender(true);
    b.setVisibleMidfielder(true);
    b.setVisibleAttacker(true);

    b.on_Goalkeeper1_ChB_clicked();

    return a.exec();
}
