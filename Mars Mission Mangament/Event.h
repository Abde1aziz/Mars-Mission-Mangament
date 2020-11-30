#pragma once
#include "Helpers.h"

class Event
{
protected:
	EventType eventType;
public:
	
	virtual EventType GetEventType() {
		return eventType;
	}
	virtual MissionType GetMissionType() = 0;
	virtual int GetEventDay() = 0;
	virtual int GetMissionID() = 0;
};

