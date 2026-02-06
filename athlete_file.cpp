#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <random>
using namespace std;

struct record{
    string date;
    double time = 0.0;
};

struct athlete{
    string firstName;
    string lastName;
    record recordList[4];
};

void readData(athlete athleteList[], int numAthletes){
    ifstream outFile;
    ifstream firstNameFile;
    ifstream lastNameFile;
    outFile.open("athlete_many.txt");

    string firstNameList[50];
    string lastNameList[50];

    if(firstNameFile && lastNameFile){
        for(int i = 0; i < 50; i++){
            firstNameFile >> firstNameList[i];
            lastNameFile >> lastNameList[i];
        }
    }else{
        cout << "ERROR, file failed to open";
    }

    for(int i = 0; i < 50; i++){
        int randNum = rand() % 50;
        outFile << firstNameList[randNum];
    }
}