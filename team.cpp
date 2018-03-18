#include "stdafx.h"
#include "Team.h"
#include <iostream>
#include <thread>
#include <stdlib.h>
#include <string>

using namespace std;

Team::Team()
{
}

Team::Team(const Team &team)
{
    if (team.imageData)		// != nullptr
    {
        cout << "Constructor [copy]: copying image " << team.imageData << " it will last 5s" << endl;
      //imageData = new char[strlen(team.imageData) + 1];
      //memcpy(imageData, team.imageData, strlen(team.imageData) + 1);
        this_thread::sleep_for(chrono::seconds(5));
    }
}

Team::Team(string name, string stadium, string city, int power, int streak, int wins, int draws, int losses, int points) : name(name), stadium(stadium), city(city), power(power), streak(streak), wins(wins), draws(draws), losses(losses), points(points)
{
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
    return name.empty() ? "Anonymous" : name;
}

string Team::GetStadium() const
{
    return stadium.empty() ? "Anonymous" : name;
}

string Team::GetCity() const
{
    return city.empty() ? "Anonymous" : name;
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

    if (imageData) {
        delete[]imageData;
        imageData = nullptr;
    }
    if (team.imageData)
    {
        //imageData = new char[strlen(team.imageData) + 1];
      //memcpy(imageData, team.imageData, strlen(team.imageData) + 1);
    }

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

//Team Team::Simulation(static Team& team1, static Team& team2)
//{
//    srand(time(NULL));
//    int winner = rand() % (team1.power + team2.power) + (0 - team2.power);
//    if (winner > 20)
//    {
//        cout << team1.name << " won with " << team2.name << " on " << team1.stadium << " in " << team1.city << "." << endl;
//        team1.wins++;
//        team1.streak++;
//        team1.points = team1.points + 3;
//        team2.losses++;
//        team2.streak = 1;
//        return team1;
//    }
//    if (winner <= 20 && winner > -20)
//    {
//        cout << team1.name << " draw with " << team2.name << " on " << team1.stadium << " in " << team1.city << "." << endl;
//        team1.draws++;
//        team1.streak = 2;
//        team2.draws++;
//        team2.streak = 2;
//        team1.points = team1.points + 1;
//        team2.points = team2.points + 1;
//        return team1;
//    }
//    if (winner <= -20)
//    {
//        cout << team2.name << " won with " << team1.name << " on " << team1.stadium << " in " << team1.city << "." << endl;
//        team2.wins++;
//        team2.streak++;
//        team2.points = team2.points + 3;
//        team1.losses++;
//        team1.streak = 1;
//        return team2;
//    }
//}

//Team Team::SimulateMatch(static Team& team1, static Team& team2)
//{
//    Team ClonedTeam1 = team1;
//    ClonedTeam1.name = team1.name;
//    ClonedTeam1.stadium = team1.stadium;
//    ClonedTeam1.city = team1.city;
//    ClonedTeam1.power = team1.power;
//    ClonedTeam1.imageData = team1.imageData;
//    ClonedTeam1.streak = team1.streak;
//    ClonedTeam1.wins = team1.wins = 0;
//    ClonedTeam1.draws = team1.draws = 0;
//    ClonedTeam1.losses = team1.losses = 0;
//    ClonedTeam1.points = team1.points = 0;
//    Team ClonedTeam2 = team2;
//    ClonedTeam2.name = team2.name;
//    ClonedTeam2.stadium = team2.stadium;
//    ClonedTeam2.city = team2.city;
//    ClonedTeam2.power = team2.power;
//    ClonedTeam2.imageData = team2.imageData;
//    ClonedTeam2.streak = team2.streak;
//    ClonedTeam2.wins = team1.wins;
//    ClonedTeam2.draws = team1.draws;
//    ClonedTeam2.losses = team1.losses;
//    ClonedTeam2.points = team1.points;
//    float pwr1 = ClonedTeam1.power;
//    float pwr2 = ClonedTeam2.power;
//    ClonedTeam1.power = ClonedTeam1.SetPower(ClonedTeam1.power * (1 + (ClonedTeam1.streak - 1) / 10));
//    ClonedTeam2.power = ClonedTeam2.SetPower(ClonedTeam2.power * (1 + (ClonedTeam2.streak - 1) / 10));
//    Simulation(ClonedTeam1, ClonedTeam2);
//    ClonedTeam1.power = pwr1;
//    ClonedTeam2.power = pwr2;
//    team1 = ClonedTeam1;
//    team1.wins = ClonedTeam1.wins;
//    team1.draws = ClonedTeam1.draws;
//    team1.losses = ClonedTeam1.losses;
//    team1.points = ClonedTeam1.points;
//    team1.streak = ClonedTeam1.streak;
//    team2 = ClonedTeam2;
//    team2.wins = ClonedTeam2.wins;
//    team2.draws = ClonedTeam2.draws;
//    team2.losses = ClonedTeam2.losses;
//    team2.points = ClonedTeam2.points;
//    team2.streak = ClonedTeam2.streak;
//    return team1;
//}

std::ostream& operator<< (std::ostream& os, const Team& team)
{
    os << team.GetName();
    return os;
}
