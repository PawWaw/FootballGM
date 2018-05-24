#include "database.h"
#include <vector>
#include "player.h"
#include "goalkeeper.h"
#include "defender.h"
#include "midfielder.h"
#include "attacker.h"

vector<Player> database::GoalkeeperDB;
vector<Player> database::DefenderDB;
vector<Player> database::MidfielderDB;
vector<Player> database::AttackerDB;



database::database()
{

}

database::~database()
{

}

void FillGDB()
{
    //database::GoalkeeperDB.push_back({});
}
