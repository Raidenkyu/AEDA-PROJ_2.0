#ifndef EXTRAS_H_
#define EXTRAS_H_


                      /////                                          /////
                     /////               EXTRAS . H                 /////
                    /////                                          /////

// Class: Time

class Time{
public:
	Time(unsigned int h = 0, unsigned int m = 0, unsigned int s = 0);
	void printTime();
	Time operator+(const Time& t);

private:
    unsigned int timeArrange();
	unsigned int hours, minutes, seconds;
};

class Schedule{

};






#endif /* SRC_EXTRAS_H_ */
