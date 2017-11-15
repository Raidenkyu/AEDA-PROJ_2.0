#include <iomanip>
#include <sstream>
#include "extras.h"

using namespace std;

                      /////                                            /////
                     /////               EXTRAS . CPP                 /////
                    /////                                            /////

// Definition of class: Time

Time::Time(unsigned int d, unsigned int m,unsigned int y): day(d), month(m), year(y){}

Time::Time(string time){
	stringstream ss;
	char slash;
	ss >> time;
	ss >> this->year >> slash >> this->month >> slash >> this->day;
}

RealTime::RealTime():Time(0,0,0){
	time_t theTime = time(NULL);
	struct tm *aTime = localtime(&theTime);
	this->day = aTime->tm_mday;
	this->month = aTime ->tm_mon;
	this->year = aTime->tm_year;
}

void Time::printTime(ostream & os){
	os << year << "/" << month << "/" << day;
}

ostream & operator<<(ostream & os, Time & t){
	t.printTime(os);
	return os;
}

unsigned int Time::getDay() {
	return this->day;
}

unsigned int Time::getMonth() {
	return month;
}

unsigned int Time::getYear() {
	return year;
}

bool operator==(Time & t1, Time & t2){
	if(t1.getDay() == t2.getDay() && t2.getMonth() == t1.getMonth() && t1.getYear() == t2.getYear())
		return true;
	else
		return false;
}

bool operator<(Time &t1, Time & t2){
	if(t1.getYear() < t2.getYear())
		return true;
	else if(t1.getYear() == t2.getYear()){
		if(t1.getMonth() < t2. getMonth()){
			return true;
		}
		else if(t1.getMonth() == t2.getMonth()){
			if(t1.getDay() < t2.getDay()){
				return true;
			}
			else{
				return false;
			}
		}
		else{
			return false;
		}
	}
	else{
	return false;
	}
}


