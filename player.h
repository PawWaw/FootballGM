#ifndef _PLAYER_H_
#define _PLAYER_H_
#include <QString>
#include <vector>
#include <string>
#include <human.h>


using namespace std;

class Player : public Human
{
public:
    float injury;
    float fitness;
    float quality;
    float price;
    int chemistry;
    float strength;
    QString position;
    int specificstat1, specificstat2, specificstat3;


    // constructors
    Player();
    Player(QString name2, float height2, int age2, QString nationality2, float injury, float fitness, float quality, float price, int chemistry, QString position, float strength,  int specificstat1, int specificstat2,
           int specificstat3);

    ~Player();

    // setters
    float SetInjury();
    float SetFitness();
    float SetQuality();
    int SetStrength();
    void SetAge();

    // getters
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
    void PlayerCosts();



};

#endif // !_PLAYER_H_

