#ifndef _DEFENDER_H_
#define _DEFENDER_H_

#include <string>

using namespace std;

class Defender
{
    int decisiveness;
    int defence;
    int aggresion;

protected:


    friend ostream& operator<< (ostream& os, const Defender& foo);

public:

    // konstruktory

    Defender();
    Defender(int, int, int);
    ~Defender();

    // setters

    // getters

    Defender GetInfo(Defender) const;
    int GetDecisiveness() const;
    int GetDefence() const;
    int GetAggresion() const;

    // operators

    Defender& operator= (const Defender& defender);

    // other

    void PrintInfo(Defender);

};

#endif


