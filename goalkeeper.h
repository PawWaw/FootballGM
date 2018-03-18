#ifndef _GOALKEEPER_H_
#define _GOALKEEPER_H_

#include <string>

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
    Goalkeeper(int, int, int);
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

    void PrintInfo(Goalkeeper);

};

#endif

