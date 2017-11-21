#ifndef EXTRAS_H_
#define EXTRAS_H_
#include <vector>
#include <string>

                      /////                                          /////
                     /////               EXTRAS . H                 /////
                    /////                                          /////

// Class: Time

/**
 * @brief      Class for time.
 */
class Time{
public:

	/**
	 * @brief      Constructs Time Object
	 *
	 * @param[in]  d     day
	 * @param[in]  m     month
	 * @param[in]  y     year
	 */
	Time(unsigned int min,  unsigned int h, unsigned int d, unsigned int m, unsigned int y);

	/**
	 * @brief      Constructs Time Object
	 *
	 * @param[in]  time  The time in string format
	 */
	Time(std::string time);

	unsigned int getMinutes();

	unsigned int getHours();

	/**
	 * @brief      Gets the day.
	 *
	 * @return     The day.
	 */
	unsigned int getDay();

	/**
	 * @brief      Gets the month.
	 *
	 * @return     The month.
	 */
	unsigned int getMonth();

	/**
	 * @brief      Gets the year.
	 *
	 * @return     The year.
	 */
	unsigned int getYear();

	/**
	 * @brief      prints the time
	 *
	 * @param      os    ostream where the time will be printed
	 */
	void printTime(std::ostream & os);

	int diferencaDias();

protected:
	unsigned int minutes, hours, day, month, year;

};


/**
 * @brief      Class for real time.
 */
class  RealTime: public Time{
public:
	RealTime();

};

/**
 * @brief      Checks if two times are equal
 *
 * @param      t1    The time 1
 * @param      t2    The time 2
 *
 * @return     if both times are equal return true otherwise return false.
 */
bool operator==(Time & t1, Time & t2);

/**
 * @brief      Checks if one time is more recent than the other
 *
 * @param      t1    The time 1
 * @param      t2    The time 2
 *
 * @return     if time 1 is more recent than time 2 return true otherwise return false.
 */
bool operator<(Time &t1, Time & t2);

/**
 * @brief      prints the time in a ostream in string format
 *
 * @param      os    The oostream
 * @param      t     The time
 *
 * @return     The ostream where the time will be printed
 */
std::ostream & operator<<(std::ostream & os, Time & t);




/**
 * @brief      implementation of a Quick Sort Algorithm
 *
 * @param[in]  arr    The arr
 *
 * @tparam     T      elements of the vector arr
 */
template<class T>
void Sort(std::vector<T> arr){
	T tmp;
	for(unsigned int i = 0; i < arr.size();i++){
		for(unsigned int j = i+1; j < arr.size();j++){
			if(arr[i]->getNome() > arr[j]->getNome()){
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}


/**
 * @brief      implementation of a Binary Search Algorithm
 *
 * @param[in]  v     the vector
 * @param[in]  x     the element
 *
 * @tparam     T     type of the elements of the vector
 *
 * @return     the index of the element if found, otherwise -1
 */
template <class T,class P>
int BinarySearch(const std::vector<T> &v, P x){
	int left = 0, right = v.size() - 1;
	while (left <= right){
		int middle = (left + right) / 2;
		if (v[middle]->getNome() < x){
			left = middle + 1;
		}else if (x < v[middle]->getNome()){
			right = middle - 1;
		}else{
			return middle; // encontrou
		}
	}
	return -1; // nao encontrou
}

int getRealDay();


#endif /* SRC_EXTRAS_H_ */
