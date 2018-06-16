#include "database.h"
#include <fstream>
#include <istream>
#include <ostream>
#include <iostream>
#include <string>

std::vector<PlayerInfo> DataBase::playerz;
std::vector<PlayerInfo> DataBase::chosen;
std::vector<PlayerInfo> DataBase::InGamePlayers;
std::vector<Team> DataBase::Teams;
std::vector<Team> DataBase::Clone;

using namespace std;

DataBase::DataBase()
{

}

DataBase::~DataBase()
{

}

PlayerInfo::PlayerInfo(QString name, float height, int age, QString nationality, float injury2, float fitness2, float quality2,
         float price2, int chemistry2, QString position2, float strength2, int specificstat12, int specificstat22,
         int specificstat32) : Player(name, height, age, nationality, injury2, fitness2,
         quality2, price2, chemistry2, position2, strength2, specificstat12, specificstat22, specificstat32)
{

}

PlayerInfo::~PlayerInfo()
{

}

void DataBase::loadDataBase()                   // załadowanie bazy danych zawodników i drużyn
{
    ifstream f ("teams.txt");
    string k = "1", m, n, o, p, r, s, t, u, v, w, x, y, z;
    if(!f.is_open())
        return;
    QString k1, m1, n1, v1;
    int o1, p1, r1, s1, t1, u1, w1, x1, y1, z1;
    if(f.is_open())
    {
        for(int i = 0; i < 20; i++)
        {
            getline(f, k);
            k1 = QString::fromStdString(k);

            getline(f, m);
            m1 = QString::fromStdString(m);
            getline(f, n);
            n1 = QString::fromStdString(n);
            getline(f, o);
            o1 = std::stoi(o);
            getline(f, p);
            p1 = std::stoi(p);
            getline(f, r);
            r1 = std::stoi(r);
            getline(f, s);
            s1 = std::stoi(s);
            getline(f, t);
            t1 = std::stoi(t);
            getline(f, u);
            u1 = std::stoi(u);
            Teams.push_back({k1, m1, n1, o1, p1, r1, s1, t1, u1});

        }
    }
    else
    {
        exit(0);
    }

    fstream h;
    h.open("players.txt");
    float m2, t2;
    if(h.is_open())
    {
        for(int i = 0; i < 60; i++)
        {
            std::getline(h, k);
            k1 = QString::fromStdString(k);
            std::getline(h, m);
            m2 = stof(m);
            std::getline(h, n);
            o1 = stoi(n);
            std::getline(h, o);
            m1 = QString::fromStdString(o);
            std::getline(h, p);
            p1 = stoi(p);
            std::getline(h, r);
            r1 = stoi(r);
            std::getline(h, s);
            s1 = stoi(s);
            std::getline(h, t);
            t2 = stof(t);
            std::getline(h, u);
            u1 = stoi(u);
            std::getline(h, v);
            v1 = QString::fromStdString(v);
            std::getline(h, w);
            w1 = stoi(w);
            std::getline(h, x);
            x1 = stoi(x);
            std::getline(h, y);
            y1 = stoi(y);
            std::getline(h, z);
            z1 = stoi(z);
            DataBase::playerz.push_back({k1, m2, o1, m1, p1, r1, s1, t2, u1, v1, w1, x1, y1, z1});
        }
    }
    else
    {
        exit(0);
    }
/*
David De Gea", 1.93, 27, "Spain", 0, 100, 90, 31.2, 10, "Goalkeeper", 70, 90, 90, 86});
Ederson Moraes", 1.88, 24, "Brazil", 0, 100, 84, 28.3, 10, "Goalkeeper", 70, 81, 87, 79});
Nick Pope", 1.92, 26, "England", 0, 100, 75, 24.8, 10, "Goalkeeper", 70, 76, 77, 74});
Rob Elliot", 1.90, 32, "Ireland", 0, 100, 69, 20.2, 10, "Goalkeeper", 70, 69, 68, 69});
Asmir Begovic", 1.99, 30, "Bosnia", 0, 100, 82, 22.7, 10, "Goalkeeper", 70, 81, 82, 79});
Loris Karius", 1.89, 24, "Germany", 0, 100, 80, 24.2, 10, "Goalkeeper", 70, 84, 85, 76});
Martin Dubravka", 1.91, 29, "Slovakia", 0, 100, 74, 22.0, 10, "Goalkeeper", 70, 80, 78, 70});
Thibaout Courtois", 1.99, 26, "Belgium", 0, 100, 89, 27.3, 10, "Goalkeeper", 70, 85, 88, 86});
Petr Cech", 1.96, 36, "Czech Republic", 0, 100, 86, 26.7, 10, "Goalkeeper", 70, 82, 81, 83});
Lukasz Fabianski", 1.90, 33, "Poland", 0, 100, 80, 23.8, 10, "Goalkeeper", 70, 77, 84, 78});
Matthew Ryan", 1.84, 26, "Australia", 0, 100, 77, 22.8, 10, "Goalkeeper", 70, 76, 78, 74});
Jordan Pickford", 1.85, 24, "England", 0, 100, 79, 24.8, 10, "Goalkeeper", 70, 79, 83, 74});
Jonas Lossl", 1.95, 29, "Denmark", 0, 100, 75, 23.2, 10, "Goalkeeper", 70, 74, 77, 71});
Jack Butland", 1.96, 25, "England", 0, 100, 81, 25.2, 10, "Goalkeeper", 70, 81, 85, 78});
Heurelho Gomes", 1.91, 37, "Brazil", 0, 100, 80, 22.2, 10, "Goalkeeper", 70, 83, 86, 77});
Cesar Azpilicueta", 1.78, 28, "Spain", 0, 100, 86, 36.4, 10, "Defender", 70, 79, 87, 79});
Nicolas Otamendi", 1.83, 30, "Argentina", 0, 100, 85, 32.3, 10, "Defender", 70, 63, 85, 82});
Antonio Valencia", 1.80, 32, "Ecuador", 0, 100, 83, 36.2, 10, "Defender", 70, 87, 78, 85});
Jan Vertonghen", 1.89, 31, "Belgium", 0, 100, 85, 30.3, 10, "Defender", 70, 67, 85, 81});
Sead Kolasinac", 1.83, 24, "Bosnia", 0, 100, 81, 29.3, 10, "Defender", 70, 79, 79, 90});
Nathan Ake", 1.80, 23, "Belgium", 0, 100, 77, 25.8, 10, "Defender", 70, 76, 78, 76});
James Tarkowski", 1.91, 25, "England", 0, 100, 78, 22.8, 10, "Defender", 70, 64, 78, 79});
Ragnar Klavan", 1.87, 32, "Estonia", 0, 100, 78, 20.8, 10, "Defender", 70, 57, 78, 76});
Cuco Martina", 1.85, 28, "Curacao", 0, 100, 71, 22.4, 10, "Defender", 70, 81, 79, 85});
Jamaal Lascelles", 1.89, 24, "England", 0, 100, 76, 23.8, 10, "Defender", 70, 65, 77, 77});
Mathias Jorgensen", 1.91, 28, "Denmark", 0, 100, 75, 22.8, 10, "Defender", 70, 69, 73, 82});
Hector Bellerin", 1.78, 23, "Spain", 0, 100, 81, 29.8, 10, "Defender", 70, 95, 75, 70});
Alfie Mawson", 1.88, 24, "England", 0, 100, 73, 28.8, 10, "Defender", 70, 53, 73, 75});
Brad Smith", 1.77, 24, "Australia", 0, 100, 65, 19.7, 10, "Defender", 70, 79, 56, 68});
Marvin Zeegelaar", 1.86, 27, "Holland", 0, 100, 75, 20.8, 10, "Defender", 70, 78, 71, 80});
Mohamed Salah", 1.75, 25, "Egypt", 0, 100, 85, 54.0, 10, "Midfielder", 70, 76, 87, 77});
Raheem Sterling", 1.70, 23, "England", 0, 100, 84, 43.4, 10, "Midfielder", 70, 76, 86, 74});
Riyad Mahrez", 1.79, 27, "Algeria", 0, 100, 84, 44.4, 10, "Midfielder", 70, 79, 88, 76});
Heung Min Son", 1.83, 25, "Korea Republic", 0, 100, 83, 41.4, 10, "Midfielder", 70, 76, 84, 83});
Pascal Gross", 1.81, 26, "Germany", 0, 100, 76, 30.3, 10, "Midfielder", 70, 78, 73, 67});
A. Doucoure", 1.82, 25, "France", 0, 100, 78, 27.8, 10, "Midfielder", 70, 73, 76, 71});
Jesse Lingard", 1.75, 25, "England", 0, 100, 80, 30.6, 10, "Midfielder", 70, 75, 82, 78});
H. Mkhitaryan", 1.77, 29, "Armenia", 0, 100, 85, 38.9, 10, "Midfielder", 70, 80, 86, 79});
Eden Hazard", 1.73, 27, "Belgium", 0, 100, 91, 53.5, 10, "Midfielder", 70, 85, 93, 83});
Aaron Mooy", 1.74, 27, "Australia", 0, 100, 78, 26.8, 10, "Midfielder", 70, 77, 75, 72});
Joe Allen", 1.68, 28, "Wales", 0, 100, 77, 25.5, 10, "Midfielder", 70, 73, 77, 63});
Paul Pogba", 1.91, 25, "France", 0, 100, 88, 39.3, 10, "Midfielder", 70, 86, 85, 79});
Oriol Romeu", 1.83, 26, "Spain", 0, 100, 79, 27.1, 10, "Midfielder", 70, 65, 63, 38});
Ilkay Gundogan", 1.80, 27, "Germany", 0, 100, 85, 27.6, 10, "Midfielder", 70, 83, 87, 74});
Xherdan Shaqiri", 1.69, 26, "Switzerland", 0, 100, 82, 32.3, 10, "Midfielder", 70, 78, 84, 77});
Harry Kane", 1.88, 24, "England", 0, 100, 88, 64.1, 10, "Attacker", 70, 73, 89, 81});
Sergio Aguero", 1.73, 29, "Argentina", 0, 100, 89, 59.6, 10, "Attacker", 70, 87, 88, 89});
Roberto Firmino", 1.81, 26, "Brazil", 0, 100, 84, 49.0, 10, "Attacker", 70, 77, 82, 86});
Romelu Lukaku", 1.90, 25, "Belgium", 0, 100, 86, 57.6, 10, "Attacker", 70, 83, 85, 74});
Jamie Vardy", 1.78, 31, "England", 0, 100, 81, 44.0, 10, "Attacker", 70, 91, 79, 77});
Wayne Rooney", 1.76, 32, "England", 0, 100, 81, 36.4, 10, "Attacker", 70, 68, 81, 76});
Alvaro Morata", 1.89, 25, "Spain", 0, 100, 85, 52.5, 10, "Attacker", 70, 83, 81, 81});
A. Lacazette", 1.75, 26, "France", 0, 100, 85, 51.5, 10, "Attacker", 70, 86, 83, 85});
Callum Wilson", 1.80, 26, "England", 0, 100, 75, 30.3, 10, "Attacker", 70, 90, 73, 74});
Jay Rodriguez", 1.85, 28, "England", 0, 100, 76, 26.7, 10, "Attacker", 70, 77, 75, 75});
Glenn Murray", 1.85, 34, "England", 0, 100, 73, 29.8, 10, "Attacker", 70, 49, 74, 66});
Javier Hernandez", 1.75, 29, "Mexico", 0, 100, 82, 33.8, 10, "Attacker", 70, 79, 80, 78});
Steve Mounie", 1.90, 23, "Benin", 0, 100, 76, 29.4, 10, "Attacker", 70, 74, 74, 66});
P. E. Aubameyang", 1.87, 28, "Gabon", 0, 100, 88, 53.5, 10, "Attacker", 70, 96, 84, 81});
Islam Slimani", 1.88, 29, "Algeria", 0, 100, 82, 33.4, 10, "Attacker", 70, 69, 78, 73});
*/
 /*
    Teams.push_back({"Arsenal", "Emirates", "London", 140, 1, 0, 0, 0, 0});
    Teams.push_back({"Bournemouth", "Vitality Stadium", "Bournemouth", 80, 1, 0, 0, 0, 0});
    Teams.push_back({"Brighton & Hove", "Falmer Stadium", "Brighton", 80, 1, 0,  0, 0, 0});
    Teams.push_back({"Burnley", "Turf Moor", "Burnley", 80, 1, 0,  0, 0, 0});
    Teams.push_back({"Chelsea", "Stamford Bridge", "London", 140, 1, 0,  0, 0, 0});
    Teams.push_back({"Crystal Palace", "Selhurst Park", "London", 70, 1, 0, 0, 0, 0});
    Teams.push_back({"Everton", "Goodison Park", "Liverpool", 90, 1, 0, 0, 0, 0});
    Teams.push_back({"Huddersfield", "John Smith's Stadium", "Huddersfield", 80, 1, 0,  0, 0, 0});
    Teams.push_back({"Leicester", "King Power Stadium", "Leicester", 90, 1, 0, 0, 0, 0});
    Teams.push_back({"Liverpool", "Anfield", "Liverpool", 170, 1, 0, 0, 0, 0});
    Teams.push_back({"Manchester City", "Etihad", "Manchester", 180, 1, 0, 0, 0, 0});
    Teams.push_back({"Manchester United", "Old Trafford", "Manchester", 160, 1, 0, 0, 0, 0});
    Teams.push_back({"Newcastle", "St James's Park", "Newcastle", 90, 1, 0, 0, 0, 0});
    Teams.push_back({"Stoke", "Britannia Stadium", "Stoke-on-Trent", 80, 1, 0, 0, 0, 0});
    Teams.push_back({"Southampton", "St Mary's Stadium", "Southampton", 70, 1, 0, 0, 0, 0});
    Teams.push_back({"My Team", "User Stadium", "London", 40, 1, 0, 0, 0, 0});
    Teams.push_back({"Tottenham", "Wembley", "London", 140, 1, 0, 0, 0, 0});
    Teams.push_back({"Watford", "Vicarage Road", "Watford", 90, 1, 0, 0, 0, 0});
    Teams.push_back({"West Bromwich Albion", "The Hawthorns", "West Bromwich", 70, 1, 0, 0, 0, 0});
    Teams.push_back({"West Ham United", "London Stadium", "London", 70, 1, 0, 0, 0, 0});

*/
}
