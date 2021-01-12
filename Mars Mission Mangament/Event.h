#pragma once

#include "Helpers.h"

class Event
{
protected:
	int eventType;
	int missionType;
	int eventDay;
	int missionID;


public:
	Event() {}

	Event(int eType, int mType, int day, int id) {
		eventType = eType;
		missionType = mType;
		eventDay = day;
		missionID = id;

	}
	virtual int GetEventType() {
		return eventType;
	}

	virtual int GetMissionType() {
		return missionType;
	}
	virtual int GetEventDay() {
		return eventDay;
	}
	virtual int GetMissionID() {
		return missionID;
	}
	virtual int GetDistance() {
		return missionTargetLocationDistance;
	}



	virtual int GetDaysToComplete() {
		return daysToComplete;
	}

	virtual int GetSignificance() {
		return missionSignificance;
	}
};

