#ifndef _GOALKEEPER_H_
#define _GOALKEEPER_H_

#include <string>
#include <vector>
#include "player.h"

using namespace std;

class Goalkeeper
{
    int reflex;
    int parades;
    int composure;

protected:


    friend ostream& operator<< (ostream& os, const Goalkeeper& foo);

public:

    // konstruktory

    Goalkeeper();
    Goalkeeper(string, int, int, int);
    ~Goalkeeper();

    // setters

    // getters

    Goalkeeper GetInfo(Goalkeeper) const;
    int GetReflex() const;
    int GetParades() const;
    int GetComposure() const;

    // operators

    Goalkeeper& operator= (const Goalkeeper& goalkeeper);

    // other

    vector<Goalkeeper> goalkeepers;
    void FillGoalkeeperVector();
    void PrintInfo(Goalkeeper);

};

#endif

