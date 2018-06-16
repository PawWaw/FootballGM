#ifndef SIMULATION_H
#define SIMULATION_H
#include "team.h"
#include "subwindow.h"

class simulation
{
private:
    SubWindow& subWindowRef;
    MainWindow& mainWindowRef;

public:
    simulation(SubWindow &subWindow, MainWindow &mainWindow);
    void MakeSeason();
    Team Simulation(Team& team1, Team& team2);
    Team SimulateMatch(Team& team1, Team& team2);
    void addmatch(Team& team, Team& team1, Team& team10);
    void addresult(Team& team, Team& team1);
};

#endif // SIMULATION_H
