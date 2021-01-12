#pragma once

#include "Helpers.h"

class Rovers
{

private:

	int checkupDuration;
	int roverSpeed;
	int ID;
	int numberOfMissionsCompleted;
	int timeToFinishCheckup;
	int roverStatus;
	int roverType;

public:
	Rovers();
	Rovers(int checkupD, int speed, int id, int type);
	void SetRoverType(int type);
	int  getRovertype();
	void setCheckupDuration(int CheckupDuration);
	int getCheckupDuration();
	void setSpeed(int Speed);
	int getSpeed();
	void setID(int ID2);
	int getID();
	void setNumberOfMissionsCompleted(int NumberOfMissionsCompleted);
	int getNumberOfMissionsCompleted();
	void setTimeToFinishCheckup(int TimeToFinishCheckup);
	int getTimeToFinishCheckup();

	void AssignRover2Mission() {
		roverStatus = IN_MISSION_ROVER;
	}
	
	void CompleteRoverMission() {
		roverStatus = WAITING_ROVER;
		numberOfMissionsCompleted++;
	}
};

Rovers::Rovers() {}

Rovers::Rovers(int checkupD, int speed, int id, int type)
{
	checkupDuration = checkupD;
	roverSpeed = speed;
	ID = id;
	timeToFinishCheckup = 0;
	numberOfMissionsCompleted = 0;
	roverType = type;
	roverStatus = WAITING_ROVER;

}
void Rovers::SetRoverType(int RoverType)
{
	roverType = RoverType;
}
int  Rovers::getRovertype()
{
	return roverType;
}
void Rovers::setCheckupDuration(int CheckupDuration)
{
	checkupDuration = CheckupDuration;
}
int Rovers::getCheckupDuration()
{
	return checkupDuration;
}
void Rovers::setSpeed(int Speed)
{
	roverSpeed = Speed;
}
int Rovers::getSpeed()
{
	return roverSpeed;
}
void Rovers::setID(int ID2)
{
	ID = ID2;
}
int Rovers::getID()
{
	return ID;
}
void Rovers::setNumberOfMissionsCompleted(int NumberOfMissionsCompleted)
{
	numberOfMissionsCompleted = NumberOfMissionsCompleted;
}
int Rovers::getNumberOfMissionsCompleted()
{
	return numberOfMissionsCompleted;
}
void Rovers::setTimeToFinishCheckup(int TimeToFinishCheckup)
{
	timeToFinishCheckup = TimeToFinishCheckup;
}
int Rovers::getTimeToFinishCheckup()
{
	return timeToFinishCheckup;
}