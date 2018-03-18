#include "stdafx.h"
#include "Player.h"
#include "Goalkeeper.h"
#include <iostream>
#include <thread>
#include <stdlib.h>

using namespace std;

Goalkeeper::Goalkeeper()
{

}

Goalkeeper::Goalkeeper(int reflex, int parades, int composure)
{

}

Goalkeeper::~Goalkeeper()
{

}

Goalkeeper Goalkeeper::GetInfo(Goalkeeper goalkeeper) const
{
    return goalkeeper;
}

int Goalkeeper::GetReflex() const
{
    return reflex;
}

int Goalkeeper::GetParades() const
{
    return parades;
}

int Goalkeeper::GetComposure() const
{
    return composure;
}

std::ostream& operator<< (std::ostream& os, const Goalkeeper& goalkeeper)
{
    os << goalkeeper.GetInfo(goalkeeper);

    return os;

}

Goalkeeper& Goalkeeper::operator=(const Goalkeeper& goalkeeper) {

    this->reflex = goalkeeper.reflex;
    this->parades = goalkeeper.parades;
    this->composure = goalkeeper.composure;

    return *this;

}

void Goalkeeper::PrintInfo(Goalkeeper goalkeeper)
{
    //cout << goalkeeper.GetReflex << endl;
    //cout << goalkeeper.GetParades << endl;
    //cout << goalkeeper.GetComposure << endl;
}
