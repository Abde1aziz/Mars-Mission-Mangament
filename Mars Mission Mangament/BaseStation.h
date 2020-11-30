#pragma once
#include "PriorityQueue.h"
#include "Missions.h"
#include "LinkedQueue.h"
#include "Event.h"
#include "LinkedList.h"
#include "Rovers.h"
#include "Helpers.h"

using namespace std;
class BaseStation
{
private:

	string *inputFileLines;
	PriorityQueue<Missions> waitingEmergencyMissions;
	LinkedList<Missions> waitingMountainiousMissions; // but it behaves like a queue delete node from begining and add node to the end
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
		Start();
	}

	/*
	 * This function is called once at the instantiation of the object
	 */
	void Start() {
		//*Reading the values from the input files and assign them
		//Converting the number of available rovers from string to int
		int* rovers = Helper::GetNumbersFromStringMax4(inputFileLines[0]);
		//Setting the number of available rovers
		availabeMountainiousRoversNo = rovers[0];
		availabePolarRoversNo = rovers[1];
		availabeEmergencyRoversNo = rovers[2];

		//Converting the speed of the rovers from string to int;
		int* roversSpeed = Helper::GetNumbersFromStringMax4(inputFileLines[1]);
		//Setting the speed of the rovers
		mountainRoversSpeed = roversSpeed[0];
		polarRoversSpeed = roversSpeed[1];
		emergencyRoversSpeed = roversSpeed[2];

		//Converting the third line from string to int
		int* line3 = Helper::GetNumbersFromStringMax4(inputFileLines[2]);
		//Setting the other varaibles
		completedMissionsToCheckupNo = line3[0];
		mountainCheckupDuration = line3[1];
		polarCheckupDuration = line3[2];
		emergencyCheckupDuration = line3[3];

		autoPromotionDuration = Helper::ConvertStringToInt(inputFileLines[3]);

		numberOfEvents = Helper::ConvertStringToInt(inputFileLines[4]);

		//*Creating rover objects
		//Mountainious Rovers
		for (int i = 0; i < availabeMountainiousRoversNo; i++) {
			Rovers mRover(mountainCheckupDuration, mountainRoversSpeed, i+1, RoverType::Mountainous_Rover);
			availableMountainiousRovers.InsertBeg(mRover);
		}

		//Polar Rovers
		for (int i = 0; i < availabePolarRoversNo; i++) {
			Rovers pRover(polarCheckupDuration, polarRoversSpeed, availabeMountainiousRoversNo + i + 1, RoverType::Polar_Rover);
			availablePolarRovers.InsertBeg(pRover);
		}

		//Emergency Rovers
		for (int i = 0; i < availabeEmergencyRoversNo; i++) {
			Rovers eRover(emergencyCheckupDuration, emergencyRoversSpeed, availabeMountainiousRoversNo + availabePolarRoversNo + i + 1, RoverType::Emergency_Rover);
			availableEmergencyRovers.InsertBeg(eRover);
		}
	}
	
	/*
	 *This function is called at every time step and takes the current time step number
	 */
	void Update(int currentDay) {
		//Peek to the queue event 
		//if the event day of the event == the current day
		// then dequeue
		//check for the event type [formulation - cancelation - promotion]
		//switch for every event type
		//for formulation create mission 
		//if the mission mountainous you will mission to the end of the list
		//for cancelation check for the id in mountainous missions

	}
	
	/*
	* This function sets the value of the mode variable
	*/
	void SetMode(int m) {
		mode = m;
	}

	/*
	* This function takes an array of string containing the information about the event 
	* and populate the events queue
	*/
	void FromStringToEvents(string eventsArray[], int size) {

	}

	~BaseStation() {
		delete inputFileLines;
	}
};

