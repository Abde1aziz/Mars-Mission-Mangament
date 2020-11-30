#pragma once
#include "Event.h"
#include "Helpers.h"
class PromotionEvent :
    public Event
{
private:
    int eventDay;
    int missionID;
public:

    enum class MissionType {
        Emergency_Mission,
        Mountainous_Mission,
        Polar_Mission
    };

    /*
    * Constructor for the class that intialize the data members
    */
    PromotionEvent(int day, int id) {
        eventDay = day;
        missionID = id;
    }

    /*
    * A getter for the event day
    */
    int GetEventDay() {
        return eventDay;
    }

    /*
    * A getter for the mission ID
    */
    int GetMissionID() {
        return missionID;
    }


};

