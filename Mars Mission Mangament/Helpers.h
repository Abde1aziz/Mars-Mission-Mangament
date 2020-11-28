#pragma once

#include <sstream>
#include <string>
#include "string"
#include "FormulationEvent.h"

using namespace std;

class Helper {
public :
    /*
    * This function takes a number in the form of a string and convert it to a number of type int
    */
    static int ConvertStringToInt(string s) {
        stringstream str(s);
        int x = 0;
        str >> x;
        return x;
    }

    /*
    * This function takes a string of numbers with white spaces between numbers 
    * and returns an array containing the number in the same order as they appear in the string.
    */
    static int* GetNumbersFromStringMax4(string str) {
        static int numbers[4];
        int numberIndecator = 0;
        bool isBlancSpace = false;
        static string numbersStr[4];
        string number = "";
        for (int i = 0; i < str.length(); i++) {
            char c = str[i];
            if (c == ' ') {
                if (!isBlancSpace) {
                    numberIndecator++;
                }
                isBlancSpace = true;
            }
            else {
                if (isBlancSpace) {
                    number = c;
                }
                else {
                    number += c;
                }
                numbersStr[numberIndecator] = number;
                isBlancSpace = false;
            }
        }
        for (int i = 0; i < 4; i++) {
            int n = ConvertStringToInt(numbersStr[i]);
            numbers[i] = n;
        }
        return numbers;
    }

};

/////////////////////////////////////////Enums////////////////////////////////
enum class MissionType { 
	Emergency_Mission, 
	Mountainous_Mission, 
	Polar_Mission 
};

enum class RoverType {
	Emergency_Rover,
	Mountainous_Rover,
	Polar_Rover
};

enum class EventType {
	Formulation,
	Cancelation,
	Promotion
};

enum class RoverStatus {
    In_Mission,
    Waiting,
    Doing_Checkup
};

enum class MissionStatus {
    Awaiting_Formulation,
    Waiting,
    In_Execution,
    Canceled,
    Completed
};
