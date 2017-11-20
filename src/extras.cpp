#include <iomanip>
#include <sstream>
#include "extras.h"
#pragma warning(disable: 4996) //_CRT_SECURE_NO_WARNINGS

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

int Time::diferencaDias() {
	RealTime rt;
	int dias = 0;

	//se ano e m�s forem iguais
	if ((rt.getYear() == getYear()) && (rt.getMonth() == getMonth()))
		dias = this->getDay() - rt.getDay();

	//se ano for igual mas m�s for diferente
	else if ((rt.getYear() == getYear()) && !(rt.getMonth() == getMonth()))
	{
		if (getMonth() - rt.getMonth() == 1)
		{
			switch (getMonth()) {
			case 1: //Janeiro
				dias = (31 - rt.getDay()) + getDay();
			case 2: //Fevereiro
				if (getYear() % 4 == 0 && getYear() % 10 == 0 && getYear() % 400 == 0)
					dias = (29 - rt.getDay()) + getDay();
				else
				dias = (28 - rt.getDay()) + getDay();
			case 3: //Mar�o
				dias = (31 - rt.getDay()) + getDay();
			case 4: //Abril
				dias = (30 - rt.getDay()) + getDay();
			case 5: //Maio
				dias = (31 - rt.getDay()) + getDay();
			case 6: //Junho
				dias = (30 - rt.getDay()) + getDay();
			case 7: //Julho
				dias = (31 - rt.getDay()) + getDay();
			case 8: //Agosto
				dias = (31 - rt.getDay()) + getDay();
			case 9: //Setembro
				dias = (30 - rt.getDay()) + getDay();
			case 10: //Outubro
				dias = (31 - rt.getDay()) + getDay();
			case 11: //Novembro (n�o h� dezembro j� que, para haver uma diferen�a de 1 m�s positiva para Dezembro, o ano teria de ser diferente)
				dias = (30 - rt.getDay()) + getDay();
			default:
				dias = -1;
			}
		}
		else
			dias = 50;
	}
	else if (!(rt.getYear() == getYear()))
	{
		if (getYear() - rt.getYear() == 1)
		{
			if (rt.getMonth() == 12 && getYear() == 1)
				dias = (31 - rt.getDay()) + getDay();
			else
				dias = -1;
		}
		else
			dias = -1;
	}
	/*
	return abs(rt.getDay() - this->getDay()) + abs(rt.getMonth - this->getMonth()) * 30 + abs(rt.getYear() - this->getYear()) * 365;*/
	return dias;
}
