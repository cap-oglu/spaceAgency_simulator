/*
 *  Author: Ahmet Ramazan Capoglu
 *  ID: 150190080
 */
#ifndef UNTITLED_PERSON_H
#define UNTITLED_PERSON_H
#include <string>
#include <iostream>
using namespace std;




class Person{
private:
    string name;
    string surname;
public:
    Person(const string & = "" , const string & = "");
    void setName(const string & name)  { this->name = name;}
    void setSurname(const string & surname) { this->surname = surname;}
    string getName() const{return this->name;}
    string getSurname() const{return this->surname;}



};

class Passenger : public Person{
private:
    int cash;
    bool ticket;
public:
    Passenger(const string & = "", const string & = "", int = 0);
    void setCash(int cash){ this->cash = cash;}
    void setTicket(bool ticket){ this->ticket = ticket;}
    int getCash() const{return this->cash;}
    bool getTicket() const{return this->ticket;}
    bool buyTicket(int);
};

class Astronaut : public Person{
    //public inheritance why?
private:
    int numMissions;
public:
    Astronaut(const string & = "", const string & = "", int = 0);
    int completeMission(){this->numMissions++; return numMissions;}

};
#endif //UNTITLED_PERSON_H