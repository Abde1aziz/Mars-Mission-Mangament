#pragma once

#include "Event.h"

class CancelationEvent :
    public Event
{
private:
    int eventDay;
    int missionID;
public:
    /*
    * Constructor for the class that intialize the data members
    */
    CancelationEvent()
    {}
    CancelationEvent(int day, int id)
        :Event(CANCELATION_EVENT, MOUNTAINOUS_MISSION, day, id) {
        eventDay = day;
        missionID = id;
    }

    int GetEventType() {
        return CANCELATION_EVENT;
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

