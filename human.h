#ifndef _HUMAN_H_
#define _HUMAN_H_

#include <string>

using namespace std;

class Human {

protected:

    string name;
    string surname;
    float height;
    int age;
    string nationality;
//	friend ostream& operator<< (ostream& os, const Human& foo);

public:
    // constructors
    Human();
    Human(string, string, float, int, string);
    ~Human();

    // setters

    // getters
    Human GetInfo(Human);
    string GetName() const;
    string GetSurname() const;
    float GetHeight() const;
    int GetAge() const;
    string GetNation() const;

    // operators
    Human& operator= (const Human& Human);

    // other
    void PrintInfo(Human);

};


#endif
