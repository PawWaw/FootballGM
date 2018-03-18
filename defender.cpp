#include "stdafx.h"
#include "Player.h"
#include "Defender.h"
#include <iostream>
#include <thread>
#include <stdlib.h>

using namespace std;

Defender::Defender()
{

}

Defender::Defender(int decisiveness, int defence, int aggresion)
{

}

Defender::~Defender()
{

}

Defender Defender::GetInfo(Defender defender) const
{
    return defender;
}

int Defender::GetDecisiveness() const
{
    return decisiveness;
}

int Defender::GetDefence() const
{
    return defence;
}

int Defender::GetAggresion() const
{
    return aggresion;
}

std::ostream& operator<< (std::ostream& os, const Defender& defender)
{
    os << defender.GetInfo(defender);

    return os;

}

Defender& Defender::operator=(const Defender& defender) {

    this->decisiveness = defender.decisiveness;
    this->defence = defender.defence;
    this->aggresion = defender.aggresion;

    return *this;

}

void Defender::PrintInfo(Defender defender)
{
    //cout << defender.GetDecisiveness << endl;
    //cout << defender.GetDefence << endl;
    //cout << defender.GetAggresion << endl;
}
