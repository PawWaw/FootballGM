#ifndef _ATTACKER_H_
#define _ATTACKER_H_

#include <string>

using namespace std;

class Attacker
{
    int shooting;
    int pace;
    int composure;

protected:


    friend ostream& operator<< (ostream& os, const Attacker& foo);

public:

    // konstruktory

    Attacker();
    Attacker(int, int, int);
    ~Attacker();

    // setters

    // getters

    Attacker GetInfo(Attacker) const;
    int GetShooting() const;
    int GetPace() const;
    int GetComposure() const;

    // operators

    Attacker& operator= (const Attacker& attacker);

    // other

    void PrintInfo(Attacker);

};

#endif



