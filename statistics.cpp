#include "Team.h"
#include "Statistics.h"
#include "stdafx.h"
#include <iostream>
#include <thread>
#include <Windows.h>
//do edycji (za mało danych)
void addteam(Team *& head, string name, string stadium, string city, int power, int streak, int wins, int draws, int losses, int points)
{
    Team* tmp = new Team;
    tmp->name = name;
    tmp->stadium = stadium;
    tmp->city = city;
    tmp->power = power;
    tmp->streak = streak;
    tmp->wins = wins;
    tmp->draws = draws;
    tmp->losses = losses;
    tmp->points = points;
    tmp->next = nullptr;
    tmp->prev = nullptr;

    if (head == nullptr) {
        head = tmp;
    }
    else {
        tmp->next = head;
        tmp->prev = nullptr;
        head->prev = tmp;
        head = tmp;
    }
}

//do usunięcia/edycji
Statistics& Statistics::createtable(Team& team1, Team& team2, Team& team3, Team& team4, Team& team5, Team& team6, Team& team7, Team& team8, Team& team9,
    Team& team10, Team& team11, Team& team12, Team& team13, Team& team14, Team& team15, Team& team16, Team& team17, Team& team18, Team& team19, Team& team20)
{
    tab1[0] = "Arsenal\t\t"; tab2[0][0] = team1.wins; tab2[0][1] = team1.draws; tab2[0][2] = team1.losses; tab2[0][3] = team1.points;
    tab1[1] = "Bournemouth\t"; tab2[1][0] = team2.wins; tab2[1][1] = team2.draws; tab2[1][2] = team2.losses; tab2[1][3] = team2.points;
    tab1[2] = team3.name; tab2[2][0] = team3.wins; tab2[2][1] = team3.draws; tab2[2][2] = team3.losses; tab2[2][3] = team3.points;
    tab1[3] = "Burnley\t\t"; tab2[3][0] = team4.wins; tab2[3][1] = team4.draws; tab2[3][2] = team4.losses; tab2[3][3] = team4.points;
    tab1[4] = "Chelsea\t\t"; tab2[4][0] = team5.wins; tab2[4][1] = team5.draws; tab2[4][2] = team5.losses; tab2[4][3] = team5.points;
    tab1[5] = "Crystal Palace\t"; tab2[5][0] = team6.wins; tab2[5][1] = team6.draws; tab2[5][2] = team6.losses; tab2[5][3] = team6.points;
    tab1[6] = "Everton\t\t"; tab2[6][0] = team7.wins; tab2[6][1] = team7.draws; tab2[6][2] = team7.losses; tab2[6][3] = team7.points;
    tab1[7] = "Huddersfield\t"; tab2[7][0] = team8.wins; tab2[7][1] = team8.draws; tab2[7][2] = team8.losses; tab2[7][3] = team8.points;
    tab1[8] = "Leicester\t"; tab2[8][0] = team9.wins; tab2[8][1] = team9.draws; tab2[8][2] = team9.losses; tab2[8][3] = team9.points;
    tab1[9] = "Liverpool\t"; tab2[9][0] = team10.wins; tab2[9][1] = team10.draws; tab2[9][2] = team10.losses; tab2[9][3] = team10.points;
    tab1[10] = "Manchester City\t"; tab2[10][0] = team11.wins; tab2[10][1] = team11.draws; tab2[10][2] = team11.losses; tab2[10][3] = team11.points;
    tab1[11] = team12.name; tab2[11][0] = team12.wins; tab2[11][1] = team12.draws; tab2[11][2] = team12.losses; tab2[11][3] = team12.points;
    tab1[12] = "Newcastle\t"; tab2[12][0] = team13.wins; tab2[12][1] = team13.draws; tab2[12][2] = team13.losses; tab2[12][3] = team13.points;
    tab1[13] = "Stoke\t\t"; tab2[13][0] = team14.wins; tab2[13][1] = team14.draws; tab2[13][2] = team14.losses; tab2[13][3] = team14.points;
    tab1[14] = "Southampton\t"; tab2[14][0] = team15.wins; tab2[14][1] = team15.draws; tab2[14][2] = team15.losses; tab2[14][3] = team15.points;
    tab1[15] = "Swansea\t\t"; tab2[15][0] = team16.wins; tab2[15][1] = team16.draws; tab2[15][2] = team16.losses; tab2[15][3] = team16.points;
    tab1[16] = "Tottenham\t"; tab2[16][0] = team17.wins; tab2[16][1] = team17.draws; tab2[16][2] = team17.losses; tab2[16][3] = team17.points;
    tab1[17] = "Watford\t\t"; tab2[17][0] = team18.wins; tab2[17][1] = team18.draws; tab2[17][2] = team18.losses; tab2[17][3] = team18.points;
    tab1[18] = team19.name; tab2[18][0] = team19.wins; tab2[18][1] = team19.draws; tab2[18][2] = team19.losses; tab2[18][3] = team19.points;
    tab1[19] = "West Ham United\t"; tab2[19][0] = team20.wins; tab2[19][1] = team20.draws; tab2[19][2] = team20.losses; tab2[19][3] = team20.points;

    return *this;
}

Statistics& Statistics::sort()
{
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 19; j++)
        {
            if (tab2[j][3] < tab2[j + 1][3])
            {
                swap(tab2[j], tab2[j + 1]);
                swap(tab1[j], tab1[j + 1]);
            }
        }
    }
    return *this;
}

Statistics& Statistics::tabledisplay(int h)
{
    sort();
    cout << "Name:" << "\t\t\t" << "Wins:" << "\t" << "Draws:" << "\t" << "Losses:" << "\t" << "Points:" << endl;
    cout << "-------------------------------------------------------" << endl;
    for (int i = 0; i < 20; i++)
        cout << tab1[i] << "\t" << tab2[i][0] << "\t" << tab2[i][1] << "\t" << tab2[i][2] << "\t" << tab2[i][3] << endl;
    if (h == 2)
    {
        cout << endl;
        cout << "Champions: " << tab1[0] << endl;
        cout << "Runner-Up: " << tab1[1] << endl;
        cout << "Third place: " << tab1[2] << endl << endl;

        cout << "Relegated: " << endl;
        cout << tab1[17] << endl;
        cout << tab1[18] << endl;
        cout << tab1[19] << endl;
    }
    return *this;
}

Statistics& Statistics::datadisplay(Team*& head)
{
    cout << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "Give the name of team, whose data you want to see:" << endl << endl;
    cin >> Team::name;
    Team * tmp = head;
    while (tmp)
    {
        if (Team::name == tmp->name)
        {
            cout << "Data about " << tmp->name << ":" << endl;
            cout << "City: " << tmp->city << endl;
            cout << "Stadium: " << tmp->stadium << endl;
            cout << "Quality (0 - 200): " << tmp->power << endl;
            cout << "Wins: " << tmp->wins << endl;
            cout << "Draws: " << tmp->draws << endl;
            cout << "Losses: " << tmp->losses << endl;
            cout << "Points: " << tmp->points << endl;
        }
        tmp = tmp->next;
    }
    return *this;
}

// do usunięcia/edycji
Statistics& Statistics::Fullfilling(Team *& head, Team& team1, Team& team2, Team& team3, Team& team4, Team& team5, Team& team6, Team& team7, Team& team8, Team& team9,
    Team& team10, Team& team11, Team& team12, Team& team13, Team& team14, Team& team15, Team& team16, Team& team17, Team& team18, Team& team19, Team& team20)
{
    addteam(head, "Arsenal", "Emirates", "London", Team::SetPower(team1.power), Team::WinStreak(team1.streak), Team::SetWins(team1.wins), Team::SetDraws(team1.draws), Team::SetLosses(team1.losses), team1.points);
    addteam(head, "Bournemouth", "Vitality Stadium", "Bournemouth", Team::SetPower(team2.power), Team::WinStreak(team2.streak), Team::SetWins(team2.wins), Team::SetDraws(team2.draws), Team::SetLosses(team2.losses), team2.points);
    addteam(head, "Brighton & Hove Albion", "Falmer Stadium", "Brighton", Team::SetPower(team3.power), Team::WinStreak(team3.streak), Team::SetWins(team3.wins), Team::SetDraws(team3.draws), Team::SetLosses(team3.losses), team3.points);
    addteam(head, "Burnley", "Turf Moor", "Burnley", Team::SetPower(team4.power), Team::WinStreak(team4.streak), Team::SetWins(team4.wins), Team::SetDraws(team4.draws), Team::SetLosses(team4.losses), team4.points);
    addteam(head, "Chelsea", "Stamford Bridge", "London", Team::SetPower(team5.power), Team::WinStreak(team5.streak), Team::SetWins(team5.wins), Team::SetDraws(team5.draws), Team::SetLosses(team5.losses), team5.points);
    addteam(head, "Crystal Palace", "Selhurst Park", "London", Team::SetPower(team6.power), Team::WinStreak(team6.streak), Team::SetWins(team6.wins), Team::SetDraws(team6.draws), Team::SetLosses(team6.losses), team6.points);
    addteam(head, "Everton", "Goodison Park", "Liverpool", Team::SetPower(team7.power), Team::WinStreak(team7.streak), Team::SetWins(team7.wins), Team::SetDraws(team7.draws), Team::SetLosses(team7.losses), team7.points);
    addteam(head, "Huddersfield", "John Smith's Stadium", "Huddersfield", Team::SetPower(team8.power), Team::WinStreak(team8.streak), Team::SetWins(team8.wins), Team::SetDraws(team8.draws), Team::SetLosses(team8.losses), team8.points);
    addteam(head, "Leicester", "King Power Stadium", "Leicester", Team::SetPower(team9.power), Team::WinStreak(team9.streak), Team::SetWins(team9.wins), Team::SetDraws(team9.draws), Team::SetLosses(team9.losses), team9.points);
    addteam(head, "Liverpool", "Anfield", "Liverpool", Team::SetPower(team10.power), Team::WinStreak(team10.streak), Team::SetWins(team10.wins), Team::SetDraws(team10.draws), Team::SetLosses(team10.losses), team10.points);
    addteam(head, "Manchester City", "Etihad", "Manchester", Team::SetPower(team11.power), Team::WinStreak(team11.streak), Team::SetWins(team11.wins), Team::SetDraws(team11.draws), Team::SetLosses(team11.losses), team11.points);
    addteam(head, "Manchester United", "Old Trafford", "Manchester", Team::SetPower(team12.power), Team::WinStreak(team12.streak), Team::SetWins(team12.wins), Team::SetDraws(team12.draws), Team::SetLosses(team12.losses), team12.points);
    addteam(head, "Newcastle", "St James's Park", "Newcastle", Team::SetPower(team13.power), Team::WinStreak(team13.streak), Team::SetWins(team13.wins), Team::SetDraws(team13.draws), Team::SetLosses(team13.losses), team13.points);
    addteam(head, "Stoke", "Britannia Stadium", "Stoke-on-Trent", Team::SetPower(team14.power), Team::WinStreak(team14.streak), Team::SetWins(team14.wins), Team::SetDraws(team14.draws), Team::SetLosses(team14.losses), team14.points);
    addteam(head, "Southampton", "St Mary's Stadium", "Southampton", Team::SetPower(team15.power), Team::WinStreak(team15.streak), Team::SetWins(team15.wins), Team::SetDraws(team15.draws), Team::SetLosses(team15.losses), team15.points);
    addteam(head, "Swansea", "Liberty Stadium", "Swansea", Team::SetPower(team16.power), Team::WinStreak(team16.streak), Team::SetWins(team16.wins), Team::SetDraws(team16.draws), Team::SetLosses(team16.losses), team16.points);
    addteam(head, "Tottenham", "Wembley", "London", Team::SetPower(team17.power), Team::WinStreak(team17.streak), Team::SetWins(team17.wins), Team::SetDraws(team17.draws), Team::SetLosses(team17.losses), team17.points);
    addteam(head, "Watford", "Vicarage Road", "Watford", Team::SetPower(team18.power), Team::WinStreak(team18.streak), Team::SetWins(team18.wins), Team::SetDraws(team18.draws), Team::SetLosses(team18.losses), team18.points);
    addteam(head, "West Bromwich Albion", "The Hawthorns", "West Bromwich", Team::SetPower(team19.power), Team::WinStreak(team19.streak), Team::SetWins(team19.wins), Team::SetDraws(team19.draws), Team::SetLosses(team19.losses), team19.points);
    addteam(head, "West Ham United", "London Stadium", "London", Team::SetPower(team20.power), Team::WinStreak(team20.streak), Team::SetWins(team20.wins), Team::SetDraws(team20.draws), Team::SetLosses(team20.losses), team20.points);

    return *this;
}
