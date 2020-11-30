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
    /*
    * Constructor for the class that intialize the data members
    */
    PromotionEvent(int day, int id)
    :Event(PROMOTION_EVENT, MOUNTAINOUS_MISSION, day, id){
        eventDay = day;
        missionID = id;
    }

    int GetEventType() {
        return  PROMOTION_EVENT;
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

