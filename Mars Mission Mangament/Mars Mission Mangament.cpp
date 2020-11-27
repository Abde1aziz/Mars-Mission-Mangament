// Mars Mission Mangament.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <thread>
#include "BaseStation.h"

using namespace std;

int main()
{
    int currentDay = 0; //The current day of the mission. It is incremented every iteration 
    bool exit = false;
    BaseStation baseStation;

    ///Asking the user to choose the mood of operation
    int mode; // the view mode of the of the output 1- Interactive mode 2-Step by Step mode 3- Silent Mode 
    cout << "Choose the program running mode.\nWhere....:\n1- Interactive mode\n2-Step by Step mode\n3- Silent Mode" << endl;
    cin >> mode;
    baseStation.setMode(mode);

    /// Reading the input file
    string fileName;
    string fileLines[100];
    fstream inputFile;
    int lineIndex = 0;
    //ask the user to enter the file name
    cout << "Enter the file name"<<endl;
    cin >> fileName;
    
    inputFile.open(fileName, ios::in);
    if (inputFile.is_open()) {
        while (getline(inputFile, fileLines[lineIndex])) {
            lineIndex++;
        }
    }

    for (int i = 0; i <= lineIndex; i++) {
        for (int j = 0; j < fileLines[i].length(); j++) {
            cout << fileLines[i][j]<<endl;
        }
    }
    
    while (!exit) {
        currentDay++;
        baseStation.Update(currentDay);

        string input; //it is just a dummy variable to take the user input to pause the program
        switch (mode) {
        case 1:
            cout << "Press any key to continue" << endl;
            cin >> input;
            break;
        case 2:
            //if the mode is step by step make the program sleep for one second
            this_thread::sleep_for(chrono::seconds(1));
            break;
        }
        exit = true;
    }
}

