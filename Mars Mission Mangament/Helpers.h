#pragma once

#include <sstream>
#include <string>
#include "string"
#include "FormulationEvent.h"
#include "CancelationEvent.h"
#include "PromotionEvent.h"


using namespace std;

enum MissionType { 
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


    static FormulationEvent ConvertStringToFormulationEvent(string str) {
    	
        EventType eventType = EventType::Formulation;
        MissionType missionType;
        int eventDay;
        int id;
        int missionTargetLocationDistance;
        int daysToComplete;
        int missionSignificance;

        int whiteSpaceIndex = 0;
        bool isWhiteSpace = false;
        string numberStr;
        int numberInt;
        for (int i = 1; i<str.length();i++){
        	char c = str[i];
        	if(c == ' '){
        		if(!isWhiteSpace){
        			whiteSpaceIndex++;
        			isWhiteSpace = true;
				}else{
					isWhiteSpace = true;
				}
			}else{
				if(whiteSpaceIndex == 1){
					if(c =='M'|| c== 'm'){
						missionType = MissionType::Mountainous_Mission;
					}else if(c == 'p' || c == 'P'){
						missionType = MissionType::Polar_Mission;
					}else if(c == 'e' || c == 'E'){
						missionType = MissionType::Emergency_Mission;
					}
				}else{
					if (isWhiteSpace) {
                    numberStr = c;
	                }
	                else {
	                    numberStr += c;
	                }
	                //Check if the second character is empty
	                if(str[i+1] == ' '){
	                	switch(whiteSpaceIndex){
	                		case 2:
	                			eventDay = Helper::ConvertStringToInt(numberStr);
	                			break;
	                		case 3:
	                			id = Helper::ConvertStringToInt(numberStr);
	                			break;
	                		case 4:
	                			missionTargetLocationDistance = Helper::ConvertStringToInt(numberStr);
	                			break;
	                		case 5:
	                			daysToComplete = Helper::ConvertStringToInt(numberStr);
	                			break;
	                		case 6:
	                			missionSignificance = Helper::ConvertStringToInt(numberStr);
	                			break;
	                				
						}
					}
	                isWhiteSpace = false;
				}
			}
		}
    }
    
    static CancelationEvent ConvertStringToCancelationEvent(string str){
    	EventType eventType = EventType::Cancelation;
        int eventDay;
        int id;

        int whiteSpaceIndex = 0;
        bool isWhiteSpace = false;
        string numberStr;
        int numberInt;
        for (int i = 1; i<str.length();i++){
        	char c = str[i];
        	if(c == ' '){
        		if(!isWhiteSpace){
        			whiteSpaceIndex++;
        			isWhiteSpace = true;
				}else{
					isWhiteSpace = true;
				}
			}else{
				
					if (isWhiteSpace) {
                    numberStr = c;
	                }
	                else {
	                    numberStr += c;
	                }
	                //Check if the second character is empty
	                if(str[i+1] == ' '){
	                	switch(whiteSpaceIndex){
	                		case 1:
	                			eventDay = Helper::ConvertStringToInt(numberStr);
	                			break;
	                		case 2:
	                			id = Helper::ConvertStringToInt(numberStr);
	                			break;
						}
					}
	                isWhiteSpace = false;
				
			}
		}
	}
	
	static PromotionEvent ConvertStringToPromotionEvent(string str){
		EventType eventType = EventType::Promotion;
        int eventDay;
        int id;

        int whiteSpaceIndex = 0;
        bool isWhiteSpace = false;
        string numberStr;
        int numberInt;
        for (int i = 1; i<str.length();i++){
        	char c = str[i];
        	if(c == ' '){
        		if(!isWhiteSpace){
        			whiteSpaceIndex++;
        			isWhiteSpace = true;
				}else{
					isWhiteSpace = true;
				}
			}else{
				
					if (isWhiteSpace) {
                    numberStr = c;
	                }
	                else {
	                    numberStr += c;
	                }
	                //Check if the second character is empty
	                if(str[i+1] == ' '){
	                	switch(whiteSpaceIndex){
	                		case 1:
	                			eventDay = Helper::ConvertStringToInt(numberStr);
	                			break;
	                		case 2:
	                			id = Helper::ConvertStringToInt(numberStr);
	                			break;
						}
					}
	                isWhiteSpace = false;
			}
		}
	}
};