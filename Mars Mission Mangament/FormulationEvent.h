#pragma once

#include "Event.h"

class FormulationEvent :
    public Event
{
private:
    //enum class MissionType {
    //    Emergency_Mission,
    //    Mountainous_Mission,
    //    Polar_Mission
    //};
    MissionType missionType = MissionType::Emergency_Mission;
    int eventDay;
    int missionID;
    int missionTargetLocationDistance;
    int daysToComplete;
    int missionSignificance;
public:
    /*
    * The default constructor. I made it to avoid problems while passing enum as a paramter.
    */
    FormulationEvent() {
        Event::eventType = EventType::Formulation;
    }

    /*
    * A constructor that intialize the data members of the class.
    */
    FormulationEvent(MissionType type, int day, int id, int distance, int timeToComplete, int importance) {
        Event::eventType = EventType::Formulation;
        missionType = type;
        eventDay = day;
        missionID = id;
        missionTargetLocationDistance = distance;
        daysToComplete = timeToComplete;
        missionSignificance = importance;
    }

    /*
    * A getter for the type of the mission to be created
    */
    EventType GetEventType() {
        return Event::eventType;
    }

    /*
    * A getter for the type of the mission to be created
    */
    MissionType GetMissionType() {
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
        return daysToComplete;
    }

    /*
    * A getter for the significance of the mission
    */
    int GetSignificance() {
        return missionSignificance;
    }
};
