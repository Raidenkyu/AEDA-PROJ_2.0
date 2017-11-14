#ifndef EXTRAS_H_
#define EXTRAS_H_
#include <vector>


                      /////                                          /////
                     /////               EXTRAS . H                 /////
                    /////                                          /////

// Class: Time

class Time{
public:
	Time(unsigned int h = 0, unsigned int m = 0, unsigned int s = 0);
	void printTime(std::ostream & os);
	Time operator+(const Time& t);

private:
    unsigned int timeArrange();
	unsigned int hours, minutes, seconds;
};

class Schedule: public Time{

};

template<class T>
void quickSort(std::vector<T> arr, int left, int right) {
      int i = left, j = right;
      int tmp;
      int pivot = arr[(left + right) / 2];

      /* partition */
      while (i <= j) {
            while (arr[i] < pivot)
                  i++;
            while (arr[j] > pivot)
                  j--;
            if (i <= j) {
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  i++;
                  j--;
            }
      };

      /* recursion */
      if (left < j)
            quickSort(arr, left, j);
      if (i < right)
            quickSort(arr, i, right);
}

template <class T>
int BinarySearch(const std::vector<T> &v, T x){
	int left = 0, right = v.size() - 1;
	while (left <= right){
		int middle = (left + right) / 2;
		if (v[middle] < x){
			left = middle + 1;
		}else if (x < v[middle]){
			right = middle - 1;
		}else{
			return middle; // encontrou
		}
	return -1; // não encontrou
	}
}




#endif /* SRC_EXTRAS_H_ */
