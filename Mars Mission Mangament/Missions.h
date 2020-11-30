#pragma once
#include "Helpers.h"
#include "Rovers.h"

class Missions
{
private:
	double targetLocationDistance;
	double significance;
	int missionID;
	double missionDuration;
	int assignmentDay;
	int finishDay;
	int dayToReachLocation;
	int dayToCompleteMission;
	int formulationDay;
	int missionType;
	int typrOfAssignedRover;
	Rovers assignedRover;

public:
	Missions() {}
	Missions(int ID);
	void SetTargetLocationDistance(double TargetLocationDistance);
	double GetTargetLocationDistance() const;
	void SetSignificance(double Signficance);
	double GetSignificance() const;
	void SetMissionID(int MissionID);
	int GetMissionID() const;
	void SetMissionDuration(double MissionDuration);
	double GetMissionDuration() const;
	void SetAssignmentDay(int AssDay);
	int GetAssignmentDay() const;
	void SetFinishDay(int FinishDay);
	int GetFinishDay() const;
	void SetDayToReachLocation(int DayReachLocation);
	int GetDayToReachLocation() const;
	void SetDayToCompleteMission(int DayComMission);
	int GetDayToCompleteMission() const;
	void SetFormulationDay(int FormualtionDay);
	int GetFormulationDay() const;
	void SetMissionType(int missionType);
	int GetMissionType() const;
	/// rest of functions
};

Missions::Missions(int ID)
{
	missionID = ID;
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
void Missions::SetMissionDuration(double MissionDuration) {
	missionDuration = MissionDuration;
}
double Missions::GetMissionDuration() const {
	return missionDuration;
}
void Missions::SetAssignmentDay(int AssDay) {
	assignmentDay = AssDay;
}
int Missions::GetAssignmentDay() const {
	return assignmentDay;
}
void Missions::SetFinishDay(int FinishDay) {
	finishDay = FinishDay;
}
int Missions::GetFinishDay() const {
	return finishDay;
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
int Missions::GetDayToCompleteMission() const {
	return dayToCompleteMission;
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
//There is an error, he can not define the type MissionType enum 
int Missions::GetMissionType() const {
	return missionType;
}