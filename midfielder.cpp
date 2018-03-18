#include "stdafx.h"
#include "Player.h"
#include "Midfielder.h"
#include <iostream>
#include <thread>
#include <stdlib.h>

using namespace std;

Midfielder::Midfielder()
{

}

Midfielder::Midfielder(int creativity, int vision, int dribbling)
{

}

Midfielder::~Midfielder()
{

}

Midfielder Midfielder::GetInfo(Midfielder midfielder) const
{
    return midfielder;
}

int Midfielder::GetCreativity() const
{
    return creativity;
}

int Midfielder::GetVision() const
{
    return vision;
}

int Midfielder::GetDribbling() const
{
    return dribbling;
}

std::ostream& operator<< (std::ostream& os, const Midfielder& midfielder)
{
    os << midfielder.GetInfo(midfielder);

    return os;

}

Midfielder& Midfielder::operator=(const Midfielder& midfielder) {

    this->creativity = midfielder.creativity;
    this->vision = midfielder.vision;
    this->dribbling = midfielder.dribbling;

    return *this;

}

void Midfielder::PrintInfo(Midfielder midfielder)
{
    //cout << midfielder.GetCreativity << endl;
    //cout << midfielder.GetVision << endl;
    //cout << midfielder.GetDribbling << endl;
}
