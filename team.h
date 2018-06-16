#ifndef _TEAM_H_
#define _TEAM_H_

#include <string>
#include <QString>
using namespace std;

class Team
{
protected:

    friend ostream& operator<< (ostream& os, const Team& foo);

public:
    // constructors
    Team();
    Team(QString name, QString stadium, QString city, int power, int streak, int wins, int draws, int losses, int points);

    // setters
    int SetPower(int);
    int SetWins(int);
    int SetDraws(int);
    int SetLosses(int);

    // getters
    string GetInfo();
    string GetName() const;
    string GetStadium() const;
    string GetCity() const;
    int GetPower() const;
    int GetWins() const;
    int GetDraws() const;
    int GetLosses() const;
    float WinStreak(float);

    // operators
    Team& operator= (const Team& team);

    // other
    void PrintInfo();
    Team Simulation(Team&, Team&);
    Team SimulateMatch(Team&, Team&);
    int CalculateUserPower(int MyPower);
    int CalculateOpponentPower(int EnemyPower);
    int SetTeamFitness();
    void SetTeamInjury();
    void HealInjury();
    bool sorting(Team& team1, Team& team2);
    QString stadium;
    QString city;
    int power;
    char * imageData = nullptr;
    Team * next;
    Team * prev;
    int wins;
    int draws;
    int losses;
    int points;
    float streak;
    QString name;
};

#endif


