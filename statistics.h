#ifndef _STATISTICS_H_
#define _STATISTICS_H_

#include <string>
using namespace std;

class Statistics : public Team {
public:
    string name;
    string tab1[20];
    int tab2[20][4];

    Statistics& Fullfilling(Team*&, Team&, Team&, Team&, Team&, Team&, Team&, Team&, Team&,
        Team&, Team&, Team&, Team&, Team&, Team&, Team&, Team&, Team&, Team&, Team&, Team&);
    Statistics& createtable(Team&, Team&, Team&, Team&, Team&, Team&, Team&, Team&,
        Team&, Team&, Team&, Team&, Team&, Team&, Team&, Team&, Team&, Team&, Team&, Team&);
    Statistics& datadisplay(Team*&);
    Statistics& sort();
    Statistics& tabledisplay(int);
};

void addteam(Team *&, string, string, string, int, int, int, int, int, int);
#endif

