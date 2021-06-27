/*
 *  Author: Ahmet Ramazan Capoglu
 *  ID: 150190080
 */
#include "Mission.h"




Mission::Mission( const string & name, int cost, int faultProbability) : name(name), cost(cost), faultProbability(faultProbability)
{   if(name != "") { //hata verebilir cunku degisik bir kontrol yontemi
        numMissions++;
        missionNumber = numMissions;
        int location;
        bool  error2 = false, error3 = false;
        string search = "-";
        location = name.find(search); // counting starts from zero


        /* if (location == string::npos || count(name.begin(), name.end(), "-") > 1 ){
            // cout << "Given name does not satisfy the mission naming convention. Please set a new name!" << endl;
             error1=true;
         }*/
        for (int i = 0; i < location; i++) {

            if (isupper(name[i]) == 0) {
                error2 = true;
                break;
            }
        }

        for (long unsigned int i = location + 1; i < name.length(); i++) {

            if (isdigit(name[i]) == 0) {
                error3 = true;
                break;
            }
        }
        if (location != 2) {
            error2 = true;
        }
        /*if((name.length()-location-1) != 2)
        {
            error3 = true;
        }*/

        if (error2 || error3) {
            cout << "Given name does not satisfy the mission naming convention. Please set a new name!" << endl;
            this->name = "AA-00";

        }
        size_of_crew = 0;
        size_of_passengers = 0;
        passengers = NULL;
        crew = NULL;
        //completed = false;
    }

}
Mission::~Mission()
{
    delete[] passengers;
    delete[] crew;
    numMissions--;
}


void Mission::operator+=( const Passenger  * inObject) { //when you make it const you can't reach setName() function for example because it is not const function i guess
if(inObject->getTicket()) {
    if (passengers == NULL) {
        passengers = new Passenger[1];
        size_of_passengers = 1;
        *passengers = *inObject;
        //passengers[0].setName(inObject.getName()); //when param of setName() is not const and & type it gives error.
        //passengers[0].setSurname(inObject.getSurname());
        //passengers[0].setCash(inObject.getCash());
        //passengers[0].setTicket(inObject.getTicket());

    } else {
        size_of_passengers++;
        Passenger *passenger_extra = new Passenger[size_of_passengers];
        for (int i = 0; i < size_of_passengers - 1; i++) {
            passenger_extra[i] = passengers[i];
        }
        passenger_extra[size_of_passengers - 1] = *inObject;
        //*(passenger_extra + size_of_passengers - 1) = inObject;
        delete[] passengers;
        //passengers = passenger_extra;
        passengers = new Passenger[size_of_passengers];
        for (int i = 0; i < size_of_passengers; i++) {
            passengers[i] = passenger_extra[i];
        }
        delete[] passenger_extra;
    }
}
else{
    cout << "Passenger " << inObject->getName() << " " << inObject->getSurname()  << " does not have a valid ticket!" << endl;
}
}
void Mission::operator+=( const Astronaut  * inObject) {
    if(crew == NULL) {
        crew = new Astronaut[1];
        size_of_crew = 1;
        crew[0] =  *inObject;


    }
    else{
        size_of_crew++;
        Astronaut * astronaut_extra = new Astronaut[size_of_crew];
        for(int i = 0; i < size_of_crew - 1; i++){
            astronaut_extra[i] = crew[i];
        }

       // *(astronaut_extra + size_of_crew - 1) = *inObject;
        astronaut_extra[size_of_crew - 1] = *inObject;
        delete[] crew;
        //crew = astronaut_extra;
        crew = new Astronaut[size_of_crew];
        for(int  i = 0;  i < size_of_crew; i++){
            crew[i] = astronaut_extra[i];
        }
        delete[] astronaut_extra;
    }
}

bool Mission::executeMission() {
    int random_number = rand() % 101; //is it between some numbers, this is not
   //int random_number = 150;
    if (random_number > faultProbability){
        cout << "MISSION " << this->name << " SUCCESSFUL!" << endl;
      //  while(crew + count == NULL) //sonda bir tane NULL bırakabilir ve her şeyi ona göre yapabilirsin
      for(int i = 0; i < size_of_crew; i++){

          cout << "Astronaut " << crew[i].getName() << " "<< crew[i].getSurname() << " successfully completed " << crew[i].completeMission()  << " missions." << endl;

      }
      this->completed = true;
      return completed;
    }
    else{
        cout << "MISSION " << this->name << " FAILED!" << endl;
        cout << "Agency reschedules the mission." << endl;
        this->completed = false;
        return completed;
    }
}

int Mission::calculateProfit(int ticket_price) {
    int net_profit = 0;
    if(completed == true){
        net_profit = ticket_price * size_of_passengers - cost;
        return net_profit;
    }
    else{
        net_profit = net_profit - cost;
        return net_profit;
    }
}

void Mission::operator=(const Mission &objectIn) {
    name = objectIn.name;
    missionNumber = objectIn.missionNumber;
    cost = objectIn.cost;
    faultProbability = objectIn.faultProbability;
    completed = objectIn.completed;
    size_of_crew = objectIn.size_of_crew;
    size_of_passengers=objectIn.size_of_passengers;
    numMissions=objectIn.numMissions;
    passengers = new Passenger[size_of_passengers];
    crew = new Astronaut[size_of_crew];
    for(int i = 0; i < size_of_passengers; i++){
        passengers[i] = objectIn.passengers[i];
    }
    for(int i = 0; i < size_of_crew; i++){
        crew[i] = objectIn.crew[i];
    }

}

