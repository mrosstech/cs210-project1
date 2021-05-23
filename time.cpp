// Time display application
// 5/18/21
// Author: Michael Ross

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <chrono>
#include <curses.h>
#include <unistd.h>

void DrawMenu();
void DrawTime(bool twelve_hour, int hours, int minutes, int seconds);
char GetInput();
void UpdateSeconds();
int GetCurrentTime(int &hours, int &minutes, int &seconds);

using namespace std;

int main() {
    // Hours / minutes and seconds will be tracked on a 24 hour basis
    // and will be converted to show in 12 hour.
    int seconds = 0;
    int minutes = 0;
    int hours = 0;
    char userInput;
    unsigned int delay = 1000;
    // Initialize time to current time
    GetCurrentTime(hours, minutes, seconds);

    // Main code loop
    do {
        // Clear Screen
        system("clear");

        // Wait 1 second
        usleep(1000000);

        // Get input
        // Display clocks
        DrawTime(true, hours, minutes, seconds);
        DrawTime(false, hours, minutes, seconds);


        // Get user input
        if (GetInput()) {
            DrawMenu();
            userInput = GetInput();
        }


    } while (!getch());

    return 0;

}

void DrawMenu() {
    cout << "**************************";
    cout << "*                        *";
    cout << "*                        *";
    cout << "**************************";
}