#ifndef SIMULATIONROUND_H
#define SIMULATIONROUND_H
#include "team.h"
#include "subwindow.h"
#include "mainwindow.h"

class simulationround
{
private:
    SubWindow& subWindowRef;
    MainWindow& mainWindowRef;
public:
    simulationround(SubWindow &subWindow, MainWindow &mainWindow);
    void MakeSeason(int j);
    Team SimulationRound(Team& team1, Team& team2);
    Team SimulateMatch(Team& team1, Team& team2);
    void addmatch(Team& team, Team& team1, Team& team10);
    void addresult(Team& team, Team& team1);



    int n = 0;
    int k = 19;
    int p, r;
    int a = 1;
};

struct less_than_key
{
    inline bool operator() (const Team& struct1, const Team& struct2)
    {
        return (struct1.points > struct2.points);
    }
};

#endif // SIMULATIONROUND_H
