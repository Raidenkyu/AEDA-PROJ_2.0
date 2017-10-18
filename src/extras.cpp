#include <iostream>
#include <iomanip>
#include "extras.h"

using namespace std;

                      /////                                            /////
                     /////               EXTRAS . CPP                 /////
                    /////                                            /////

// Definition of class: Time

Time::Time(unsigned int h , unsigned int m , unsigned int s ): hours(h), minutes(m), seconds(s){
	if (seconds >= 60){
		minutes += seconds / 60;
		seconds = seconds % 60;
	}
	if (minutes >= 60){
		hours += minutes / 60;
		minutes = minutes % 60;
	}
}

void Time::printTime(){
	if (seconds != 0) {
		cout << setw(2) << setfill('0') << hours;
		cout << ":";
		cout << setw(2) << setfill('0') << minutes;
		cout << ":";
		cout << setw(2) << setfill('0') << seconds << endl;

	}
	else {
		cout << setw(2) << setfill('0') << hours;
		cout << ":";
		cout << setw(2) << setfill('0') << minutes << endl;
	}
}

Time Time::operator +(const Time& t) {
	Time t2;
	t2.seconds = this->seconds + t.seconds;
	t2.minutes = (t2.seconds / 60) + this->minutes + t.minutes;
	t2.seconds = t2.seconds % 60;
	t2.hours = (t2.minutes / 60) + this->hours + t.hours;
	t2.minutes = t2.minutes % 60;
	return t2;
}

