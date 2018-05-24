#include "stdafx.h"
#include "Human.h"
#include <iostream>
#include <thread>
#include <stdlib.h>

using namespace std;

Human::Human()
{

}

Human::Human(QString name2, float height2, int age2, QString nationality2)
{
    name = name2;
    height = height2;
    age = age2;
    nationality = nationality2;
}

Human::~Human()
{

}

Human Human::GetInfo(Human human)
{
    return human;
}

QString Human::GetName() const
{
    return name;
}

float Human::GetHeight() const
{
    return height;
}

int Human::GetAge() const
{
    return age;
}

QString Human::GetNation() const
{
    return nationality;
}

Human& Human::operator=(const Human& Human) {
    this->name = Human.name;
    this->height = Human.height;
    this->age = Human.age;
    this->nationality = Human.nationality;

    return *this;
}
