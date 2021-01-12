#pragma once

#include "Event.h"
#include "Helpers.h"

#define MOUNTAINOUS_MISSION 1
#define POLAR_MISSION 2
#define EMERGENCY_MISSION 3
#define MOUNTAINOUS_ROVER 4
#define POLAR_ROVER 5
#define EMERGENCY_ROVER 6
#define FORMULATION_EVENT 7
#define CANCELATION_EVENT 8
#define PROMOTION_EVENT 9
#define AWAITING_FORMULATION_MISSION 10
#define WATING_MISSION 11
#define IN_EXECUTION_MISSION 12
#define CANCELED_MISSION 13
#define COMPOLETED_MISSION 14
#define IN_MISSION_ROVER 15
#define WAITING_ROVER 16
#define DOING_CHECKUP_ROVER 17
#define MARS_DAYS 25

class FormulationEvent :
    public Event
{
private:
    /*enum class MissionType {
        Emergency_Mission,
        Mountainous_Mission,
        Polar_Mission
    };*/
    int missionType = EMERGENCY_MISSION;
    int eventDay;
    int missionID;
    int missionTargetLocationDistance;
    int daysToCompletefullfillRequirement;
    int missionSignificance;
  
public:

    FormulationEvent() :Event() {}
    /*
    * A constructor that intialize the data members of the class.
    */
    // MDUR the number of days needed to fulfill the mission requirements at target location.
    FormulationEvent(int type, int day, int id, int distance, int MDUR, int importance)
        : Event(FORMULATION_EVENT, type, day, id) {
        missionType = type;
        eventDay = day;
        missionID = id;
        missionTargetLocationDistance = distance;
        daysToCompletefullfillRequirement = MDUR;
        missionSignificance = importance;
    }

    int GetEventType() {
        return FORMULATION_EVENT;
    }

    /*
    * A getter for the type of the mission to be created
    */
    int GetMissionType() {
        return missionType;
    }

    /*
    * A getter for the event day on which the mission will be formulated
    */
    int GetEventDay() {
        return eventDay;
    }

    /*
    * A getter for the id of the mission to be formulated
    */
    int GetMissionID() {
        return missionID;
    }

    /*
    * A getter for the distance of the target location from the base station
    */
    int GetDistance() {
        return missionTargetLocationDistance;
    }

   
    /*
    * A getter for the number it takes to finish the mission
    */
    int GetDaysToComplete() {
        return daysToCompletefullfillRequirement;
    }

    /*
    * A getter for the significance of the mission
    */
    int GetSignificance() {
        return missionSignificance;
    }
};
