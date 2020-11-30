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
    CancelationEvent(int day, int id) {
        Event::eventType = EventType::Cancelation;
        eventDay = day;
        missionID = id;
    }

    /*
    * A getter for the type of the mission to be created
    */
    EventType GetEventType() {
        return Event::eventType;
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

