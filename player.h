#ifndef _PLAYER_H_
#define _PLAYER_H_


class Player {

protected:
    float injury;
    float fitness;
    float quality;
    float price;
    int chemistry;
    int strength;

public:
    // constructors
    Player();
    Player(float, float, float, float, int, int);
    ~Player();

    // setters
    float SetInjury();
    float SetFitness();
    float SetQuality();
    int SetStrength();

    // getters
    //string GetInfo();
    float GetInjury();
    float GetFitness();
    float GetQuality();
    float GetPrice();
    int GetChemistry();
    int GetStrength();

    // operators
    Player& operator= (const Player& Player);

    // other
    void PrintInfo();
};

#endif // !_PLAYER_H_

