/*
 *  Author: Ahmet Ramazan Capoglu
 *  ID: 150190080
 */
#include "Agency.h"



Agency::Agency(const string & name, int cash, int ticketPrice) : name(name), cash(cash), ticketPrice(ticketPrice) {
    if (ticketPrice < 0){
        cout << "Ticket price can't be negative. It is set to 0." << endl;
        this->ticketPrice = 0;
    }
    completeMissions = NULL; //for now NULL
    nextMissions = NULL;
    size_of_new_missions = 0;
    size_of_completed_missions = 0;


}
Agency::~Agency()
{
    delete[] completeMissions;
    delete[] nextMissions;
}

void Agency::addMission(const Mission & inObject) {
    if(nextMissions == NULL){
        nextMissions = new Mission[1];
        size_of_new_missions = 1;
        *nextMissions = inObject;
    }
    else{
        size_of_new_missions++;
        Mission * mission_extras = new Mission[size_of_new_missions];
        for(int i = 0; i < size_of_new_missions - 1; i++){
            mission_extras[i] = nextMissions[i];
        }

        *(mission_extras + size_of_new_missions - 1) = inObject;
        delete[] nextMissions;
        nextMissions = mission_extras;
    }

}

void Agency::executeNextMission() {
    if(size_of_new_missions > 0) {
        if (this->nextMissions[0].executeMission() ==true) { // şimdi bu çalıştırmış oluyor mu yani else de mi çalışmış olacak?
            //this is for if true add first element of nextMissions to completedMissions
            if (completeMissions == NULL) {
                completeMissions = new Mission[1];
                size_of_completed_missions = 1;
                *completeMissions = nextMissions[0];
            } else {
                size_of_completed_missions++;
                Mission *mission_extras = new Mission[size_of_completed_missions];
                for (int i = 0; i < size_of_completed_missions - 1; i++) {
                    mission_extras[i] = completeMissions[i];
                }

                *(mission_extras + size_of_completed_missions - 1) = nextMissions[0];
                delete[] completeMissions;
                completeMissions = mission_extras;

            }
            this->cash = cash + nextMissions[0].calculateProfit(ticketPrice); //calculates profit and adds it to agency cash.
            size_of_new_missions--;
            Mission *decreasedMissions = new Mission[size_of_new_missions];
            for (int i = 0; i < size_of_new_missions; i++) {
                decreasedMissions[i] = nextMissions[i + 1];
            }
            delete[] nextMissions;
            nextMissions = decreasedMissions;

        } else {
            this->cash = cash + nextMissions[0].calculateProfit(ticketPrice);
            Mission *failedMission = new Mission[1];
            failedMission[0] = nextMissions[0];
            int i = 0;
            for (; i < size_of_new_missions - 1; i++) {
                nextMissions[i] = nextMissions[i + 1];
            }
            nextMissions[i] = failedMission[0];
            delete[] failedMission;
        }
    }
    else{
        cout << "No available mission to execute!" << endl;
    }
}

ostream &operator<<( ostream &output,Agency &inObject) {
    output << "Agency name: " << inObject.name <<"," << " Total cash: " << inObject.cash << "," << " Ticket Price: " << inObject.ticketPrice << endl;
    output << "Next Missions:" << endl;
    if(inObject.size_of_new_missions > 0) {
        for (int i = 0; i < inObject.size_of_new_missions; i++) {
            output << "Mission number: " << inObject.nextMissions[i].getMissionNumber() << " Mission name: " << inObject.nextMissions[i].getName() << " Cost: "
                 << inObject.nextMissions[i].getCost() << endl;
        }
    }
    else output << "No missions available." << endl;

    output << "Completed Missions:" << endl;
    if(inObject.size_of_completed_missions > 0) {
        for (int i = 0; i < inObject.size_of_completed_missions; i++) {
            output << "Mission number: " << i + 1 << " Mission name: " << inObject.completeMissions[i].getName() << " Cost: "
                 << inObject.completeMissions[i].getCost() << endl;
        }
    }
    else output << "No missions completed before." << endl;
    return output;
}
