/*
* Clock.cpp
*
* Date: November 6, 2023
* Author : John Munguia
*/

#include <iostream>
#include <iomanip>

using namespace std;

class Clock {
private:
    int hours;
    int minutes;
    int seconds;

public:
    Clock(int h, int m, int s) : hours(h), minutes(m), seconds(s) {}

    // Display the clock time in either 12-hour or 24-hour format
    void display(bool is24HourFormat) const {
        cout << (is24HourFormat ? "24-Hour Clock" : "12-Hour Clock") << endl;

        int displayHours = (is24HourFormat ? hours : hours % 12);
        // Display 12 instead of 0 for 12-hour format when hours are 0
        displayHours = (displayHours == 0 ? 12 : displayHours);

        cout << setfill('0') << setw(2) << displayHours << ":"
            << setw(2) << minutes << ":" << setw(2) << seconds;

        if (!is24HourFormat) {
            cout << (hours >= 12 ? " PM" : " AM");
        }

        cout << endl << endl;
    }

    // Increment the hours, ensuring it wraps around at 24
    void addHour() {
        hours = (hours + 1) % 24;
    }

    // Increment the minutes, ensuring it wraps around at 60, and update hours if necessary
    void addMinute() {
        minutes = (minutes + 1) % 60;
        if (minutes == 0) {
            addHour();
        }
    }

    // Increment the seconds, ensuring it wraps around at 60, and update minutes if necessary
    void addSecond() {
        seconds = (seconds + 1) % 60;
        if (seconds == 0) {
            addMinute();
        }
    }
};

// Function to validate user input for initial time
bool isValidTime(int h, int m, int s) {
    return (h >= 0 && h < 24 && m >= 0 && m < 60 && s >= 0 && s < 60);
}

int main() {
    int hour, minute, second;

    // Get valid user input for initial time
    do {
        cout << "Enter initial time (HH MM SS): ";
        cin >> hour >> minute >> second;
        cout << endl;

        if (!isValidTime(hour, minute, second)) {
            cout << "Invalid time. Please enter a valid time.\n";
        }

    } while (!isValidTime(hour, minute, second));

    // Create clock objects with the initial time
    Clock clock12(hour, minute, second);
    Clock clock24(hour, minute, second);

    int choice;
    do {
        // Display user menu and get user choice
        cout << "1-Add One Hour\n";
        cout << "2-Add One Minute\n";
        cout << "3-Add One Second\n";
        cout << "4-Exit Program\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;

        // Perform action based on user choice
        switch (choice) {
        case 1:
            clock12.addHour();
            clock24.addHour();
            break;
        case 2:
            clock12.addMinute();
            clock24.addMinute();
            break;
        case 3:
            clock12.addSecond();
            clock24.addSecond();
            break;
        case 4:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Please enter a valid option.\n";
        }

        // Display both clocks
        clock12.display(false); // Display in 12-hour format
        clock24.display(true);  // Display in 24-hour format

    } while (choice != 4);

    return 0;
}
