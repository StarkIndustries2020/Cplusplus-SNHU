//
//  main.cpp
//  Clock
//
//  Created by Ryan Sizemore on 1/21/21.
//

#include <iostream>
#include <time.h>
using namespace std;

// display the menu options
void static displayMenu() {
    cout << "**************************\n";
    cout << "* 1-Add One Hour         *\n";
    cout << "* 2-Add One Minute       *\n";
    cout << "* 3-Add One Second       *\n";
    cout << "* 4-Exit Program         *\n";
    cout << "**************************\n";
    cout << endl;
    cout << endl;
}

void static displayClocks(int hour24, int minutes, int seconds) {
    int hour12 = hour24%12; // sets hours to 12 hour scheme
    
    if (hour12 == 0) {
        hour12 = 12;
    }
    
    string period = (hour24 >= 12) ? "PM" : "AM"; //sets time of day period
    
    //format the time so that it is always in alignment
    string formattedHour12;
    
    if (hour12 >=1 && hour12 <10) {
        formattedHour12 = "0" + to_string(hour12);
    }
    else {
        formattedHour12 = to_string(hour12);
    }
    
    string formattedHour24;
    
    if (hour24 >= 1 && hour24 < 10) {
        formattedHour24 = "0" + to_string(hour24);
    }
    else {
        formattedHour24 = to_string(hour24);
    }
    
    string formattedMinutes = to_string(minutes);
    
    if (minutes >= 0 && minutes < 10) {
        formattedMinutes = "0" + to_string(minutes);
    }
    else {
        formattedMinutes = to_string(minutes);
    }
    
    string formattedSeconds = to_string(seconds);
    
    if (seconds >= 0 && seconds < 10) {
        formattedSeconds = "0" + to_string(seconds);
    }
    else {
        formattedSeconds = to_string(seconds);
    }
    
    cout << "**************************" << "               " << "**************************\n";
    cout << "*      12 Hour Clock     *" << "               " << "*      24 Hour Clock     *\n";
    cout << "*       " << formattedHour12 << ":" << formattedMinutes << ":" << formattedSeconds << " " << period << "      *" << "               " << "*        " << formattedHour24 << ":" << formattedMinutes << ":" << formattedSeconds << "        *\n";
    cout << "**************************" << "               " << "**************************\n";
    cout << endl;
    cout << endl;
}


// add second to time
void static addSecond(int &hour24, int &minutes, int &seconds) {
    if (seconds == 59 && minutes == 59 && hour24 == 23) {
        seconds = 0;
        minutes = 0;
        hour24 = 0;
    }
    else if (seconds == 59 && minutes == 59) {
        seconds = 0;
        minutes = 0;
        hour24 += 1;
    }
    else if (seconds == 59) {
        seconds = 0;
        minutes += 1;
    }
    else {
        seconds += 1;
    }
    
}

// add minute to time
void static addMinute(int &hour24, int &minutes, int &seconds) {
    if (minutes == 59 && hour24 == 23) {
        minutes = 0;
        hour24 = 0;
    }
    else if (minutes == 59) {
        minutes = 0;
        hour24 += 1;
    }
    else {
        minutes += 1;
    }
}

// add hour to time
void static addHour(int &hour24, int &minutes, int &seconds) {
    if (hour24 == 23) {
        hour24 = 0;
    }
    else {
        hour24 += 1;
    }
}

int main() {
    // initialize variables
    int userChoice;
    userChoice = 0;
    

    // get the current system time
    time_t timeNow = time(0);
    tm *local_time = localtime(&timeNow);
    int hour24 = local_time->tm_hour;
    int minutes = local_time->tm_min;
    int seconds = local_time->tm_sec;
        
    // display both initial clocks
    displayClocks(hour24, minutes, seconds);
    
    
    //show menu
    displayMenu();
    
    
    while (userChoice != 4) {
        cout << "Enter your choice: ";
        cin >> userChoice;
        cout << userChoice << endl;
        
        try {
            if (userChoice == 1) {
                addHour(hour24, minutes, seconds);
                displayClocks(hour24, minutes, seconds);
            }
            if (userChoice == 2) {
                addMinute(hour24, minutes, seconds);
                displayClocks(hour24, minutes, seconds);
            }
            if (userChoice == 3) {
                addSecond(hour24, minutes, seconds);
                displayClocks(hour24, minutes, seconds);
            }
            if (userChoice == 4) {
                cout << "Exiting program" << endl;
                return 4;
            }
            if (userChoice > 4 || userChoice < 1) {
                throw runtime_error("Invalid entry");
            }
        }
        catch (runtime_error& excpt) {
            cout << excpt.what() << endl;
            cout << "Please try again" << endl;
            cin.clear();
            cin.ignore(100, '\n');
        }
    }
}

    

