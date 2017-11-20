#ifndef EXTRAS_H_
#define EXTRAS_H_
#include <vector>
#include <string>

                      /////                                          /////
                     /////               EXTRAS . H                 /////
                    /////                                          /////

// Class: Time

class Time{
public:
	Time(unsigned int d, unsigned int m,unsigned int y);
	Time(std::string time);
	unsigned int getDay();
	unsigned int getMonth();
	unsigned int getYear();
	void printTime(std::ostream & os);
protected:
	unsigned int day,month,year;

};


class  RealTime: public Time{
public:
	RealTime();
};

bool operator==(Time & t1, Time & t2);
bool operator<(Time &t1, Time & t2);
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
