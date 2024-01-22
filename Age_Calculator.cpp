#include<bits/stdc++.h>
using namespace std;

struct Age {
    int years;
    int months;
    int days;
    int hours;
    int minutes;
    int seconds;
};

Age calculateAge(int birthYear, int birthMonth, int birthDay) {
    // Get the current time
    time_t t = time(0);
    tm* now = localtime(&t);

    // Calculate the age
    int currentYear = now->tm_year + 1900;
    int currentMonth = now->tm_mon + 1;
    int currentDay = now->tm_mday;
    int currentHour = now->tm_hour;
    int currentMinute = now->tm_min;
    int currentSecond = now->tm_sec;

    Age age;

    age.years = currentYear - birthYear;
    age.months = currentMonth - birthMonth;
    age.days = currentDay - birthDay;
    age.hours = currentHour;
    age.minutes = currentMinute;
    age.seconds = currentSecond;

    // Adjust age based on birth month and day
    if (age.days < 0) {
        age.months--;
        // Calculate the number of days in the birth month
        int daysInBirthMonth;
        if (birthMonth == 2) {
            // February
            daysInBirthMonth = (birthYear % 4 == 0 && (birthYear % 100 != 0 || birthYear % 400 == 0)) ? 29 : 28;
        } else if (birthMonth == 4 || birthMonth == 6 || birthMonth == 9 || birthMonth == 11) {
            // April, June, September, November
            daysInBirthMonth = 30;
        } else {
            // January, March, May, July, August, October, December
            daysInBirthMonth = 31;
        }
        age.days += daysInBirthMonth;
    }

    if (age.months < 0) {
        age.years--;
        age.months += 12;
    }

    return age;
}

int main() {

    int birthYear, birthMonth, birthDay;

    cout << "Enter your birth year: ";
    cin >> birthYear;

    cout << "\nEnter your birth month: ";
    cin >> birthMonth;

    cout << "\nEnter your birth day: ";
    cin >> birthDay;

    Age age = calculateAge(birthYear, birthMonth, birthDay);
    cout << "\nYour present age is:\n" <<endl<< age.years << " years, "<<endl << age.months << " months, "<<endl << age.days << " days, "
         <<endl << age.hours << " hours, " <<endl<< age.minutes << " minutes, and " <<endl<< age.seconds << " seconds." << endl;

    return 0;
}
