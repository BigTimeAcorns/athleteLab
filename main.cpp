/**********************************************************************************
Cade Dannels
CS211
1/25/25
Athlete Lab 

This program will take the data from an input file and intiatlize it into a list. Then
it prints the data for each athlete into a table with their best and worst times. And then
it finds the best run time across every athlete.
**********************************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

// sets up record structure and has date and time attributes
struct record{
    string date; //record date
    double time = 0.0; //record time
};

// sets up athlete structure with first, last name and a list of their record
struct athlete{
    string firstName;// athlete first name 
    string lastName;// athlete last name
    record recordList[4];// list of athlete records
};

/**********************************************************************************
athleteList is the list of athletes 
nuAthletes is the size of the athleteList
This function takes the data from the input file and initializes it into a list.
**********************************************************************************/
void readData(athlete athleteList[], int numAthletes){

    //Opens the input file
    ifstream inFile;
    inFile.open("data.txt");

    //checks to make sure the file is open and uses a nested for loop to initialize all the data from the text file into both athleteList and recordList
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
        cout << "ERROR, file failed to open"; //if file did not open it prints and error statement
    }
}

/**********************************************************************************
records is the list of the athletes records
bestTime is the pass by reference variable for the athletes best time
worsTime is the pass by reference variable for the athletes worst time
This function takes the list of the athletes records and finds their best and worst times and saves
them into their respective spots in memory.
**********************************************************************************/
void findBestWorst(record records[], double &bestTime, double &worstTime, string &bestDate, string &worstDate){
    int best = 0; // sets best index to 0
    int worst = 0; // sets worst index to 0
    
    // compares the time at each index and sets the new best/ worst
    for(int i = 1; i < 4; i++){
        if(records[i].time < records[best].time){
            best = i;
        }else if (records[i].time > records[worst].time){
            worst = i;
        }
    }
    // sets bestTime and worsTime to whatever the function found to be their best or worst time
    bestTime = records[best].time;
    worstTime = records[worst].time;
    bestDate = records[best].date;
    worstDate = records[worst].date;
}

/**********************************************************************************
athleteList is the list of the athletes
numAthletes is the size of the athleteList
This funtion prints the table and organizes it by first name, last name, best time 
and worst time for each athlete.
**********************************************************************************/
void printTable (athlete athleteList[], int numAthletes){
    double bestTime = 0; // the athlete's best time
    double worstTime = 0; // the athlete's worst time
    string bestDate; // the date of the ahtlete's best time
    string worstDate; // the date of the ahtlete's worst time

    // prints the header for the table
    cout << setw(12) << left << "First Name"
     << setw(11) << left << "Last Name"
     << setw(11) << left << "Best Time"
     << setw(6) << left << "Date"
     << setw(12) << left << "Worst Time"
     << setw(8) << left << "Date"
     << endl;

    // prints all the information in the table 
    for(int i = 0; i < numAthletes; i++){
        findBestWorst(athleteList[i].recordList, bestTime, worstTime, bestDate, worstDate);
        cout << " " << setw(11) << left << athleteList[i].firstName 
        << " " << setw(10) << left << athleteList[i].lastName 
        << " " << setw(10) << left << bestTime 
        << " " << setw(5) << left << bestDate
        << " " << setw(10) << left << worstTime 
        << " " << setw(10) << left << worstDate
        << endl;
        
    }
}


void findBestOfAll(athlete athleteList[], int numAthletes){
    int bestTime = 0; // sets the best time index at 0;
    int bestAthlete; // index of the athlete with the best time
    string firstName; // first Name of best athlete
    string lastName; // last Name of best athlete
    string date; // date of the best record
    double time; // best record time

    // nested for loop that checks each athletes records and compares them to everyone else's and saves their information
    for(int i = 0; i < numAthletes; i++){
        for(int j = 1; j < 4; j++){
            if(athleteList[i].recordList[j].time < athleteList[bestAthlete].recordList[bestTime].time){
                bestAthlete = i;
                bestTime = j;
                firstName = athleteList[bestAthlete].firstName;
                lastName = athleteList[bestAthlete].lastName;
                date = athleteList[bestAthlete].recordList[bestTime].date;
                time = athleteList[bestAthlete].recordList[bestTime].time;
            }
        }
    }

    // prints all their information in a readable way
    cout << "The best time was " << time <<  " seconds recorded on " << date << " by " << firstName << " " << lastName << endl;
}

/**********************************************************************************
This function is the main function and initializes the athleteList and size of the array.
It also calls each funtion in the program.
**********************************************************************************/
int main() {
    //initialize the athleteList array and sets the size to 5
    int numAthletes = 5;
    athlete athleteList[numAthletes];

    // calls the ncessary functions
    readData(athleteList, numAthletes);
    printTable(athleteList, numAthletes);
    findBestOfAll(athleteList, numAthletes);
    
    return 0;
}