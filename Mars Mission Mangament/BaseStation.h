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

	string *inputFileLines;
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

	//Input file variables
	int mountainRoversSpeed;
	int polarRoversSpeed;
	int emergencyRoversSpeed;
	int completedMissionsToCheckupNo;
	int mountainCheckupDuration;
	int polarCheckupDuration;
	int emergencyCheckupDuration;
	int autoPromotionDuration;
	int numberOfEvents;

	
	//Todo: complete the other data fields
public:

	BaseStation(string inputLines[]) {
		inputFileLines = inputLines;
	}

	//This function is called once at the instantiation of the object
	void Start() {
		//Converting the number of available rovers from string to int
		int* rovers = GetNumbersFromStringMax4(inputFileLines[0]);
		//Setting the number of available rovers
		availabeMountainiousRoversNo = rovers[0];
		availabePolarRoversNo = rovers[1];
		availabeEmergencyRoversNo = rovers[2];

		//Converting the speed of the rovers from string to int;
		int* roversSpeed = GetNumbersFromStringMax4(inputFileLines[1]);
		//Setting the speed of the rovers
		mountainRoversSpeed = roversSpeed[0];
		polarRoversSpeed = roversSpeed[1];
		emergencyRoversSpeed = roversSpeed[2];

		//Converting the third line from string to int
		int* line3 = GetNumbersFromStringMax4(inputFileLines[2]);
		//Setting the other varaibles
		completedMissionsToCheckupNo = line3[0];
		mountainCheckupDuration = line3[1];
		polarCheckupDuration = line3[2];
		emergencyCheckupDuration = line3[3];

	}
	
	//This function is called at every time step and takes the current time step number
	void Update(int currentDay) {

	}
	

	void SetMode(int m) {
		mode = m;
	}

	~BaseStation() {
		delete inputFileLines;
	}
};

