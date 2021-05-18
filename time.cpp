// Time display application
// 5/18/21
// Author: Michael Ross

#include <stdio.h>
#include <iostream>
#include <string.h>

void DrawMenu();
void DrawTime(bool twelve_hour, int hours, int minutes, int seconds);
using namespace std;

string GetInput();

int main() {
    int seconds = 0;
    int minutes = 0;
    int hours = 0;
    char userInput;

    // Main code loop
    do {
        // Display clocks
        DrawMenu();
        DrawTime(true, hours, minutes, seconds);
        DrawTime(false, hours, minutes, seconds);


        // Get user input


    } while (userInput != '4');

    return 0;

}

void DrawMenu() {
    cout << "**************************";
    cout << "*                        *";
    cout << "*                        *";
    cout << "**************************";
}