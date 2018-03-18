#include "stdafx.h"
#include "Human.h"
#include <iostream>
#include <thread>
#include <stdlib.h>

using namespace std;

Human::Human()
{

}

Human::Human(string name, string surname, float height, int age, string nationality)
{

}

Human::~Human()
{

}

Human Human::GetInfo(Human human)
{
    return human;
}

string Human::GetName() const
{
    return name;
}

string Human::GetSurname() const
{
    return surname;
}

float Human::GetHeight() const
{
    return height;
}

int Human::GetAge() const
{
    return age;
}

string Human::GetNation() const
{
    return nationality;
}

Human& Human::operator=(const Human& Human) {
    this->name = Human.name;
    this->surname = Human.surname;
    this->height = Human.height;
    this->age = Human.age;
    this->nationality = Human.nationality;

    return *this;
}

//ostream& operator<< (ostream& os, const Human& Human)
//{
//	os << Human.GetName();
//	os << Human.GetSurname();
//	os << Human.GetHeight();
//	os << Human.GetAge();
//	os << Human.GetNation();
//
//	return os;
//}

void Human::PrintInfo(Human human)
{
//	cout << GetInfo(human) << endl;
}
