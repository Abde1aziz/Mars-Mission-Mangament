#pragma once
#include "PriorityQueue.h"
#include "Missions.h"
#include "LinkedQueue.h"
#include "Event.h"
#include "LinkedList.h"
#include "Rovers.h"
#include "Helpers.h"
#include "Node.h"
#include <cmath>
#include <iostream>
#include "UI.h"

using namespace std;
class BaseStation
{
protected:

	string* inputFileLines;
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
	LinkedList<Rovers> inMissionRovers;
	LinkedQueue<string> lastDayMissionsAndRovers;
	LinkedQueue<string> todaysAssignedMissionsAndRovers;
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

	bool isExit = false;

	UI ui;

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


	/*//completing phase 2
		char missiontype;
		int Event_day;
		int mission_ID;
		int DaysTo_Complete;
		int Significance;
		*/
		//Todo: complete the other data fields
public:

	BaseStation(string inputLines[]) {

		availabeEmergencyRoversNo = 0;
		availabePolarRoversNo = 0;
		availabeMountainiousRoversNo = 0;
		waitingEmergencyMissionsNo = 0;
		waitingPolarMissionsNo = 0;
		waitingMountaniousMissionsNo = 0;
		completedEmergencyMissionsNo = 0;
		completedPolarMissionsNo = 0;
		completedMountainiousMissionsNo = 0;

		inputFileLines = inputLines;
		Start();
		ui = UI();
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
			Rovers mRover(mountainCheckupDuration, mountainRoversSpeed, i + 1, MOUNTAINOUS_ROVER);
			availableMountainiousRovers.InsertBeg(mRover);
		}

		//Polar Rovers
		for (int i = 0; i < availabePolarRoversNo; i++) {
			Rovers pRover(polarCheckupDuration, polarRoversSpeed, availabeMountainiousRoversNo + i + 1, POLAR_ROVER);
			availablePolarRovers.InsertBeg(pRover);
		}

		//Emergency Rovers
		for (int i = 0; i < availabeEmergencyRoversNo; i++) {
			Rovers eRover(emergencyCheckupDuration, emergencyRoversSpeed, availabeMountainiousRoversNo + availabePolarRoversNo + i + 1, EMERGENCY_ROVER);
			availableEmergencyRovers.InsertBeg(eRover);
		}

		//Creating events objects
		FromStringToEvents(&inputFileLines[5], numberOfEvents);

	}

	/*
	 *This function is called at every time step and takes the current time step number
	 */
	void Update(int currentDay)
	{
		/*
		* Assigning the missions
		*/
		Event currentEvent;
		FormulationEvent FE;
		CancelationEvent CE;
		PromotionEvent PE;

		while (events.peek(currentEvent))
		{
			if (currentEvent.GetEventDay() == currentDay)
			{
				int MissionType;

				if (currentEvent.GetEventType() == FORMULATION_EVENT)
				{
					events.dequeue(FE);
					MissionType = FE.GetMissionType();

					if (MissionType == MOUNTAINOUS_MISSION)
					{
						Missions MM(FE.GetMissionID(), FE.GetDistance(), FE.GetSignificance(),
							FE.GetDaysToComplete(),
							currentDay, FE.GetMissionType());
						waitingMountainiousMissions.InsertEnd(MM);
						waitingMountaniousMissionsNo = waitingMountainiousMissions.getCount();
					}

					else if (MissionType == EMERGENCY_MISSION)
					{
						double missionDuaration = (emergencyRoversSpeed / FE.GetDistance()) / 25;
						Missions ME(FE.GetMissionID(), FE.GetDistance(), FE.GetSignificance(),
							FE.GetDaysToComplete(),
							currentDay, FE.GetMissionType());

						double priority = FE.GetEventDay() + FE.GetDistance() + missionDuaration + FE.GetSignificance();
						waitingEmergencyMissions.enqueue(ME, priority);
						waitingEmergencyMissionsNo = waitingEmergencyMissions.getCount();

					}
					else if (MissionType == POLAR_MISSION)
					{
						Missions MP(FE.GetMissionID(), FE.GetDistance(), FE.GetSignificance(),
							FE.GetDaysToComplete(),
							currentDay, FE.GetMissionType());
						waitingPolarMissions.enqueue(MP);
						waitingPolarMissionsNo++;
					}

				}
				else if (currentEvent.GetEventType() == CANCELATION_EVENT)
				{
					events.dequeue(CE);

					Node<Missions>* pointer = waitingMountainiousMissions.getHead();
					while (pointer)
					{
						if (pointer->getItem().GetMissionID() == CE.GetMissionID())
							waitingMountainiousMissions.DeleteNode(pointer->getItem());
						waitingMountaniousMissionsNo = waitingMountainiousMissions.getCount();

					}
				}
				else if (currentEvent.GetEventType() == PROMOTION_EVENT)
				{
					events.dequeue(PE);
					int id = PE.GetMissionID();
					Node<Missions>* pointer = waitingMountainiousMissions.getHead();
					while (pointer) {
						if (pointer->getItem().GetMissionID() == id) {
							pointer->getItem().PromoteMission(currentDay);
							waitingEmergencyMissions.enqueue(pointer->getItem(), pointer->getItem().GetSignificance());
							
							waitingMountainiousMissions.DeleteNode(pointer->getItem());
							waitingEmergencyMissionsNo = waitingEmergencyMissions.getCount();
							waitingMountaniousMissionsNo = waitingMountainiousMissions.getCount();

						}
					}

				}
			}
		}

		/* 
		Waiting to Inexcution
		*/
		//assigning for EmergencyMission
		Missions Mission;
		Node<Rovers>* polarrover = availablePolarRovers.getHead();

		Node<Rovers>* emergencyrover = availableEmergencyRovers.getHead();
		Node<Rovers>* Mountainousrover = availableMountainiousRovers.getHead();
		while(waitingEmergencyMissions.peek(Mission)){
			waitingEmergencyMissions.dequeue(Mission);
			waitingEmergencyMissionsNo = waitingEmergencyMissions.getCount();
			if (availableEmergencyRovers.getHead())
			{
				inExecutionMissions.InsertBeg(Mission);
				Mission.AssignRover(currentDay, emergencyrover);
				emergencyrover->getItem().AssignRover2Mission();
				inMissionRovers.InsertEnd(emergencyrover->getItem());
				availableEmergencyRovers.DeleteNode(emergencyrover->getItem());
				availabeEmergencyRoversNo = availableEmergencyRovers.getCount();
			}
			else if (availableMountainiousRovers.getHead())
			{
				inExecutionMissions.InsertBeg(Mission);
				Mission.AssignRover(currentDay, Mountainousrover);
				Mountainousrover->getItem().AssignRover2Mission();
				inMissionRovers.InsertEnd(Mountainousrover->getItem());
				availableMountainiousRovers.DeleteNode(Mountainousrover->getItem());
				availabeMountainiousRoversNo = availableMountainiousRovers.getCount();
				
			}
			else if (availablePolarRovers.getHead())
			{
				inExecutionMissions.InsertBeg(Mission);
				Mission.AssignRover(currentDay, polarrover);
				polarrover->getItem().AssignRover2Mission();
				inMissionRovers.InsertEnd(polarrover->getItem());
				availablePolarRovers.DeleteNode(polarrover->getItem());
				availabePolarRoversNo = availablePolarRovers.getCount();
			}
		}
		//assigning for MountauniousMission
		while (waitingMountainiousMissions.getHead() != nullptr) {

			Mission = waitingMountainiousMissions.getHead()->getItem();

			if (availableMountainiousRovers.getHead())
			{
				inExecutionMissions.InsertBeg(waitingMountainiousMissions.getHead()->getItem());
				availabeMountainiousRoversNo--;
				Mission.AssignRover(currentDay, Mountainousrover);
			}
			else if (availablePolarRovers.getHead())
			{
				waitingPolarMissions.dequeue(Mission);
				inExecutionMissions.InsertBeg(Mission);
				availabePolarRoversNo--;
				Mission.AssignRover(currentDay, polarrover);

			}
		}
		//assigning for PolarMission
		if (availablePolarRovers.getHead())
		{
			waitingPolarMissions.dequeue(Mission);
			inExecutionMissions.InsertBeg(Mission);
			availabePolarRoversNo--;
			Mission.AssignRover(currentDay, polarrover);

		}
		////////////////////////////////////////////////////////////////////////////////////////////////////////

		/*
		* inExecution to completed
		*/

		if (remainder(currentDay, 5) == 0)
		{

			Node<Missions>* completedmission = inExecutionMissions.getHead();

			if (completedmission)
			{
				finishedMissions.InsertBeg(completedmission->getItem());
			}
		}

		Exit();
	}



void Exit() {
	if (!events.isEmpty() && !waitingEmergencyMissions.isEmpty() && !waitingMountainiousMissions.isEmpty() && !waitingPolarMission.isEmpty()) {
		isExit == true;
	}
}

bool GetIsExit() {
	return isExit;
}

void SetMode(int m);
void	FromStringToEvents(string* eventsArray, int size);
~BaseStation();


};

/*
* This function sets the value of the mode variable
*/
void BaseStation::SetMode(int m) {
	mode = m;
}
/*
 * This function takes an array of string containing the information about the event
 * and populate the events queue
 */

void BaseStation::FromStringToEvents(string* eventsArray, int size) {
	for (int i = 0; i < size; i++) {
		if (eventsArray[i][0] == 'F' || eventsArray[i][0] == 'f') {
			events.enqueue(Helper::ConvertStringToFormulationEvent(eventsArray[i]));
		}
		else if (eventsArray[i][0] == 'X' || eventsArray[i][0] == 'x') {
			events.enqueue(Helper::ConvertStringToCancelationEvent(eventsArray[i]));
		}
		else if (eventsArray[i][0] == 'P' || eventsArray[i][0] == 'p') {
			events.enqueue(Helper::ConvertStringToPromotionEvent(eventsArray[i]));
		}
	}
}

BaseStation::~BaseStation()
{
	delete inputFileLines;
}