/*
 *  Author: Ahmet Ramazan Capoglu
 *  ID: 150190080
 */
#ifndef UNTITLED_MISSION_H
#define UNTITLED_MISSION_H


#include <algorithm>
#include <string>
#include "Person.h"
using namespace std;



class Mission{
private:
    string name;
    int missionNumber;
    int cost;
    int faultProbability;
    bool completed;
    Passenger * passengers;
    Astronaut * crew;
    static int numMissions;
    int size_of_crew;
    int size_of_passengers;
public:
    //without const it gives error
    void setName( const string & name){ this->name = name;}
    string getName() const{return this->name;}

    int getCost() const{return this->cost;}
    int getMissionNumber() const{return this->missionNumber;}
    //Mission():name(""),cost(0),faultProbability(0),size_of_crew(0),size_of_passengers(0){numMissions++;missionNumber = numMissions;}
    Mission( const string& = "", int = 0, int = 0);
    ~Mission();
    void operator+=(const Passenger * inObject); //are we going to do 2 different "+=" ?
    void operator+=(const Astronaut * inObject);
    void operator=(const Mission & objectIn);
    bool executeMission();

    int calculateProfit( int ticket_price);

};

#endif //UNTITLED_MISSION_H