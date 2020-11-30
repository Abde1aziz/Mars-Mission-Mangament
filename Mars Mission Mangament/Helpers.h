#pragma once

#include <sstream>
#include <string>
#include "FormulationEvent.h"
#include "CancelationEvent.h"
#include "PromotionEvent.h"


using namespace std;

#define MOUNTAINOUS_MISSION 1
#define POLAR_MISSION 2
#define EMERGENCY_MISSION 3
#define MOUNTAINOUS_ROVER 4
#define POLAR_ROVER 5
#define EMERGENCY_ROVER 6
#define FORMULATION_EVENT 7
#define CANCELATION_EVENT 8
#define PROMOTION_EVENT 9
#define AWAITING_FORMULATION_MISSION 10
#define WATING_MISSION 11
#define IN_EXECUTION_MISSION 12
#define CANCELED_MISSION 13
#define COMPOLETED_MISSION 14
#define IN_MISSION_ROVER 15
#define WAITING_ROVER 16
#define DOING_CHECKUP_ROVER 17

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
    	
        int eventType = FORMULATION_EVENT;
        int missionType;
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
						missionType = MOUNTAINOUS_MISSION;
					}else if(c == 'p' || c == 'P'){
						missionType = POLAR_MISSION;
					}else if(c == 'e' || c == 'E'){
						missionType = EMERGENCY_MISSION;
					}
				}else{
					if (isWhiteSpace) {
                    numberStr = c;
	                }
	                else {
	                    numberStr += c;
	                }
	                //Check if the second character is empty to be sure that there are not a rest to the number
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
		FormulationEvent evnt(missionType, eventDay, id, missionTargetLocationDistance, daysToComplete, missionSignificance);
		return evnt;
    }
    
    static CancelationEvent ConvertStringToCancelationEvent(string str){
		int eventType = CANCELATION_EVENT;
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
		CancelationEvent evnt(eventDay, id);
		return evnt;
	}
	
	static PromotionEvent ConvertStringToPromotionEvent(string str){
		int eventType = PROMOTION_EVENT;
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
		PromotionEvent evnt(eventDay, id);
		return evnt;
	}
};