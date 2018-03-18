#ifndef _MIDFIELDER_H_
#define _MIDFIELDER_H_

#include <string>

using namespace std;

class Midfielder
{
    int creativity;
    int vision;
    int dribbling;

protected:


    friend ostream& operator<< (ostream& os, const Midfielder& foo);

public:

    // konstruktory

    Midfielder();
    Midfielder(int, int, int);
    ~Midfielder();

    // setters

    // getters

    Midfielder GetInfo(Midfielder) const;
    int GetCreativity() const;
    int GetVision() const;
    int GetDribbling() const;

    // operators

    Midfielder& operator= (const Midfielder& midfielder);

    // other

    void PrintInfo(Midfielder);

};

#endif


