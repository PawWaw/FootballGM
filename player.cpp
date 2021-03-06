#include "stdafx.h"
#include "Human.h"
#include "Player.h"
#include "Team.h"
#include "goalkeeper.h"
#include "database.h"
#include <iostream>
#include <thread>
#include <stdlib.h>
#include <string>

using namespace std;

Player::Player()
{

}

Player::Player(QString name2, float height2, int age2, QString nationality2, float injury2, float fitness2, float quality2, float price2, int chemistry2, QString position2, float strength2, int specificstat12, int specificstat22,
               int specificstat32) : Human(name2, height2, age2, nationality2)
{
    injury = injury2;
    fitness = fitness2;
    quality = quality2;
    price = price2;
    strength = strength2;
    chemistry = chemistry2;
    position = position2;
    specificstat1 = specificstat12;
    specificstat2 = specificstat22;
    specificstat3 = specificstat32;
}


Player::~Player()
{

}

float Player::SetInjury()	// uzupełnić
{
    return injury;
}

float Player::SetFitness()	// uzupełnić
{
    return fitness * 0.99;
}

float Player::SetQuality()	// uzupełnić
{
    return quality;
}

int Player::SetStrength()	// uzupełnić
{
    return strength;
}

/*string Player::GetInfo()	// uzupełnić
{

}*/

float Player::GetInjury()
{
    return injury;
}

float Player::GetFitness()
{
    return fitness;
}

float Player::GetQuality()
{
    return quality;
}

float Player::GetPrice()
{
    return price;
}

int Player::GetChemistry()
{
    return chemistry;
}

int Player::GetStrength()
{
    return strength;
}

Player& Player::operator=(const Player& Player) {
    this->injury = Player.injury;
    this->fitness = Player.fitness;
    this->quality = Player.quality;
    this->price = Player.price;
    this->chemistry = Player.chemistry;
    this->strength = Player.strength;
    this->position = Player.position;
    return *this;
}

void Player::PrintInfo()
{
    //cout << GetInfo() << endl;
}

void Player::PlayerCosts()
{
    //Player::Tab[0][1] = "David De Gea";
    //Tab[0][1] = "40";
}

void Player::SetAge()
{
    for(int i = 0; i < DataBase::playerz.size(); i++)
        DataBase::playerz[i].age++;

}
