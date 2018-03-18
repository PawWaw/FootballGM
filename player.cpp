#include "stdafx.h"
#include "Human.h"
#include "Player.h"
#include "Team.h"
#include <iostream>
#include <thread>
#include <stdlib.h>

using namespace std;

Player::Player()
{

}

Player::Player(float injury, float fitness, float quality, float price, int chemistry, int strength)
{

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
    return fitness;
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
    return *this;
}

void Player::PrintInfo()
{
    //cout << GetInfo() << endl;
}
