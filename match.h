#ifndef MATCH_H
#define MATCH_H
#include <vector>
#include "player.h"
#include <string.h>

using namespace std;

class Match
{
public:
    Match();
    static vector<Player> players;
    void FillMatch();
};

#endif // MATCH_H
