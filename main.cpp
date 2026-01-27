#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
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
    ifstream inFile;
    inFile.open("data.txt");

    if(inFile){
        for(int i = 0; i < numAthletes; i++){
            inFile >> athleteList[i].firstName >> athleteList[i].lastName;
            for(int j = 0; j < 4; j++){
                inFile >> athleteList[i].recordList[j].date;
                inFile >> athleteList[i].recordList[j].time;
            }
        }
        inFile.close();
    }else{
        cout << "ERROR, file failed to open";
    }
}


void findBestWorst(record records[], double &bestTime, double &worstTime){
    int best = records[0].time;
    int worst = records[0].time;
    for(int i = 1; i < 4, i++;){
        if(records[i].time < records[best].time){
            bestTime = records[i].time;
        }
        if (records[i].time > records[worst].time){
            worstTime = records[i].time;
        }
    }
}


void printTable (athlete athleteList[], int numAthletes){
    double bestTime = 0;
    double worstTime = 0;
    cout << setw(11) << left << "First Name"
     << setw(10) << left << "Last Name"
     << setw(10) << left << "Best Time"
     << setw(10) << left << "Worst Time"
     << endl;
    for(int i = 0; i < numAthletes; i++){
        findBestWorst(athleteList[i].recordList, bestTime, worstTime);
        cout << " " << setw(11) << left << athleteList[i].firstName << setw(10) << left << athleteList[i].lastName << setw(10) << left << bestTime << setw(10) << left << worstTime << endl;
        
    }
}

int main() {
    int numAthletes = 5;
    athlete athleteList[numAthletes];

    readData(athleteList, numAthletes);
    printTable(athleteList, numAthletes);

    // string findBestOfAll();
    return 0;
}

