#ifndef DATABASE_H
#define DATABASE_H

#include <vector>
#include <QString>
#include "human.h"
#include "player.h"
#include "goalkeeper.h"
#include "defender.h"
#include "team.h"

class PlayerInfo : public Player
{
public:
    PlayerInfo(QString name, float height, int age, QString nationality, float injury2, float fitness2, float quality2,
               float price2, int chemistry2, QString position2, float strength2, int specificstat12, int specificstat22,
               int specificstat32);
    ~PlayerInfo();
};


class DataBase
{

public:
    static std::vector<PlayerInfo> playerz;
    static std::vector<PlayerInfo> chosen;
    static std::vector<PlayerInfo> InGamePlayers;
    static std::vector<Team> Teams;
    static std::vector<Team> Clone;

    static void loadDataBase();

    DataBase();
    ~DataBase();
};

#endif // DATABASE_H
