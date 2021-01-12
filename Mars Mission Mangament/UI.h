#pragma once
#include <iostream>
#include "fstream"
#include "PriorityQueue.h"
#include "Missions.h"
#include "LinkedQueue.h"
#include "Event.h"
#include "LinkedList.h"
#include "Rovers.h"
#include "Helpers.h"
#include "QueueADT.h"

using namespace std;
class UI
{
public:
	void OutputMode(int CurrentDay, LinkedList<Rovers> availablePolarRovers, LinkedList<Rovers> availableMountainiousRovers, LinkedList<Rovers> availableEmergencyRovers, LinkedQueue<Missions> waitingPolarMissions, LinkedList<Missions> waitingMountainiousMissions, PriorityQueue<Missions> waitingEmergencyMissions, LinkedList<Missions> inExecutionMissions,
		LinkedList <Missions> completedMissions, LinkedQueue<string> lastDayMissionsAndRovers, int waitingPolarMissionsNo, int waitingEmergencyMissionsNo, int waitingMountaniousMissionsNo, int availabePolarRoversNo, int availabeEmergencyRovers, int availabeMountainiousRoversNo, int completedPolarMissionsNo, int completedEmergencyMissionsNo, int completedMountainiousMissionsNo){
		// first line of available rovers
		Rovers rover;
		cout << " Avaiable rovers : " << "     ";
		// Displaying the IDs of available Polar missions
		Node <Rovers>* WaitPolarRover = availablePolarRovers.getHead();
		while (WaitPolarRover) {
			cout << "(" << WaitPolarRover->getItem().getID() << ")";
			WaitPolarRover = WaitPolarRover->getNext();
		}

		// Displaying the IDs of available Mountanoius missions
		Node <Rovers>* WaitMounRover = availableMountainiousRovers.getHead();
		while (WaitMounRover) {
			cout << WaitMounRover->getItem().getID();
			WaitMounRover = WaitMounRover->getNext();
		}

		// Displaying the IDs of available Emergency missions
		Node <Rovers>* WaitEmergencyRover = availableEmergencyRovers.getHead();
		while (WaitEmergencyRover) {
			cout << "[" << WaitEmergencyRover->getItem().getID() << "]";
			WaitEmergencyRover = WaitEmergencyRover->getNext();
		}
		cout << endl;


		// second line of Waiting missions 
		cout << "Waiting Missions : ";
		Missions M;
		// 	// Displaying the IDs of available Polar missions
		while (waitingPolarMissions.peek(M)) {
			waitingPolarMissions.dequeue(M);
			cout << "(" << M.GetMissionID() << ")" << " ";
		}

		// Displaying the IDs of available Mountanous missions
		Node <Missions>* WaitMountMission = waitingMountainiousMissions.getHead(); // linkedList Mountantious
		while (WaitMountMission) {
			cout << WaitMountMission->getItem().GetMissionID();
			WaitMountMission = WaitMountMission->getNext();
		}

		// // Displaying the IDs of available Emergency missions
		while (waitingEmergencyMissions.peek(M)) {
			waitingEmergencyMissions.dequeue(M);
			cout << "(" << M.GetMissionID() << ")" << " ";
		}
		cout << endl;

		// third line of In-Execution messions 
		cout << " In-Execution Missions : " << "     ";
		Node <Missions>* inExecutionMiss = inExecutionMissions.getHead(); // linkedList Mountantious
		while (inExecutionMiss) {
			if (inExecutionMiss->getItem().GetMissionType() == POLAR_MISSION) {
				cout << "(" << inExecutionMiss->getItem().GetMissionID() << ")";
			}
			else if (inExecutionMiss->getItem().GetMissionType() == MOUNTAINOUS_MISSION) {
				cout << inExecutionMiss->getItem().GetMissionID();
			}
			else {
				cout << "[" << inExecutionMiss->getItem().GetMissionID() << "]";
			}
			inExecutionMiss = inExecutionMiss->getNext();
		}
		cout << endl;

		// fourth line of Completed Missions 
		cout << " Completed Missions : " << "     ";
		Node <Missions>* CompletedMiss = completedMissions.getHead();
		while (CompletedMiss) {
			if (CompletedMiss->getItem().GetMissionType() == POLAR_MISSION) {
				cout << "(" << CompletedMiss->getItem().GetMissionID() << ")";
			}
			else if (CompletedMiss->getItem().GetMissionType() == MOUNTAINOUS_MISSION) {
				cout << CompletedMiss->getItem().GetMissionID();
			}
			else {
				cout << "[" << CompletedMiss->getItem().GetMissionID() << "]";
			}
			CompletedMiss = CompletedMiss->getNext();
		}
		cout << endl;

		// fifth line 
		cout << "Current Day : " << "          " << CurrentDay << endl;


		// sixth line Number of waiting missions of each type
		cout << " Number of Waiting Missions: " << "(" << waitingPolarMissionsNo << ")" << "  ";
		cout << "[" << waitingEmergencyMissionsNo << "]" << "   ";
		cout << waitingMountaniousMissionsNo << endl;

		// seventh line Number of available rovers of each type
		cout << " Number of availble rovers: " << "(" << availabePolarRoversNo << ")" << "  ";
		cout << "[" << availabeEmergencyRovers << "]" << "   ";
		cout << availabeMountainiousRoversNo << endl;

		// eighth line 
		string Mm;
		while (lastDayMissionsAndRovers.peek(Mm)) {
			lastDayMissionsAndRovers.dequeue(Mm);
			cout << Mm;
			cout << endl;

			//ninth line total number of completed missions of each type
			cout << "Total number of completed missions: " << "(" << completedPolarMissionsNo << ")" << "  ";
			cout << "[" << completedEmergencyMissionsNo << "]" << "   ";
			cout << completedMountainiousMissionsNo << endl;

		}
	}
	void OutputFile(int CurrentDay, LinkedList<Missions> completedMissions) {
		cout << " Completed Missions : " << "     ";
		Node <Missions>* CompletedMiss = completedMissions.getHead(); 
		ofstream myfile;
		myfile.open("Output.txt");
		while (CompletedMiss) {
			myfile << "  CD      ID      FD      WD      ED      .\n";
			// WD   WD = AssignmentDay - FD
			// ED   ED = CD - AssignmentDay
			int CD = CompletedMiss->getItem().GetCompleteDay();
			int ID = CompletedMiss->getItem().GetMissionID();
			int FD = CompletedMiss->getItem().GetFormulationDay();
			// 
			int WD = CompletedMiss->getItem().GetAssignemtDay() - FD;
			int ED = CD - CompletedMiss->getItem().GetAssignemtDay();
			//
			myfile << CD << ID << FD << WD << ED << endl;
			myfile.close();
		}
	}
};
