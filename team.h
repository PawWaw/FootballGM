#ifndef _TEAM_H_
#define _TEAM_H_

#include <string>
using namespace std;

class Team
{
protected:

    friend ostream& operator<< (ostream& os, const Team& foo);

public:
    // constructors
    Team();
    Team(const Team &team);
    Team(string name, string stadium, string city, int power, int streak, int wins, int draws, int losses, int points);

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
    //Team Simulation(static Team&, static Team&);
    //Team SimulateMatch(static Team&, static Team&);
    string stadium;
    string city;
    int power = 100;
    char * imageData = nullptr;
    Team * next;
    Team * prev;
    int wins = 0;
    int draws = 0;
    int losses = 0;
    int points = 0;
    float streak = 1;
    string name;
};

#endif


