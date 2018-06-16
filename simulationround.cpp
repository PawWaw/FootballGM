#include "simulationround.h"
#include "statistics.h"
#include "subwindow.h"
#include "ui_subwindow.h"
#include <QString>
#include <QTime>
#include <QLCDNumber>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QQuickStyle>
#include <QEventLoop>
#include <QCoreApplication>
#include <QWidget>
#include <windows.h>
#include "database.h"



simulationround::simulationround(SubWindow &subWindow, MainWindow &mainWindow) :
                       subWindowRef(subWindow), mainWindowRef(mainWindow)
{

}


void simulationround::addmatch(Team& team, Team& team1, Team& team10)
{
    SimulateMatch(team1, team10);
    team = team1;
    team1.points = team.points;

}

void simulationround::addresult(Team& team, Team& team1)
{
    team.wins += team1.wins;
    team.draws += team1.draws;
    team.losses += team1.losses;
    team.points += team1.points;
    team.streak = team1.streak;
    team1.points = team.points;
}


void simulationround::MakeSeason(int j)
{
        Statistics table;
        Team * head = nullptr;
        Team team10;
        Team t;
        int temp;
        team10 = DataBase::Teams[19];
        int h;
        string txt;
                DataBase::Teams[15].HealInjury();
                DataBase::Teams[15].power = t.CalculateUserPower(DataBase::Teams[15].power);
                Team team1;
                Team team2;
                Team team3;
                for(int k = 0; k < 20; k++)
                {
                    if (k == j)
                    {
                        team3 = DataBase::Teams[j];
                        addmatch(DataBase::Teams[j], team3, team10);
                    }
                }
                DataBase::Teams[19] = team10;
                team10.points = DataBase::Teams[19].points;
                QString s = QString::number(team3.points);
                QString xxx = team3.name + " have " + s + " point(s).";
                subWindowRef.setText1(xxx);
                QString z = QString::number(team10.points);
                QString xxx2 = team10.name + " have " + z + " point(s).";
                subWindowRef.setText2(xxx2);
                QTime dieTime= QTime::currentTime().addSecs(1);
                    while (QTime::currentTime() < dieTime)
                        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
                a++;
                for (int w = 1; w < 10; w++)
                {
                    p = j - w;
                    if (p < 0)
                    {
                        p = 19 + p;
                    }
                    for(int l = 0; l < 20; l++)
                    {
                        if (l == p)
                        {
                            team1 = DataBase::Teams[p];
                        }
                    }

                    r = j + w;
                    if (r >= k)
                        r = r - 19;
                    for(int m = 0; m < 20; m++)
                    {
                        if (m == r)
                        {
                             team2 = DataBase::Teams[r];
                        }
                    }
                    if(team1.name == "My Team")
                    {
                        temp = team2.power;
                        team2.power = t.CalculateOpponentPower(team2.power);
                        team2.power = temp;
                    }
                    SimulateMatch(team1, team2);
                    for(int h = 0; h < 20; h++)
                    {
                        if (h == p)
                        {
                            DataBase::Teams[p] = team1;
                        }
                    }
                    for(int g = 0; g < 20; g++)
                    {
                        if (g == r)
                        {
                           DataBase::Teams[r] = team2;
                        }
                    }
                    QString x = QString::number(team1.points);
                    QString xxx3 = team1.name + " have " + x + " point(s).";
                    subWindowRef.setText1(xxx3);

                    QString d = QString::number(team2.points);
                    QString xxx4 = team2.name + " have " + d + " point(s).";
                    subWindowRef.setText2(xxx4);

                    if (a == 190)
                        break;
                    a++;
                    QTime dieTime= QTime::currentTime().addSecs(1);
                        while (QTime::currentTime() < dieTime)
                            QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
                }
                DataBase::Teams[15].SetTeamFitness();
                DataBase::Teams[15].SetTeamInjury();
                DataBase::Clone.assign(DataBase::Teams.begin(), DataBase::Teams.end());
                sort(DataBase::Clone.begin(), DataBase::Clone.end(), less_than_key());
                mainWindowRef.printtable();
}

bool Team::sorting (Team& team1, Team& team2)
{
    return (team1.points < team2.points);
}


Team simulationround::SimulationRound(Team& team1, Team& team2)
{
    srand(time(NULL));
    int winner = rand() % (team1.power + team2.power) + (0 - team2.power);
    QString xxx6;
    if (winner > 20)
    {
        xxx6 = team1.name + " won with " + team2.name + " on " + team1.stadium + " in " + team1.city + ".";
        subWindowRef.setText3(xxx6);
        team1.wins++;
        team1.streak++;
        team1.points = team1.points + 3;
        team2.losses++;
        team2.streak = 1;
        return team1;
    }
    if (winner <= 20 && winner > -20)
    {
        xxx6 = team1.name + " draw with " + team2.name + " on " + team1.stadium + " in " + team1.city + ".";
        subWindowRef.setText3(xxx6);
        team1.draws++;
        team1.streak = 2;
        team2.draws++;
        team2.streak = 2;
        team1.points = team1.points + 1;
        team2.points = team2.points + 1;
        return team1;
    }
    if (winner <= -20)
    {
        xxx6 = team2.name + " won with " + team1.name + " on " + team1.stadium + " in " + team1.city + ".";
        subWindowRef.setText3(xxx6);
        team2.wins++;
        team2.streak++;
        team2.points = team2.points + 3;
        team1.losses++;
        team1.streak = 1;
        return team2;
    }
}

Team simulationround::SimulateMatch(Team& team1, Team& team2)
{
    Team ClonedTeam1 = team1;
    ClonedTeam1.name = team1.name;
    ClonedTeam1.stadium = team1.stadium;
    ClonedTeam1.city = team1.city;
    ClonedTeam1.power = team1.power;
    ClonedTeam1.imageData = team1.imageData;
    ClonedTeam1.streak = team1.streak;
    ClonedTeam1.wins = team1.wins;
    ClonedTeam1.draws = team1.draws;
    ClonedTeam1.losses = team1.losses;
    ClonedTeam1.points = team1.points;
    Team ClonedTeam2 = team2;
    ClonedTeam2.name = team2.name;
    ClonedTeam2.stadium = team2.stadium;
    ClonedTeam2.city = team2.city;
    ClonedTeam2.power = team2.power;
    ClonedTeam2.imageData = team2.imageData;
    ClonedTeam2.streak = team2.streak;
    ClonedTeam2.wins = team1.wins;
    ClonedTeam2.draws = team1.draws;
    ClonedTeam2.losses = team1.losses;
    ClonedTeam2.points = team1.points;
    float pwr1 = ClonedTeam1.power;
    float pwr2 = ClonedTeam2.power;
    ClonedTeam1.power = ClonedTeam1.SetPower(ClonedTeam1.power * (1 + (ClonedTeam1.streak - 1) / 10));
    ClonedTeam2.power = ClonedTeam2.SetPower(ClonedTeam2.power * (1 + (ClonedTeam2.streak - 1) / 10));
    SimulationRound(ClonedTeam1, ClonedTeam2);
    ClonedTeam1.power = pwr1;
    ClonedTeam2.power = pwr2;
    team1 = ClonedTeam1;

    team2 = ClonedTeam2;

    return team1;
}
