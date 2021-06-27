/*
 *  Author: Ahmet Ramazan Capoglu
 *  ID: 150190080
 */
#ifndef UNTITLED_AGENCY_H
#define UNTITLED_AGENCY_H
#include <string>
#include <iostream>
#include "Mission.h"
using namespace std;





class Agency{
private:
    string name;
    int cash;
    int ticketPrice;
    int size_of_new_missions;
    int size_of_completed_missions;
    Mission * completeMissions;
    Mission * nextMissions;
public:
    Agency(const string & = "", int = 0, int = 0);
    ~Agency();
    void setTicketPrice(int ticket_price){this->ticketPrice = ticket_price;}
    int getTicketPrice(){return this->ticketPrice;}
    void addMission(const Mission &);
    void executeNextMission();
    friend ostream &operator<<(ostream &, Agency & );

};

#endif //UNTITLED_AGENCY_H