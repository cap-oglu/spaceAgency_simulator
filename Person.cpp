/*
 *  Author: Ahmet Ramazan Capoglu
 *  ID: 150190080
 */
#include "Person.h"




using namespace std;

Person::Person(const string & name, const string & surname) : name(name), surname(surname)
{}

Passenger::Passenger(const string & name, const string & surname, int cash) : Person(name,surname), cash(cash)
{
    //i am using a constructor which don't take attributes, so it is necessary to write this?
    if(cash < 0){
        this->cash = 0;
        cerr << "Passenger cash can’t be negative. It is set to 0." << endl;

    }
    this->ticket = false;
}
bool Passenger::buyTicket(int price) {
    /*if(this->ticket == true){
        return false; //if passenger has already a ticket, it will not buy a ticket?
    } */
     if(this->cash >= price){
        this->cash = this->cash - price; //if ticket bought then cash will decrease
        this->ticket = true; //have a ticket now
        return true;
    }

     return false;
}

Astronaut::Astronaut(const string & name, const string & surname , int numMissions) : Person(name, surname), numMissions(numMissions)
{
    if(numMissions < 0){
        cout << "Number of missions that astronaut completed can't be negative. It is set to 0." << endl;
        this->numMissions = 0;
    }
}