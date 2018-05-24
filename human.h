#ifndef _HUMAN_H_
#define _HUMAN_H_

#include <string>
#include <QString>

using namespace std;

class Human {

public:

    QString name;
    float height;
    int age;
    QString nationality;
//	friend ostream& operator<< (ostream& os, const Human& foo);


    // constructors
    Human();
    Human(QString name, float height, int age, QString nationality);
    ~Human();

    // setters

    // getters
    Human GetInfo(Human);
    QString GetName() const;
    float GetHeight() const;
    int GetAge() const;
    QString GetNation() const;

    // operators
    Human& operator= (const Human& Human);

    // other
    void PrintInfo(Human);

};


#endif
