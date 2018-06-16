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
}
