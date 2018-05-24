#include "stdafx.h"
#include "Manager.h"
#include "Human.h"
#include <iostream>
#include <thread>
#include <stdlib.h>

using namespace std;

Manager::Manager()
{

}

Manager::Manager(int FormationBonus, int TeamBonus)
{

}

Manager::~Manager()
{

}

int Manager::GetFormationBonus()
{
    return FormationBonus;
}

int Manager::GetTeamBonus()
{
    return TeamBonus;
}

Manager& Manager::operator=(const Manager& Manager) {
    this->FormationBonus = Manager.FormationBonus;
    this->TeamBonus = Manager.TeamBonus;

    return *this;
}

ostream& operator<< (ostream& os, const Human& Human)
{
    //os << Human.GetName();
    //os << Human.GetSurname();
    os << Human.GetHeight();
    os << Human.GetAge();
    //os << Human.GetNation();

    return os;
}

//void Human::PrintInfo(Human human)
//{
//	cout << GetInfo(human) << endl;
//}
