#include "stdafx.h"
#include "Player.h"
#include "Attacker.h"
#include <iostream>
#include <thread>
#include <stdlib.h>

using namespace std;

Attacker::Attacker()
{

}

Attacker::Attacker(int shooting, int pace, int composure)
{

}

Attacker::~Attacker()
{

}

Attacker Attacker::GetInfo(Attacker attacker) const
{
    return attacker;
}

int Attacker::GetShooting() const
{
    return shooting;
}

int Attacker::GetPace() const
{
    return pace;
}

int Attacker::GetComposure() const
{
    return composure;
}

std::ostream& operator<< (std::ostream& os, const Attacker& attacker)
{
    os << attacker.GetInfo(attacker);

    return os;

}

Attacker& Attacker::operator=(const Attacker& attacker) {

    this->shooting = attacker.shooting;
    this->pace = attacker.pace;
    this->composure = attacker.composure;

    return *this;

}

void Attacker::PrintInfo(Attacker attacker)
{
    //cout << attacker.GetShooting << endl;
    //cout << attacker.GetPace << endl;
    //cout << attacker.GetComposure << endl;
}
