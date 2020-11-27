#pragma once
#include "PriorityQueue.h"
#include "Missions.h"
#include "LinkedQueue.h"
#include "Event.h"
#include "LinkedList.h"
#include "Rovers.h"

using namespace std;
class BaseStation
{
private:
	PriorityQueue<Missions> waitingEmergencyMissions;
	LinkedQueue<Missions> waitingMountainiousMissions;
	LinkedQueue<Missions> waitingPolarMissions;
	LinkedQueue<Event> events;
	LinkedList<Missions> inExecutionMissions;
	LinkedList<Missions> finishedMissions;
	LinkedList<Rovers> roverCheckUpList;
	LinkedList<Rovers> availablePolarRovers;
	LinkedList<Rovers> availableMountainiousRovers; 
	LinkedList<Rovers> availableEmergencyRovers;
	LinkedQueue<string> lastDayMissionsAndRovers;
	int availabeEmergencyRoversNo;
	int availabePolarRoversNo;
	int availabeMountainiousRoversNo;
	int waitingEmergencyMissionsNo;
	int waitingPolarMissionsNo;
	int waitingMountaniousMissionsNo;
	int completedEmergencyMissionsNo;
	int completedPolarMissionsNo;
	int completedMountainiousMissionsNo;
	int mode;

	
	//Todo: complete the other data fields
public:
	//This function is called once at the instantiation of the object
	void Start() {

	}
	
	//This function is called at every time step and takes the current time step number
	void Update(int currentDay) {

	}
	
	BaseStation() {
		Start();
	}

	void setMode(int m) {
		mode = m;
	}


};

