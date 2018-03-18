#ifndef _MANAGER_H_
#define _MANAGER_H_

#include <string>

using namespace std;

class Manager {

protected:
    int FormationBonus;
    int TeamBonus;
    friend ostream& operator<< (ostream& os, const Manager& foo);

public:
    // constructors
    Manager();
    Manager(int, int);
    ~Manager();

    // setters

    // getters
    int GetFormationBonus();
    int GetTeamBonus();

    // operators
    Manager& operator= (const Manager& Manager);

    // other
//	void PrintInfo();
};


#endif
