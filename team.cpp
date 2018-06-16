#include "stdafx.h"
#include "Team.h"
#include <iostream>
#include <thread>
#include <stdlib.h>
#include <string>
#include "database.h"
#include <string>
#include <subwindow.h>
#include <windows.h>
#include <ui_subwindow.h>

using namespace std;

Team::Team()
{

}

Team::Team(QString name2, QString stadium2, QString city2, int power2, int streak2, int wins2, int draws2, int losses2, int points2)
{
    name = name2;
    stadium = stadium2;
    city = city2;
    power = power2;
    points = points2;
    wins = wins2;
    draws = draws2;
    losses = losses2;
    streak = streak2;
}

// setters
int Team::SetPower(int power)
{
    if (power > 0)
        this->power = power;
    else {
        this->power = 0;
        cout << GetName() << " power modified to " << this->power << " by setter function" << endl;
    }
    return power;
}

int Team::SetWins(int wins)
{
    if (wins >= 0)
        this->wins = wins;
    else {
        this->wins = 0;
        cout << GetName() << " wins number modified to " << this->wins << " by setter function" << endl;
    }
    return wins;
}

int Team::SetDraws(int draws)
{
    if (draws >= 0)
        this->draws = draws;
    else {
        this->draws = 0;
        cout << GetName() << " draws number modified to " << this->draws << " by setter function" << endl;
    }
    return draws;
}

int Team::SetLosses(int losses)
{
    if (losses >= 0)
        this->losses = losses;
    else {
        this->losses = 0;
        cout << GetName() << " losses number modified to " << this->losses << " by setter function" << endl;
    }
    return losses;
}

// getters

string Team::GetName() const
{
    //return name.empty() ? "Anonymous" : name;
}

string Team::GetStadium() const
{
    //return stadium.empty() ? "Anonymous" : name;
}

string Team::GetCity() const
{
    //return city.empty() ? "Anonymous" : name;
}

int Team::GetPower() const
{
    return power;
}

int Team::GetWins() const
{
    return wins;
}

int Team::GetDraws() const
{
    return draws;
}

int Team::GetLosses() const
{
    return losses;
}

float Team::WinStreak(float streak)
{
    return streak;
}

// operatory
Team& Team::operator=(const Team& team) {
    this->name = team.name;
    this->stadium = team.stadium;
    this->city = team.city;
    this->power = team.power;
    this->points = team.points;
    this->wins = team.wins;
    this->draws = team.draws;
    this->losses = team.losses;
    this->streak = team.streak;
    return *this;
}

// other
string Team::GetInfo()
{
    string imageDesc = imageData ? imageData : "no data";
    return imageDesc;
}

void Team::PrintInfo()
{
    cout << GetInfo() << endl;
}




std::ostream& operator<< (std::ostream& os, const Team& team)
{
    os << team.GetName();
    return os;
}


int Team::CalculateUserPower(int MyPower)                               // ustawienie siły wybranej drużyny
{
    int flag1 = 0;
    int flag2 = 0;

    for (int i = 0; i < DataBase::InGamePlayers.size(); i++)
    {
        if (DataBase::InGamePlayers[i].position == "Midfielder" && flag1 < 3)
        {
            MyPower = MyPower + (DataBase::InGamePlayers[i].specificstat1 + DataBase::InGamePlayers[i].specificstat2 + DataBase::InGamePlayers[i].specificstat3)/10 * DataBase::InGamePlayers[i].fitness/100;
            flag1++;
        }

        if (DataBase::InGamePlayers[i].position == "Attacker" && flag2 < 4)
        {
            MyPower = MyPower + (DataBase::InGamePlayers[i].specificstat1 + DataBase::InGamePlayers[i].specificstat2 + DataBase::InGamePlayers[i].specificstat3)/10 * DataBase::InGamePlayers[i].fitness/100;
            flag2++;
        }
    }

    return MyPower;
}

int Team::CalculateOpponentPower(int EnemyPower)                        // ustawienie siły przeciwnika
{
    int flag = 0;
    for (int i = 0; i < DataBase::InGamePlayers.size(); i++)
    {
        if (DataBase::InGamePlayers[i].position == "Goalkeeper" && flag == 0)
        {
            EnemyPower = EnemyPower - (DataBase::InGamePlayers[i].specificstat1 + DataBase::InGamePlayers[i].specificstat2 + DataBase::InGamePlayers[i].specificstat3)/10*DataBase::InGamePlayers[i].fitness/100;
            flag = 1;
        }

        if (DataBase::InGamePlayers[i].position == "Defender")
        {
             EnemyPower = EnemyPower - (DataBase::InGamePlayers[i].specificstat1 + DataBase::InGamePlayers[i].specificstat2 + DataBase::InGamePlayers[i].specificstat3)/10*DataBase::InGamePlayers[i].fitness/100;
        }
    }
    return EnemyPower;
}

int Team::SetTeamFitness()                                              // ustawienie kondycji wybranej drużyny
{
    for (int i = 0; i < DataBase::InGamePlayers.size(); i++)
    {
        DataBase::InGamePlayers[i].fitness = DataBase::InGamePlayers[i].SetFitness();
    }
}

void Team::SetTeamInjury()                                              // ustawienie kontuzji wybranej drużyny
{
    srand(time(NULL));
    for (int i = 0; i < DataBase::InGamePlayers.size(); i++)
    {
        int injury = rand() % 100;
        if (injury >= 96)
        {
            DataBase::InGamePlayers[i].injury = 1;
            DataBase::InGamePlayers[i].fitness *= 0.5;
        }
        else
            DataBase::InGamePlayers[i].injury = 0;

    }
}

void Team::HealInjury()                                                 // leczeniekontuzji
{
    for (int i = 0; i < DataBase::chosen.size(); i++)
    {
        srand(time(NULL));
        int injury = rand() % 100;
        if (injury >= 50 && DataBase::chosen[i].injury == 1)
        {
            DataBase::chosen[i].injury = 0;
            DataBase::chosen[i].fitness *= 2;
        }
    }
}
