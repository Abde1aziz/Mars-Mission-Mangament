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
	RoverStatus roverStatus;
	RoverType roverType;

public:
	Rovers();
	Rovers(int checkupD, int speed, int id, RoverType);
	void setRoverType(RoverType roverType);
	RoverType  getRovertype();
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
};

Rovers::Rovers() {}

Rovers::Rovers(int checkupD, int speed , int id, RoverType type)
{
	checkupDuration = checkupD;
	roverSpeed = speed;
	ID = id;
	timeToFinishCheckup = 0;
	numberOfMissionsCompleted = 0;
	roverType = type;
	roverStatus = RoverStatus::Waiting;

}
void Rovers::setRoverType(RoverType RoverType)
{
	roverType = RoverType;
}
RoverType  Rovers::getRovertype()
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