// Time display application
// 5/18/21
// Author: Michael Ross

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <chrono>
#include <curses.h>
#include <unistd.h>
#include <iomanip>
#include <cctype>
#include <cstring>

int DoMenu();
char GetInput();

void DrawTime(int hours, int minutes, int seconds);
void UpdateSeconds(int &hours, int &minutes, int &seconds);
void UpdateMinutes(int &hours, int &minutes, int &seconds);
void UpdateHours(int &hours, int &minutes, int &seconds);

int GetCurrentTime(int &hours, int &minutes, int &seconds);


using namespace std;

int main() {
    // Hours / minutes and seconds will be tracked on a 24 hour basis
    // and will be converted to show in 12 hour.
    int seconds = 0;
    int minutes = 0;
    int hours = 0;
    char userInput;
    char menuInput;
    unsigned int delay = 1000;
    // Initialize time to current time
    GetCurrentTime(hours, minutes, seconds);

    // Main code loop
    do {
        // Clear Screen
        system("clear");
        
        // Draw the time on the screen
        DrawTime(hours, minutes, seconds);

        // Get user keystrokes
        userInput = getch();

        // If user entered a keystroke then do the menu
        if (!isblank(userInput)) {
            menuInput = DoMenu();

            switch (menuInput) {
                case 1:
                    UpdateHours(hours, minutes, seconds);
                    break;
                case 2:
                    UpdateMinutes(hours, minutes, seconds);
                    break;
                case 3:
                    UpdateSeconds(hours, minutes, seconds);
            }
        }

        // Wait 1 second
        usleep(1000000);

        // Add a second
        UpdateSeconds(hours, minutes, seconds);

    } while (menuInput != 4);

    return 0;

}

void DrawTime(int hours, int minutes, int seconds) {
    int th_hours = hours - 12;
    int th_minutes = minutes;
    int th_seconds = seconds;

    if (th_hours = 0) {
        th_hours = 12;
    }

    cout << "**************************    **************************\n";
    cout << "*      12-Hour Clock     *    *      24-Hour Clock     *\n";
    cout << setfill('0') << setw(2) << "*      " << th_hours << ":" << th_minutes << ":" << th_seconds << "       *    ";
    cout << setfill('0') << setw(2) << "*      " << hours << ":" << minutes << ":" << seconds << "       *\n";
    cout << "**************************" << endl;
}

int GetCurrentTime(int &hours, int &minutes, int &seconds) {
    // Get the current time in seconds since 1970
    const time_t now = time(0);
    
    // Use the initial 'now' time to create a local time object
    const tm localTime = *localtime(addressof(now));
    
    // Set the hours, minutes, and seconds references to update the variables in the main loop.
    hours = localTime.tm_hour;
    minutes = localTime.tm_min;
    seconds = localTime.tm_sec;
}

void UpdateSeconds(int &hours, int &minutes, int &seconds) {
    if (seconds == 59) {
        seconds = 0;
        UpdateMinutes(hours, minutes, seconds);
    } else {
        seconds += 1;
    }
}
void UpdateMinutes(int &hours, int &minutes, int &seconds) {
    if (minutes == 59) {
        minutes = 0;
        UpdateHours(hours, minutes, seconds);
    } else {
        minutes += 1;
    }
}
void UpdateHours(int &hours, int &minutes, int &seconds) {
    if (hours == 24) {
        hours = 0;
    } else {
        hours += 1;
    }
}

int DoMenu() {
    int userInput = 0;

    cout << "**************************" << endl;
    cout << "* 1 - Add One Hour       *" << endl;
    cout << "* 2 - Add One Minute     *" << endl;
    cout << "* 3 - Add One Second     *" << endl;
    cout << "* 4 - Exit Program       *" << endl;
    cout << "**************************" << endl;

    while (userInput < 1 && userInput > 4) {
        cin >> userInput;
        if (userInput < 1 || userInput > 4) {
            cout << "Please enter valid input." << endl;
        }
    }
}