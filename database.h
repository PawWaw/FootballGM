#ifndef DATABASE_H
#define DATABASE_H
#include <vector>
#include "player.h"
#include "goalkeeper.h"
#include "defender.h"
#include "midfielder.h"
#include "attacker.h"

class database
{
public:
    database();
    ~database();

    static vector<Player> GoalkeeperDB;
    static vector<Player> DefenderDB;
    static vector<Player> MidfielderDB;
    static vector<Player> AttackerDB;

    void FillGDB();
    void FillDDB();
    void FillMDB();
    void FillADB();
    void LoadAll();

};

#endif // DATABASE_H
