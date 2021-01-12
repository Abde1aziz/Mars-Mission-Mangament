#pragma once
#include "Helpers.h"
#include "Rovers.h"
#include "Node.h"
#include <cmath>

using namespace std;

class Missions
{
private:
	double targetLocationDistance;
	double significance;
	int missionID; 
	double missionDuration;
	int assignmentDay;
	int MDUR; // the number of days needed to fulfill the mission requirements at target location.
	int completeDay;
	int dayToReachLocation; 
	int dayToCompleteMission; 
	int formulationDay;	
	int missionType;	
	Node<Rovers>* Rover;
	int roveType;
	int waitingDays;
	int excecutionDays;
	
public:
	Missions();
	Missions(int ID, double TargetLocationDistance,
		double Significance, int mdur,
		int formlationday, int MissionType);             
	void SetTargetLocationDistance( double TargetLocationDistance);
	double GetTargetLocationDistance() const;
	void SetSignificance(double Signficance);                  
	double GetSignificance() const;
	void SetMissionID(int MissionID);                           
	int GetMissionID() const; 
	void SetMissionDuration(int TargetLocation,Rovers* rover);
    double GetMissionDuration () const;

	void SetWaitingDays(int assignmentDay, int FormulationDay);  
	int GetWaitingDays() const;
	void SetExecutionDays(double missionDuration,int MDUR);     
	int GetExecutionDays() const;
	void SetCompleteDay();                                      
	int GetCompleteDay() const;
	void SetDayToReachLocation(int DayReachLocation);
	int GetDayToReachLocation() const;
	void SetDayToCompleteMission(int DayComMission) ;
	void SetFormulationDay(int FormualtionDay);
	int GetFormulationDay() const;
	void SetMissionType(int missionType);
	int GetMissionType() const;
	int GetRoverType() const;

	Node<Rovers>* GetRover() {
		return Rover;
	}

//Do something functions
	
	void AssignRover(int currentDay, Node<Rovers>* rover, int rovertype); 

	void PromoteMission(int currentDay);

	int GetAssignemtDay() {
		return assignmentDay;
	}

};



Missions::Missions() {

}
Missions::Missions(int ID, double TargetLocationDistance,
double Significance, int mdur,
int formlationday, int MissionType)
{
	 missionID = ID;
	 targetLocationDistance= TargetLocationDistance;
	 significance= Significance;
	 MDUR= mdur;
	 formulationDay= formlationday;
	 missionType= MissionType;
}

void Missions::SetTargetLocationDistance(double TargetLocationDistance) {
	targetLocationDistance = TargetLocationDistance;
}
double Missions::GetTargetLocationDistance()const {
	return targetLocationDistance;
}
void Missions::SetSignificance(double Significance) {
	significance = Significance;
}
double Missions::GetSignificance() const {
	return significance; 
}
void Missions::SetMissionID(int MissionID) {
	missionID = MissionID;
}
int Missions::GetMissionID() const {
	return missionID;
}
void Missions::SetMissionDuration(int TargetLocation, Rovers* rover) {
	missionDuration = ceil((TargetLocation/(rover->getSpeed()))/MARS_DAYS);
}
double Missions::GetMissionDuration() const {
	return missionDuration;
}

void Missions::SetWaitingDays(int assignmentDay,int FormulationDay)
{
	waitingDays = assignmentDay - FormulationDay;
}
int Missions::GetWaitingDays() const
{
	return waitingDays;
}
void Missions::SetExecutionDays(double missionDuration, int dayReachLocation)
{
    	excecutionDays = 2 * missionDuration + dayReachLocation;
		
}
 int Missions::GetExecutionDays() const
{
	return excecutionDays;
}
void Missions::SetCompleteDay() 
{
	completeDay = excecutionDays + waitingDays + formulationDay;
}
int Missions::GetCompleteDay() const {
	return completeDay;
}
void Missions::SetDayToReachLocation(int DayReachLocation) {
	dayToReachLocation = DayReachLocation;
}
int Missions::GetDayToReachLocation() const {
	return  dayToReachLocation;
}
void Missions::SetDayToCompleteMission(int DayComMission) {
	dayToCompleteMission = DayComMission;
}

void Missions::SetFormulationDay(int FormulationDay) {
	formulationDay = FormulationDay;
}
int Missions::GetFormulationDay() const {
	return formulationDay;
}
void  Missions::SetMissionType(int missionType) {
	missionType = missionType;
}
int Missions::GetMissionType() const {
	return missionType;
}

void Missions::AssignRover(int currentDay, Node<Rovers>* rover,int rovertype)
{
	assignmentDay = currentDay;
	Rover = rover;
	
}

void Missions::PromoteMission(int currentDay){
	missionType = EMERGENCY_MISSION;
}


int Missions::GetRoverType() const {
	return roveType;
}